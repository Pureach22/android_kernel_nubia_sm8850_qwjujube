__int64 __fastcall msm_cvp_close(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x3
  unsigned __int64 StatusReg; // x20
  int v5; // w8
  int v12; // w9

  if ( a1 && *(_QWORD *)(a1 + 128) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_926A2, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), a1 + 15392);
    if ( !*(_QWORD *)(a1 + 320) )
    {
      v5 = *(_DWORD *)(a1 + 328);
      if ( (unsigned int)(v5 - 3) <= 1 )
      {
        *(_DWORD *)(a1 + 328) = 8;
        goto LABEL_25;
      }
      if ( v5 == 8 )
        return 4294967274LL;
    }
    if ( *(_DWORD *)(a1 + 136) != 3 )
    {
      if ( (unsigned int)msm_cvp_cleanup_instance(a1) )
      {
        result = 4294967274LL;
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          return result;
        printk(&unk_952BD, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        return 4294967274LL;
      }
      msm_cvp_session_deinit(a1);
    }
    if ( (unsigned int)msm_cvp_comm_try_state(a1, 8u) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_885A9, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      msm_cvp_deinit_core(a1);
    }
LABEL_25:
    msm_cvp_comm_session_clean(a1);
    _X8 = (unsigned int *)(a1 + 14824);
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stlxr(v12 - 1, _X8) );
    if ( v12 == 1 )
    {
      __dmb(9u);
      msm_cvp_destroy((__int64 *)a1);
    }
    else if ( v12 <= 0 )
    {
      refcount_warn_saturate(a1 + 14824, 3);
    }
    return 0;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    if ( (unsigned int)__ratelimit(&msm_cvp_close__rs, "msm_cvp_close") )
      printk(&unk_8B716, &unk_8E7CE, "msm_cvp_close", v2);
    return 4294967274LL;
  }
  return result;
}
