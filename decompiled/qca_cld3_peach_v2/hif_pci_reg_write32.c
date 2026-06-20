__int64 __fastcall hif_pci_reg_write32(__int64 a1, unsigned int a2, unsigned int a3)
{
  _QWORD *v5; // x19
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
  unsigned int v19; // w22
  __int64 v20; // x8
  int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // [xsp+0h] [xbp-10h] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD **)(a1 + 2560);
  v30 = 0;
  if ( a2 <= 0xFDF )
  {
    result = writel_8(a3);
    goto LABEL_21;
  }
  v7 = *((_BYTE *)v5 + 74400);
  if ( (v7 & 1) == 0 && (unsigned int)hif_force_wake_request(*v5) )
  {
    v16 = jiffies;
    if ( hal_write32_mb___last_ticks_2 - jiffies + 125 < 0 )
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
      hal_write32_mb___last_ticks_2 = v16;
    }
    goto LABEL_20;
  }
  if ( a2 < 0x80000 || (v5[9278] & 1) == 0 )
    goto LABEL_14;
  if ( *((_BYTE *)v5 + 74248) == 1 )
  {
    v17 = v5[2] + a2;
    v18 = *(_DWORD **)(v5[9299] + 48LL);
    if ( *(v18 - 1) != 925895004 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v18)(v5, v17);
LABEL_14:
    result = writel_8(a3);
    if ( (v7 & 1) != 0 )
      goto LABEL_21;
    goto LABEL_18;
  }
  pld_lock_reg_window(*(_QWORD *)(v5[1] + 40LL), (__int64)&v30);
  v19 = (a2 >> 19) & 0x3F | 0x40000000;
  writel_8(v19);
  v20 = v5[2];
  *((_DWORD *)v5 + 18557) = (a2 >> 19) & 0x3F;
  v21 = readl_9(v20 + 12920);
  if ( v21 != v19 )
  {
    hal_reg_wr_fail_history_add((__int64)v5, 12920, v19, v21);
    if ( v5 )
      ++*((_DWORD *)v5 + 18601);
  }
  writel_8(a3);
  result = pld_unlock_reg_window(*(_QWORD *)(v5[1] + 40LL), (__int64)&v30);
  if ( (v7 & 1) == 0 )
  {
LABEL_18:
    result = hif_force_wake_release(*v5);
    if ( !(_DWORD)result )
      goto LABEL_21;
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: Wake up release failed",
      v22,
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
LABEL_20:
    result = qdf_check_state_before_panic(v8, v9, v10, v11, v12, v13, v14, v15);
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
