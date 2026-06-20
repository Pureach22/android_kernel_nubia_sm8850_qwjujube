__int64 __fastcall mlo_ser_set_link_cb(__int64 a1, int a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x9
  __int64 v13; // x19
  __int64 v14; // x8
  unsigned int *v15; // x8
  __int64 v16; // x20
  __int64 result; // x0
  _DWORD *v18; // x8
  __int64 v19; // x1

  if ( !a1 || !*(_QWORD *)(a1 + 32) )
    return 16;
  if ( !wlan_objmgr_get_mlo_ctx() )
    return 16;
  v12 = a1;
  v13 = *(_QWORD *)(a1 + 32);
  v14 = *(_QWORD *)(v13 + 216);
  if ( !v14 || (v15 = *(unsigned int **)(v14 + 80)) == nullptr )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: psoc is NULL, reason: %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlo_ser_set_link_cb",
      (unsigned int)a2);
    return 29;
  }
  v16 = *(_QWORD *)(v12 + 40);
  if ( !v16 )
    return 4;
  result = 4;
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      wlan_objmgr_vdev_release_ref(v13, 0x5Au, v15, v4, v5, v6, v7, v8, v9, v10, v11);
      _qdf_mem_free(v16);
      return 0;
    }
    if ( a2 != 3 )
      return result;
LABEL_18:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: vdev %d command not execute: %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlo_ser_set_link_cb",
      *(unsigned __int8 *)(v13 + 168),
      (unsigned int)a2);
    v18 = *(_DWORD **)(v16 + 8);
    if ( v18 )
    {
      v19 = *(_QWORD *)(v16 + 24);
      if ( *(v18 - 1) != 662908326 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v18)(v13, v19, 0);
      return 0;
    }
    return 0;
  }
  if ( !a2 )
    return mlo_link_set_active(v15, *(_QWORD *)(v12 + 40));
  if ( a2 == 1 )
    goto LABEL_18;
  return result;
}
