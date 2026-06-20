__int64 __fastcall cm_check_and_set_sae_single_pmk_cap(__int64 a1, __int64 a2, const void *a3, unsigned __int8 a4)
{
  unsigned int v6; // w20
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int64 v27; // x8
  __int64 result; // x0
  int param; // w0
  __int64 v30; // x0
  __int16 v31; // w8
  int v32; // w10
  unsigned __int8 *v33; // x24
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x0
  int v43; // w9
  __int64 v44; // x22
  void *v45; // x0
  __int64 v46; // x20
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // [xsp+10h] [xbp-30h] BYREF
  __int64 v56; // [xsp+18h] [xbp-28h]
  __int64 v57; // [xsp+20h] [xbp-20h]
  __int64 v58; // [xsp+28h] [xbp-18h]
  int v59; // [xsp+30h] [xbp-10h] BYREF
  __int16 v60; // [xsp+34h] [xbp-Ch]
  __int64 v61; // [xsp+38h] [xbp-8h]

  v6 = a2;
  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = 0;
  v59 = 0;
  v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( !v8 )
  {
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: get vdev failed",
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "cm_check_and_set_sae_single_pmk_cap");
    goto LABEL_7;
  }
  v17 = v8;
  if ( (unsigned int)wlan_vdev_get_bss_peer_mac_for_pmksa(v8, (__int64)&v59, v9, v10, v11, v12, v13, v14, v15, v16) )
  {
    v26 = "%s: Failed to find connected bssid";
  }
  else
  {
    param = wlan_crypto_get_param(v17, 7u);
    if ( (param & 0x80000000) == 0 )
    {
      v27 = 134218752;
      if ( (param & 0x8000400) != 0 )
      {
        v57 = 0;
        v58 = 0;
        v55 = 0;
        v56 = 0;
        wlan_cm_roam_cfg_get_value(a1, v6, 25, (int)&v55);
        wlan_mlme_set_sae_single_pmk_bss_cap(a1, v6, v56);
        v27 = (unsigned __int8)v56;
        if ( (unsigned __int8)v56 == 1 )
        {
          v30 = _qdf_mem_malloc(0x98u, "cm_check_and_set_sae_single_pmk_cap", 6186);
          if ( v30 )
          {
            v31 = v60;
            v32 = v59;
            *(_BYTE *)(v30 + 144) = 1;
            v33 = (unsigned __int8 *)v30;
            *(_WORD *)(v30 + 4) = v31;
            *(_DWORD *)v30 = v32;
            *(_BYTE *)(v30 + 86) = a4;
            qdf_mem_copy((void *)(v30 + 22), a3, a4);
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: SPMK received for %02x:%02x:%02x:**:**:%02xpmk_len:%d",
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              "cm_check_and_set_sae_single_pmk_cap",
              *v33,
              v33[1],
              v33[2],
              v33[5],
              v33[86]);
            wlan_crypto_set_sae_single_pmk_info(v17, (__int64)v33);
            qdf_mem_set(v33, 0x98u, 0);
            _qdf_mem_free((__int64)v33);
            v42 = _qdf_mem_malloc(0x98u, "cm_check_and_set_sae_single_pmk_cap", 6206);
            if ( v42 )
            {
              v43 = v59;
              v44 = v42;
              *(_WORD *)(v42 + 4) = v60;
              *(_DWORD *)v42 = v43;
              if ( (cm_lookup_pmkid_using_bssid(a1, v6, v42) & 1) != 0 )
              {
                wlan_crypto_selective_clear_sae_single_pmk_entries(v17, (__int64)&v59);
                v45 = (void *)_qdf_mem_malloc(0x50u, "cm_check_and_set_sae_single_pmk_cap", 6224);
                if ( v45 )
                {
                  v46 = (__int64)v45;
                  qdf_mem_copy(v45, (const void *)(v44 + 22), *(unsigned __int8 *)(v44 + 86));
                  *(_BYTE *)(v46 + 64) = *(_BYTE *)(v44 + 86);
                  *(_QWORD *)(v46 + 72) = *(_QWORD *)(v44 + 136);
                  *(_WORD *)(v46 + 66) = *(_DWORD *)(v44 + 124) * (unsigned int)*(unsigned __int8 *)(v44 + 128) / 0x64;
                  wlan_mlme_update_sae_single_pmk(v17, v46, v47, v48, v49, v50, v51, v52, v53, v54);
                  qdf_mem_set((void *)v46, 0x50u, 0);
                  _qdf_mem_free(v46);
                }
              }
              qdf_mem_set((void *)v44, 0x98u, 0);
              _qdf_mem_free(v44);
            }
          }
        }
      }
      goto LABEL_5;
    }
    v26 = "%s: Invalid mgmt cipher";
  }
  qdf_trace_msg(0x68u, 2u, v26, v18, v19, v20, v21, v22, v23, v24, v25, "cm_check_and_set_sae_single_pmk_cap");
LABEL_5:
  result = wlan_objmgr_vdev_release_ref(v17, 0x4Du, (unsigned int *)v27, v18, v19, v20, v21, v22, v23, v24, v25);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
