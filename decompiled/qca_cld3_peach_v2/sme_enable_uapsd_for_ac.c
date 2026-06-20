__int64 __fastcall sme_enable_uapsd_for_ac(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        char a15,
        unsigned int a16)
{
  _QWORD *context; // x0
  unsigned int v19; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  _ReadStatusReg(SP_EL0);
  if ( !a15 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: No need to configure auto trigger:psb is 0",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "sme_enable_uapsd_for_ac");
    goto LABEL_7;
  }
  context = _cds_get_context(54, (__int64)"sme_enable_uapsd_for_ac", a2, a3, a4, a5, a6, a7, a8, a9);
  v19 = 16;
  if ( context && a1 <= 3 )
  {
    if ( (unsigned int)wma_trigger_uapsd_params() )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Failed to Trigger Uapsd params for vdev %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "sme_enable_uapsd_for_ac",
        a16);
      v19 = 16;
      goto LABEL_8;
    }
LABEL_7:
    v19 = 0;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v19;
}
