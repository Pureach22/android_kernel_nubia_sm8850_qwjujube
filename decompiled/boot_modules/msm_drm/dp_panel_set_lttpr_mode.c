__int64 __fastcall dp_panel_set_lttpr_mode(__int64 a1, char a2)
{
  char v2; // w9
  __int64 v3; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v6; // x0
  __int64 v7; // x0
  char v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v6 = &unk_275B6D;
LABEL_9:
    result = printk(v6, "dp_panel_set_lttpr_mode");
    goto LABEL_6;
  }
  if ( (a2 & 1) != 0 )
    v2 = 85;
  else
    v2 = -86;
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 1192) + 24LL);
  v8[0] = v2;
  result = drm_dp_dpcd_write(v3, 983043, v8, 1);
  if ( result != 1 )
  {
    v7 = get_ipc_log_context(result);
    ipc_log_string(v7, "[w][%-4d]failed to set LTTPR mode\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v6 = &unk_22D10E;
    goto LABEL_9;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
