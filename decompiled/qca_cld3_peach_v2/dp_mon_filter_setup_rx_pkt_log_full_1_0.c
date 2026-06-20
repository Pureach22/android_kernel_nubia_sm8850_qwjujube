__int64 __fastcall dp_mon_filter_setup_rx_pkt_log_full_1_0(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 result; // x0
  __int64 v11; // x11
  __int64 v12; // x10
  __int64 v13; // x12
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x10
  __int128 v19; // kr00_16
  __int128 v20; // [xsp+8h] [xbp-68h] BYREF
  __int64 v21; // [xsp+18h] [xbp-58h]
  __int64 v22; // [xsp+20h] [xbp-50h]
  __int64 v23; // [xsp+28h] [xbp-48h]
  __int64 v24; // [xsp+30h] [xbp-40h]
  __int64 v25; // [xsp+38h] [xbp-38h]
  __int64 v26; // [xsp+40h] [xbp-30h]
  __int64 v27; // [xsp+48h] [xbp-28h]
  __int64 v28; // [xsp+50h] [xbp-20h]
  __int64 v29; // [xsp+58h] [xbp-18h]
  int v30; // [xsp+60h] [xbp-10h]
  __int64 v31; // [xsp+68h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  v20 = 0u;
  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 96456);
    LOBYTE(v20) = 1;
    dp_mon_filter_set_status_cmn(v9, &v20);
    *(_QWORD *)((char *)&v20 + 4) |= 0x7AuLL;
    result = ((__int64 (__fastcall *)(__int64, __int64, __int128 *))dp_mon_filter_show_filter)(v9, 1, &v20);
    v11 = v24;
    v13 = v25;
    v12 = v26;
    v14 = *(_QWORD *)(*(_QWORD *)(v9 + 37064) + 8LL);
    *(_QWORD *)(v14 + 124) = v23;
    *(_QWORD *)(v14 + 148) = v12;
    *(_QWORD *)(v14 + 140) = v13;
    *(_QWORD *)(v14 + 132) = v11;
    v15 = v27;
    v16 = v28;
    v17 = v29;
    *(_DWORD *)(v14 + 180) = v30;
    *(_QWORD *)(v14 + 156) = v15;
    *(_QWORD *)(v14 + 172) = v17;
    *(_QWORD *)(v14 + 164) = v16;
    v18 = v21;
    v19 = v20;
    *(_QWORD *)(v14 + 116) = v22;
    *(_QWORD *)(v14 + 108) = v18;
    *(_OWORD *)(v14 + 92) = v19;
  }
  else
  {
    result = qdf_trace_msg(
               0x73u,
               2u,
               "%s: pdev Context is null",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "dp_mon_filter_setup_rx_pkt_log_full_1_0");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
