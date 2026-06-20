__int64 init_module()
{
  __int64 v0; // x0
  unsigned int v1; // w19
  unsigned __int64 hyp_res; // x0
  __int64 v4; // x2
  __int64 v5; // x3
  unsigned __int64 v6; // x8
  int v7; // w13
  _DWORD *v8; // x12
  __int64 v9; // x10
  __int64 v10; // x11
  int v11; // w15
  _DWORD *v12; // x14
  int v13; // w14
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 rm_heap_free; // x19
  void *v19; // x0
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = _kmalloc_cache_noprof(mem_prot_pool_free, 3520, 72);
  rm_heap_manager = v0;
  if ( !v0 )
  {
    v1 = -12;
    goto LABEL_3;
  }
  *(_DWORD *)v0 = 255;
  *(_QWORD *)(v0 + 40) = v0 + 40;
  *(_QWORD *)(v0 + 48) = v0 + 40;
  *(_QWORD *)(v0 + 56) = v0 + 56;
  *(_QWORD *)(v0 + 64) = v0 + 56;
  LODWORD(v20[0]) = 0;
  hyp_res = gh_rm_vm_get_hyp_res(255, v20);
  v1 = hyp_res;
  if ( hyp_res && hyp_res <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( LODWORD(v20[0]) )
    {
      v6 = 0;
      v7 = (unsigned __int8)hyp_heap_manage_supported;
      v8 = (_DWORD *)(hyp_res + 4);
      v9 = rm_heap_manager + 8;
      v10 = rm_heap_manager + 4;
      while ( *((_BYTE *)v8 - 4) != 11 )
      {
        v13 = v7;
LABEL_16:
        ++v6;
        v8 += 11;
        v7 = v13;
        if ( v6 >= LODWORD(v20[0]) )
          goto LABEL_17;
      }
      v11 = v8[1];
      v12 = (_DWORD *)v10;
      if ( v11 )
      {
        if ( v11 != 1 )
          goto LABEL_13;
        v12 = (_DWORD *)v9;
      }
      *v12 = *v8;
LABEL_13:
      v13 = 1;
      if ( (v7 & 1) == 0 )
        hyp_heap_manage_supported = 1;
      goto LABEL_16;
    }
LABEL_17:
    kfree(hyp_res);
    v1 = 0;
  }
  else
  {
    printk(&unk_7053, "gh_rm_get_heap_resource_info", v4, v5);
    if ( (v1 & 0x80000000) != 0 )
    {
      printk(&unk_6F49, "gh_rm_heap_manager_init", v1, v15);
LABEL_28:
      kfree(rm_heap_manager);
      goto LABEL_3;
    }
  }
  if ( (hyp_heap_manage_supported & 1) == 0 )
  {
    v19 = &unk_7075;
LABEL_27:
    printk(v19, "gh_rm_heap_manager_init", v14, v15);
    goto LABEL_28;
  }
  v20[0] = 0;
  if ( (unsigned int)mem_prot_pool_alloc(0x400000, v20, 4) )
  {
    v19 = &unk_7311;
    goto LABEL_27;
  }
  if ( (unsigned int)mem_prot_pool_free(v20[0], 0x400000, 4) )
    printk(&unk_7115, "check_mem_prot_enabled", v16, v17);
  rm_heap_manager_enabled = 1;
  rm_heap_free = gh_get_rm_heap_free(0);
  gh_get_rm_heap_free(1u);
  printk(&unk_71F5, "gh_rm_heap_manager_init", "Root heap", rm_heap_free);
  v1 = 0;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v1;
}
