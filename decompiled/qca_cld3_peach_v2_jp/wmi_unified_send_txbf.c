__int64 __fastcall wmi_unified_send_txbf(
        _QWORD *a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w11
  unsigned int v13; // w8
  unsigned int v14; // w20

  v10 = (unsigned __int8)a2[121];
  if ( (a2[122] & 1) != 0 )
    v13 = 3;
  else
    v13 = a2[120] & 1 | (2 * (a2[122] & 1));
  v14 = v13 & 0xFFFFFFFB | (4 * (v10 & 1));
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: txbf_en.sutxbfee %d txbf_en.mutxbfee %d, sutxbfer %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wmi_unified_send_txbf",
    v13 & 1,
    v13 >> 1,
    ((unsigned int)(4 * v10) >> 2) & 1);
  return wma_vdev_set_param(*a1, (unsigned __int8)a2[131], 45, v14);
}
