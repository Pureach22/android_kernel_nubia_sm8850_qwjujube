__int64 __fastcall hal_rx_flow_delete_cmem_fse_peach(__int64 a1, int a2, int a3)
{
  __int64 v4; // x22
  unsigned int v5; // w21
  __int64 v6; // x1
  __int64 (__fastcall *v7)(__int64, __int64); // x8
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  __int64 v11; // x1
  unsigned int v12; // w20
  __int64 v13; // x8
  int v14; // w0
  int v15; // w20
  __int64 result; // x0
  unsigned int v17; // w20
  __int64 v18; // x8
  int v19; // w0
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v4 = a1 + 73728;
  v5 = a2 + (a3 << 6) + 36;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  if ( v5 >= 0x80000 && (*(_BYTE *)(a1 + 74224) & 1) != 0 )
  {
    if ( *(_BYTE *)(a1 + 74248) == 1 )
    {
      v6 = *(_QWORD *)(a1 + 16) + v5;
      v7 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 74392) + 48LL);
      if ( *((_DWORD *)v7 - 1) != 925895004 )
        __break(0x8228u);
      v8 = v7(a1, v6);
      if ( !(unsigned int)readl_8(v8) )
        goto LABEL_19;
    }
    else
    {
      pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v20);
      v12 = (v5 >> 19) & 0x3F | 0x40000000;
      writel_7(v12, *(_QWORD *)(a1 + 16) + 12920LL);
      v13 = *(_QWORD *)(a1 + 16);
      *(_DWORD *)(v4 + 500) = (v5 >> 19) & 0x3F;
      v14 = readl_8(v13 + 12920);
      if ( v14 != v12 )
      {
        hal_reg_wr_fail_history_add(a1, 12920, v12, v14);
        if ( a1 )
          ++*(_DWORD *)(v4 + 676);
      }
      v15 = readl_8(*(_QWORD *)(a1 + 16) + (v5 & 0x7FFFF) + 0x80000LL);
      pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v20);
      if ( !v15 )
        goto LABEL_19;
    }
LABEL_9:
    v20[0] = 0;
    if ( v5 >= 0x80000 && (*(_BYTE *)(v4 + 496) & 1) != 0 )
    {
      if ( *(_BYTE *)(v4 + 520) != 1 )
      {
        pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v20);
        v17 = (v5 >> 19) & 0x3F | 0x40000000;
        writel_7(v17, *(_QWORD *)(a1 + 16) + 12920LL);
        v18 = *(_QWORD *)(a1 + 16);
        *(_DWORD *)(v4 + 500) = (v5 >> 19) & 0x3F;
        v19 = readl_8(v18 + 12920);
        if ( v19 != v17 )
        {
          hal_reg_wr_fail_history_add(a1, 12920, v17, v19);
          if ( a1 )
            ++*(_DWORD *)(v4 + 676);
        }
        writel_7(0, *(_QWORD *)(a1 + 16) + (v5 & 0x7FFFF) + 0x80000LL);
        pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL), (__int64)v20);
        goto LABEL_22;
      }
      v9 = *(_QWORD *)(a1 + 16) + v5;
      v10 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v4 + 664) + 48LL);
      if ( *((_DWORD *)v10 - 1) != 925895004 )
        __break(0x8228u);
      v11 = v10(a1, v9);
    }
    else
    {
      v11 = *(_QWORD *)(a1 + 16) + v5;
    }
    writel_7(0, v11);
LABEL_22:
    result = 0;
    goto LABEL_23;
  }
  if ( (unsigned int)readl_8(*(_QWORD *)(a1 + 16) + v5) )
    goto LABEL_9;
LABEL_19:
  result = 17;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
