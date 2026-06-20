__int64 __fastcall wlan_clear_sae_auth_logs_cache(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 ext_hdl; // x0
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x21
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x20

  v2 = a2;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( result )
  {
    v12 = result;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(result, v4, v5, v6, v7, v8, v9, v10, v11);
    if ( ext_hdl )
    {
      v23 = ext_hdl;
      qdf_trace_msg(
        0x38u,
        8u,
        "%s: vdev:%d clear sae auth logs cache",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wlan_clear_sae_auth_logs_cache",
        v2);
      qdf_mem_set((void *)(v23 + 336), 0x5AD8u, 0);
      return wlan_objmgr_vdev_release_ref(v12, 0x43u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
    }
    else
    {
      result = wlan_objmgr_vdev_release_ref(v12, 0x43u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
      v42 = jiffies;
      if ( wlan_clear_sae_auth_logs_cache___last_ticks_1 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x1Fu,
                   2u,
                   "%s: vdev legacy private object is NULL",
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   "wlan_clear_sae_auth_logs_cache");
        wlan_clear_sae_auth_logs_cache___last_ticks_1 = v42;
      }
    }
  }
  else
  {
    v33 = jiffies;
    if ( wlan_clear_sae_auth_logs_cache___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x1Fu,
                 2u,
                 "%s: Invalid vdev:%d",
                 v4,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 "wlan_clear_sae_auth_logs_cache",
                 v2);
      wlan_clear_sae_auth_logs_cache___last_ticks = v33;
    }
  }
  return result;
}
