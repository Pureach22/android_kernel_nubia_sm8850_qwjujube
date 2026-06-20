__int64 __fastcall mem_buf_assign_mem(unsigned int a1, __int64 a2, unsigned int *a3)
{
  int v3; // w26
  __int64 v7; // x1
  __int64 v8; // x0
  __int64 v9; // x22
  unsigned int v10; // w23
  __int64 result; // x0
  __int64 v12; // x0
  __int64 v13; // x22
  __int64 v14; // x23
  unsigned int v15; // w24
  int v16; // w27
  unsigned int v17; // w0
  unsigned int v18; // w22
  __int64 v19; // x0
  int *v20; // x21
  unsigned int v21; // w20
  int v22; // w23
  int v23; // w24
  unsigned int v24; // w0
  unsigned int v25; // w19
  const char *v26; // x1
  __int64 v27; // x2
  const char *v28; // x1
  int v29; // [xsp+0h] [xbp-10h] BYREF
  int v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = current_vmid;
  v29 = 7;
  v30 = current_vmid;
  if ( a2 && *a3 && *((_QWORD *)a3 + 1) && *((_QWORD *)a3 + 2) )
  {
    a3[6] = -1;
    mutex_lock(&mem_buf_heap_lock);
    if ( *(_DWORD *)(a2 + 12) )
    {
      v8 = *(_QWORD *)a2;
      v9 = 0;
      v10 = 0;
      do
      {
        ++v10;
        v9 += *(unsigned int *)(v8 + 12);
        v8 = sg_next(v8, v7);
      }
      while ( v10 < *(_DWORD *)(a2 + 12) );
    }
    else
    {
      v9 = 0;
    }
    v12 = mem_buf_vm_uses_gunyah(*((_QWORD *)a3 + 1), *a3);
    if ( (int)v12 >= 1 )
      v12 = gh_rm_heap_memlend_prealloc(v9);
    v13 = *((_QWORD *)a3 + 1);
    v14 = *((_QWORD *)a3 + 2);
    v15 = *a3;
    if ( (mem_buf_vm_uses_hyp_assign(v12) & 1) == 0 )
      goto LABEL_17;
    v16 = current_vmid;
    v17 = hyp_assign_table(a2, &v30, 1, v13, v14, v15);
    if ( (v17 & 0x80000000) != 0 )
    {
      if ( v3 == v16 )
        v28 = "Assign";
      else
        v28 = "Unassign";
      v18 = v17;
      printk(&unk_1387E, v28, v17);
    }
    else
    {
      v18 = v17;
      if ( !v17 )
      {
LABEL_17:
        v19 = mem_buf_assign_mem_gunyah(a1, a2, a3);
        if ( (_DWORD)v19 )
        {
          v20 = *((int **)a3 + 1);
          v21 = *a3;
          v18 = v19;
          if ( (mem_buf_vm_uses_hyp_assign(v19) & 1) != 0 )
          {
            v22 = *v20;
            v23 = current_vmid;
            v24 = hyp_assign_table(a2, v20, v21, &v30, &v29, 1);
            if ( (v24 & 0x80000000) != 0 )
            {
              v25 = v24;
              if ( v22 == v23 )
                v26 = "Assign";
              else
                v26 = "Unassign";
              printk(&unk_1387E, v26, v24);
              printk(&unk_12E88, v25, v27);
              v18 = -99;
            }
          }
        }
        else
        {
          v18 = 0;
        }
      }
    }
    mutex_unlock(&mem_buf_heap_lock);
    result = v18;
    goto LABEL_10;
  }
  result = 4294967274LL;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
