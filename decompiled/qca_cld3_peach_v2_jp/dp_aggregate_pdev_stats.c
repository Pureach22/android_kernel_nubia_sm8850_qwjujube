__int64 __fastcall dp_aggregate_pdev_stats(_QWORD *a1)
{
  void *v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x21
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  void (__fastcall *v24)(_QWORD); // x8
  unsigned __int64 StatusReg; // x8
  __int64 i; // x21
  __int64 v28; // x8

  v2 = qdf_mem_malloc_atomic_fl(0xA428u, (__int64)"dp_aggregate_pdev_stats", 0x1F17u);
  v11 = a1[1];
  if ( !v2 )
    return qdf_trace_msg(
             0x89u,
             2u,
             "%s: %pK: DP alloc failure - unable to get alloc vdev stats",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "dp_aggregate_pdev_stats",
             a1[1]);
  v12 = (__int64)v2;
  qdf_mem_set(a1 + 374, 0x8F8u, 0);
  qdf_mem_set(a1 + 661, 0x590u, 0);
  qdf_mem_set(a1 + 65, 0x978u, 0);
  qdf_mem_set(a1 + 368, 0x30u, 0);
  if ( a1 )
  {
    v21 = a1[11945];
    if ( v21 )
    {
      if ( *(_DWORD *)(v21 + 39100) )
      {
        v22 = *(_QWORD *)(v11 + 20056);
        if ( v22 )
        {
          v23 = *(_QWORD *)(v22 + 416);
          if ( !v23 || (v24 = *(void (__fastcall **)(_QWORD))(v23 + 176)) == nullptr )
          {
            qdf_trace_msg(
              0x92u,
              8u,
              "%s: callback not registered",
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              "dp_monitor_invalid_peer_update_pdev_stats");
            if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
              goto LABEL_12;
LABEL_17:
            raw_spin_lock(a1 + 39);
            goto LABEL_18;
          }
          if ( *((_DWORD *)v24 - 1) != -1557217772 )
            __break(0x8228u);
          v24(a1);
        }
      }
    }
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    goto LABEL_17;
LABEL_12:
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    goto LABEL_17;
  raw_spin_lock_bh(a1 + 39);
  a1[40] |= 1uLL;
LABEL_18:
  for ( i = a1[37]; i; i = *(_QWORD *)(i + 104) )
  {
    dp_aggregate_vdev_stats(i, v12, 2u);
    dp_update_pdev_stats(a1, v12);
    dp_update_pdev_ingress_stats(a1, i);
  }
  v28 = a1[40];
  if ( (v28 & 1) != 0 )
  {
    a1[40] = v28 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 39);
  }
  else
  {
    raw_spin_unlock(a1 + 39);
  }
  return _qdf_mem_free(v12);
}
