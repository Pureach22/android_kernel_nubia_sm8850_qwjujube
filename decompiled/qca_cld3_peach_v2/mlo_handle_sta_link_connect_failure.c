__int64 __fastcall mlo_handle_sta_link_connect_failure(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x22
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v15; // x19
  __int64 v16; // x0
  _QWORD *v17; // x9
  __int64 v18; // x8
  __int64 v19; // x10
  unsigned __int64 v20; // x10
  const char *v21; // x2
  __int64 v22; // x9
  unsigned int v23; // w8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // [xsp+8h] [xbp-38h] BYREF
  __int64 v42; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v43)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v44)(); // [xsp+20h] [xbp-20h]
  __int64 v45; // [xsp+28h] [xbp-18h]
  __int64 v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 1360);
  v45 = 0;
  v46 = 0;
  v43 = nullptr;
  v44 = nullptr;
  v41 = 0;
  v42 = 0;
  if ( !v10 )
  {
    v21 = "%s: ML dev ctx is NULL";
    goto LABEL_18;
  }
  v12 = *(_QWORD *)(v10 + 24);
  if ( (!v12
     || (result = wlan_vdev_mlme_is_mlo_vdev(v12, a3, a4, a5, a6, a7, a8, a9, a10), (result & 1) == 0)
     || (v15 = *(_QWORD *)(v10 + 24), (*(_BYTE *)(v15 + 60) & 2) != 0))
    && ((v16 = *(_QWORD *)(v10 + 32)) == 0
     || (result = wlan_vdev_mlme_is_mlo_vdev(v16, a3, a4, a5, a6, a7, a8, a9, a10), (result & 1) == 0)
     || (v15 = *(_QWORD *)(v10 + 32), (*(_BYTE *)(v15 + 60) & 2) != 0))
    || !v15 )
  {
    v21 = "%s: Assoc Vdev is NULL";
LABEL_18:
    result = qdf_trace_msg(0x8Fu, 2u, v21, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_handle_sta_link_connect_failure");
    goto LABEL_19;
  }
  if ( v15 == a1 )
    goto LABEL_19;
  v17 = *(_QWORD **)(a1 + 1360);
  if ( v17 )
  {
    v18 = v17[278];
    if ( v18 )
    {
      v19 = v17[3];
      if ( v19 && v19 == a1 )
      {
        v20 = *(_QWORD *)(v18 + 8) & 0xFFFFFFFFFFFFFFFELL;
        *(_QWORD *)(v18 + 8) = v20;
        if ( v17[4] == a1 )
          goto LABEL_23;
      }
      else
      {
        v22 = v17[4];
        if ( v22 && v22 == a1 )
        {
          v20 = *(_QWORD *)(v18 + 8);
LABEL_23:
          *(_QWORD *)(v18 + 8) = v20 & 0xFFFFFFFFFFFFFFFDLL;
        }
      }
    }
  }
  v23 = *(_DWORD *)(a2 + 56);
  if ( v23 <= 0xC && ((1 << v23) & 0x1802) != 0 )
  {
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(v15, 0x5Au, a3, a4, a5, a6, a7, a8, a9, a10) )
    {
      result = qdf_trace_msg(
                 0x8Fu,
                 2u,
                 "%s: Failed to get ref vdev_id %d",
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 "mlo_handle_sta_link_connect_failure",
                 *(unsigned __int8 *)(v15 + 168));
    }
    else
    {
      v42 = v15;
      v43 = ml_activate_disconnect_req_sched_cb;
      v44 = ml_activate_disconnect_req_flush_cb;
      result = scheduler_post_message_debug(
                 0x48u,
                 0x15u,
                 72,
                 (unsigned __int16 *)&v41,
                 0x50Eu,
                 (__int64)"mlo_post_disconnect_msg");
      if ( (_DWORD)result )
        result = wlan_objmgr_vdev_release_ref(v15, 0x5Au, v32, v33, v34, v35, v36, v37, v38, v39, v40);
    }
  }
  else
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64))mlo_disconnect_req)(a1, 5, 1);
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
