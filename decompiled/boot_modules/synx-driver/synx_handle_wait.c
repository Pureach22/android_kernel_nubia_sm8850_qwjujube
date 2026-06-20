__int64 __fastcall synx_handle_wait(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 result; // x0
  int v6; // w8
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  __int64 v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) == 16 )
  {
    v3 = *(_QWORD *)(a1 + 16);
    v7 = 0;
    v8 = 0;
    if ( inline_copy_from_user((int)&v7, v3, 0x10u) )
    {
      result = 4294967282LL;
    }
    else
    {
      v6 = synx_wait(a2, (unsigned int)v7, v8);
      result = 0;
      *(_DWORD *)(a1 + 8) = v6;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
