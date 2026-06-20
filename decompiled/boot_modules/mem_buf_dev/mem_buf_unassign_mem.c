__int64 __fastcall mem_buf_unassign_mem(__int64 a1, int *a2, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  int v12; // w21
  int v13; // w22
  int v14; // w19
  const char *v15; // x1
  unsigned int v16; // w19
  int v17; // [xsp+0h] [xbp-10h] BYREF
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  result = 4294967274LL;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 7;
  v18 = current_vmid;
  if ( a1 && a2 && a3 )
  {
    v9 = mutex_lock(&mem_buf_heap_lock);
    if ( a4 == -1 || (v9 = mem_buf_unassign_mem_gunyah(a4), !(_DWORD)v9) )
    {
      v11 = gh_rm_heap_shrink(v9, v10);
      if ( (mem_buf_vm_uses_hyp_assign(v11) & 1) != 0 )
      {
        v12 = *a2;
        v13 = current_vmid;
        LODWORD(v9) = hyp_assign_table(a1, a2, a3, &v18, &v17, 1);
        if ( (v9 & 0x80000000) != 0 )
        {
          v14 = v9;
          if ( v12 == v13 )
            v15 = "Assign";
          else
            v15 = "Unassign";
          printk(&unk_1387E, v15, (unsigned int)v9);
          LODWORD(v9) = v14;
        }
      }
      else
      {
        LODWORD(v9) = 0;
      }
    }
    v16 = v9;
    mutex_unlock(&mem_buf_heap_lock);
    result = v16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
