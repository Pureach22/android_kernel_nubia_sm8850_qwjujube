__int64 __fastcall bam_pipe_set_mti(__int64 a1, unsigned int a2, int a3, unsigned int a4)
{
  if ( !a3 )
    a4 = 0;
  return bam_write_reg(a1, 0x21u, a2, a4);
}
