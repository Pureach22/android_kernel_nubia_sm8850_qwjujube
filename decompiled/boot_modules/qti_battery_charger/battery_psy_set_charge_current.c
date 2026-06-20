__int64 __fastcall battery_psy_set_charge_current(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned int v3; // w20
  __int64 result; // x0
  __int64 v5; // x19
  int v6; // w9
  unsigned int v7; // w21
  int v8; // w0
  int v9; // w8
  int v10; // w9
  __int64 v11; // x2
  int v12; // w8
  unsigned int v13; // w8
  unsigned int v14; // w21
  unsigned int v15; // w7
  unsigned int v16; // w20
  int v17; // w22
  unsigned int v18; // w8
  int v19; // w10
  unsigned int v20; // w21
  __int64 v21; // [xsp+10h] [xbp-20h] BYREF
  int v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+1Ch] [xbp-14h]
  unsigned int v24; // [xsp+24h] [xbp-Ch]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 548);
  if ( !v3 )
  {
    result = 0;
    goto LABEL_6;
  }
  if ( (v3 & 0x80000000) != 0 )
  {
    printk(&unk_FEBB, "battery_psy_set_charge_current", a3);
    result = 4294967274LL;
    goto LABEL_6;
  }
  if ( v3 < a2 )
  {
    result = 4294967274LL;
    goto LABEL_6;
  }
  v5 = a1;
  *(_DWORD *)(a1 + 544) = a2;
  if ( v3 >= 0x28 )
  {
    v6 = *(_DWORD *)(a1 + 484);
    v7 = a2;
    v23 = 0;
    v24 = 0;
    v21 = 0x10000800ALL;
    v22 = v6;
    v8 = battery_chg_write(a1, (__int64)&v21, 0x18u, 0x3E8u);
    a2 = v7;
    v9 = v8;
    a1 = v5;
    v10 = 0;
    if ( !v9 )
    {
      if ( **(_DWORD **)(v5 + 472) )
        v10 = 20;
      else
        v10 = 0;
    }
    goto LABEL_15;
  }
  if ( v3 > 0x13 )
  {
    v10 = 0;
LABEL_15:
    v11 = *(unsigned int *)(a1 + 548);
    v12 = v10 | 0xA;
    if ( !*(_BYTE *)(a1 + 1052) )
      v12 = v10;
    goto LABEL_18;
  }
  v12 = 0;
  v11 = v3;
LABEL_18:
  v13 = v12 + a2;
  v14 = a2;
  if ( a2 )
    v15 = v13;
  else
    v15 = 0;
  v16 = *(_DWORD *)(*(_QWORD *)(a1 + 528) + 4LL * (int)v15);
  printk(&unk_10AFC, "battery_get_fcc_by_thermal_level", v11);
  v17 = *(_DWORD *)(v5 + 1120);
  *(_DWORD *)(v5 + 1120) = v16;
  printk(&unk_102D2, "battery_psy_set_charge_current", v14);
  if ( *(_BYTE *)(v5 + 1140) == 1 )
  {
    v18 = *(_DWORD *)(v5 + 1124);
    if ( v18 >= v16 )
      v18 = v16;
    if ( v18 >= *(_DWORD *)(v5 + 1120) )
      v16 = *(_DWORD *)(v5 + 1120);
    else
      v16 = v18;
  }
  v19 = *(_DWORD *)(v5 + 392);
  v24 = v16;
  v23 = 0xA00000000LL;
  v21 = 0x10000800ALL;
  v22 = v19;
  result = battery_chg_write(v5, (__int64)&v21, 0x18u, 0x3E8u);
  if ( (result & 0x80000000) != 0 )
  {
    v20 = result;
    printk(&unk_FE40, "__battery_psy_set_charge_current", v16);
    result = v20;
  }
  else
  {
    *(_DWORD *)(v5 + 1128) = v16;
    if ( !(_DWORD)result )
    {
      *(_DWORD *)(v5 + 544) = v14;
      goto LABEL_6;
    }
  }
  *(_DWORD *)(v5 + 1120) = v17;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
