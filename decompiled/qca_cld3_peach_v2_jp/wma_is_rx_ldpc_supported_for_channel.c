__int64 __fastcall wma_is_rx_ldpc_supported_for_channel(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x8
  int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w2
  __int16 v31; // w8
  int v32; // w8
  _QWORD v33[7]; // [xsp+8h] [xbp-38h] BYREF

  v33[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(
                      54,
                      (__int64)"wma_is_rx_ldpc_supported_for_channel",
                      a2,
                      a3,
                      a4,
                      a5,
                      a6,
                      a7,
                      a8,
                      a9);
  memset(v33, 0, 48);
  if ( result )
  {
    v19 = *(_QWORD *)(result + 24);
    if ( v19 && (v20 = *(_QWORD *)(v19 + 2800)) != 0 )
    {
      v21 = *(unsigned __int8 *)(v20 + 824);
      if ( wlan_reg_is_24ghz_ch_freq(a1) )
        v30 = 1;
      else
        v30 = 2;
      if ( (unsigned int)wma_get_caps_for_phyidx_hwmode(v33, 1, v30, v22, v23, v24, v25, v26, v27, v28, v29) )
      {
        result = 0;
      }
      else
      {
        if ( v21 )
        {
          if ( wlan_reg_is_24ghz_ch_freq(a1) )
            v31 = v33[0];
          else
            v31 = WORD2(v33[0]);
          v32 = v31 & 0x1000;
        }
        else
        {
          v32 = v33[0] & 0x40;
        }
        result = v32 != 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Target handle is NULL",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wma_is_rx_ldpc_supported_for_channel");
      result = 1;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
