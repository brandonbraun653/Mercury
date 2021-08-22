# **********************************************************************************************************************
#   FileName:
#       dtb_parser.py
#
#   Description:
#       Simple script to convert device tree binaries into a desired format.
#
#   8/21/21 | Brandon Braun | brandonbraun653@gmail.com
# **********************************************************************************************************************

from pathlib import Path
from argparse import ArgumentParser
from pyfdt.pyfdt import FdtBlobParse

if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument("--input", required=True, help="Input to be converted")
    parser.add_argument("--type", required=True, help="File type to convert to", choices=["dts", "dtb", "json"])
    args = parser.parse_args()

    with open(args.input, mode='rb') as infile:
        root_name = Path(args.input).stem
        dtb = FdtBlobParse(infile)

        if args.type == "dts":
            with open(root_name + ".dts", mode='w') as outfile:
                outfile.write(dtb.to_fdt().to_dts())
        elif args.type == "dtb":
            with open(root_name + ".dtb", mode='wb') as outfile:
                outfile.write(dtb.to_fdt().to_dtb())
        elif args.type == "json":
            with open(root_name + ".json", mode='w') as outfile:
                outfile.write(dtb.to_fdt().to_json())
        else:
            RuntimeError("Unsupported input type")
