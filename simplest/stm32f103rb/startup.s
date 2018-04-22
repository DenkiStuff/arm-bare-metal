/* Cortex_M3 Stack pointer to loaded from 0x00*/
.section STACK_INIT
_StackInit:
  .word 0x20005000

.section INT_VECTOR_TABLE, "x"
.global _Reset
_Reset:
  .word Reset_Handler		+ 1	/* Reset 					*/
  .word Default_Handler		+ 1	/* Non-Maskable Interrupt	*/
  .word Default_Handler		+ 1	/* Hard Fault				*/
  .word Default_Handler		+ 1	/* Memory Manage			*/
  .word Default_Handler		+ 1	/* Bus Fault				*/
  .word Default_Handler		+ 1	/* Usage Fault				*/
  .word 0x0000					/* Reserved					*/
  .word 0x0000					/* Reserved					*/
  .word 0x0000					/* Reserved					*/
  .word 0x0000					/* Reserved					*/
  .word Default_Handler		+ 1	/* System Service Call		*/
  .word Default_Handler		+ 1	/* Debug Monitor			*/
  .word 0x0000					/* Reserved					*/
  .word Default_Handler		+ 1	/* Pendable System Service	*/
  .word Default_Handler		+ 1	/* System Tick Timer		*/

Reset_Handler:
  BL c_entry
  B .

Default_Handler:
  B .
