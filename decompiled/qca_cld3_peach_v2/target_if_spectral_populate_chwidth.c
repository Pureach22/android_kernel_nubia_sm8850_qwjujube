__int64 __fastcall target_if_spectral_populate_chwidth(__int64 a1, unsigned int *a2, char a3)
{
  unsigned int default_sscan_bw; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x4
  unsigned int v17; // w0

  if ( *(_BYTE *)(a1 + 1192) == 1 )
  {
    *a2 = *(unsigned __int16 *)(a1 + 708);
    if ( (*(_BYTE *)(a1 + 1193) & 1) != 0 )
    {
LABEL_3:
      a2[1] = *(unsigned __int16 *)(a1 + 788);
      return 0;
    }
  }
  else
  {
    default_sscan_bw = get_default_sscan_bw(a1, 0, a3 & 1);
    v16 = default_sscan_bw;
    *a2 = default_sscan_bw;
    if ( default_sscan_bw >= 8 )
    {
LABEL_7:
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Invalid sscan BW %u",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "target_if_spectral_populate_chwidth",
        v16);
      return 16;
    }
    *(_WORD *)(a1 + 708) = default_sscan_bw;
    if ( (*(_BYTE *)(a1 + 1193) & 1) != 0 )
      goto LABEL_3;
  }
  v17 = get_default_sscan_bw(a1, 1, a3 & 1);
  v16 = v17;
  a2[1] = v17;
  if ( v17 > 7 )
    goto LABEL_7;
  *(_WORD *)(a1 + 788) = v17;
  return 0;
}
