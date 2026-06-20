__int64 __fastcall cam_ife_hw_mgr_add_csid_go_cmd(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 **v3; // x8
  __int64 *v4; // x21
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 result; // x0
  int v9; // w9
  int v11[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (__int64 **)(a1 + 208);
  v4 = *(__int64 **)(a1 + 208);
  if ( v4 == (__int64 *)(a1 + 208) )
  {
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  while ( 1 )
  {
    if ( !*((_DWORD *)v4 + 4) )
      goto LABEL_3;
    v5 = v4[4];
    if ( v5 )
      break;
    v6 = v4[5];
    if ( v6 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_add_csid_go_cmd",
        14998,
        "Offline with right rsrc [%u] not supported ctx: %u",
        *(_DWORD *)(v6 + 4),
        *(_DWORD *)(a1 + 56));
      goto LABEL_8;
    }
LABEL_3:
    v4 = (__int64 *)*v4;
    if ( v4 == (__int64 *)v3 )
      goto LABEL_8;
  }
  v9 = *(_DWORD *)(*(_QWORD *)(v5 + 16) + 4LL);
  v11[0] = *(_DWORD *)(a1 + 8744);
  v11[1] = v9;
  result = cam_isp_add_change_base(a2, v3, v11, a3);
  if ( !(_DWORD)result )
    result = cam_isp_add_csid_offline_cmd(a2, v4[4], a3, 1);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
