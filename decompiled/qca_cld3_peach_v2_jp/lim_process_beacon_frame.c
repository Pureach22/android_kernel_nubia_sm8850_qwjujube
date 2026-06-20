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
  __int64 v14; // x25
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
  _DWORD *v30; // x19
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
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x0
  size_t v57; // x0
  void *v58; // x0
  __int64 v59; // x3
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x8
  __int64 v77; // x22
  __int64 tx_ops; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x23
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 cmpt_obj; // x0
  __int64 v97; // x22
  void (__fastcall *v98)(__int64, __int64, __int64); // x8
  __int64 v99; // x0
  __int64 v100; // x1
  const char *v101; // x2
  __int64 v102; // x21
  _BYTE v103[4]; // [xsp+4h] [xbp-12Ch] BYREF
  _DWORD s[72]; // [xsp+8h] [xbp-128h] BYREF
  __int64 v105; // [xsp+128h] [xbp-8h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int16 *)(a2 + 40);
  v103[0] = 0;
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
    result = _qdf_mem_malloc(0xD80u, "lim_process_beacon_frame", 627);
    if ( !result )
      goto LABEL_12;
    v30 = (_DWORD *)result;
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
      if ( *(unsigned __int8 *)(a3 + 24) == *((unsigned __int8 *)v30 + 1183)
        && *(unsigned __int8 *)(a3 + 25) == *((unsigned __int8 *)v30 + 1184)
        && *(unsigned __int8 *)(a3 + 26) == *((unsigned __int8 *)v30 + 1185)
        && *(unsigned __int8 *)(a3 + 27) == *((unsigned __int8 *)v30 + 1186)
        && *(unsigned __int8 *)(a3 + 28) == *((unsigned __int8 *)v30 + 1187)
        && *(unsigned __int8 *)(a3 + 29) == *((unsigned __int8 *)v30 + 1188) )
      {
        qdf_mem_copy((void *)(a3 + 296), v30, 8u);
        ++*(_DWORD *)(a3 + 304);
      }
      qdf_trace(53, 4u, 0, *v30);
      qdf_trace(53, 4u, 0, v30[1]);
      if ( *(_DWORD *)(a3 + 72) == 2 )
      {
        vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_89A959, 4u, (unsigned __int8 *)(v14 + 12), v18);
        if ( *(_DWORD *)(a3 + 156) == 16 && vendor_ie_ptr_from_oui )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev:%d Drop OWE rx beacon. Wait for probe for join success",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "lim_process_beacon_frame",
            *(unsigned __int8 *)(a3 + 10));
          goto LABEL_11;
        }
        v56 = *(_QWORD *)(a3 + 320);
        if ( v56 )
        {
          _qdf_mem_free(v56);
          *(_QWORD *)(a3 + 320) = 0;
          *(_DWORD *)(a3 + 312) = 0;
        }
        *(_BYTE *)(v17 + 12208) = *(_DWORD *)(a2 + 8);
        v57 = *(unsigned int *)(a2 + 32);
        *(_DWORD *)(a3 + 312) = v57;
        v58 = (void *)_qdf_mem_malloc(v57, "lim_process_beacon_frame", 704);
        *(_QWORD *)(a3 + 320) = v58;
        if ( v58 )
          qdf_mem_copy(v58, *(const void **)(a2 + 16), *(unsigned int *)(a3 + 312));
        mgmt_txrx_frame_hex_dump((__int64)v13, *(_DWORD *)(a2 + 32), 0, v59, v60, v61, v62, v63, v64, v65, v66, v67);
        lim_check_and_announce_join_success(v17, (__int64)v30, v13, a3);
      }
      wlan_cm_is_vdev_connected(*(_QWORD *)(a3 + 16), v39, v40, v41, v42, v43, v44, v45, v46);
      v76 = *(_QWORD *)(a3 + 112);
      if ( v76 )
        v77 = v76 + 4364;
      else
        v77 = 0;
      tx_ops = wlan_reg_get_tx_ops(*(_QWORD *)(v17 + 21552), v68, v69, v70, v71, v72, v73, v74, v75);
      if ( tx_ops )
      {
        if ( v77 )
        {
          v87 = tx_ops;
          lim_process_tpe_ie_from_beacon(v17, a3, v77, v103);
          if ( (v103[0] & 1) == 0 )
          {
            v102 = jiffies;
            if ( lim_process_beacon_frame___last_ticks_5 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(0x35u, 8u, "no change in TPE IE", v88, v89, v90, v91, v92, v93, v94, v95);
              lim_process_beacon_frame___last_ticks_5 = v102;
            }
            goto LABEL_11;
          }
          cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a3 + 16), v88, v89, v90, v91, v92, v93, v94, v95);
          if ( cmpt_obj )
          {
            v97 = cmpt_obj;
            lim_calculate_tpc(v17, a3, 0);
            v98 = *(void (__fastcall **)(__int64, __int64, __int64))(v87 + 144);
            if ( v98 )
            {
              v99 = *(_QWORD *)(v17 + 21552);
              v100 = *(unsigned __int8 *)(a3 + 10);
              if ( *((_DWORD *)v98 - 1) != 1094041931 )
                __break(0x8228u);
              v98(v99, v100, v97 + 528);
            }
            goto LABEL_11;
          }
          v101 = "%s: vdev component object is NULL";
        }
        else
        {
          v101 = "%s: bss descriptor is NULL";
        }
        qdf_trace_msg(0x35u, 2u, v101, v79, v80, v81, v82, v83, v84, v85, v86, "lim_process_beacon_frame");
      }
    }
LABEL_11:
    result = _qdf_mem_free((__int64)v30);
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
