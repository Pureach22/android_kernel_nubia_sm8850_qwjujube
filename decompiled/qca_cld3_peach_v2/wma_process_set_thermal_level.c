__int64 __fastcall wma_process_set_thermal_level(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  __int64 result; // x0
  const char *v13; // x2
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  void (*v24)(void); // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _DWORD v33[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v34; // [xsp+10h] [xbp-30h]
  __int64 v35; // [xsp+18h] [xbp-28h]
  __int64 v36; // [xsp+20h] [xbp-20h]
  __int64 v37; // [xsp+28h] [xbp-18h]
  __int64 v38; // [xsp+30h] [xbp-10h]
  __int64 v39; // [xsp+38h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v13 = "%s: TM Invalid input";
LABEL_7:
    qdf_trace_msg(0x36u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_set_thermal_level");
    result = 16;
    goto LABEL_21;
  }
  v10 = a2;
  qdf_trace_msg(0x36u, 8u, "%s: TM set level %d", a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_set_thermal_level", a2);
  if ( !*(_BYTE *)(a1 + 673) )
  {
    v13 = "%s: Thermal mgmt is not enabled, ignoring set level command";
    goto LABEL_7;
  }
  if ( v10 < 6 )
  {
    if ( *(unsigned __int8 *)(a1 + 672) == v10 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Current level %d is same as the set level, ignoring",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wma_process_set_thermal_level",
        v10);
    }
    else
    {
      *(_BYTE *)(a1 + 672) = v10;
      context = _cds_get_context(71, (__int64)"wma_process_set_thermal_level", a3, a4, a5, a6, a7, a8, a9, a10);
      if ( context && *context && (v23 = *(_QWORD *)(*context + 128LL)) != 0 )
      {
        v24 = *(void (**)(void))(v23 + 8);
        if ( v24 )
        {
          if ( *((_DWORD *)v24 - 1) != 632910735 )
            __break(0x8228u);
          v24();
        }
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          1u,
          "%s invalid instance",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "cdp_throttle_set_level");
      }
      v37 = 0;
      v38 = 0;
      v35 = 0;
      v36 = 0;
      qdf_trace_msg(
        0x36u,
        4u,
        "%s: Thermal level: %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wma_set_thermal_level_ind",
        v10);
      v34 = 0;
      v33[0] = 5237;
      v33[1] = v10;
      if ( (unsigned int)scheduler_post_message_debug(
                           0x36u,
                           0x34u,
                           52,
                           (unsigned __int16 *)v33,
                           0x70Fu,
                           (__int64)"wma_set_thermal_level_ind") )
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Fail to post set thermal level ind msg",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wma_set_thermal_level_ind");
    }
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid thermal level set %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_process_set_thermal_level",
      v10);
    result = 16;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
