__int64 __fastcall hdd_set_features(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  if ( (unsigned int)_osif_vdev_sync_op_start(a1, v22, "hdd_set_features") )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: VDEV in transition, ignore set_features",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_set_features");
  }
  else
  {
    context = _cds_get_context(71, (__int64)"__hdd_set_features", v4, v5, v6, v7, v8, v9, v10, v11);
    if ( (*(_BYTE *)(a1 + 55153) & 1) != 0 )
    {
      if ( context )
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: vdev mode %d vdev_id %d current features 0x%llx, changed features 0x%llx",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "__hdd_set_features",
          *(unsigned int *)(a1 + 2728),
          *(unsigned __int8 *)(*(_QWORD *)(a1 + 55512) + 8LL),
          *(_QWORD *)(a1 + 184),
          a2);
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Not triggered by hdd_netdev_update_features",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "__hdd_set_features");
    }
    _osif_vdev_sync_op_stop(v22[0], "hdd_set_features");
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
