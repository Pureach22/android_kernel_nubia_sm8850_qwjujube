__int64 __fastcall policy_mgr_get_ml_sta_info(
        _QWORD *a1,
        _BYTE *a2,
        _BYTE *a3,
        __int64 a4,
        __int64 a5,
        _BYTE *a6,
        __int64 a7,
        __int64 a8)
{
  __int64 i; // x21
  unsigned int v14; // w28
  int v15; // w25
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x27
  unsigned __int64 v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  int v36; // w9
  __int64 v37; // x8
  int v38; // w9

  *a2 = 0;
  *a3 = 0;
  if ( a6 )
    *a6 = 0;
  qdf_mutex_acquire((__int64)(a1 + 7));
  for ( i = 0; i != 180; i += 36 )
  {
    if ( *((_BYTE *)&pm_conc_connection_list + i + 28) == 1 && !*(_DWORD *)((char *)&pm_conc_connection_list + i) )
    {
      v14 = *((unsigned __int8 *)&pm_conc_connection_list + i + 24);
      v15 = *(_DWORD *)((char *)&pm_conc_connection_list + i + 4);
      v16 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              *a1,
              *((unsigned __int8 *)&pm_conc_connection_list + i + 24),
              24);
      if ( v16 )
      {
        v25 = v16;
        if ( (wlan_vdev_mlme_is_mlo_vdev(v16, v17, v18, v19, v20, v21, v22, v23, v24) & 1) != 0 )
        {
          *(_BYTE *)(a4 + (unsigned __int8)*a2) = v14;
          v26 = (unsigned __int8)*a2;
          *a2 = v26 + 1;
          *(_DWORD *)(a5 + 4 * v26) = v15;
        }
        else if ( a6 )
        {
          if ( a7 )
            *(_BYTE *)(a7 + (unsigned __int8)*a6) = v14;
          if ( a8 )
            *(_DWORD *)(a8 + 4LL * (unsigned __int8)*a6) = v15;
          v26 = (unsigned int)(unsigned __int8)(*a6)++ + 1;
        }
        wlan_objmgr_vdev_release_ref(v25, 0x18u, (unsigned int *)v26, v27, v28, v29, v30, v31, v32, v33, v34);
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: invalid vdev for id %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "policy_mgr_get_ml_sta_info",
          v14);
      }
    }
  }
  if ( pm_disabled_ml_links == 1 && !dword_8D4FC4 )
  {
    *(_BYTE *)(a4 + (unsigned __int8)*a2) = byte_8D4FCC;
    v35 = (unsigned __int8)*a2;
    v36 = dword_8D4FC8;
    *a2 = v35 + 1;
    *(_DWORD *)(a5 + 4 * v35) = v36;
    ++*a3;
  }
  if ( byte_8D4FD0 == 1 && !dword_8D4FD4 )
  {
    *(_BYTE *)(a4 + (unsigned __int8)*a2) = byte_8D4FDC;
    v37 = (unsigned __int8)*a2;
    v38 = dword_8D4FD8;
    *a2 = v37 + 1;
    *(_DWORD *)(a5 + 4 * v37) = v38;
    ++*a3;
  }
  return qdf_mutex_release((__int64)(a1 + 7));
}
