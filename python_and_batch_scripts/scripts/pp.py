
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        prog='process_tables.py',
        description='constructs temperature compensate tables from raw data.')
    parser.add_argument('-f','--filename', help="base name of files")
    args = parser.parse_args()
    file_base_name = args.filename
    input_file = open(file_base_name+".txt")
    output_file = open(file_base_name+".csv", "w" )
    block_number = 0 
    dataStr = input_file.read()
    blocks = dataStr.split("tmptur")
    for block in blocks :
        #print("block number : " , block_number )
        lines = block.splitlines(keepends=False)
        number_lines = len(lines)
        #print("number of lines : " , number_lines )
        if block_number > 0 :
            number_samples = 0
            sumx = 0
            sumy = 0
            sumz = 0
            sumrms = 0 
            line_number = 0 
            for line in lines :
                rows = line.split(',')
                number_rows = len(rows)
                if (number_rows == 11) and ( line_number > 0 ) :
                    number_samples += 1
                    sumx += int(rows[1])
                    sumy += int(rows[2])
                    sumz += int(rows[3])
                    sumrms += int(rows[10])
                    if ((rows[1]==0) or (rows[2]== 0 ) or (rows[3]==0)) :
                        print(line)
                line_number += 1
            avex = int(sumx/number_samples)
            avey = int(sumy/number_samples)
            avez = int(sumz/number_samples)
            averms = int(sumrms/number_samples)
            print( avex , avey , avez , averms )
            output_file.write(str(avex)+","+str(avey)+","+str(avez)+"\n" )        
        block_number += 1
    

