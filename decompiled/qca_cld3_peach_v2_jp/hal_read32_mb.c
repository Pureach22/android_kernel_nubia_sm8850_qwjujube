__int64 __fastcall hal_read32_mb(__int64 *a1, unsigned int a2)
{
  __int64 *v2; // x22
  char v5; // w21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v14; // x2
  __int64 v15; // x1
  __int64 (__fastcall *v16)(__int64 *, __int64); // x8
  __int64 v17; // x0
  __int64 result; // x0
  __int64 v19; // x9
  unsigned int v20; // w0
  unsigned int v21; // w20
  __int64 v22; // x8
  unsigned int v23; // w19
  int v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // [xsp+0h] [xbp-10h] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v2 = a1 + 9216;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((_BYTE *)a1 + 74400);
  v33 = 0;
  if ( (v5 & 1) == 0 && (unsigned int)hif_force_wake_request(*a1) )
  {
    v14 = "%s: Wake up request failed";
LABEL_16:
    qdf_trace_msg(0x46u, 2u, v14, v6, v7, v8, v9, v10, v11, v12, v13, "hal_read32_mb", v33, v34);
    qdf_check_state_before_panic(v25, v26, v27, v28, v29, v30, v31, v32);
    result = 0;
    goto LABEL_17;
  }
  if ( (v2[62] & 1) != 0 )
  {
    if ( *((_BYTE *)v2 + 520) == 1 )
    {
      v15 = a1[2] + a2;
      v16 = *(__int64 (__fastcall **)(__int64 *, __int64))(v2[83] + 48);
      if ( *((_DWORD *)v16 - 1) != 925895004 )
        __break(0x8228u);
      v17 = v16(a1, v15);
      result = readl_6(v17);
      if ( (v5 & 1) != 0 )
        goto LABEL_17;
    }
    else
    {
      pld_lock_reg_window(*(_QWORD *)(a1[1] + 40), (__int64)&v33);
      writel_5(1073741844, a1[2] + 12920);
      v19 = a1[2];
      *((_DWORD *)v2 + 125) = 20;
      v20 = readl_6(v19 + 12920);
      if ( v20 != 1073741844 )
      {
        hal_reg_wr_fail_history_add(a1, 12920, 1073741844, v20);
        if ( a1 )
          ++*((_DWORD *)v2 + 169);
      }
      v21 = readl_6(a1[2] + (a2 & 0x7FFFF) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1[1] + 40), (__int64)&v33);
      result = v21;
      if ( (v5 & 1) != 0 )
        goto LABEL_17;
    }
  }
  else
  {
    result = readl_6(a1[2] + a2);
    if ( (v5 & 1) != 0 )
      goto LABEL_17;
  }
  v22 = *a1;
  v23 = result;
  v24 = hif_force_wake_release(v22);
  result = v23;
  if ( v24 )
  {
    v14 = "%s: Wake up release failed";
    goto LABEL_16;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
