__int64 __fastcall hdd_set_t2lm_negotiation_support(
        unsigned __int8 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w20
  int v12; // w21
  __int64 result; // x0
  __int64 *v14; // x22
  __int64 v15; // x23
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( !a2 )
    return 4294967274LL;
  v10 = *(unsigned __int8 *)(a2 + 4);
  if ( *(_BYTE *)(a2 + 4) )
  {
    if ( v10 == 2 )
    {
      v10 = 3;
      v12 = 1;
    }
    else if ( v10 == 1 )
    {
      v12 = 1;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Invalid T2LM negotiation support",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "hdd_get_cfg_t2lm_neg_support_type");
      v12 = 0;
      v10 = 0;
    }
  }
  else
  {
    v12 = 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: T2LM negotiation support: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_set_t2lm_negotiation_support",
    v10);
  v14 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  v15 = v14[2];
  wlan_mlme_set_t2lm_negotiation_supported(*v14, v10);
  result = 0;
  if ( v12 )
  {
    if ( (*(_BYTE *)(v15 + 21785) & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: clear user disabled roaming for eht testbed",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hdd_set_t2lm_negotiation_support");
      ucfg_clear_user_disabled_roaming(*v14, a1[8]);
      return 0;
    }
  }
  return result;
}
