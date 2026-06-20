__int64 __fastcall p2p_check_and_update_channel(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v9; // x2
  _QWORD *v11; // x20
  __int64 v13; // x0
  __int64 v14; // x19
  unsigned int v15; // w22
  __int64 current_roc_ctx; // x0
  unsigned __int64 v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  if ( !a1 || *(_DWORD *)(a1 + 44) )
  {
    v9 = "%s: NULL tx ctx or channel valid";
    return qdf_trace_msg(0x4Eu, 2u, v9, a2, a3, a4, a5, a6, a7, a8, a9, "p2p_check_and_update_channel");
  }
  v11 = *(_QWORD **)(a1 + 16);
  v13 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *v11,
          *(unsigned int *)(a1 + 24),
          15);
  if ( !v13 )
  {
    v9 = "%s: null vdev object";
    return qdf_trace_msg(0x4Eu, 2u, v9, a2, a3, a4, a5, a6, a7, a8, a9, "p2p_check_and_update_channel");
  }
  v14 = v13;
  v15 = *(_DWORD *)(v13 + 16);
  current_roc_ctx = p2p_find_current_roc_ctx(v11);
  if ( current_roc_ctx && v15 <= 7 )
  {
    v17 = (unsigned int)(1 << v15);
    if ( (v17 & 0x8C) != 0 )
    {
      v17 = *(unsigned int *)(current_roc_ctx + 40);
      *(_DWORD *)(a1 + 44) = v17;
    }
  }
  return wlan_objmgr_vdev_release_ref(v14, 0xFu, (unsigned int *)v17, v18, v19, v20, v21, v22, v23, v24, v25);
}
