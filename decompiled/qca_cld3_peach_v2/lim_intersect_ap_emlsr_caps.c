__int64 __fastcall lim_intersect_ap_emlsr_caps(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x8
  const char *v27; // x2
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  v12 = *(_QWORD *)(a10 + 16);
  wlan_objmgr_vdev_get_ref(v12, 2u, a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !v12 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: vdev is null",
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             "lim_intersect_ap_emlsr_caps");
  v24 = *(_QWORD *)(v12 + 1360);
  if ( v24 )
  {
    v25 = *(_QWORD *)(v24 + 2224);
    if ( v25 )
    {
      if ( (*(_BYTE *)(v12 + 49) & 4) != 0 )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(a10 + 16) + 60LL) & 2) != 0 )
        {
          *(_BYTE *)(a11 + 397) = *(_BYTE *)(v25 + 1344);
          *(_WORD *)(a11 + 402) = *(unsigned __int8 *)(v25 + 1345);
        }
        else
        {
          *(_BYTE *)(a11 + 397) = 1;
          *(_WORD *)(a11 + 402) = (*(_WORD *)(a12 + 5358) >> 11) & 0xF;
          *(_BYTE *)(v25 + 1344) = 1;
          *(_BYTE *)(v25 + 1345) = *(_BYTE *)(a11 + 402);
        }
      }
      else
      {
        *(_BYTE *)(a11 + 397) = 0;
      }
      goto LABEL_10;
    }
    v27 = "%s: sta ctx is null";
  }
  else
  {
    v27 = "%s: mlo dev ctx is null";
  }
  qdf_trace_msg(0x35u, 2u, v27, v16, v17, v18, v19, v20, v21, v22, v23, "lim_intersect_ap_emlsr_caps");
LABEL_10:
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: emlsr support: %d, transition timeout:%d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "lim_intersect_ap_emlsr_caps",
    *(unsigned __int8 *)(a11 + 397),
    *(unsigned __int16 *)(a11 + 402));
  return wlan_objmgr_vdev_release_ref(v12, 2u, v28, v29, v30, v31, v32, v33, v34, v35, v36);
}
