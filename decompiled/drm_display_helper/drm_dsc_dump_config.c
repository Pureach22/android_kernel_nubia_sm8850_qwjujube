__int64 __fastcall drm_dsc_dump_config(__int64 a1, unsigned int a2, unsigned __int8 *a3)
{
  const char *v6; // x9
  const char *v7; // x4
  const char *v8; // x5
  const char *v9; // x6
  const char *v10; // x7
  const char *v11; // x8

  drm_printf(
    a1,
    "%.*sdsc-cfg: version: %d.%d, picture: w=%d, h=%d, slice: count=%d, w=%d, h=%d, size=%d\n",
    a2,
    "\t\t\t\t\tX",
    a3[127],
    a3[126],
    *((unsigned __int16 *)a3 + 5),
    *((unsigned __int16 *)a3 + 6),
    a3[3],
    *((unsigned __int16 *)a3 + 2),
    *((unsigned __int16 *)a3 + 3),
    *((unsigned __int16 *)a3 + 61));
  v6 = "no";
  if ( a3[26] )
    v7 = "yes";
  else
    v7 = "no";
  if ( a3[120] )
    v8 = "yes";
  else
    v8 = "no";
  if ( a3[2] )
    v9 = "yes";
  else
    v9 = "no";
  if ( a3[8] )
    v10 = "yes";
  else
    v10 = "no";
  if ( a3[128] )
    v11 = "yes";
  else
    v11 = "no";
  if ( a3[129] )
    v6 = "yes";
  drm_printf(
    a1,
    "%.*sdsc-cfg: mode: block-pred=%s, vbr=%s, rgb=%s, simple-422=%s, native-422=%s, native-420=%s\n",
    a2,
    "\t\t\t\t\tX",
    v7,
    v8,
    v9,
    v10,
    v11,
    v6);
  drm_printf(
    a1,
    "%.*sdsc-cfg: color-depth: uncompressed-bpc=%d, compressed-bpp=%d.%04d line-buf-bpp=%d\n",
    a2,
    "\t\t\t\t\tX",
    a3[1],
    *((unsigned __int16 *)a3 + 8) >> 4,
    625 * (*((_WORD *)a3 + 8) & 0xF),
    *a3);
  drm_printf(
    a1,
    "%.*sdsc-cfg: rc-model: size=%d, bits=%d, mux-word-size: %d, initial-delays: xmit=%d, dec=%d\n",
    a2,
    "\t\t\t\t\tX",
    *((unsigned __int16 *)a3 + 52),
    *((unsigned __int16 *)a3 + 62),
    a3[121],
    *((unsigned __int16 *)a3 + 11),
    *((unsigned __int16 *)a3 + 12));
  drm_printf(
    a1,
    "%.*sdsc-cfg: offsets: initial=%d, final=%d, slice-bpg=%d\n",
    a2,
    "\t\t\t\t\tX",
    *((unsigned __int16 *)a3 + 14),
    *((unsigned __int16 *)a3 + 59),
    *((unsigned __int16 *)a3 + 58));
  drm_printf(
    a1,
    "%.*sdsc-cfg: line-bpg-offsets: first=%d, non-first=%d, second=%d, non-second=%d, second-adj=%d\n",
    a2,
    "\t\t\t\t\tX",
    a3[27],
    *((unsigned __int16 *)a3 + 57),
    a3[130],
    *((unsigned __int16 *)a3 + 66),
    *((unsigned __int16 *)a3 + 67));
  drm_printf(
    a1,
    "%.*sdsc-cfg: rc-tgt-offsets: low=%d, high=%d, rc-edge-factor: %d, rc-quant-incr-limits: [0]=%d, [1]=%d\n",
    a2,
    "\t\t\t\t\tX",
    a3[15],
    a3[14],
    a3[18],
    a3[20],
    a3[19]);
  drm_printf(
    a1,
    "%.*sdsc-cfg: initial-scale: %d, scale-intervals: increment=%d, decrement=%d\n",
    a2,
    "\t\t\t\t\tX",
    a3[108],
    *((unsigned __int16 *)a3 + 56),
    *((unsigned __int16 *)a3 + 55));
  drm_printf(a1, "%.*sdsc-cfg: flatness: min-qp=%d, max-qp=%d\n", a2, "\t\t\t\t\tX", a3[106], a3[107]);
  drm_printf(
    a1,
    "%.*sdsc-cfg: rc-level:         0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14\n",
    a2,
    "\t\t\t\t\tX");
  drm_printf(
    a1,
    "%.*sdsc-cfg: rc-buf-thresh:  %3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d\n",
    a2,
    "\t\t\t\t\tX",
    *((unsigned __int16 *)a3 + 15),
    *((unsigned __int16 *)a3 + 16),
    *((unsigned __int16 *)a3 + 17),
    *((unsigned __int16 *)a3 + 18),
    *((unsigned __int16 *)a3 + 19),
    *((unsigned __int16 *)a3 + 20),
    *((unsigned __int16 *)a3 + 21),
    *((unsigned __int16 *)a3 + 22),
    *((unsigned __int16 *)a3 + 23),
    *((unsigned __int16 *)a3 + 24),
    *((unsigned __int16 *)a3 + 25),
    *((unsigned __int16 *)a3 + 26),
    *((unsigned __int16 *)a3 + 27),
    *((unsigned __int16 *)a3 + 28));
  drm_printf(
    a1,
    "%.*sdsc-cfg: rc-min-qp:      %3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d\n",
    a2,
    "\t\t\t\t\tX",
    a3[58],
    a3[61],
    a3[64],
    a3[67],
    a3[70],
    a3[73],
    a3[76],
    a3[79],
    a3[82],
    a3[85],
    a3[88],
    a3[91],
    a3[94],
    a3[97],
    a3[100]);
  drm_printf(
    a1,
    "%.*sdsc-cfg: rc-max-qp:      %3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d\n",
    a2,
    "\t\t\t\t\tX",
    a3[59],
    a3[62],
    a3[65],
    a3[68],
    a3[71],
    a3[74],
    a3[77],
    a3[80],
    a3[83],
    a3[86],
    a3[89],
    a3[92],
    a3[95],
    a3[98],
    a3[101]);
  return drm_printf(
           a1,
           "%.*sdsc-cfg: rc-bpg-offset:  %3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d\n",
           a2,
           "\t\t\t\t\tX",
           a3[60],
           a3[63],
           a3[66],
           a3[69],
           a3[72],
           a3[75],
           a3[78],
           a3[81],
           a3[84],
           a3[87],
           a3[90],
           a3[93],
           a3[96],
           a3[99],
           a3[102]);
}
