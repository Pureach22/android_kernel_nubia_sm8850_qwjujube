__int64 __fastcall sde_vm_trusted_init(__int64 a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x21
  _QWORD *v4; // x20
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w21
  void *v10; // x0
  unsigned int v11; // w3

  v2 = (_QWORD *)_kmalloc_cache_noprof(msleep, 3520, 288);
  v3 = (__int64)v2;
  if ( !v2 )
    return (unsigned int)-12;
  v2[9] = sde_vm_accept;
  v4 = v2 + 9;
  v2[16] = sde_vm_pre_release;
  v2[17] = sde_vm_post_acquire;
  v2[10] = sde_vm_release_0;
  v2[11] = sde_vm_owns_hw_0;
  v2[14] = sde_vm_deinit_0;
  v2[15] = 0;
  v2[12] = sde_kms_vm_trusted_prepare_commit;
  v2[13] = sde_kms_vm_trusted_post_commit;
  v2[18] = sde_vm_request_valid;
  v2[19] = sde_vm_release_0;
  v2[20] = 0;
  v2[21] = sde_vm_msg_send;
  v2[22] = sde_vm_resource_init;
  v2[8] = a1;
  _mutex_init(v2, "&sde_vm->base.vm_res_lock", &sde_vm_trusted_init___key);
  v5 = sde_vm_populate_res(a1, v3);
  if ( (_DWORD)v5 )
  {
    v11 = v5;
    v10 = &unk_2521C7;
    v9 = v11;
    goto LABEL_8;
  }
  v6 = gh_mem_notifier_register(v5, sde_vm_mem_lend_notification_handler, v3);
  if ( !v6 )
  {
    printk(&unk_272231, "sde_vm_trusted_init");
    v9 = 0;
    goto LABEL_11;
  }
  *(_QWORD *)(v3 + 48) = v6;
  v7 = gh_irq_wait_for_lend_v2(0, 1, sde_vm_irq_lend_notification_handler, v3);
  if ( v7 )
  {
    v9 = v7;
    printk(&unk_247EBD, "sde_vm_trusted_init");
    goto LABEL_11;
  }
  *(_QWORD *)(a1 + 6384) = v3;
  *(_DWORD *)(v3 + 56) = 0;
  v8 = sde_vm_msgq_init(v3);
  v9 = 0;
  if ( v8 )
  {
    v9 = v8;
    v10 = &unk_2721F2;
LABEL_8:
    printk(v10, "sde_vm_trusted_init");
LABEL_11:
    sde_vm_deinit_0(a1, v4);
  }
  return v9;
}
