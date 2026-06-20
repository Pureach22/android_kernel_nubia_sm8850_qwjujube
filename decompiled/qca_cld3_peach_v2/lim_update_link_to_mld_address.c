__int64 __fastcall lim_update_link_to_mld_address(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char is_sae_auth_addr_conversion_required; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  int v24; // w8
  __int64 v25; // x0
  void *v26; // x0
  int *v27; // x1
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 peer_mld_addr; // x0
  int v37; // w9
  int v38; // [xsp+8h] [xbp-18h] BYREF
  __int16 v39; // [xsp+Ch] [xbp-14h]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v38 = 0;
  is_sae_auth_addr_conversion_required = wlan_cm_is_sae_auth_addr_conversion_required(
                                           a2,
                                           a4,
                                           a5,
                                           a6,
                                           a7,
                                           a8,
                                           a9,
                                           a10,
                                           a11);
  result = 0;
  if ( (is_sae_auth_addr_conversion_required & 1) != 0 )
  {
    v24 = *(_DWORD *)(a2 + 16);
    if ( v24 )
    {
      if ( v24 != 1 )
        goto LABEL_13;
      v25 = lim_search_pre_auth_list(a1, a3 + 10);
      if ( !v25 )
      {
        result = 4;
        goto LABEL_14;
      }
      if ( !(*(_DWORD *)(v25 + 601) | *(unsigned __int16 *)(v25 + 605)) )
        goto LABEL_13;
      qdf_mem_copy((void *)(a3 + 10), (const void *)(v25 + 601), 6u);
      v26 = (void *)(a3 + 16);
      v27 = (int *)(a2 + 80);
LABEL_12:
      qdf_mem_copy(v26, v27, 6u);
      qdf_mem_copy((void *)(a3 + 4), (const void *)(a2 + 80), 6u);
LABEL_13:
      result = 0;
      goto LABEL_14;
    }
    if ( wlan_cm_is_vdev_active(a2, v15, v16, v17, v18, v19, v20, v21, v22) )
    {
      peer_mld_addr = wlan_cm_roaming_get_peer_mld_addr(a2, v28, v29, v30, v31, v32, v33, v34, v35);
      if ( !peer_mld_addr )
      {
        result = 16;
        goto LABEL_14;
      }
      v37 = *(_DWORD *)peer_mld_addr;
      v39 = *(_WORD *)(peer_mld_addr + 4);
      v38 = v37;
      goto LABEL_11;
    }
    result = wlan_vdev_get_bss_peer_mld_mac(a2, &v38, v28, v29, v30, v31, v32, v33, v34, v35);
    if ( !(_DWORD)result )
    {
LABEL_11:
      qdf_mem_copy((void *)(a3 + 10), &v38, 6u);
      v26 = (void *)(a3 + 16);
      v27 = &v38;
      goto LABEL_12;
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
