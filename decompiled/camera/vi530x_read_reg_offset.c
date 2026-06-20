__int64 __fastcall vi530x_read_reg_offset(__int64 a1, char a2, char a3, __int64 a4)
{
  __int64 v4; // x19
  __int16 v5; // w8
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // w8
  int v9; // w19
  char v10; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-28h] BYREF
  char *v12; // [xsp+10h] [xbp-20h]
  __int64 v13; // [xsp+18h] [xbp-18h]
  __int64 v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  v10 = a3 + a2;
  if ( v4 )
  {
    v12 = nullptr;
    v13 = 0;
    v11 = 0;
    v5 = *(_WORD *)(v4 + 2);
    v14 = a4;
    v6 = *(_QWORD *)(v4 + 24);
    v12 = &v10;
    LOWORD(v11) = v5;
    LOWORD(v13) = v5;
    WORD2(v11) = 1;
    *(_DWORD *)((char *)&v13 + 2) = 65537;
    LODWORD(result) = i2c_transfer(v6, &v11, 2);
    if ( (_DWORD)result == 2 )
    {
      v8 = 0;
    }
    else
    {
      v9 = result;
      printk(&unk_3E019C);
      LODWORD(result) = v9;
      v8 = -5;
    }
    if ( (int)result >= 0 )
      result = v8;
    else
      result = (unsigned int)result;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
