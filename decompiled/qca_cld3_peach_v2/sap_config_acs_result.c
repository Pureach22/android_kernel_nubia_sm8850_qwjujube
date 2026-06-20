__int64 __fastcall sap_config_acs_result(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  unsigned int v8; // w22
  long double v9; // q0
  char v10; // w0
  int concurrent_bw; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  bool is_6ghz_chan_freq; // w0
  int v31; // w9
  int v32; // w9
  __int64 v33; // x8
  unsigned int v34; // w10
  int v35; // w10
  __int64 v36; // x8
  int v37; // w9
  int v38; // w9
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 result; // x0
  _BYTE v43[12]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v44; // [xsp+Ch] [xbp-14h]
  int v45; // [xsp+14h] [xbp-Ch]
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 1544);
  v7 = *(unsigned int *)(a2 + 1484);
  v45 = 0;
  v44 = 0;
  v8 = *(unsigned __int16 *)(v6 + 42);
  *(_QWORD *)&v43[4] = 0;
  *(_DWORD *)v43 = v8;
  *(double *)&v9 = sap_phymode_is_eht(v7);
  if ( (v10 & 1) != 0 )
  {
    wlan_reg_set_create_punc_bitmap((__int64)v43, 1);
    v8 = *(_DWORD *)v43;
  }
  concurrent_bw = wlan_sap_get_concurrent_bw(
                    *(_QWORD *)(a1 + 21632),
                    *(_QWORD *)(a1 + 21624),
                    *(unsigned int *)(*(_QWORD *)(a2 + 1544) + 564LL),
                    v8,
                    v9);
  if ( *(_DWORD *)v43 != concurrent_bw )
  {
    v20 = concurrent_bw;
    qdf_trace_msg(0x39u, 8u, "%s: Width: %d -> %d", v12, v13, v14, v15, v16, v17, v18, v19, "sap_config_acs_result");
    *(_DWORD *)v43 = v20;
  }
  wlan_reg_set_channel_params_for_pwrmode(
    *(_QWORD *)(a1 + 21632),
    *(_DWORD *)(*(_QWORD *)(a2 + 1544) + 564LL),
    a3,
    (__int64)v43,
    0,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19);
  *(_WORD *)(*(_QWORD *)(a2 + 1544) + 42LL) = *(_WORD *)v43;
  v29 = *(_QWORD *)(a2 + 1544);
  if ( *(unsigned __int16 *)(v29 + 42) > 1u
    || (is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v29 + 564)),
        v29 = *(_QWORD *)(a2 + 1544),
        is_6ghz_chan_freq) )
  {
    v31 = *(_DWORD *)&v43[8];
  }
  else
  {
    v31 = 0;
  }
  *(_DWORD *)(v29 + 572) = v31;
  v32 = 0;
  v33 = *(_QWORD *)(a2 + 1544);
  v34 = *(unsigned __int16 *)(v33 + 42);
  if ( v34 <= 7 && ((1 << v34) & 0x98) != 0 )
    v32 = v44;
  v35 = v43[4];
  *(_DWORD *)(v33 + 576) = v32;
  v36 = *(_QWORD *)(a2 + 1544);
  if ( v35 == 3 )
  {
    v37 = -20;
  }
  else
  {
    if ( v35 != 1 )
    {
      v38 = 0;
      goto LABEL_18;
    }
    v37 = 20;
  }
  v38 = *(_DWORD *)(v36 + 564) + v37;
LABEL_18:
  v39 = v43[5];
  v40 = *(unsigned int *)v43;
  v41 = HIWORD(v44);
  *(_DWORD *)(v36 + 568) = v38;
  result = qdf_trace_msg(
             0x39u,
             8u,
             "%s: ccfs0 %d ch_width %d, punct 0x%x",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "sap_acs_set_puncture_bitmap",
             v39,
             v40,
             v41,
             *(_QWORD *)v43);
  *(_WORD *)(*(_QWORD *)(a2 + 1544) + 586LL) = HIWORD(v44);
  _ReadStatusReg(SP_EL0);
  return result;
}
