bool __fastcall sps_bam_pipe_pending_desc(__int64 a1, unsigned int a2)
{
  int offset; // w21

  offset = bam_pipe_get_desc_read_offset(a1 + 216, a2);
  return offset != (unsigned int)bam_pipe_get_desc_write_offset(a1 + 216, a2);
}
