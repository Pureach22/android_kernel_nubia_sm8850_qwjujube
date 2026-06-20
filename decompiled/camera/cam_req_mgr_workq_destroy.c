_QWORD *__fastcall cam_req_mgr_workq_destroy(_QWORD *result)
{
  __int64 v1; // x19
  _QWORD *v2; // x20
  __int64 v3; // x21
  __int64 v4; // x22
  int v5; // w8
  __int64 v6; // x0
  _QWORD *v7; // x0
  _QWORD *v8; // x0

  if ( !result )
    return result;
  v1 = *result;
  v2 = result;
  if ( !*result )
    return result;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_workq_destroy",
      280,
      "destroy workque %s",
      (const char *)(v1 + 60));
    if ( *(_DWORD *)(v1 + 44) )
      goto LABEL_6;
LABEL_8:
    raw_spin_lock_bh(v1 + 40);
    v3 = 0;
    goto LABEL_9;
  }
  if ( !*(_DWORD *)(v1 + 44) )
    goto LABEL_8;
LABEL_6:
  v3 = raw_spin_lock_irqsave(v1 + 40);
LABEL_9:
  *(_DWORD *)(v1 + 56) = 1;
  v4 = *(_QWORD *)(v1 + 32);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v1 + 44);
    v6 = v1 + 40;
    *(_QWORD *)(v1 + 32) = 0;
    if ( v5 )
      raw_spin_unlock_irqrestore(v6, v3);
    else
      raw_spin_unlock_bh(v6);
    destroy_workqueue(v4);
    if ( *(_DWORD *)(v1 + 44) )
      v3 = raw_spin_lock_irqsave(v1 + 40);
    else
      raw_spin_lock_bh(v1 + 40);
  }
  v7 = *(_QWORD **)(*(_QWORD *)(v1 + 296) + 8LL);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v7, 0);
  else
    kvfree(v7);
  v8 = *(_QWORD **)(v1 + 296);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v8, 0);
  else
    kvfree(v8);
  *(_QWORD *)(v1 + 280) = v1 + 280;
  *(_QWORD *)(v1 + 288) = v1 + 280;
  *(_QWORD *)(v1 + 248) = v1 + 248;
  *(_QWORD *)(v1 + 256) = v1 + 248;
  *(_QWORD *)(v1 + 264) = v1 + 264;
  *(_QWORD *)(v1 + 272) = v1 + 264;
  *v2 = 0;
  if ( *(_DWORD *)(v1 + 44) )
    raw_spin_unlock_irqrestore(v1 + 40, v3);
  else
    raw_spin_unlock_bh(v1 + 40);
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free((_QWORD *)v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
