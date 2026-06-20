__int64 __fastcall dp_debug_max_pclk_khz_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  size_t v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned __int64 StatusReg; // x20
  __int64 ipc_log_context; // x0
  unsigned int v13; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v13 = 0;
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
  v14[0] = 0;
  _check_object_size(v14, v6, 0);
  v8 = inline_copy_from_user((__int64)v14, a2, v6);
  result = 0;
  if ( !v8 )
  {
    *((_BYTE *)v14 + v6) = 0;
    v9 = kstrtoint(v14, 10, &v13);
    if ( (_DWORD)v9 )
    {
LABEL_3:
      result = 0;
      goto LABEL_9;
    }
    if ( v13 > *(_DWORD *)(*(_QWORD *)(v4 + 344) + 704LL) )
    {
      ipc_log_context = get_ipc_log_context(v9);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]requested: %d, max_pclk_khz:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v13,
        *(_DWORD *)(*(_QWORD *)(v4 + 344) + 704LL));
      v9 = printk(&unk_218A90, "dp_debug_max_pclk_khz_write");
    }
    else
    {
      *(_DWORD *)(v4 + 168) = v13;
    }
    v10 = get_ipc_log_context(v9);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v10, "[d][%-4d]max_pclk_khz: %d\n", *(_DWORD *)(StatusReg + 1800), v13);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]max_pclk_khz: %d\n", *(_DWORD *)(StatusReg + 1800), v13);
    result = v6;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
