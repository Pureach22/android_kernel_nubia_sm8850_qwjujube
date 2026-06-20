__int64 __fastcall wlan_mlme_send_ch_width_update_with_notify(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10,
        unsigned __int8 a11,
        unsigned int a12)
{
  __int64 ext_hdl; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int16 *v24; // x22
  __int64 v25; // x23
  unsigned int v26; // w6
  unsigned int v27; // w6
  const char *v28; // x2
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w25
  __int64 v39; // x7
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int16 *v49; // x23
  void *v50; // x24
  __int64 v51; // x26
  __int64 v52; // x0
  unsigned int v53; // w22
  int v54; // w8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w8
  __int64 v64; // x5
  unsigned int v65; // w19
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  int v74; // w22
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 cmpt_obj; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  unsigned int v92; // w21
  unsigned int v93; // [xsp+18h] [xbp-18h] BYREF
  __int64 v94; // [xsp+1Ch] [xbp-14h]
  int v95; // [xsp+24h] [xbp-Ch]
  __int64 v96; // [xsp+28h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ext_hdl = wlan_vdev_mlme_get_ext_hdl((__int64)a10, a1, a2, a3, a4, a5, a6, a7, a8);
  if ( ext_hdl && (v24 = (unsigned __int16 *)a10[5]) != nullptr )
  {
    v25 = ext_hdl + 20480;
    v26 = *(_DWORD *)(ext_hdl + 24252);
    if ( v26 == 8 )
    {
      v27 = *(_DWORD *)(ext_hdl + 24248);
      if ( v27 == 8 || v27 < a12 )
      {
        v28 = "%s: vdev %d: Invalid new chwidth:%d, assoc ch_width:%d";
LABEL_10:
        qdf_trace_msg(
          0x68u,
          8u,
          v28,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "wlan_mlme_send_ch_width_update_with_notify",
          a11,
          a12);
        result = 4;
        goto LABEL_29;
      }
    }
    else if ( v26 < a12 )
    {
      v28 = "%s: vdev %d: Invalid new chwidth:%d, cur_ch_width:%d";
      goto LABEL_10;
    }
    if ( wlan_reg_is_24ghz_ch_freq(*v24) )
    {
      LOWORD(v38) = a12;
      if ( a12 )
      {
        if ( a12 != 1 )
        {
          v39 = *(unsigned int *)(v25 + 3780);
          goto LABEL_25;
        }
        v38 = *(_DWORD *)(v25 + 3780);
        if ( !v38 )
        {
          v39 = 0;
LABEL_25:
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: vdev %d: CW:%d update not supported for freq:%d sec_2g_freq %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "wlan_mlme_send_ch_width_update_with_notify",
            a11,
            a12,
            *v24,
            v39);
          result = 11;
          goto LABEL_29;
        }
      }
    }
    else
    {
      LOWORD(v38) = 0;
    }
    v95 = 0;
    v94 = 0;
    v40 = wlan_vdev_mlme_get_ext_hdl((__int64)a10, v30, v31, v32, v33, v34, v35, v36, v37);
    if ( !v40 )
      goto LABEL_27;
    v49 = (unsigned __int16 *)a10[5];
    if ( !v49 || (v50 = (void *)a10[4]) == nullptr )
    {
      v63 = 16;
LABEL_28:
      v64 = a12;
      v65 = v63;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d: Failed to update CW:%d to host, status:%d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "wlan_mlme_send_ch_width_update_with_notify",
        a11,
        v64,
        v63);
      result = v65;
      goto LABEL_29;
    }
    v51 = v40;
    v52 = a10[19];
    if ( !v52 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d: Pdev is NULL",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "wlan_mlme_update_ch_width",
        a11);
      goto LABEL_27;
    }
    v93 = a12;
    v53 = *v49;
    wlan_reg_set_channel_params_for_pwrmode(v52, v53, v38, (__int64)&v93, 0, v41, v42, v43, v44, v45, v46, v47, v48);
    *(unsigned __int16 *)((char *)v49 + 3) = *(_WORD *)((char *)&v94 + 1);
    v54 = HIDWORD(v94);
    *((_DWORD *)v49 + 5) = v95;
    *((_DWORD *)v49 + 6) = a12;
    *((_DWORD *)v49 + 4) = v54;
    if ( (unsigned int)wlan_update_peer_phy_mode(v49, a10) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Failed to update phymode",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "wlan_mlme_update_ch_width");
LABEL_27:
      v63 = 4;
      goto LABEL_28;
    }
    *(_BYTE *)(v51 + 24256) = 0;
    qdf_mem_copy(v50, v49, 0x20u);
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: vdev id %d freq %d seg0 %d seg1 %d ch_width %d mhz seg0 %d mhz seg1 %d",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "wlan_mlme_update_ch_width",
      a11,
      v53,
      BYTE1(v94),
      BYTE2(v94),
      v93,
      HIDWORD(v94),
      v95);
    v74 = target_if_phy_ch_width_to_wmi_chan_width(a12);
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj((__int64)a10, v75, v76, v77, v78, v79, v80, v81, v82);
    if ( cmpt_obj )
    {
      HIDWORD(v94) = v74;
      v93 = a11;
      LODWORD(v94) = 186;
      result = tgt_vdev_mgr_set_param_send(cmpt_obj, (__int64)&v93, v84, v85, v86, v87, v88, v89, v90, v91);
      v92 = result;
      if ( !(_DWORD)result )
        goto LABEL_29;
    }
    else
    {
      v92 = 16;
    }
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d: Failed to update CW:%d to fw, status:%d",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      "wlan_mlme_send_ch_width_update_with_notify",
      a11,
      a12,
      v92);
    result = v92;
  }
  else
  {
    result = 4;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
