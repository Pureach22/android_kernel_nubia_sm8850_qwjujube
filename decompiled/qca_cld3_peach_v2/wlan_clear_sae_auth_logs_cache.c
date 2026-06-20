__int64 __fastcall wlan_clear_sae_auth_logs_cache(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w20
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  __int64 v23; // x0
  unsigned int v24; // w20
  __int64 ext_hdl; // x0
  __int64 v26; // x21
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x21
  const char *v30; // x3
  __int64 v31; // x4
  __int64 v32; // x21
  __int64 v33; // x0
  unsigned int *v34; // x8
  __int64 v35; // x21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x20
  __int64 v45; // x22

  v2 = a2;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( result )
  {
    v12 = result;
    if ( (wlan_vdev_mlme_is_mlo_vdev(result, v4, v5, v6, v7, v8, v9, v10, v11) & 1) != 0 )
    {
      v22 = *(_QWORD *)(v12 + 1360);
      if ( !v22 )
      {
        v35 = jiffies;
        v13 = (unsigned int *)(wlan_clear_ml_vdev_sae_auth_logs___last_ticks - jiffies);
        if ( wlan_clear_ml_vdev_sae_auth_logs___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x1Fu,
            2u,
            "%s: mlo_dev ctx is NULL for vdev:%d",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "wlan_clear_ml_vdev_sae_auth_logs",
            *(unsigned __int8 *)(v12 + 168));
          wlan_clear_ml_vdev_sae_auth_logs___last_ticks = v35;
        }
        return wlan_objmgr_vdev_release_ref(v12, 0x43u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
      }
      v23 = *(_QWORD *)(v22 + 24);
      if ( v23 )
      {
        v24 = *(unsigned __int8 *)(v23 + 168);
        ext_hdl = wlan_vdev_mlme_get_ext_hdl(v23, v14, v15, v16, v17, v18, v19, v20, v21);
        if ( !ext_hdl )
          goto LABEL_19;
        v26 = ext_hdl;
        qdf_trace_msg(
          0x38u,
          8u,
          "%s: vdev:%d clear sae auth logs cache",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_clear_ml_vdev_sae_auth_logs",
          v24);
        qdf_mem_set((void *)(v26 + 336), 0x5AD8u, 0);
      }
      v27 = *(_QWORD *)(v22 + 32);
      if ( !v27 )
        return wlan_objmgr_vdev_release_ref(v12, 0x43u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
      v24 = *(unsigned __int8 *)(v27 + 168);
      v28 = wlan_vdev_mlme_get_ext_hdl(v27, v14, v15, v16, v17, v18, v19, v20, v21);
      if ( v28 )
      {
        v29 = v28;
        v30 = "wlan_clear_ml_vdev_sae_auth_logs";
        v31 = v24;
LABEL_14:
        qdf_trace_msg(
          0x38u,
          8u,
          "%s: vdev:%d clear sae auth logs cache",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v30,
          v31);
        qdf_mem_set((void *)(v29 + 336), 0x5AD8u, 0);
        return wlan_objmgr_vdev_release_ref(v12, 0x43u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
      }
LABEL_19:
      v45 = jiffies;
      v13 = (unsigned int *)(wlan_clear_ml_vdev_sae_auth_logs___last_ticks_34 - jiffies);
      if ( wlan_clear_ml_vdev_sae_auth_logs___last_ticks_34 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x1Fu,
          2u,
          "%s: vdev:%d legacy private object is NULL",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_clear_ml_vdev_sae_auth_logs",
          v24);
        wlan_clear_ml_vdev_sae_auth_logs___last_ticks_34 = v45;
      }
      return wlan_objmgr_vdev_release_ref(v12, 0x43u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
    }
    v33 = wlan_vdev_mlme_get_ext_hdl(v12, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( v33 )
    {
      v29 = v33;
      v30 = "wlan_clear_sae_auth_logs_cache";
      v31 = v2;
      goto LABEL_14;
    }
    result = wlan_objmgr_vdev_release_ref(v12, 0x43u, v34, v14, v15, v16, v17, v18, v19, v20, v21);
    v44 = jiffies;
    if ( wlan_clear_sae_auth_logs_cache___last_ticks_1 - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x1Fu,
                 2u,
                 "%s: vdev legacy private object is NULL",
                 v36,
                 v37,
                 v38,
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 "wlan_clear_sae_auth_logs_cache");
      wlan_clear_sae_auth_logs_cache___last_ticks_1 = v44;
    }
  }
  else
  {
    v32 = jiffies;
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
      wlan_clear_sae_auth_logs_cache___last_ticks = v32;
    }
  }
  return result;
}
