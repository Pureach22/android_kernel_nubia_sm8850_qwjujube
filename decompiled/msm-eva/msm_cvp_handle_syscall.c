__int64 __fastcall msm_cvp_handle_syscall(__int64 a1, unsigned int *a2)
{
  _DWORD *StatusReg; // x19
  __int64 v5; // x3
  unsigned int v6; // w22
  __int64 result; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  unsigned int v10; // w19
  int v11; // w5
  __int64 v12; // x0
  unsigned int v13; // w0
  int v14; // w8
  unsigned int v15; // w22
  __int64 pkt_name_from_type; // x23
  unsigned int v17; // w23
  unsigned __int64 aon_time; // x0
  unsigned int v19; // w4
  __int64 v20; // x1
  __int64 v21; // x2
  void *v22; // x0
  __int64 v23; // x1
  __int64 v24; // x2
  void *v25; // x0
  const char *v26; // x3
  __int64 v27; // x8
  __int64 *v28; // x8
  unsigned int v29; // w4
  unsigned int v30; // w23
  unsigned int v31; // w24
  __int64 v32; // x0
  int v33; // w22
  unsigned int *v34; // x28
  int *v35; // x25
  unsigned int v36; // w23
  unsigned int v37; // w8
  unsigned int v38; // w22
  int v39; // w0
  __int64 v40; // x24
  unsigned int v41; // w25
  int v42; // w0
  unsigned int *v43; // x28
  unsigned int v44; // w22
  unsigned int v45; // w8
  unsigned int v47; // w0
  unsigned int v48; // w28
  __int64 v49; // x0
  __int64 v50; // x9
  _QWORD *v51; // x8
  _QWORD *v52; // x9
  unsigned __int64 v59; // x9
  unsigned __int64 v61; // x8
  unsigned int pkt_index; // w0
  __int64 v63; // x8
  int v64; // w22
  int v65; // w25
  unsigned int v66; // w22
  unsigned __int64 v67; // x9
  __int64 v68; // x8
  int v69; // w21
  unsigned int v70; // w24
  __int64 v71; // x0
  unsigned int v72; // w28
  __int64 v73; // x25
  int v74; // w22
  int v75; // w25
  unsigned int v76; // w21
  __int64 v77; // x23
  __int64 (__fastcall *v78)(__int64, __int64, _DWORD *, const char *, _QWORD); // x8
  __int64 v79; // x0
  __int64 v80; // t1
  __int64 v81; // x8
  unsigned __int64 v82; // [xsp+18h] [xbp-28h]
  __int64 v83; // [xsp+38h] [xbp-8h]
  unsigned int v84; // [xsp+38h] [xbp-8h]

  StatusReg = (_DWORD *)_ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( !a1 || !a2 )
    {
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_95AEE, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
        return 4294967274LL;
      }
      return result;
    }
    if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
      printk(&unk_9702E, "hfi", "msm_cvp_handle_syscall", *a2);
    v5 = *a2;
    if ( (unsigned int)(v5 - 268439618) >= 3 )
    {
      mutex_lock(a1 + 80);
      v6 = *(_DWORD *)(a1 + 328) & 0xFFFFFFFE;
      mutex_unlock(a1 + 80);
      if ( v6 != 4 )
      {
        result = msm_cvp_session_create(a1);
        if ( (_DWORD)result )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v8 = (unsigned int)StatusReg[450];
            v9 = (unsigned int)StatusReg[451];
            v10 = result;
            printk(&unk_89461, v8, v9, &unk_8E7CE);
            return v10;
          }
          return result;
        }
      }
      v5 = *a2;
    }
    if ( (int)v5 <= 268439617 )
    {
      if ( (int)v5 <= 268439568 )
      {
        switch ( (_DWORD)v5 )
        {
          case 0x10001001:
            return msm_cvp_get_session_info(a1, a2 + 4);
          case 0x10001003:
            return msm_cvp_register_buffer(a1, a2 + 4);
          case 0x10001004:
            return msm_cvp_unregister_buffer(a1, a2 + 4);
        }
        goto LABEL_73;
      }
      if ( (_DWORD)v5 == 268439569 )
        return msm_cvp_update_power(a1);
      if ( (_DWORD)v5 != 268439616 )
      {
        if ( (_DWORD)v5 != 268439617 )
          goto LABEL_73;
        if ( cvp_get_inst_validate(*(_QWORD *)(a1 + 128), a1) )
        {
          v12 = _msecs_to_jiffies(*(unsigned int *)(*(_QWORD *)(a1 + 128) + 1024LL));
          v13 = cvp_wait_process_message(a1, a1 + 176, 0, v12, a2 + 4);
          v14 = msm_cvp_debug;
          v15 = v13;
          if ( (msm_cvp_debug & 0x20000) != 0
            && (pkt_name_from_type = get_pkt_name_from_type(a2[5]),
                get_aon_time(),
                v14 = msm_cvp_debug,
                (msm_cvp_debug & 0x20000) != 0)
            && !msm_cvp_debug_out )
          {
            printk(&unk_84F4D, "perf", "msm_cvp_session_receive_hfi", pkt_name_from_type);
            if ( (msm_cvp_debug & 0x10000) != 0 )
            {
LABEL_38:
              v17 = a2[5];
              if ( v17 > 0x4021000 && a2[4] >= 0x44 )
              {
                get_pkt_name_from_type(v17);
                aon_time = get_aon_time();
                if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
                  printk(&unk_85F5D, "info", aon_time, "EVA_KMD_REV_END");
              }
            }
          }
          else if ( (v14 & 0x10000) != 0 )
          {
            goto LABEL_38;
          }
          cvp_put_inst(a1);
          return v15;
        }
        return 4294967192LL;
      }
      v30 = a2[1];
      v31 = a2[2];
      v32 = *(_QWORD *)(a1 + 128);
      if ( v32 )
      {
        if ( *(_DWORD *)(a1 + 328) == 9 )
        {
          result = 4294967192LL;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_8F5EE, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            return 4294967192LL;
          }
          return result;
        }
        if ( !cvp_get_inst_validate(v32, a1) )
          return 4294967192LL;
        raw_spin_lock(a1 + 176);
        v38 = *(_DWORD *)(a1 + 180);
        raw_spin_unlock(a1 + 176);
        if ( v38 >= 4 )
        {
          v39 = -22;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_8AA40, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            v39 = -22;
          }
LABEL_212:
          v76 = v39;
          cvp_put_inst(a1);
          return v76;
        }
        if ( (msm_cvp_debug & 8) != 0 && !msm_cvp_debug_out )
          printk(&unk_83907, "cmd", "msm_cvp_session_process_hfi", a2[5]);
        pkt_index = get_pkt_index(a2 + 4);
        if ( (pkt_index & 0x80000000) != 0 )
        {
          v39 = 0;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_84FA2, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            v39 = 0;
          }
          goto LABEL_212;
        }
        v63 = cvp_hfi_defs + 84LL * pkt_index;
        v64 = *(unsigned __int8 *)(v63 + 8);
        v65 = *(_DWORD *)(v63 + 12);
        if ( v64 == 1 && (unsigned int)__ratelimit(&msm_cvp_session_process_hfi__rs, "msm_cvp_session_process_hfi") )
        {
          printk(&unk_90318, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], "sess");
          if ( v65 )
            goto LABEL_173;
        }
        else if ( v65 )
        {
LABEL_173:
          if ( v30 )
            v66 = v31;
          else
            v66 = 0;
          if ( !v31 )
            v30 = 0;
          if ( v66 > 0x32
            || v30 >> 30
            || (v67 = 4 * v30, v68 = 48 * v66, (v68 ^ 0xFFFFFFFFuLL) < v67)
            || v67 + v68 >= 0x969 )
          {
            v39 = -22;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8AA88, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
              v39 = -22;
            }
          }
          else
          {
            v39 = msm_cvp_proc_oob(a1, a2 + 4);
            if ( v39 )
            {
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                v69 = v39;
                printk(&unk_8B468, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
                v39 = v69;
              }
            }
            else
            {
              if ( (msm_cvp_debug & 0x10000) != 0 )
              {
                v70 = a2[5];
                if ( v70 > 0x4011000 && a2[4] >= 0x40 )
                {
                  v84 = a2[6];
                  v71 = get_pkt_name_from_type(v70);
                  v72 = a2[18];
                  v73 = v71;
                  v82 = get_aon_time();
                  trace_tracing_eva_frame_from_sw_0(v82, "EVA_KMD_FWD_BEGIN", v84, v72, v70, v73);
                  if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
                    printk(&unk_85F5D, "info", v82, "EVA_KMD_FWD_BEGIN");
                }
              }
              v39 = cvp_enqueue_pkt(a1, a2 + 4, v30, v66);
              if ( v39 && (msm_cvp_debug & 1) != 0 )
              {
                v74 = v39;
                if ( !msm_cvp_debug_out )
                  printk(&unk_8DEA3, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
                v39 = v74;
              }
            }
          }
          goto LABEL_212;
        }
        raw_spin_lock(a1 + 176);
        v75 = *(_DWORD *)(a1 + 180);
        raw_spin_unlock(a1 + 176);
        if ( v75 != 2 && (v64 & 1) == 0 )
        {
          v39 = -22;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_93BEB, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            v39 = -22;
          }
          goto LABEL_212;
        }
        goto LABEL_173;
      }
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        return result;
      v23 = (unsigned int)StatusReg[450];
      v24 = (unsigned int)StatusReg[451];
      v25 = &unk_912BD;
      v26 = (const char *)&unk_8E7CE;
