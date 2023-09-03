public class PremiumUser implements User, Comparable<Object> {
    private final String un;
    private User follower[];

    public PremiumUser(String u) {
        this.un = u;
        follower = new User[0];
    }

    public void addFollower(final User u)
        throws SocialNetworkException {
        if (((PremiumUser) u) == this)
            throw new SocialNetworkException("Error: abbiamo riscontrato un problema");
        User copy[] = new User[this.follower.length + 1];
        for (int i = 0; i < this.follower.length; i++)
            if (((NormalUser) u).equals(follower[i]) || ((PremiumUser) u).equals(follower[i]))
                throw new SocialNetworkException("Error: stai già seguendo il seguente utente");
        for (int i = 0; i < follower.length; i++)
            copy[i] = follower[i];
        copy[copy.length - 1] = (u instanceof NormalUser) ? ((NormalUser) u) : (u instanceof PremiumUser) ? ((PremiumUser) u) : null;
        if (copy[copy.length - 1] == null)
            throw new SocialNetworkException("Error: utente non corretto");
        this.follower = copy;
    }

    @Override
    public String getUsername() {
        return this.un;
    }

    @Override
    public String toString() {
        String ret = this.un + ", follower: [ ";
        for (int i = 0; i < follower.length; i++) {
            ret += follower[i].getUsername();
            if (i != follower.length - 1)
                ret += ", ";
        }
        ret += " ]";
        return ret;
    }

    @Override
    public boolean equals(final Object o) {
        if (!(o instanceof PremiumUser))
            return false;
        return (this.un.equals(((User) o).getUsername()));
    }

    @Override
    public int compareTo(final Object o) {
        if (!(o instanceof PremiumUser))
            return -1;
        else if (((PremiumUser) o).follower.length == this.follower.length)
            return 0;
        else if (((PremiumUser) o).follower.length > this.follower.length)
            return -1;
        else
            return 1;
    }
}
