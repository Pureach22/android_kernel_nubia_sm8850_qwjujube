__int64 __fastcall i2c_r_bytes(__int64 a1, char a2, __int64 a3, __int16 a4)
{
  __int64 v4; // x8
  __int16 v5; // w10
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // w19
  char v9; // [xsp+4h] [xbp-2Ch] BYREF
  __int16 v10; // [xsp+8h] [xbp-28h] BYREF
  int v11; // [xsp+Ah] [xbp-26h]
  __int16 v12; // [xsp+Eh] [xbp-22h]
  char *v13; // [xsp+10h] [xbp-20h]
  __int16 v14; // [xsp+18h] [xbp-18h]
  __int16 v15; // [xsp+1Ah] [xbp-16h]
  __int16 v16; // [xsp+1Ch] [xbp-14h]
  __int16 v17; // [xsp+1Eh] [xbp-12h]
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 808);
  v9 = a2;
  v5 = *(_WORD *)(v4 + 2);
  v18 = a3;
  v11 = 0x10000;
  v6 = *(_QWORD *)(v4 + 24);
  v13 = &v9;
  v12 = 0;
  v15 = 1;
  v10 = v5;
  v14 = v5;
  v16 = a4;
  v17 = 0;
  result = i2c_transfer(v6, &v10, 2);
  if ( (result & 0x80000000) != 0 )
  {
    v8 = result;
    printk(&unk_147C9, "haptic_hv", 101, "i2c_r_bytes");
    result = v8;
  }
  else if ( (_DWORD)result != 2 )
  {
    printk(&unk_154F2, "haptic_hv", 104, "i2c_r_bytes");
    result = 4294967290LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
