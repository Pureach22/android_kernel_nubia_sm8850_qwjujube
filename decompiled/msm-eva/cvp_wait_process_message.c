__int64 __fastcall cvp_wait_process_message(__int64 a1, __int64 a2, __int64 a3, __int64 a4, void *a5)
{
  __int64 v7; // x8
  unsigned __int64 StatusReg; // x19
  char v12; // w0
  __int64 v13; // x8
  char v14; // w8
  __int64 v15; // x0
  __int64 v16; // x24
  char v17; // w8
  __int64 v18; // x23
  __int64 v19; // x23
  unsigned int msg_size; // w0
  unsigned __int64 v21; // x1
  __int64 result; // x0
  __int64 v23; // x8
  _QWORD v24[5]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v25[2]; // [xsp+30h] [xbp-10h] BYREF

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = _ReadStatusReg(SP_EL0);
  v25[1] = v7;
  v25[0] = 0;
  v12 = cvp_msg_pending(a2, v25, a3);
  if ( (v12 & 1 & (a4 == 0)) != 0 )
    v13 = 1;
  else
    v13 = a4;
  if ( (v12 & 1) == 0 && v13 )
  {
    memset(v24, 0, sizeof(v24));
    init_wait_entry(v24, 0);
    prepare_to_wait_event(a2 + 32, v24, 2);
    v14 = cvp_msg_pending(a2, v25, a3);
    if ( (v14 & 1 & (a4 == 0)) != 0 )
      v15 = 1;
    else
      v15 = a4;
    if ( (v14 & 1) == 0 && v15 )
    {
      do
      {
        v16 = schedule_timeout();
        prepare_to_wait_event(a2 + 32, v24, 2);
        v17 = cvp_msg_pending(a2, v25, a3);
        if ( (v17 & 1 & (v16 == 0)) != 0 )
          v15 = 1;
        else
          v15 = v16;
      }
      while ( (v17 & 1) == 0 && v15 );
    }
    v18 = v15;
    finish_wait(a2 + 32, v24);
    v13 = v18;
  }
  if ( !v13 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_965AF, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      v23 = *(_QWORD *)(a1 + 128);
      if ( v23 )
        goto LABEL_27;
    }
    else
    {
      v23 = *(_QWORD *)(a1 + 128);
      if ( v23 )
      {
LABEL_27:
        if ( *(_QWORD *)(v23 + 256) && *(_DWORD *)(a1 + 328) != 9 )
          print_hfi_queue_info();
      }
    }
    handle_session_timeout(a1, 1);
    result = 4294967186LL;
    goto LABEL_38;
  }
  v19 = v25[0];
  if ( v25[0] )
  {
    if ( a5 )
    {
      msg_size = get_msg_size(v25[0] + 16LL);
      memcpy(a5, (const void *)(v19 + 16), msg_size);
      v21 = *(_QWORD *)(v19 + 48);
      if ( v21 >= 0x200 )
        msm_cvp_unmap_frame(a1, v21);
    }
    cvp_kmem_cache_free(cvp_driver + 72, v19);
  }
  else
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      printk(&unk_87813, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    if ( *(_DWORD *)(a1 + 328) > 6u || (unsigned int)(*(_DWORD *)(a2 + 4) - 1) > 1 )
    {
      result = 4294967192LL;
      goto LABEL_38;
    }
    msm_cvp_comm_kill_session(a1);
  }
  result = 0;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
