__int64 __fastcall hdd_trigger_epcs_function(__int64 a1, __int64 a2)
{
  __int64 vdev_by_user; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  __int64 v13; // x19
  __int64 v14; // x1
  unsigned int v15; // w20

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_trigger_epcs_function");
  if ( vdev_by_user )
  {
    v12 = *(unsigned __int8 *)(a2 + 4);
    v13 = vdev_by_user;
    qdf_trace_msg(0x33u, 8u, "%s: Trigger EPCS %d", v4, v5, v6, v7, v8, v9, v10, v11, "hdd_trigger_epcs_function", v12);
    if ( v12 == 1 )
    {
      v14 = 2;
    }
    else
    {
      if ( v12 )
      {
        v15 = -22;
        goto LABEL_9;
      }
      v14 = 5;
    }
    ucfg_epcs_deliver_cmd(v13, v14);
    v15 = 0;
LABEL_9:
    _hdd_objmgr_put_vdev_by_user(v13, 6, "hdd_trigger_epcs_function");
    return v15;
  }
  return (unsigned int)-22;
}
