__int64 __fastcall sde_vm_primary_init(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x20
  _QWORD *v4; // x21
  __int64 v5; // x0
  __int64 result; // x0
  unsigned int v7; // w20
  __int64 v8; // x19
  unsigned int v9; // w20
  __int64 v10; // x0

  v2 = (_QWORD *)_kmalloc_cache_noprof(msleep, 3520, 280);
  v3 = v2;
  if ( !v2 )
    return 4294967284LL;
  v2[9] = sde_vm_reclaim;
  v4 = v2 + 9;
  v2[16] = sde_vm_pre_release;
  v2[17] = sde_vm_post_acquire;
  v2[10] = sde_vm_release;
  v2[11] = sde_vm_owns_hw;
  v2[14] = sde_vm_deinit;
  v2[15] = 0;
  v2[12] = sde_kms_vm_primary_prepare_commit;
  v2[13] = sde_kms_vm_primary_post_commit;
  v2[18] = sde_vm_request_valid;
  v2[19] = 0;
  v2[22] = 0;
  v2[20] = 0;
  v2[21] = sde_vm_msg_send;
  v5 = gh_mem_notifier_register(0, sde_vm_mem_release_notification_handler, v2);
  if ( v5 )
  {
    v3[6] = v5;
    v3[8] = a1;
    *((_DWORD *)v3 + 15) = -1;
    *(_QWORD *)(a1 + 6384) = v3;
    _mutex_init(v3, "&sde_vm->base.vm_res_lock", &sde_vm_primary_init___key);
    result = sde_vm_msgq_init(*(_QWORD *)(a1 + 6384));
    if ( !(_DWORD)result )
      return result;
    v7 = result;
    printk(&unk_2721F2, "sde_vm_primary_init");
    result = v7;
  }
  else
  {
    printk(&unk_25CFD0, "sde_vm_primary_init");
    result = 4294967274LL;
  }
  v8 = *(_QWORD *)(a1 + 6384);
  if ( v8 )
  {
    v9 = result;
    v4[12] = 0;
    v4[13] = 0;
    v4[10] = 0;
    v4[11] = 0;
    v4[8] = 0;
    v4[9] = 0;
    v4[6] = 0;
    v4[7] = 0;
    v4[4] = 0;
    v4[5] = 0;
    v4[2] = 0;
    v4[3] = 0;
    *v4 = 0;
    v4[1] = 0;
    sde_vm_msgq_deinit(v8);
    if ( *(_QWORD *)(v8 + 48) )
      gh_mem_notifier_unregister();
    v10 = *(_QWORD *)(v8 + 272);
    if ( v10 )
      sde_vm_free_irq(v10);
    kfree(v8);
    return v9;
  }
  return result;
}
