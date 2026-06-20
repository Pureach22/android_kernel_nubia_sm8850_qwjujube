__int64 __fastcall hdd_indicate_mgmt_frame_to_user(
        unsigned __int8 *a1,
        unsigned int a2,
        unsigned __int8 *a3,
        unsigned __int8 a4,
        unsigned int a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 adapter_by_macaddr; // x23
  unsigned int v28; // w9
  __int64 *v29; // x22
  unsigned int v30; // w25
  int v31; // w9
  int v32; // w10
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x28
  int v43; // w8
  int v44; // w9
  int v45; // w10
  int v46; // w12
  const char *v47; // x2
  const char *v48; // x2
  __int64 v49; // x4
  unsigned __int64 StatusReg; // x8
  unsigned int *v51; // x8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x1
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x8
  unsigned __int64 v80; // x28
  const char *v81; // x2
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x26
  __int64 v91; // x8
  __int64 v92; // x26
  __int64 v93; // x10
  __int64 v94; // x1
  _QWORD *v95; // x10
  __int64 v96; // x0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x27
  double v106; // d0
  unsigned int *v107; // x8
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  unsigned int *v123; // x8
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x8
  __int64 v133; // [xsp+0h] [xbp-A0h]
  int v134; // [xsp+2Ch] [xbp-74h]
  __int64 v137; // [xsp+40h] [xbp-60h] BYREF
  __int64 v138; // [xsp+48h] [xbp-58h] BYREF
  __int64 v139; // [xsp+50h] [xbp-50h] BYREF
  bool v140; // [xsp+5Ch] [xbp-44h] BYREF
  _DWORD v141[2]; // [xsp+60h] [xbp-40h] BYREF
  __int64 v142; // [xsp+68h] [xbp-38h]
  unsigned __int8 *v143; // [xsp+70h] [xbp-30h]
  __int64 v144; // [xsp+78h] [xbp-28h]
  __int64 v145; // [xsp+80h] [xbp-20h]
  __int64 v146; // [xsp+88h] [xbp-18h]
  __int64 v147; // [xsp+90h] [xbp-10h]
  __int64 v148; // [xsp+98h] [xbp-8h]

  v148 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v137 = 0;
  if ( !a1 )
  {
    v47 = "%s: link info is null";
LABEL_28:
    result = qdf_trace_msg(0x33u, 2u, v47, a7, a8, a9, a10, a11, a12, a13, a14, "hdd_indicate_mgmt_frame_to_user");
    goto LABEL_29;
  }
  if ( **(_DWORD **)a1 != 1885692259 )
  {
    v47 = "%s: invalid adapter";
    goto LABEL_28;
  }
  result = _osif_vdev_sync_op_start(*(_QWORD *)(*(_QWORD *)a1 + 32LL), &v137, "hdd_indicate_mgmt_frame_to_user");
  if ( !(_DWORD)result )
  {
    v140 = 0;
    v138 = 0;
    v139 = 0;
    adapter_by_macaddr = *(_QWORD *)a1;
    if ( *(_QWORD *)a1 )
    {
      if ( !a2 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Frame Length is ZERO, for frame %d rx freq %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "__hdd_indicate_mgmt_frame_to_user",
          a4,
          a5);
        goto LABEL_34;
      }
      if ( a3 )
      {
        v28 = *a3;
        v29 = *(__int64 **)(adapter_by_macaddr + 24);
        v30 = v28 >> 4;
        v31 = v28 & 0xC;
        if ( !v31 && a2 >= 0x1B && v30 == 11 )
        {
          v32 = *((unsigned __int16 *)a3 + 12);
          if ( v32 == 7 )
            goto LABEL_38;
          if ( v32 == 2 && (*(_DWORD *)(adapter_by_macaddr + 40) | 2) == 3 )
            a1[2367] = 1;
        }
        if ( v31 || v30 == 4 )
          goto LABEL_38;
        if ( *((_DWORD *)a3 + 1) == -1 && *((__int16 *)a3 + 4) == -1 )
          goto LABEL_38;
        adapter_by_macaddr = hdd_get_adapter_by_macaddr((__int64)v29, a3 + 4);
        if ( adapter_by_macaddr )
          goto LABEL_38;
        adapter_by_macaddr = hdd_get_adapter_by_rand_macaddr(v29, a3 + 4);
        if ( adapter_by_macaddr )
          goto LABEL_38;
        adapter_by_macaddr = hdd_find_adapter_for_nan_oui_frames(v29, a2, a3, v30);
        if ( adapter_by_macaddr )
          goto LABEL_38;
        v42 = jiffies;
        if ( _hdd_indicate_mgmt_frame_to_user___last_ticks - jiffies + 125 < 0 )
        {
          if ( a3 == (unsigned __int8 *)-4LL )
          {
            v45 = 0;
            v43 = 0;
            v44 = 0;
            v46 = 0;
          }
          else
          {
            v43 = a3[4];
            v44 = a3[5];
            v45 = a3[6];
            v46 = a3[9];
          }
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: No adapter found for type %d subtype %d len %d freq %d, dest addr %02x:%02x:%02x:**:**:%02x",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "__hdd_indicate_mgmt_frame_to_user",
            a4,
            v30,
            a2,
            a5,
            v43,
            v44,
            v45,
            v46);
          _hdd_indicate_mgmt_frame_to_user___last_ticks = v42;
        }
        adapter_by_macaddr = hdd_get_adapter((__int64)v29, 8);
        if ( adapter_by_macaddr )
        {
LABEL_38:
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v29 + 4);
          }
          else
          {
            raw_spin_lock_bh(v29 + 4);
            v29[5] |= 1uLL;
          }
          hdd_get_front_adapter_no_lock((__int64)v29, &v139);
          if ( v139 )
          {
            hdd_adapter_dev_hold_debug(v139, 0x42u, v51, v52, v53, v54, v55, v56, v57, v58, v59);
            v60 = v139;
          }
          else
          {
            v60 = 0;
          }
          hdd_get_next_adapter_no_lock((__int64)v29, v60, &v138);
          if ( v138 )
            hdd_adapter_dev_hold_debug(v138, 0x42u, v61, v62, v63, v64, v65, v66, v67, v68, v69);
          v70 = v29[5];
          if ( (v70 & 1) != 0 )
          {
            v29[5] = v70 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v29 + 4);
            v79 = v139;
            if ( v139 )
              goto LABEL_49;
          }
          else
          {
            raw_spin_unlock(v29 + 4);
            v79 = v139;
            if ( v139 )
            {
LABEL_49:
              v80 = _ReadStatusReg(SP_EL0);
              v134 = 100 * a6;
              while ( 1 )
              {
                if ( v79 == adapter_by_macaddr )
                {
                  if ( *(_QWORD *)(adapter_by_macaddr + 32) )
                  {
                    if ( *(_DWORD *)adapter_by_macaddr == 1885692259 )
                    {
                      if ( a2 > 0x19 )
                      {
                        if ( a3[24] == 1 && a3[25] == 4 )
                          ((void (__fastcall *)(__int64, __int64, _QWORD))sme_update_dsc_pto_up_mapping)(
                            v29[2],
                            adapter_by_macaddr + 41824,
                            *(unsigned __int8 *)(*(_QWORD *)(adapter_by_macaddr + 52824) + 8LL));
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x33u,
                          8u,
                          "%s: Not a QOS frame len: %d",
                          v71,
                          v72,
                          v73,
                          v74,
                          v75,
                          v76,
                          v77,
                          v78,
                          "hdd_is_qos_action_frame",
                          a2);
                      }
                      ucfg_psoc_mlme_get_11be_capab(*v29, &v140);
                      v90 = jiffies;
                      if ( _hdd_indicate_mgmt_frame_to_user___last_ticks_65 - jiffies + 125 < 0 )
                      {
                        LODWORD(v133) = a5;
                        qdf_trace_msg(
                          0x33u,
                          8u,
                          "%s: vdev %d (if_idx %d): Indicate Frame type %d len %d freq %d over NL80211",
                          v82,
                          v83,
                          v84,
                          v85,
                          v86,
                          v87,
                          v88,
                          v89,
                          "__hdd_indicate_mgmt_frame_to_user",
                          a1[8],
                          *(unsigned int *)(*(_QWORD *)(adapter_by_macaddr + 32) + 224LL),
                          a4,
                          a2,
                          v133);
                        _hdd_indicate_mgmt_frame_to_user___last_ticks_65 = v90;
                      }
                      v91 = *(_QWORD *)(adapter_by_macaddr + 32);
                      v146 = 0;
                      v147 = 0;
                      v144 = 0;
                      v145 = 0;
                      v92 = *(_QWORD *)(v91 + 992);
                      v142 = 0;
                      v143 = nullptr;
                      v141[0] = 1000 * a5;
                      v93 = *(_QWORD *)a1;
                      v94 = a1[8];
                      v141[1] = v134;
                      v95 = *(_QWORD **)(v93 + 24);
                      v143 = a3;
                      v144 = a2;
                      LODWORD(v145) = 1;
                      v96 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                              *v95,
                              v94,
                              6);
                      if ( v96 )
                      {
                        v105 = v96;
                        v106 = cfg80211_rx_mgmt_ext(v92, v141);
                        wlan_objmgr_vdev_release_ref(v105, 6u, v107, v106, v108, v109, v110, v111, v112, v113, v114);
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: vdev(%u) is NULL",
                          v97,
                          v98,
                          v99,
                          v100,
                          v101,
                          v102,
                          v103,
                          v104,
                          "wlan_cfg80211_rx_mgmt_ext",
                          a1[8]);
                      }
                      goto LABEL_66;
                    }
                    v81 = "%s: adapter has invalid magic";
                  }
                  else
                  {
                    v81 = "%s: adapter->dev is NULL";
                  }
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    v81,
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    v77,
                    v78,
                    "__hdd_indicate_mgmt_frame_to_user");
                }
