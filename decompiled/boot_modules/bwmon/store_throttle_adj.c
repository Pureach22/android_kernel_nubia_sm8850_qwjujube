__int64 __fastcall store_throttle_adj(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 (*v7)(void); // x8
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(*(_QWORD *)(a1 - 8) + 40LL) )
  {
    v8 = 0;
    LODWORD(result) = kstrtouint(a3, 10, &v8);
    if ( (result & 0x80000000) != 0 )
    {
      result = (int)result;
    }
    else
    {
      v7 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 8) + 40LL);
      if ( *((_DWORD *)v7 - 1) != -1874162456 )
        __break(0x8228u);
      LODWORD(result) = v7();
      if ( (_DWORD)result )
        result = (int)result;
      else
        result = a4;
    }
  }
  else
  {
    result = -1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
