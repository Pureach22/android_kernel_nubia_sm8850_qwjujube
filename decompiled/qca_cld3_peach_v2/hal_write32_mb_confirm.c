__int64 __fastcall hal_write32_mb_confirm(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  char v7; // w23
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x1
  __int64 (__fastcall *v25)(__int64, __int64); // x8
  __int64 v26; // x21
  __int64 v27; // x8
  unsigned int v28; // w21
  int v29; // w0
  int v30; // w3
  __int64 v31; // x0
  int v32; // w1
  int v33; // w0
  unsigned int v34; // w22
  __int64 v35; // x8
  int v36; // w0
  __int64 v37; // x22
  int v38; // w0
  unsigned int v39; // w20
  __int64 v40; // x8
  unsigned int v41; // w19
  int v42; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // [xsp+0h] [xbp-10h] BYREF
  __int64 v60; // [xsp+8h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59 = 0;
  if ( a2 <= 0xFDF )
  {
    writel_6(a3, *(_QWORD *)(a1 + 16) + a2);
    result = 11;
    goto LABEL_22;
  }
  v7 = *(_BYTE *)(a1 + 74400);
  if ( (v7 & 1) == 0 && (unsigned int)hif_force_wake_request(*(_QWORD *)a1) )
  {
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: Wake up request failed",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hal_write32_mb_confirm",
      v59,
      v60);
    qdf_check_state_before_panic(v16, v17, v18, v19, v20, v21, v22, v23);
    result = 16;
    goto LABEL_22;
  }
  if ( a2 >= 0x80000 && (*(_BYTE *)(a1 + 74224) & 1) != 0 )
  {
    if ( *(_BYTE *)(a1 + 74248) != 1 )
    {
      pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)&v59);
      v34 = (a2 >> 19) & 0x3F | 0x40000000;
      writel_6(v34, *(_QWORD *)(a1 + 16) + 12920LL);
      v35 = *(_QWORD *)(a1 + 16);
      *(_DWORD *)(a1 + 74228) = (a2 >> 19) & 0x3F;
      v36 = readl_7(v35 + 12920);
      if ( v36 != v34 )
      {
        hal_reg_wr_fail_history_add(a1, 12920, v34, v36);
        if ( a1 )
          ++*(_DWORD *)(a1 + 74404);
      }
      writel_6(a3, *(_QWORD *)(a1 + 16) + (a2 & 0x7FFFF) + 0x80000LL);
      v37 = a2 & 0x7FFFF | 0x80000;
      v38 = readl_7(*(_QWORD *)(a1 + 16) + v37);
      if ( v38 == a3 )
      {
        v39 = 0;
      }
      else
      {
        hal_reg_wr_fail_history_add(a1, v37, a3, v38);
        if ( a1 )
          ++*(_DWORD *)(a1 + 74404);
        v39 = 16;
      }
      pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)&v59);
      result = v39;
      goto LABEL_19;
    }
    v24 = *(_QWORD *)(a1 + 16) + a2;
    v25 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 74392) + 48LL);
    if ( *((_DWORD *)v25 - 1) != 925895004 )
      __break(0x8228u);
    v26 = v25(a1, v24);
    writel_6(a3, v26);
    v27 = *(_QWORD *)(a1 + 16);
    v28 = v26 - v27;
    v29 = readl_7(v27 + v28);
    if ( v29 != a3 )
    {
      v30 = v29;
      v31 = a1;
      v32 = v28;
      goto LABEL_24;
    }
  }
  else
  {
    writel_6(a3, *(_QWORD *)(a1 + 16) + a2);
    v33 = readl_7(*(_QWORD *)(a1 + 16) + a2);
    if ( v33 != a3 )
    {
      v30 = v33;
      v31 = a1;
      v32 = a2;
LABEL_24:
      hal_reg_wr_fail_history_add(v31, v32, a3, v30);
      result = 16;
      if ( a1 )
        ++*(_DWORD *)(a1 + 74404);
      goto LABEL_19;
    }
  }
  result = 0;
LABEL_19:
  if ( (v7 & 1) == 0 )
  {
    v40 = *(_QWORD *)a1;
    v41 = result;
    v42 = hif_force_wake_release(v40);
    result = v41;
    if ( v42 )
    {
      qdf_trace_msg(
        0x46u,
        2u,
        "%s: Wake up release failed",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "hal_write32_mb_confirm",
        v59,
        v60);
      qdf_check_state_before_panic(v51, v52, v53, v54, v55, v56, v57, v58);
      result = 4;
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
