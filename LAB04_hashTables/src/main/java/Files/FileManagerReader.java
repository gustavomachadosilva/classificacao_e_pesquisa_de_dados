package Files;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class FileManagerReader implements FileManager{

    private final String fileName;
    protected BufferedReader bufferedReader = null;

    public FileManagerReader(String fileName) throws Exception{
        this.fileName = fileName;
        this.setup();
    }

    @Override
    public void setup() {
        try {
            this.bufferedReader = new BufferedReader(new FileReader(fileName));
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void close() {
        try {
            bufferedReader.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());;
        }
    }
}
