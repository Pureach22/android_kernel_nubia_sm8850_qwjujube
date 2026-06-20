__int64 __fastcall policy_mgr_vdev_is_force_inactive(__int64 a1, char a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  unsigned int v13; // w20
  unsigned int v14; // w9

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = context;
    qdf_mutex_acquire(context + 56);
    if ( pm_disabled_ml_links[0] == 1 && !dword_8D4FC4 && byte_8D4FCC == a2 )
    {
      v13 = 1;
    }
    else
    {
      if ( dword_8D4FD4 )
        v14 = 0;
      else
        v14 = (unsigned __int8)byte_8D4FD0;
      if ( byte_8D4FDC == a2 )
        v13 = v14;
      else
        v13 = 0;
    }
    qdf_mutex_release(v12 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_vdev_is_force_inactive");
    return 0;
  }
  return v13;
}
