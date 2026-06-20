__int64 __fastcall cdp_txrx_set_vdev_param(
        __int64 a1,
        __int64 a2,
        _QWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  _DWORD *v12; // x8
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 result; // x0
  _QWORD v16[4]; // [xsp+0h] [xbp-20h] BYREF

  v16[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && *(_QWORD *)a1 )
  {
    v11 = *(_QWORD *)(*(_QWORD *)a1 + 8LL);
    if ( v11 && (v12 = *(_DWORD **)(v11 + 40)) != nullptr )
    {
      v13 = a3[1];
      v14 = a3[2];
      v16[0] = *a3;
      v16[1] = v13;
      v16[2] = v14;
      if ( *(v12 - 1) != -96731432 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD *))v12)(a1, a2, 8, v16);
    }
    else
    {
      result = qdf_trace_msg(0x89u, 8u, "NULL vdev params callback", a4, a5, a6, a7, a8, a9, a10, a11);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x89u,
               8u,
               "%s: Invalid Instance:",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "cdp_txrx_set_vdev_param");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
