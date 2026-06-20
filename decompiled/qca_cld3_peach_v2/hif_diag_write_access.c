__int64 __fastcall hif_diag_write_access(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v6; // x8
  __int64 v7; // x1
  __int64 v8; // x8
  unsigned int v9; // w22
  unsigned int v10; // w21
  __int64 v11; // x8
  int v12; // w0
  __int64 result; // x0
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 616) + 268LL) <= a2 )
  {
    LODWORD(v14[0]) = a3;
    result = hif_diag_write_mem(a1, a2, (int)v14, 4u);
  }
  else if ( (hif_target_sleep_state_adjust(a1, 0, 1) & 0x80000000) != 0 )
  {
    result = 16;
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 40);
    v14[0] = 0;
    v7 = v6 + a2;
    v8 = *(_QWORD *)(a1 + 30720);
    if ( *(_BYTE *)(a1 + 31089) == 1 && (v9 = v7 - v8, (unsigned int)(v7 - v8) >> 19) )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v14);
      v10 = (v9 >> 19) & 0x3F | 0x40000000;
      writel(v10, *(_QWORD *)(a1 + 30720) + 12920LL);
      v11 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v9 >> 19) & 0x3F;
      v12 = readl(v11 + 12920);
      if ( v12 != v10 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v10,
          v12,
          12920);
      writel(a3, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v9 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v14);
    }
    else
    {
      writel(a3, v7);
    }
    result = ((unsigned int)hif_target_sleep_state_adjust(a1, 1, 0) >> 27) & 0x10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
