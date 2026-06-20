__int64 __fastcall sde_vm_msgq_init(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  __int64 v3; // x8
  unsigned __int64 v4; // x21
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x20

  v2 = gh_msgq_register(258);
  if ( v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_241735, "sde_vm_msgq_init");
    return 0;
  }
  v3 = a1[20];
  a1[32] = v2;
  if ( !v3 )
    return 0;
  v4 = v2;
  v5 = kthread_create_on_node(sde_vm_msgq_listener, a1, 0xFFFFFFFFLL, "disp_msgq_listener");
  v6 = v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_278DEE, "sde_vm_msgq_init");
    gh_msgq_unregister(v4);
    a1[32] = 0;
    return 4294967274LL;
  }
  else
  {
    wake_up_process(v5);
    a1[27] = 0;
    a1[28] = 0;
    a1[24] = a1 + 24;
    a1[25] = a1 + 24;
    a1[26] = sde_vm_msgq_process_msg;
    a1[23] = v6;
    return 0;
  }
}
