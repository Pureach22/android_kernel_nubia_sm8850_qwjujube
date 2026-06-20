__int64 __fastcall tgt_cfr_info_send(
        __int64 a1,
        const void *a2,
        __int64 a3,
        const void *a4,
        __int64 a5,
        const void *a6,
        __int64 a7)
{
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  unsigned int v23; // w25
  void *v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x26
  _DWORD *v34; // x8
  __int64 v35; // x1
  __int64 v36; // x0

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( comp_private_obj )
  {
    v22 = comp_private_obj;
    if ( *(_QWORD *)(comp_private_obj + 1696) )
    {
      v23 = a5 + a3 + a7;
      v24 = (void *)_qdf_mem_malloc(v23, "tgt_cfr_info_send", 49);
      if ( v24 )
      {
        v33 = (__int64)v24;
        if ( a3 )
          qdf_mem_copy(v24, a2, (unsigned int)a3);
        if ( a5 )
          qdf_mem_copy((void *)(v33 + a3), a4, (unsigned int)a5);
        if ( a7 )
          qdf_mem_copy((void *)(v33 + a3 + a5), a6, (unsigned int)a7);
        v34 = *(_DWORD **)(v22 + 1696);
        v35 = *(unsigned int *)(v22 + 1692);
        v36 = *(unsigned __int8 *)(v22 + 1688);
        if ( *(v34 - 1) != -847879029 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v34)(v36, v35, v33, v23);
        _qdf_mem_free(v33);
        return 0;
      }
      else
      {
        qdf_trace_msg(
          0x6Au,
          2u,
          "%s: failed to alloc memory, len %d, vdev_id %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "tgt_cfr_info_send",
          v23,
          *(unsigned __int8 *)(v22 + 1688));
        return 16;
      }
    }
    else
    {
      if ( a2 )
        cfr_streamfs_write(comp_private_obj);
      if ( a4 )
        cfr_streamfs_write(v22);
      if ( a6 )
        cfr_streamfs_write(v22);
      return cfr_streamfs_flush(v22);
    }
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: pdev_cfr is NULL\n", v14, v15, v16, v17, v18, v19, v20, v21, "tgt_cfr_info_send");
    return 0xFFFFFFFFLL;
  }
}
