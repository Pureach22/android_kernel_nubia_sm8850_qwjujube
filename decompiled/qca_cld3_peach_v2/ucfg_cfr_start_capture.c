__int64 __fastcall ucfg_cfr_start_capture(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  __int64 v16; // x0
  __int64 v17; // x22
  __int64 v18; // x0
  __int64 v19; // x8
  int v20; // w9
  const char *v21; // x2
  __int64 result; // x0
  __int64 v23; // x19
  char v24; // w8

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !comp_private_obj )
  {
    v21 = "%s: PDEV cfr object is NULL!";
    goto LABEL_15;
  }
  if ( !*(_BYTE *)(comp_private_obj + 8) )
  {
    v21 = "%s: cfr is not supported on this chip";
    goto LABEL_15;
  }
  v15 = comp_private_obj;
  v16 = wlan_objmgr_peer_get_comp_private_obj(a2, 0x1Eu);
  if ( !v16 )
  {
    v21 = "%s: PEER cfr object is NULL!";
    goto LABEL_15;
  }
  v17 = v16;
  v18 = *(_QWORD *)(a1 + 80);
  if ( !v18 )
  {
    v21 = "%s: psoc is null!";
    goto LABEL_15;
  }
  if ( !(unsigned int)tgt_cfr_validate_period(v18, *(_DWORD *)(a3 + 4), v7, v8, v9, v10, v11, v12, v13, v14) )
    return 4294967274LL;
  v19 = v15;
  if ( *(_DWORD *)(a3 + 4) )
  {
    if ( *(_BYTE *)(v15 + 9)
      || (qdf_trace_msg(
            0x6Au,
            2u,
            "%s: Global periodic timer is not enabled, configure global cfr timer",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "ucfg_cfr_start_capture"),
          v19 = v15,
          *(_DWORD *)(a3 + 4)) )
    {
      v20 = *(unsigned __int16 *)(v19 + 42);
      if ( v20 == *(unsigned __int16 *)(v19 + 40) )
      {
        v21 = "%s: max periodic cfr clients reached";
LABEL_15:
        qdf_trace_msg(0x6Au, 2u, v21, v7, v8, v9, v10, v11, v12, v13, v14, "ucfg_cfr_start_capture");
        return 4294967274LL;
      }
      if ( !*(_BYTE *)(v17 + 8) )
        *(_WORD *)(v19 + 42) = v20 + 1;
    }
  }
  else if ( *(_BYTE *)(v15 + 9) )
  {
    v21 = "%s: Single shot capture is not allowed during periodic capture";
    goto LABEL_15;
  }
  if ( *(_BYTE *)(v19 + 1385) && (*(_BYTE *)(v19 + 176) & 0x3F) != 0 )
  {
    v23 = v19;
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: This is not allowed since RCC is enabled",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "ucfg_cfr_start_capture");
    *(_BYTE *)(v23 + 9) = 0;
    return 4294967274LL;
  }
  result = tgt_cfr_start_capture(a1, a2, a3, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( (_DWORD)result )
  {
    --*(_WORD *)(v15 + 42);
  }
  else
  {
    *(_BYTE *)(v17 + 9) = *(_BYTE *)a3;
    *(_DWORD *)(v17 + 12) = *(_DWORD *)(a3 + 4);
    v24 = *(_BYTE *)(a3 + 8);
    *(_BYTE *)(v17 + 8) = 1;
    *(_BYTE *)(v17 + 16) = v24;
  }
  return result;
}
