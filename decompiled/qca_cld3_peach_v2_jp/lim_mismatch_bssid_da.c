bool __fastcall lim_mismatch_bssid_da(unsigned __int8 *a1)
{
  int v2; // w19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  int v12; // [xsp+0h] [xbp-20h]
  int v13; // [xsp+8h] [xbp-18h]
  int v14; // [xsp+10h] [xbp-10h]
  int v15; // [xsp+18h] [xbp-8h]

  v2 = qdf_mem_cmp(a1 + 16, a1 + 4, 6u);
  if ( v2 )
  {
    v13 = a1[17];
    v15 = a1[21];
    v14 = a1[18];
    v12 = a1[16];
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: DA: %02x:%02x:%02x:**:**:%02x mismatch bssid%02x:%02x:%02x:**:**:%02x",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "lim_mismatch_bssid_da",
      a1[4],
      a1[5],
      a1[6],
      a1[9],
      v12,
      v13,
      v14,
      v15);
  }
  return v2 != 0;
}
