__int64 __fastcall lim_update_ch_width_for_p2p_client(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w8
  __int64 v12; // x0
  __int64 v15; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w5
  int v25; // w6
  char v26; // w7
  int v27; // w8
  int v28; // [xsp+8h] [xbp-18h] BYREF
  __int64 v29; // [xsp+Ch] [xbp-14h]
  int v30; // [xsp+14h] [xbp-Ch]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 *)(a2 + 154);
  v30 = 0;
  v29 = 0;
  if ( v11 >= 8 )
  {
    v12 = *(_QWORD *)(result + 21560);
    v15 = a2 + 4096;
    v28 = 2;
    wlan_reg_set_channel_params_for_pwrmode(v12, a3, 0, (__int64)&v28, 0, a4, a5, a6, a7, a8, a9, a10, a11);
    v24 = v28;
    if ( v28 )
    {
      v25 = (unsigned __int8)v29;
    }
    else
    {
      v25 = 0;
      LOBYTE(v29) = 0;
    }
    v26 = BYTE1(v29);
    *(_BYTE *)(a2 + 160) = v25 != 0;
    *(_BYTE *)(a2 + 161) = v25 != 0;
    v27 = BYTE2(v29);
    *(_DWORD *)(a2 + 164) = v25;
    *(_DWORD *)(a2 + 7176) = v24;
    *(_BYTE *)(v15 + 3078) = v26;
    *(_BYTE *)(v15 + 3088) = v27;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Start P2P_CLI in ch freq %d max supported ch_width: %u cbmode: %u seg0: %u, seg1: %u",
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "lim_update_ch_width_for_p2p_client",
               a3,
               v27);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
