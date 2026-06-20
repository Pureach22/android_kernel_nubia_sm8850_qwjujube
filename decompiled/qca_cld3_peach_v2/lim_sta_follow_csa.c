__int64 __fastcall lim_sta_follow_csa(
        __int64 a1,
        __int64 a2,
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
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 ext_hdl; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w20
  unsigned int max_bw; // w0
  const char *v37; // x2
  unsigned int v38; // w1

  if ( *(_DWORD *)(a1 + 284) != *(_DWORD *)(a2 + 4)
    || *(_DWORD *)(a1 + 7176) != *(_DWORD *)a4
    || *(unsigned __int8 *)(a1 + 7186) != *(unsigned __int8 *)(a4 + 6) )
  {
    return 1;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdevid %d puncture, old: 0x%x, new: 0x%x",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_is_puncture_same",
    *(unsigned __int8 *)(a1 + 10),
    *(unsigned __int16 *)(a1 + 7184),
    *(unsigned __int16 *)(a3 + 16),
    v12,
    v13);
  if ( *(unsigned __int16 *)(a3 + 16) != *(unsigned __int16 *)(a1 + 7184) )
    return 1;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a1 + 16), v17, v18, v19, v20, v21, v22, v23, v24);
  if ( ext_hdl )
  {
    v34 = *(_DWORD *)(ext_hdl + 24248);
    max_bw = wlan_mlme_get_max_bw();
    if ( v34 == 2 && *(_DWORD *)a4 == 3 && max_bw >= 3 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: BW upgrade %d->%d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "lim_sta_follow_csa",
        2,
        3);
      return 1;
    }
    v37 = "%s: Ignore CSA, no change in ch, bw and puncture";
    v38 = 8;
  }
  else
  {
    v37 = "%s: null mlme priv";
    v38 = 2;
  }
  qdf_trace_msg(0x35u, v38, v37, v26, v27, v28, v29, v30, v31, v32, v33, "lim_sta_follow_csa");
  return 0;
}
