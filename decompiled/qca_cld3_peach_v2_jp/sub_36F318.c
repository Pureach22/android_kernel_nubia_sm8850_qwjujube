// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_36F318(
        unsigned int a1,
        _QWORD a2,
        const char *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w19
  __int64 v12; // x20
  __int64 v13; // x24
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x5

  qdf_trace_msg(a1, 2u, a3, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( *(_DWORD *)(v12 + 16) != -1 )
  {
    *(_DWORD *)(v12 + 36) = 16;
    hdd_wmm_notify_app(v12);
  }
  if ( *(_BYTE *)(v13 + 6) == 1 )
  {
    if ( *(_DWORD *)(v13 + 24) == 1 )
      *(_BYTE *)(v13 + 5) = 0;
    if ( *(_DWORD *)(v13 + 24) != 1 )
      goto LABEL_11;
  }
  if ( *(_BYTE *)v13 == 1 )
  {
    if ( (*(_BYTE *)(v13 + 5) & 1) != 0 )
      v22 = " ";
    else
      v22 = " not ";
  }
  else
  {
LABEL_11:
    v22 = " ";
    *(_BYTE *)(v13 + 5) = 1;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: complete, access for TL AC %d is%sallowed",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "hdd_wmm_sme_callback",
    v11,
    v22);
  return 0;
}
