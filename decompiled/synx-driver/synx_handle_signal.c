__int64 __fastcall synx_handle_signal(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 result; // x0
  _QWORD v5[3]; // [xsp+8h] [xbp-18h] BYREF

  v5[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) == 16 )
  {
    v3 = *(_QWORD *)(a1 + 16);
    v5[0] = 0;
    v5[1] = 0;
    if ( inline_copy_from_user((int)v5, v3, 0x10u) )
      result = 4294967282LL;
    else
      result = synx_signal(a2, LODWORD(v5[0]), HIDWORD(v5[0]));
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
