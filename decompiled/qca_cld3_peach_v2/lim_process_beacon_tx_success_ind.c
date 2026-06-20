__int64 __fastcall lim_process_beacon_tx_success_ind(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 session_by_vdev_id; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  unsigned __int8 *v14; // x25
  __int64 cmpt_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w21
  const char *v25; // x2
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w22
  int v45; // w8
  bool v46; // zf
  int v47; // w8
  char v48; // w8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  const char *v57; // x3
  __int64 v58; // x0
  int v59; // w23
  __int64 v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w21
  __int64 v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int v79; // w22
  __int64 v80; // x0
  __int64 v81; // x8
  __int64 v82; // x24
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // x0
  unsigned int v92; // w23
  char v93; // w8
  char v94; // w9
  char v95; // w8
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // [xsp+18h] [xbp-28h] BYREF
  __int64 v113; // [xsp+20h] [xbp-20h]
  __int64 v114; // [xsp+28h] [xbp-18h]
  int v115; // [xsp+30h] [xbp-10h]
  unsigned __int8 v116[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v117; // [xsp+38h] [xbp-8h]

  v117 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a3 + 4));
  if ( !session_by_vdev_id )
  {
    v25 = "%s: Session Does not exist for given session id";
LABEL_29:
    v57 = "lim_process_beacon_tx_success_ind";
LABEL_30:
    result = qdf_trace_msg(0x35u, 2u, v25, v5, v6, v7, v8, v9, v10, v11, v12, v57);
    goto LABEL_31;
  }
  v13 = session_by_vdev_id;
  v14 = (unsigned __int8 *)(session_by_vdev_id + 7171);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(session_by_vdev_id + 16), v5, v6, v7, v8, v9, v10, v11, v12);
  if ( cmpt_obj )
    v24 = *(unsigned __int8 *)(cmpt_obj + 197);
  else
    v24 = 0;
  v26 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(v13 + 16), v16, v17, v18, v19, v20, v21, v22, v23);
  if ( v26 )
    *(_BYTE *)(v26 + 197) = 0;
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: Vdev %d role: %d swIe: %d opIe: %d switch cnt:%d Is SAP / GO Moved before STA: %d",
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             "lim_process_beacon_tx_success_ind",
             *(unsigned __int8 *)(v13 + 10),
             *(unsigned int *)(v13 + 88),
             *(unsigned __int8 *)(v13 + 7282),
             *v14,
             *(char *)(v13 + 7218),
             v24 & 1);
  if ( *(_DWORD *)(v13 + 88) != 1 )
    goto LABEL_31;
  v44 = *(_DWORD *)(*(_QWORD *)(a1 + 21624) + 20LL);
  result = wlan_get_sap_ch_sw_info(*(_QWORD *)(v13 + 16), v36, v37, v38, v39, v40, v41, v42, v43);
  if ( !result )
  {
    v25 = "%s: Invalid channel info";
    goto LABEL_29;
  }
  if ( *(_BYTE *)(v13 + 7282)
    && (v44 & 0x2000000) == 0
    && ((v45 = *(unsigned __int8 *)(v13 + 7218), v45 != 1)
      ? (v46 = v45 == *(unsigned __int8 *)(result + 46))
      : (v46 = 1),
        !v46 ? (v47 = 0) : (v47 = 1),
        ((v47 | v24) & 1) != 0)
    || *(_BYTE *)(v13 + 7284) )
  {
    result = lim_process_ap_ecsa_timeout(v13);
  }
  if ( *v14 )
    *v14 = 0;
  if ( *(_DWORD *)(v13 + 88) == 1 && *(char *)(v13 + 8745) < 0 )
  {
    v48 = *(_BYTE *)(v13 + 8767);
    if ( (v48 & 0x3F) != 0 )
    {
      v115 = 0;
      v113 = 0;
      v114 = 0;
      v112 = 0;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Vdev %d countdown: %d, new_color: %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "lim_handle_bss_color_change_ie",
        *(unsigned __int8 *)(v13 + 10),
        *(unsigned __int8 *)(v13 + 8766),
        v48 & 0x3F);
      if ( *(_BYTE *)(v13 + 8766) )
      {
        --*(_BYTE *)(v13 + 8766);
LABEL_52:
        if ( !(unsigned int)sch_set_fixed_beacon_fields(a1, v13) )
        {
          lim_send_beacon_ind(a1, v13, 4u, v5, v6, v7, v8, v9, v10, v11, v12);
          result = qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: Updated BSS color change countdown = %d",
                     v104,
                     v105,
                     v106,
                     v107,
                     v108,
                     v109,
                     v110,
                     v111,
                     "lim_send_bss_color_change_ie_update",
                     *(unsigned __int8 *)(v13 + 8766));
          goto LABEL_31;
        }
        v25 = "%s: Unable to set BSS color change IE in beacon";
        v57 = "lim_send_bss_color_change_ie_update";
        goto LABEL_30;
      }
      v58 = *(_QWORD *)(v13 + 16);
      v59 = *(unsigned __int8 *)(v13 + 10);
      *(_BYTE *)(v13 + 9776) = 0;
      v116[0] = 0;
      v60 = wlan_vdev_mlme_get_cmpt_obj(v58, v49, v50, v51, v52, v53, v54, v55, v56);
      if ( v60 )
        v69 = *(unsigned __int8 *)(v60 + 198);
      else
        v69 = 0;
      v70 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(v13 + 16), v61, v62, v63, v64, v65, v66, v67, v68);
      if ( !v70
        || (v79 = *(unsigned __int8 *)(v70 + 199), !*(_BYTE *)(v70 + 199))
        || !v69
        || (v80 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(v13 + 16), v71, v72, v73, v74, v75, v76, v77, v78)) == 0
        || *(_BYTE *)(v80 + 202) != 1 )
      {
LABEL_51:
        qdf_mem_set(&v112, 0x1Cu, 0);
        v94 = *(_BYTE *)(v13 + 8767);
        v95 = *(_BYTE *)(v13 + 8745) & 0x40 | v94 & 0x3F;
        *(_BYTE *)(v13 + 8767) = v94 & 0xC0;
        *(_BYTE *)(v13 + 8745) = v95;
        LOBYTE(v115) = 0;
        HIDWORD(v114) = v94 & 0x3F;
        HIWORD(v113) |= 0x800u;
        lim_send_beacon_params(a1, (unsigned __int16 *)&v112, v13);
        lim_send_obss_color_collision_cfg(a1, v13, 1u, v96, v97, v98, v99, v100, v101, v102, v103);
        wma_allow_suspend_after_obss_color_change(*(_QWORD *)(v13 + 16));
        goto LABEL_52;
      }
      v81 = *(_QWORD *)(*(_QWORD *)(v13 + 16) + 216LL);
      if ( v81 )
        v82 = *(_QWORD *)(v81 + 80);
      else
        v82 = 0;
      policy_mgr_get_mac_id_by_session_id(v82, v59, v116);
      if ( (unsigned int)policy_mgr_get_conc_vdev_on_same_mac(v82, v59, v116[0]) == 255
        || (policy_mgr_sr_same_mac_conc_enabled(v82, v83, v84, v85, v86, v87, v88, v89, v90) & 1) != 0 )
      {
        v91 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(v13 + 16), v83, v84, v85, v86, v87, v88, v89, v90);
        v92 = 1;
        if ( v91 )
        {
          v93 = 0;
LABEL_49:
          *(_BYTE *)(v91 + 203) = v93;
        }
      }
      else
      {
        v91 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(v13 + 16), v83, v84, v85, v86, v87, v88, v89, v90);
        v92 = 0;
        v79 = 128;
        if ( v91 )
        {
          v93 = 1;
          goto LABEL_49;
        }
      }
      wlan_spatial_reuse_config_set(*(_QWORD *)(v13 + 16), v69, v79);
      wlan_spatial_reuse_osif_event(*(_QWORD *)(v13 + 16), v92, 1);
      goto LABEL_51;
    }
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
