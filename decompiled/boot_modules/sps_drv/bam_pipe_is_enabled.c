__int64 __fastcall bam_pipe_is_enabled(__int64 a1, unsigned int a2)
{
  return bam_read_reg_field(a1, 0x1Cu, a2, 2u);
}
