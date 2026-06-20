__int64 __fastcall gh_tlmm_vm_mem_on_release_handler(__int64 result, __int64 a2, _QWORD *a3, unsigned int *a4)
{
  _QWORD *v4; // x19
  __int64 v5; // x0

  if ( !a3 )
    return printk(&unk_7097);
  if ( a2 != 1360003090 )
    return dev_err(*a3, "Invalid notification type\n");
  if ( (_DWORD)result != 3 )
    return dev_err(*a3, "Invalid tag\n");
  if ( !a4 )
    return dev_err(*a3, "Invalid data or notification message\n");
  v4 = a3 + 17;
  while ( 1 )
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == a3 + 17 )
      break;
    if ( *((unsigned __int16 *)a4 + 2) == *((unsigned __int16 *)v4 + 14) )
    {
      v5 = *a4;
      if ( (_DWORD)v5 != *((_DWORD *)v4 + 9) )
        return dev_err(*a3, "Invalid mem handle detected\n");
      if ( !(_DWORD)v5 )
        return dev_err(*(_QWORD *)v4[2], "Invalid memory handle\n");
      result = ghd_rm_mem_reclaim(v5, 0);
      if ( (_DWORD)result )
        result = dev_err(*(_QWORD *)v4[2], "VM mem reclaim failed rc:%d\n", result);
      *((_DWORD *)v4 + 9) = 0;
      return result;
    }
  }
  return result;
}
