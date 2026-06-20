__int64 __fastcall init_deinit_populate_dbs_or_sbs_cap_ext2(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int ready; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19
  __int64 result; // x0
  __int64 v15; // x8
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  ready = wmi_extract_dbs_or_sbs_cap_service_ready_ext2(a2, a3, &v16);
  if ( ready )
  {
    v13 = ready;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Extraction of twt capability failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "init_deinit_populate_dbs_or_sbs_cap_ext2");
    ready = v13;
  }
  else if ( a1 )
  {
    v15 = *(_QWORD *)(a1 + 2800);
    if ( v15 )
      *(_DWORD *)(v15 + 4492) = v16;
  }
  result = qdf_status_to_os_return(ready);
  _ReadStatusReg(SP_EL0);
  return result;
}
