__int64 __fastcall target_if_dbr_buf_release(
        __int64 a1,
        unsigned __int8 a2,
        __int64 a3,
        unsigned int a4,
        unsigned __int8 a5)
{
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x1
  __int64 v20; // x8
  __int64 v21; // x5
  __int64 v22; // x2
  __int64 result; // x0
  const char *v24; // x2

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 8u);
  if ( !comp_private_obj )
  {
    v24 = "%s: dir buf rx object is null";
LABEL_11:
    qdf_trace_msg(0x5Bu, 2u, v24, v11, v12, v13, v14, v15, v16, v17, v18, "target_if_dbr_buf_release");
    return 16;
  }
  if ( a5 >= 3u )
  {
    __break(0x5512u);
    return ((__int64 (*)(void))target_if_dbr_replenish_ring)();
  }
  v19 = *(_QWORD *)(comp_private_obj + 8) + 112LL * a2 + 56LL * a5;
  if ( !v19 )
  {
    v24 = "%s: dir buf rx module param is null";
    goto LABEL_11;
  }
  if ( **(_DWORD **)(v19 + 24) <= a4 )
  {
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: invalid cookie %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "target_if_dbr_vaddr_lookup",
      a4);
    return 16;
  }
  v20 = *(_QWORD *)(v19 + 32) + 32LL * a4;
  v21 = *(_QWORD *)(v20 + 8);
  if ( v21 != a3 )
  {
    qdf_trace_msg(
      0x5Bu,
      8u,
      "%s: Invalid paddr, cookie %d, pool paddr %pK, paddr %pK",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "target_if_dbr_vaddr_lookup",
      a4,
      v21,
      a3);
    return 16;
  }
  v22 = *(_QWORD *)(v20 + 16) + *(unsigned __int8 *)(v20 + 24);
  if ( v22 )
  {
    result = target_if_dbr_replenish_ring(a1, v19, v22, a4);
    if ( !(_DWORD)result )
      return result;
    v24 = "%s: Ring replenish failed";
    goto LABEL_11;
  }
  return 16;
}
