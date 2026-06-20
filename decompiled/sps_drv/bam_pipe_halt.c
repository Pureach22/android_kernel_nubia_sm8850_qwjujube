__int64 __fastcall bam_pipe_halt(__int64 a1, unsigned int a2, char a3)
{
  return bam_write_reg_field(a1, 0x1Eu, a2, 1u, a3 & 1);
}
