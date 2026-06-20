void *__fastcall lim_update_stads_eht_caps(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  unsigned int v14; // w8
  bool v15; // cc
  int v16; // w8
  void *result; // x0

  v14 = *(unsigned __int8 *)(a12 + 154);
  v15 = v14 > 0xD;
  v16 = (1 << v14) & 0x3001;
  if ( !v15 && v16 != 0 )
  {
    if ( *(_BYTE *)(a11 + 2612) )
    {
      *(_BYTE *)(a10 + 68) = 1;
      return qdf_mem_copy((void *)(a10 + 932), (const void *)(a11 + 2612), 0x5Cu);
    }
    else
    {
      return (void *)qdf_trace_msg(
                       0x35u,
                       2u,
                       "%s: EHT cap IE is missing in assoc response",
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       "lim_update_stads_eht_caps",
                       v12,
                       v13);
    }
  }
  return result;
}
