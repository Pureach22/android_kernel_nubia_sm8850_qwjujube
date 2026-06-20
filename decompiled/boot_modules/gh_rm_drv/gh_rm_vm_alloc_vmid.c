__int64 __fastcall gh_rm_vm_alloc_vmid(unsigned int a1, _DWORD *a2)
{
  __int64 result; // x0
  __int16 *v5; // x20
  unsigned int v6; // w0
  int v7; // w21
  unsigned int v8; // w19
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  if ( a1 > 4 )
    goto LABEL_2;
  v11[0] = 0;
  v9 = 0;
  raw_spin_lock(&gh_vm_table_lock);
  if ( !a1 || (v5 = &gh_vm_table[52 * a1], (unsigned __int16)*v5 != 0xFFFF) )
  {
    printk(&unk_121BC, "gh_rm_vm_alloc_vmid");
    raw_spin_unlock(&gh_vm_table_lock);
    goto LABEL_2;
  }
  raw_spin_unlock(&gh_vm_table_lock);
  LOWORD(v10) = *a2;
  v6 = gunyah_rm_call(rm, 1442840577, &v10, 4, v11, &v9);
  if ( v6 )
  {
    v8 = v6;
    printk(&unk_130C9, "gh_rm_vm_alloc_vmid");
    result = v8;
    goto LABEL_18;
  }
  if ( v11[0] && v9 != 4 )
  {
    printk(&unk_129C7, "gh_rm_vm_alloc_vmid");
    kfree(v11[0]);
    goto LABEL_2;
  }
  if ( v11[0] )
  {
    v7 = *(_DWORD *)v11[0];
    *a2 = *(_DWORD *)v11[0];
  }
  else
  {
    LOWORD(v7) = *(_WORD *)a2;
  }
  raw_spin_lock(&gh_vm_table_lock);
  if ( *((_QWORD *)v5 + 1) || *((_QWORD *)v5 + 2) || *((_QWORD *)v5 + 3) || *((_QWORD *)v5 + 4) )
  {
    raw_spin_unlock(&gh_vm_table_lock);
    printk(&unk_12F2D, "gh_rm_vm_alloc_vmid");
LABEL_2:
    result = 4294967274LL;
    goto LABEL_18;
  }
  if ( (_WORD)v7 )
    *v5 = v7;
  raw_spin_unlock(&gh_vm_table_lock);
  kfree(v11[0]);
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
