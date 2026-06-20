__int64 __fastcall cam_cci_irq(__int64 a1, __int64 a2)
{
  char *v2; // x19
  unsigned int v4; // w20
  unsigned int v5; // w22
  __int64 v6; // x0
  unsigned int v7; // w23
  _BOOL4 v8; // w24
  _BOOL4 v9; // w28
  __int64 v10; // x0
  int v11; // w23
  __int64 v12; // x0
  int v13; // w8
  __int64 v14; // x0
  int v15; // w8
  int v16; // w0
  int v17; // w8
  int v18; // w8
  __int64 v19; // x8
  unsigned int v20; // w23
  __int64 v21; // x0
  unsigned int v22; // w1
  __int64 v23; // x24
  int v24; // w8
  char *v25; // x9
  __int64 v26; // x0
  char *v27; // x9
  __int64 v28; // x0
  int v29; // w8
  char *v30; // x9
  __int64 v31; // x0
  char *v32; // x9
  __int64 v33; // x0
  __int64 v34; // x24
  __int64 v35; // x0
  __int64 v36; // x24
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x24
  __int64 v40; // x0
  __int64 v41; // x24
  int v42; // w8
  unsigned __int64 StatusReg; // x23
  __int64 v45; // x0
  __int64 v46; // x8

  v2 = *(char **)(a2 + 672);
  v4 = cam_io_r_mb(v2 + 3084);
  v5 = cam_io_r_mb(v2 + 3096);
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_irq",
      102,
      "BASE: %p, irq0:%x irq1:%x",
      v2,
      v4,
      v5);
  cam_io_w_mb(v4, v2 + 3080);
  cam_io_w_mb(v5, v2 + 3092);
  if ( (v5 & 0x100000) != 0 && (v4 & 0x1000) == 0 )
  {
    v6 = raw_spin_lock_irqsave(a2 + 5824);
    *(_DWORD *)(a2 + 5832) |= 0x100000u;
    raw_spin_unlock_irqrestore(a2 + 5824, v6);
    v7 = 13434880;
    v8 = (v5 & 0x10000) == 0;
    v9 = (v4 & 1) == 0;
    if ( (v5 & 0x10000) == 0 || (v4 & 1) != 0 )
    {
LABEL_13:
      cam_io_w_mb(v7, v2 + 3088);
      if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_irq",
          129,
          "Updating the reg mask for irq1: 0x%x",
          v7);
      goto LABEL_29;
    }
    v7 = 13369344;
LABEL_12:
    v10 = raw_spin_lock_irqsave(a2 + 5824);
    *(_DWORD *)(a2 + 5832) |= 0x10000u;
    raw_spin_unlock_irqrestore(a2 + 5824, v10);
    goto LABEL_13;
  }
  v8 = (v5 & 0x10000) == 0;
  v9 = (v4 & 1) == 0;
  if ( (v5 & 0x10000) != 0 && (v4 & 1) == 0 )
  {
    v7 = 14417920;
    goto LABEL_12;
  }
  if ( (v4 & 0x1001) == 0 )
    goto LABEL_29;
  if ( (v4 & 1) == 0 )
  {
    v11 = 0;
    if ( (v4 & 0x1000) == 0 )
      goto LABEL_27;
LABEL_24:
    v14 = raw_spin_lock_irqsave(a2 + 5824);
    v15 = *(_DWORD *)(a2 + 5832);
    if ( (v15 & 0x100000) != 0 )
    {
      v11 |= 0x100000u;
      *(_DWORD *)(a2 + 5832) = v15 & 0xFFEFFFFF;
    }
    raw_spin_unlock_irqrestore(a2 + 5824, v14);
    goto LABEL_27;
  }
  v12 = raw_spin_lock_irqsave(a2 + 5824);
  v13 = *(_DWORD *)(a2 + 5832);
  if ( (v13 & 0x10000) != 0 )
  {
    v11 = 0x10000;
    *(_DWORD *)(a2 + 5832) = v13 & 0xFFFEFFFF;
  }
  else
  {
    v11 = 0;
  }
  raw_spin_unlock_irqrestore(a2 + 5824, v12);
  if ( (v4 & 0x1000) != 0 )
    goto LABEL_24;
