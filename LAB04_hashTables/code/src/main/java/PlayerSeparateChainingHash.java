import LinkedList.PlayerLinkedList;
import LinkedList.PlayerQuery;
import Player.Player;

public class PlayerSeparateChainingHash {

    private final int hashTableSize;
    private final PlayerLinkedList[] playerLinkedLists;

    public PlayerSeparateChainingHash(int hashTableSize) {
        this.hashTableSize = hashTableSize;
        playerLinkedLists = new PlayerLinkedList[hashTableSize];
    }

    public void insertPlayer(Player player) {

        int keyHashCode = keyToHashCode(player.getId());

        if (linkedListIsNull(keyHashCode)) {
            this.playerLinkedLists[keyHashCode] = new PlayerLinkedList();
        }

        this.playerLinkedLists[keyHashCode].append(player);

    }

    public Player findPlayerById(int playerId, PlayerQuery query) {
        int keyHashCode = keyToHashCode(playerId);

        if (linkedListIsNull(keyHashCode)) {
            return new Player();
        }
        return this.playerLinkedLists[keyHashCode].findPlayer(playerId, query);

    }

    public int keyToHashCode(int key) {
        return (key % this.hashTableSize);
    }

    private boolean linkedListIsNull (int keyHashCode) {
        return this.playerLinkedLists[keyHashCode] == null;
    }

    public float tableOccupancyRate() {
        int count = 0;

        for (PlayerLinkedList playerLinkedList : playerLinkedLists) {
            if (playerLinkedList != null) {
                count++;
            }
        }

        return (((float) count) / ((float) this.hashTableSize));
    }

    public int biggestLinkedListSize() {
        int biggestSize = 0;
        int size;

        for (PlayerLinkedList playerLinkedList : playerLinkedLists) {
            if (playerLinkedList != null) {
                size = playerLinkedList.size();

                if (size > biggestSize) {
                    biggestSize = size;
                }
            }
        }

        return biggestSize;

    }

    public int averageLinkedListSize() {
        int count = 0;
        int sumSize = 0;

        for (PlayerLinkedList playerLinkedList : playerLinkedLists) {
            if (playerLinkedList != null) {
                count++;
                sumSize += playerLinkedList.size();
            }
        }

        return sumSize / count;
    }
}
