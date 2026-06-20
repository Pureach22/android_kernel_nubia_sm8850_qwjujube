__int64 __fastcall dwc3_msm_update_bus_bw(__int64 result, int a2)
{
  unsigned int v2; // w8
  _QWORD *v3; // x19
  __int64 v4; // x0
  unsigned int v5; // w20
  int v6; // w0
  int v7; // w0
  int v8; // w0

  if ( (*(_BYTE *)(result + 2804) & 1) == 0 )
  {
    v2 = *(_DWORD *)(result + 708);
    v3 = (_QWORD *)result;
    v4 = *(_QWORD *)(result + 1256);
    if ( v2 )
      v5 = v2;
    else
      v5 = a2;
    dwc3_dbg_print(v4, 0xFFu, "bus_vote_start", a2, (const char *)&unk_16A05);
    if ( v5 >= 3 )
      v5 = 3;
    v6 = icc_set_bw(v3[89], bus_vote_values[6 * v5], bus_vote_values[6 * v5 + 1]);
    if ( v6 )
      dev_err(*v3, "bus bw voting path:%s bv:%d failed %d\n", "usb-ddr", v5, v6);
    v7 = icc_set_bw(v3[90], bus_vote_values[6 * v5 + 2], bus_vote_values[6 * v5 + 3]);
    if ( v7 )
      dev_err(*v3, "bus bw voting path:%s bv:%d failed %d\n", "usb-ipa", v5, v7);
    v8 = icc_set_bw(v3[91], bus_vote_values[6 * v5 + 4], bus_vote_values[6 * v5 + 5]);
    if ( v8 )
      dev_err(*v3, "bus bw voting path:%s bv:%d failed %d\n", "ddr-usb", v5, v8);
    return dwc3_dbg_print(v3[157], 0xFFu, "bus_vote_end", v5, (const char *)&unk_16A05);
  }
  return result;
}
