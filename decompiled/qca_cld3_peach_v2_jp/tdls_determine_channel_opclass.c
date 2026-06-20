__int64 __fastcall tdls_determine_channel_opclass(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int *a4,
        _DWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  char v16; // w8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w5
  __int64 v27; // x22
  int v28; // w2
  int v29; // w1
  __int64 v30; // x0
  unsigned int v31; // w0
  unsigned int channel; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int8 v41; // w0
  __int64 result; // x0
  int v43; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_BYTE *)(a1 + 156);
  v43 = 0;
  if ( (v16 & 1) != 0 && *(_DWORD *)(a1 + 208) == 1 )
  {
    *a4 = (unsigned __int8)wlan_reg_freq_to_chan(0, *(_DWORD *)(a3 + 492), a6, a7, a8, a9, a10, a11, a12, a13);
    v26 = *(unsigned __int8 *)(a3 + 490);
  }
  else
  {
    v27 = *(_QWORD *)(*(_QWORD *)a2 + 152LL);
    v28 = *(unsigned __int8 *)(*(_QWORD *)a2 + 104LL);
    v29 = *(_DWORD *)(*(_QWORD *)a2 + 16LL);
    v30 = *(_QWORD *)(v27 + 80);
    v43 = v28;
    v31 = policy_mgr_qdf_opmode_to_pm_con_mode(v30, v29, v28, a6, a7, a8, a9, a10, a11, a12, a13);
    channel = policy_mgr_get_channel(*(_QWORD *)a1, v31, &v43);
    v41 = wlan_reg_freq_to_chan(v27, channel, v33, v34, v35, v36, v37, v38, v39, v40);
    v26 = 0;
    *a4 = v41;
  }
  *a5 = v26;
  result = qdf_trace_msg(
             0,
             8u,
             "%s: channel:%d opclass:%d",
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             "tdls_determine_channel_opclass",
             *a4);
  _ReadStatusReg(SP_EL0);
  return result;
}
