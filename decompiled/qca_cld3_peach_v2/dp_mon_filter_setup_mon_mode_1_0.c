__int64 __fastcall dp_mon_filter_setup_mon_mode_1_0(
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
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x19
  int v12; // w22
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 v17; // x12
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x12
  __int64 v21; // x9
  __int64 v22; // x11
  __int64 v23; // x12
  __int64 result; // x0
  __int64 v25; // x11
  __int64 v26; // x10
  __int64 v27; // x12
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x11
  __int64 v31; // x12
  __int64 v32; // x10
  __int64 v33; // x11
  __int64 v34; // x12
  const char *v35; // x2
  __int64 v36; // [xsp+8h] [xbp-68h] BYREF
  __int64 v37; // [xsp+10h] [xbp-60h]
  __int64 v38; // [xsp+18h] [xbp-58h]
  __int64 v39; // [xsp+20h] [xbp-50h]
  __int64 v40; // [xsp+28h] [xbp-48h]
  __int64 v41; // [xsp+30h] [xbp-40h]
  __int64 v42; // [xsp+38h] [xbp-38h]
  __int64 v43; // [xsp+40h] [xbp-30h]
  __int64 v44; // [xsp+48h] [xbp-28h]
  __int64 v45; // [xsp+50h] [xbp-20h]
  __int64 v46; // [xsp+58h] [xbp-18h]
  int v47; // [xsp+60h] [xbp-10h]
  __int64 v48; // [xsp+68h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v36 = 0;
  if ( !a1 )
  {
    v35 = "%s: pdev Context is null";
LABEL_8:
    result = qdf_trace_msg(0x73u, 2u, v35, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_setup_mon_mode_1_0");
    goto LABEL_9;
  }
  v9 = *(_QWORD *)(a1 + 8);
  if ( !v9 )
  {
    v35 = "%s: Soc Context is null";
    goto LABEL_8;
  }
  v10 = *(_QWORD *)(v9 + 40);
  LOBYTE(v36) = 1;
  v11 = *(_QWORD *)(a1 + 96456);
  v12 = *(unsigned __int8 *)(v10 + 633);
  dp_mon_filter_set_mon_cmn();
  ((void (__fastcall *)(__int64, _QWORD, __int64 *))dp_mon_filter_show_filter)(v11, 0, &v36);
  v13 = 184;
  if ( !v12 )
    v13 = 0;
  v14 = v43;
  v15 = **(_QWORD **)(v11 + 37064) + v13;
  v17 = v40;
  v16 = v41;
  *(_QWORD *)(v15 + 48) = v42;
  *(_QWORD *)(v15 + 56) = v14;
  *(_QWORD *)(v15 + 32) = v17;
  *(_QWORD *)(v15 + 40) = v16;
  v19 = v45;
  v18 = v46;
  v20 = v44;
  *(_DWORD *)(v15 + 88) = v47;
  *(_QWORD *)(v15 + 72) = v19;
  *(_QWORD *)(v15 + 80) = v18;
  *(_QWORD *)(v15 + 64) = v20;
  v21 = v39;
  v22 = v36;
  v23 = v37;
  *(_QWORD *)(v15 + 16) = v38;
  *(_QWORD *)(v15 + 24) = v21;
  *(_QWORD *)v15 = v22;
  *(_QWORD *)(v15 + 8) = v23;
  qdf_mem_set(&v36, 0x5Cu, 0);
  LOBYTE(v36) = 1;
  dp_mon_filter_set_status_cmn(v11, &v36);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))dp_mon_filter_show_filter)(v11, 0, &v36);
  v25 = v41;
  v27 = v42;
  v26 = v43;
  v28 = **(_QWORD **)(v11 + 37064);
  *(_QWORD *)(v28 + 124) = v40;
  *(_QWORD *)(v28 + 148) = v26;
  *(_QWORD *)(v28 + 140) = v27;
  *(_QWORD *)(v28 + 132) = v25;
  v29 = v44;
  v30 = v45;
  v31 = v46;
  *(_DWORD *)(v28 + 180) = v47;
  *(_QWORD *)(v28 + 156) = v29;
  *(_QWORD *)(v28 + 172) = v31;
  *(_QWORD *)(v28 + 164) = v30;
  v32 = v38;
  v33 = v36;
  v34 = v37;
  *(_QWORD *)(v28 + 116) = v39;
  *(_QWORD *)(v28 + 108) = v32;
  *(_QWORD *)(v28 + 100) = v34;
  *(_QWORD *)(v28 + 92) = v33;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
