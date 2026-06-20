__int64 __fastcall ucfg_cfr_stop_capture(__int64 a1, __int64 a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  __int64 v14; // x0
  __int64 v15; // x22
  __int64 result; // x0
  const char *v17; // x2

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !comp_private_obj )
  {
    v17 = "%s: PDEV cfr object is NULL!";
LABEL_12:
    qdf_trace_msg(0x6Au, 2u, v17, v5, v6, v7, v8, v9, v10, v11, v12, "ucfg_cfr_stop_capture");
    return 4294967274LL;
  }
  if ( !*(_BYTE *)(comp_private_obj + 8) )
  {
    v17 = "%s: cfr is not supported on this chip";
    goto LABEL_12;
  }
  v13 = comp_private_obj;
  v14 = wlan_objmgr_peer_get_comp_private_obj(a2, 0x1Eu);
  if ( !v14 )
  {
    v17 = "%s: PEER cfr object is NULL!";
    goto LABEL_12;
  }
  if ( !*(_DWORD *)(v14 + 12) || !*(_BYTE *)(v14 + 8) )
  {
    v17 = "%s: periodic cfr not started for the client";
    goto LABEL_12;
  }
  v15 = v14;
  result = tgt_cfr_stop_capture(a1, a2, v5, v6, v7, v8, v9, v10, v11, v12);
  if ( !(_DWORD)result )
  {
    *(_BYTE *)(v15 + 8) = 0;
    --*(_WORD *)(v13 + 42);
  }
  return result;
}
