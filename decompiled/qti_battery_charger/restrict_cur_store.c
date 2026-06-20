__int64 __fastcall restrict_cur_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v6; // w8
  unsigned int v7; // w9
  int v9; // w10
  int v10; // w23
  unsigned int v11; // w21
  int v12; // w8
  int v13; // w0
  int v14; // w22
  unsigned int v15; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v16; // [xsp+10h] [xbp-20h] BYREF
  int v17; // [xsp+18h] [xbp-18h]
  __int64 v18; // [xsp+1Ch] [xbp-14h]
  unsigned int v19; // [xsp+24h] [xbp-Ch]
  __int64 v20; // [xsp+28h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  if ( (unsigned int)kstrtouint(a3, 0, &v15) || (v6 = v15, v7 = *(_DWORD *)(a1 + 1112), v15 > v7) )
  {
    a4 = -22;
  }
  else
  {
    v9 = *(unsigned __int8 *)(a1 + 1132);
    v10 = *(_DWORD *)(a1 + 1116);
    *(_DWORD *)(a1 + 1116) = v15;
    if ( v9 == 1 )
    {
      if ( v6 >= v7 )
        v11 = v7;
      else
        v11 = v6;
      v12 = *(_DWORD *)(a1 + 384);
      v18 = 0xA00000000LL;
      v16 = 0x10000800ALL;
      v19 = v11;
      v17 = v12;
      v13 = battery_chg_write(a1 - 8, (__int64)&v16, 0x18u, 0x3E8u);
      if ( v13 < 0 )
      {
        v14 = v13;
        printk(&unk_FE40, "__battery_psy_set_charge_current", v11);
        a4 = v14;
        *(_DWORD *)(a1 + 1116) = v10;
      }
      else
      {
        *(_DWORD *)(a1 + 1120) = v11;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
