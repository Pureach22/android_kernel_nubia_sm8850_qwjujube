unsigned __int8 *__fastcall cm_roam_scan_offload_ap_profile(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  char v6; // w21
  unsigned __int8 *result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int8 *v18; // x27
  __int64 cmpt_obj; // x0
  size_t v20; // x2
  __int64 rso_config_fl; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x25
  int param; // w23
  int v32; // w8
  int v33; // w0
  int v34; // w8
  char v35; // w26
  int v36; // w21
  int v37; // w0
  int v38; // w8
  int v39; // w26
  int v40; // w0
  unsigned __int64 v41; // x24
  int v42; // w27
  int v43; // w25
  int v44; // w1
  bool v45; // cc
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w8
  size_t v55; // x2
  unsigned __int8 *v56; // x23
  int v57; // w8
  int mcc_to_scc_switch_mode; // w24
  int v59; // w8
  _DWORD *v60; // x8
  unsigned __int8 *v61; // [xsp+8h] [xbp-8h]

  v6 = *(_BYTE *)(a2 + 104);
  result = (unsigned __int8 *)mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    v18 = result;
    *(_BYTE *)a4 = v6;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( cmpt_obj )
    {
      v20 = *(unsigned __int8 *)(cmpt_obj + 162);
      if ( *(_BYTE *)(cmpt_obj + 162) )
      {
        *(_BYTE *)(a4 + 12) = v20;
        qdf_mem_copy((void *)(a4 + 13), (const void *)(cmpt_obj + 129), v20);
      }
      else
      {
        *(_BYTE *)(a4 + 12) = 0;
      }
    }
    rso_config_fl = wlan_cm_get_rso_config_fl(a2, "cm_update_crypto_params", 2060);
    if ( rso_config_fl )
    {
      v30 = rso_config_fl;
      param = wlan_crypto_get_param(a2, 1u);
      if ( param < 1 )
      {
        v32 = 0;
      }
      else if ( (param & 0x600) != 0 )
      {
        v32 = 9;
      }
      else if ( (param & 0x8C) != 0 )
      {
        v32 = 4;
      }
      else if ( (param & 2) != 0 )
      {
        v32 = 2;
      }
      else if ( (param & 0x140) != 0 )
      {
        v32 = 7;
      }
      else if ( (param & 0x2010) != 0 )
      {
        v32 = 5;
      }
      else if ( (param & 0x1800) != 0 )
      {
        v32 = 10;
      }
      else
      {
        v32 = (param & 0x18001) != 0;
      }
      *(_DWORD *)(a4 + 52) = v32;
      v33 = wlan_crypto_get_param(a2, 2u);
      if ( v33 < 1 )
      {
        v34 = 0;
      }
      else if ( (v33 & 0x600) != 0 )
      {
        v34 = 9;
      }
      else if ( (v33 & 0x8C) != 0 )
      {
        v34 = 4;
      }
      else if ( (v33 & 2) != 0 )
      {
        v34 = 2;
      }
      else if ( (v33 & 0x140) != 0 )
      {
        v34 = 7;
      }
      else if ( (v33 & 0x2010) != 0 )
      {
        v34 = 5;
      }
      else if ( (v33 & 0x1800) != 0 )
      {
        v34 = 10;
      }
      else
      {
        v34 = (v33 & 0x18001) != 0;
      }
      *(_DWORD *)(a4 + 56) = v34;
      v35 = wlan_crypto_get_param(a2, 5u);
      v36 = wlan_crypto_vdev_has_mgmtcipher(a2, 6208) & ((unsigned __int8)(v35 & 0x80) >> 7);
      v37 = wlan_crypto_get_param(a2, 3u);
      if ( (v37 & 0x40) != 0 )
      {
        v38 = 7;
        v61 = v18;
        if ( !v36 )
          goto LABEL_30;
      }
      else if ( (v37 & 0x800) != 0 )
      {
        v38 = 10;
        v61 = v18;
        if ( !v36 )
          goto LABEL_30;
      }
      else
      {
        v38 = (v37 << 19 >> 31) & 0xF;
        v61 = v18;
        if ( !v36 )
        {
LABEL_30:
          v38 = 0;
LABEL_33:
          *(_DWORD *)(a4 + 60) = v38;
          v39 = wlan_crypto_get_param(a2, 0);
          v40 = wlan_crypto_get_param(a2, 7u);
          *(_DWORD *)(a4 + 48) = cm_crypto_authmode_to_wmi_authmode(v39, v40, param);
          v41 = 0;
          v42 = 0;
          v43 = *(_DWORD *)(v30 + 68);
          while ( 1 )
          {
            v44 = (1 << v42) & v43;
            if ( v44 )
              v45 = (int)v41 <= 10;
            else
              v45 = 0;
            if ( v45 )
            {
              if ( v41 >= 0xB )
              {
                __break(0x5512u);
                return (unsigned __int8 *)cm_update_hlp_info();
              }
              *(_DWORD *)(a4 + 76 + 4 * v41++) = cm_crypto_authmode_to_wmi_authmode(v39, v44, param);
            }
            if ( ++v42 == 30 )
            {
              v18 = v61;
              *(_DWORD *)(a4 + 72) = v41;
              goto LABEL_43;
            }
          }
        }
      }
      *(_DWORD *)(a4 + 4) |= 4u;
      goto LABEL_33;
    }
LABEL_43:
    *(_DWORD *)(a4 + 8) = *(unsigned __int8 *)(a3 + 189);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: profile->rssi_threshold:%d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "cm_roam_scan_offload_ap_profile");
    *(_BYTE *)(a4 + 68) = *(_BYTE *)(a3 + 191);
    v54 = *((_DWORD *)v18 + 622);
    if ( v54 )
      *(_DWORD *)(a4 + 8) = v54;
    *(_DWORD *)(a4 + 64) = *((_DWORD *)v18 + 395);
    if ( *(_BYTE *)(a3 + 792) == 1 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: set owe ap profile:%d",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "cm_update_owe_ap_profile",
        1);
      *(_BYTE *)(a4 + 468) = 1;
      v55 = *(unsigned __int8 *)(a3 + 793);
      *(_BYTE *)(a4 + 469) = v55;
      qdf_mem_copy((void *)(a4 + 470), (const void *)(a3 + 794), v55);
    }
    result = (unsigned __int8 *)wlan_psoc_mlme_get_cmpt_obj(a1);
    if ( result )
    {
      v56 = result;
      if ( (*(_BYTE *)(a3 + 188) & 1) == 0 )
        *(_DWORD *)(a4 + 120) = -1;
      *(_DWORD *)(a4 + 124) = result[1920];
      *(_DWORD *)(a4 + 128) = result[1921];
      *(_DWORD *)(a4 + 132) = result[1922];
      *(_DWORD *)(a4 + 136) = result[1923];
      *(_DWORD *)(a4 + 140) = result[1924];
      *(_DWORD *)(a4 + 144) = result[1925];
      *(_DWORD *)(a4 + 148) = result[1926];
      *(_DWORD *)(a4 + 260) = result[1934];
      *(_DWORD *)(a4 + 152) = result[1929];
      *(_DWORD *)(a4 + 156) = result[1927];
      if ( policy_mgr_is_pcl_weightage_required(a1) && (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
        v57 = v56[1928];
      else
        v57 = 0;
      *(_DWORD *)(a4 + 160) = v57;
      *(_DWORD *)(a4 + 164) = v56[1930];
      *(_DWORD *)(a4 + 168) = v56[1931];
      *(_DWORD *)(a4 + 172) = v56[1932];
      *(_DWORD *)(a4 + 176) = v56[1933];
      mcc_to_scc_switch_mode = policy_mgr_get_mcc_to_scc_switch_mode(a1);
      if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
      {
        v59 = 0;
      }
      else
      {
        v59 = 0;
        if ( (v56[2000] & 4) == 0 && mcc_to_scc_switch_mode == 6 )
          v59 = v56[1935];
      }
      *(_DWORD *)(a4 + 268) = v59;
      *(_DWORD *)(a4 + 180) = *((_DWORD *)v56 + 497);
      *(_DWORD *)(a4 + 184) = *((_DWORD *)v56 + 499);
      *(_DWORD *)(a4 + 188) = *((_DWORD *)v56 + 498);
      *(_DWORD *)(a4 + 264) = *((_DWORD *)v56 + 503);
      *(_DWORD *)(a4 + 200) = (v56[2000] >> 2) & 1;
      *(_DWORD *)(a4 + 196) = *((_DWORD *)v18 + 854);
      qdf_mem_copy((void *)(a4 + 208), v56 + 1936, 9u);
      qdf_mem_copy((void *)(a4 + 220), v56 + 1948, 0x14u);
      result = (unsigned __int8 *)qdf_mem_copy((void *)(a4 + 240), v56 + 1968, 0x14u);
      if ( *(_BYTE *)(a3 + 1367) == 1 && (*(_BYTE *)(a3 + 92) & 1) == 0 )
      {
        *(_DWORD *)(a4 + 192) = *((_DWORD *)v18 + 859);
        v60 = v18 + 3432;
      }
      else
      {
        *(_DWORD *)(a4 + 192) = *(_DWORD *)(a3 + 220);
        v60 = (_DWORD *)(a3 + 228);
      }
      *(_DWORD *)(a4 + 204) = *v60;
      *(_DWORD *)(a4 + 272) = *(_DWORD *)(a3 + 204);
      *(_DWORD *)(a4 + 276) = *(_DWORD *)(a3 + 208);
      *(_DWORD *)(a4 + 280) = *(_DWORD *)(a3 + 212);
    }
    *(_QWORD *)(a4 + 284) = *(_QWORD *)(v18 + 6556);
    *(_QWORD *)(a4 + 292) = *(_QWORD *)(v18 + 6564);
    *(_QWORD *)(a4 + 300) = *(_QWORD *)(v18 + 6572);
    *(_QWORD *)(a4 + 308) = *(_QWORD *)(v18 + 6396);
    *(_QWORD *)(a4 + 316) = *(_QWORD *)(v18 + 6404);
    *(_QWORD *)(a4 + 324) = *(_QWORD *)(v18 + 6412);
    *(_QWORD *)(a4 + 332) = *(_QWORD *)(v18 + 6420);
    *(_QWORD *)(a4 + 340) = *(_QWORD *)(v18 + 6428);
    *(_QWORD *)(a4 + 348) = *(_QWORD *)(v18 + 6436);
    *(_QWORD *)(a4 + 356) = *(_QWORD *)(v18 + 6444);
    *(_QWORD *)(a4 + 364) = *(_QWORD *)(v18 + 6452);
    *(_QWORD *)(a4 + 372) = *(_QWORD *)(v18 + 6460);
    *(_QWORD *)(a4 + 380) = *(_QWORD *)(v18 + 6468);
    *(_QWORD *)(a4 + 388) = *(_QWORD *)(v18 + 6476);
    *(_QWORD *)(a4 + 396) = *(_QWORD *)(v18 + 6484);
    *(_QWORD *)(a4 + 404) = *(_QWORD *)(v18 + 6492);
    *(_QWORD *)(a4 + 412) = *(_QWORD *)(v18 + 6500);
    *(_QWORD *)(a4 + 420) = *(_QWORD *)(v18 + 6508);
    *(_QWORD *)(a4 + 428) = *(_QWORD *)(v18 + 6516);
    *(_QWORD *)(a4 + 436) = *(_QWORD *)(v18 + 6524);
    *(_QWORD *)(a4 + 444) = *(_QWORD *)(v18 + 6532);
    *(_QWORD *)(a4 + 452) = *(_QWORD *)(v18 + 6540);
    *(_QWORD *)(a4 + 460) = *(_QWORD *)(v18 + 6548);
  }
  return result;
}
