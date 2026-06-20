__int64 __fastcall ucfg_spectral_control(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v13; // x2
  unsigned int v14; // w4
  __int64 v15; // x0
  __int64 comp_private_obj; // x0
  __int64 (__fastcall *v17)(__int64, unsigned int *); // x8

  if ( !a1 )
  {
    v13 = "%s: PDEV is NULL!";
LABEL_17:
    qdf_trace_msg(0x56u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_spectral_control");
    return 4;
  }
  if ( (wlan_spectral_is_feature_disabled_pdev(a1) & 1) != 0 )
  {
    qdf_trace_msg(
      0x56u,
      4u,
      "%s: Spectral feature is disabled",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_spectral_control");
    return 39;
  }
  v14 = *((unsigned __int8 *)a2 + 4);
  if ( v14 > 0x35 )
    goto LABEL_8;
  if ( ((1LL << v14) & 0xD8C0000000LL) != 0 )
  {
    if ( (wlan_spectral_is_mode_disabled_pdev(a1, *a2) & 1) != 0 )
    {
      qdf_trace_msg(
        0x56u,
        4u,
        "%s: Spectral mode %d is disabled",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "ucfg_spectral_control",
        *a2);
      return 11;
    }
  }
  else if ( ((1LL << v14) & 0x30E02000000000LL) == 0 )
  {
LABEL_8:
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid spectral cp request id %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_spectral_is_mode_specific_request");
  }
  v15 = *(_QWORD *)(a1 + 80);
  if ( !v15 || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v15, 0x13u)) == 0 )
  {
    v13 = "%s: spectral context is NULL!";
    goto LABEL_17;
  }
  v17 = *(__int64 (__fastcall **)(__int64, unsigned int *))(comp_private_obj + 48);
  if ( *((_DWORD *)v17 - 1) != -830522681 )
    __break(0x8228u);
  return v17(a1, a2);
}
