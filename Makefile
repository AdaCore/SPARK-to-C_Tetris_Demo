all:
        # Build the native Ada sanity-check executable
	gprbuild -P SPARK_Tetris_Native/SPARK_Tetris_Native_Ada.gpr -f -XFRONTEND=console
        # use SPARK-to-C to convert the Ada Tetris library to C code
	gprbuild --target=c -P SPARK_Tetris_Lib/SPARK_Tetris_Lib.gpr -gnatp -f -XFRONTEND=external_C
        # Build the native C sanity-check executable
	gprbuild -P SPARK_Tetris_Native/SPARK_Tetris_Native_C.gpr -f
