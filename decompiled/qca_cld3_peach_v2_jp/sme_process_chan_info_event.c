__int64 __fastcall sme_process_chan_info_event(
        __int64 a1,
        _DWORD *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w22
  __int64 result; // x0
  __int64 v26; // x1
  __int64 v27; // x19

  if ( !a2 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Chan info report is NULL\n",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "sme_process_chan_info_event");
  wlan_cp_stats_update_chan_info(*(_QWORD *)(a1 + 21552));
  v14 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21552),
          a3,
          11);
  if ( !v14 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: vdev not found for vdev %d",
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             "sme_indicate_chan_info_event",
             (unsigned __int8)a3);
  v24 = *(_DWORD *)(v14 + 16);
  result = wlan_objmgr_vdev_release_ref(v14, 0xBu, v15, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( v24 == 1 )
  {
    result = _qdf_mem_malloc(0x180u, "sme_indicate_chan_info_event", 2663);
    if ( result )
    {
      v26 = (unsigned __int8)a3;
      v27 = result;
      *(_DWORD *)(result + 360) = *a2;
      csr_roam_call_callback(a1, v26, result, 50, 0);
      return _qdf_mem_free(v27);
    }
  }
  return result;
}
