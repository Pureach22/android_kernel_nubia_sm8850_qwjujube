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
  int v26; // w21
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
  __int16 v45; // w21
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
  __int16 v56; // w21
  unsigned int v57; // w22
  unsigned __int8 *v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int16 v67; // w21
  unsigned int v68; // w22
  unsigned __int8 *v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int16 v78; // w21
  unsigned int v79; // w22
  const void *v80; // x1
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  const char *v89; // x2
  const char *v90; // x3
  int v91; // w8
  void *v92; // x0
  __int64 v93; // x22
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  int v102; // w8
  unsigned int v103; // w20
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  const char *v112; // x2
  int v113; // w8
  __int64 v114; // x9
  __int64 v115; // x8
  __int64 v116; // [xsp+0h] [xbp-30h]
  _WORD v117[2]; // [xsp+8h] [xbp-28h] BYREF
  _WORD v118[2]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v119; // [xsp+10h] [xbp-20h] BYREF
  __int64 v120; // [xsp+18h] [xbp-18h]
  __int64 v121; // [xsp+20h] [xbp-10h]
  __int64 v122; // [xsp+28h] [xbp-8h]

  v122 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[304];
  v118[0] = 0;
  v120 = 0;
  v121 = 0;
  v119 = 0;
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
    v116 = v13;
    wlan_hdd_add_extra_ie(a1, v14, v118, 127);
    wlan_hdd_add_extra_ie(a1, v15, v118, 107);
    wlan_hdd_add_extra_ie(a1, v15, v118, 108);
    wlan_hdd_add_extra_ie(a1, v15, v118, 244);
    wlan_hdd_add_extra_ie(a1, v15, v118, 54);
    if ( *(_DWORD *)(v10 + 40) == 1 )
      wlan_hdd_add_extra_ie(a1, v15, v118, 68);
    v117[0] = 0;
    wlan_hdd_add_extra_ie(a1, v15, v118, 70);
    v24 = a1[304];
    v25 = *(unsigned __int8 **)(v24 + 8);
    if ( v25 )
    {
      v26 = *(_DWORD *)(v24 + 36);
      if ( v26 >= 2 )
      {
        do
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
            break;
          }
          if ( (_DWORD)v32 == 221 )
          {
            v33 = v25[1];
            if ( (unsigned int)v30 >= 4 )
            {
              if ( !(unsigned int)qdf_mem_cmp(v25 + 2, &unk_AF8250, 4u)
                || !(unsigned int)qdf_mem_cmp(v25 + 2, &unk_AF8255, 4u)
                || !(unsigned int)qdf_mem_cmp(v25 + 2, &unk_AF825A, 4u)
                || !(unsigned int)qdf_mem_cmp(v25 + 2, &unk_AF7ADD, 4u) )
              {
                goto LABEL_16;
              }
              v33 = v25[1];
            }
            v34 = v118[0];
            v35 = v33 + 2;
            if ( v33 + 2 + (unsigned int)v118[0] > 0x200 )
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
                v118[0]);
            }
            else
            {
              qdf_mem_copy((void *)(v15 + v118[0]), v25, v35);
              v118[0] = v34 + v35;
            }
          }
