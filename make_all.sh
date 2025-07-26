#!/bin/bash

# Dossier principal (par défaut, le dossier courant)
ROOT_DIR="${1:-.}"

# Couleurs pour les logs
GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[1;33m"
NC="\033[0m" # No Color

# Fonction pour traiter un dossier
process_dir() {
    local dir="$1"
    echo -e "${YELLOW}📁 Traitement du dossier : $dir${NC}"

    if [ -f "$dir/Makefile" ] || [ -f "$dir/makefile" ]; then
        # Exécuter make
        echo -n "➡️  make... "
        if make -C "$dir" > /dev/null 2>&1; then
            echo -e "${GREEN}OK${NC}"
        else
            echo -e "${RED}ÉCHEC${NC}"
        fi

        # Exécuter fclean
        echo -n "🧹 make fclean... "
        if make -C "$dir" fclean > /dev/null 2>&1; then
            echo -e "${GREEN}OK${NC}"
        else
            echo -e "${RED}ÉCHEC${NC}"
        fi
    else
        echo -e "${RED}Aucun Makefile trouvé dans $dir${NC}"
    fi
}

# Parcours récursif des dossiers (profondeur 1 uniquement)
for subdir in "$ROOT_DIR"/*/; do
    [ -d "$subdir" ] || continue
    process_dir "$subdir"
done
