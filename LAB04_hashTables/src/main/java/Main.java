import Files.ConstructionStatisticsFileWriter;
import Files.PlayerFileReader;
import Files.PlayerIdFileReader;
import Files.QueryStatisticsFileWriter;
import LinkedList.PlayerQuery;
import Player.Player;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws Exception {

        String fileName = "src/players.csv";
        String fileName2 = "src/estatisticas_construção.txt";
        String fileName3 = "src/consultas.csv";
        String fileName4 = "src/estatisticas_consultas.txt";
        ConstructionStatisticsFileWriter constructionStatisticsFileWriter = new ConstructionStatisticsFileWriter(fileName2);
        PlayerSeparateChainingHash[] playerHashs = new PlayerSeparateChainingHash[5];
        int[] hashTableSizes = {3793, 6637, 9473, 12323, 15149};
        long[] tableConstructionTimes = new long[5];
        float[] tableOccupancyRates = new float[5];
        int[] tableBiggestLinkedListSizes = new int[5];
        int[] tableAverageLinkedListSizes = new int[5];

        for (int i = 0; i< hashTableSizes.length; i++) {
            long start;
            long end;

            start = System.currentTimeMillis();
            playerHashs[i] = createPlayerHashTable(hashTableSizes[i], fileName);
            end = System.currentTimeMillis();
            tableConstructionTimes[i] = end - start;

            tableOccupancyRates[i] = playerHashs[i].tableOccupancyRate();
            tableBiggestLinkedListSizes[i] = playerHashs[i].biggestLinkedListSize();
            tableAverageLinkedListSizes[i] = playerHashs[i].averageLinkedListSize();

        }

        constructionStatisticsFileWriter.writeLine(Arrays.toString(tableConstructionTimes));
        constructionStatisticsFileWriter.writeLine(Arrays.toString(tableOccupancyRates));
        constructionStatisticsFileWriter.writeLine(Arrays.toString(tableBiggestLinkedListSizes));
        constructionStatisticsFileWriter.writeLine(Arrays.toString(tableAverageLinkedListSizes));

        constructionStatisticsFileWriter.close();

        PlayerIdFileReader playerIdFileReader = new PlayerIdFileReader(fileName3);
        ArrayList<String> playerIds = playerIdFileReader.getAllId();
        playerIdFileReader.close();

        QueryStatisticsFileWriter queryStatisticsFileWriter = new QueryStatisticsFileWriter(fileName4);
        ArrayList<String> lines = new ArrayList<>();
        long[] timeQueries = {0, 0, 0, 0, 0};
        long start;
        long end;
        for (String id : playerIds) {
            ArrayList<String> line = new ArrayList<>();
            Player player = new Player();
            int playerId = Integer.parseInt(id);
            PlayerQuery[] queries = new PlayerQuery[5];
            start = 0;
            end = 0;

            for (int i = 0; i < 5; i++) {
                queries[i] = new PlayerQuery(1);

                start = System.currentTimeMillis();
                player = playerHashs[i].findPlayerById(playerId, queries[i]);
                end = System.currentTimeMillis();

                timeQueries[i] += (end - start);
            }

            line.add(Integer.toString(player.getId()));
            line.add(player.getName());

            for (int i = 0; i < 5; i++) {
                line.add(Integer.toString(queries[i].getCount()));
            }

            lines.add(String.valueOf(line));

        }
        queryStatisticsFileWriter.writeLine(Arrays.toString(timeQueries));

        for (String line : lines) {
            queryStatisticsFileWriter.writeLine(line);
        }

        queryStatisticsFileWriter.close();



    }

    public static PlayerSeparateChainingHash createPlayerHashTable(int hashTableSize, String fileName) throws Exception {
        PlayerSeparateChainingHash playerHash = new PlayerSeparateChainingHash(hashTableSize);
        PlayerFileReader playerFileReader = new PlayerFileReader(fileName);
        Player player = new Player();

        while (player != null) {
            player = playerFileReader.getNextPlayer();

            if (player != null) {
                playerHash.insertPlayer(player);
            }
        }

        playerFileReader.close();

        return playerHash;
    }

}
