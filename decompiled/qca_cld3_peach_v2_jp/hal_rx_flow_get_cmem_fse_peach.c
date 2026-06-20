__int64 __fastcall hal_rx_flow_get_cmem_fse_peach(__int64 result, int a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x23
  __int64 v9; // x0
  unsigned int v10; // w26
  __int64 v11; // x1
  __int64 (__fastcall *v12)(__int64, __int64); // x8
  unsigned int v13; // w21
  __int64 v14; // x8
  int v15; // w0
  unsigned int v16; // w21
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 == 64 )
  {
    v5 = result;
    v6 = 0;
    v7 = result + 73728;
    do
    {
      v10 = a2 + v6;
      v17[0] = 0;
      if ( (unsigned int)(a2 + v6) >= 0x80000 && (*(_BYTE *)(v7 + 496) & 1) != 0 )
      {
        if ( *(_BYTE *)(v7 + 520) != 1 )
        {
          pld_lock_reg_window(*(_QWORD *)(*(_QWORD *)(v5 + 8) + 40LL), (__int64)v17);
          v13 = (v10 >> 19) & 0x3F | 0x40000000;
          writel_7(v13, *(_QWORD *)(v5 + 16) + 12920LL);
          v14 = *(_QWORD *)(v5 + 16);
          *(_DWORD *)(v7 + 500) = (v10 >> 19) & 0x3F;
          v15 = readl_8(v14 + 12920);
          if ( v15 != v13 )
          {
            hal_reg_wr_fail_history_add(v5, 12920, v13, v15);
            if ( v5 )
              ++*(_DWORD *)(v7 + 676);
          }
          v16 = readl_8(*(_QWORD *)(v5 + 16) + (v10 & 0x7FFFF) + 0x80000LL);
          pld_unlock_reg_window(*(_QWORD *)(*(_QWORD *)(v5 + 8) + 40LL), (__int64)v17);
          result = v16;
          goto LABEL_5;
        }
        v11 = *(_QWORD *)(v5 + 16) + v10;
        v12 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 664) + 48LL);
        if ( *((_DWORD *)v12 - 1) != 925895004 )
          __break(0x8228u);
        v9 = v12(v5, v11);
      }
      else
      {
        v9 = *(_QWORD *)(v5 + 16) + v10;
      }
      result = readl_8(v9);
LABEL_5:
      *(_DWORD *)(a3 + v6) = result;
      v6 += 4;
    }
    while ( v6 != 64 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
