__int64 __fastcall tgt_vdev_mgr_cdp_vdev_attach(
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
  __int64 v9; // x20
  __int64 v10; // x21
  __int64 v11; // x8
  __int64 **v12; // x19
  char v13; // w9
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w9
  __int64 v23; // x8
  __int64 (__fastcall *v24)(__int64 **, __int64, __int64 *); // x8
  __int64 v25; // x1
  __int64 result; // x0
  __int64 v27; // [xsp+8h] [xbp-28h] BYREF
  __int64 v28; // [xsp+10h] [xbp-20h]
  int cdp_txrx_subtype; // [xsp+18h] [xbp-18h]
  int v30; // [xsp+1Ch] [xbp-14h]
  __int64 v31; // [xsp+20h] [xbp-10h]
  __int64 v32; // [xsp+28h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 520);
  v28 = 0;
  v10 = *(_QWORD *)(v9 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: psoc object is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_vdev_mgr_cdp_vdev_attach");
    result = 4;
    goto LABEL_13;
  }
  v12 = *(__int64 ***)(v11 + 2808);
  if ( !v12 )
  {
LABEL_12:
    result = 16;
    goto LABEL_13;
  }
  v13 = *(_BYTE *)(v9 + 168);
  v27 = v9 + 74;
  LOBYTE(v28) = v13;
  HIDWORD(v28) = wlan_util_vdev_get_cdp_txrx_opmode(v9);
  cdp_txrx_subtype = wlan_util_vdev_get_cdp_txrx_subtype(v9);
  v22 = *(_DWORD *)(v9 + 16);
  v31 = v9 + 80;
  v30 = v22;
  if ( !*v12 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v14, v15, v16, v17, v18, v19, v20, v21, "cdp_vdev_attach");
    goto LABEL_12;
  }
  v23 = **v12;
  if ( !v23 )
    goto LABEL_12;
  v24 = *(__int64 (__fastcall **)(__int64 **, __int64, __int64 *))(v23 + 16);
  if ( !v24 )
    goto LABEL_12;
  v25 = *(unsigned __int8 *)(v10 + 40);
  if ( *((_DWORD *)v24 - 1) != -738885604 )
    __break(0x8228u);
  result = v24(v12, v25, &v27);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
