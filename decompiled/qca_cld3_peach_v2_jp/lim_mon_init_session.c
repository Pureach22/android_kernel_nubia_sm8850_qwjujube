__int64 __fastcall lim_mon_init_session(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x3
  __int64 v4; // x5
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int8 *)(a1 + 12272);
  v4 = a2[4];
  v14[0] = 0;
  result = ((__int64 (__fastcall *)(__int64, unsigned __int8 *, _BYTE *, __int64, __int64, __int64))pe_create_session)(
             a1,
             a2 + 5,
             v14,
             v3,
             3,
             v4);
  if ( result )
    *(_BYTE *)(result + 7170) = 1;
  else
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Monitor mode: Session Can not be created bssid: %02x:%02x:%02x:**:**:%02x",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "lim_mon_init_session",
               a2[5],
               a2[6],
               a2[7],
               a2[10]);
  _ReadStatusReg(SP_EL0);
  return result;
}
