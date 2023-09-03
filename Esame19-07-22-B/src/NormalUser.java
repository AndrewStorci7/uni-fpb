public class NormalUser implements User {
    private final String n;
    private final String c;
    private User amici[];

    public NormalUser(String n, String c) {
        this.n = n;
        this.c = c;
        amici = new User[0];
    }

    @Override
    public String getUsername() {
        return this.n + this.c;
    }

    public void addFriend(final User u)
        throws SocialNetworkException {
        if (((NormalUser) u) == this)
            throw new SocialNetworkException("Error: abbiamo riscontrato un problema");
        User copy[] = new User[this.amici.length + 1];
        for (int i = 0; i < this.amici.length; i++)
            copy[i] = this.amici[i];
        copy[copy.length - 1] = (u instanceof NormalUser) ? ((NormalUser) u) : (u instanceof PremiumUser) ? ((PremiumUser) u) : null;
        if (copy[copy.length - 1] == null)
            throw new SocialNetworkException("Error: utente non corretto");
        this.amici = copy;
    }

    public void follow(final PremiumUser pu) {
        try {
            pu.addFollower(this);
        } catch (SocialNetworkException e) {
            System.out.println(e.getMessage());
        }
    }

    public boolean equals(final Object o) {
        if (!(o instanceof NormalUser))
            return false;
        return (this.n.equals(((NormalUser) o).n) && this.c.equals(((NormalUser) o).c));
    }

    @Override
    public String toString() {
        return this.getUsername() + this.amici.length;
    }

}
