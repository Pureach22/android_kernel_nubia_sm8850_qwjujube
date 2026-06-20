__int64 __fastcall bam_pipe_get_desc_write_offset(__int64 a1, unsigned int a2)
{
  return bam_read_reg_field(a1, 0x28u, a2, 0xFFFFu);
}
