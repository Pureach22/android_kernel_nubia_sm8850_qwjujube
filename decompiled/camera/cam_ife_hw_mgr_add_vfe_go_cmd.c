__int64 __fastcall cam_ife_hw_mgr_add_vfe_go_cmd(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 *v3; // x21
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 result; // x0
  int v8; // w8
  int v10[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(__int64 **)(a1 + 256);
  if ( v3 == (__int64 *)(a1 + 256) )
  {
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  while ( 1 )
  {
    if ( !*((_DWORD *)v3 + 4) )
      goto LABEL_3;
    v4 = v3[4];
    if ( v4 )
      break;
    v5 = v3[5];
    if ( v5 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_add_vfe_go_cmd",
        15051,
        "Offline with right rsrc [%u] not supported ctx: %u",
        *(_DWORD *)(v5 + 4),
        *(_DWORD *)(a1 + 56));
      goto LABEL_8;
    }
LABEL_3:
    v3 = (__int64 *)*v3;
    if ( v3 == (__int64 *)(a1 + 256) )
      goto LABEL_8;
  }
  v8 = *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4LL);
  v10[0] = *(_DWORD *)(a1 + 8744);
  v10[1] = v8;
  result = cam_isp_add_change_base(a2, (__int64 **)(a1 + 224), v10, a3);
  if ( !(_DWORD)result )
    result = cam_isp_add_go_cmd(a2, v3[4], a3, 1);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
