__int64 __fastcall if_mgr_enable_roaming_on_vdev(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w21
  unsigned int v5; // w20
  __int64 v8; // x22
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x10
  unsigned int *v18; // x8
  __int64 v19; // x9
  __int64 v20; // x23
  __int64 assoc_link_vdev; // x24
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  unsigned int *v32; // x22

  v3 = *(_QWORD *)(result + 80);
  if ( v3 )
  {
    if ( !*(_DWORD *)(a2 + 16) && (*(_BYTE *)(a2 + 60) & 2) == 0 )
    {
      v4 = *(unsigned __int8 *)(a3 + 4);
      v5 = *(unsigned __int8 *)(a2 + 168);
      v8 = result;
      result = (__int64)wlan_objmgr_get_vdev_by_id_from_pdev(result, v4, 0x4Eu);
      v17 = a2;
      v18 = (unsigned int *)a3;
      v19 = v8;
      if ( !result
        || (v20 = result,
            assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(result),
            result = wlan_objmgr_vdev_release_ref(v20, 0x4Eu, v22, v23, v24, v25, v26, v27, v28, v29, v30),
            v17 = a2,
            v18 = (unsigned int *)a3,
            v19 = v8,
            assoc_link_vdev != a2) )
      {
        if ( v4 != v5 && *(_DWORD *)(v17 + 20) == 3 )
        {
          v31 = v19;
          v32 = v18;
          qdf_trace_msg(
            0x78u,
            8u,
            "%s: Enable roaming for vdev_id %d, requestor %d",
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            "if_mgr_enable_roaming_on_vdev",
            v5,
            *v18);
          mlme_set_rso_pending_disable_req_bitmap(v3, v5, *v32, 1);
          return wlan_cm_enable_rso(v31, v5, *v32, 43);
        }
      }
    }
  }
  return result;
}
