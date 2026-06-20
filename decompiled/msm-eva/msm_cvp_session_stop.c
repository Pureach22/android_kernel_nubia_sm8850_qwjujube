__int64 __fastcall msm_cvp_session_stop(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x19
  __int64 v4; // x0
  __int64 v5; // x22
  __int64 inst_validate; // x0
  __int64 v7; // x21
  int v8; // w8
  unsigned int v9; // w22
  __int64 result; // x0
  __int64 v11; // x8
  __int64 *v12; // x23
  __int64 (__fastcall *v13)(__int64, unsigned __int64); // x9
  __int64 v14; // x0
  unsigned int v15; // w0
  int v16; // w24
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  void (__fastcall *v25)(_QWORD); // x8
  __int64 v26; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    v4 = *(_QWORD *)(a1 + 128);
    if ( v4 )
    {
      if ( a2 )
        v5 = a2 + 16;
      else
        v5 = 0;
      inst_validate = cvp_get_inst_validate(v4, a1);
      if ( !inst_validate )
        return 4294967192LL;
      v7 = inst_validate;
      raw_spin_lock(a1 + 176);
      v8 = *(_DWORD *)(a1 + 180);
      if ( v8 == 4 )
        goto LABEL_53;
      if ( v8 == 3 )
      {
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
          printk(&unk_8D15C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
        raw_spin_unlock(a1 + 176);
        v9 = 0;
        goto LABEL_48;
      }
      if ( !*(_DWORD *)(a1 + 184) )
      {
LABEL_53:
        if ( (unsigned int)__ratelimit(&msm_cvp_session_stop__rs, "msm_cvp_session_stop") )
          printk(&unk_83036, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "sess");
        raw_spin_unlock(a1 + 176);
        v11 = *(_QWORD *)(a1 + 128);
        v12 = *(__int64 **)(v11 + 256);
        _X9 = (unsigned __int64 *)(v11 + 1296);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v23 = __ldxr(_X9);
          v24 = v23 + 1;
        }
        while ( __stlxr(v24, _X9) );
        __dmb(0xBu);
        if ( !v12 )
          goto LABEL_54;
        v13 = (__int64 (__fastcall *)(__int64, unsigned __int64))v12[7];
        if ( !v13 )
          goto LABEL_54;
        v14 = *(_QWORD *)(a1 + 320);
        if ( *((_DWORD *)v13 - 1) != 1021877503 )
          __break(0x8229u);
        v15 = v13(v14, v24 & 0x7FFFFFFFFFFFFFFFLL);
        if ( v15 )
        {
          v16 = 4;
          v9 = v15;
          if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
            printk(&unk_8450C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
        }
        else
        {
LABEL_54:
          if ( (unsigned int)wait_for_sess_signal_receipt(a1, 16) )
          {
            if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
              printk(&unk_89E43, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
            v9 = msm_cvp_session_flush_stop(a1);
            goto LABEL_48;
          }
          v9 = 0;
          v16 = 3;
        }
        raw_spin_lock(a1 + 176);
        *(_DWORD *)(a1 + 180) = v16;
        raw_spin_unlock(a1 + 176);
        _wake_up(a1 + 208, 3, 0, 0);
        cvp_fence_thread_stop(a1);
        if ( v12 )
        {
          v25 = (void (__fastcall *)(_QWORD))v12[23];
          if ( v25 )
          {
            v26 = *v12;
            if ( *((_DWORD *)v25 - 1) != -1066802076 )
              __break(0x8228u);
            v25(v26);
          }
        }
LABEL_48:
        cvp_put_inst(v7);
        if ( (unsigned int)__ratelimit(&msm_cvp_session_stop__rs_24, "msm_cvp_session_stop") )
          printk(&unk_89EA5, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "sess");
        return v9;
      }
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8DDAB, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        if ( !v5 )
          goto LABEL_22;
      }
      else if ( !v5 )
      {
LABEL_22:
        raw_spin_unlock(a1 + 176);
        v9 = -117;
        goto LABEL_48;
      }
      *(_DWORD *)(v5 + 4) = *(_DWORD *)(a1 + 184);
      goto LABEL_22;
    }
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_912BD, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
