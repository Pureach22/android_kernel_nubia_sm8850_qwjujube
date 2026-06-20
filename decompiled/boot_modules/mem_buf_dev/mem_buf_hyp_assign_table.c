__int64 __fastcall mem_buf_hyp_assign_table(
        __int64 a1,
        int *a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6)
{
  int v12; // w25
  int v13; // w26
  __int64 result; // x0
  unsigned int v15; // w19
  const char *v16; // x1

  if ( (mem_buf_vm_uses_hyp_assign() & 1) == 0 )
    return 0;
  v12 = *a2;
  v13 = current_vmid;
  result = hyp_assign_table(a1, a2, a3, a4, a5, a6);
  if ( (result & 0x80000000) != 0 )
  {
    v15 = result;
    if ( v12 == v13 )
      v16 = "Assign";
    else
      v16 = "Unassign";
    printk(&unk_1387E, v16, (unsigned int)result);
    return v15;
  }
  return result;
}
