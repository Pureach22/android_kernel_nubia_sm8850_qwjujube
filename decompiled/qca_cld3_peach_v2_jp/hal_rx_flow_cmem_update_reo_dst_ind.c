__int64 __fastcall hal_rx_flow_cmem_update_reo_dst_ind(__int64 a1, int a2, int a3, char a4)
{
  __int64 v6; // x23
  unsigned int v7; // w22
  __int64 v8; // x1
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x0
  int v11; // w0
  unsigned int v12; // w21
  __int64 v13; // x8
  int v14; // w0
  int v15; // w21
  __int64 v16; // x0
  unsigned int v17; // w20
  __int64 v18; // x1
  __int64 (__fastcall *v19)(__int64, __int64); // x8
  __int64 v20; // x0
  __int64 result; // x0
  unsigned int v22; // w21
  __int64 v23; // x8
  int v24; // w0
  _QWORD v25[2]; // [xsp+0h] [xbp-10h] BYREF

  v6 = a1 + 73728;
  v7 = a2 + (a3 << 6) + 36;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  if ( v7 >= 0x80000 && (*(_BYTE *)(a1 + 74224) & 1) != 0 )
  {
    if ( *(_BYTE *)(a1 + 74248) == 1 )
    {
      v8 = *(_QWORD *)(a1 + 16) + v7;
      v9 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 74392) + 48LL);
      if ( *((_DWORD *)v9 - 1) != 925895004 )
        __break(0x8228u);
      v10 = v9(a1, v8);
      v11 = readl_8(v10);
    }
    else
    {
      pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v25);
      v12 = (v7 >> 19) & 0x3F | 0x40000000;
      writel_7(v12, *(_QWORD *)(a1 + 16) + 12920LL);
      v13 = *(_QWORD *)(a1 + 16);
      *(_DWORD *)(v6 + 500) = (v7 >> 19) & 0x3F;
      v14 = readl_8(v13 + 12920);
      if ( v14 != v12 )
      {
        hal_reg_wr_fail_history_add(a1, 12920, v12, v14);
        if ( a1 )
          ++*(_DWORD *)(v6 + 676);
      }
      v15 = readl_8(*(_QWORD *)(a1 + 16) + (v7 & 0x7FFFF) + 0x80000LL);
      pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v25);
      v11 = v15;
    }
  }
  else
  {
    v11 = readl_8(*(_QWORD *)(a1 + 16) + v7);
  }
  v16 = v11 & 0xE0FFFFFF | ((a4 & 0x1F) << 24);
  v25[0] = 0;
  if ( v7 >= 0x80000 && (*(_BYTE *)(v6 + 496) & 1) != 0 )
  {
    v17 = v16;
    if ( *(_BYTE *)(v6 + 520) == 1 )
    {
      v18 = *(_QWORD *)(a1 + 16) + v7;
      v19 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v6 + 664) + 48LL);
      if ( *((_DWORD *)v19 - 1) != 925895004 )
        __break(0x8228u);
      v20 = v19(a1, v18);
      result = writel_7(v17, v20);
    }
    else
    {
      pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v25);
      v22 = (v7 >> 19) & 0x3F | 0x40000000;
      writel_7(v22, *(_QWORD *)(a1 + 16) + 12920LL);
      v23 = *(_QWORD *)(a1 + 16);
      *(_DWORD *)(v6 + 500) = (v7 >> 19) & 0x3F;
      v24 = readl_8(v23 + 12920);
      if ( v24 != v22 )
      {
        hal_reg_wr_fail_history_add(a1, 12920, v22, v24);
        if ( a1 )
          ++*(_DWORD *)(v6 + 676);
      }
      writel_7(v17, *(_QWORD *)(a1 + 16) + (v7 & 0x7FFFF) + 0x80000LL);
      result = pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v25);
    }
  }
  else
  {
    result = writel_7(v16, *(_QWORD *)(a1 + 16) + v7);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
