_BYTE *__fastcall qdf_debugfs_seq_next(__int64 a1, _BYTE *a2, _QWORD *a3)
{
  _BYTE *result; // x0

  result = a2;
  if ( a2 )
  {
    ++*a3;
    if ( *a2 == 1 )
    {
      _qdf_mem_free((__int64)a2);
      return nullptr;
    }
  }
  return result;
}
