__int64 __fastcall cam_sync_handle_wait(__int64 a1)
{
  __int64 v1; // x1
  __int64 result; // x0
  int v4; // w8
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  __int64 v6; // [xsp+10h] [xbp-10h]
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) == 16 && (v1 = *(_QWORD *)(a1 + 16)) != 0 )
  {
    v5 = 0;
    v6 = 0;
    if ( inline_copy_from_user_2((int)&v5, v1, 0x10u) )
    {
      result = 4294967282LL;
    }
    else
    {
      v4 = cam_sync_wait(v5, v6);
      result = 0;
      *(_DWORD *)(a1 + 8) = v4;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
