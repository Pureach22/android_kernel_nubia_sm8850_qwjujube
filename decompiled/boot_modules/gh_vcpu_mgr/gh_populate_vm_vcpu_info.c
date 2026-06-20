__int64 __fastcall gh_populate_vm_vcpu_info(unsigned int a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x2
  unsigned int vm_name; // w0
  __int64 v8; // x25
  unsigned __int64 v9; // x19
  __int64 v11; // x22
  __int64 v12; // x23
  int v13; // w4
  size_t v14; // x0
  unsigned __int64 v15; // x24
  size_t v16; // x0
  __int64 v17; // x8
  bool v18; // cf
  size_t v19; // x2
  void *v20; // x0
  __int64 v21; // x24
  __int64 v22; // x0
  __int64 v23; // x2
  unsigned __int64 v24; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v26; // x24
  __int64 (*v27)(_QWORD, _QWORD, const char *, ...); // x0
  char string[8]; // [xsp+8h] [xbp-18h] BYREF
  int v29; // [xsp+10h] [xbp-10h]
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (init_done & 1) == 0 )
  {
    printk(&unk_7C16, "gh_populate_vm_vcpu_info", a3);
    LODWORD(v9) = -6;
    goto LABEL_11;
  }
  *(_WORD *)string = 0;
  if ( ((unsigned int)ghd_rm_get_vmid(2, string) || *(unsigned __int16 *)string != (unsigned __int16)a1)
    && ((unsigned int)ghd_rm_get_vmid(4, string) || *(unsigned __int16 *)string != (unsigned __int16)a1) )
  {
    printk(&unk_7DC2, (unsigned __int16)a1, v6);
    LODWORD(v9) = 0;
    goto LABEL_11;
  }
  mutex_lock(&gh_vm_mutex);
  *(_DWORD *)string = 0;
  vm_name = gh_rm_get_vm_name(a1, string);
  if ( vm_name )
  {
    printk(&unk_7AD3, (unsigned __int16)a1, vm_name);
    LODWORD(v9) = 0;
    goto LABEL_10;
  }
  v8 = gh_vms + 40LL * *(unsigned int *)string;
  if ( !v8 || (*(_BYTE *)(v8 + 24) & 1) != 0 )
  {
    LODWORD(v9) = 0;
    goto LABEL_10;
  }
  v11 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, byte_50);
  if ( !v11 )
  {
LABEL_37:
    LODWORD(v9) = -12;
    goto LABEL_10;
  }
  while ( 1 )
  {
    *(_QWORD *)(v11 + 21) = *(_QWORD *)"gh_vcpu_ws";
    v12 = v11 + 21;
    *(_DWORD *)(v11 + 28) = 7567199;
    v13 = *(_DWORD *)(v8 + 4);
    v29 = 0;
    *(_QWORD *)string = 0;
    scnprintf(string, 12, "_%d_%d", (unsigned __int16)a1, v13);
    v14 = strnlen((const char *)(v11 + 21), 0x20u);
    v15 = v14;
    if ( v14 >= 0x3B )
    {
      v16 = _fortify_panic(2, 59, v14 + 1);
LABEL_35:
      _fortify_panic(2, 12, v16 + 1);
      goto LABEL_36;
    }
    v16 = strnlen(string, 0xCu);
    if ( v16 >= 0xD )
      goto LABEL_35;
    if ( v16 != 12 )
      break;
LABEL_36:
    _fortify_panic(4, 12, 13);
    StatusReg = _ReadStatusReg(SP_EL0);
    v26 = *(_QWORD *)(StatusReg + 80);
    v27 = _kmalloc_cache_noprof;
    *(_QWORD *)(StatusReg + 80) = &gh_populate_vm_vcpu_info__alloc_tag;
    v11 = _kmalloc_cache_noprof(v27, 3520, byte_50);
    *(_QWORD *)(StatusReg + 80) = v26;
    if ( !v11 )
      goto LABEL_37;
  }
  if ( v15 <= 0x1F )
  {
    v17 = v16 + v15;
    v18 = v16 + v15 >= 0x20;
    if ( v16 + v15 >= 0x20 )
      v19 = 31 - v15;
    else
      v19 = v16;
    v20 = (void *)(v12 + v15);
    if ( v18 )
      v21 = 31;
    else
      v21 = v17;
    memcpy(v20, string, v19);
    *(_BYTE *)(v12 + v21) = 0;
  }
  v22 = wakeup_source_register(0, v11 + 21);
  *(_QWORD *)(v11 + 56) = v22;
  if ( v22 )
  {
    *(_QWORD *)(v11 + 8) = a3;
    *(_DWORD *)(v11 + 16) = a2;
    *(_WORD *)v8 = a1;
    *(_QWORD *)v11 = v8;
    v24 = xa_store(v8 + 8, a2, v11, 3264);
    if ( v24 >= 0xFFFFFFFFFFFFC006LL && (v24 & 3) == 2 && (v9 = v24 >> 2, (unsigned int)(v24 >> 2)) )
    {
      wakeup_source_unregister(*(_QWORD *)(v11 + 56));
      kfree(v11);
    }
    else
    {
      LODWORD(v9) = 0;
      ++*(_DWORD *)(v8 + 4);
    }
  }
  else
  {
    printk(&unk_7D2E, "gh_populate_vm_vcpu_info", v23);
    kfree(v11);
    LODWORD(v9) = 0;
  }
LABEL_10:
  mutex_unlock(&gh_vm_mutex);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v9;
}
