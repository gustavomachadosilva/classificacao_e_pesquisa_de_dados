package LinkedList;

import Player.Player;

public class PlayerNode {

    private final Player player;
    private PlayerNode next;

    public PlayerNode(Player player) {
        this.player = player;
        this.next = null;
    }

    public PlayerNode getNext() {
        return next;
    }

    public void setNext(PlayerNode next) {
        this.next = next;
    }

    public Player getPlayer() {
        return player;
    }
}
