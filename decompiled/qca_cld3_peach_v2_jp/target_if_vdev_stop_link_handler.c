__int64 *__fastcall target_if_vdev_stop_link_handler(
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
  unsigned __int16 *v10; // x8
  __int64 v12; // x19
  unsigned int v13; // w22
  unsigned int v14; // w24
  char is_dfs_for_freq; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 (__fastcall *v25)(_QWORD); // x8
  char v26; // w25
  __int64 *result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w8
  __int64 *v37; // x21
  const char *v38; // x2
  const char *v39; // x3
  __int64 v40; // x4
  unsigned int v41; // [xsp+8h] [xbp-18h] BYREF
  __int64 v42; // [xsp+Ch] [xbp-14h]
  int v43; // [xsp+14h] [xbp-Ch]
  __int64 v44; // [xsp+18h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 152);
  v43 = 0;
  v42 = 0;
  if ( !v9 )
  {
    v38 = "%s: pdev is NULL";
    v39 = "target_if_vdev_stop_link_handler";
    goto LABEL_14;
  }
  v10 = *(unsigned __int16 **)(a1 + 32);
  v12 = *(_QWORD *)(v9 + 80);
  v13 = *v10;
  v14 = *((_DWORD *)v10 + 6);
  is_dfs_for_freq = wlan_reg_is_dfs_for_freq(v9, v13, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "target_if_vdev_mgr_get_rx_ops");
    v40 = 255;
LABEL_18:
    result = (__int64 *)qdf_trace_msg(
                          0x68u,
                          2u,
                          "%s: psoc_id:%d No Rx Ops",
                          v16,
                          v17,
                          v18,
                          v19,
                          v20,
                          v21,
                          v22,
                          v23,
                          "target_if_vdev_stop_link_handler",
                          v40);
    goto LABEL_19;
  }
  v24 = *(_QWORD *)(v12 + 2136);
  if ( !v24 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_17;
  }
  v25 = *(__int64 (__fastcall **)(_QWORD))(v24 + 1128);
  if ( !v25 )
  {
LABEL_17:
    v40 = *(unsigned __int8 *)(v12 + 48);
    goto LABEL_18;
  }
  v26 = is_dfs_for_freq;
  if ( *((_DWORD *)v25 - 1) != -868578850 )
    __break(0x8228u);
  result = (__int64 *)v25(v12);
  v36 = *(_DWORD *)(a1 + 16);
  v41 = v14;
  if ( v36 == 1 )
  {
    v37 = result;
    if ( (v26 & 1) != 0
      || (result = (__int64 *)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                v9,
                                v13,
                                &v41,
                                0,
                                v28,
                                v29,
                                v30,
                                v31,
                                v32,
                                v33,
                                v34,
                                v35),
          (_DWORD)result == 2) )
    {
      result = (__int64 *)lmac_get_htc_hdl(v12, v28, v29, v30, v31, v32, v33, v34, v35);
      if ( result )
      {
        if ( *((_BYTE *)v37 + 616) == 1 )
        {
          htc_vote_link_down(result, 4);
          result = (__int64 *)qdf_runtime_pm_allow_suspend(v37 + 75);
          *((_BYTE *)v37 + 616) = 0;
        }
        goto LABEL_19;
      }
      v38 = "%s: HTC handle is NULL";
      v39 = "target_if_vote_for_link_down";
LABEL_14:
      result = (__int64 *)qdf_trace_msg(0x68u, 2u, v38, a2, a3, a4, a5, a6, a7, a8, a9, v39);
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
