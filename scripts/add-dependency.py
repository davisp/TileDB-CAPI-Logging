#!/usr/bin/env python3

import json
import os
import sys

DEP_NAME = "tiledb-capi-logging"

def main():
  if len(sys.argv) != 2:
    print("usage: {} vcpkg.json".format(sys.argv[0]))
    exit(1)

  with open(sys.argv[1]) as handle:
    data = json.load(handle)

  if DEP_NAME in data["dependencies"]:
    return

  data["dependencies"].append(DEP_NAME)
  with open(sys.argv[1], "w") as handle:
    json.dump(data, handle, indent = 4, sort_keys = True)

if __name__ == "__main__":
  main()
