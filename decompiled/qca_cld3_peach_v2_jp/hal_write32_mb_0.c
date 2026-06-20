__int64 __fastcall hal_write32_mb_0(_QWORD *a1, unsigned int a2, unsigned int a3)
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
  __int64 v16; // x20
  __int64 v17; // x1
  _DWORD *v18; // x8
  __int64 v19; // x1
  unsigned int v20; // w22
  __int64 v21; // x8
  int v22; // w0
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

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  if ( a2 <= 0xFDF )
  {
    result = writel_6(a3, a1[2] + a2);
    goto LABEL_22;
  }
  v7 = *((_BYTE *)a1 + 74400);
  if ( (v7 & 1) == 0 && (unsigned int)hif_force_wake_request(*a1) )
  {
    v16 = jiffies;
    if ( hal_write32_mb___last_ticks_0 - jiffies + 125 < 0 )
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
      hal_write32_mb___last_ticks_0 = v16;
    }
    goto LABEL_21;
  }
  if ( a2 < 0x80000 || (a1[9278] & 1) == 0 )
  {
    v19 = a1[2] + a2;
    goto LABEL_15;
  }
  if ( *((_BYTE *)a1 + 74248) == 1 )
  {
    v17 = a1[2] + a2;
    v18 = *(_DWORD **)(a1[9299] + 48LL);
    if ( *(v18 - 1) != 925895004 )
      __break(0x8228u);
    v19 = ((__int64 (__fastcall *)(_QWORD *, __int64))v18)(a1, v17);
LABEL_15:
    result = writel_6(a3, v19);
    if ( (v7 & 1) != 0 )
      goto LABEL_22;
    goto LABEL_19;
  }
  pld_lock_reg_window(*(_QWORD *)(a1[1] + 40LL), (__int64)&v31);
  v20 = (a2 >> 19) & 0x3F | 0x40000000;
  writel_6(v20, a1[2] + 12920LL);
  v21 = a1[2];
  *((_DWORD *)a1 + 18557) = (a2 >> 19) & 0x3F;
  v22 = readl_7(v21 + 12920);
  if ( v22 != v20 )
  {
    hal_reg_wr_fail_history_add((__int64)a1, 12920, v20, v22);
    if ( a1 )
      ++*((_DWORD *)a1 + 18601);
  }
  writel_6(a3, a1[2] + (a2 & 0x7FFFF) + 0x80000LL);
  result = pld_unlock_reg_window(*(_QWORD *)(a1[1] + 40LL), (__int64)&v31);
  if ( (v7 & 1) == 0 )
  {
LABEL_19:
    result = hif_force_wake_release(*a1);
    if ( !(_DWORD)result )
      goto LABEL_22;
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
LABEL_21:
    result = qdf_check_state_before_panic(v8, v9, v10, v11, v12, v13, v14, v15);
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
