__int64 __fastcall wlan_hdd_del_pmksa_cache(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 vdev_by_user; // x0
  __int64 v5; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  __int16 v15; // w9
  _QWORD v17[10]; // [xsp+0h] [xbp-A0h] BYREF
  __int64 v18; // [xsp+50h] [xbp-50h]
  _QWORD v19[4]; // [xsp+58h] [xbp-48h] BYREF
  _QWORD v20[5]; // [xsp+78h] [xbp-28h] BYREF

  v20[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 52824);
  memset(v20, 0, 32);
  memset(v19, 0, sizeof(v19));
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(v3, 6, "wlan_hdd_del_pmksa_cache");
  if ( vdev_by_user )
  {
    v5 = vdev_by_user;
    qdf_mem_set(v17, 0x98u, 0);
    if ( *(_BYTE *)(a2 + 87) )
    {
      qdf_mem_copy(v19, (const void *)(a2 + 88), *(unsigned __int8 *)(a2 + 87));
      qdf_mem_copy(v20, (const void *)(a2 + 120), 2u);
      HIBYTE(v18) = *(_BYTE *)(a2 + 87);
    }
    else
    {
      v15 = *(_WORD *)(a2 + 4);
      LODWORD(v17[0]) = *(_DWORD *)a2;
      WORD2(v17[0]) = v15;
    }
    v14 = wlan_crypto_set_del_pmksa(v5, (__int64)v17, 0, v6, v7, v8, v9, v10, v11, v12, v13);
    _hdd_objmgr_put_vdev_by_user(v5, 6, "wlan_hdd_del_pmksa_cache");
  }
  else
  {
    v14 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v14;
}
