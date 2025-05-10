package Player;

public class Player {

    private int id;
    private String name;
    private String positions;

    public Player(int id, String name, String positions) {
        this.id = id;
        this.name = name;
        this.positions = positions;
    }

    public Player() {
        this.id = 99999;
        this.name = "NAO_ENCONTRADO";
        this.positions = "";
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPositions() {
        return positions;
    }

    public void setPositions(String positions) {
        this.positions = positions;
    }

    @Override
    public String toString() {
        return "Player{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", positions='" + positions + '\'' +
                '}';
    }

}
