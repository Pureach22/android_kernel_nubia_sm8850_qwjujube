__int64 __fastcall lim_update_overlap_sta_param(__int64 a1, const void *a2, char *a3)
{
  __int64 v5; // x22
  char *i; // x21
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  char v17; // w8

  if ( *a3 )
  {
    v5 = 32;
    for ( i = (char *)(a1 + 11441); *(i - 1); i += 12 )
    {
      result = qdf_mem_cmp(i, a2, 6u);
      if ( !(_DWORD)result )
        return result;
      if ( !--v5 )
        return qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: Overlap cache is full",
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 "lim_update_overlap_sta_param");
    }
    result = (__int64)qdf_mem_copy(i, a2, 6u);
    *(i - 1) = 1;
    v17 = *a3 + 1;
  }
  else
  {
    result = (__int64)qdf_mem_copy((void *)(a1 + 11441), a2, 6u);
    v17 = 1;
    *(_BYTE *)(a1 + 11440) = 1;
  }
  *a3 = v17;
  return result;
}
