__int64 __fastcall hdd_adapter_set_wlm_client_latency_level(__int64 result)
{
  __int64 *v1; // x21
  __int64 v2; // x19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w0
  __int64 v21; // x4
  const char *v22; // x2
  unsigned int v23; // w0
  _BYTE v24[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(__int64 **)(result + 24);
  if ( v1 )
  {
    v2 = result;
    v3 = *v1;
    v24[0] = 0;
    if ( (unsigned int)mlme_get_cfg_wlm_reset(v3, v24) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: could not get the wlm reset flag",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "hdd_adapter_set_wlm_client_latency_level");
      v24[0] = 0;
    }
    else if ( (v24[0] & 1) != 0 )
    {
      goto LABEL_11;
    }
    if ( (hdd_get_multi_client_ll_support(v2) & 1) != 0 )
    {
      v20 = wlan_hdd_set_wlm_client_latency_level(
              v2,
              0xFFFFFF,
              *(_WORD *)(v2 + 52098),
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19);
      if ( v20 )
      {
        v21 = v20;
        v22 = "%s: Fail to set latency level:%u";
LABEL_10:
        qdf_trace_msg(0x33u, 3u, v22, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_adapter_set_wlm_client_latency_level", v21);
      }
    }
    else
    {
      v23 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))sme_set_wlm_latency_level)(
              v1[2],
              *(unsigned __int8 *)(*(_QWORD *)(v2 + 52832) + 8LL),
              *(unsigned __int16 *)(v2 + 52098),
              0,
              0);
      if ( v23 )
      {
        v21 = v23;
        v22 = "%s: set wlm mode failed, %u";
        goto LABEL_10;
      }
    }
LABEL_11:
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: wlm initial mode %u",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "hdd_adapter_set_wlm_client_latency_level",
               *(unsigned __int16 *)(v2 + 52098));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
