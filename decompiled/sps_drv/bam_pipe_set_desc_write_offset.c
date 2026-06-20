__int64 __fastcall bam_pipe_set_desc_write_offset(__int64 a1, unsigned int a2, int a3)
{
  return bam_write_reg_field(a1, 0x28u, a2, 0xFFFFu, a3);
}
