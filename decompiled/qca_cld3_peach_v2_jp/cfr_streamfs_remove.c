__int64 __fastcall cfr_streamfs_remove(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 comp_private_obj; // x0
  __int64 v12; // x8

  if ( (wlan_cfr_is_feature_disabled(a1) & 1) != 0 )
  {
    qdf_trace_msg(0x6Au, 4u, "%s: cfr is disabled", v2, v3, v4, v5, v6, v7, v8, v9, "cfr_streamfs_remove");
    return 39;
  }
  else
  {
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
    if ( comp_private_obj )
    {
      v12 = comp_private_obj;
      if ( *(_QWORD *)(comp_private_obj + 56) )
        *(_QWORD *)(comp_private_obj + 56) = 0;
      if ( *(_QWORD *)(comp_private_obj + 64) )
      {
        *(_QWORD *)(v12 + 64) = 0;
        return 0;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 16;
    }
  }
}
