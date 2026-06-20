__int64 __fastcall msm_cvp_session_start(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v3; // x20
  __int64 result; // x0
  int v5; // w25
  __int64 *v6; // x26
  void (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x0
  int v9; // w21
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x24
  __int64 (__fastcall *v12)(__int64, unsigned __int64); // x9
  __int64 v13; // x0
  unsigned int v14; // w0
  unsigned int v15; // w21
  __int64 v16; // x1
  __int64 v17; // x2
  void *v18; // x0
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v28; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = _ReadStatusReg(SP_EL0);
  v29 = *(_QWORD *)(StatusReg + 1808);
  if ( a1 && *(_QWORD *)(a1 + 128) )
  {
    raw_spin_lock(a1 + 176);
    if ( *(_DWORD *)(a1 + 184) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_96FEE, *(unsigned int *)(v3 + 1800), *(unsigned int *)(v3 + 1804), &unk_8E7CE);
      raw_spin_unlock(a1 + 176);
      result = 4294967274LL;
      goto LABEL_51;
    }
    v5 = *(_DWORD *)(a1 + 180);
    *(_DWORD *)(a1 + 180) = 2;
    raw_spin_unlock(a1 + 176);
    v6 = *(__int64 **)(*(_QWORD *)(a1 + 128) + 256LL);
    if ( v6 )
    {
      v7 = (void (__fastcall *)(_QWORD))v6[23];
      if ( v7 )
      {
        v8 = *v6;
        if ( *((_DWORD *)v7 - 1) != -1066802076 )
          __break(0x8228u);
        v7(v8);
      }
    }
    if ( *(_DWORD *)(a1 + 14852) )
    {
      *(_QWORD *)s = 0;
      v28 = 0;
      mutex_lock(a1 + 15272);
      *(_DWORD *)(a1 + 15320) = 2;
      mutex_unlock(a1 + 15272);
      if ( *(_DWORD *)(a1 + 14852) )
      {
        v9 = 0;
        while ( 1 )
        {
          if ( !cvp_get_inst_validate(*(_QWORD *)(a1 + 128), a1) )
          {
            v15 = -104;
            goto LABEL_37;
          }
          snprintf(s, 0x10u, "fthread_%d", v9);
          v10 = kthread_create_on_node(cvp_fence_thread, a1, 0xFFFFFFFFLL, s);
          v11 = v10;
          if ( v10 <= 0xFFFFFFFFFFFFF000LL )
            wake_up_process(v10);
          if ( !v11 )
            break;
          if ( (unsigned int)++v9 >= *(_DWORD *)(a1 + 14852) )
            goto LABEL_24;
        }
        v15 = -10;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          printk(&unk_877E9, *(unsigned int *)(v3 + 1800), *(unsigned int *)(v3 + 1804), &unk_8E7CE);
LABEL_37:
        mutex_lock(a1 + 15272);
        *(_DWORD *)(a1 + 15320) = 3;
        mutex_unlock(a1 + 15272);
        _wake_up(a1 + 15344, 3, 0, 0);
        goto LABEL_47;
      }
LABEL_24:
      raw_spin_lock(a1 + 232);
      *(_DWORD *)(a1 + 236) = 2;
      raw_spin_unlock(a1 + 232);
    }
    _X9 = (unsigned __int64 *)(*(_QWORD *)(a1 + 128) + 1296LL);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v25 = __ldxr(_X9);
      v26 = v25 + 1;
    }
    while ( __stlxr(v26, _X9) );
    __dmb(0xBu);
    if ( v6 )
    {
      v12 = (__int64 (__fastcall *)(__int64, unsigned __int64))v6[6];
      if ( v12 )
      {
        v13 = *(_QWORD *)(a1 + 320);
        if ( *((_DWORD *)v12 - 1) != 1021877503 )
          __break(0x8229u);
        v14 = v12(v13, v26 & 0x7FFFFFFFFFFFFFFFLL);
        if ( v14 )
        {
          if ( (msm_cvp_debug & 2) != 0 )
          {
            v15 = v14;
            if ( !msm_cvp_debug_out )
            {
              v16 = *(unsigned int *)(v3 + 1800);
              v17 = *(unsigned int *)(v3 + 1804);
              v18 = &unk_877AD;
LABEL_44:
              printk(v18, v16, v17, "warn");
              goto LABEL_46;
            }
            goto LABEL_46;
          }
          goto LABEL_45;
        }
      }
    }
    v14 = wait_for_sess_signal_receipt(a1, 15);
    if ( v14 )
    {
      if ( (msm_cvp_debug & 2) != 0 )
      {
        v15 = v14;
        if ( !msm_cvp_debug_out )
        {
          v16 = *(unsigned int *)(v3 + 1800);
          v17 = *(unsigned int *)(v3 + 1804);
          v18 = &unk_8624A;
          goto LABEL_44;
        }
LABEL_46:
        cvp_fence_thread_stop(a1);
LABEL_47:
        raw_spin_lock(a1 + 176);
        *(_DWORD *)(a1 + 180) = v5;
        raw_spin_unlock(a1 + 176);
        result = v15;
        goto LABEL_51;
      }
LABEL_45:
      v15 = v14;
      goto LABEL_46;
    }
    if ( (unsigned int)__ratelimit(&msm_cvp_session_start__rs, "msm_cvp_session_start") )
      printk(&unk_84495, *(unsigned int *)(v3 + 1800), *(unsigned int *)(v3 + 1804), "sess");
    result = 0;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_912BD, *(unsigned int *)(v3 + 1800), *(unsigned int *)(v3 + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
