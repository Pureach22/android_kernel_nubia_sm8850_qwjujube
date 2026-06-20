__int64 __fastcall wma_set_mcc_channel_time_latency(_QWORD *a1, unsigned __int8 a2, unsigned int a3)
{
  unsigned int v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w21
  _QWORD *context; // x0
  _QWORD *v16; // x22
  const char *v17; // x2
  __int64 result; // x0
  _BYTE v19[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  v5 = cds_chan_to_freq(a2);
  if ( !a1 )
  {
    v17 = "%s: NULL wma ptr. Exiting";
    goto LABEL_8;
  }
  v14 = v5;
  context = _cds_get_context(53, (__int64)"wma_set_mcc_channel_time_latency", v6, v7, v8, v9, v10, v11, v12, v13);
  if ( !context )
  {
LABEL_9:
    result = 16;
    goto LABEL_10;
  }
  v16 = context;
  if ( !(unsigned __int8)lim_is_in_mcc((__int64)context) )
  {
    v17 = "%s: MCC is not active. Exiting";
    goto LABEL_8;
  }
  if ( (unsigned int)policy_mgr_get_dynamic_mcc_adaptive_sch(v16[2694], v19) )
  {
    v17 = "%s: Failed to get value for MCC_ADAPTIVE_SCHED, Exit w/o setting latency";
LABEL_8:
    qdf_trace_msg(0x36u, 2u, v17, v6, v7, v8, v9, v10, v11, v12, v13, "wma_set_mcc_channel_time_latency");
    goto LABEL_9;
  }
  if ( v19[0] == 1 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Can't set channel latency while MCC ADAPTIVE SCHED is enabled. Exit",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wma_set_mcc_channel_time_latency");
    result = 0;
  }
  else
  {
    result = wmi_unified_set_mcc_channel_time_latency_cmd(*a1, v14, a3);
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
