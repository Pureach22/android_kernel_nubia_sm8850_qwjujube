__int64 __fastcall charge_control_en_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w10
  unsigned int v7; // w0
  unsigned int v9; // w21
  _BYTE v10[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h] BYREF
  int v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+1Ch] [xbp-14h]
  int v14; // [xsp+24h] [xbp-Ch]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  if ( (unsigned int)kstrtobool(a3, v10) )
  {
    a4 = -22;
  }
  else if ( v10[0] != *(unsigned __int8 *)(a1 + 1135) )
  {
    v14 = v10[0];
    v6 = *(_DWORD *)(a1 + 384);
    v13 = 0x1800000000LL;
    v11 = 0x10000800ALL;
    v12 = v6;
    v7 = battery_chg_write(a1 - 8, (__int64)&v11, 0x18u, 0x3E8u);
    if ( (v7 & 0x80000000) != 0 )
    {
      v9 = v7;
      printk(&unk_11087, "charge_control_en_store", v7);
      a4 = (int)v9;
    }
    else
    {
      *(_BYTE *)(a1 + 1135) = v10[0];
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
