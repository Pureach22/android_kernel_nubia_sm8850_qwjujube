__int64 __fastcall sde_vm_accept(__int64 a1)
{
  __int64 v2; // x22
  unsigned __int64 v3; // x20
  unsigned int v4; // w23
  _DWORD *v5; // x0
  _DWORD *v6; // x21
  unsigned int *v7; // x22
  __int64 v8; // x1
  __int64 v9; // x1
  __int64 v10; // x10
  _QWORD *v11; // x8
  _QWORD *v12; // x9
  __int64 v13; // x4
  __int64 v14; // x6
  __int64 v16; // x26
  __int64 v17; // x27
  unsigned int v18; // w28
  unsigned int *v19; // x22
  unsigned int v20; // w24
  unsigned int v21; // w0
  unsigned int v22; // w23
  __int64 irq_data; // x0
  __int64 v24; // x25
  __int64 v25; // x0
  unsigned int v32; // w9
  void *v33; // x0

  v2 = *(_QWORD *)(a1 + 6384);
  v3 = sde_vm_populate_acl(2);
  if ( v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_21497C, "_sde_vm_accept_mem");
    v4 = v3;
    goto LABEL_24;
  }
  v5 = (_DWORD *)gh_rm_mem_accept(*(unsigned int *)(v2 + 60), 1, 1, 134, 17, v3, 0, 0, 0);
  v6 = v5;
  if ( !v5 || (unsigned __int64)v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_247F48, "_sde_vm_accept_mem");
    v4 = -22;
    *(_DWORD *)(v2 + 60) = -1;
    goto LABEL_23;
  }
  v7 = *(unsigned int **)(v2 + 280);
  v8 = *v7;
  if ( (_DWORD)v8 == *v5 )
  {
    sort((char *)v5 + 6, v8, 16, _sgl_cmp, 0);
    v10 = *v7;
    if ( !(_DWORD)v10 )
    {
LABEL_11:
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_23726B, v9);
      else
        printk(&unk_25938B, "_sde_vm_accept_mem");
      v4 = 0;
      goto LABEL_22;
    }
    v11 = (_QWORD *)((char *)v6 + 14);
    v12 = (_QWORD *)((char *)v7 + 14);
    while ( 1 )
    {
      v13 = *(v12 - 1);
      v14 = *(v11 - 1);
      if ( v13 != v14 )
        break;
      if ( *v12 != *v11 )
      {
        v14 = *(v12 - 1);
        break;
      }
      --v10;
      v11 += 2;
      v12 += 2;
      if ( !v10 )
        goto LABEL_11;
    }
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "sgl mismatch: (%llu - %llu) vs (%llu - %llu)\n", v13, *v12, v14, *v11);
    v4 = -22;
  }
  else
  {
    v4 = -7;
  }
  printk(&unk_25220B, "_sde_vm_accept_mem");
LABEL_22:
  kvfree(v6);
LABEL_23:
  kfree(v3);
  if ( !v4 )
  {
    v16 = *(_QWORD *)(a1 + 6384);
    v17 = *(_QWORD *)(v16 + 272);
    if ( !*(_DWORD *)v17 )
      return 0;
    v18 = 0;
    while ( 1 )
    {
      v19 = (unsigned int *)(*(_QWORD *)(v17 + 8) + 8LL * (int)v18);
      v20 = v19[1];
      v21 = gh_irq_accept(*v19, 0xFFFFFFFFLL, 4);
      if ( (v21 & 0x80000000) != 0 )
      {
        v33 = &unk_2416F8;
        goto LABEL_45;
      }
      v22 = v21;
      _X8 = (unsigned int *)(v16 + 56);
      __asm { PRFM            #0x11, [X8] }
      do
        v32 = __ldxr(_X8);
      while ( __stxr(v32 + 1, _X8) );
      irq_data = irq_get_irq_data(v20);
      if ( !irq_data )
      {
        v33 = &unk_24B33A;
        goto LABEL_45;
      }
      v24 = irq_data;
      v25 = irq_get_irq_data(v22);
      if ( !v25 )
      {
        v33 = &unk_24B33A;
        goto LABEL_45;
      }
      if ( *(_QWORD *)(v24 + 8) != *(_QWORD *)(v25 + 8) )
        break;
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_278DBA, *v19);
      else
        printk(&unk_2722A8, "_sde_vm_accept_irq");
      ++v18;
      v4 = 0;
      if ( v18 >= *(_DWORD *)v17 )
        return v4;
    }
    v33 = &unk_26B356;
LABEL_45:
    printk(v33, "_sde_vm_accept_irq");
    v4 = -22;
  }
LABEL_24:
  sde_vm_release_irq(*(_QWORD *)(a1 + 6384));
  sde_vm_release_mem(*(_QWORD *)(a1 + 6384));
  return v4;
}
