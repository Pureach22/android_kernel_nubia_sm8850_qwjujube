__int64 __fastcall wlan_cdp_set_peer_freq(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        unsigned int a12)
{
  __int64 result; // x0
  __int64 v13; // x8
  _DWORD *v14; // x8

  _ReadStatusReg(SP_EL0);
  if ( a1 && (result = *(_QWORD *)(a1 + 2808)) != 0 && *(_QWORD *)result )
  {
    v13 = *(_QWORD *)(*(_QWORD *)result + 8LL);
    if ( v13 )
    {
      v14 = *(_DWORD **)(v13 + 112);
      if ( v14 )
      {
        if ( *(v14 - 1) != 201075190 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v14)(result, a12, a2, 5);
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x89u,
               8u,
               "%s: Invalid Instance:",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "cdp_txrx_set_peer_param");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
