__int64 __fastcall hal_read32_mb_1(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  char v5; // w22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x1
  __int64 (__fastcall *v23)(__int64, __int64); // x8
  unsigned int *v24; // x0
  int v25; // w21
  __int64 v26; // x8
  int v27; // w0
  unsigned int v28; // w20
  __int64 v29; // x8
  unsigned int v30; // w19
  int v31; // w8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // [xsp+0h] [xbp-10h] BYREF
  __int64 v41; // [xsp+8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  if ( a2 <= 0xFDF )
  {
    result = readl_8((unsigned int *)(*(_QWORD *)(a1 + 16) + a2));
    goto LABEL_20;
  }
  v5 = *(_BYTE *)(a1 + 74400);
  if ( (v5 & 1) == 0 && (unsigned int)hif_force_wake_request(*(_QWORD *)a1) )
  {
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: Wake up request failed",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hal_read32_mb",
      v40,
      v41);
    goto LABEL_19;
  }
  if ( a2 < 0x80000 || (*(_BYTE *)(a1 + 74224) & 1) == 0 )
  {
    result = readl_8((unsigned int *)(*(_QWORD *)(a1 + 16) + a2));
    if ( (v5 & 1) != 0 )
      goto LABEL_20;
    goto LABEL_17;
  }
  if ( *(_BYTE *)(a1 + 74248) == 1 )
  {
    v22 = *(_QWORD *)(a1 + 16) + a2;
    v23 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 74392) + 48LL);
    if ( *((_DWORD *)v23 - 1) != 925895004 )
      __break(0x8228u);
    v24 = (unsigned int *)v23(a1, v22);
    result = readl_8(v24);
    if ( (v5 & 1) != 0 )
      goto LABEL_20;
LABEL_17:
    v29 = *(_QWORD *)a1;
    v30 = result;
    v31 = hif_force_wake_release(v29);
    result = v30;
    if ( !v31 )
      goto LABEL_20;
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: Wake up release failed",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "hal_read32_mb",
      v40,
      v41);
LABEL_19:
    qdf_check_state_before_panic(v14, v15, v16, v17, v18, v19, v20, v21);
    result = 0;
    goto LABEL_20;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)&v40);
  v25 = (a2 >> 19) & 0x3F | 0x40000000;
  writel_7(v25, (unsigned int *)(*(_QWORD *)(a1 + 16) + 12920LL));
  v26 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 74228) = (a2 >> 19) & 0x3F;
  v27 = readl_8((unsigned int *)(v26 + 12920));
  if ( v27 != v25 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v25, v27);
    if ( a1 )
      ++*(_DWORD *)(a1 + 74404);
  }
  v28 = readl_8((unsigned int *)(*(_QWORD *)(a1 + 16) + (a2 & 0x7FFFF) + 0x80000LL));
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)&v40);
  result = v28;
  if ( (v5 & 1) == 0 )
    goto LABEL_17;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
