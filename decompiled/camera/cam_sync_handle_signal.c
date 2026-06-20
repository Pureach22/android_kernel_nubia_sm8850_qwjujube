__int64 __fastcall cam_sync_handle_signal(__int64 a1)
{
  __int64 v1; // x1
  __int64 result; // x0
  unsigned int v3; // [xsp+Ch] [xbp-14h]
  _QWORD v4[2]; // [xsp+10h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) == 8 && (v1 = *(_QWORD *)(a1 + 16)) != 0 )
  {
    v4[0] = 0;
    if ( inline_copy_from_user_2((int)v4, v1, 8u) )
    {
      result = 4294967282LL;
    }
    else
    {
      result = cam_sync_get_obj_ref(v4[0]);
      if ( (_DWORD)result )
      {
        if ( (debug_mdl & 0x80) != 0 && !debug_priority )
        {
          v3 = result;
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            (unsigned __int8)debug_mdl & 0x80,
            4,
            "cam_sync_handle_signal",
            731,
            "Error: cannot signal an uninitialized sync obj = %d",
            LODWORD(v4[0]));
          result = v3;
        }
      }
      else
      {
        result = cam_sync_signal(v4[0], HIDWORD(v4[0]), 6u);
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
