__int64 __fastcall wlan_hdd_set_multipass(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  _DWORD *v20; // x8
  __int64 v21; // x1
  __int64 result; // x0
  char v23; // [xsp+0h] [xbp-20h] BYREF
  __int64 v24; // [xsp+1h] [xbp-1Fh]
  _BYTE v25[23]; // [xsp+9h] [xbp-17h]

  *(_QWORD *)&v25[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"wlan_hdd_set_multipass", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context && *context )
  {
    v19 = *(_QWORD *)(*context + 8LL);
    if ( v19 && (v20 = *(_DWORD **)(v19 + 40)) != nullptr )
    {
      v21 = *(unsigned __int8 *)(a1 + 104);
      v24 = 0;
      v23 = 1;
      *(_QWORD *)v25 = 0;
      *(_QWORD *)&v25[7] = 0;
      if ( *(v20 - 1) != -96731432 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, char *))v20)(context, v21, 11, &v23);
    }
    else
    {
      result = qdf_trace_msg(0x89u, 8u, "NULL vdev params callback", v11, v12, v13, v14, v15, v16, v17, v18);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x89u,
               8u,
               "%s: Invalid Instance:",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "cdp_txrx_set_vdev_param");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
