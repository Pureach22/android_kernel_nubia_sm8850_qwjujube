__int64 __fastcall cdp_txrx_set_psoc_param(
        __int64 a1,
        __int64 a2,
        __int64 *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  _DWORD *v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 result; // x0
  _QWORD v17[4]; // [xsp+0h] [xbp-20h] BYREF

  v17[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*(_QWORD *)a1 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a5, a6, a7, a8, a9, a10, a11, a12, "cdp_txrx_set_psoc_param");
LABEL_9:
    result = 16;
    goto LABEL_10;
  }
  v12 = *(_QWORD *)(*(_QWORD *)a1 + 8LL);
  if ( !v12 )
    goto LABEL_9;
  v13 = *(_DWORD **)(v12 + 184);
  if ( !v13 )
    goto LABEL_9;
  v14 = *a3;
  v15 = a3[1];
  v17[2] = a3[2];
  v17[0] = v14;
  v17[1] = v15;
  if ( *(v13 - 1) != -503247959 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v13)(a1, a2, v17, a4);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
