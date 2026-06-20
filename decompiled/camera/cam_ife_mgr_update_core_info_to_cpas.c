__int64 __fastcall cam_ife_mgr_update_core_info_to_cpas(__int64 a1, char a2)
{
  _QWORD *v2; // x21
  _QWORD *v3; // x22
  __int64 result; // x0
  int v7; // w0
  int v8; // w7
  unsigned int v9; // w19
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_QWORD *)(a1 + 208);
  v3 = *(_QWORD **)(a1 + 208);
  if ( v3 == (_QWORD *)(a1 + 208) )
  {
LABEL_13:
    result = 0;
  }
  else
  {
    v10[0] = 0;
    while ( 1 )
    {
      if ( v3[4] )
      {
        result = cam_ife_mgr_find_core_idx(0, a1, 0, v10);
        if ( (_DWORD)result )
          goto LABEL_14;
        result = cam_ife_mgr_find_core_idx(result, a1, 7, (char *)v10 + 4);
        if ( (_DWORD)result )
          goto LABEL_14;
        v7 = cam_cpas_csid_input_core_info_update(v10[0], SHIDWORD(v10[0]), a2 & 1);
        if ( v7 )
          break;
      }
      if ( v3[5] )
      {
        result = cam_ife_mgr_find_core_idx(1, a1, 0, v10);
        if ( (_DWORD)result )
          goto LABEL_14;
        result = cam_ife_mgr_find_core_idx(1, a1, 7, (char *)v10 + 4);
        if ( (_DWORD)result )
          goto LABEL_14;
        v7 = cam_cpas_csid_input_core_info_update(v10[0], SHIDWORD(v10[0]), a2 & 1);
        if ( v7 )
          break;
      }
      v3 = (_QWORD *)*v3;
      if ( v3 == v2 )
        goto LABEL_13;
    }
    v8 = *(_DWORD *)(a1 + 56);
    v9 = v7;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000000,
      1,
      "cam_ife_mgr_update_core_info_to_cpas",
      367,
      "Failed to update core info to cpas rc:%d,ctx:%u",
      v7,
      v8);
    result = v9;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
