__int64 __fastcall cdp_ipa_opt_dp_enable_disable_low_power_mode(
        __int64 a1,
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
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  __int64 result; // x0
  __int64 v25; // [xsp+8h] [xbp-18h] BYREF
  int v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 80);
  v26 = 0;
  v25 = 0;
  if ( v10 && (v11 = *(_QWORD *)(v10 + 2800)) != 0 && (v12 = *(_QWORD *)(v11 + 16)) != 0 )
  {
    v14 = **(_QWORD **)(a1 + 1232);
    qdf_mem_set(&v25, 0xCu, 0);
    LOBYTE(v26) = 0;
    LODWORD(v25) = 44;
    HIDWORD(v25) = a2;
    if ( (unsigned int)wmi_unified_pdev_param_send(v12) )
    {
      v23 = "%s Unable to enable/disable:(%d) IMPS";
LABEL_11:
      qdf_trace_msg(
        0x45u,
        1u,
        v23,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "cdp_ipa_opt_dp_enable_disable_low_power_mode",
        a2);
      result = 16;
      goto LABEL_12;
    }
    LODWORD(v25) = 202;
    HIDWORD(v25) = a2;
    if ( (unsigned int)wmi_unified_pdev_param_send(v14) )
    {
      v23 = "%s Unable to enable/disable:(%d) ILP";
      goto LABEL_11;
    }
    result = wmi_unified_set_sta_ps_mode(v12);
    if ( (_DWORD)result )
    {
      v23 = "%s Unable to enable/disable:(%d) BMPS";
      goto LABEL_11;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "Unable to get wmi handle", a3, a4, a5, a6, a7, a8, a9, a10);
    result = 29;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
