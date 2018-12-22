#include <wikictl_help.h>
#include <stdio.h>

void show_help()
{
    printf("Uso: wikictl -H <host> -P <port>\n");
    printf("\n");
    printf("-h,--help --> mostra questo messaggio.\n");
    printf("-v,--version --> mostra la versione.\n");
    printf("-k <value> --> setta la chiave.\n");
    printf("-p <value> --> setta la posizione.\n");
    printf("--accendi --> accende.\n");
    printf("--spegni --> spegne.\n");
    printf("--apri --> apre.\n");
    printf("--chiudi --> chiude.\n");
    printf("--status --> mostra lo stato.\n");
    printf("--home --> pagina principale.\n");
    printf("--download --> scarica configurazione.\n");
    printf("--upload --> carica configurazione... nome file: wiki.json\n");
}