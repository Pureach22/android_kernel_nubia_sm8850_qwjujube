__int64 __fastcall dp_debug_mst_mode_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  size_t v8; // x8
  __int64 v9; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  int v12; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v12 = 0;
  if ( !v4 )
  {
    result = -19;
    goto LABEL_9;
  }
  if ( *a4 )
    goto LABEL_3;
  if ( a3 >= 7 )
    v6 = 7;
  else
    v6 = a3;
  v13[0] = 0;
  _check_object_size(v13, v6, 0);
  v8 = inline_copy_from_user((__int64)v13, a2, v6);
  result = 0;
  if ( !v8 )
  {
    *((_BYTE *)v13 + v6) = 0;
    v9 = kstrtoint(v13, 10, &v12);
    if ( (_DWORD)v9 )
    {
LABEL_3:
      result = 0;
      goto LABEL_9;
    }
    *(_BYTE *)(*(_QWORD *)(v4 + 344) + 724LL) = v12 != 0;
    ipc_log_context = get_ipc_log_context(v9);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[d][%-4d]mst_enable: %d\n", *(_DWORD *)(StatusReg + 1800), v12);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mst_enable: %d\n", *(_DWORD *)(StatusReg + 1800), v12);
    result = v6;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
