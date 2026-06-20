__int64 __fastcall msm_cvp_session_flush_stop(__int64 a1)
{
  __int64 v2; // x0
  __int64 inst_validate; // x0
  __int64 v4; // x20
  unsigned int v5; // w6
  unsigned int v6; // w21
  __int64 result; // x0
  unsigned __int64 v8; // x8
  int v9; // w22
  __int64 v10; // x21
  unsigned int v11; // w0
  unsigned __int64 v12; // x8
  __int64 (__fastcall *v13)(__int64, unsigned __int64); // x9
  __int64 v14; // x0
  unsigned int v15; // w0
  unsigned __int64 v16; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned int v28; // w0
  unsigned __int64 v29; // x8

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 128);
    if ( v2 )
    {
      inst_validate = cvp_get_inst_validate(v2, a1);
      if ( !inst_validate )
        return 4294967192LL;
      v4 = inst_validate;
      raw_spin_lock(a1 + 176);
      v5 = *(_DWORD *)(a1 + 180);
      if ( v5 == 3 )
      {
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          printk(&unk_8D15C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
        }
        raw_spin_unlock(a1 + 176);
        v6 = 0;
        goto LABEL_40;
      }
      if ( v5 > 1 )
      {
        raw_spin_unlock(a1 + 176);
        v10 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 256LL);
        if ( (unsigned int)__ratelimit(&msm_cvp_session_flush_stop__rs, "msm_cvp_session_flush_stop") )
        {
          v19 = _ReadStatusReg(SP_EL0);
          printk(&unk_8A9AA, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), "sess");
        }
        v11 = cvp_session_flush_all(a1);
        if ( v11 )
        {
          v9 = 4;
          v6 = v11;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v12 = _ReadStatusReg(SP_EL0);
            printk(&unk_844C9, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
          }
          goto LABEL_39;
        }
        _X9 = (unsigned __int64 *)(*(_QWORD *)(a1 + 128) + 1296LL);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v26 = __ldxr(_X9);
          v27 = v26 + 1;
        }
        while ( __stlxr(v27, _X9) );
        __dmb(0xBu);
        if ( v10 )
        {
          v13 = *(__int64 (__fastcall **)(__int64, unsigned __int64))(v10 + 56);
          if ( v13 )
          {
            v14 = *(_QWORD *)(a1 + 320);
            if ( *((_DWORD *)v13 - 1) != 1021877503 )
              __break(0x8229u);
            v15 = v13(v14, v27 & 0x7FFFFFFFFFFFFFFFLL);
            if ( v15 )
            {
              v9 = 4;
              v6 = v15;
              if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
              {
                v16 = _ReadStatusReg(SP_EL0);
                printk(&unk_8450C, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), "warn");
              }
              goto LABEL_39;
            }
          }
        }
        v28 = wait_for_sess_signal_receipt(a1, 16);
        if ( v28 )
        {
          v9 = 4;
          v6 = v28;
          if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
          {
            v29 = _ReadStatusReg(SP_EL0);
            printk(&unk_9446C, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), "warn");
          }
          goto LABEL_39;
        }
      }
      else
      {
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v18 = _ReadStatusReg(SP_EL0);
          printk(&unk_8B3C8, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), "warn");
        }
        raw_spin_unlock(a1 + 176);
      }
      v6 = 0;
      v9 = 3;
LABEL_39:
      raw_spin_lock(a1 + 176);
      *(_DWORD *)(a1 + 180) = v9;
      raw_spin_unlock(a1 + 176);
      _wake_up(a1 + 208, 3, 0, 0);
      cvp_fence_thread_stop(a1);
LABEL_40:
      cvp_put_inst(v4);
      return v6;
    }
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v8 = _ReadStatusReg(SP_EL0);
    printk(&unk_912BD, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
