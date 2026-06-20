__int64 __fastcall dp_rx_tid_update_cb(
        __int64 result,
        unsigned int *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x5

  v13 = *(unsigned int *)(a3 + 4);
  if ( (_DWORD)v13 )
  {
    if ( (_DWORD)v13 != 255 )
      return qdf_trace_msg(
               0x81u,
               2u,
               "%s: %pK: Rx tid HW desc update failed(%d): tid %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "dp_rx_tid_update_cb",
               result,
               v13,
               *a2,
               v11,
               v12);
  }
  return result;
}
