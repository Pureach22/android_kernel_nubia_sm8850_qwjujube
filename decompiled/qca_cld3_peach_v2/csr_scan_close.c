__int64 __fastcall csr_scan_close(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  _DWORD *comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  csr_ll_lock(a1 + 17008);
  while ( 1 )
  {
    v2 = csr_ll_remove_head(a1 + 17008, 0);
    if ( !v2 )
      break;
    _qdf_mem_free(v2);
  }
  csr_ll_unlock(a1 + 17008);
  csr_ll_lock(a1 + 17096);
  while ( 1 )
  {
    v3 = csr_ll_remove_head(a1 + 17096, 0);
    if ( !v3 )
      break;
    _qdf_mem_free(v3);
  }
  csr_ll_unlock(a1 + 17096);
  csr_ll_close(a1 + 17008);
  csr_ll_close(a1 + 17096);
  comp_private_obj = (_DWORD *)wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 21624), 3u);
  if ( comp_private_obj )
  {
    *comp_private_obj |= 2u;
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: Psoc scan_disabled %x",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_scan_psoc_set_disable");
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_psoc_set_disable",
      919);
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: Failed to get scan object",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_scan_psoc_set_disable");
  }
  return 0;
}
