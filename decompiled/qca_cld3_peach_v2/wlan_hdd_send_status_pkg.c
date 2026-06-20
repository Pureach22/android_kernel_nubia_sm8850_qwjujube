__int64 __fastcall wlan_hdd_send_status_pkg(
        _BYTE *a1,
        __int64 a2,
        char a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x24
  __int64 result; // x0
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _DWORD *v26; // x21
  unsigned __int8 v27; // w0
  __int64 v28; // x24
  __int64 v29; // x27
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  bool v38; // w8
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w8
  int v57; // w8
  int v58; // w9
  __int64 v59; // x28
  unsigned __int8 v60; // w0
  __int64 v61; // x9
  __int64 v62; // x26
  unsigned int v63; // w25
  __int64 v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  char v73; // w9
  size_t v74; // x2
  char v75; // w8
  int v76; // w9
  __int16 v77; // w9
  unsigned __int64 StatusReg; // x25
  __int64 v79; // x26
  __int64 v80; // [xsp+8h] [xbp-38h]
  _BYTE v81[4]; // [xsp+24h] [xbp-1Ch] BYREF
  _BYTE v82[4]; // [xsp+28h] [xbp-18h] BYREF
  unsigned int v83; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v84[2]; // [xsp+30h] [xbp-10h] BYREF

  LOBYTE(v15) = a3;
  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(51, (__int64)"wlan_hdd_send_status_pkg", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !result )
    goto LABEL_12;
  v17 = result;
  result = hdd_get_conparam();
  if ( (_DWORD)result == 5 )
    goto LABEL_12;
  result = _kmalloc_cache_noprof(sg_next, 3520, 4288);
  v26 = (_DWORD *)result;
  if ( !result )
    goto LABEL_12;
LABEL_4:
  if ( (_BYTE)v15 )
  {
    v81[0] = 0;
    if ( !a1 )
    {
      *(_WORD *)v26 = 256;
      goto LABEL_10;
    }
    v27 = a1[8];
    v82[0] = 0;
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         v27,
                         (__int64)"wlan_hdd_gen_wlan_status_pack",
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25) )
      goto LABEL_11;
    v28 = *(_QWORD *)a1;
    v29 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
    if ( (unsigned int)wlan_mlme_get_lpass_support(*(_QWORD *)v29, v82) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get LPASS support config",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_hdd_gen_wlan_status_pack");
      goto LABEL_11;
    }
    wlan_mlme_get_wls_6ghz_cap(*(_QWORD *)v29, v81);
    v80 = v28;
    v38 = *(_BYTE *)(v29 + 853) && (v82[0] & 1) != 0;
    *(_BYTE *)v26 = v38;
    v39 = _qdf_mem_malloc(0x200u, "wlan_hdd_gen_wlan_status_pack", 130);
    if ( !v39 )
      goto LABEL_11;
    v15 = v39;
    v83 = 128;
    sme_get_cfg_valid_channels(v39, &v83, v40, v41, v42, v43, v44, v45, v46, v47);
    v56 = v83;
    v26[5] = 0;
    if ( !v56 )
    {
LABEL_30:
      _qdf_mem_free(v15);
      wlan_reg_get_cc_and_src(*(_QWORD *)v29, (char *)v26 + 6, v65, v66, v67, v68, v69, v70, v71, v72);
      v73 = a1[8];
      *((_BYTE *)v26 + 1) = 1;
      *((_BYTE *)v26 + 2) = v73;
      v26[3] = *(_DWORD *)(v80 + 40);
      if ( a2 )
      {
        v74 = *(unsigned __int8 *)(a2 + 236);
        v75 = a1[2688];
        v76 = *(_DWORD *)(a2 + 620);
        *((_BYTE *)v26 + 3) = a4;
        *((_BYTE *)v26 + 4) = v75;
        v26[4] = v76;
        if ( v74 <= 0x20 )
        {
          *((_BYTE *)v26 + 5) = v74;
          memcpy(v26 + 38, (const void *)(a2 + 237), v74);
        }
        v77 = *(_WORD *)(a2 + 232);
        v26[46] = *(_DWORD *)(a2 + 228);
        *((_WORD *)v26 + 94) = v77;
      }
      goto LABEL_10;
    }
    v57 = 0;
    while ( 1 )
    {
      v59 = v57;
      if ( (v81[0] & 1) != 0 || !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v15 + 4LL * v57)) )
      {
        v60 = wlan_reg_freq_to_chan(
                *(_QWORD *)(v29 + 8),
                *(_DWORD *)(v15 + 4 * v59),
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55);
        if ( v60 )
        {
          v61 = (unsigned int)v26[5];
          if ( (unsigned int)v61 >= 0x80 )
          {
            __break(0x5512u);
            StatusReg = _ReadStatusReg(SP_EL0);
            v79 = *(_QWORD *)(StatusReg + 80);
            *(_QWORD *)(StatusReg + 80) = &wlan_hdd_send_status_pkg__alloc_tag;
            result = _kmalloc_cache_noprof(sg_next, 3520, 4288);
            v26 = (_DWORD *)result;
            *(_QWORD *)(StatusReg + 80) = v79;
            if ( !result )
              goto LABEL_12;
            goto LABEL_4;
          }
          v62 = (__int64)&v26[8 * v61 + 48];
          *((_BYTE *)v26 + v61 + 24) = v60;
          *(_DWORD *)v62 = v60;
          v63 = *(_DWORD *)(v15 + 4 * v59);
          v64 = *(_QWORD *)(v29 + 16);
          v84[0] = 0;
          if ( !(unsigned int)sme_get_reg_info(v64, v63, (unsigned int *)v84 + 1, (unsigned int *)v84) )
          {
            *(_DWORD *)(v62 + 8) = v63;
            *(_DWORD *)(v62 + 12) = v63;
            *(_QWORD *)(v62 + 16) = 0;
            if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                                 *(_QWORD *)(v29 + 8),
                                 v63,
                                 0,
                                 v48,
                                 v49,
                                 v50,
                                 v51,
                                 v52,
                                 v53,
                                 v54,
                                 v55) == 2 )
              *(_DWORD *)(v62 + 20) |= 0x400u;
            v58 = v84[0];
            *(_DWORD *)(v62 + 24) = HIDWORD(v84[0]);
            *(_DWORD *)(v62 + 28) = v58;
          }
          ++v26[5];
        }
      }
      v57 = v59 + 1;
      if ( (int)v59 + 1 >= v83 )
        goto LABEL_30;
    }
  }
LABEL_10:
  wlan_hdd_send_svc_nlink_msg(*(_DWORD *)(v17 + 1456), 0x106u, v26, 4288);
LABEL_11:
  result = kfree(v26);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
