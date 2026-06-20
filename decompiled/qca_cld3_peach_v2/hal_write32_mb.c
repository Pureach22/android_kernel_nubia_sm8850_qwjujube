__int64 __fastcall hal_write32_mb(_QWORD *a1, unsigned int a2, unsigned int a3)
{
  _QWORD *v3; // x23
  char v7; // w22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  __int64 v17; // x1
  _DWORD *v18; // x8
  __int64 v19; // x1
  __int64 result; // x0
  __int64 v21; // x9
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // [xsp+0h] [xbp-10h] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v3 = a1 + 9216;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *((_BYTE *)a1 + 74400);
  v31 = 0;
  if ( (v7 & 1) == 0 && (unsigned int)hif_force_wake_request(*a1) )
  {
    v16 = jiffies;
    if ( hal_write32_mb___last_ticks - jiffies + 125 < 0 )
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
        "hal_write32_mb",
        v31,
        v32);
      hal_write32_mb___last_ticks = v16;
    }
    goto LABEL_18;
  }
  if ( (v3[62] & 1) != 0 )
  {
    if ( *((_BYTE *)v3 + 520) != 1 )
    {
      pld_lock_reg_window(*(_QWORD *)(a1[1] + 40LL), (__int64)&v31);
      writel_5(1073741844, a1[2] + 12920LL);
      v21 = a1[2];
      *((_DWORD *)v3 + 125) = 20;
      v22 = readl_6(v21 + 12920);
      if ( v22 != 1073741844 )
      {
        hal_reg_wr_fail_history_add(a1, 12920, 1073741844, v22);
        if ( a1 )
          ++*((_DWORD *)v3 + 169);
      }
      writel_5(a3, a1[2] + (a2 & 0x7FFFF) + 0x80000LL);
      result = pld_unlock_reg_window(*(_QWORD *)(a1[1] + 40LL), (__int64)&v31);
      if ( (v7 & 1) != 0 )
        goto LABEL_19;
      goto LABEL_16;
    }
    v17 = a1[2] + a2;
    v18 = *(_DWORD **)(v3[83] + 48LL);
    if ( *(v18 - 1) != 925895004 )
      __break(0x8228u);
    v19 = ((__int64 (__fastcall *)(_QWORD *, __int64))v18)(a1, v17);
  }
  else
  {
    v19 = a1[2] + a2;
  }
  result = writel_5(a3, v19);
  if ( (v7 & 1) != 0 )
    goto LABEL_19;
LABEL_16:
  result = hif_force_wake_release(*a1);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: Wake up release failed",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hal_write32_mb",
      v31,
      v32);
LABEL_18:
    result = qdf_check_state_before_panic(v8, v9, v10, v11, v12, v13, v14, v15);
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
