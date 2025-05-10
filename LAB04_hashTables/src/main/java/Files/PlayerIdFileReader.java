package Files;

import java.io.IOException;
import java.util.ArrayList;

public class PlayerIdFileReader extends FileManagerReader{

    public PlayerIdFileReader(String fileName) throws Exception {
        super(fileName);
    }

    public ArrayList<String> getAllId() throws IOException {
        String line;
        ArrayList<String> ids = new ArrayList<>();

        while ((line = bufferedReader.readLine()) != null) {
            ids.add(line);
        }

        return ids;
    }
}
