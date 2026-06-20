__int64 __fastcall mlo_mgr_update_csa_link_info(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v15; // w23
  __int16 bw_value; // w0
  __int64 v17; // x22
  __int16 v18; // w21
  unsigned int v19; // w1
  int v20; // w10
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  const char *v30; // x2
  int v31; // [xsp+10h] [xbp-20h] BYREF
  __int64 v32; // [xsp+14h] [xbp-1Ch]
  __int64 v33; // [xsp+1Ch] [xbp-14h]
  int v34; // [xsp+24h] [xbp-Ch]
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v33 = 0;
  v32 = 0;
  if ( !a2 )
  {
    v30 = "%s: invalid mlo dev ctx";
LABEL_12:
    qdf_trace_msg(0x8Fu, 2u, v30, a5, a6, a7, a8, a9, a10, a11, a12, "mlo_mgr_update_csa_link_info");
    result = 0;
    goto LABEL_13;
  }
  v15 = a4;
  bw_value = wlan_reg_get_bw_value(*(_DWORD *)(a3 + 12));
  if ( v15 > 0xE )
    goto LABEL_11;
  v17 = *(_QWORD *)(a2 + 3880);
  if ( *(unsigned __int8 *)(v17 + 6) != v15 )
  {
    if ( *(unsigned __int8 *)(v17 + 54) != v15 )
    {
      if ( *(unsigned __int8 *)(v17 + 102) == v15 )
      {
        v17 += 96;
        if ( v17 )
          goto LABEL_7;
      }
      goto LABEL_11;
    }
    v17 += 48;
  }
  if ( !v17 )
  {
LABEL_11:
    v30 = "%s: invalid link_info";
    goto LABEL_12;
  }
LABEL_7:
  v18 = bw_value;
  **(_WORD **)(v17 + 32) = *(_DWORD *)(a3 + 4);
  v19 = *(_DWORD *)(a3 + 4);
  v31 = *(_DWORD *)(a3 + 12);
  wlan_reg_set_channel_params_for_pwrmode(a1, v19, 0, (__int64)&v31, 0, a5, a6, a7, a8, a9, a10, a11, a12);
  v20 = v33;
  *(_DWORD *)(*(_QWORD *)(v17 + 32) + 16LL) = HIDWORD(v32);
  *(_DWORD *)(*(_QWORD *)(v17 + 32) + 20LL) = v20;
  *(_DWORD *)(*(_QWORD *)(v17 + 32) + 28LL) = wlan_eht_chan_phy_mode(
                                                *(unsigned int *)(a3 + 4),
                                                v18,
                                                *(_DWORD *)(a3 + 12));
  *(_DWORD *)(*(_QWORD *)(v17 + 32) + 24LL) = *(_DWORD *)(a3 + 12);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: CSA: freq: %d, cfreq1: %d, cfreq2: %d, bw: %d, phymode:%d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "mlo_mgr_update_csa_link_info",
    **(unsigned __int16 **)(v17 + 32),
    *(unsigned int *)(*(_QWORD *)(v17 + 32) + 16LL),
    *(unsigned int *)(*(_QWORD *)(v17 + 32) + 20LL),
    *(unsigned int *)(*(_QWORD *)(v17 + 32) + 24LL),
    *(_DWORD *)(*(_QWORD *)(v17 + 32) + 28LL));
  result = 1;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
