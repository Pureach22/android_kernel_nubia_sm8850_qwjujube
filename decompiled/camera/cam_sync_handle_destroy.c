__int64 __fastcall cam_sync_handle_destroy(__int64 a1)
{
  __int64 v1; // x1
  __int64 result; // x0
  _QWORD v3[8]; // [xsp+0h] [xbp-50h] BYREF
  unsigned int v4; // [xsp+40h] [xbp-10h]
  __int64 v5; // [xsp+48h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) == 68 && (v1 = *(_QWORD *)(a1 + 16)) != 0 )
  {
    v4 = 0;
    memset(v3, 0, sizeof(v3));
    if ( inline_copy_from_user_2((int)v3, v1, 0x44u) )
      result = 4294967282LL;
    else
      result = cam_sync_deinit_object(*(_QWORD *)(sync_dev + 128), v4, 0, 0);
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
