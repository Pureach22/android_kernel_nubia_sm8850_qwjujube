__int64 __fastcall sap_config_acs_result(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x1
  unsigned int v9; // w22
  __int64 v10; // x2
  unsigned int concurrent_bw; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w23
  __int64 result; // x0
  __int64 v22; // x8
  int v23; // w9
  int v24; // w10
  __int64 v25; // x8
  int v26; // w9
  __int64 v27; // x8
  bool v28; // zf
  int v29; // w9
  int v30; // w9
  unsigned int v31; // [xsp+8h] [xbp-18h] BYREF
  __int64 v32; // [xsp+Ch] [xbp-14h]
  int v33; // [xsp+14h] [xbp-Ch]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 1536);
  v7 = *(_QWORD *)(a1 + 21560);
  v8 = *(_QWORD *)(a1 + 21552);
  v33 = 0;
  v9 = *(unsigned __int16 *)(v6 + 42);
  v10 = *(unsigned int *)(v6 + 564);
  v32 = 0;
  v31 = v9;
  concurrent_bw = wlan_sap_get_concurrent_bw(v7, v8, v10, v9);
  if ( concurrent_bw != v9 )
  {
    v20 = concurrent_bw;
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: Width: %d -> %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "sap_config_acs_result",
      v9,
      concurrent_bw);
    v31 = v20;
  }
  result = wlan_reg_set_channel_params_for_pwrmode(
             *(_QWORD *)(a1 + 21560),
             *(_DWORD *)(*(_QWORD *)(a2 + 1536) + 564LL),
             a3,
             (__int64)&v31,
             0,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19);
  *(_WORD *)(*(_QWORD *)(a2 + 1536) + 42LL) = v31;
  v22 = *(_QWORD *)(a2 + 1536);
  if ( *(unsigned __int16 *)(v22 + 42) > 1u
    || (result = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v22 + 564)), v22 = *(_QWORD *)(a2 + 1536), (result & 1) != 0) )
  {
    v23 = HIDWORD(v32);
  }
  else
  {
    v23 = 0;
  }
  *(_DWORD *)(v22 + 572) = v23;
  v24 = v33;
  v25 = *(_QWORD *)(a2 + 1536);
  v26 = (unsigned __int8)v32;
  if ( (unsigned int)*(unsigned __int16 *)(v25 + 42) - 3 >= 2 )
    v24 = 0;
  *(_DWORD *)(v25 + 576) = v24;
  v27 = *(_QWORD *)(a2 + 1536);
  if ( v26 == 3 )
  {
    v30 = -20;
  }
  else
  {
    v28 = v26 == 1;
    v29 = 0;
    if ( !v28 )
      goto LABEL_15;
    v30 = 20;
  }
  v29 = *(_DWORD *)(v27 + 564) + v30;
LABEL_15:
  *(_DWORD *)(v27 + 568) = v29;
  _ReadStatusReg(SP_EL0);
  return result;
}
