__int64 __fastcall wlan_cm_init_occupied_ch_freq_list(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int *v15; // x8
  __int64 v16; // x19
  __int64 ext_hdl_fl; // x20
  unsigned int operation_chan_freq; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w21
  __int64 cmpt_obj; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  size_t v37; // x2
  const char *v38; // x2
  __int64 result; // x0
  __int64 v40; // x25
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x0
  __int16 v50; // w8
  int v51; // w8
  unsigned int *v52; // x22
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  char v61; // w8
  unsigned int v62; // w8
  _QWORD *scan_result; // x23
  _BOOL4 v64; // w26
  _QWORD *v65; // x8
  char v66; // w8
  unsigned int v67; // w8
  unsigned int v68; // w24
  unsigned int v69; // w25
  __int64 v70; // x9
  unsigned __int64 v71; // x8
  _DWORD *v72; // x11
  __int64 v73; // x12
  _DWORD *v74; // x13
  int v75; // w14
  int v76; // t1
  unsigned __int64 v77; // x9
  bool v78; // cc
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  _QWORD *v87; // [xsp+0h] [xbp-40h] BYREF
  _QWORD *v88; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v89[4]; // [xsp+10h] [xbp-30h] BYREF
  char v90; // [xsp+30h] [xbp-10h]
  __int64 v91; // [xsp+38h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v87 = nullptr;
  v88 = nullptr;
  v90 = 0;
  memset(v89, 0, sizeof(v89));
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a3, 0x4Du);
  if ( vdev_by_id_from_pdev )
  {
    v15 = (unsigned int *)*((unsigned int *)vdev_by_id_from_pdev + 4);
    if ( ((unsigned int)v15 & 0xFFFFFFFD) != 0 )
      goto LABEL_15;
    v16 = (__int64)vdev_by_id_from_pdev;
    ext_hdl_fl = cm_get_ext_hdl_fl(
                   (__int64)vdev_by_id_from_pdev,
                   (__int64)"wlan_cm_init_occupied_ch_freq_list",
                   0x92Du,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   v14);
    vdev_by_id_from_pdev = (_QWORD *)v16;
    if ( !ext_hdl_fl )
      goto LABEL_15;
    operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)v16);
    if ( !operation_chan_freq )
    {
      v38 = "%s: failed to get op freq";
      goto LABEL_11;
    }
    v27 = operation_chan_freq;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v16, v19, v20, v21, v22, v23, v24, v25, v26);
    if ( cmpt_obj )
    {
      v37 = *(unsigned __int8 *)(cmpt_obj + 178);
      if ( *(_BYTE *)(cmpt_obj + 178) )
      {
        LOBYTE(v89[0]) = *(_BYTE *)(cmpt_obj + 178);
        qdf_mem_copy((char *)v89 + 1, (const void *)(cmpt_obj + 145), v37);
        if ( *(_BYTE *)(ext_hdl_fl + 112) )
        {
          v38 = "%s: Ini contains neighbor scan ch list";
LABEL_11:
          qdf_trace_msg(
            0x68u,
            8u,
            v38,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "wlan_cm_init_occupied_ch_freq_list",
            v87);
LABEL_14:
          vdev_by_id_from_pdev = (_QWORD *)v16;
LABEL_15:
          result = wlan_objmgr_vdev_release_ref(
                     (__int64)vdev_by_id_from_pdev,
                     0x4Du,
                     v15,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     v13,
                     v14);
          goto LABEL_16;
        }
        v40 = _qdf_mem_malloc(0x2D8u, "wlan_cm_init_occupied_ch_freq_list", 2374);
        vdev_by_id_from_pdev = (_QWORD *)v16;
        if ( !v40 )
          goto LABEL_15;
        *(_DWORD *)(v40 + 56) = wlan_crypto_get_param(v16, 3u);
        if ( (*(_DWORD *)(v16 + 16) & 0xFFFFFFFD) != 0 )
          goto LABEL_26;
        v49 = cm_get_ext_hdl_fl(
                v16,
                (__int64)"wlan_cm_fill_crypto_filter_from_vdev",
                0x89Eu,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48);
        if ( !v49 )
          goto LABEL_26;
        v50 = *(_WORD *)(v49 + 84);
        if ( (v50 & 0x40) != 0 )
        {
          v51 = 2;
        }
        else
        {
          if ( (v50 & 0x80) == 0 )
          {
LABEL_25:
            *(_DWORD *)(v40 + 40) = *(_DWORD *)(v49 + 64);
            *(_DWORD *)(v40 + 52) = *(_DWORD *)(v49 + 76);
            *(_DWORD *)(v40 + 48) = *(_DWORD *)(v49 + 72);
            *(_DWORD *)(v40 + 44) = *(_DWORD *)(v49 + 68);
LABEL_26:
            *(_BYTE *)(v40 + 17) = 1;
            qdf_mem_copy((void *)(v40 + 100), v89, 0x21u);
            v52 = (unsigned int *)(ext_hdl_fl + 276);
            *(_BYTE *)(ext_hdl_fl + 272) = 0;
            *(_BYTE *)(ext_hdl_fl + 676) = 1;
            if ( !wlan_is_channel_present_in_list((int *)(ext_hdl_fl + 276), 0, v27) )
            {
              v61 = *(_BYTE *)(ext_hdl_fl + 272);
              *v52 = v27;
              v62 = (unsigned __int8)(v61 + 1);
              if ( v62 >= 0xF )
                LOBYTE(v62) = 15;
              *(_BYTE *)(ext_hdl_fl + 272) = v62;
            }
            scan_result = scm_get_scan_result(a1, v40, v53, v54, v55, v56, v57, v58, v59, v60);
            _qdf_mem_free(v40);
            if ( !scan_result )
            {
              ((void (__fastcall *)(__int64))cm_dump_occupied_chan_list)(ext_hdl_fl + 272);
              goto LABEL_14;
            }
            if ( !*((_DWORD *)scan_result + 4)
              || ((wlan_mlme_get_dual_sta_roaming_enabled(a2) & 1) == 0
                ? (v64 = 0)
                : (v64 = (unsigned int)policy_mgr_mode_specific_connection_count(a2, 0, nullptr) > 1),
                  qdf_list_peek_front(scan_result, &v88),
                  (v65 = v88) == nullptr) )
            {
LABEL_59:
              v79 = ((double (__fastcall *)(__int64))cm_dump_occupied_chan_list)(ext_hdl_fl + 272);
              scm_purge_scan_results((__int64)scan_result, v79, v80, v81, v82, v83, v84, v85, v86);
              goto LABEL_14;
            }
            while ( 1 )
            {
              v68 = *(_DWORD *)(v65[3] + 1192LL);
              if ( v64
                && (!wlan_reg_is_24ghz_ch_freq(v27) || !wlan_reg_is_24ghz_ch_freq(v68))
                && (wlan_reg_is_24ghz_ch_freq(v27) || wlan_reg_is_24ghz_ch_freq(v68)) )
              {
                goto LABEL_41;
              }
              v69 = *(unsigned __int8 *)(ext_hdl_fl + 272);
              ++*(_BYTE *)(ext_hdl_fl + 676);
              if ( wlan_is_channel_present_in_list((int *)(ext_hdl_fl + 276), v69, v68) )
                goto LABEL_41;
              if ( v69 )
              {
                if ( v69 >= 0x63 )
                  v70 = 99;
                else
                  v70 = v69;
                if ( v69 == 1 )
                {
                  v71 = v70;
                }
                else
                {
                  v72 = (_DWORD *)(ext_hdl_fl + 276 + 4 * v70);
                  v71 = v70 & 1;
                  v73 = v70 & 0x7E;
                  v74 = v72;
                  do
                  {
                    v75 = *(v72 - 1);
                    v76 = *(v74 - 2);
                    v74 -= 2;
                    v73 -= 2;
                    *(v72 - 1) = v76;
                    *v72 = v75;
                    v72 = v74;
                  }
                  while ( v73 );
                  if ( (v70 & 0x7E) == v70 )
                    goto LABEL_38;
                }
                do
                {
                  v77 = ext_hdl_fl + 4 * v71;
                  v78 = v71-- > 1;
                  *(_DWORD *)(v77 + 276) = *(_DWORD *)(v77 + 272);
                }
                while ( v78 );
              }
LABEL_38:
              v66 = *(_BYTE *)(ext_hdl_fl + 272);
              *v52 = v68;
              v67 = (unsigned __int8)(v66 + 1);
              if ( v67 >= 0xF )
                LOBYTE(v67) = 15;
              *(_BYTE *)(ext_hdl_fl + 272) = v67;
LABEL_41:
              qdf_list_peek_next(scan_result, v88, &v87);
              v65 = v87;
              v87 = nullptr;
              v88 = v65;
              if ( !v65 )
                goto LABEL_59;
            }
          }
          v51 = 1;
        }
        *(_DWORD *)(v40 + 24) = v51;
        goto LABEL_25;
      }
      LOBYTE(v89[0]) = 0;
    }
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: failed to find SSID for vdev %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_cm_init_occupied_ch_freq_list",
      a3,
      v87);
    goto LABEL_14;
  }
  result = qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev object is NULL for vdev %d",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "wlan_cm_init_occupied_ch_freq_list",
             a3);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
