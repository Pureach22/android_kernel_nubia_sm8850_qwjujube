__int64 __fastcall sde_i2c_byte_read(__int64 a1, unsigned __int8 a2, char a3, __int64 a4)
{
  __int64 v4; // x0
  __int64 result; // x0
  char v6; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v7[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v8; // [xsp+18h] [xbp-18h]
  __int64 v9; // [xsp+20h] [xbp-10h]
  __int64 v10; // [xsp+28h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v6 = a3;
  v7[1] = &v6;
  v7[0] = a2 >> 1;
  v9 = a4;
  v8 = v7[0];
  WORD2(v7[0]) = 1;
  *(_DWORD *)((char *)&v8 + 2) = 65537;
  if ( (int)i2c_transfer(v4, v7, 2) <= 0 )
  {
    printk(&unk_221455, "sde_i2c_byte_read");
    result = 4294967283LL;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
