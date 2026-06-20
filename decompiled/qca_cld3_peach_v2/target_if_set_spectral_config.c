__int64 __fastcall target_if_set_spectral_config(
        __int64 a1,
        unsigned int *a2,
        unsigned int a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 (*v14)(void); // x8
  __int64 v18; // x0
  const char *v20; // x2
  const char *v21; // x2
  __int64 v22; // x4
  __int64 v23; // x8
  __int64 v24; // x8
  char v25; // t1
  __int64 v26; // x22

  if ( !a4 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Error code argument is null",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_set_spectral_config");
    return 29;
  }
  *a4 = 0;
  if ( !a1 )
  {
    v20 = "%s: pdev object is NULL";
LABEL_17:
    qdf_trace_msg(0x56u, 2u, v20, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_set_spectral_config");
    return 16;
  }
  v12 = *(_QWORD *)(a1 + 80);
  if ( !v12 )
  {
    v21 = "%s: psoc is null";
LABEL_15:
    qdf_trace_msg(0x56u, 2u, v21, a5, a6, a7, a8, a9, a10, a11, a12, "get_target_if_spectral_handle_from_pdev");
LABEL_16:
    v20 = "%s: spectral object is NULL";
    goto LABEL_17;
  }
  v13 = *(_QWORD *)(v12 + 2136);
  if ( !v13 )
  {
    v21 = "%s: rx_ops is null";
    goto LABEL_15;
  }
  v14 = *(__int64 (**)(void))(v13 + 256);
  if ( *((_DWORD *)v14 - 1) != 1565325861 )
    __break(0x8228u);
  v18 = v14();
  if ( !v18 )
    goto LABEL_16;
  if ( !a2 )
  {
    v20 = "%s: parameter object is NULL";
    goto LABEL_17;
  }
  if ( a3 < 2 )
  {
    v22 = *a2;
    if ( (unsigned int)v22 > 0x1B )
    {
      __break(0x5512u);
      return ((__int64 (*)(void))target_if_set_spectral_config)();
    }
    v23 = v18 + 56LL * a3 + 2 * v22;
    v25 = *(_BYTE *)(v23 + 232);
    v24 = v23 + 232;
    if ( (v25 & 1) == 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Spectral parameter(%u) unsupported for mode %u",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "target_if_set_spectral_config");
      *a4 = 1;
      return 16;
    }
    if ( *(_BYTE *)(v24 + 1) != 1 )
      return ((__int64 (*)(void))target_if_set_spectral_config)();
    v26 = v18;
    qdf_trace_msg(
      0x56u,
      3u,
      "%s: Setting Spectral parameter %u for all modes",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_set_spectral_config");
    if ( !(unsigned int)target_if_set_spectral_config(v26, a2, 0, a4) )
      return 16 * (unsigned int)((unsigned int)target_if_set_spectral_config(v26, a2, 1, a4) != 0);
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid Spectral mode %u",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_set_spectral_config",
      a3);
    *a4 = 2;
  }
  return 16;
}
