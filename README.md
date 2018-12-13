# WikiCTL

Applicazione a riga di comando che si interfaccia con therickys93/wikicontroller.

## Comandi

```wikictl --home``` --> GET /

```wikictl --reset -k <key>``` --> GET /reset/:key

```wikictl --accendi -k <key> -p <pos>``` --> GET /on/:key/:pos ( pos parte da zero ).

```wikictl --spegni -k <key> -p <pos>``` --> GET /off/:key/:pos ( pos parte da zero ).