__int64 __fastcall dp_tx_update_eapol_comp_status_stats(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int8 a5,
        unsigned int a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  unsigned __int8 v15; // w19
  _DWORD *v17; // x9
  unsigned int v18; // w8
  __int64 v19; // x0
  __int64 v20; // x21
  char v21; // w22
  __int64 v22; // x8
  __int64 v23; // x8

  if ( (unsigned __int8)a6 >= 7u )
    return qdf_trace_msg(
             0x7Du,
             2u,
             "%s: Invalid Tx status Received",
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             "dp_tx_update_eapol_comp_status_stats");
  v15 = a6;
  v17 = *(_DWORD **)(*(_QWORD *)(result + 8) + 328LL);
  if ( v17 )
  {
    v18 = *(unsigned __int8 *)(a2 + 59);
    v19 = *(_QWORD *)(result + 16);
    v20 = a4;
    v21 = a7;
    if ( *(v17 - 1) != -428814833 )
      __break(0x8229u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v17)(v19, a3, v18, a6);
    a7 = v21;
    a4 = v20;
  }
  if ( (a7 & 1) != 0 )
  {
    if ( a4 )
    {
      v22 = a4 + 3256LL * a5 + 4LL * v15;
      ++*(_DWORD *)(v22 + 2776);
    }
  }
  else if ( a4 )
  {
    v23 = a4 + 3256LL * a5 + 4LL * v15;
    ++*(_DWORD *)(v23 + 2804);
  }
  return result;
}
