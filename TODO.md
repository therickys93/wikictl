per quanto riguarda la compilazione per windows è stato usato questo file travis.yml:

```
os:
  - linux
  - osx
  - windows
language: c
before_install:
  - if [[ "$TRAVIS_OS_NAME" == "windows" ]]; then choco install make          ; fi
script:
    - make clean
    - make
```

da capire come sostituire le librerie unix con quelle windows e avere cosi la cross-compilation.