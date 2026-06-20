__int64 __fastcall cvp_session_flush_all(__int64 a1)
{
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x0
  __int64 inst_validate; // x0
  __int64 v5; // x21
  __int64 v6; // x22
  int v7; // w0
  unsigned int v8; // w22
  __int64 result; // x0
  __int64 (__fastcall *v10)(__int64, unsigned __int64); // x9
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  void *v14; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  int v23; // w22
  _QWORD *v24; // x24
  _QWORD *v25; // x23
  char v26; // w8
  int v27; // w9
  int v28; // w22
  int v29; // w9
  unsigned __int64 v30; // x23
  unsigned __int64 v31; // x8
  int v32; // w22
  _QWORD *v33; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( a1 && (v3 = *(_QWORD *)(a1 + 128)) != 0 )
  {
    inst_validate = cvp_get_inst_validate(v3, a1);
    if ( inst_validate )
    {
      v5 = inst_validate;
      if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
        printk(&unk_93BB7, "sess", a1, (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
      v6 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 256LL);
      v7 = cvp_clean_fence_queue(a1);
      if ( v7 )
        goto LABEL_8;
      if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
        printk(
          &unk_8B417,
          "sess",
          "cvp_session_flush_all",
          (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
      _X9 = (unsigned __int64 *)(*(_QWORD *)(a1 + 128) + 1296LL);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v21 = __ldxr(_X9);
        v22 = v21 + 1;
      }
      while ( __stlxr(v22, _X9) );
      __dmb(0xBu);
      if ( !v6 )
        goto LABEL_27;
      v10 = *(__int64 (__fastcall **)(__int64, unsigned __int64))(v6 + 96);
      if ( !v10 )
        goto LABEL_27;
      v11 = *(_QWORD *)(a1 + 320);
      if ( *((_DWORD *)v10 - 1) != 1021877503 )
        __break(0x8229u);
      v7 = v10(v11, v22 & 0x7FFFFFFFFFFFFFFFLL);
      if ( v7 )
      {
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          goto LABEL_8;
        v12 = *(unsigned int *)(StatusReg + 1800);
        v13 = *(unsigned int *)(StatusReg + 1804);
        v14 = &unk_96571;
      }
      else
      {
LABEL_27:
        v7 = wait_for_sess_signal_receipt(a1, 18);
        if ( !v7 )
        {
          if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
            printk(
              &unk_93176,
              "sess",
              "cvp_session_flush_all",
              (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
          v24 = (_QWORD *)(a1 + 15368);
          if ( *(_QWORD *)(a1 + 15368) != a1 + 15368 )
          {
            mutex_lock(a1 + 15272);
            v25 = (_QWORD *)*v24;
            if ( (_QWORD *)*v24 == v24 )
            {
              v28 = 0;
            }
            else
            {
              v26 = msm_cvp_debug;
              v27 = msm_cvp_debug_out;
              v28 = 0;
              do
              {
                if ( v26 < 0 && !v27 )
                {
                  printk(
                    &unk_8D198,
                    "synx",
                    "cvp_drain_fence_sched_list",
                    *(_QWORD *)(v25[38] + 32LL) & 0x7FFFFFFFFFFFFFFFLL);
                  v26 = msm_cvp_debug;
                  v27 = msm_cvp_debug_out;
                }
                v25 = (_QWORD *)*v25;
                ++v28;
              }
              while ( v25 != v24 );
            }
            mutex_unlock(a1 + 15272);
            v29 = *(_DWORD *)(*(_QWORD *)(a1 + 128) + 1024LL);
            v30 = v29 * (__int64)(1000 * v28);
            if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
              printk(&unk_88D61, "synx", "cvp_drain_fence_sched_list", v29 * (__int64)(1000 * v28));
            v31 = v30 / 0x64;
            if ( (int)(v30 / 0x64) <= 1 )
              LODWORD(v31) = 1;
            v32 = -(int)v31;
            while ( 1 )
            {
              mutex_lock(a1 + 15272);
              v33 = (_QWORD *)*v24;
              mutex_unlock(a1 + 15272);
              if ( v33 == v24 )
                break;
              usleep_range_state(100, 200, 2);
              if ( __CFADD__(v32++, 1) )
              {
                v7 = -110;
                if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                {
                  printk(
                    &unk_862BF,
                    *(unsigned int *)(StatusReg + 1800),
                    *(unsigned int *)(StatusReg + 1804),
                    &unk_8E7CE);
                  v7 = -110;
                }
                goto LABEL_8;
              }
            }
          }
          v7 = 0;
          goto LABEL_8;
        }
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        {
LABEL_8:
          v8 = v7;
          mutex_lock(a1 + 15272);
          *(_DWORD *)(a1 + 15324) = 0;
          mutex_unlock(a1 + 15272);
          cvp_put_inst(v5);
          return v8;
        }
        v12 = *(unsigned int *)(StatusReg + 1800);
        v13 = *(unsigned int *)(StatusReg + 1804);
        v14 = &unk_8624A;
      }
      v23 = v7;
      printk(v14, v12, v13, &unk_8E7CE);
      v7 = v23;
      goto LABEL_8;
    }
    return 4294967192LL;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_912BD, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
