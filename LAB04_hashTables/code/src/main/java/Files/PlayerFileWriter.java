package Files;

import Player.Player;

import java.io.*;

public class PlayerFileWriter extends FileManagerWriter {

    public PlayerFileWriter(String fileName) throws Exception {
        super(fileName);
    }

    public void savePlayer(Player player) throws IOException {
        String line = player.toString();

        bufferedWriter.write(line);
        bufferedWriter.newLine();
    }

}
