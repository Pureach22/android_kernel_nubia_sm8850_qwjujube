__int64 __fastcall wlan_hdd_vendor_scan_random_attr(
        __int64 a1,
        _BYTE *a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  _WORD *v17; // x10
  _WORD *v18; // x11
  char v19; // w10
  char v20; // w11
  char v21; // w12
  char v22; // w9
  char v23; // w13
  char v24; // w10
  char v25; // w11
  char v26; // w9
  char v27; // w12
  char v28; // w10
  char v29; // w11
  char v30; // w9
  char v31; // w13
  __int64 v32; // [xsp+8h] [xbp-18h]

  if ( (a2[36] & 8) == 0 )
    return 0;
  v32 = v13;
  if ( (*(_BYTE *)(a1 + 111) & 0x20) == 0 || hdd_cm_is_vdev_connected(*(_DWORD **)(a3 + 52832)) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: SCAN RANDOMIZATION not supported",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_hdd_vendor_scan_random_attr",
      v12,
      v32);
    return 4294967201LL;
  }
  v17 = *(_WORD **)(a4 + 72);
  v18 = *(_WORD **)(a4 + 80);
  if ( v17 )
  {
    if ( v18 )
    {
      if ( *v17 == 10 && *v18 == 10 )
      {
        qdf_mem_copy(a2 + 72, v17 + 2, 6u);
        qdf_mem_copy(a2 + 78, (const void *)(*(_QWORD *)(a4 + 80) + 4LL), 6u);
        if ( (a2[78] & 1) != 0 && (a2[72] & 1) == 0 )
        {
          v19 = a2[79];
          v20 = a2[73];
          v21 = a2[80];
          a2[72] &= a2[78];
          v22 = a2[74];
          v23 = a2[81];
          v24 = v20 & v19;
          v25 = a2[75];
          a2[73] = v24;
          v26 = v22 & v21;
          v27 = a2[76];
          v28 = v25 & v23;
          v29 = a2[82];
          a2[74] = v26;
          v30 = a2[83];
          v31 = a2[77];
          a2[75] = v28;
          a2[76] = v27 & v29;
          a2[77] = v31 & v30;
          return 0;
        }
      }
    }
  }
  else if ( !v18 )
  {
    qdf_mem_set(a2 + 72, 6u, 0);
    qdf_mem_set(a2 + 78, 6u, 0);
    a2[72] = 2;
    a2[78] = 3;
    return 0;
  }
  return 4294967274LL;
}
