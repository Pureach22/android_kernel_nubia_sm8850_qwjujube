__int64 __fastcall mem_buf_vm_uses_gunyah(__int64 a1, int a2)
{
  int v4; // w8
  __int64 v5; // x22
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x2
  __int64 v10; // x2

  if ( a2 )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = v4;
      v6 = xa_load(&mem_buf_vms, *(int *)(a1 + 4LL * v4));
      if ( !v6 )
        break;
      if ( (*(_BYTE *)(v6 + 12) & 2) != 0 )
        return 1;
      v4 = v5 + 1;
      if ( a2 == (_DWORD)v5 + 1 )
        goto LABEL_6;
    }
    if ( (unsigned int)__ratelimit(&mem_buf_vm_uses_gunyah__rs, "mem_buf_vm_uses_gunyah") )
      printk(&unk_130DC, *(unsigned int *)(a1 + 4 * v5), v10);
    return 4294967274LL;
  }
  else
  {
LABEL_6:
    v7 = xa_load(&mem_buf_vms, current_vmid);
    if ( v7 )
    {
      return (*(_DWORD *)(v7 + 12) >> 1) & 1;
    }
    else
    {
      result = __ratelimit(&mem_buf_vm_uses_gunyah__rs_1, "mem_buf_vm_uses_gunyah");
      if ( (_DWORD)result )
      {
        printk(&unk_130DC, (unsigned int)current_vmid, v9);
        return 0;
      }
    }
  }
  return result;
}
