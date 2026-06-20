__int64 __fastcall cm_lookup_pmkid_using_bssid(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 pmksa; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v4 )
  {
    v13 = v4;
    pmksa = wlan_crypto_get_pmksa(v4, a3, v5, v6, v7, v8, v9, v10, v11, v12);
    if ( pmksa )
    {
      v24 = pmksa;
      qdf_mem_copy((void *)(a3 + 6), (const void *)(pmksa + 6), 0x10u);
      qdf_mem_copy((void *)(a3 + 22), (const void *)(v24 + 22), *(unsigned __int8 *)(v24 + 86));
      *(_BYTE *)(a3 + 86) = *(_BYTE *)(v24 + 86);
      *(_DWORD *)(a3 + 124) = *(_DWORD *)(v24 + 124);
      *(_BYTE *)(a3 + 128) = *(_BYTE *)(v24 + 128);
      v25 = *(unsigned int **)(v24 + 136);
      *(_QWORD *)(a3 + 136) = v25;
      wlan_objmgr_vdev_release_ref(v13, 0x4Du, v25, v26, v27, v28, v29, v30, v31, v32, v33);
      return 1;
    }
    wlan_objmgr_vdev_release_ref(v13, 0x4Du, v15, v16, v17, v18, v19, v20, v21, v22, v23);
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid vdev", v5, v6, v7, v8, v9, v10, v11, v12, "cm_lookup_pmkid_using_bssid");
  }
  return 0;
}
