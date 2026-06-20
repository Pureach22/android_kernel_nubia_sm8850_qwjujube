__int64 __fastcall bam_pipe_get_desc_read_offset(__int64 a1, unsigned int a2)
{
  return bam_read_reg_field(a1, 0x29u, a2, 0xFFFFu);
}