LABEL_27:
  if ( v11 )
  {
    v16 = cam_io_r_mb(v2 + 3088);
    cam_io_w_mb(v16 | (unsigned int)v11, v2 + 3088);
  }
LABEL_29:
  cam_io_w_mb(1, v2 + 3072);
  if ( (v4 & 0x1000000) != 0 )
  {
    if ( *(_BYTE *)(a2 + 4054) == 1 )
    {
      v17 = *(_DWORD *)(a2 + 4040);
      *(_BYTE *)(a2 + 4054) = 0;
      if ( !v17 )
        complete(a2 + 4104);
      complete_all(a2 + 4136);
      complete_all(a2 + 4168);
    }
    if ( *(_BYTE *)(a2 + 4598) == 1 )
    {
      v18 = *(_DWORD *)(a2 + 4584);
      *(_BYTE *)(a2 + 4598) = 0;
      if ( !v18 )
        complete(a2 + 4648);
      complete_all(a2 + 4680);
      complete_all(a2 + 4712);
    }
  }
  if ( !v9 && !v8 )
  {
    *(_DWORD *)(a2 + 4040) = 0;
LABEL_43:
    complete(a2 + 4168);
LABEL_44:
    v19 = 4136;
    goto LABEL_45;
  }
  if ( !v9 )
  {
    v24 = *(unsigned __int8 *)(a2 + 5828);
    *(_DWORD *)(a2 + 4040) = 0;
    if ( v24 != 1 )
      goto LABEL_44;
    goto LABEL_43;
  }
  if ( v8 )
    goto LABEL_46;
  v19 = 4168;
  *(_DWORD *)(a2 + 4040) = 0;
LABEL_45:
  complete(a2 + v19);
LABEL_46:
  if ( (v5 & 0x400000) != 0 )
  {
    v21 = raw_spin_lock_irqsave(a2 + 5824);
    v22 = *(_DWORD *)(a2 + 404);
    v23 = v21;
    goto LABEL_55;
  }
  v20 = 1;
  if ( (v5 & 0x800000) != 0 )
    goto LABEL_67;
LABEL_48:
  if ( (v5 & 0x40000) == 0 )
  {
LABEL_49:
    if ( (v5 & 0x80000) != 0 )
      goto LABEL_87;
LABEL_50:
    if ( (v4 & 0x10) != 0 )
      goto LABEL_97;
LABEL_51:
    if ( (v4 & 0x100) != 0 )
      goto LABEL_100;
LABEL_52:
    if ( (v4 & 0x1000) != 0 )
      goto LABEL_103;
    goto LABEL_112;
  }
LABEL_77:
  v28 = raw_spin_lock_irqsave(a2 + 5824);
  v22 = *(_DWORD *)(a2 + 404);
  v23 = v28;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_irq",
      286,
      "CCI%d_M0_Q0: th_irq honoured irq1: 0x%x th_irq_ref_cnt: %d",
      *(_DWORD *)(a2 + 404),
      v5,
      *(_DWORD *)(a2 + 4520));
  v29 = *(_DWORD *)(a2 + 4520);
  if ( v29 == 1 )
  {
    complete(a2 + 4456);
    goto LABEL_86;
  }
  *(_DWORD *)(a2 + 4520) = v29 - 1;
  if ( (head + 1) % 100 == tail )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_irq",
      297);
    v20 = 0;
    goto LABEL_86;
  }
  if ( (unsigned int)head > 0x63 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_176:
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                         + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
            & 1) != 0 )
        {
          ++*(_DWORD *)(StatusReg + 16);
          v45 = _traceiter_cam_cci_burst(0, v22, 1u, 0, (__int64)"th_irq honoured irq1", v5);
          v46 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v46;
          if ( !v46 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule_notrace(v45);
        }
LABEL_55:
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_irq",
            216,
            "CCI%d_M1_Q0: th_irq honoured irq1: 0x%x th_irq_ref_cnt: %d",
            *(_DWORD *)(a2 + 404),
            v5,
            *(_DWORD *)(a2 + 5064));
        if ( *(_DWORD *)(a2 + 5064) != 1 )
          break;
        complete(a2 + 5000);
        v20 = 1;
