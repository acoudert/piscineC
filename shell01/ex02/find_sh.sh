find . -type f -name "*.sh" -exec basename {} \; | rev | sed 's/hs.//' | rev
