package LinkedList;

import Player.Player;


public class PlayerLinkedList {

    private PlayerNode head;

    public void append(Player player) {
        PlayerNode newNode = new PlayerNode(player);
        PlayerNode current = head;

        if (current == null) {
            this.head = newNode;
        }
        else {
            while (current.getNext() != null) {
                current = current.getNext();
            }

            current.setNext(newNode);
        }
    }

    public Player findPlayer(int id, PlayerQuery playerQuery) {
        PlayerNode current = head;
        int currentId = -1;

        while (currentId != id && current != null) {
            currentId = current.getPlayer().getId();

            if (currentId != id) {
                playerQuery.setCount(playerQuery.getCount() + 1);
                current = current.getNext();
            }

        }

        if (currentId != id || currentId == -1) {
            return new Player();
        }

        return current.getPlayer();

    }

    public int size() {
        PlayerNode current = head;
        int size = 0;

        while (current != null) {
            current = current.getNext();
            size++;
        }

        return size;
    }

}
