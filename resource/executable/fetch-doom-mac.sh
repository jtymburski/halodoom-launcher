#!/usr/bin/env bash

#
# This downloads the Zandronum and Doom assets for running
# mods from a central repository, for Mac binaries.
#

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

echo "## OS X DOWNLOADER ##"

source "$SCRIPT_DIR/fetch-doom-base"

echo ""

# Zandronum Fetch

echo "-- Downloading Zandronum --"

ZANDRONUM_LOCAL_PATH="$SCRIPT_DIR/zandronum.tar.gz"
download_from_github_api "zandronum-[0-9.]*-osx.tar.gz" "$ZANDRONUM_LOCAL_PATH"

echo ""
echo "-- Extracting Zandronum --"

extract_and_clean_up_asset "$ZANDRONUM_LOCAL_PATH" "$SCRIPT_DIR/mac"

# Fin

echo ""
read -p "Press any key to finish..."
