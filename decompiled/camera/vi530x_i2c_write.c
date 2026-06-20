__int64 __fastcall vi530x_i2c_write(__int64 a1, char a2, const void *a3, unsigned __int8 a4)
{
  __int64 v4; // x24
  unsigned __int64 v8; // x23
  _BYTE *v9; // x20
  unsigned __int16 v10; // w8
  __int64 v11; // x0
  int v12; // w21
  unsigned int v13; // w22
  __int64 result; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v16; // x26
  _QWORD v17[3]; // [xsp+8h] [xbp-18h] BYREF

  v17[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  if ( v4 )
  {
    v17[0] = 0;
    v8 = a4;
    v9 = (_BYTE *)_kmalloc_noprof(a4 + 1LL, 3264);
    if ( v9 )
    {
      while ( 1 )
      {
        *v9 = a2;
        if ( v8 >= a4 )
          break;
        _fortify_panic(17, v8, a4);
        StatusReg = _ReadStatusReg(SP_EL0);
        v16 = *(_QWORD *)(StatusReg + 80);
        v8 = a4;
        *(_QWORD *)(StatusReg + 80) = &vi530x_i2c_write__alloc_tag;
        v9 = (_BYTE *)_kmalloc_noprof(a4 + 1LL, 3264);
        *(_QWORD *)(StatusReg + 80) = v16;
        if ( !v9 )
          goto LABEL_11;
      }
      memcpy(v9 + 1, a3, a4);
      v10 = *(_WORD *)(v4 + 2);
      v11 = *(_QWORD *)(v4 + 24);
      v17[1] = v9;
      LODWORD(v17[0]) = v10;
      WORD2(v17[0]) = a4 + 1;
      v12 = i2c_transfer(v11, v17, 1);
      v13 = 0;
      if ( v12 != 1 )
      {
        printk(&unk_3E019C);
        v13 = -5;
      }
      kfree(v9);
      if ( v12 >= 0 )
        result = v13;
      else
        result = (unsigned int)v12;
    }
    else
    {
LABEL_11:
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
