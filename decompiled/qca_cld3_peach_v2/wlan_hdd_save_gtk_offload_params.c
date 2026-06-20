__int64 __fastcall wlan_hdd_save_gtk_offload_params(
        __int64 a1,
        const void *a2,
        char a3,
        const void *a4,
        unsigned int a5,
        _BYTE *a6)
{
  unsigned int v7; // w26
  __int64 *v8; // x23
  __int64 result; // x0
  __int64 v14; // x19
  __int64 v15; // x28
  __int16 v16; // w8
  int v17; // w9
  __int64 vdev_by_user; // x0
  __int64 v19; // x20
  int v20; // w21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  LOBYTE(v7) = a3;
  v8 = *(__int64 **)(a1 + 24);
  result = _qdf_mem_malloc(0x80u, "wlan_hdd_save_gtk_offload_params", 9152);
  if ( result )
  {
    v14 = result;
    v15 = *(_QWORD *)(a1 + 52832);
    if ( a2 )
    {
      if ( (v7 & 0xE0) != 0 )
        v7 = 32;
      else
        v7 = (unsigned __int8)v7;
      qdf_mem_copy((void *)(result + 4), a2, v7);
      *(_BYTE *)(v14 + 36) = v7;
    }
    if ( a4 )
    {
      if ( a5 >= 0x40 )
        a5 = 64;
      qdf_mem_copy((void *)(v14 + 37), a4, a5);
    }
    v16 = *(_WORD *)(v15 + 312);
    v17 = *(_DWORD *)(v15 + 308);
    *(_DWORD *)(v14 + 104) = a5;
    *(_WORD *)(v14 + 124) = v16;
    *(_DWORD *)(v14 + 120) = v17;
    *(_BYTE *)(v14 + 126) = hdd_is_fils_connection(v8, a1) & 1;
    *(_BYTE *)(v14 + 119) = *a6;
    *(_BYTE *)(v14 + 118) = a6[1];
    *(_BYTE *)(v14 + 117) = a6[2];
    *(_BYTE *)(v14 + 116) = a6[3];
    *(_BYTE *)(v14 + 115) = a6[4];
    *(_BYTE *)(v14 + 114) = a6[5];
    *(_BYTE *)(v14 + 113) = a6[6];
    *(_BYTE *)(v14 + 112) = a6[7];
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 86, "wlan_hdd_save_gtk_offload_params");
    if ( vdev_by_user )
    {
      v19 = vdev_by_user;
      v20 = ucfg_pmo_cache_gtk_offload_req(vdev_by_user, v14);
      _hdd_objmgr_put_vdev_by_user(v19, 86, "wlan_hdd_save_gtk_offload_params");
      if ( v20 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to cache GTK Offload",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "wlan_hdd_save_gtk_offload_params");
    }
    return _qdf_mem_free(v14);
  }
  return result;
}
