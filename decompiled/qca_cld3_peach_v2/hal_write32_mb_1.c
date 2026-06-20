double __fastcall hal_write32_mb_1(_QWORD *a1, const char *a2, unsigned int a3)
{
  unsigned int v4; // w21
  double result; // d0
  char v7; // w23
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
  unsigned int v20; // w22
  __int64 v21; // x8
  int v22; // w0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // [xsp+0h] [xbp-10h] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v4 = (unsigned int)a2;
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  if ( (unsigned int)a2 <= 0xFDF )
  {
    writel_7(a3, a1[2] + (unsigned int)a2);
    goto LABEL_22;
  }
  v7 = *((_BYTE *)a1 + 74400);
  if ( (v7 & 1) == 0 && (unsigned int)hif_force_wake_request(*a1) )
  {
    v16 = jiffies;
    if ( hal_write32_mb___last_ticks_1 - jiffies + 125 < 0 )
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
        v30,
        v31);
      hal_write32_mb___last_ticks_1 = v16;
    }
    goto LABEL_21;
  }
  if ( v4 < 0x80000 || (a1[9278] & 1) == 0 )
  {
    v19 = a1[2] + v4;
    goto LABEL_15;
  }
  if ( *((_BYTE *)a1 + 74248) == 1 )
  {
    v17 = a1[2] + v4;
    v18 = *(_DWORD **)(a1[9299] + 48LL);
    if ( *(v18 - 1) != 925895004 )
      __break(0x8228u);
    v19 = ((__int64 (__fastcall *)(_QWORD *, __int64))v18)(a1, v17);
LABEL_15:
    writel_7(a3, v19);
    if ( (v7 & 1) != 0 )
      goto LABEL_22;
    goto LABEL_19;
  }
  pld_lock_reg_window(*(_QWORD *)(a1[1] + 40LL), (__int64)&v30);
  v20 = (v4 >> 19) & 0x3F | 0x40000000;
  writel_7(v20, a1[2] + 12920LL);
  v21 = a1[2];
  *((_DWORD *)a1 + 18557) = (v4 >> 19) & 0x3F;
  v22 = readl_8(v21 + 12920);
  if ( v22 != v20 )
  {
    hal_reg_wr_fail_history_add((__int64)a1, 12920, v20, v22);
    if ( a1 )
      ++*((_DWORD *)a1 + 18601);
  }
  writel_7(a3, a1[2] + (v4 & 0x7FFFF) + 0x80000LL);
  pld_unlock_reg_window(*(_QWORD *)(a1[1] + 40LL), (__int64)&v30);
  if ( (v7 & 1) == 0 )
  {
LABEL_19:
    if ( !(unsigned int)hif_force_wake_release(*a1) )
      goto LABEL_22;
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: Wake up release failed",
      result,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "hal_write32_mb",
      v30,
      v31);
LABEL_21:
    qdf_check_state_before_panic(v8, v9, v10, v11, v12, v13, v14, v15);
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
