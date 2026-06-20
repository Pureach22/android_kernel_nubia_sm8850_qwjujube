__int64 __fastcall synx_handle_recover(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x1
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) == 8 )
  {
    v3 = *(_QWORD *)(a1 + 16);
    v6[0] = 0;
    if ( inline_copy_from_user((int)v6, v3, 8u) )
    {
      result = 4294967282LL;
    }
    else
    {
      result = synx_recover(*a2);
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
