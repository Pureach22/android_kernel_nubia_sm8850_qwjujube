__int64 __fastcall bam_pipe_satellite_mti(__int64 a1, unsigned int a2)
{
  char v2; // w19

  v2 = a2;
  bam_write_reg(a1, 0x21u, a2, 0);
  return bam_write_reg_field(a1, 8u, 0, 1 << v2, 1);
}