LABEL_16:
          v25 += v30 + 2;
        }
        while ( v26 > 1 );
      }
    }
    ext_ie_ptr_from_ext_id = wlan_get_ext_ie_ptr_from_ext_id(
                               "#",
                               1u,
                               *(unsigned __int8 **)(a1[304] + 8),
                               *(_DWORD *)(a1[304] + 36));
    if ( ext_ie_ptr_from_ext_id )
    {
      v45 = v118[0];
      v46 = ext_ie_ptr_from_ext_id[1] + 2;
      if ( v46 + v118[0] > 0x200 )
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
        v89 = "%s: Adding HE Cap ie failed";
        goto LABEL_49;
      }
      qdf_mem_copy((void *)(v15 + v118[0]), ext_ie_ptr_from_ext_id, v46);
      v118[0] = v45 + v46;
    }
    v47 = wlan_get_ext_ie_ptr_from_ext_id("$", 1u, *(unsigned __int8 **)(a1[304] + 8), *(_DWORD *)(a1[304] + 36));
    if ( !v47 )
      goto LABEL_35;
    v56 = v118[0];
    v57 = v47[1] + 2;
    if ( v57 + v118[0] <= 0x200 )
    {
      qdf_mem_copy((void *)(v15 + v118[0]), v47, v57);
      v118[0] = v56 + v57;
LABEL_35:
      v58 = wlan_get_ext_ie_ptr_from_ext_id("j", 1u, *(unsigned __int8 **)(a1[304] + 8), *(_DWORD *)(a1[304] + 36));
      if ( v58 )
      {
        v67 = v118[0];
        v68 = v58[1] + 2;
        if ( v68 + v118[0] > 0x200 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: **Ie Length is too big***",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "wlan_hdd_add_extn_ie");
          v89 = "%s: Adding EHT Cap IE failed";
LABEL_59:
          v90 = "hdd_update_11be_apies";
          goto LABEL_60;
        }
        qdf_mem_copy((void *)(v15 + v118[0]), v58, v68);
        v118[0] = v67 + v68;
      }
      v69 = wlan_get_ext_ie_ptr_from_ext_id("l", 1u, *(unsigned __int8 **)(a1[304] + 8), *(_DWORD *)(a1[304] + 36));
      if ( !v69 )
      {
LABEL_41:
        if ( *(_DWORD *)(*a1 + 40) == 1
          && ((unsigned __int8)wlan_hdd_get_sap_obss(a1, v70, v71, v72, v73, v74, v75, v76, v77) & 1) != 0 )
        {
          wlan_hdd_add_extra_ie(a1, v15, v118, 74);
        }
        if ( *(_DWORD *)(v10 + 40) == 1
          && (wlan_vdev_mlme_is_mlo_vdev(
                *(_QWORD *)(*(_QWORD *)(v10 + 52832) + 32LL),
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77)
            & 1) != 0 )
        {
          v80 = a1 + 9;
        }
        else
        {
          v80 = (const void *)(v10 + 1617);
        }
        qdf_mem_copy(&v119, v80, 6u);
        v91 = *(_DWORD *)(v9 + 40) + 512;
        HIWORD(v119) = *((unsigned __int8 *)a1 + 8);
        v92 = (void *)_qdf_mem_malloc(v91, "wlan_hdd_cfg80211_update_apies", 5940);
        v93 = (__int64)v92;
        if ( !v92 )
          goto LABEL_61;
        qdf_mem_copy(v92, *(const void **)(v9 + 16), *(unsigned int *)(v9 + 40));
        v102 = *(_DWORD *)(*a1 + 40);
        v117[0] = *(_DWORD *)(v9 + 40);
        if ( v102 == 1
          && ((unsigned __int8)wlan_hdd_get_sap_obss(a1, v94, v95, v96, v97, v98, v99, v100, v101) & 1) != 0 )
        {
          wlan_hdd_add_extra_ie(a1, v93, v117, 74);
        }
        wlan_hdd_add_extra_ie(a1, v93, v117, 244);
        wlan_hdd_add_extra_ie(a1, v93, v117, 54);
        if ( (a1[746] & 2) != 0 )
        {
          WORD1(v120) = v117[0];
          v121 = v93;
          LOWORD(v120) = 0;
          if ( (unsigned int)sme_update_add_ie(v116, &v119, 2) == 16 )
          {
            v112 = "%s: Could not pass on PROBE_RESP add Ie data";
            goto LABEL_78;
          }
          wlansap_reset_sap_config_add_ie(a1 + 35, 2);
        }
        else
        {
          wlansap_update_sap_config_add_ie(a1 + 35, v93, v117[0], 2);
        }
        if ( (a1[746] & 2) != 0 )
        {
          v113 = *(_DWORD *)(v9 + 44);
          v114 = *(_QWORD *)(v9 + 24);
          LOWORD(v120) = 0;
          WORD1(v120) = v113;
          v121 = v114;
          if ( (unsigned int)sme_update_add_ie(v116, &v119, 3) == 16 )
          {
LABEL_77:
            v112 = "%s: Could not pass on Add Ie Assoc Response data";
            goto LABEL_78;
          }
          wlansap_reset_sap_config_add_ie(a1 + 35, 3);
        }
        else
        {
          wlansap_update_sap_config_add_ie(a1 + 35, *(_QWORD *)(v9 + 24), *(unsigned int *)(v9 + 44), 3);
        }
        if ( (a1[746] & 2) == 0 )
        {
          wlansap_update_sap_config_add_ie(a1 + 35, v15, v118[0], 1);
LABEL_75:
          if ( (a1[746] & 2) == 0
            || (WORD1(v120) = *(_DWORD *)(v9 + 36),
                v115 = *(_QWORD *)(v9 + 8),
                LOWORD(v120) = 0,
                v121 = v115,
                (unsigned int)sme_update_add_ie(v116, &v119, 4) != 16) )
          {
            v103 = 0;
            goto LABEL_62;
          }
          goto LABEL_77;
        }
        WORD1(v120) = v118[0];
        v121 = v15;
        LOWORD(v120) = 256;
        if ( (unsigned int)sme_update_add_ie(v116, &v119, 1) != 16 )
        {
          wlansap_reset_sap_config_add_ie(a1 + 35, 1);
          goto LABEL_75;
        }
        v112 = "%s: Could not pass on Add Ie probe beacon data";
LABEL_78:
        qdf_trace_msg(0x33u, 2u, v112, v104, v105, v106, v107, v108, v109, v110, v111, "wlan_hdd_cfg80211_update_apies");
        goto LABEL_61;
      }
      v78 = v118[0];
      v79 = v69[1] + 2;
      if ( v79 + v118[0] <= 0x200 )
      {
        qdf_mem_copy((void *)(v15 + v118[0]), v69, v79);
        v118[0] = v78 + v79;
        goto LABEL_41;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: **Ie Length is too big***",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        "wlan_hdd_add_extn_ie");
      v89 = "%s: Adding EHT Op IE failed";
      goto LABEL_59;
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
    v89 = "%s: Adding HE Op ie failed";
LABEL_49:
    v90 = "hdd_update_11ax_apies";
LABEL_60:
    qdf_trace_msg(0x33u, 2u, v89, v81, v82, v83, v84, v85, v86, v87, v88, v90);
    v93 = 0;
LABEL_61:
    v103 = -22;
LABEL_62:
    _qdf_mem_free(v15);
    _qdf_mem_free(v93);
    result = v103;
    goto LABEL_14;
  }
  result = 4294967284LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
