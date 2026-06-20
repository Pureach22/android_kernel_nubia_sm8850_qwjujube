__int64 __fastcall fastrpc_handle_rpc_response(__int64 a1, __int64 *a2, unsigned int a3, char a4)
{
  __int64 v6; // x25
  unsigned __int64 v7; // x22
  __int64 v8; // x24
  __int64 v9; // x20
  unsigned int v10; // w8
  unsigned int v12; // w25
  unsigned int v18; // w9
  __int64 v19; // x20
  __int64 result; // x0
  int v21; // w24
  __int64 v22; // x23
  unsigned int v23; // w8
  unsigned int v25; // w25
  unsigned int v27; // w9
  int v28; // w23
  __int64 *v29; // x28
  __int64 v30; // x21
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x19
  __int64 v35; // x8
  __int64 v36; // x24
  int v37; // w25
  unsigned int v38; // w8
  unsigned int v40; // w10
  int v41; // w27
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x1
  unsigned __int64 v45; // x26
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x9
  int v49; // w8
  __int64 v50; // x9
  __int64 v51; // x24
  __int64 v52; // x21
  __int64 v53; // x20
  _QWORD *v54; // x0
  _QWORD *v55; // x21
  int v56; // w2
  __int64 v57; // x9
  int v58; // w22
  char v59; // w8
  __int64 v60; // x10
  __int64 v61; // x0
  unsigned int v62; // w8
  unsigned int v64; // w10
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x1
  __int64 v68; // x4
  __int64 v69; // x5
  unsigned __int64 StatusReg; // x23
  __int64 v71; // x24
  __int64 (__fastcall *v72)(__int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD); // x8
  __int64 v73; // x0
  __int64 v74; // t1
  __int64 v75; // x8
  int v77; // [xsp+2Ch] [xbp-4h]

  v6 = a1 + 49152;
  if ( a3 == 8 )
    goto LABEL_2;
  v19 = *a2;
  if ( *a2 != 2882382797LL )
  {
    if ( a3 < 0x10 )
      return 4294967274LL;
    v28 = 0;
    v29 = nullptr;
    if ( a2 )
    {
      v30 = 0;
      v77 = 0;
      if ( a3 >= 0x18 )
      {
        v28 = *((_DWORD *)a2 + 3);
        v30 = *((unsigned int *)a2 + 5);
        v29 = a2;
        v77 = *((_DWORD *)a2 + 4);
      }
    }
    else
    {
      v77 = 0;
      v30 = 0;
    }
    v41 = *((_DWORD *)a2 + 2);
    v42 = ktime_get_with_offset(1);
    v43 = ns_to_timespec64(v42);
    if ( v43 <= 0x225C17D03LL )
    {
      if ( v43 >= (__int64)0xFFFFFFFDDA3E82FDLL )
        v45 = v44 + 1000000000 * v43;
      else
        v45 = 0x8000000000000000LL;
    }
    else
    {
      v45 = 0x7FFFFFFFFFFFFFFFLL;
    }
    v46 = raw_spin_lock_irqsave(a1 + 64036);
    v47 = *(unsigned int *)(v6 + 3612);
    if ( (unsigned int)v47 >= 0x81 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v71 = qword_226A0;
        if ( qword_226A0 )
        {
          do
          {
            v72 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD))v71;
            v73 = *(_QWORD *)(v71 + 8);
            if ( *(_DWORD *)(*(_QWORD *)v71 - 4LL) != -1266066563 )
              __break(0x8228u);
            v46 = v72(v73, (unsigned int)v19, v30, 0, 0, 0);
            v74 = *(_QWORD *)(v71 + 24);
            v71 += 24;
          }
          while ( v74 );
        }
        v75 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v75;
        if ( !v75 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v46);
      }
