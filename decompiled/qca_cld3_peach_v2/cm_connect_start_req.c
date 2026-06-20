__int64 __fastcall cm_connect_start_req(__int64 a1, __int64 a2)
{
  __int64 cm_ctx_fl; // x0
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  void *v15; // x0
  void *v16; // x0
  void *v17; // x0
  void *v18; // x0
  int v19; // w8
  int v20; // w9
  int v21; // w8
  int v22; // w10
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 result; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  unsigned int v28; // w20
  int v29; // [xsp+Ch] [xbp-134h] BYREF
  __int64 v30; // [xsp+10h] [xbp-130h] BYREF
  _DWORD s[72]; // [xsp+18h] [xbp-128h] BYREF
  __int64 v32; // [xsp+138h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  cm_ctx_fl = cm_get_cm_ctx_fl(a1, "cm_connect_start_req", 3610);
  if ( !cm_ctx_fl )
  {
    result = 4;
    goto LABEL_41;
  }
  cm_vdev_scan_cancel(*(_QWORD *)(*(_QWORD *)cm_ctx_fl + 216LL));
  v5 = _qdf_mem_malloc(0x9F0u, "cm_connect_start_req", 3620);
  if ( !v5 )
  {
    result = 2;
    goto LABEL_41;
  }
  v14 = v5;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v6, v7, v8, v9, v10, v11, v12, v13) & 1) != 0 && (*(_BYTE *)(a1 + 60) & 2) != 0 )
    *(_BYTE *)(a2 + 808) = 1;
  memcpy((void *)(v14 + 32), (const void *)a2, 0x3E0u);
  *(_QWORD *)(v14 + 128) = 0;
  *(_QWORD *)(v14 + 192) = 0;
  *(_QWORD *)(v14 + 208) = 0;
  *(_QWORD *)(v14 + 136) = 0;
  if ( *(_QWORD *)(a2 + 176) )
  {
    v15 = (void *)_qdf_mem_malloc(*(unsigned int *)(a2 + 168), "cm_allocate_and_copy_ies_and_keys", 3560);
    *(_QWORD *)(v14 + 208) = v15;
    if ( !v15 )
    {
      *(_DWORD *)(v14 + 200) = 0;
      if ( !*(_QWORD *)(a2 + 160) )
        goto LABEL_12;
      goto LABEL_10;
    }
    qdf_mem_copy(v15, *(const void **)(a2 + 176), *(unsigned int *)(a2 + 168));
  }
  if ( !*(_QWORD *)(a2 + 160) )
    goto LABEL_12;
LABEL_10:
  v16 = (void *)_qdf_mem_malloc(*(unsigned int *)(a2 + 152), "cm_allocate_and_copy_ies_and_keys", 3569);
  *(_QWORD *)(v14 + 192) = v16;
  if ( !v16 )
    goto LABEL_31;
  qdf_mem_copy(v16, *(const void **)(a2 + 160), *(unsigned int *)(a2 + 152));
LABEL_12:
  if ( *(_QWORD *)(a2 + 96) )
  {
    v17 = (void *)_qdf_mem_malloc(*(unsigned __int8 *)(a2 + 112), "cm_allocate_and_copy_ies_and_keys", 3579);
    *(_QWORD *)(v14 + 128) = v17;
    if ( !v17 )
      goto LABEL_31;
    qdf_mem_copy(v17, *(const void **)(a2 + 96), *(unsigned __int8 *)(a2 + 112));
  }
  if ( !*(_QWORD *)(a2 + 104) )
    goto LABEL_18;
  v18 = (void *)_qdf_mem_malloc(*(unsigned __int8 *)(a2 + 113), "cm_allocate_and_copy_ies_and_keys", 3590);
  *(_QWORD *)(v14 + 136) = v18;
  if ( !v18 )
  {
LABEL_31:
    LODWORD(result) = 2;
LABEL_40:
    v28 = result;
    cm_free_connect_req_mem(v14 + 24);
    _qdf_mem_free(v14);
    result = v28;
    goto LABEL_41;
  }
  qdf_mem_copy(v18, *(const void **)(a2 + 104), *(unsigned __int8 *)(a2 + 113));
LABEL_18:
  if ( *(_QWORD *)(v14 + 192) )
  {
    memset(s, 0, sizeof(s));
    v30 = 0;
    v29 = 82989056;
    qdf_mem_copy((char *)&v30 + 4, &v29, 4u);
    v29 = 312110928;
    qdf_mem_copy(&v30, &v29, 4u);
    if ( wlan_get_vendor_ie_ptr_from_oui(&v30, 4u, *(unsigned __int8 **)(v14 + 192), *(_DWORD *)(v14 + 184)) )
      *(_BYTE *)(v14 + 216) |= 4u;
    if ( wlan_get_vendor_ie_ptr_from_oui((char *)&v30 + 4, 4u, *(unsigned __int8 **)(v14 + 192), *(_DWORD *)(v14 + 184)) )
      *(_BYTE *)(v14 + 216) |= 2u;
    if ( !(unsigned int)wlan_get_crypto_params_from_rsn_ie(s, *(_QWORD *)(v14 + 192), *(_DWORD *)(v14 + 184), nullptr)
      || !(unsigned int)wlan_get_crypto_params_from_wpa_ie(s, *(_QWORD *)(v14 + 192), *(_DWORD *)(v14 + 184), nullptr)
      || !(unsigned int)wlan_get_crypto_params_from_wapi_ie(s, *(_QWORD *)(v14 + 192), *(_DWORD *)(v14 + 184)) )
    {
      v19 = *(_DWORD *)(v14 + 120) | s[5];
      v20 = s[0];
      *(_DWORD *)(v14 + 116) |= s[1];
      *(_DWORD *)(v14 + 120) = v19;
      v21 = s[2];
      v22 = s[3];
      *(_DWORD *)(v14 + 108) = v20;
      *(_DWORD *)(v14 + 112) = v21;
      LOWORD(v21) = s[38];
      *(_DWORD *)(v14 + 156) = v22;
      *(_WORD *)(v14 + 152) = v21;
    }
  }
  v23 = *(_QWORD *)(a1 + 216);
  if ( v23 )
    v24 = *(_QWORD *)(v23 + 80);
  else
    v24 = 0;
  ucfg_cm_handle_legacy_conn_pre_start(v24, *(unsigned __int8 *)(a1 + 168));
  if ( (*(_BYTE *)(a1 + 60) & 2) == 0 )
  {
    v26 = *(_QWORD *)(a1 + 216);
    if ( v26 )
    {
      v27 = *(_QWORD *)(v26 + 80);
      if ( v27 )
        wlan_tdls_check_and_teardown_links_sync(v27, a1);
    }
  }
  wlan_cm_set_force_20mhz_in_24ghz(a1, (*(unsigned __int16 *)(a2 + 194) >> 1) & 1);
  result = cm_sm_deliver_event(a1, 0, 2520, v14 + 24);
  if ( (_DWORD)result )
    goto LABEL_40;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
