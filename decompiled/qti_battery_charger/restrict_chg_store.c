__int64 __fastcall restrict_chg_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  int v7; // w8
  __int64 v8; // x9
  bool v9; // zf
  unsigned int v10; // w21
  unsigned int v11; // w8
  int v12; // w10
  int v13; // w22
  _BYTE v14[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h] BYREF
  int v16; // [xsp+18h] [xbp-18h]
  __int64 v17; // [xsp+1Ch] [xbp-14h]
  unsigned int v18; // [xsp+24h] [xbp-Ch]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  if ( (unsigned int)kstrtobool(a3, v14) )
  {
    result = -22;
  }
  else
  {
    v7 = v14[0];
    v8 = 1112;
    v9 = v14[0] == 0;
    *(_BYTE *)(a1 + 1132) = v14[0];
    if ( !v9 )
      v8 = 1116;
    v10 = *(_DWORD *)(a1 + v8);
    if ( v7 )
    {
      v11 = *(_DWORD *)(a1 + 1116);
      if ( v11 >= v10 )
        v11 = *(_DWORD *)(a1 + v8);
      if ( v11 >= *(_DWORD *)(a1 + 1112) )
        v10 = *(_DWORD *)(a1 + 1112);
      else
        v10 = v11;
    }
    v12 = *(_DWORD *)(a1 + 384);
    v18 = v10;
    v17 = 0xA00000000LL;
    v15 = 0x10000800ALL;
    v16 = v12;
    v13 = battery_chg_write(a1 - 8, (__int64)&v15, 0x18u, 0x3E8u);
    if ( v13 < 0 )
      printk(&unk_FE40, "__battery_psy_set_charge_current", v10);
    else
      *(_DWORD *)(a1 + 1120) = v10;
    if ( v13 >= 0 )
      result = a4;
    else
      result = v13;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
