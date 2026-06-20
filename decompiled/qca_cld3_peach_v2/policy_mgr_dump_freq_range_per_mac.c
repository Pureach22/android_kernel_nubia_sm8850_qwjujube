_DWORD *__fastcall policy_mgr_dump_freq_range_per_mac(
        _DWORD *result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *v10; // x20
  const char *v12; // x3
  const char *v13; // x3
  __int64 v14; // [xsp+0h] [xbp-10h]
  int v15; // [xsp+0h] [xbp-10h]
  __int64 v16; // [xsp+8h] [xbp-8h]
  int v17; // [xsp+8h] [xbp-8h]

  v10 = result;
  if ( *result || result[2] )
  {
    if ( a2 <= 7 )
      v12 = off_AD9200[a2];
    else
      v12 = "Unknown";
    v17 = result[3];
    v15 = result[2];
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10,
                         v12,
                         a2,
                         0,
                         v15,
                         v17);
  }
  if ( v10[4] || v10[6] )
  {
    if ( a2 <= 7 )
      v13 = off_AD9200[a2];
    else
      v13 = "Unknown";
    LODWORD(v16) = v10[7];
    LODWORD(v14) = v10[6];
    return (_DWORD *)qdf_trace_msg(
                       0x4Fu,
                       8u,
                       "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       v13,
                       a2,
                       1,
                       v14,
                       v16);
  }
  return result;
}