LABEL_66:
        raw_spin_unlock_irqrestore(a2 + 5824, v23);
        if ( (v5 & 0x800000) == 0 )
          goto LABEL_48;
LABEL_67:
        v26 = raw_spin_lock_irqsave(a2 + 5824);
        v22 = *(_DWORD *)(a2 + 404);
        v23 = v26;
        if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000,
            4,
            "cam_cci_irq",
            251,
            "CCI%d_M1_Q1: th_irq honoured irq1: 0x%x th_irq_ref_cnt: %d",
            *(_DWORD *)(a2 + 404),
            v5,
            *(_DWORD *)(a2 + 5068));
        if ( *(_DWORD *)(a2 + 5068) == 1 )
        {
          complete(a2 + 5032);
          goto LABEL_76;
        }
        --*(_DWORD *)(a2 + 5068);
        if ( (head + 1) % 100 == tail )
        {
          ((void (*)(__int64, const char *, ...))cam_print_log)(
            3,
            print_fmt_cam_context_state,
            (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
            "cam_cci_irq",
            262);
          v20 = 0;
          goto LABEL_76;
        }
        if ( (unsigned int)head <= 0x63 )
        {
          v27 = (char *)&cci_irq_queue + 20 * (unsigned int)head;
          v20 = 2;
          head = (head + 1) % 100;
          *(_QWORD *)(v27 + 12) = 0x100000001LL;
          *((_DWORD *)v27 + 1) = v4;
          *((_DWORD *)v27 + 2) = v5;
          *(_DWORD *)v27 = 1;
LABEL_76:
          raw_spin_unlock_irqrestore(a2 + 5824, v23);
          if ( (v5 & 0x40000) == 0 )
            goto LABEL_49;
          goto LABEL_77;
        }
      }
      --*(_DWORD *)(a2 + 5064);
      if ( (head + 1) % 100 == tail )
      {
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
          "cam_cci_irq",
          227);
        v20 = 0;
        goto LABEL_66;
      }
      if ( (unsigned int)head <= 0x63 )
      {
        v25 = (char *)&cci_irq_queue + 20 * (unsigned int)head;
        v20 = 2;
        head = (head + 1) % 100;
        *((_DWORD *)v25 + 1) = v4;
        *((_DWORD *)v25 + 2) = v5;
        *(_QWORD *)(v25 + 12) = 1;
        *(_DWORD *)v25 = 1;
        goto LABEL_66;
      }
    }
  }
  v30 = (char *)&cci_irq_queue + 20 * (unsigned int)head;
  v20 = 2;
  head = (head + 1) % 100;
  *((_DWORD *)v30 + 1) = v4;
  *((_DWORD *)v30 + 2) = v5;
  *(_QWORD *)(v30 + 12) = 0;
  *(_DWORD *)v30 = 1;
LABEL_86:
  raw_spin_unlock_irqrestore(a2 + 5824, v23);
  if ( (v5 & 0x80000) == 0 )
    goto LABEL_50;