LABEL_98:
      printk(v25, v23, v24, v26);
      return 4294967274LL;
    }
    if ( (int)v5 > 268439620 )
      break;
    if ( (_DWORD)v5 == 268439618 )
    {
      v19 = a2[4];
      if ( v19 >= 0x41 )
      {
        result = 4294967289LL;
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          return result;
        v20 = (unsigned int)StatusReg[450];
        v21 = (unsigned int)StatusReg[451];
        v22 = &unk_91675;
LABEL_66:
        printk(v22, v20, v21, &unk_8E7CE);
        return 4294967289LL;
      }
      result = 0;
      if ( v19 )
      {
        v33 = 0;
        v34 = a2 + 5;
        do
        {
          v35 = (int *)&v34[2 * v33];
          v36 = result;
          if ( (unsigned int)msm_cvp_set_sysprop_sess(a1, v35, v33)
            && (unsigned int)msm_cvp_set_sysprop_pwr_hw(a1, (int *)&v34[2 * v33])
            && (unsigned int)msm_cvp_set_sysprop_pwr_op(a1, (int *)&v34[2 * v33]) )
          {
            v37 = *v35 - 30;
            if ( v37 <= 0x12 && ((0x4924Fu >> v37) & 1) != 0 )
            {
              result = v36;
              *(_DWORD *)((char *)*(&off_6AC50 + v37) + a1) = v35[1];
            }
            else
            {
              result = 4294967282LL;
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                printk(&unk_83AE8, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
                result = 4294967282LL;
              }
            }
          }
          else
          {
            result = v36;
          }
          ++v33;
        }
        while ( v33 < a2[4] );
      }
      return result;
    }
    if ( (_DWORD)v5 != 268439619 )
    {
      v11 = a2[4];
      if ( v11 > 2 )
      {
        if ( v11 == 3 )
          return msm_cvp_session_start(a1);
        if ( v11 == 4 )
          return msm_cvp_session_stop(a1, (__int64)a2);
      }
      else
      {
        if ( v11 == 1 )
          return msm_cvp_session_create(a1);
        if ( v11 == 2 )
          return 0;
      }
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8C7A5, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
        return 4294967274LL;
      }
      return result;
    }
    v27 = *(_QWORD *)(a1 + 128);
    if ( !v27 || (v28 = *(__int64 **)(v27 + 256)) == nullptr )
    {
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        return result;
      v23 = (unsigned int)StatusReg[450];
      v24 = (unsigned int)StatusReg[451];
      v25 = &unk_912BD;
      v26 = (const char *)&unk_8E7CE;
      goto LABEL_98;
    }
    v29 = a2[4];
    if ( v29 > 0x40 )
    {
      result = 4294967289LL;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        return result;
      v20 = (unsigned int)StatusReg[450];
      v21 = (unsigned int)StatusReg[451];
      v22 = &unk_8457A;
      goto LABEL_66;
    }
    if ( !v29 )
      return 0;
    v40 = 0;
    result = 0;
    v41 = 0;
    v83 = *v28;
    while ( v40 != 64 )
    {
      v43 = &a2[2 * v40 + 5];
      v44 = result;
      switch ( *v43 )
      {
        case 1u:
          v45 = *(_DWORD *)(v83 + 16);
          goto LABEL_149;
        case 7u:
          v45 = *(_DWORD *)(a1 + 14988);
          goto LABEL_149;
        case 8u:
          v45 = *(_DWORD *)(a1 + 14992);
          goto LABEL_149;
        case 9u:
          _X9 = *(unsigned __int64 **)(*(_QWORD *)(v83 + 736) + 8LL);
          __asm { PRFM            #0x11, [X9] }
          do
            v61 = __ldxr(_X9);
          while ( __stxr(v61 + 1, _X9) );
          if ( !v61 && (get_file___already_done & 1) == 0 )
          {
            get_file___already_done = 1;
            _warn_printk("struct file::f_count incremented from zero; use-after-free condition present!\n");
            __break(0x800u);
          }
          v47 = dma_buf_fd(*(_QWORD *)(v83 + 736), 0x80000);
          if ( (v47 & 0x80000000) == 0 )
            goto LABEL_147;
          v48 = v47;
          if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
            printk(&unk_8F65F, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], "warn");
          v49 = *(_QWORD *)(v83 + 736);
          goto LABEL_159;
        case 0xAu:
          v45 = *(_DWORD *)(a1 + 15260);
LABEL_149:
          v43[1] = v45;
          goto LABEL_115;
        case 0xBu:
          _X8 = *(unsigned __int64 **)(*(_QWORD *)(v83 + 2592) + 8LL);
          __asm { PRFM            #0x11, [X8] }
          do
            v59 = __ldxr(_X8);
          while ( __stxr(v59 + 1, _X8) );
          if ( !v59 && (get_file___already_done & 1) == 0 )
          {
            get_file___already_done = 1;
            _warn_printk("struct file::f_count incremented from zero; use-after-free condition present!\n");
            __break(0x800u);
          }
          v47 = dma_buf_fd(*(_QWORD *)(v83 + 2592), 524290);
          if ( (v47 & 0x80000000) != 0 )
          {
            v48 = v47;
            if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
              printk(&unk_91638, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], "warn");
            v49 = *(_QWORD *)(v83 + 2592);
LABEL_159:
            dma_buf_put(v49);
            result = v48;
          }
          else
          {
LABEL_147:
            v43[1] = v47;
            result = 0;
          }
          goto LABEL_116;
        case 0xCu:
          v50 = *(_QWORD *)(a1 + 128);
          result = (unsigned int)result;
          v51 = *(_QWORD **)(v50 + 280);
          v52 = (_QWORD *)(v50 + 280);
          break;
        case 0x10u:
          v42 = 0;
          goto LABEL_114;
        case 0x11u:
          v42 = 3;
          goto LABEL_114;
        case 0x12u:
          v42 = 2;
          goto LABEL_114;
        case 0x13u:
          v42 = 1;
          goto LABEL_114;
        case 0x22u:
          v42 = 4;
          goto LABEL_114;
        case 0x25u:
          v42 = 5;
          goto LABEL_114;
        case 0x28u:
          v42 = 6;
          goto LABEL_114;
        case 0x2Bu:
          v42 = 7;
          goto LABEL_114;
        case 0x2Eu:
          v42 = 8;
LABEL_114:
          v43[1] = msm_cvp_get_hw_aggregate_cycles(v42);
LABEL_115:
          result = v44;
          goto LABEL_116;
        default:
          result = 4294967282LL;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_85958, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], &unk_8E7CE);
            result = 4294967282LL;
          }
          goto LABEL_116;
      }
      while ( v51 != v52 )
      {
        if ( v51 )
        {
          if ( v51 == (_QWORD *)a1 )
          {
            v43[1] = v41;
            break;
          }
          ++v41;
        }
        v51 = (_QWORD *)*v51;
      }
