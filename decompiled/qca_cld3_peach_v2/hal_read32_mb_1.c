double __fastcall hal_read32_mb_1(__int64 a1, const char *a2)
{
  unsigned int v2; // w20
  double result; // d0
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
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // [xsp+0h] [xbp-10h] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v2 = (unsigned int)a2;
  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  if ( (unsigned int)a2 <= 0xFDF )
  {
    readl_8((unsigned int *)(*(_QWORD *)(a1 + 16) + (unsigned int)a2));
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
      v35,
      v36);
    goto LABEL_19;
  }
  if ( v2 < 0x80000 || (*(_BYTE *)(a1 + 74224) & 1) == 0 )
  {
    readl_8((unsigned int *)(*(_QWORD *)(a1 + 16) + v2));
    if ( (v5 & 1) != 0 )
      goto LABEL_20;
    goto LABEL_17;
  }
  if ( *(_BYTE *)(a1 + 74248) == 1 )
  {
    v22 = *(_QWORD *)(a1 + 16) + v2;
    v23 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 74392) + 48LL);
    if ( *((_DWORD *)v23 - 1) != 925895004 )
      __break(0x8228u);
    v24 = (unsigned int *)v23(a1, v22);
    readl_8(v24);
    if ( (v5 & 1) != 0 )
      goto LABEL_20;
LABEL_17:
    if ( !(unsigned int)hif_force_wake_release(*(_QWORD *)a1) )
      goto LABEL_20;
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: Wake up release failed",
      result,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "hal_read32_mb",
      v35,
      v36);
LABEL_19:
    qdf_check_state_before_panic(v14, v15, v16, v17, v18, v19, v20, v21);
    goto LABEL_20;
  }
  pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)&v35);
  v25 = (v2 >> 19) & 0x3F | 0x40000000;
  writel_7(v25, (unsigned int *)(*(_QWORD *)(a1 + 16) + 12920LL));
  v26 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 74228) = (v2 >> 19) & 0x3F;
  v27 = readl_8((unsigned int *)(v26 + 12920));
  if ( v27 != v25 )
  {
    hal_reg_wr_fail_history_add(a1, 12920, v25, v27);
    if ( a1 )
      ++*(_DWORD *)(a1 + 74404);
  }
  readl_8((unsigned int *)(*(_QWORD *)(a1 + 16) + (v2 & 0x7FFFF) + 0x80000LL));
  pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)&v35);
  if ( (v5 & 1) == 0 )
    goto LABEL_17;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
