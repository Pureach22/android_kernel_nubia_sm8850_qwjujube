__int64 __fastcall init_deinit_populate_sap_coex_capability(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int ready; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w19
  __int64 result; // x0
  __int64 v17; // x8
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  qdf_mem_set(&v18, 4u, 0);
  ready = wmi_extract_sap_coex_cap_service_ready_ext2(a2, a3, &v18);
  if ( ready )
  {
    v15 = ready;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Extraction of sap_coex_chan_pref cap failed",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "init_deinit_populate_sap_coex_capability");
    ready = v15;
  }
  else if ( a1 )
  {
    v17 = *(_QWORD *)(a1 + 2800);
    if ( v17 )
      *(_BYTE *)(v17 + 994) = *(_BYTE *)(v17 + 994) & 0xFD | (2 * (v18 != 0));
  }
  result = qdf_status_to_os_return(ready);
  _ReadStatusReg(SP_EL0);
  return result;
}
