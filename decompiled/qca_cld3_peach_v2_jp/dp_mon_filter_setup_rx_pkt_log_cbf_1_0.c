__int64 __fastcall dp_mon_filter_setup_rx_pkt_log_cbf_1_0(
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
  __int64 v10; // x20
  __int64 v11; // x11
  __int64 v12; // x10
  __int64 v13; // x12
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x12
  __int64 v21; // x8
  __int64 v22; // x20
  int v23; // w21
  __int64 result; // x0
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x9
  __int64 v29; // x12
  __int64 v30; // x10
  __int64 v31; // x11
  __int64 v32; // x12
  __int64 v33; // x9
  __int64 v34; // x11
  __int64 v35; // x12
  const char *v36; // x2
  __int64 v37; // [xsp+8h] [xbp-68h] BYREF
  __int64 v38; // [xsp+10h] [xbp-60h]
  __int64 v39; // [xsp+18h] [xbp-58h]
  __int64 v40; // [xsp+20h] [xbp-50h]
  __int64 v41; // [xsp+28h] [xbp-48h]
  __int64 v42; // [xsp+30h] [xbp-40h]
  __int64 v43; // [xsp+38h] [xbp-38h]
  __int64 v44; // [xsp+40h] [xbp-30h]
  __int64 v45; // [xsp+48h] [xbp-28h]
  __int64 v46; // [xsp+50h] [xbp-20h]
  __int64 v47; // [xsp+58h] [xbp-18h]
  int v48; // [xsp+60h] [xbp-10h]
  __int64 v49; // [xsp+68h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v37 = 0;
  if ( !a1 )
  {
    v36 = "%s: pdev Context is null";
LABEL_8:
    result = qdf_trace_msg(0x73u, 2u, v36, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_setup_rx_pkt_log_cbf_1_0");
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(a1 + 8) )
  {
    v36 = "%s: Soc Context is null";
    goto LABEL_8;
  }
  LOBYTE(v37) = 1;
  v10 = *(_QWORD *)(a1 + 95560);
  dp_mon_filter_set_status_cbf();
  ((void (__fastcall *)(__int64, __int64, __int64 *))dp_mon_filter_show_filter)(v10, 3, &v37);
  v11 = v42;
  v13 = v43;
  v12 = v44;
  v14 = *(_QWORD *)(*(_QWORD *)(v10 + 37064) + 24LL);
  *(_QWORD *)(v14 + 124) = v41;
  *(_QWORD *)(v14 + 148) = v12;
  *(_QWORD *)(v14 + 140) = v13;
  *(_QWORD *)(v14 + 132) = v11;
  v15 = v45;
  v16 = v46;
  v17 = v47;
  *(_DWORD *)(v14 + 180) = v48;
  *(_QWORD *)(v14 + 156) = v15;
  *(_QWORD *)(v14 + 172) = v17;
  *(_QWORD *)(v14 + 164) = v16;
  v18 = v39;
  v19 = v37;
  v20 = v38;
  *(_QWORD *)(v14 + 116) = v40;
  *(_QWORD *)(v14 + 108) = v18;
  *(_QWORD *)(v14 + 100) = v20;
  *(_QWORD *)(v14 + 92) = v19;
  qdf_mem_set(&v37, 0x5Cu, 0);
  v21 = *(_QWORD *)(a1 + 8);
  v22 = *(_QWORD *)(a1 + 95560);
  LOBYTE(v37) = 1;
  v23 = *(unsigned __int8 *)(*(_QWORD *)(v21 + 40) + 633LL);
  dp_mon_filter_set_cbf_cmn(a1, &v37);
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64 *))dp_mon_filter_show_filter)(v22, 3, &v37);
  v25 = 184;
  if ( !v23 )
    v25 = 0;
  v26 = v44;
  v27 = *(_QWORD *)(*(_QWORD *)(v22 + 37064) + 24LL) + v25;
  v29 = v41;
  v28 = v42;
  *(_QWORD *)(v27 + 48) = v43;
  *(_QWORD *)(v27 + 56) = v26;
  *(_QWORD *)(v27 + 32) = v29;
  *(_QWORD *)(v27 + 40) = v28;
  v31 = v46;
  v30 = v47;
  v32 = v45;
  *(_DWORD *)(v27 + 88) = v48;
  *(_QWORD *)(v27 + 72) = v31;
  *(_QWORD *)(v27 + 80) = v30;
  *(_QWORD *)(v27 + 64) = v32;
  v33 = v40;
  v34 = v37;
  v35 = v38;
  *(_QWORD *)(v27 + 16) = v39;
  *(_QWORD *)(v27 + 24) = v33;
  *(_QWORD *)v27 = v34;
  *(_QWORD *)(v27 + 8) = v35;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