LABEL_66:
                hdd_adapter_dev_put_debug(v139, 0x42u, v71, v72, v73, v74, v75, v76, v77, v78);
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (*(_DWORD *)(v80 + 16) & 0xF0000) != 0
                  || (*(_DWORD *)(v80 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(v29 + 4);
                }
                else
                {
                  raw_spin_lock_bh(v29 + 4);
                  v29[5] |= 1uLL;
                }
                v139 = v138;
                hdd_get_next_adapter_no_lock((__int64)v29, v138, &v138);
                hdd_validate_next_adapter(&v139, &v138, 0x42u, v115, v116, v117, v118, v119, v120, v121, v122);
                if ( v138 )
                  hdd_adapter_dev_hold_debug(v138, 0x42u, v123, v124, v125, v126, v127, v128, v129, v130, v131);
                v132 = v29[5];
                if ( (v132 & 1) != 0 )
                {
                  v29[5] = v132 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v29 + 4);
                  v79 = v139;
                  if ( !v139 )
                    break;
                }
                else
                {
                  raw_spin_unlock(v29 + 4);
                  v79 = v139;
                  if ( !v139 )
                    break;
                }
              }
            }
          }
        }
LABEL_34:
        result = _osif_vdev_sync_op_stop(v137, "hdd_indicate_mgmt_frame_to_user");
        goto LABEL_29;
      }
      v48 = "%s: pbFrames is NULL  for frame %d len %d rx freq %d";
      v49 = a4;
    }
    else
    {
      v48 = "%s: adapter is NULL for frame %d len %d rx freq %d";
      v49 = a4;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      v48,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "__hdd_indicate_mgmt_frame_to_user",
      v49,
      a2,
      a5);
    goto LABEL_34;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
