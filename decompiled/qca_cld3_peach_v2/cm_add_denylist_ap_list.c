__int64 __fastcall cm_add_denylist_ap_list(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  __int64 bssid_reject_list; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int64 v18; // x21
  unsigned __int8 *v19; // x24
  __int64 i; // x25
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x7
  int v24; // w8
  int v25; // w9
  __int64 v26; // [xsp+0h] [xbp-10h]

  result = _qdf_mem_malloc(0x3C0u, "cm_add_denylist_ap_list", 2724);
  if ( result )
  {
    v5 = result;
    bssid_reject_list = dlm_get_bssid_reject_list(a1, result, 10, 1);
    *(_DWORD *)(a2 + 8) = (unsigned __int8)bssid_reject_list;
    if ( (_BYTE)bssid_reject_list )
    {
      v18 = 0;
      v19 = (unsigned __int8 *)(a2 + 20);
      for ( i = v5; ; i += 96 )
      {
        v25 = *(_DWORD *)i;
        *((_WORD *)v19 + 2) = *(_WORD *)(i + 4);
        *(_DWORD *)v19 = v25;
        if ( v18 == 16 )
          break;
        if ( v19 )
        {
          v21 = *v19;
          v22 = v19[1];
          v23 = v19[2];
          v24 = v19[5];
        }
        else
        {
          v23 = 0;
          v21 = 0;
          v22 = 0;
          v24 = 0;
        }
        LODWORD(v26) = v24;
        bssid_reject_list = qdf_trace_msg(
                              0x68u,
                              8u,
                              "%s: Denylist bssid[%d]:%02x:%02x:%02x:**:**:%02x",
                              v10,
                              v11,
                              v12,
                              v13,
                              v14,
                              v15,
                              v16,
                              v17,
                              "cm_add_denylist_ap_list",
                              (unsigned int)v18++,
                              v21,
                              v22,
                              v23,
                              v26);
        v19 += 6;
        if ( v18 >= *(unsigned int *)(a2 + 8) )
          return _qdf_mem_free(v5);
      }
      __break(0x5512u);
      return cm_roam_scan_offload_ap_profile(bssid_reject_list, v7, v8, v9);
    }
    else
    {
      return _qdf_mem_free(v5);
    }
  }
  return result;
}