LABEL_116:
      if ( ++v40 >= (unsigned __int64)a2[4] )
        return result;
    }
    __break(0x5512u);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)(unsigned int)StatusReg[10] >> 3) & 0x1FFFFFF8)) >> StatusReg[10])
        & 1) != 0 )
    {
      ++StatusReg[4];
      v77 = qword_977D8;
      if ( qword_977D8 )
      {
        do
        {
          v78 = *(__int64 (__fastcall **)(__int64, __int64, _DWORD *, const char *, _QWORD))v77;
          v79 = *(_QWORD *)(v77 + 8);
          if ( *(_DWORD *)(*(_QWORD *)v77 - 4LL) != -641035679 )
            __break(0x8228u);
          result = v78(v79, 66, StatusReg, "msm_cvp_handle_syscall", 0);
          v80 = *(_QWORD *)(v77 + 24);
          v77 += 24;
        }
        while ( v80 );
      }
      v81 = *((_QWORD *)StatusReg + 2) - 1LL;
      StatusReg[4] = v81;
      if ( !v81 || !*((_QWORD *)StatusReg + 2) )
        preempt_schedule_notrace(result);
    }
  }
  switch ( (_DWORD)v5 )
  {
    case 0x10001045:
      result = 4294967274LL;
      if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
        return result;
      v23 = (unsigned int)StatusReg[450];
      v24 = (unsigned int)StatusReg[451];
      v25 = &unk_8F62A;
      v26 = "warn";
      goto LABEL_98;
    case 0x10001046:
      return cvp_session_flush_all(a1);
    case 0x10001047:
      result = 0;
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8DDEE, (unsigned int)StatusReg[450], (unsigned int)StatusReg[451], "warn");
        return 0;
      }
      break;
    default:
LABEL_73:
      result = 4294966772LL;
      if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_84EE4, "hfi", "msm_cvp_handle_syscall", v5);
        return 4294966772LL;
      }
      break;
  }
  return result;
}
