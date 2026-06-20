__int64 __fastcall wlan_mlo_link_peer_delete(
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
  __int64 v9; // x19
  __int64 v10; // x8
  __int64 v12; // x8
  __int64 v13; // x2
  int v14; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v39; // w8
  unsigned int v40; // w8

  v9 = *(_QWORD *)(a1 + 784);
  if ( !v9 )
    return 17;
  v10 = *(_QWORD *)(a1 + 96);
  if ( v10 && (v12 = *(_QWORD *)(v10 + 216)) != 0 )
    v13 = *(_QWORD *)(v12 + 80);
  else
    v13 = 0;
  wlan_minidump_remove(a2, a3, a4, a5, a6, a7, a8, a9, *(_QWORD *)(a1 + 784), 904, v13);
  qdf_mutex_acquire(v9 + 120);
  v14 = *(_DWORD *)(a1 + 64);
  *(_QWORD *)(a1 + 784) = 0;
  *(_DWORD *)(a1 + 64) = v14 & 0xFFFFFFFE;
  qdf_mutex_release(v9 + 120);
  mlo_peer_detach_link_peer(v9, a1);
  _X9 = (unsigned int *)(v9 + 188);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v39 = __ldxr(_X9);
    v40 = v39 - 1;
  }
  while ( __stlxr(v40, _X9) );
  __dmb(0xBu);
  if ( !v40 )
  {
    v23 = *(_QWORD *)(v9 + 192);
    if ( v23 )
    {
      mlo_dev_mlpeer_detach(v23, v9);
      mlo_peer_free(v9, v24, v25, v26, v27, v28, v29, v30, v31);
    }
    else
    {
      qdf_trace_msg(0x8Fu, 2u, "%s: ML DEV is NULL", v15, v16, v17, v18, v19, v20, v21, v22, "mlo_peer_cleanup");
    }
  }
  return 0;
}
