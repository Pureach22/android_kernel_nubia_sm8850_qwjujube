__int64 __fastcall store_uint(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  unsigned int v7; // w9
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v6 = kstrtouint(a3, 0, &v9);
  if ( v6 )
  {
    a4 = v6;
  }
  else if ( v9 && ((v7 = *(_DWORD *)(a2 + 32)) == 0 || v9 <= v7) )
  {
    **(_DWORD **)(a2 + 40) = v9;
  }
  else
  {
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
