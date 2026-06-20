__int64 __fastcall wma_resume_vdev_delete(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v2 = *(_QWORD *)(a1 + 16);
  v3 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 24),
         a2,
         8);
  if ( v3 )
  {
    v12 = v3;
    lim_pasn_peer_del_all_resp_vdev_delete_resume(v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    wlan_objmgr_vdev_release_ref(v12, 8u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: Vdev is NULL", v4, v5, v6, v7, v8, v9, v10, v11, "wma_resume_vdev_delete");
    return 29;
  }
}
