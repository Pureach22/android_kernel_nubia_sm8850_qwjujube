__int64 __fastcall synx_handle_release(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 result; // x0
  _QWORD v5[8]; // [xsp+0h] [xbp-50h] BYREF
  unsigned int v6; // [xsp+40h] [xbp-10h]
  __int64 v7; // [xsp+48h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) == 68 )
  {
    v3 = *(_QWORD *)(a1 + 16);
    v6 = 0;
    memset(v5, 0, sizeof(v5));
    if ( inline_copy_from_user((int)v5, v3, 0x44u) )
      result = 4294967282LL;
    else
      result = synx_release(a2, v6);
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
