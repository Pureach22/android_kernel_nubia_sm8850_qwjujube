void *__fastcall mlo_mgr_update_link_info_reset(void *result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  int v4; // w8
  int v5; // w9
  int v6; // w8
  int v7; // w9

  _ReadStatusReg(SP_EL0);
  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 3880);
    v3 = (__int64)result;
    if ( *(_DWORD *)(v2 + 24) | *(unsigned __int16 *)(v2 + 28) && *(_DWORD *)v2 | *(unsigned __int16 *)(v2 + 4) )
      wlan_crypto_free_key_by_link_id((__int64)result, *(unsigned __int8 **)(a2 + 3880), *(_BYTE *)(v2 + 6));
    qdf_mem_set((void *)v2, 6u, 0);
    qdf_mem_set((void *)(v2 + 24), 6u, 0);
    qdf_mem_set(*(void **)(v2 + 32), 0x28u, 0);
    *(_QWORD *)(v2 + 16) = 0;
    v4 = *(_DWORD *)(v2 + 72);
    v5 = *(unsigned __int16 *)(v2 + 76);
    *(_BYTE *)(v2 + 12) = -1;
    *(_BYTE *)(v2 + 6) = -1;
    if ( v4 | v5 && *(_DWORD *)(v2 + 48) | *(unsigned __int16 *)(v2 + 52) )
      wlan_crypto_free_key_by_link_id(v3, (unsigned __int8 *)(v2 + 48), *(_BYTE *)(v2 + 54));
    qdf_mem_set((void *)(v2 + 48), 6u, 0);
    qdf_mem_set((void *)(v2 + 72), 6u, 0);
    qdf_mem_set(*(void **)(v2 + 80), 0x28u, 0);
    *(_BYTE *)(v2 + 60) = -1;
    v6 = *(_DWORD *)(v2 + 120);
    v7 = *(unsigned __int16 *)(v2 + 124);
    *(_BYTE *)(v2 + 54) = -1;
    *(_QWORD *)(v2 + 64) = 0;
    if ( v6 | v7 && *(_DWORD *)(v2 + 96) | *(unsigned __int16 *)(v2 + 100) )
      wlan_crypto_free_key_by_link_id(v3, (unsigned __int8 *)(v2 + 96), *(_BYTE *)(v2 + 102));
    qdf_mem_set((void *)(v2 + 96), 6u, 0);
    qdf_mem_set((void *)(v2 + 120), 6u, 0);
    result = qdf_mem_set(*(void **)(v2 + 128), 0x28u, 0);
    *(_QWORD *)(v2 + 112) = 0;
    *(_BYTE *)(v2 + 108) = -1;
    *(_BYTE *)(v2 + 102) = -1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
