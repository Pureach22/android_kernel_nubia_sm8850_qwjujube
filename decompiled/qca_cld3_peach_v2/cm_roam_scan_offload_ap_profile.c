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
  __int64 v41; // x0
  __int64 v42; // x2
  unsigned __int64 v43; // x24
  int v44; // w27
  unsigned int v45; // w25
  __int64 v46; // x1
  bool v47; // cc
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w8
  size_t v57; // x2
  unsigned __int8 *v58; // x23
  int v59; // w8
  int mcc_to_scc_switch_mode; // w24
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  int v69; // w8
  unsigned __int8 v70; // w8
  int v71; // w8
  int v72; // w8
  _DWORD *v73; // x8
  unsigned __int8 *v74; // [xsp+8h] [xbp-8h]

  v6 = *(_BYTE *)(a2 + 168);
  result = (unsigned __int8 *)mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    v18 = result;
    *(_BYTE *)a4 = v6;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( cmpt_obj )
    {
      v20 = *(unsigned __int8 *)(cmpt_obj + 178);
      if ( *(_BYTE *)(cmpt_obj + 178) )
      {
        *(_BYTE *)(a4 + 12) = v20;
        qdf_mem_copy((void *)(a4 + 13), (const void *)(cmpt_obj + 145), v20);
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
        v74 = v18;
        if ( !v36 )
          goto LABEL_30;
      }
      else if ( (v37 & 0x800) != 0 )
      {
        v38 = 10;
        v74 = v18;
        if ( !v36 )
          goto LABEL_30;
      }
      else
      {
        v38 = (v37 << 19 >> 31) & 0xF;
        v74 = v18;
        if ( !v36 )
        {
LABEL_30:
          v38 = 0;
LABEL_33:
          *(_DWORD *)(a4 + 60) = v38;
          v39 = wlan_crypto_get_param(a2, 0);
          v40 = wlan_crypto_get_param(a2, 7u);
          v41 = cm_crypto_authmode_to_wmi_authmode(v39, v40, param);
          *(_DWORD *)(a4 + 48) = v41;
          v43 = 0;
          v44 = 0;
          v45 = *(_DWORD *)(v30 + 68);
          while ( 1 )
          {
            v46 = (1 << v44) & v45;
            if ( (_DWORD)v46 )
              v47 = (int)v43 <= 10;
            else
              v47 = 0;
            if ( v47 )
            {
              if ( v43 >= 0xB )
              {
                __break(0x5512u);
                return (unsigned __int8 *)cm_roam_init_req(v41, v46, v42);
              }
              v41 = cm_crypto_authmode_to_wmi_authmode(v39, v46, param);
              *(_DWORD *)(a4 + 76 + 4 * v43++) = v41;
            }
            if ( ++v44 == 30 )
            {
              v18 = v74;
              *(_DWORD *)(a4 + 72) = v43;
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
    v56 = *((_DWORD *)v18 + 673);
    if ( v56 )
      *(_DWORD *)(a4 + 8) = v56;
    *(_DWORD *)(a4 + 64) = *((_DWORD *)v18 + 446);
    if ( *(_BYTE *)(a3 + 792) == 1 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: set owe ap profile:%d",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "cm_update_owe_ap_profile",
        1);
      *(_BYTE *)(a4 + 476) = 1;
      v57 = *(unsigned __int8 *)(a3 + 793);
      *(_BYTE *)(a4 + 477) = v57;
      qdf_mem_copy((void *)(a4 + 478), (const void *)(a3 + 794), v57);
    }
    result = (unsigned __int8 *)wlan_psoc_mlme_get_cmpt_obj(a1);
    if ( result )
    {
      v58 = result;
      if ( (*(_BYTE *)(a3 + 188) & 1) == 0 )
        *(_DWORD *)(a4 + 120) = -1;
      *(_DWORD *)(a4 + 124) = result[1920];
      *(_DWORD *)(a4 + 128) = result[1921];
      *(_DWORD *)(a4 + 132) = result[1922];
      *(_DWORD *)(a4 + 136) = result[1923];
      *(_DWORD *)(a4 + 140) = result[1924];
      *(_DWORD *)(a4 + 144) = result[1925];
      *(_DWORD *)(a4 + 148) = result[1926];
      *(_DWORD *)(a4 + 268) = result[1945];
      *(_DWORD *)(a4 + 152) = result[1929];
      *(_DWORD *)(a4 + 156) = result[1927];
      if ( policy_mgr_is_pcl_weightage_required(a1) && (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
        v59 = v58[1928];
      else
        v59 = 0;
      *(_DWORD *)(a4 + 160) = v59;
      *(_DWORD *)(a4 + 164) = v58[1930];
      *(_DWORD *)(a4 + 168) = v58[1931];
      *(_DWORD *)(a4 + 172) = v58[1932];
      *(_DWORD *)(a4 + 176) = v58[1933];
      mcc_to_scc_switch_mode = policy_mgr_get_mcc_to_scc_switch_mode(a1);
      if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
      {
        v69 = 0;
      }
      else
      {
        v69 = 0;
        if ( (v58[2048] & 4) == 0 && mcc_to_scc_switch_mode == 6 )
          v69 = v58[1946];
      }
      *(_DWORD *)(a4 + 276) = v69;
      v70 = v58[1934];
      *(_DWORD *)(a4 + 264) = 0;
      *(_BYTE *)(a4 + 260) = v70;
      v71 = v58[1937];
      *(_DWORD *)(a4 + 264) = v71;
      v72 = v71 | (v58[1938] << 16);
      *(_DWORD *)(a4 + 264) = v72;
      *(_DWORD *)(a4 + 264) = v72 | (v58[1939] << 8);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: mlo weightage 0x%x",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "cm_update_mlo_score_params");
      *(_DWORD *)(a4 + 180) = *((_DWORD *)v58 + 500);
      *(_DWORD *)(a4 + 184) = *((_DWORD *)v58 + 511);
      *(_DWORD *)(a4 + 188) = *((_DWORD *)v58 + 509);
      *(_DWORD *)(a4 + 272) = *((_DWORD *)v58 + 516);
      *(_DWORD *)(a4 + 200) = (v58[2048] >> 2) & 1;
      *(_DWORD *)(a4 + 196) = *((_DWORD *)v18 + 907);
      qdf_mem_copy((void *)(a4 + 208), v58 + 1948, 9u);
      qdf_mem_copy((void *)(a4 + 220), v58 + 1960, 0x14u);
      result = (unsigned __int8 *)qdf_mem_copy((void *)(a4 + 240), v58 + 1980, 0x14u);
      if ( *(_BYTE *)(a3 + 1383) == 1 && (*(_BYTE *)(a3 + 92) & 1) == 0 )
      {
        *(_DWORD *)(a4 + 192) = *((_DWORD *)v18 + 912);
        v73 = v18 + 3644;
      }
      else
      {
        *(_DWORD *)(a4 + 192) = *(_DWORD *)(a3 + 220);
        v73 = (_DWORD *)(a3 + 228);
      }
      *(_DWORD *)(a4 + 204) = *v73;
      *(_DWORD *)(a4 + 280) = *(_DWORD *)(a3 + 204);
      *(_DWORD *)(a4 + 284) = *(_DWORD *)(a3 + 208);
      *(_DWORD *)(a4 + 288) = *(_DWORD *)(a3 + 212);
    }
    *(_QWORD *)(a4 + 292) = *(_QWORD *)(v18 + 6772);
    *(_QWORD *)(a4 + 300) = *(_QWORD *)(v18 + 6780);
    *(_QWORD *)(a4 + 308) = *(_QWORD *)(v18 + 6788);
    *(_QWORD *)(a4 + 316) = *(_QWORD *)(v18 + 6612);
    *(_QWORD *)(a4 + 324) = *(_QWORD *)(v18 + 6620);
    *(_QWORD *)(a4 + 332) = *(_QWORD *)(v18 + 6628);
    *(_QWORD *)(a4 + 340) = *(_QWORD *)(v18 + 6636);
    *(_QWORD *)(a4 + 348) = *(_QWORD *)(v18 + 6644);
    *(_QWORD *)(a4 + 356) = *(_QWORD *)(v18 + 6652);
    *(_QWORD *)(a4 + 364) = *(_QWORD *)(v18 + 6660);
    *(_QWORD *)(a4 + 372) = *(_QWORD *)(v18 + 6668);
    *(_QWORD *)(a4 + 380) = *(_QWORD *)(v18 + 6676);
    *(_QWORD *)(a4 + 388) = *(_QWORD *)(v18 + 6684);
    *(_QWORD *)(a4 + 396) = *(_QWORD *)(v18 + 6692);
    *(_QWORD *)(a4 + 404) = *(_QWORD *)(v18 + 6700);
    *(_QWORD *)(a4 + 412) = *(_QWORD *)(v18 + 6708);
    *(_QWORD *)(a4 + 420) = *(_QWORD *)(v18 + 6716);
    *(_QWORD *)(a4 + 428) = *(_QWORD *)(v18 + 6724);
    *(_QWORD *)(a4 + 436) = *(_QWORD *)(v18 + 6732);
    *(_QWORD *)(a4 + 444) = *(_QWORD *)(v18 + 6740);
    *(_QWORD *)(a4 + 452) = *(_QWORD *)(v18 + 6748);
    *(_QWORD *)(a4 + 460) = *(_QWORD *)(v18 + 6756);
    *(_QWORD *)(a4 + 468) = *(_QWORD *)(v18 + 6764);
  }
  return result;
}
