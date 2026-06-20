__int64 __fastcall hdd_set_idle_ps_config(
        __int64 a1,
        char a2,
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
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w20

  v10 = a2 & 1;
  v13 = qdf_trace_msg(0x33u, 8u, "%s: Enter Val %d", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_idle_ps_config", a2 & 1);
  if ( (unsigned int)hdd_get_conparam(v13) == 5 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Skipping powersave in FTM",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_set_idle_ps_config");
    return 0;
  }
  else if ( *(unsigned __int8 *)(a1 + 3256) == v10 )
  {
    qdf_trace_msg(0x33u, 8u, "Already in the requested power state:%d", v14, v15, v16, v17, v18, v19, v20, v21, v10);
    return 0;
  }
  else
  {
    result = sme_set_idle_powersave_config(a2 & 1);
    if ( (_DWORD)result )
    {
      v31 = result;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Fail to Set Idle PS Config val %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "hdd_set_idle_ps_config",
        v10);
      return v31;
    }
    else
    {
      *(_BYTE *)(a1 + 3256) = v10;
    }
  }
  return result;
}
