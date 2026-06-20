__int64 __fastcall dp_get_debug(__int64 a1)
{
  __int64 v2; // x0

  if ( a1 )
    return *(_QWORD *)(a1 - 976);
  if ( !g_dp_display || (v2 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v2 = 0;
  ipc_log_string(v2, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_275B6D, "dp_get_debug");
  return -22;
}
