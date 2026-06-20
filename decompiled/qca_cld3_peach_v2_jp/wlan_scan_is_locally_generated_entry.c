__int64 __fastcall wlan_scan_is_locally_generated_entry(__int64 a1, unsigned __int8 *a2)
{
  __int64 entry_by_bssid; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  char v12; // w21
  __int64 v13; // x19
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  unsigned int v18; // w20
  __int64 v19; // x0
  __int64 v20; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)a2 | *((unsigned __int16 *)a2 + 2) && (entry_by_bssid = scm_scan_get_entry_by_bssid(a1, a2)) != 0 )
  {
    v12 = *(_BYTE *)(entry_by_bssid + 50);
    v13 = entry_by_bssid;
    if ( (v12 & 1) != 0 )
    {
      if ( a2 )
      {
        v14 = *a2;
        v15 = a2[1];
        v16 = a2[2];
        v17 = a2[5];
      }
      else
      {
        v16 = 0;
        v14 = 0;
        v15 = 0;
        v17 = 0;
      }
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: %02x:%02x:%02x:**:**:%02x: Flushing the candidate scan entry",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "wlan_scan_is_locally_generated_entry",
        v14,
        v15,
        v16,
        v17);
    }
    v19 = *(_QWORD *)(v13 + 1192);
    if ( v19 )
      _qdf_mem_free(v19);
    v20 = *(_QWORD *)(v13 + 1712);
    v18 = v12 & 1;
    if ( v20 )
      _qdf_mem_free(v20);
    _qdf_mem_free(v13);
  }
  else
  {
    v18 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v18;
}
