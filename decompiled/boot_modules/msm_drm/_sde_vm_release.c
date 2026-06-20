__int64 __fastcall sde_vm_release(__int64 a1)
{
  __int64 result; // x0
  unsigned int resources; // w0
  __int64 v4; // x21
  unsigned __int64 v5; // x19
  unsigned int v6; // w26
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x20
  unsigned int v9; // w0
  _WORD *v10; // x21
  unsigned int v11; // w0
  unsigned int v12; // w22
  void *v13; // x0
  void *v14; // x0
  __int64 v15; // x20
  unsigned int v16; // w8
  unsigned int v17; // w3
  __int64 v18; // x1
  __int64 v19; // x19
  unsigned int *v20; // x0
  unsigned int *v21; // x20
  unsigned int v22; // w27
  unsigned int *v23; // x26
  unsigned int v24; // w0
  unsigned int v25; // w0
  unsigned int v32; // w9
  void *v33; // x0
  unsigned int v34; // w4
  void *v35; // x0
  _QWORD *v36[2]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v37[2]; // [xsp+10h] [xbp-20h] BYREF
  __int16 v38[2]; // [xsp+20h] [xbp-10h] BYREF
  unsigned int v39; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+28h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a1 + 6384) )
  {
    v37[0] = v37;
    v37[1] = v37;
    v36[0] = v36;
    v36[1] = v36;
    resources = sde_vm_get_resources(a1, (__int64)v36);
    if ( resources )
    {
      v6 = resources;
      printk(&unk_21F879, "_sde_vm_release");
LABEL_19:
      sde_vm_free_resources((__int64)v36);
      result = v6;
      goto LABEL_3;
    }
    v4 = *(_QWORD *)(a1 + 6384);
    v39 = 0;
    v38[0] = 0;
    v5 = sde_vm_populate_acl(2);
    if ( v5 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_26B310, "_sde_vm_lend_mem");
LABEL_15:
      v6 = -22;
      goto LABEL_16;
    }
    v7 = sde_vm_populate_sgl((__int64)v36);
    v8 = v7;
    if ( !v7 || v7 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_2371F8, "_sde_vm_lend_mem");
      kfree(v5);
      goto LABEL_15;
    }
    v9 = ghd_rm_mem_lend(1, 0, 17, v5, v7, 0, &v39);
    if ( v9 )
    {
      v12 = v9;
      printk(&unk_255C55, "_sde_vm_lend_mem");
      goto LABEL_28;
    }
    *(_DWORD *)(v4 + 60) = v39;
    ghd_rm_get_vmid(2, v38);
    v10 = sde_vm_populate_vmid(v38[0]);
    v11 = gh_rm_mem_notify(v39, 1, 0, v10);
    if ( v11 )
    {
      v17 = v11;
      v13 = &unk_24E8B1;
      v12 = v17;
    }
    else
    {
      v12 = 0;
      if ( (_drm_debug & 4) != 0 )
      {
        printk(&unk_278D68, 0);
        goto LABEL_27;
      }
      v13 = &unk_21F8A9;
    }
    printk(v13, "_sde_vm_lend_mem");
LABEL_27:
    kfree(v10);
LABEL_28:
    kfree(v8);
    kfree(v5);
    v6 = v12;
    if ( !v12 )
    {
      v19 = *(_QWORD *)(a1 + 6384);
      v20 = (unsigned int *)sde_vm_populate_irq(v36);
      *(_QWORD *)(v19 + 272) = v20;
      if ( !*v20 )
      {
        v6 = 0;
        goto LABEL_19;
      }
      v21 = v20;
      v22 = 0;
      while ( 1 )
      {
        v23 = (unsigned int *)(*((_QWORD *)v21 + 1) + 8LL * (int)v22);
        v24 = gh_irq_lend_v2(*v23, 2, v23[1], sde_vm_irq_release_notification_handler, v19);
        if ( v24 )
        {
          v34 = v24;
          v35 = &unk_21BB73;
          goto LABEL_45;
        }
        _X8 = (unsigned int *)(v19 + 56);
        __asm { PRFM            #0x11, [X8] }
        do
          v32 = __ldxr(_X8);
        while ( __stxr(v32 + 1, _X8) );
        v25 = gh_irq_lend_notify(*v23);
        if ( v25 )
          break;
        if ( (_drm_debug & 4) != 0 )
          printk(&unk_27C11A, *v23);
        else
          printk(&unk_21BBB6, "_sde_vm_lend_irq");
        ++v22;
        v6 = 0;
        if ( v22 >= *v21 )
          goto LABEL_19;
      }
      v34 = v25;
      v35 = &unk_24B2F7;
LABEL_45:
      v6 = v34;
      printk(v35, "_sde_vm_lend_irq");
      v14 = &unk_24B2C8;
LABEL_17:
      printk(v14, "_sde_vm_release");
      v15 = *(_QWORD *)(a1 + 6384);
      v16 = *(_DWORD *)(v15 + 60);
      if ( (v16 & 0x80000000) != 0 )
      {
        if ( !(unsigned int)sde_vm_reclaim_irq(a1) )
          goto LABEL_19;
      }
      else
      {
        if ( (unsigned int)ghd_rm_mem_reclaim(v16, 0) )
        {
          printk(&unk_23067A, "_sde_vm_reclaim_mem");
          v33 = &unk_2260C3;
LABEL_49:
          printk(v33, "_sde_vm_reclaim");
          goto LABEL_19;
        }
        if ( (_drm_debug & 4) != 0 )
          printk(&unk_22CDB7, v18);
        else
          printk(&unk_226084, "_sde_vm_reclaim_mem");
        *(_DWORD *)(v15 + 60) = -1;
        if ( !(unsigned int)sde_vm_reclaim_irq(a1) )
          goto LABEL_19;
      }
      v33 = &unk_25215D;
      goto LABEL_49;
    }
LABEL_16:
    v14 = &unk_252125;
    goto LABEL_17;
  }
  result = 0;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
