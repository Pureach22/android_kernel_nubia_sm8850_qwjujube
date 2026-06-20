__int64 __fastcall hal_rx_flow_get_cmem_fse_ts_peach(__int64 a1, int a2)
{
  unsigned int v2; // w21
  __int64 v4; // x1
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // w20
  __int64 v9; // x8
  int v10; // w0
  unsigned int v11; // w0
  __int64 v12; // x8
  unsigned int v13; // w19
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = a2 + 52;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  if ( (unsigned int)(a2 + 52) >= 0x80000 && (*(_BYTE *)(a1 + 74224) & 1) != 0 )
  {
    if ( *(_BYTE *)(a1 + 74248) == 1 )
    {
      v4 = *(_QWORD *)(a1 + 16) + v2;
      v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 74392) + 48LL);
      if ( *((_DWORD *)v5 - 1) != 925895004 )
        __break(0x8228u);
      v6 = v5(a1, v4);
      result = readl_8(v6);
    }
    else
    {
      pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v14);
      v8 = (v2 >> 19) & 0x3F | 0x40000000;
      writel_7(v8, *(_QWORD *)(a1 + 16) + 12920LL);
      v9 = *(_QWORD *)(a1 + 16);
      *(_DWORD *)(a1 + 74228) = (v2 >> 19) & 0x3F;
      v10 = readl_8(v9 + 12920);
      if ( v10 != v8 )
      {
        hal_reg_wr_fail_history_add(a1, 12920, v8, v10);
        if ( a1 )
          ++*(_DWORD *)(a1 + 74404);
      }
      v11 = readl_8(*(_QWORD *)(a1 + 16) + (v2 & 0x7FFFF) + 0x80000LL);
      v12 = *(_QWORD *)(a1 + 8);
      v13 = v11;
      pld_unlock_reg_window(*(_QWORD *)(v12 + 40), (__int64)v14);
      result = v13;
    }
  }
  else
  {
    result = readl_8(*(_QWORD *)(a1 + 16) + v2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
