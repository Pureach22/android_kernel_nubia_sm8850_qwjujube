__int64 __fastcall wlan_mlo_peer_free_aid(__int64 a1, unsigned __int8 a2, __int16 a3)
{
  __int64 mlo_ctx; // x0
  __int64 v7; // x19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w8
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x11
  __int64 v20; // x10
  __int64 v21; // x12
  __int64 v22; // x11
  __int64 v23; // x12
  __int64 v25; // x10

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
    return 16;
  v7 = mlo_ctx;
  qdf_mutex_acquire(mlo_ctx + 64);
  v16 = (a3 & 0x3FFF) - 1;
  if ( ((*(_QWORD *)(a1 + ((v16 >> 3) & 0x1FF8LL)) >> ((unsigned __int8)a3 - 1)) & 1) != 0 )
  {
    v17 = (unsigned __int16)v16 >> 6;
    v18 = 1LL << ((unsigned __int8)a3 - 1);
    *(_QWORD *)(a1 + 8 * v17) &= ~v18;
    v19 = *(_QWORD *)(a1 + 264);
    v20 = ~v18;
    if ( v19 )
    {
      v21 = *(_QWORD *)(v19 + 8 * v17);
      if ( (v21 & v18) != 0 )
        *(_QWORD *)(v19 + 8 * v17) = v21 & v20;
    }
    v22 = *(_QWORD *)(a1 + 272);
    if ( v22 )
    {
      v23 = *(_QWORD *)(v22 + 8 * v17);
      if ( (v23 & v18) != 0 )
        *(_QWORD *)(v22 + 8 * v17) = v23 & v20;
    }
  }
  else if ( a2 > 1u )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: AID free failed, link ix(%d) is invalid for assoc_id %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_mlo_peer_free_aid");
  }
  else
  {
    v25 = *(_QWORD *)(a1 + 8LL * a2 + 264);
    if ( v25 )
      *(_QWORD *)(v25 + ((v16 >> 3) & 0x1FF8LL)) &= ~(1LL << ((unsigned __int8)a3 - 1));
  }
  qdf_mutex_release(v7 + 64);
  return 0;
}
