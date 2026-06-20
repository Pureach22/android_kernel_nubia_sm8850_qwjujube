__int64 __fastcall target_if_vdev_mgr_set_mac_address_send(
        __int64 a1,
        __int64 a2,
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
  __int64 v11; // x8
  __int64 *v12; // x9
  __int64 v14; // x0
  char v15; // w9
  __int64 result; // x0
  const char *v17; // x2
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  char v26; // [xsp+8h] [xbp-18h] BYREF
  int v27; // [xsp+9h] [xbp-17h]
  __int16 v28; // [xsp+Dh] [xbp-13h]
  int v29; // [xsp+Fh] [xbp-11h]
  __int16 v30; // [xsp+13h] [xbp-Dh]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a3 + 152);
  if ( !v11 )
  {
    v17 = "%s: PDEV is NULL";
    goto LABEL_7;
  }
  v12 = *(__int64 **)(v11 + 1232);
  if ( !v12 || (v14 = *v12) == 0 )
  {
    v17 = "%s: wmi_handle is null";
LABEL_7:
    qdf_trace_msg(0x68u, 2u, v17, a4, a5, a6, a7, a8, a9, a10, a11, "target_if_vdev_mgr_wmi_handle_get");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to get WMI handle!",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "target_if_vdev_mgr_set_mac_address_send");
    result = 4;
    goto LABEL_8;
  }
  v15 = *(_BYTE *)(a3 + 104);
  v27 = a1;
  v29 = a2;
  v26 = v15;
  v28 = WORD2(a1);
  v30 = WORD2(a2);
  result = wmi_unified_send_set_mac_addr(v14, &v26);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
