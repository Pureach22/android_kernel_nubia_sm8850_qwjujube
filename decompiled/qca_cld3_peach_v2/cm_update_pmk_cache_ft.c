__int64 __fastcall cm_update_pmk_cache_ft(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w21
  int v5; // w22
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  const char *v16; // x2
  unsigned int v17; // w1
  unsigned int *v18; // x8
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 cmpt_obj; // x0
  size_t v29; // x2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v39; // [xsp+8h] [xbp-B8h]
  __int64 v40; // [xsp+10h] [xbp-B0h]
  __int64 v41; // [xsp+18h] [xbp-A8h]
  _QWORD v42[10]; // [xsp+20h] [xbp-A0h] BYREF
  __int64 v43; // [xsp+70h] [xbp-50h]
  _QWORD v44[4]; // [xsp+78h] [xbp-48h] BYREF
  _QWORD v45[3]; // [xsp+98h] [xbp-28h] BYREF
  __int64 v46; // [xsp+B0h] [xbp-10h]
  __int64 v47; // [xsp+B8h] [xbp-8h]

  v4 = a2;
  v5 = a1;
  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  memset(v45, 0, sizeof(v45));
  memset(v44, 0, sizeof(v44));
  v43 = 0;
  v41 = 0;
  memset(v42, 0, sizeof(v42));
  v39 = 0;
  v40 = 0;
  v38 = 0;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v6 )
  {
    v15 = v6;
    if ( *(_DWORD *)(v6 + 16) )
    {
      v16 = "%s: vdev mode is not STA";
      v17 = 2;
    }
    else
    {
      wlan_vdev_get_bss_peer_mac_for_pmksa(v6, (__int64)v42, v7, v8, v9, v10, v11, v12, v13, v14);
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v15, v20, v21, v22, v23, v24, v25, v26, v27);
      if ( cmpt_obj )
      {
        v29 = *(unsigned __int8 *)(cmpt_obj + 178);
        if ( *(_BYTE *)(cmpt_obj + 178) )
        {
          HIBYTE(v43) = *(_BYTE *)(cmpt_obj + 178);
          qdf_mem_copy(v44, (const void *)(cmpt_obj + 145), v29);
        }
        else
        {
          HIBYTE(v43) = 0;
        }
      }
      wlan_cm_roam_cfg_get_value(v5, v4, 20, (int)&v38);
      if ( a3 )
        qdf_mem_copy(v45, (const void *)(a3 + 120), 2u);
      v18 = (unsigned int *)(unsigned __int8)v39;
      if ( (unsigned __int8)v39 != 1 )
        goto LABEL_15;
      BYTE2(v46) = v39;
      WORD2(v46) = v38;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: MDID:0x%x copied to PMKSA",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "cm_update_pmk_cache_ft");
      if ( !(unsigned int)wlan_crypto_update_pmk_cache_ft(v15, (__int64)v42, v30, v31, v32, v33, v34, v35, v36, v37) )
        goto LABEL_15;
      v16 = "%s: Failed to update the crypto table";
      v17 = 8;
    }
    qdf_trace_msg(0x68u, v17, v16, v7, v8, v9, v10, v11, v12, v13, v14, "cm_update_pmk_cache_ft");
LABEL_15:
    result = wlan_objmgr_vdev_release_ref(v15, 0x4Du, v18, v7, v8, v9, v10, v11, v12, v13, v14);
    goto LABEL_16;
  }
  result = qdf_trace_msg(0x68u, 2u, "%s: vdev is NULL", v7, v8, v9, v10, v11, v12, v13, v14, "cm_update_pmk_cache_ft");
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
