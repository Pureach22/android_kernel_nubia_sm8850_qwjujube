__int64 __fastcall target_if_vdev_set_tx_rx_decap_type(
        __int64 a1,
        int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x10
  __int64 v12; // x10
  __int64 v14; // x0
  __int64 v16; // x1
  __int64 v17; // x8
  __int64 (__fastcall *v18)(__int64, __int64, __int64, int *); // x8
  __int64 v19; // x2
  __int64 result; // x0
  __int64 v21; // x8
  int v22; // [xsp+0h] [xbp-20h] BYREF
  __int64 v23; // [xsp+4h] [xbp-1Ch]
  __int64 v24; // [xsp+Ch] [xbp-14h]
  int v25; // [xsp+14h] [xbp-Ch]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 216);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 || (v14 = *(_QWORD *)(v12 + 2808)) == 0 )
  {
    result = 4;
    goto LABEL_22;
  }
  v16 = *(unsigned __int8 *)(a1 + 168);
  if ( a2 == 14 )
  {
    if ( *(_QWORD *)v14 )
    {
      v21 = *(_QWORD *)(*(_QWORD *)v14 + 8LL);
      if ( v21 )
      {
        v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64, int *))(v21 + 40);
        if ( v18 )
        {
          v22 = a3;
          v19 = 13;
          goto LABEL_15;
        }
      }
      goto LABEL_19;
    }
LABEL_20:
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a4, a5, a6, a7, a8, a9, a10, a11, "cdp_txrx_set_vdev_param");
    goto LABEL_21;
  }
  if ( a2 != 13 )
  {
    result = 0;
    goto LABEL_22;
  }
  if ( !*(_QWORD *)v14 )
    goto LABEL_20;
  v17 = *(_QWORD *)(*(_QWORD *)v14 + 8LL);
  if ( !v17 || (v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64, int *))(v17 + 40)) == nullptr )
  {
LABEL_19:
    qdf_trace_msg(0x89u, 8u, "NULL vdev params callback", a4, a5, a6, a7, a8, a9, a10, a11);
LABEL_21:
    result = 16;
    goto LABEL_22;
  }
  v22 = a3;
  v19 = 12;
LABEL_15:
  v23 = 0;
  v24 = 0;
  v25 = 0;
  if ( *((_DWORD *)v18 - 1) != -96731432 )
    __break(0x8228u);
  result = v18(v14, v16, v19, &v22);
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