LABEL_87:
  v31 = raw_spin_lock_irqsave(a2 + 5824);
  v22 = *(_DWORD *)(a2 + 404);
  v23 = v31;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_irq",
      321,
      "CCI%d_M0_Q1: th_irq honoured irq1: 0x%x th_irq_ref_cnt: %d",
      *(_DWORD *)(a2 + 404),
      v5,
      *(_DWORD *)(a2 + 4524));
  if ( *(_DWORD *)(a2 + 4524) == 1 )
  {
    complete(a2 + 4488);
  }
  else
  {
    --*(_DWORD *)(a2 + 4524);
    if ( (head + 1) % 100 == tail )
    {
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_irq",
        332);
      v20 = 0;
    }
    else
    {
      if ( (unsigned int)head > 0x63 )
        goto LABEL_176;
      v32 = (char *)&cci_irq_queue + 20 * (unsigned int)head;
      v20 = 2;
      head = (head + 1) % 100;
      *(_QWORD *)(v32 + 12) = 0x100000000LL;
      *((_DWORD *)v32 + 1) = v4;
      *((_DWORD *)v32 + 2) = v5;
      *(_DWORD *)v32 = 1;
    }
  }
  raw_spin_unlock_irqrestore(a2 + 5824, v23);
  if ( (v4 & 0x10) == 0 )
    goto LABEL_51;
LABEL_97:
  v33 = raw_spin_lock_irqsave(a2 + 4368);
  *(_DWORD *)(a2 + 4044) = 0;
  v34 = v33;
  *(_DWORD *)(a2 + 4040) = 0;
  if ( *(_DWORD *)(a2 + 4360) == 1 )
  {
    complete(a2 + 4296);
    *(_DWORD *)(a2 + 4360) = 0;
  }
  raw_spin_unlock_irqrestore(a2 + 4368, v34);
  if ( (v4 & 0x100) == 0 )
    goto LABEL_52;
LABEL_100:
  v35 = raw_spin_lock_irqsave(a2 + 4372);
  *(_DWORD *)(a2 + 4048) = 0;
  v36 = v35;
  *(_DWORD *)(a2 + 4040) = 0;
  if ( *(_DWORD *)(a2 + 4364) == 1 )
  {
    complete(a2 + 4328);
    *(_DWORD *)(a2 + 4364) = 0;
  }
  raw_spin_unlock_irqrestore(a2 + 4372, v36);
  if ( (v4 & 0x1000) != 0 )
  {
LABEL_103:
    if ( (v5 & 0x100000) != 0 )
    {
      *(_DWORD *)(a2 + 4584) = 0;
      goto LABEL_105;
    }
  }
