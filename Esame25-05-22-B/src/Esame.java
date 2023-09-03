import exceptions.StudenteGiaIscrittoException;
import exceptions.StudenteGiaVerbalizzatoException;
import exceptions.StudenteNonIscrittoException;

public class Esame {
    private Studente si[];          // Studenti iscritti
    private Verbalizzazione sv[];   // Voti studenti verbalizzati

    public Esame() {
        si = new Studente[0];
        sv = new Verbalizzazione[0];
    }

    private void is_inside(final Object s, final Object array[])
        throws StudenteGiaVerbalizzatoException,
            StudenteGiaIscrittoException,
            StudenteNonIscrittoException {
        for (int i = 0; i < array.length; i++) {
            if (array instanceof Verbalizzazione[] &&
                    ((Verbalizzazione) array[i]).equals(((Verbalizzazione) s)))
                throw new StudenteGiaVerbalizzatoException(s.toString());
            else if (array instanceof Studente[] &&
                    ((Studente) array[i]).equals((Studente) s))
                throw new StudenteGiaIscrittoException(s.toString());
        }
        if (array instanceof Studente[])
            throw new StudenteNonIscrittoException(s.toString());
    }

    public void iscrivi(final Studente s) {
        try {
            this.is_inside(s, si);
        } catch (StudenteNonIscrittoException e) {
            Studente newSi[] = new Studente[si.length + 1];
            for (int i = 0; i < si.length; i++)
                newSi[i] = si[i];
            newSi[newSi.length - 1] = s;
            si = newSi;
        } catch (StudenteGiaIscrittoException e) {
            System.out.println(e.getMessage());
        } catch (StudenteGiaVerbalizzatoException e) {
            System.out.println(e.getMessage());
        }
    }

    public void verbalizza(final Studente s,final int v) {
        Verbalizzazione newV = null;
        try {
            newV = new Verbalizzazione(s, v);
            this.is_inside(s, si);
        } catch (StudenteGiaVerbalizzatoException e) {
            System.out.println(e.getMessage());
        } catch (StudenteGiaIscrittoException e) {
            try {
                this.is_inside(newV, sv);
                Verbalizzazione newSv[] = new Verbalizzazione[sv.length + 1];
                for (int i = 0; i < sv.length; i++)
                    newSv[i] = sv[i];
                newSv[newSv.length - 1] = newV;
                sv = newSv;
            } catch (StudenteNonIscrittoException _e) {
                System.out.println(_e.getMessage());
            } catch (StudenteGiaIscrittoException _e) {
                System.out.println(_e.getMessage());
            } catch (StudenteGiaVerbalizzatoException _e) {
                System.out.println(_e.getMessage());
            }
        } catch (StudenteNonIscrittoException e) {
            System.out.println(e.getMessage());
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public int hashCode() {
        int ret = 17;
        ret = 31 * ret + si.hashCode();
        ret = 31 * ret + sv.hashCode();
        return ret;
    }
}
