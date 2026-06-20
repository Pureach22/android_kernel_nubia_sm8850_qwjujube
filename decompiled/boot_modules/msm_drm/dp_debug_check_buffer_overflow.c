__int64 __fastcall dp_debug_check_buffer_overflow(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // w8
  int v5; // w8
  __int64 ipc_log_context; // x0

  if ( *a2 <= (int)a1 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]buffer overflow\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_27296B, "dp_debug_check_buffer_overflow");
    return 4294967274LL;
  }
  else
  {
    v3 = a1;
    v5 = *a3 + v3;
    *a3 = v5;
    *a2 = 4096 - v5;
    return 0;
  }
}
