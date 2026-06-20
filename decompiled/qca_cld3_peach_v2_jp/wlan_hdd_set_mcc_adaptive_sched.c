__int64 __fastcall wlan_hdd_set_mcc_adaptive_sched(
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
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _BYTE v21[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enable : %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_set_mcc_adaptive_sched",
    a2 & 1);
  ucfg_policy_mgr_get_mcc_adaptive_sch(a1, v21);
  result = 0;
  if ( v21[0] == 1 )
  {
    ucfg_policy_mgr_set_dynamic_mcc_adaptive_sch(a1, a2 & 1);
    result = sme_set_mas(a2 & 1);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Fail to config mcc adaptive sched.",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_hdd_set_mcc_adaptive_sched");
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
