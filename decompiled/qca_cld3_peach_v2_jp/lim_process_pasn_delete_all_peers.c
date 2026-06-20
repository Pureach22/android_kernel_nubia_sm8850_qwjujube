__int64 __fastcall lim_process_pasn_delete_all_peers(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x20
  unsigned int *v5; // x8
  unsigned int v6; // w19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  v3 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 21552),
         *(unsigned __int8 *)(a2 + 4),
         13);
  if ( v3 )
  {
    v4 = v3;
    v6 = wma_delete_all_pasn_peers();
    if ( v6 )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to delete all PASN peers for vdev:%d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "lim_process_pasn_delete_all_peers",
        *(unsigned __int8 *)(a2 + 4));
    wlan_objmgr_vdev_release_ref(v4, 0xDu, v5, v7, v8, v9, v10, v11, v12, v13, v14);
  }
  else
  {
    return 4;
  }
  return v6;
}
