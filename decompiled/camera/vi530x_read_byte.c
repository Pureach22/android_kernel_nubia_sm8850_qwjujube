__int64 __fastcall vi530x_read_byte(__int64 a1, char a2, __int64 a3)
{
  __int64 v3; // x19
  __int16 v4; // w8
  __int64 v5; // x0
  __int64 result; // x0
  unsigned int v7; // w8
  int v8; // w19
  char v9; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-28h] BYREF
  char *v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 96);
  v9 = a2;
  if ( v3 )
  {
    v11 = nullptr;
    v12 = 0;
    v10 = 0;
    v4 = *(_WORD *)(v3 + 2);
    v13 = a3;
    v5 = *(_QWORD *)(v3 + 24);
    v11 = &v9;
    LOWORD(v10) = v4;
    LOWORD(v12) = v4;
    WORD2(v10) = 1;
    *(_DWORD *)((char *)&v12 + 2) = 65537;
    LODWORD(result) = i2c_transfer(v5, &v10, 2);
    if ( (_DWORD)result == 2 )
    {
      v7 = 0;
    }
    else
    {
      v8 = result;
      printk(&unk_3E019C);
      LODWORD(result) = v8;
      v7 = -5;
    }
    if ( (int)result >= 0 )
      result = v7;
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
