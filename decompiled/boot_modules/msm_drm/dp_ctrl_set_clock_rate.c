__int64 __fastcall dp_ctrl_set_clock_rate(__int64 a1, char *s2, unsigned int a3, int a4)
{
  __int64 v4; // x8
  __int64 v6; // x19
  int v7; // w23
  __int64 v8; // x21
  __int64 v9; // x24
  bool v10; // w22
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x23
  __int64 result; // x0
  __int64 v14; // x0

  v4 = *(_QWORD *)(a1 + 168) + 48LL * a3;
  v6 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 184) + 396LL) * a4);
  v7 = *(_DWORD *)(v4 + 48);
  v8 = *(_QWORD *)(v4 + 56);
  if ( v7 )
  {
    v9 = v8 + 120LL * (unsigned int)(v7 - 1) + 120;
    while ( 1 )
    {
      a1 = strcmp((const char *)(v8 + 8), s2);
      v10 = (_DWORD)a1 != 0;
      if ( !(_DWORD)a1 )
        break;
      --v7;
      v8 += 120;
      if ( !v7 )
      {
        v8 = v9;
        break;
      }
    }
  }
  else
  {
    v10 = 1;
  }
  ipc_log_context = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  result = ipc_log_string(
             ipc_log_context,
             "[d][%-4d]setting rate=%d on clk=%s\n",
             *(_DWORD *)(StatusReg + 1800),
             v6,
             s2);
  if ( (_drm_debug & 4) != 0 )
    result = _drm_dev_dbg(
               0,
               0,
               0,
               "[msm-dp-debug][%-4d]setting rate=%d on clk=%s\n",
               *(_DWORD *)(StatusReg + 1800),
               v6,
               s2);
  if ( v10 )
  {
    v14 = get_ipc_log_context(result);
    ipc_log_string(v14, "[e][%-4d]%s clock could not be set with rate %d\n", *(_DWORD *)(StatusReg + 1800), s2, v6);
    return printk(&unk_241B04, "dp_ctrl_set_clock_rate");
  }
  else
  {
    *(_QWORD *)(v8 + 48) = v6;
  }
  return result;
}
