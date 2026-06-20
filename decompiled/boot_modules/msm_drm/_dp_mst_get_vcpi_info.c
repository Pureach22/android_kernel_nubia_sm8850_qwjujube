__int64 __fastcall dp_mst_get_vcpi_info(__int64 a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _QWORD *v7; // x8
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x22

  *a3 = 0;
  *a4 = 0;
  v7 = (_QWORD *)(*(_QWORD *)(a1 + 88) + 56LL);
  while ( 1 )
  {
    v7 = (_QWORD *)*v7;
    if ( v7 == (_QWORD *)(*(_QWORD *)(a1 + 88) + 56LL) )
      break;
    if ( *((unsigned __int8 *)v7 - 23) == a2 )
    {
      *a3 = *((char *)v7 - 24);
      *a4 = *((_DWORD *)v7 - 5);
      break;
    }
  }
  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    ipc_log_context,
    "[i][%-4d]vcpi_info. vcpi:%d, start_slot:%d, num_slots:%d\n",
    *(_DWORD *)(StatusReg + 1800),
    a2,
    *a3,
    *a4);
  if ( (_drm_debug & 4) != 0 )
    return printk(&unk_25696C, *(unsigned int *)(StatusReg + 1800));
  else
    return printk(&unk_25E01A, "_dp_mst_get_vcpi_info");
}
