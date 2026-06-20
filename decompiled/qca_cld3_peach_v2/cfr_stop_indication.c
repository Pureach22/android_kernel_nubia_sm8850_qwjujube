__int64 __fastcall cfr_stop_indication(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v11; // w19

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(*(_QWORD *)(a1 + 216), 0x1Eu);
  if ( comp_private_obj )
  {
    if ( *(_QWORD *)(comp_private_obj + 1696) )
    {
      return 0;
    }
    else
    {
      v11 = 16 * (*(_QWORD *)(comp_private_obj + 56) == 0);
      qdf_trace_msg(0x6Au, 8u, "%s: stop indication done", v2, v3, v4, v5, v6, v7, v8, v9, "cfr_stop_indication");
      return v11;
    }
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: pdev_cfr is NULL\n", v2, v3, v4, v5, v6, v7, v8, v9, "cfr_stop_indication");
    return 4;
  }
}
