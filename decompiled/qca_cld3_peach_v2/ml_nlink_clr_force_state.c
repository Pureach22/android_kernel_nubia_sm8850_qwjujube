__int64 __fastcall ml_nlink_clr_force_state(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  int v13; // [xsp+0h] [xbp-20h]
  int v14; // [xsp+8h] [xbp-18h]
  int v15; // [xsp+10h] [xbp-10h]

  v2 = *(_QWORD *)(a2 + 1360);
  if ( v2 )
  {
    if ( *(_QWORD *)(v2 + 2224) )
    {
      qdf_mutex_acquire(v2 + 1656);
      v3 = *(_QWORD *)(v2 + 2224);
      qdf_mem_set((void *)(v3 + 1348), 0x12u, 0);
      v14 = *(unsigned __int16 *)(v3 + 1354);
      v15 = *(unsigned __int16 *)(v3 + 1360);
      v13 = *(unsigned __int8 *)(v3 + 1352);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%x",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "ml_nlink_clr_force_state",
        *(unsigned __int16 *)(v3 + 1350),
        *(unsigned __int16 *)(v3 + 1348),
        *(unsigned __int8 *)(v3 + 1356),
        *(unsigned __int16 *)(v3 + 1358),
        v13,
        v14,
        v15);
      qdf_mem_set((void *)(*(_QWORD *)(v2 + 2224) + 1368LL), 0x50u, 0);
      return qdf_mutex_release(v2 + 1656);
    }
  }
  return result;
}
