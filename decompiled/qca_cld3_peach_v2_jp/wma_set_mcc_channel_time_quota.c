__int64 __fastcall wma_set_mcc_channel_time_quota(
        _QWORD *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  _QWORD *context; // x0
  _QWORD *v21; // x23
  unsigned int v22; // w0
  __int64 v23; // x2
  unsigned int v24; // w22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w21
  const char *v34; // x2
  unsigned int v35; // w1
  __int64 result; // x0
  _BYTE v37[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = 0;
  if ( !a1 )
  {
    v34 = "%s: NULL wma ptr. Exiting";
    goto LABEL_7;
  }
  context = _cds_get_context(53, (__int64)"wma_set_mcc_channel_time_quota", a7, a8, a9, a10, a11, a12, a13, a14);
  if ( !context )
  {
LABEL_10:
    result = 16;
    goto LABEL_11;
  }
  v21 = context;
  if ( !(unsigned __int8)lim_is_in_mcc((__int64)context) )
  {
    v34 = "%s: MCC is not active. Exiting";
    v35 = 8;
    goto LABEL_9;
  }
  v22 = wlan_reg_chan_band_to_freq(a1[4], a2, 1LL << a5, a7, a8, a9, a10, a11, a12, a13, a14);
  v23 = 1LL << a6;
  v24 = v22;
  v33 = wlan_reg_chan_band_to_freq(a1[4], a4, v23, v25, v26, v27, v28, v29, v30, v31, v32);
  if ( (unsigned int)policy_mgr_get_dynamic_mcc_adaptive_sch(v21[2694], v37) )
  {
    v34 = "%s: Failed to retrieve WNI_CFG_ENABLE_MCC_ADAPTIVE_SCHED. Exit";
LABEL_7:
    v35 = 2;
LABEL_9:
    qdf_trace_msg(0x36u, v35, v34, a7, a8, a9, a10, a11, a12, a13, a14, "wma_set_mcc_channel_time_quota");
    goto LABEL_10;
  }
  if ( v37[0] == 1 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Can't set channel quota while MCC_ADAPTIVE_SCHED is enabled. Exit",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "wma_set_mcc_channel_time_quota");
    result = 0;
  }
  else
  {
    result = wmi_unified_set_mcc_channel_time_quota_cmd(*a1, v24, a3, v33);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
