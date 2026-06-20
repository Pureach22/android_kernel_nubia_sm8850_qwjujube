_BYTE *qdf_debugfs_seq_start()
{
  _BYTE *result; // x0

  result = (_BYTE *)_qdf_mem_malloc(1u, "qdf_debugfs_seq_start", 110);
  if ( result )
    *result = 0;
  return result;
}
