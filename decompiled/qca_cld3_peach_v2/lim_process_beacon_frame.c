__int64 __fastcall lim_process_beacon_frame(
        __int64 result,
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
  unsigned int v11; // w4
  __int64 v12; // x20
  __int16 *v13; // x23
  __int64 v14; // x26
  __int64 v17; // x21
  unsigned __int16 v18; // w24
  unsigned __int8 *rsn_data_from_ie_ptr; // x0
  unsigned __int8 *v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  __int64 v30; // x19
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  char v47; // w25
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x0
  size_t v67; // x0
  void *v68; // x0
  __int64 v69; // x3
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x8
  __int64 v95; // x22
  __int64 tx_ops; // x0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x23
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  __int64 cmpt_obj; // x0
  __int64 v115; // x22
  void (__fastcall *v116)(__int64, __int64, __int64); // x8
  __int64 v117; // x0
  __int64 v118; // x1
  const char *v119; // x2
  __int64 v120; // x21
  __int64 v121; // [xsp+0h] [xbp-130h] BYREF
  _DWORD s[72]; // [xsp+8h] [xbp-128h] BYREF
  __int64 v123; // [xsp+128h] [xbp-8h]

  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int16 *)(a2 + 40);
  BYTE4(v121) = 0;
  LOBYTE(v121) = 0;
  if ( v11 <= 0xB )
  {
    v12 = jiffies;
    if ( lim_process_beacon_frame___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: payload invalid len %d",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "lim_process_beacon_frame");
      lim_process_beacon_frame___last_ticks = v12;
    }
    goto LABEL_12;
  }
  v13 = *(__int16 **)(a2 + 16);
  v14 = *(_QWORD *)(a2 + 24);
  v17 = result;
  v18 = v11 - 12;
  memset(s, 0, sizeof(s));
  rsn_data_from_ie_ptr = wlan_get_rsn_data_from_ie_ptr((unsigned __int8 *)(v14 + 12), v18);
  if ( !rsn_data_from_ie_ptr
    || (v20 = rsn_data_from_ie_ptr,
        qdf_mem_set(s, 0x120u, 0),
        result = wlan_crypto_rsnie_check(s, v20, nullptr),
        !(_DWORD)result) )
  {
    result = _qdf_mem_malloc(0x1A08u, "lim_process_beacon_frame", 627);
    if ( !result )
      goto LABEL_12;
    v30 = result;
    if ( (unsigned int)sir_convert_beacon_frame2_struct(v17, a2, result) )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Received invalid Beacon in state: %X",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "lim_process_beacon_frame",
        *(unsigned int *)(a3 + 72));
      lim_print_mlm_state(v17, 3, *(unsigned int *)(a3 + 72));
    }
    else
    {
      if ( (mlo_is_mld_sta(*(_QWORD *)(a3 + 16)) & 1) != 0 )
      {
        if ( (unsigned int)lim_get_bpcc_from_mlo_ie(v30, (char *)&v121 + 4) )
          v47 = 0;
        else
          v47 = lim_check_cu_happens(
                  *(_QWORD *)(a3 + 16),
                  *(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 93LL),
                  BYTE4(v121));
        v48 = *(_QWORD *)(a3 + 16);
        if ( v48 && *(unsigned __int16 *)(a2 + 40) >= 0xCu )
          mlo_process_ml_reconfig_ie(v48, 0);
      }
      else
      {
        v47 = 1;
      }
      lim_process_bcn_prb_rsp_t2lm(v17, a3, (char *)v30, v39, v40, v41, v42, v43, v44, v45, v46);
      if ( !(unsigned int)lim_check_for_ml_probe_req(a3) )
        goto LABEL_11;
      if ( *(unsigned __int8 *)(a3 + 24) == *(unsigned __int8 *)(v30 + 1183)
        && *(unsigned __int8 *)(a3 + 25) == *(unsigned __int8 *)(v30 + 1184)
        && *(unsigned __int8 *)(a3 + 26) == *(unsigned __int8 *)(v30 + 1185)
        && *(unsigned __int8 *)(a3 + 27) == *(unsigned __int8 *)(v30 + 1186)
        && *(unsigned __int8 *)(a3 + 28) == *(unsigned __int8 *)(v30 + 1187)
        && *(unsigned __int8 *)(a3 + 29) == *(unsigned __int8 *)(v30 + 1188) )
      {
        qdf_mem_copy((void *)(a3 + 296), (const void *)v30, 8u);
        ++*(_DWORD *)(a3 + 304);
      }
      qdf_trace(53, 4u, 0, *(_DWORD *)v30);
      qdf_trace(53, 4u, 0, *(_DWORD *)(v30 + 4));
      if ( *(_DWORD *)(a3 + 72) == 2 )
      {
        vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_969AA7, 4u, (unsigned __int8 *)(v14 + 12), v18);
        if ( *(_DWORD *)(a3 + 156) == 16 && vendor_ie_ptr_from_oui )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev:%d Drop OWE rx beacon. Wait for probe for join success",
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "lim_process_beacon_frame",
            *(unsigned __int8 *)(a3 + 10));
          goto LABEL_11;
        }
        v66 = *(_QWORD *)(a3 + 320);
        if ( v66 )
        {
          _qdf_mem_free(v66);
          *(_QWORD *)(a3 + 320) = 0;
          *(_DWORD *)(a3 + 312) = 0;
        }
        *(_BYTE *)(v17 + 12208) = *(_DWORD *)(a2 + 8);
        v67 = *(unsigned int *)(a2 + 32);
        *(_DWORD *)(a3 + 312) = v67;
        v68 = (void *)_qdf_mem_malloc(v67, "lim_process_beacon_frame", 704);
        *(_QWORD *)(a3 + 320) = v68;
        if ( v68 )
          qdf_mem_copy(v68, *(const void **)(a2 + 16), *(unsigned int *)(a3 + 312));
        mgmt_txrx_frame_hex_dump((__int64)v13, *(_DWORD *)(a2 + 32), 0, v69, v70, v71, v72, v73, v74, v75, v76, v77);
        lim_check_and_announce_join_success(v17, v30, v13, a3);
      }
      if ( wlan_cm_is_vdev_connected(*(_QWORD *)(a3 + 16), v49, v50, v51, v52, v53, v54, v55, v56) )
        lim_process_beacon_eht_op(a3, v30, v78, v79, v80, v81, v82, v83, v84, v85);
      if ( (v47 & 1) == 0 )
        goto LABEL_11;
      lim_process_beacon_eht(v17, a3, v30, v78, v79, v80, v81, v82, v83, v84, v85);
      v94 = *(_QWORD *)(a3 + 112);
      v95 = v94 ? v94 + 4548 : 0LL;
      tx_ops = wlan_reg_get_tx_ops(*(_QWORD *)(v17 + 21624), v86, v87, v88, v89, v90, v91, v92, v93);
      if ( !tx_ops )
        goto LABEL_11;
      if ( v95 )
      {
        v105 = tx_ops;
        lim_process_tpe_ie_from_beacon(v17, a3, v95, &v121);
        if ( (v121 & 1) == 0 )
        {
          v120 = jiffies;
          if ( lim_process_beacon_frame___last_ticks_24 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(0x35u, 8u, "no change in TPE IE", v106, v107, v108, v109, v110, v111, v112, v113);
            lim_process_beacon_frame___last_ticks_24 = v120;
          }
          goto LABEL_11;
        }
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a3 + 16), v106, v107, v108, v109, v110, v111, v112, v113);
        if ( cmpt_obj )
        {
          v115 = cmpt_obj;
          lim_calculate_tpc(v17, a3, 0);
          v116 = *(void (__fastcall **)(__int64, __int64, __int64))(v105 + 144);
          if ( v116 )
          {
            v117 = *(_QWORD *)(v17 + 21624);
            v118 = *(unsigned __int8 *)(a3 + 10);
            if ( *((_DWORD *)v116 - 1) != 1094041931 )
              __break(0x8228u);
            v116(v117, v118, v115 + 544);
          }
          goto LABEL_11;
        }
        v119 = "%s: vdev component object is NULL";
      }
      else
      {
        v119 = "%s: bss descriptor is NULL";
      }
      qdf_trace_msg(0x35u, 2u, v119, v97, v98, v99, v100, v101, v102, v103, v104, "lim_process_beacon_frame", v121);
    }
LABEL_11:
    result = _qdf_mem_free(v30);
    goto LABEL_12;
  }
  v29 = jiffies;
  if ( lim_validate_rsn_ie___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: RSN IE check failed %d",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               "lim_validate_rsn_ie",
               (unsigned int)result);
    lim_validate_rsn_ie___last_ticks = v29;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
