__int64 __fastcall msm_cvp_comm_try_state(__int64 a1, unsigned int a2)
{
  _DWORD *StatusReg; // x19
  __int64 v5; // x22
  __int64 v6; // x2
  __int64 v7; // x3
  unsigned int v8; // w5
  int v9; // w24
  char v10; // w8
  int v11; // w9
  unsigned int v12; // w22
  unsigned int v13; // w5
  int v14; // w8
  __int64 result; // x0
  __int64 v16; // x8
  __int64 *v17; // x22
  int v18; // w26
  __int64 v20; // x23
  __int64 *v21; // x22
  __int64 v22; // x3
  __int64 v23; // x2
  int v24; // w8
  __int16 v25; // w9
  unsigned int (__fastcall *v26)(__int64, __int64, __int64); // x8
  __int64 v27; // x0
  unsigned int v28; // w5
  int v29; // w8
  int v31; // w8
  __int16 v32; // w9
  unsigned int v33; // w0
  __int64 v34; // x0
  __int64 (__fastcall *v35)(_QWORD); // x8
  __int64 v36; // x0
  unsigned int v37; // w0
  unsigned int v38; // w5
  int v39; // w8
  int v41; // w9
  __int64 v42; // x8
  __int64 v43; // x22
  __int64 (__fastcall *v44)(_QWORD); // x8
  __int64 v45; // x0
  unsigned int v46; // w0
  unsigned int v47; // w5
  int v48; // w8
  __int16 v50; // w8
  int v51; // w9
  unsigned int v52; // w5
  int v53; // w8
  unsigned int v55; // w5
  int v56; // w8
  unsigned int v58; // w0
  unsigned int v59; // w5
  int v60; // w8
  __int64 v62; // x0
  __int64 v63; // x8

  StatusReg = (_DWORD *)_ReadStatusReg(SP_EL0);
  while ( a1 )
  {
    v5 = *(_QWORD *)(cvp_driver + 48);
    mutex_lock(a1 + 32);
    v8 = *(_DWORD *)(a1 + 328);
    if ( v8 == 9 && !*(_DWORD *)(v5 + 304) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_897B7, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
      mutex_unlock(a1 + 32);
      return 4294967274LL;
    }
    if ( a2 > 9 || v8 >= 0xA )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_8657C, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
      goto LABEL_30;
    }
    if ( v8 == 9 )
      v9 = 6;
    else
      v9 = *(_DWORD *)(a1 + 328);
    if ( a2 >= 7 && v8 == 3 )
      goto LABEL_12;
    if ( v9 <= 4 )
    {
      if ( v9 > 2 )
      {
        if ( v9 == 3 )
          goto LABEL_255;
      }
      else
      {
        if ( v9 == 1 )
        {
          if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
            printk(&unk_8D394, "sess", a1, (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
        }
        else if ( v9 != 2 )
        {
          goto LABEL_30;
        }
        if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
        {
          if ( *(_DWORD *)(a1 + 328) > 0xAu )
            goto LABEL_282;
          printk(&unk_8D394, "sess", a1, (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
        }
        v20 = *(_QWORD *)(a1 + 128);
        if ( !v20 || (v21 = *(__int64 **)(v20 + 256)) == nullptr )
        {
          v12 = -22;
          goto LABEL_262;
        }
        mutex_lock(*(_QWORD *)(a1 + 128));
        v23 = *(unsigned int *)(v20 + 304);
        if ( (_DWORD)v23 )
        {
          if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
            printk(&unk_8C998, "core", v23, v22);
          goto LABEL_242;
        }
        if ( *(_QWORD *)(v20 + 1096) )
        {
          v24 = msm_cvp_debug_out;
          v25 = msm_cvp_debug;
          if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_8F9FE, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], "warn");
            v25 = msm_cvp_debug;
            v24 = msm_cvp_debug_out;
          }
        }
        else
        {
          v34 = _kmalloc_large_noprof(23424, 3520);
          *(_QWORD *)(v20 + 1096) = v34;
          v25 = msm_cvp_debug;
          v24 = msm_cvp_debug_out;
          if ( !v34 )
          {
            v12 = -12;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              printk(&unk_93E2A, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            goto LABEL_141;
          }
        }
        if ( (v25 & 0x100) != 0 && !v24 )
        {
          printk(&unk_8CA45, "core", "msm_comm_init_core", v20);
          v35 = (__int64 (__fastcall *)(_QWORD))v21[1];
          if ( v35 )
            goto LABEL_134;
        }
        else
        {
          v35 = (__int64 (__fastcall *)(_QWORD))v21[1];
          if ( v35 )
          {
LABEL_134:
            v36 = *v21;
            if ( *((_DWORD *)v35 - 1) != -1066802076 )
              __break(0x8228u);
            v37 = v35(v36);
            if ( v37 )
            {
              v12 = v37;
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                printk(&unk_8FF0B, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
              kfree(*(_QWORD *)(v20 + 1096));
LABEL_141:
              *(_QWORD *)(v20 + 1096) = 0;
              *(_DWORD *)(v20 + 304) = 0;
              mutex_unlock(v20);
              goto LABEL_262;
            }
          }
        }
        *(_BYTE *)(v20 + 1268) = 0;
        *(_DWORD *)(v20 + 304) = 1;
LABEL_242:
        change_cvp_inst_state(a1, 2u);
        mutex_unlock(v20);
        v55 = *(_DWORD *)(a1 + 328);
        if ( v55 < 0xA )
        {
          if ( v55 == 9 )
            v56 = 6;
          else
            v56 = *(_DWORD *)(a1 + 328);
          if ( v55 == 3 && a2 > 6 )
            v56 = 8;
        }
        else
        {
          v56 = -22;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_8657C, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            v56 = -22;
          }
        }
        if ( v56 >= (int)a2 )
          goto LABEL_65;
LABEL_255:
        if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
        {
          if ( *(_DWORD *)(a1 + 328) > 0xAu )
            goto LABEL_282;
          printk(&unk_8D394, "sess", a1, (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
        }
        v58 = msm_cvp_comm_check_core_init(*(_QWORD *)(a1 + 128));
        if ( v58 )
        {
          v12 = v58;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            printk(&unk_8EF2B, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
          msm_cvp_comm_generate_sys_error(a1);
          goto LABEL_262;
        }
        change_cvp_inst_state(a1, 3u);
        v59 = *(_DWORD *)(a1 + 328);
        if ( v59 < 0xA )
        {
          if ( v59 == 9 )
            v60 = 6;
          else
            v60 = *(_DWORD *)(a1 + 328);
          if ( v59 == 3 && a2 > 6 )
            v60 = 8;
        }
        else
        {
          v60 = -22;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_8657C, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            v60 = -22;
          }
        }
        if ( v60 >= (int)a2 )
          goto LABEL_65;
      }
      if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
      {
        if ( *(_DWORD *)(a1 + 328) > 0xAu )
          goto LABEL_282;
        printk(&unk_8D394, "sess", a1, (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
      }
      v16 = *(_QWORD *)(a1 + 128);
      if ( !v16 || (v17 = *(__int64 **)(v16 + 256)) == nullptr )
      {
        v12 = -22;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          printk(&unk_83D1E, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
        goto LABEL_262;
      }
      if ( (unsigned int)v9 >= 4 )
      {
        v12 = 0;
        v18 = 1;
        if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_9679F, "info", a1, *(unsigned int *)(a1 + 328));
          v12 = 0;
        }
        goto LABEL_101;
      }
      if ( (msm_cvp_debug & 0x2000) == 0 || msm_cvp_debug_out )
      {
        v26 = (unsigned int (__fastcall *)(__int64, __int64, __int64))v17[4];
        if ( v26 )
          goto LABEL_93;
        goto LABEL_96;
      }
      printk(&unk_8290F, "sess", "msm_comm_session_init", a1);
      v26 = (unsigned int (__fastcall *)(__int64, __int64, __int64))v17[4];
      if ( !v26 )
        goto LABEL_96;
LABEL_93:
      v27 = *v17;
      if ( *((_DWORD *)v26 - 1) != 228438788 )
        __break(0x8228u);
      if ( !v26(v27, a1, a1 + 320) )
      {
LABEL_96:
        if ( *(_QWORD *)(a1 + 320) )
        {
          change_cvp_inst_state(a1, 4u);
          v12 = 0;
          v18 = 1;
LABEL_101:
          if ( !v18 )
            goto LABEL_262;
          v28 = *(_DWORD *)(a1 + 328);
          if ( v28 < 0xA )
          {
            if ( v28 == 9 )
              v29 = 6;
            else
              v29 = *(_DWORD *)(a1 + 328);
            if ( v28 == 3 && a2 > 6 )
              v29 = 8;
          }
          else
          {
            v29 = -22;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8657C, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
              v29 = -22;
            }
          }
          if ( v29 >= (int)a2 )
            goto LABEL_65;
LABEL_115:
          if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
          {
            if ( *(_DWORD *)(a1 + 328) > 0xAu )
              goto LABEL_282;
            printk(&unk_8D394, "sess", a1, (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
          }
          v31 = msm_cvp_debug_out;
          v32 = msm_cvp_debug;
          if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_879DC, "sess", a1, v7);
            v32 = msm_cvp_debug;
            v31 = msm_cvp_debug_out;
            if ( (unsigned int)v9 < 5 )
              goto LABEL_120;
          }
          else if ( (unsigned int)v9 < 5 )
          {
LABEL_120:
            if ( (v32 & 0x2000) != 0 && !v31 )
              printk(&unk_8E22D, "sess", 11, v7);
            v33 = wait_for_sess_signal_receipt(a1, 11);
            if ( v33 )
            {
              v12 = v33;
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                printk(&unk_90551, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
              goto LABEL_262;
            }
            change_cvp_inst_state(a1, 5u);
LABEL_150:
            v38 = *(_DWORD *)(a1 + 328);
            if ( v38 < 0xA )
            {
              if ( v38 == 9 )
                v39 = 6;
              else
                v39 = *(_DWORD *)(a1 + 328);
              if ( v38 == 3 && a2 > 6 )
                v39 = 8;
            }
            else
            {
              v39 = -22;
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                printk(&unk_8657C, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
                v39 = -22;
              }
            }
            if ( v39 >= (int)a2 )
              goto LABEL_65;
LABEL_163:
            v41 = msm_cvp_debug_out;
            if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
            {
              if ( *(_DWORD *)(a1 + 328) > 0xAu )
                goto LABEL_282;
              printk(&unk_8D394, "sess", a1, (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
              v41 = msm_cvp_debug_out;
              if ( (msm_cvp_debug & 4) != 0 )
              {
LABEL_166:
                if ( !v41 )
                  printk(&unk_8EED4, "info", v6, v7);
              }
            }
            else if ( (msm_cvp_debug & 4) != 0 )
            {
              goto LABEL_166;
            }
            v42 = *(_QWORD *)(a1 + 128);
            if ( !v42 || (v43 = *(_QWORD *)(v42 + 256)) == 0 )
            {
              v12 = -22;
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                printk(&unk_86F4F, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
              goto LABEL_262;
            }
            if ( (unsigned int)v9 >= 6 )
            {
              v12 = 0;
              if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
              {
                printk(&unk_9679F, "info", a1, *(unsigned int *)(a1 + 328));
                goto LABEL_194;
              }
              goto LABEL_195;
            }
            if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8290F, "sess", "msm_comm_session_close", a1);
              v44 = *(__int64 (__fastcall **)(_QWORD))(v43 + 40);
              if ( v44 )
                goto LABEL_180;
            }
            else
            {
              v44 = *(__int64 (__fastcall **)(_QWORD))(v43 + 40);
              if ( v44 )
              {
LABEL_180:
                v45 = *(_QWORD *)(a1 + 320);
                if ( *((_DWORD *)v44 - 1) != -1066802076 )
                  __break(0x8228u);
                v46 = v44(v45);
                if ( v46 )
                {
                  v12 = v46;
                  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                    printk(&unk_87A15, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
                  goto LABEL_195;
                }
              }
            }
            change_cvp_inst_state(a1, 6u);
LABEL_194:
            v12 = 0;
LABEL_195:
            if ( v12 )
              goto LABEL_262;
            v47 = *(_DWORD *)(a1 + 328);
            if ( v47 < 0xA )
            {
              if ( v47 == 9 )
                v48 = 6;
              else
                v48 = *(_DWORD *)(a1 + 328);
              if ( v47 == 3 && a2 > 6 )
                v48 = 8;
            }
            else
            {
              v48 = -22;
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                printk(&unk_8657C, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
                v48 = -22;
              }
            }
            if ( v48 >= (int)a2 )
              goto LABEL_65;
LABEL_209:
            v50 = msm_cvp_debug;
            v51 = msm_cvp_debug_out;
            if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
            {
              if ( *(_DWORD *)(a1 + 328) > 0xAu )
                goto LABEL_282;
              printk(&unk_8D394, "sess", a1, (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
              v50 = msm_cvp_debug;
              v51 = msm_cvp_debug_out;
              if ( (msm_cvp_debug & 4) != 0 )
              {
LABEL_212:
                if ( !v51 )
                {
                  printk(&unk_90508, "info", v6, v7);
                  v50 = msm_cvp_debug;
                  v51 = msm_cvp_debug_out;
                }
              }
            }
            else if ( (msm_cvp_debug & 4) != 0 )
            {
              goto LABEL_212;
            }
            if ( (unsigned int)v9 >= 7 )
            {
              if ( (v50 & 4) != 0 && !v51 )
                printk(&unk_9679F, "info", a1, *(unsigned int *)(a1 + 328));
            }
            else
            {
              if ( (v50 & 0x2000) != 0 && !v51 )
                printk(&unk_8E22D, "sess", 12, v7);
              v12 = wait_for_sess_signal_receipt(a1, 12);
              if ( v12 )
                goto LABEL_262;
              change_cvp_inst_state(a1, 7u);
            }
            v52 = *(_DWORD *)(a1 + 328);
            if ( v52 < 0xA )
            {
              if ( v52 == 9 )
                v53 = 6;
              else
                v53 = *(_DWORD *)(a1 + 328);
              if ( v52 == 3 && a2 > 6 )
                v53 = 8;
            }
            else
            {
              v53 = -22;
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                printk(&unk_8657C, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
                v53 = -22;
              }
            }
            if ( v53 >= (int)a2 )
              goto LABEL_65;
            msm_cvp_comm_session_clean(a1);
            goto LABEL_12;
          }
          if ( (v32 & 4) != 0 && !v31 )
            printk(&unk_9679F, "info", a1, *(unsigned int *)(a1 + 328));
          goto LABEL_150;
        }
      }
      v18 = 0;
      v12 = -22;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_95268, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
        v18 = 0;
      }
      goto LABEL_101;
    }
    if ( v9 <= 6 )
    {
      if ( v9 == 5 )
        goto LABEL_115;
      goto LABEL_163;
    }
    if ( v9 == 7 )
      goto LABEL_209;
LABEL_12:
    v10 = msm_cvp_debug;
    v11 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
    {
      if ( *(_DWORD *)(a1 + 328) > 0xAu )
        goto LABEL_282;
      printk(&unk_8D394, "sess", a1, (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
      v10 = msm_cvp_debug;
      v11 = msm_cvp_debug_out;
      if ( (msm_cvp_debug & 0x2000) == 0 )
        goto LABEL_16;
    }
    else if ( (msm_cvp_debug & 0x2000) == 0 )
    {
      goto LABEL_16;
    }
    if ( v11 )
      goto LABEL_16;
    if ( *(_DWORD *)(a1 + 328) <= 0xAu )
    {
      printk(&unk_8D394, "sess", a1, (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
      v10 = msm_cvp_debug;
      v11 = msm_cvp_debug_out;
LABEL_16:
      if ( (v10 & 4) != 0 && !v11 )
        printk(&unk_90CB0, "info", v6, v7);
      v12 = msm_cvp_deinit_core(a1);
      if ( v12 )
      {
LABEL_262:
        mutex_unlock(a1 + 32);
        return msm_cvp_state_result_check(a1, v12, a2);
      }
      v13 = *(_DWORD *)(a1 + 328);
      if ( v13 < 0xA )
      {
        if ( v13 == 9 )
          v14 = 6;
        else
          v14 = *(_DWORD *)(a1 + 328);
        if ( v13 == 3 && a2 > 6 )
          v14 = 8;
      }
      else
      {
        v14 = -22;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_8657C, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
          v14 = -22;
        }
      }
      if ( v14 >= (int)a2 )
      {
LABEL_65:
        v12 = 0;
        goto LABEL_262;
      }
LABEL_30:
      v12 = -22;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_846DD, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
      goto LABEL_262;
    }
LABEL_282:
    __break(0x5512u);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)(unsigned int)StatusReg[10] >> 3) & 0x1FFFFFF8)) >> StatusReg[10])
        & 1) != 0 )
    {
      ++StatusReg[4];
      v62 = _traceiter_tracing_mark_write(0, 0x42u, (__int64)StatusReg, (__int64)"msm_cvp_comm_try_state", 0);
      v63 = *((_QWORD *)StatusReg + 2) - 1LL;
      StatusReg[4] = v63;
      if ( !v63 || !*((_QWORD *)StatusReg + 2) )
        preempt_schedule_notrace(v62);
    }
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_87927, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
