public class SocialNetwork {
    private final String n;
    private User utenti[];

    public SocialNetwork(String n) {
        this.n = n;
        utenti = new User[0];
    }

    public void addUser(final User u)
        throws SocialNetworkException {
        for (int i = 0; i < utenti.length; i++) {
            if (u instanceof NormalUser && ((NormalUser) u).equals(utenti[i]))
                throw new SocialNetworkException("Error: utente già iscritto");
            else if (u instanceof PremiumUser && ((PremiumUser) u).equals(utenti[i]))
                throw new SocialNetworkException("Error: utente già iscritto");
        }
        User copy[] = new User[utenti.length + 1];
        for (int i = 0; i < utenti.length; i++)
            copy[i] = utenti[i];
        copy[copy.length - 1] = (u instanceof NormalUser) ? ((NormalUser) u) : (u instanceof PremiumUser) ? ((PremiumUser) u) : null;
        if (copy[copy.length - 1] == null)
            throw new SocialNetworkException("Error: abbiamo riscontrato un problema");
        this.utenti = copy;
    }
}
