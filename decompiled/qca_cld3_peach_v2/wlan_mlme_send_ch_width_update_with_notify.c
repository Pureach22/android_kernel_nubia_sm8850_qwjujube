__int64 __fastcall wlan_mlme_send_ch_width_update_with_notify(
        __int64 a1,
        _QWORD *a2,
        unsigned __int8 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 ext_hdl; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int16 *v25; // x23
  __int64 v26; // x24
  unsigned int v27; // w6
  unsigned int v28; // w6
  const char *v29; // x2
  __int64 result; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w26
  __int64 v40; // x7
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int16 *v50; // x24
  void *v51; // x25
  __int64 v52; // x27
  __int64 v53; // x0
  unsigned int v54; // w23
  unsigned __int8 v55; // w8
  int v56; // w8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w8
  __int64 v66; // x5
  unsigned int v67; // w19
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  int v76; // w23
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 cmpt_obj; // x0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned int v94; // w23
  unsigned int v95; // w21
  unsigned int v96; // [xsp+20h] [xbp-20h] BYREF
  __int64 v97; // [xsp+24h] [xbp-1Ch]
  __int64 v98; // [xsp+2Ch] [xbp-14h]
  int v99; // [xsp+34h] [xbp-Ch]
  __int64 v100; // [xsp+38h] [xbp-8h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ext_hdl = wlan_vdev_mlme_get_ext_hdl((__int64)a2, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( ext_hdl )
  {
    v25 = (unsigned __int16 *)a2[5];
    if ( v25 )
    {
      v26 = ext_hdl + 20480;
      v27 = *(_DWORD *)(ext_hdl + 24252);
      if ( v27 == 8 )
      {
        v28 = *(_DWORD *)(ext_hdl + 24248);
        if ( v28 == 8 || v28 < a4 )
        {
          v29 = "%s: vdev %d: Invalid new chwidth:%d, assoc ch_width:%d";
LABEL_10:
          qdf_trace_msg(
            0x68u,
            8u,
            v29,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "wlan_mlme_send_ch_width_update_with_notify",
            a3,
            a4);
          result = 4;
          goto LABEL_29;
        }
      }
      else if ( v27 < a4 )
      {
        v29 = "%s: vdev %d: Invalid new chwidth:%d, cur_ch_width:%d";
        goto LABEL_10;
      }
      if ( wlan_reg_is_24ghz_ch_freq(*v25) )
      {
        v39 = a4;
        if ( a4 )
        {
          if ( a4 != 1 )
          {
            v40 = *(unsigned int *)(v26 + 3780);
            goto LABEL_25;
          }
          v39 = *(_DWORD *)(v26 + 3780);
          if ( !v39 )
          {
            v40 = 0;
LABEL_25:
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: vdev %d: CW:%d update not supported for freq:%d sec_2g_freq %d",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "wlan_mlme_send_ch_width_update_with_notify",
              a3,
              a4,
              *v25,
              v40);
            result = 11;
            goto LABEL_29;
          }
        }
      }
      else
      {
        v39 = 0;
      }
      v99 = 0;
      v98 = 0;
      v97 = 0;
      v41 = wlan_vdev_mlme_get_ext_hdl((__int64)a2, v31, v32, v33, v34, v35, v36, v37, v38);
      if ( v41 )
      {
        v50 = (unsigned __int16 *)a2[5];
        if ( !v50 || (v51 = (void *)a2[4]) == nullptr )
        {
          v65 = 16;
LABEL_28:
          v66 = a4;
          v67 = v65;
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev %d: Failed to update CW:%d to host, status:%d",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "wlan_mlme_send_ch_width_update_with_notify",
            a3,
            v66,
            v65);
          result = v67;
          goto LABEL_29;
        }
        v52 = v41;
        v53 = a2[27];
        if ( v53 )
        {
          v96 = a4;
          v54 = *v50;
          wlan_reg_set_channel_params_for_pwrmode(
            v53,
            v54,
            v39,
            (__int64)&v96,
            0,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49);
          v55 = BYTE1(v97);
          v50[16] = 0;
          *(unsigned __int16 *)((char *)v50 + 3) = __PAIR16__(BYTE2(v97), v55);
          v56 = HIDWORD(v97);
          *((_DWORD *)v50 + 5) = v98;
          *((_DWORD *)v50 + 6) = a4;
          *((_DWORD *)v50 + 4) = v56;
          if ( !(unsigned int)wlan_update_peer_phy_mode(v50, a2) )
          {
            *(_BYTE *)(v52 + 24256) = 0;
            qdf_mem_copy(v51, v50, 0x28u);
            qdf_trace_msg(
              0x1Fu,
              8u,
              "%s: vdev id %d freq %d seg0 %d seg1 %d ch_width %d mhz seg0 %d mhz seg1 %d",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "wlan_mlme_update_ch_width",
              a3,
              v54,
              BYTE1(v97),
              BYTE2(v97),
              v96,
              HIDWORD(v97),
              v98);
            v76 = target_if_phy_ch_width_to_wmi_chan_width(a4);
            cmpt_obj = wlan_vdev_mlme_get_cmpt_obj((__int64)a2, v77, v78, v79, v80, v81, v82, v83, v84);
            if ( cmpt_obj )
            {
              HIDWORD(v97) = v76;
              v96 = a3;
              LODWORD(v97) = 186;
              v94 = tgt_vdev_mgr_set_param_send(cmpt_obj, (__int64)&v96, v86, v87, v88, v89, v90, v91, v92, v93);
              policy_mgr_handle_ml_sta_link_on_traffic_type_change(a1, (__int64)a2);
              v95 = v94;
              if ( !v94 )
              {
                result = 0;
                goto LABEL_29;
              }
            }
            else
            {
              v95 = 16;
            }
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: vdev %d: Failed to update CW:%d to fw, status:%d",
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              "wlan_mlme_send_ch_width_update_with_notify",
              a3,
              a4,
              v95);
            result = v95;
            goto LABEL_29;
          }
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: Failed to update phymode",
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            "wlan_mlme_update_ch_width");
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev %d: Pdev is NULL",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "wlan_mlme_update_ch_width",
            a3);
        }
      }
      v65 = 4;
      goto LABEL_28;
    }
  }
  result = 4;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
