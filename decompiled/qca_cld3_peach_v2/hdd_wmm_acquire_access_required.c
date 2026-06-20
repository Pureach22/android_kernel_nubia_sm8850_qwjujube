__int64 __fastcall hdd_wmm_acquire_access_required(
        __int64 result,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  char v12; // w10

  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      v12 = 11;
      goto LABEL_11;
    }
    if ( a2 == 3 )
    {
      *(_BYTE *)(result + 41696) &= 7u;
      return result;
    }
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid AC Type",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hdd_wmm_acquire_access_required",
             v10,
             v11);
  }
  if ( !a2 )
  {
    *(_BYTE *)(result + 41696) &= 0xEu;
    return result;
  }
  if ( a2 != 1 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid AC Type",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hdd_wmm_acquire_access_required",
             v10,
             v11);
  v12 = 13;
LABEL_11:
  *(_BYTE *)(result + 41696) &= v12;
  return result;
}
