__int64 __fastcall wlan_mlo_peer_get_primary_link_vdev(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 v19; // x20
  int ref; // w21
  __int64 result; // x0
  const char *v22; // x20

  if ( !a1 )
  {
    v22 = "%s: ml_peer is null";
    goto LABEL_15;
  }
  qdf_mutex_acquire(a1 + 120);
  if ( *(_DWORD *)(a1 + 200) > 1u )
  {
    v22 = "%s: ml_peer is not created and association is not done";
LABEL_14:
    qdf_mutex_release(a1 + 120);
    goto LABEL_15;
  }
  v18 = *(_QWORD *)(a1 + 16);
  if ( !v18 || *(_BYTE *)(a1 + 31) != 1 )
  {
    v18 = *(_QWORD *)(a1 + 56);
    if ( !v18 || (*(_BYTE *)(a1 + 71) & 1) == 0 )
    {
      v22 = "%s: None of the peer is designated as primary";
      goto LABEL_14;
    }
  }
  v19 = *(_QWORD *)(v18 + 96);
  if ( !v19 )
  {
    v22 = "%s: link vdev not found";
    goto LABEL_14;
  }
  ref = wlan_objmgr_vdev_try_get_ref(*(_QWORD *)(v18 + 96), 0x5Au, v10, v11, v12, v13, v14, v15, v16, v17);
  qdf_mutex_release(a1 + 120);
  result = v19;
  if ( !ref )
    return result;
  v22 = "%s: taking ref failed";
LABEL_15:
  qdf_trace_msg(0x8Fu, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlo_peer_get_primary_link_vdev");
  return 0;
}
