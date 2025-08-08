# 1: "infiles/basic.txt" "cat -e" "cat -e" "outfiles/outfile"                       
# 2: "infiles/basic.txt" "ls -la" "cat -e" "outfiles/outfile"                       
# 3: "infiles/basic.txt" "ls -l -a" "cat -e -n" "outfiles/outfile"                  
# 4: "infiles/basic.txt" "ls -l -a -f" "cat -e -n" "outfiles/outfile"               
# 5: "infiles/basic.txt" "ls -laf" "cat -e -n" "outfiles/outfile"                   
# 6: "infiles/basic.txt" "grep -A5 is" "cat -e" "outfiles/nonexistingfile"          
# 7: "infiles/basic.txt" "cat -e" "grep nonexistingword" "outfiles/nonexistingfile" 
# 8: "infiles/empty.txt" "grep nonexistingword" "cat -e" "outfiles/outfile"         
# 9: "infiles/basic.txt" "sleep 3" "ls" "outfiles/outfile"        
#11: "nonexistingfile" "cat -e" "ls" "outfiles/outfile"                               
#12: "nonexistingfile" "cat" "sleep 3" "outfiles/outfile"                             
#13: "infiles/infile_without_permissions" "cat -e" "cat -e" "outfiles/outfile"        
#14: "infiles/basic.txt" "cat -e" "cat -e" "outfiles/outfile_without_permissions"     
#15: "infiles/basic.txt" "sleep 3" "cat -e" "outfiles/outfile_without_permissions"    
#16: "nonexistingfile" "cat -e" "cat -e" "outfiles/outfile_without_permissions"       
#17: "infiles/basic.txt" "nonexistingcommand" "cat -e" "outfiles/outfile"             
#18: "infiles/basic.txt" "cat -e" "nonexistingcommand" "outfiles/outfile"             
#19: "infiles/basic.txt" "cat -e" "cat -nonexistingflag" "outfiles/outfile"           
#20:                                                                             
#21: ""                                                                          
#22: "infiles/basic.txt" "cat -e" "outfiles/outfile"                             
#23: "" "cat -e" "cat -e" "outfiles/outfile"                                     
#24: "infiles/basic.txt" "" "cat -e" "outfiles/outfile"                          
#25: "infiles/basic.txt" "cat -e" "" "outfiles/outfile"    

not the man who points out how the strong man stumbles, or where the doer of deeds could have done them better. 

who errs, who comes short again and again, because there is no effort without error and shortcoming; 

but who does actually strive to do the deeds; who knows great enthusiasms, the great devotions; 

