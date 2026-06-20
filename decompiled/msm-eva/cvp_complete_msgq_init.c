__int64 __fastcall cvp_complete_msgq_init(__int64 a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  v2 = kthread_create_on_node(cvp_msgq_receiver, a1, 0xFFFFFFFFLL, "CVP msgq receiver");
  if ( v2 < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = v2;
    wake_up_process(v2);
    *(_QWORD *)(a1 + 88) = v3;
    if ( v3 )
    {
      _mutex_init(a1, "&msgq_drv->ipc_lock", &cvp_complete_msgq_init___key);
      *(_DWORD *)(a1 + 96) = 0;
      _init_swait_queue_head(a1 + 104, "&x->wait", &init_completion___key_2);
      *(_DWORD *)(a1 + 128) = 0;
      _init_swait_queue_head(a1 + 136, "&x->wait", &init_completion___key_2);
      *(_DWORD *)(a1 + 160) = 0;
      _init_swait_queue_head(a1 + 168, "&x->wait", &init_completion___key_2);
      *(_DWORD *)(a1 + 192) = 0;
      _init_swait_queue_head(a1 + 200, "&x->wait", &init_completion___key_2);
      *(_DWORD *)(a1 + 224) = 0;
      _init_swait_queue_head(a1 + 232, "&x->wait", &init_completion___key_2);
      return 0;
    }
  }
  else
  {
    *(_QWORD *)(a1 + 88) = v2;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_84BD8, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
