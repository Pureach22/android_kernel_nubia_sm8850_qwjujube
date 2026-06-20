__int64 __fastcall wlan_hdd_cfg80211_update_apies(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x28
  __int64 v10; // x24
  __int64 v12; // x8
  __int64 v13; // x21
  __int64 v14; // x0
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  unsigned __int8 *v25; // x22
  int v26; // w23
  const char *v27; // x2
  unsigned int v28; // w1
  __int64 result; // x0
  __int64 v30; // x26
  unsigned int v31; // w6
  __int64 v32; // x4
  int v33; // w8
  __int16 v34; // w25
  unsigned int v35; // w27
  unsigned __int8 *ext_ie_ptr_from_ext_id; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int16 v45; // w23
  unsigned int v46; // w22
  unsigned __int8 *v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int16 v56; // w23
  unsigned int v57; // w22
  int v58; // w8
  void *v59; // x0
  __int64 v60; // x22
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  int v69; // w8
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  const char *v78; // x2
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  const char *v87; // x2
  int v88; // w8
  __int64 v89; // x9
  __int64 v90; // x8
  unsigned int v91; // w20
  _WORD v92[2]; // [xsp+8h] [xbp-28h] BYREF
  _WORD v93[2]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v94; // [xsp+10h] [xbp-20h] BYREF
  __int64 v95; // [xsp+18h] [xbp-18h]
  __int64 v96; // [xsp+20h] [xbp-10h]
  __int64 v97; // [xsp+28h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[270];
  v93[0] = 0;
  v95 = 0;
  v96 = 0;
  v94 = 0;
  if ( !v9 )
  {
    v27 = "%s: Beacon is NULL !";
    v28 = 2;
    goto LABEL_13;
  }
  v10 = *a1;
  if ( !*a1 || (v12 = *(_QWORD *)(v10 + 24)) == 0 || (v13 = *(_QWORD *)(v12 + 16)) == 0 )
  {
    v27 = "%s: NULL MAC context";
    v28 = 8;
LABEL_13:
    qdf_trace_msg(0x33u, v28, v27, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_cfg80211_update_apies");
    result = 4294967274LL;
    goto LABEL_14;
  }
  v14 = _qdf_mem_malloc(0x200u, "wlan_hdd_cfg80211_update_apies", 5889);
  if ( v14 )
  {
    v15 = v14;
    wlan_hdd_add_extra_ie(a1, v14, v93, 127);
    wlan_hdd_add_extra_ie(a1, v15, v93, 107);
    wlan_hdd_add_extra_ie(a1, v15, v93, 108);
    wlan_hdd_add_extra_ie(a1, v15, v93, 244);
    wlan_hdd_add_extra_ie(a1, v15, v93, 54);
    if ( *(_DWORD *)(v10 + 40) == 1 )
      wlan_hdd_add_extra_ie(a1, v15, v93, 68);
    v92[0] = 0;
    wlan_hdd_add_extra_ie(a1, v15, v93, 70);
    v24 = a1[270];
    v25 = *(unsigned __int8 **)(v24 + 8);
    if ( !v25 || (v26 = *(_DWORD *)(v24 + 36), v26 < 2) )
    {
LABEL_29:
      ext_ie_ptr_from_ext_id = wlan_get_ext_ie_ptr_from_ext_id(
                                 "#",
                                 1u,
                                 *(unsigned __int8 **)(a1[270] + 8),
                                 *(_DWORD *)(a1[270] + 36));
      if ( ext_ie_ptr_from_ext_id )
      {
        v45 = v93[0];
        v46 = ext_ie_ptr_from_ext_id[1] + 2;
        if ( v46 + v93[0] > 0x200 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: **Ie Length is too big***",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "wlan_hdd_add_extn_ie");
          v78 = "%s: Adding HE Cap ie failed";
          goto LABEL_46;
        }
        qdf_mem_copy((void *)(v15 + v93[0]), ext_ie_ptr_from_ext_id, v46);
        v93[0] = v45 + v46;
      }
      v47 = wlan_get_ext_ie_ptr_from_ext_id("$", 1u, *(unsigned __int8 **)(a1[270] + 8), *(_DWORD *)(a1[270] + 36));
      if ( !v47 )
      {
LABEL_35:
        if ( *(_DWORD *)(*a1 + 40) == 1
          && ((unsigned __int8)wlan_hdd_get_sap_obss(a1, v48, v49, v50, v51, v52, v53, v54, v55) & 1) != 0 )
        {
          wlan_hdd_add_extra_ie(a1, v15, v93, 74);
        }
        qdf_mem_copy(&v94, (const void *)(v10 + 1617), 6u);
        v58 = *(_DWORD *)(v9 + 40) + 512;
        HIWORD(v94) = *((unsigned __int8 *)a1 + 8);
        v59 = (void *)_qdf_mem_malloc(v58, "wlan_hdd_cfg80211_update_apies", 5940);
        v60 = (__int64)v59;
        if ( !v59 )
          goto LABEL_63;
        qdf_mem_copy(v59, *(const void **)(v9 + 16), *(unsigned int *)(v9 + 40));
        v69 = *(_DWORD *)(*a1 + 40);
        v92[0] = *(_DWORD *)(v9 + 40);
        if ( v69 == 1 && ((unsigned __int8)wlan_hdd_get_sap_obss(a1, v61, v62, v63, v64, v65, v66, v67, v68) & 1) != 0 )
          wlan_hdd_add_extra_ie(a1, v60, v92, 74);
        wlan_hdd_add_extra_ie(a1, v60, v92, 244);
        wlan_hdd_add_extra_ie(a1, v60, v92, 54);
        if ( (a1[552] & 2) != 0 )
        {
          WORD1(v95) = v92[0];
          v96 = v60;
          LOWORD(v95) = 0;
          if ( (unsigned int)sme_update_add_ie(v13, &v94, 2) == 16 )
          {
            v87 = "%s: Could not pass on PROBE_RESP add Ie data";
            goto LABEL_62;
          }
          wlansap_reset_sap_config_add_ie(a1 + 35, 2);
        }
        else
        {
          wlansap_update_sap_config_add_ie(a1 + 35, v60, v92[0], 2);
        }
        if ( (a1[552] & 2) != 0 )
        {
          v88 = *(_DWORD *)(v9 + 44);
          v89 = *(_QWORD *)(v9 + 24);
          LOWORD(v95) = 0;
          WORD1(v95) = v88;
          v96 = v89;
          if ( (unsigned int)sme_update_add_ie(v13, &v94, 3) == 16 )
          {
LABEL_61:
            v87 = "%s: Could not pass on Add Ie Assoc Response data";
            goto LABEL_62;
          }
          wlansap_reset_sap_config_add_ie(a1 + 35, 3);
        }
        else
        {
          wlansap_update_sap_config_add_ie(a1 + 35, *(_QWORD *)(v9 + 24), *(unsigned int *)(v9 + 44), 3);
        }
        if ( (a1[552] & 2) == 0 )
        {
          wlansap_update_sap_config_add_ie(a1 + 35, v15, v93[0], 1);
LABEL_59:
          if ( (a1[552] & 2) == 0
            || (WORD1(v95) = *(_DWORD *)(v9 + 36),
                v90 = *(_QWORD *)(v9 + 8),
                LOWORD(v95) = 0,
                v96 = v90,
                (unsigned int)sme_update_add_ie(v13, &v94, 4) != 16) )
          {
            v91 = 0;
            goto LABEL_64;
          }
          goto LABEL_61;
        }
        WORD1(v95) = v93[0];
        v96 = v15;
        LOWORD(v95) = 256;
        if ( (unsigned int)sme_update_add_ie(v13, &v94, 1) != 16 )
        {
          wlansap_reset_sap_config_add_ie(a1 + 35, 1);
          goto LABEL_59;
        }
        v87 = "%s: Could not pass on Add Ie probe beacon data";
LABEL_62:
        qdf_trace_msg(0x33u, 2u, v87, v79, v80, v81, v82, v83, v84, v85, v86, "wlan_hdd_cfg80211_update_apies");
        goto LABEL_63;
      }
      v56 = v93[0];
      v57 = v47[1] + 2;
      if ( v57 + v93[0] <= 0x200 )
      {
        qdf_mem_copy((void *)(v15 + v93[0]), v47, v57);
        v93[0] = v56 + v57;
        goto LABEL_35;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: **Ie Length is too big***",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "wlan_hdd_add_extn_ie");
      v78 = "%s: Adding HE Op ie failed";
LABEL_46:
      qdf_trace_msg(0x33u, 2u, v78, v70, v71, v72, v73, v74, v75, v76, v77, "hdd_update_11ax_apies");
      v60 = 0;
LABEL_63:
      v91 = -22;
LABEL_64:
      _qdf_mem_free(v15);
      _qdf_mem_free(v60);
      result = v91;
      goto LABEL_14;
    }
    while ( 1 )
    {
      v30 = v25[1];
      v31 = v26 - 2;
      v32 = *v25;
      v26 = v26 - 2 - v30;
      if ( v31 < (unsigned int)v30 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: **Invalid IEs eid: %d elem_len: %d left: %d**",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "wlan_hdd_add_hostapd_conf_vsie",
          v32,
          v25[1]);
        goto LABEL_29;
      }
      if ( (_DWORD)v32 == 221 )
      {
        v33 = v25[1];
        if ( (unsigned int)v30 >= 4 )
        {
          if ( !(unsigned int)qdf_mem_cmp(v25 + 2, &unk_A062C0, 4u)
            || !(unsigned int)qdf_mem_cmp(v25 + 2, &unk_A062C5, 4u)
            || !(unsigned int)qdf_mem_cmp(v25 + 2, &unk_A062CA, 4u)
            || !(unsigned int)qdf_mem_cmp(v25 + 2, &unk_A05B4D, 4u) )
          {
            goto LABEL_16;
          }
          v33 = v25[1];
        }
        v34 = v93[0];
        v35 = v33 + 2;
        if ( v33 + 2 + (unsigned int)v93[0] > 0x200 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: IE Length is too big IEs eid: %d elem_len: %d total_ie_lent: %d",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "wlan_hdd_add_hostapd_conf_vsie",
            221,
            (unsigned int)v30,
            v93[0]);
        }
        else
        {
          qdf_mem_copy((void *)(v15 + v93[0]), v25, v35);
          v93[0] = v34 + v35;
        }
      }
LABEL_16:
      v25 += v30 + 2;
      if ( v26 <= 1 )
        goto LABEL_29;
    }
  }
  result = 4294967284LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
