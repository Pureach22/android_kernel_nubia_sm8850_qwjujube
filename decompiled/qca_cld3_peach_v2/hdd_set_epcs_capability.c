__int64 __fastcall hdd_set_epcs_capability(__int64 a1, __int64 a2)
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
  const char *v14; // x4
  unsigned int v15; // w20

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_set_epcs_capability");
  if ( vdev_by_user )
  {
    v12 = *(unsigned __int8 *)(a2 + 4);
    v13 = vdev_by_user;
    if ( v12 )
      v14 = "Enable";
    else
      v14 = "Disable";
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Configure EPCS capability %s(%d)",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_set_epcs_capability",
      v14,
      v12);
    if ( v12 <= 1 )
    {
      ucfg_epcs_set_config(v13, v12);
      v15 = 0;
    }
    else
    {
      v15 = -22;
    }
    _hdd_objmgr_put_vdev_by_user(v13, 6, "hdd_set_epcs_capability");
  }
  else
  {
    return (unsigned int)-22;
  }
  return v15;
}