LABEL_112:
  if ( (v4 & 0x1000) != 0 )
  {
    v42 = *(unsigned __int8 *)(a2 + 5829);
    *(_DWORD *)(a2 + 4584) = 0;
    if ( v42 == 1 )
LABEL_105:
      complete(a2 + 4712);
    v37 = 4680;
LABEL_107:
    complete(a2 + v37);
  }
  else if ( (v5 & 0x100000) != 0 )
  {
    v37 = 4712;
    *(_DWORD *)(a2 + 4584) = 0;
    goto LABEL_107;
  }
  if ( (v4 & 0x10000) != 0 )
  {
    v38 = raw_spin_lock_irqsave(a2 + 4912);
    *(_DWORD *)(a2 + 4588) = 0;
    v39 = v38;
    *(_DWORD *)(a2 + 4584) = 0;
    if ( *(_DWORD *)(a2 + 4904) == 1 )
    {
      complete(a2 + 4840);
      *(_DWORD *)(a2 + 4904) = 0;
    }
    raw_spin_unlock_irqrestore(a2 + 4912, v39);
    if ( (v4 & 0x100000) != 0 )
      goto LABEL_118;
LABEL_110:
    if ( (v5 & 0x20000) == 0 )
      goto LABEL_123;
LABEL_121:
    if ( (debug_mdl & 0x4000) == 0 || debug_priority )
      goto LABEL_123;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_irq",
      438,
      "RD_PAUSE ON MASTER_0");
    if ( (v5 & 0x200000) != 0 )
    {
LABEL_124:
      if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_irq",
          441,
          "RD_PAUSE ON MASTER_1");
    }
  }
  else
  {
    if ( (v4 & 0x100000) == 0 )
      goto LABEL_110;
LABEL_118:
    v40 = raw_spin_lock_irqsave(a2 + 4916);
    *(_DWORD *)(a2 + 4592) = 0;
    v41 = v40;
    *(_DWORD *)(a2 + 4584) = 0;
    if ( *(_DWORD *)(a2 + 4908) == 1 )
    {
      complete(a2 + 4872);
      *(_DWORD *)(a2 + 4908) = 0;
    }
    raw_spin_unlock_irqrestore(a2 + 4916, v41);
    if ( (v5 & 0x20000) != 0 )
      goto LABEL_121;
LABEL_123:
    if ( (v5 & 0x200000) != 0 )
      goto LABEL_124;
  }
  if ( (v4 & 0x2000000) != 0 )
  {
    *(_BYTE *)(a2 + 4054) = 1;
    cam_io_w_mb(1009, v2 + 4);
  }
  if ( (v4 & 0x4000000) != 0 )
  {
    *(_BYTE *)(a2 + 4598) = 1;
    cam_io_w_mb(258049, v2 + 4);
  }
  if ( (v4 & 0x18000EE6) != 0 )
  {
    *(_DWORD *)(a2 + 4040) = -22;
    if ( (v4 & 0x8000000) != 0 )
    {
      if ( *(_BYTE *)(a2 + 5896) == 1 )
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
          "cam_cci_irq",
          459);
      else
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
          "cam_cci_irq",
          463);
      cam_cci_dump_registers(a2, 0, 0);
      if ( *(_DWORD *)(a2 + 4520) )
        complete_all(a2 + 4456);
      complete_all(a2 + 4296);
    }
    if ( (v4 & 0x10000000) != 0 )
    {
      if ( *(_BYTE *)(a2 + 5896) == 1 )
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
          "cam_cci_irq",
          480);
      else
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
          "cam_cci_irq",
          484);
      cam_cci_dump_registers(a2, 0, 1);
      if ( *(_DWORD *)(a2 + 4524) )
        complete_all(a2 + 4488);
      complete_all(a2 + 4328);
    }
    if ( (v4 & 0xEE0) != 0 )
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_irq",
        500);
    if ( (v4 & 6) != 0 )
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_irq",
        504);
    *(_BYTE *)(a2 + 4054) = 1;
    cam_io_w_mb(1009, v2 + 4);
  }
  if ( (v4 & 0x60EE6000) != 0 )
  {
    *(_DWORD *)(a2 + 4584) = -22;
    if ( (v4 & 0x20000000) != 0 )
    {
      if ( *(_BYTE *)(a2 + 5896) == 1 )
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
          "cam_cci_irq",
          515);
      else
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
          "cam_cci_irq",
          519);
      cam_cci_dump_registers(a2, 1, 0);
      if ( *(_DWORD *)(a2 + 5064) )
        complete_all(a2 + 5000);
      complete_all(a2 + 4840);
    }
    if ( (v4 & 0x40000000) != 0 )
    {
      if ( *(_BYTE *)(a2 + 5896) == 1 )
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
          "cam_cci_irq",
          536);
      else
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
          "cam_cci_irq",
          540);
      cam_cci_dump_registers(a2, 1, 1);
      if ( *(_DWORD *)(a2 + 5068) )
        complete_all(a2 + 5032);
      complete_all(a2 + 4872);
    }
    if ( (v4 & 0xEE0000) != 0 )
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_irq",
        556);
    if ( (v4 & 0x6000) != 0 )
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_irq",
        560);
    *(_BYTE *)(a2 + 4598) = 1;
    cam_io_w_mb(258049, v2 + 4);
  }
  return v20;
}
