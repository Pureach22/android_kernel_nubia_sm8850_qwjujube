__int64 *__fastcall target_if_vdev_start_link_handler(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x22
  unsigned __int16 *v11; // x8
  __int64 v14; // x19
  unsigned int v15; // w20
  unsigned int v16; // w25
  int is_dfs_for_freq; // w21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int _5g_bonded_channel_state_for_pwrmode; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  __int64 (__fastcall *v36)(_QWORD); // x8
  int v37; // w25
  __int64 *result; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 *v47; // x20
  unsigned __int16 *v48; // x8
  unsigned int v49; // w23
  unsigned int v50; // w26
  int v51; // w24
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w22
  int v61; // w8
  const char *v62; // x2
  const char *v63; // x3
  __int64 v64; // x4
  unsigned int v65; // [xsp+8h] [xbp-18h] BYREF
  __int64 v66; // [xsp+Ch] [xbp-14h]
  int v67; // [xsp+14h] [xbp-Ch]
  __int64 v68; // [xsp+18h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 152);
  v67 = 0;
  v66 = 0;
  if ( !v10 )
  {
    v62 = "%s: pdev is NULL";
    v63 = "target_if_vdev_start_link_handler";
    goto LABEL_15;
  }
  v11 = *(unsigned __int16 **)(a1 + 40);
  v14 = *(_QWORD *)(v10 + 80);
  v15 = *v11;
  v16 = *((_DWORD *)v11 + 6);
  is_dfs_for_freq = wlan_reg_is_dfs_for_freq(v10, v15, a3, a4, a5, a6, a7, a8, a9, a10);
  v65 = v16;
  _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                           v10,
                                           v15,
                                           &v65,
                                           0,
                                           v18,
                                           v19,
                                           v20,
                                           v21,
                                           v22,
                                           v23,
                                           v24,
                                           v25);
  if ( !v14 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "target_if_vdev_mgr_get_rx_ops");
    v64 = 255;
LABEL_19:
    result = (__int64 *)qdf_trace_msg(
                          0x68u,
                          2u,
                          "%s: psoc_id:%d No Rx Ops",
                          v27,
                          v28,
                          v29,
                          v30,
                          v31,
                          v32,
                          v33,
                          v34,
                          "target_if_vdev_start_link_handler",
                          v64);
    goto LABEL_20;
  }
  v35 = *(_QWORD *)(v14 + 2136);
  if ( !v35 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_18;
  }
  v36 = *(__int64 (__fastcall **)(_QWORD))(v35 + 1128);
  if ( !v36 )
  {
LABEL_18:
    v64 = *(unsigned __int8 *)(v14 + 48);
    goto LABEL_19;
  }
  v37 = _5g_bonded_channel_state_for_pwrmode;
  if ( *((_DWORD *)v36 - 1) != -868578850 )
    __break(0x8228u);
  result = (__int64 *)v36(v14);
  if ( *(_DWORD *)(a1 + 16) == 1 )
  {
    v47 = result;
    if ( (a2 & 1) == 0 )
    {
      if ( !(is_dfs_for_freq & 1 | (v37 == 2)) )
        goto LABEL_20;
      goto LABEL_25;
    }
    v48 = *(unsigned __int16 **)(a1 + 32);
    v49 = *v48;
    v50 = *((_DWORD *)v48 + 6);
    v51 = wlan_reg_is_dfs_for_freq(v10, v49, v39, v40, v41, v42, v43, v44, v45, v46);
    v65 = v50;
    result = (__int64 *)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                          v10,
                          v49,
                          &v65,
                          0,
                          v52,
                          v53,
                          v54,
                          v55,
                          v56,
                          v57,
                          v58,
                          v59);
    v60 = ((_DWORD)result != 2) & ~v51;
    v61 = v37;
    if ( !(v60 | is_dfs_for_freq & 1) && v37 != 2 )
    {
      result = (__int64 *)lmac_get_htc_hdl(v14, v39, v40, v41, v42, v43, v44, v45, v46);
      if ( result )
      {
        v61 = v37;
        if ( *((_BYTE *)v47 + 616) == 1 )
        {
          htc_vote_link_down(result, 4);
          result = (__int64 *)qdf_runtime_pm_allow_suspend(v47 + 75);
          v61 = v37;
          *((_BYTE *)v47 + 616) = 0;
        }
      }
      else
      {
        result = (__int64 *)qdf_trace_msg(
                              0x68u,
                              2u,
                              "%s: HTC handle is NULL",
                              v39,
                              v40,
                              v41,
                              v42,
                              v43,
                              v44,
                              v45,
                              v46,
                              "target_if_vote_for_link_down");
        v61 = v37;
      }
    }
    if ( (v60 & (is_dfs_for_freq | (v61 == 2))) == 1 )
    {
LABEL_25:
      result = (__int64 *)lmac_get_htc_hdl(v14, v39, v40, v41, v42, v43, v44, v45, v46);
      if ( result )
      {
        if ( (v47[77] & 1) == 0 )
        {
          htc_vote_link_up(result, 4);
          result = (__int64 *)qdf_runtime_pm_prevent_suspend(v47 + 75);
          *((_BYTE *)v47 + 616) = 1;
        }
        goto LABEL_20;
      }
      v62 = "%s: HTC handle is NULL";
      v63 = "target_if_vote_for_link_up";
LABEL_15:
      result = (__int64 *)qdf_trace_msg(0x68u, 2u, v62, a3, a4, a5, a6, a7, a8, a9, a10, v63);
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
