__int64 __fastcall wlan_send_wfatest_cmd(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w8
  __int64 cmpt_obj; // x0
  __int64 result; // x0
  const char *v13; // x2
  __int64 v14; // x8
  __int64 v15; // x0
  int v16; // w19
  __int64 ext_hdl; // x0
  int v18; // w9
  __int64 v19; // x8
  unsigned int v20; // w9
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v25; // x0
  __int64 (__fastcall *v26)(__int64, __int64); // x8
  const char *v27; // x2
  const char *v28; // x3
  unsigned int v29; // w0
  const char *v30; // x2

  _ReadStatusReg(SP_EL0);
  if ( !a1 || !a2 )
  {
    v13 = "%s: vdev or test params is NULL";
LABEL_26:
    qdf_trace_msg(0x1Fu, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_send_wfatest_cmd");
    result = 16;
    goto LABEL_29;
  }
  v10 = *(_DWORD *)(a2 + 8);
  if ( v10 == 5 )
  {
    v14 = *(_QWORD *)(a1 + 152);
    if ( v14 && (v15 = *(_QWORD *)(v14 + 80)) != 0 )
    {
      v16 = *(unsigned __int8 *)(a2 + 4);
      ext_hdl = wlan_psoc_mlme_get_ext_hdl(v15);
      if ( ext_hdl )
      {
        v18 = *(_DWORD *)(ext_hdl + 7424);
        v19 = ext_hdl;
        result = 0;
        if ( v16 )
          v20 = v18 | 1;
        else
          v20 = v18 & 0xFFFFFFFE;
        *(_DWORD *)(v19 + 7424) = v20;
        goto LABEL_29;
      }
      v27 = "%s: vdev legacy private object is NULL";
    }
    else
    {
      v27 = "%s: psoc object is NULL";
    }
    v28 = "wlan_wfa_set_test_feature_flags";
    v29 = 31;
    goto LABEL_28;
  }
  if ( v10 == 4 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( cmpt_obj )
    {
      result = tgt_vdev_mgr_fils_enable_send(cmpt_obj, a3, a4, a5, a6, a7, a8, a9, a10);
      goto LABEL_29;
    }
    v27 = "%s: failed to get mlme_obj";
    v28 = "wlan_send_wfatest_cmd";
    v29 = 54;
LABEL_28:
    qdf_trace_msg(v29, 2u, v27, a3, a4, a5, a6, a7, a8, a9, a10, v28);
    result = 4;
    goto LABEL_29;
  }
  v21 = *(_QWORD *)(a1 + 152);
  if ( !v21 || (v22 = *(_QWORD *)(v21 + 80)) == 0 )
  {
    v30 = "%s: psoc object is NULL";
LABEL_24:
    qdf_trace_msg(0x1Fu, 2u, v30, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_wfatest_get_tx_ops_from_vdev");
    goto LABEL_25;
  }
  v25 = wlan_psoc_mlme_get_ext_hdl(v22);
  if ( !v25 )
  {
    v30 = "%s: vdev legacy private object is NULL";
    goto LABEL_24;
  }
  v26 = *(__int64 (__fastcall **)(__int64, __int64))(v25 + 7416);
  if ( !v26 )
  {
LABEL_25:
    v13 = "%s: Failed to send WFA test cmd";
    goto LABEL_26;
  }
  if ( *((_DWORD *)v26 - 1) != 647215956 )
    __break(0x8228u);
  result = v26(a1, a2);
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
