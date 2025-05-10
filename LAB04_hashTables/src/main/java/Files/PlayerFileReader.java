package Files;

import Player.Player;

import java.io.IOException;

public class PlayerFileReader extends FileManagerReader {

    public PlayerFileReader(String fileName) throws Exception {
        super(fileName);
    }

    public Player getNextPlayer() throws IOException {
        String csvDivisor = ",";
        String line;

        while ((line = bufferedReader.readLine()) != null) {

            if (!line.equals("sofifa_id,name,player_positions")) {
                String[] playerData = line.split(csvDivisor);

                if (playerData[2].contains("\"")) {
                    for (int i = 3; i < playerData.length; i++) {
                        playerData[2] += playerData[i];
                    }

                    playerData[2] = playerData[2].replace("\"", "");
                    playerData[2] = playerData[2].replace(" ", ", ");
                }

                return new Player(Integer.parseInt(playerData[0]), playerData[1], playerData[2]);
            }

        }

        return null;

    }
}
