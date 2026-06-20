__int64 __fastcall policy_mgr_sta_ml_link_enable_allowed(
        __int64 a1,
        char a2,
        unsigned __int8 a3,
        __int64 a4,
        __int64 a5)
{
  char is_concurrency_allowed; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w8
  unsigned int v19; // w21
  unsigned int v20; // w20
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int *v30; // x8
  unsigned int v31; // w21
  __int64 v32; // x22
  __int64 assoc_link_vdev; // x0
  bool is_vdev_active; // w0

  is_concurrency_allowed = 0;
  if ( a2 && a3 >= 2u )
  {
    if ( (policy_mgr_is_ml_sta_links_in_mcc(a1, a4, a5, 0, a3, nullptr) & 1) != 0
      || (v18 = a3 - 1,
          v19 = *(unsigned __int8 *)(a5 + v18),
          v20 = *(_DWORD *)(a4 + 4LL * v18),
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: disabled_link_vdev_id %d disabled_link_freq %d",
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            "policy_mgr_sta_ml_link_enable_allowed",
            v19,
            v20),
          !v20) )
    {
      is_concurrency_allowed = 0;
    }
    else
    {
      v21 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v19, 24);
      if ( v21 )
      {
        v30 = (unsigned int *)*(unsigned int *)(v21 + 16);
        if ( (_DWORD)v30 )
        {
          v31 = 0;
LABEL_20:
          wlan_objmgr_vdev_release_ref(v21, 0x18u, v30, v22, v23, v24, v25, v26, v27, v28, v29);
          is_concurrency_allowed = policy_mgr_is_concurrency_allowed(a1, 0, v20, 3, v31, 0);
          return is_concurrency_allowed & 1;
        }
        v32 = v21;
        if ( (wlan_vdev_mlme_is_mlo_vdev(v21, v22, v23, v24, v25, v26, v27, v28, v29) & 1) != 0 )
        {
          v30 = (unsigned int *)*(unsigned __int8 *)(v32 + 60);
          v21 = v32;
          if ( ((unsigned __int8)v30 & 2) == 0 )
          {
            v31 = 1;
            goto LABEL_20;
          }
          assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(v32);
          if ( assoc_link_vdev )
          {
            is_vdev_active = ucfg_cm_is_vdev_active(assoc_link_vdev, v22, v23, v24, v25, v26, v27, v28, v29);
            v30 = (_DWORD *)(&off_0 + 3);
            if ( is_vdev_active )
              v31 = 3;
            else
              v31 = 1;
          }
          else
          {
            v31 = 1;
          }
        }
        else
        {
          v31 = 0;
        }
        v21 = v32;
        goto LABEL_20;
      }
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: invalid vdev for id %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "policy_mgr_sta_ml_link_enable_allowed",
        v19);
      is_concurrency_allowed = 0;
    }
  }
  return is_concurrency_allowed & 1;
}
