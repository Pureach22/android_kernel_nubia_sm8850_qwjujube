__int64 __fastcall synx_handle_bind(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 result; // x0
  __int64 v6; // [xsp+0h] [xbp-20h] BYREF
  __int64 v7; // [xsp+8h] [xbp-18h]
  __int64 v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) == 24 )
  {
    v3 = *(_QWORD *)(a1 + 16);
    v7 = 0;
    v8 = 0;
    v6 = 0;
    if ( inline_copy_from_user((int)&v6, v3, 0x18u) )
    {
      result = 4294967282LL;
    }
    else
    {
      result = synx_bind(a2, v6, v7, v8);
      *(_DWORD *)(a1 + 8) = result;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
