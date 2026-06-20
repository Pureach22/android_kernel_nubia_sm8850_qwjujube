__int64 __fastcall emmc_dload_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  _DWORD *v7; // x8
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a1 + 104) )
  {
    v9[0] = 0;
    v6 = kstrtobool(a3, v9);
    if ( v6 < 0 )
    {
      a4 = v6;
    }
    else
    {
      v7 = *(_DWORD **)(a1 + 104);
      if ( v9[0] == 1 )
      {
        if ( v7 )
          *v7 = 2;
      }
      else if ( v7 )
      {
        *v7 = 0;
      }
    }
  }
  else
  {
    a4 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
