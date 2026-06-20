__int64 __fastcall scm_get_mld_addr_by_link_addr(__int64 a1, unsigned __int8 *a2, void *a3)
{
  __int64 entry_by_bssid; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 result; // x0
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  __int64 v22; // x0
  __int64 v23; // x0

  _ReadStatusReg(SP_EL0);
  entry_by_bssid = scm_scan_get_entry_by_bssid();
  if ( !entry_by_bssid )
  {
    if ( a2 )
    {
      v18 = *a2;
      v19 = a2[1];
      v20 = a2[2];
      v21 = a2[5];
    }
    else
    {
      v20 = 0;
      v18 = 0;
      v19 = 0;
      v21 = 0;
    }
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: scan entry not found for link addr: %02x:%02x:%02x:**:**:%02x",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "scm_get_mld_addr_by_link_addr",
      v18,
      v19,
      v20,
      v21);
LABEL_17:
    result = 16;
    goto LABEL_18;
  }
  v14 = entry_by_bssid;
  if ( !(*(_DWORD *)(entry_by_bssid + 1912) | *(unsigned __int16 *)(entry_by_bssid + 1916)) )
  {
    v22 = *(_QWORD *)(entry_by_bssid + 1320);
    if ( v22 )
      _qdf_mem_free(v22);
    v23 = *(_QWORD *)(v14 + 1896);
    if ( v23 )
      _qdf_mem_free(v23);
    _qdf_mem_free(v14);
    goto LABEL_17;
  }
  qdf_mem_copy(a3, (const void *)(entry_by_bssid + 1912), 6u);
  v15 = *(_QWORD *)(v14 + 1320);
  if ( v15 )
    _qdf_mem_free(v15);
  v16 = *(_QWORD *)(v14 + 1896);
  if ( v16 )
    _qdf_mem_free(v16);
  _qdf_mem_free(v14);
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
