__int64 __fastcall wlan_hdd_set_pmksa_cache(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 v13; // x22
  __int64 vdev_by_user; // x0
  __int64 v15; // x20
  __int64 v16; // x0
  __int64 v17; // x23
  int v19; // w9
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w25

  v10 = *(_QWORD *)(a1 + 24);
  if ( !v10 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: HDD context is null", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_set_pmksa_cache");
    return 4;
  }
  if ( (unsigned int)_wlan_hdd_validate_context(*(_QWORD *)(a1 + 24), "wlan_hdd_set_pmksa_cache") )
    return 4;
  v13 = *(_QWORD *)(v10 + 16);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 6, "wlan_hdd_set_pmksa_cache");
  if ( !vdev_by_user )
    return 16;
  v15 = vdev_by_user;
  v16 = _qdf_mem_malloc(0x98u, "wlan_hdd_set_pmksa_cache", 30979);
  if ( v16 )
  {
    v17 = v16;
    if ( *((_BYTE *)a2 + 87) )
    {
      qdf_mem_copy((void *)(v16 + 88), a2 + 22, *((unsigned __int8 *)a2 + 87));
      qdf_mem_copy((void *)(v17 + 120), a2 + 30, 2u);
      *(_BYTE *)(v17 + 87) = *((_BYTE *)a2 + 87);
    }
    else
    {
      v19 = *a2;
      *(_WORD *)(v16 + 4) = *((_WORD *)a2 + 2);
      *(_DWORD *)v16 = v19;
    }
    qdf_mem_copy((void *)(v17 + 6), (char *)a2 + 6, 0x10u);
    qdf_mem_copy((void *)(v17 + 22), (char *)a2 + 22, *((unsigned __int8 *)a2 + 86));
    *(_BYTE *)(v17 + 86) = *((_BYTE *)a2 + 86);
    *(_QWORD *)(v17 + 136) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    *(_DWORD *)(v17 + 124) = a2[31];
    *(_BYTE *)(v17 + 128) = *((_BYTE *)a2 + 128);
    v28 = wlan_crypto_set_del_pmksa(v15, v17, 1, v20, v21, v22, v23, v24, v25, v26, v27);
    if ( v28 )
    {
      qdf_mem_set((void *)v17, 0x98u, 0);
      _qdf_mem_free(v17);
    }
    else if ( *((_BYTE *)a2 + 86) )
    {
      sme_roam_set_psk_pmk(v13, v17, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), 0);
      sme_set_pmk_cache_ft(v13, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), a2);
    }
    _hdd_objmgr_put_vdev_by_user(v15, 6, "wlan_hdd_set_pmksa_cache");
    return v28;
  }
  else
  {
    _hdd_objmgr_put_vdev_by_user(v15, 6, "wlan_hdd_set_pmksa_cache");
    return 2;
  }
}
