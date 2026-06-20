__int64 __fastcall policy_mgr_change_sap_channel_with_csa(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        char a5)
{
  __int64 context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _DWORD *v19; // x8
  __int64 v20; // x24
  __int64 v21; // x1
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _DWORD *v30; // x8
  __int64 result; // x0
  __int64 v32; // [xsp+8h] [xbp-18h] BYREF
  __int64 v33; // [xsp+10h] [xbp-10h]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid context",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "policy_mgr_change_sap_channel_with_csa");
LABEL_18:
    result = 4;
    goto LABEL_19;
  }
  v19 = *(_DWORD **)(context + 360);
  v20 = context;
  if ( v19 )
  {
    LODWORD(v32) = a4;
    if ( *(v19 - 1) != 157525345 )
      __break(0x8228u);
    if ( !((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD, __int64 *))v19)(a1, a2, a3, &v32)
      && (unsigned int)v32 < a4 )
    {
      a4 = v32;
    }
  }
  if ( HIDWORD(v33) )
    v21 = HIDWORD(v33);
  else
    v21 = (unsigned int)v33;
  if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))policy_mgr_check_bw_with_unsafe_chan_freq)(a1, v21, a4) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      4u,
      "%s: SAP bw shrink to 20M for unsafe",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "policy_mgr_change_sap_channel_with_csa");
    a4 = 0;
  }
  if ( !*(_QWORD *)(v20 + 288) )
    goto LABEL_18;
  qdf_trace_msg(
    0x4Fu,
    4u,
    "%s: SAP change change without restart",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "policy_mgr_change_sap_channel_with_csa");
  v30 = *(_DWORD **)(v20 + 288);
  if ( *(v30 - 1) != -1621151175 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))v30)(a1, a2, a3, a4, a5 & 1);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
