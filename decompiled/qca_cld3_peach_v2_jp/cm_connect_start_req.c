__int64 __fastcall cm_connect_start_req(__int64 a1, __int64 a2)
{
  __int64 cm_ctx_fl; // x0
  __int64 v5; // x0
  __int64 v6; // x19
  void *v7; // x0
  void *v8; // x0
  void *v9; // x0
  void *v10; // x0
  int v11; // w8
  int v12; // w9
  int v13; // w8
  int v14; // w10
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 result; // x0
  unsigned int v18; // w20
  int v19; // [xsp+Ch] [xbp-134h] BYREF
  __int64 v20; // [xsp+10h] [xbp-130h] BYREF
  _DWORD s[72]; // [xsp+18h] [xbp-128h] BYREF
  __int64 v22; // [xsp+138h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  cm_ctx_fl = cm_get_cm_ctx_fl(a1, "cm_connect_start_req", 3610);
  if ( !cm_ctx_fl )
  {
    result = 4;
    goto LABEL_33;
  }
  cm_vdev_scan_cancel(*(_QWORD *)(*(_QWORD *)cm_ctx_fl + 152LL));
  v5 = _qdf_mem_malloc(0x380u, "cm_connect_start_req", 3620);
  if ( !v5 )
  {
    result = 2;
    goto LABEL_33;
  }
  v6 = v5;
  memcpy((void *)(v5 + 32), (const void *)a2, 0x330u);
  *(_QWORD *)(v6 + 128) = 0;
  *(_QWORD *)(v6 + 192) = 0;
  *(_QWORD *)(v6 + 208) = 0;
  *(_QWORD *)(v6 + 136) = 0;
  if ( *(_QWORD *)(a2 + 176) )
  {
    v7 = (void *)_qdf_mem_malloc(*(unsigned int *)(a2 + 168), "cm_allocate_and_copy_ies_and_keys", 3560);
    *(_QWORD *)(v6 + 208) = v7;
    if ( !v7 )
    {
      *(_DWORD *)(v6 + 200) = 0;
      if ( !*(_QWORD *)(a2 + 160) )
        goto LABEL_9;
      goto LABEL_7;
    }
    qdf_mem_copy(v7, *(const void **)(a2 + 176), *(unsigned int *)(a2 + 168));
  }
  if ( !*(_QWORD *)(a2 + 160) )
    goto LABEL_9;
LABEL_7:
  v8 = (void *)_qdf_mem_malloc(*(unsigned int *)(a2 + 152), "cm_allocate_and_copy_ies_and_keys", 3569);
  *(_QWORD *)(v6 + 192) = v8;
  if ( !v8 )
    goto LABEL_31;
  qdf_mem_copy(v8, *(const void **)(a2 + 160), *(unsigned int *)(a2 + 152));
LABEL_9:
  if ( *(_QWORD *)(a2 + 96) )
  {
    v9 = (void *)_qdf_mem_malloc(*(unsigned __int8 *)(a2 + 112), "cm_allocate_and_copy_ies_and_keys", 3579);
    *(_QWORD *)(v6 + 128) = v9;
    if ( !v9 )
      goto LABEL_31;
    qdf_mem_copy(v9, *(const void **)(a2 + 96), *(unsigned __int8 *)(a2 + 112));
  }
  if ( !*(_QWORD *)(a2 + 104) )
    goto LABEL_15;
  v10 = (void *)_qdf_mem_malloc(*(unsigned __int8 *)(a2 + 113), "cm_allocate_and_copy_ies_and_keys", 3590);
  *(_QWORD *)(v6 + 136) = v10;
  if ( !v10 )
  {
LABEL_31:
    LODWORD(result) = 2;
LABEL_32:
    v18 = result;
    cm_free_connect_req_mem(v6 + 24);
    _qdf_mem_free(v6);
    result = v18;
    goto LABEL_33;
  }
  qdf_mem_copy(v10, *(const void **)(a2 + 104), *(unsigned __int8 *)(a2 + 113));
LABEL_15:
  if ( *(_QWORD *)(v6 + 192) )
  {
    memset(s, 0, sizeof(s));
    v20 = 0;
    v19 = 82989056;
    qdf_mem_copy((char *)&v20 + 4, &v19, 4u);
    v19 = 312110928;
    qdf_mem_copy(&v20, &v19, 4u);
    if ( wlan_get_vendor_ie_ptr_from_oui(&v20, 4u, *(unsigned __int8 **)(v6 + 192), *(_DWORD *)(v6 + 184)) )
      *(_BYTE *)(v6 + 216) |= 4u;
    if ( wlan_get_vendor_ie_ptr_from_oui((char *)&v20 + 4, 4u, *(unsigned __int8 **)(v6 + 192), *(_DWORD *)(v6 + 184)) )
      *(_BYTE *)(v6 + 216) |= 2u;
    if ( !(unsigned int)wlan_get_crypto_params_from_rsn_ie(s, *(_QWORD *)(v6 + 192), *(_DWORD *)(v6 + 184), nullptr)
      || !(unsigned int)wlan_get_crypto_params_from_wpa_ie(s, *(_QWORD *)(v6 + 192), *(_DWORD *)(v6 + 184), nullptr)
      || !(unsigned int)wlan_get_crypto_params_from_wapi_ie(s, *(_QWORD *)(v6 + 192), *(_DWORD *)(v6 + 184)) )
    {
      v11 = *(_DWORD *)(v6 + 120) | s[5];
      v12 = s[0];
      *(_DWORD *)(v6 + 116) |= s[1];
      *(_DWORD *)(v6 + 120) = v11;
      v13 = s[2];
      v14 = s[3];
      *(_DWORD *)(v6 + 108) = v12;
      *(_DWORD *)(v6 + 112) = v13;
      LOWORD(v13) = s[38];
      *(_DWORD *)(v6 + 156) = v14;
      *(_WORD *)(v6 + 152) = v13;
    }
  }
  v15 = *(_QWORD *)(a1 + 152);
  if ( v15 )
  {
    v16 = *(_QWORD *)(v15 + 80);
    if ( v16 )
      wlan_tdls_check_and_teardown_links_sync(v16, a1);
  }
  wlan_cm_set_force_20mhz_in_24ghz(a1, (*(unsigned __int16 *)(a2 + 194) >> 1) & 1);
  result = cm_sm_deliver_event(a1, 0, 872, v6 + 24);
  if ( (_DWORD)result )
    goto LABEL_32;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
