__int64 __fastcall sme_disable_uapsd_for_ac(
        unsigned int a1,
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
  __int64 v10; // x29
  __int64 v11; // x30
  unsigned int v14; // w21
  _QWORD *context; // x0
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // [xsp+8h] [xbp-28h]

  if ( a1 > 3 )
    return 16;
  v25 = v11;
  v14 = dword_A2FA58[a1];
  context = _cds_get_context(54, (__int64)"sme_disable_uapsd_for_ac", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    result = wma_disable_uapsd_per_ac(context, a2, v14);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to disable uapsd for ac %d for vdev %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "sme_disable_uapsd_for_ac",
      a1,
      a2,
      v10,
      v25);
  }
  return 16;
}
