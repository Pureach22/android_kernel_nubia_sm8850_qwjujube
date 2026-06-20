__int64 __fastcall csr_scan_filter_results(__int64 a1)
{
  __int64 v2; // x22
  __int64 pdev_by_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  unsigned int v13; // w21
  __int64 v14; // x22
  __int64 v15; // x23
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  _DWORD s[100]; // [xsp+8h] [xbp-198h] BYREF
  __int64 v35; // [xsp+198h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(*(_QWORD *)(a1 + 8) + 6392LL);
  memset(s, 0, sizeof(s));
  pdev_by_id = wlan_objmgr_get_pdev_by_id(*(_QWORD *)(a1 + 21624), 0, 7u);
  if ( pdev_by_id )
  {
    v12 = pdev_by_id;
    v13 = 0;
    if ( (_DWORD)v2 )
    {
      v14 = -v2;
      v15 = 1498;
      while ( v15 != 1598 )
      {
        if ( (wlan_reg_is_dsrc_freq() & 1) == 0 )
        {
          if ( v13 > 0x63 )
            break;
          s[v13++] = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4 * v15);
        }
        ++v15;
        if ( v14 + v15 == 1498 )
          goto LABEL_9;
      }
      __break(0x5512u);
    }
LABEL_9:
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: No of valid channel %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "csr_scan_filter_results",
      v13);
    ucfg_scan_filter_valid_channel(v12, (__int64)s, v13, v16, v17, v18, v19, v20, v21, v22, v23);
    wlan_objmgr_pdev_release_ref(v12, 7u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
    result = 0;
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: pdev is NULL", v4, v5, v6, v7, v8, v9, v10, v11, "csr_scan_filter_results");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
