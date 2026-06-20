void *__fastcall lim_add_eht_cap(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  void *result; // x0

  if ( a4 )
  {
    if ( (*(_BYTE *)(a3 + 256) & 1) != 0 )
      return qdf_mem_copy((void *)(a3 + 260), (const void *)(a4 + 3480), 0x5Cu);
  }
  return result;
}
