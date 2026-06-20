__int64 __fastcall wlansap_get_max_bw_by_phymode(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w8

  if ( !result )
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid SAP pointer", a2, a3, a4, a5, a6, a7, a8, a9, "wlansap_get_max_bw_by_phymode");
    return 0;
  }
  v9 = *(_DWORD *)(result + 1484);
  if ( v9 > 511 )
  {
    if ( v9 != 512 && v9 != 4096 && v9 != 2048 )
      return 0;
LABEL_11:
    if ( (unsigned int)sme_get_vht_ch_width(result) < 2 )
      return 2;
    else
      return 3;
  }
  result = 1;
  if ( v9 != 16 && v9 != 64 )
  {
    if ( v9 != 256 )
      return 0;
    goto LABEL_11;
  }
  return result;
}