LABEL_2:
      v7 = *a2;
      if ( (unsigned int)v7 > 0x3FF )
        return 0;
      v8 = raw_spin_lock_irqsave(a1 + 51600);
      v9 = v6 + 2496;
      do
      {
        v9 = *(_QWORD *)v9;
        if ( v9 == v6 + 2496 )
          goto LABEL_99;
      }
      while ( *(_DWORD *)(v9 + 244) != HIDWORD(v7) );
      v10 = *(_DWORD *)(v9 + 664);
      _X21 = (unsigned int *)(v9 + 664);
      if ( v10 )
      {
        do
        {
          __asm { PRFM            #0x11, [X21] }
          do
            v18 = __ldxr(_X21);
          while ( v18 == v10 && __stxr(v10 + 1, _X21) );
          v12 = v10;
          if ( v18 == v10 )
            break;
          v12 = 0;
          v10 = v18;
        }
        while ( v18 );
      }
      else
      {
        v12 = 0;
      }
      if ( (((v12 + 1) | v12) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(v9 + 664, 0);
        if ( v12 )
        {
LABEL_36:
          raw_spin_unlock_irqrestore(a1 + 51600, v8);
          v34 = raw_spin_lock_irqsave(v9 + 324);
          v35 = *(_QWORD *)(v9 + 8 * ((v7 >> 8) & 3) + 504);
          if ( v35 )
          {
            v36 = v35 + 40LL * (unsigned __int8)v7;
            v37 = *(_DWORD *)(v36 + 32);
            if ( (unsigned int)(v37 - 1) < 2 )
            {
              complete(v36);
              *(_DWORD *)(v36 + 32) = 2;
LABEL_41:
              raw_spin_unlock_irqrestore(v9 + 324, v34);
              v38 = *_X21;
              if ( *_X21 + 1 < 2 )
                return 0;
              if ( v38 != 1 )
              {
                while ( v38 != 1 )
                {
                  __asm { PRFM            #0x11, [X21] }
                  do
                    v40 = __ldxr(_X21);
                  while ( v40 == v38 && __stlxr(v38 - 1, _X21) );
                  result = 0;
                  _ZF = v40 == v38;
                  v38 = v40;
                  if ( _ZF )
                    return result;
                }
              }
LABEL_81:
              queue_work_on(32, system_wq, v9 + 672);
              return 0;
            }
            if ( v37 )
              goto LABEL_41;
          }
          printk(&unk_235FF, (unsigned int)v7, HIDWORD(v7), v31, v32, v33);
          goto LABEL_41;
        }
      }
      else if ( v12 )
      {
        goto LABEL_36;
      }
      dev_warn(
        *(_QWORD *)(a1 + 168),
        "Warning: %s: user-obj for fl (%pK) being released\n",
        "fastrpc_handle_signal_rpmsg");
LABEL_99:
      raw_spin_unlock_irqrestore(a1 + 51600, v8);
      printk(&unk_23D85, "fastrpc_handle_signal_rpmsg", HIDWORD(v7), (unsigned int)v7, v68, v69);
      return 0;
    }
    v48 = a1 + 32 * v47;
    if ( (unsigned int)v47 <= 0x7E )
      v49 = v47 + 1;
    else
      v49 = 0;
    v50 = v48 + 59936;
    *(_DWORD *)(v6 + 3612) = v49;
    *(_QWORD *)v50 = v19;
    *(_DWORD *)(v50 + 8) = v41;
    *(_DWORD *)(v50 + 12) = v28;
    *(_DWORD *)(v50 + 16) = v77;
    *(_DWORD *)(v50 + 20) = v30;
    *(_QWORD *)(v50 + 24) = v45;
    raw_spin_unlock_irqrestore(a1 + 64036, v46);
    v51 = *a2;
    v52 = (unsigned __int16)*a2 >> 6;
    v53 = raw_spin_lock_irqsave(a1 + 51600);
    v54 = (_QWORD *)idr_find(a1 + 51608, v52);
    if ( !v54 )
    {
LABEL_94:
      v66 = a1 + 51600;
      v67 = v53;
LABEL_103:
      raw_spin_unlock_irqrestore(v66, v67);
      return 0;
    }
    v55 = v54;
    if ( v54[10] != (v51 & 0xFFFFFFFFFFFFFFF0LL) )
    {
      raw_spin_unlock_irqrestore(a1 + 51600, v53);
      dev_info(
        *(_QWORD *)(a1 + 168),
        "Warning: rsp ctxid 0x%llx mismatch with local ctxid 0x%llx (full rsp ctx 0x%llx)",
        v51 & 0xFFFFFFFFFFFFFFF0LL,
        v55[10],
        *a2);
      return 0;
    }
    if ( v29 )
    {
      v56 = *((_DWORD *)v29 + 5);
      if ( v56 != 2 )
      {
        dev_err(*(_QWORD *)(a1 + 168), "Incorrect response version %d\n", v56);
        raw_spin_unlock_irqrestore(a1 + 51600, v53);
        return 4294967274LL;
      }
    }
    v57 = v54[30];
    v58 = *((_DWORD *)a2 + 2);
    v59 = a4;
    if ( v57 )
    {
      if ( !*(_DWORD *)(v57 + 64136) )
      {
        v60 = v54[23];
        v61 = *(_QWORD *)(*(_QWORD *)(v60 + 128) + 64048LL);
        if ( v61 )
        {
          pm_wakeup_ws_event(v61, *(unsigned int *)(v60 + 292), 1);
          v59 = a4;
        }
      }
    }
    *((_DWORD *)v55 + 6) = v58;
    *((_DWORD *)v55 + 25) = v28;
    if ( v28 > 1 )
    {
      if ( v28 == 2 )
      {
        *((_DWORD *)v55 + 14) = v77;
        goto LABEL_91;
      }
      if ( v28 != 3 )
      {
LABEL_91:
        if ( (v59 & 1) != 0 )
        {
          v65 = v55[23];
          if ( v65 )
            dev_info(
              *(_QWORD *)(a1 + 168),
              "glink wakeup by(%s): domain(%d) pd_type(%d) pid(%d: %d: %d) tid(%d) handle(0x%x) sc(0x%x)\n",
              (const char *)(v65 + 252),
              *(_DWORD *)a1,
              *(_DWORD *)(v65 + 268),
              *(_DWORD *)(v65 + 240),
              *(_DWORD *)(v65 + 248),
              *(_DWORD *)(v65 + 244),
              *((_DWORD *)v55 + 7),
              *((_DWORD *)v55 + 10),
              *((_DWORD *)v55 + 9));
        }
        goto LABEL_94;
      }
    }
    else if ( v28 )
    {
      if ( v28 == 1 )
      {
        complete(v55 + 14);
        v59 = a4;
      }
      goto LABEL_91;
    }
    *((_BYTE *)v55 + 96) = 1;
    complete(v55 + 14);
    v59 = a4;
    goto LABEL_91;
  }
  result = 4294967294LL;
  if ( a3 >= 0x18 && *((_DWORD *)a2 + 2) == 4 )
  {
    v21 = *(_DWORD *)a1;
    v22 = raw_spin_lock_irqsave(a1 + 51600);
    v9 = v6 + 2496;
    do
    {
      v9 = *(_QWORD *)v9;
      if ( v9 == v6 + 2496 )
        goto LABEL_102;
    }
    while ( *(_DWORD *)(v9 + 244) != *((_DWORD *)a2 + 3) );
    v23 = *(_DWORD *)(v9 + 664);
    _X21 = (unsigned int *)(v9 + 664);
    if ( v23 )
    {
      do
      {
        __asm { PRFM            #0x11, [X21] }
        do
          v27 = __ldxr(_X21);
        while ( v27 == v23 && __stxr(v23 + 1, _X21) );
        v25 = v23;
        if ( v27 == v23 )
          break;
        v25 = 0;
        v23 = v27;
      }
      while ( v27 );
    }
    else
    {
      v25 = 0;
    }
    if ( (((v25 + 1) | v25) & 0x80000000) != 0 )
    {
      refcount_warn_saturate(v9 + 664, 0);
      if ( v25 )
        goto LABEL_79;
    }
    else if ( v25 )
    {
LABEL_79:
      raw_spin_unlock_irqrestore(a1 + 51600, v22);
      fastrpc_queue_pd_status(v9, v21, *((_DWORD *)a2 + 4), *(_DWORD *)(v9 + 284));
      v62 = *(_DWORD *)(v9 + 664);
      if ( v62 + 1 < 2 )
        return 0;
      if ( v62 != 1 )
      {
        while ( v62 != 1 )
        {
          __asm { PRFM            #0x11, [X21] }
          do
            v64 = __ldxr(_X21);
          while ( v64 == v62 && __stlxr(v62 - 1, _X21) );
          result = 0;
          _ZF = v64 == v62;
          v62 = v64;
          if ( _ZF )
            return result;
        }
      }
      goto LABEL_81;
    }
    dev_warn(*(_QWORD *)(a1 + 168), "Warning: %s: user-obj for fl (%pK) being released\n", "fastrpc_notif_find_process");
LABEL_102:
    v66 = a1 + 51600;
    v67 = v22;
    goto LABEL_103;
  }
  return result;
}
