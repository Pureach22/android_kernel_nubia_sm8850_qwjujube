bool __fastcall scm_scan_entries_contain_cmn_akm(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x10
  __int64 v11; // x9
  _BOOL4 v12; // w8
  unsigned int v13; // w19
  int secure_akm_available; // w0
  const char *v17; // x2
  int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v10 = *(_QWORD *)(a1 + 1288);
  v11 = *(_QWORD *)(a2 + 1288);
  v12 = (v10 | v11) == 0;
  if ( !v10 || !v11 )
    return v12;
  if ( *(unsigned __int8 *)(a1 + 1158) != *(unsigned __int8 *)(a2 + 1158) )
  {
    v17 = "%s: RSN generation mismatch %x %x";
LABEL_19:
    qdf_trace_msg(0x15u, 8u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "scm_scan_entries_contain_cmn_akm");
    return 0;
  }
  if ( ((*(unsigned __int16 *)(a2 + 1156) ^ *(unsigned __int16 *)(a1 + 1156)) & 0x80) != 0 )
  {
    v17 = "%s: MFPC capability is not equal 0x%x, 0x%x";
    goto LABEL_19;
  }
  if ( (*(_DWORD *)(a2 + 1144) & *(_DWORD *)(a1 + 1144)) == 0 )
  {
    v17 = "%s: Intersected UC cipher bitmap NULL 0x%x, 0x%x";
    goto LABEL_19;
  }
  if ( (*(_DWORD *)(a2 + 1148) & *(_DWORD *)(a1 + 1148)) == 0 )
  {
    v17 = "%s: Intersected MC cipher bitmap NULL 0x%x, 0x%x";
    goto LABEL_19;
  }
  v13 = *(_DWORD *)(a1 + 1140);
  secure_akm_available = wlan_crypto_get_secure_akm_available(v13);
  if ( secure_akm_available == 30 )
  {
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: No matching AKM 0x%x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "scm_scan_entries_contain_cmn_akm",
      v13);
    return 0;
  }
  if ( (*(_DWORD *)(a2 + 1140) & (1 << secure_akm_available)) == 0 )
  {
    v17 = "%s: Intersected AKM bitmap NULL 0x%x, 0x%x";
    goto LABEL_19;
  }
  if ( ((1 << secure_akm_available) & 0x18000C00) != 0 )
  {
    v18 = util_scan_entry_sae_h2e_capable(a1) & 1;
    if ( v18 != (util_scan_entry_sae_h2e_capable(a2) & 1) )
    {
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: SAE-H2E capability mismatch",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "scm_scan_entries_contain_cmn_akm");
      return 0;
    }
  }
  return 1;
}
