__int64 __fastcall venus_hfi_isr_handler(unsigned int a1, __int64 a2)
{
  __int64 v4; // x8
  void (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x8
  unsigned int (__fastcall *v7)(__int64, __int64); // x8
  __int64 v8; // x1
  __int64 v9; // x4
  _QWORD *v10; // x0
  unsigned __int64 v11; // x26
  _QWORD *v12; // x27
  __int64 inst_ref_locked; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  int v18; // w19
  int v19; // w8
  int v20; // w0
  __int64 v21; // x28
  int v22; // w5
  __int64 v23; // x22
  int v24; // w27
  int v25; // w28
  __int64 *inst_using_session_id; // x0
  __int64 v27; // x1
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x4
  unsigned __int64 v31; // x21
  unsigned __int64 v32; // x19
  __int64 v33; // x8
  unsigned int (__fastcall *v34)(__int64, __int64); // x8
  __int64 v35; // x1
  __int64 result; // x0
  unsigned int v37; // [xsp+4h] [xbp-8Ch]
  __int64 v38; // [xsp+8h] [xbp-88h] BYREF
  __int64 v39; // [xsp+10h] [xbp-80h]
  __int64 v40; // [xsp+18h] [xbp-78h]
  __int64 v41; // [xsp+20h] [xbp-70h]
  __int64 v42; // [xsp+28h] [xbp-68h]
  __int64 v43; // [xsp+30h] [xbp-60h]
  __int64 v44; // [xsp+38h] [xbp-58h]
  __int64 v45; // [xsp+40h] [xbp-50h]
  __int64 v46; // [xsp+48h] [xbp-48h]
  __int64 v47; // [xsp+50h] [xbp-40h]
  __int64 v48; // [xsp+58h] [xbp-38h]
  __int64 v49; // [xsp+60h] [xbp-30h]
  __int64 v50; // [xsp+68h] [xbp-28h]
  __int64 v51; // [xsp+70h] [xbp-20h]
  __int64 v52; // [xsp+78h] [xbp-18h]
  __int64 v53; // [xsp+80h] [xbp-10h]
  __int64 v54; // [xsp+88h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (msm_vidc_debug & 4) != 0 )
  {
    printk(&unk_85E49, "low ", 0xFFFFFFFFLL, "codec", "venus_hfi_isr_handler");
    if ( a2 )
      goto LABEL_3;
LABEL_103:
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_isr_handler");
    result = 0;
    goto LABEL_106;
  }
  if ( !a2 )
    goto LABEL_103;
LABEL_3:
  core_lock(a2);
  if ( (unsigned int)_resume(a2) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_819EC, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_isr_handler");
    core_unlock(a2);
    goto LABEL_95;
  }
  v4 = *(_QWORD *)(a2 + 6544);
  if ( v4 )
  {
    v5 = *(void (__fastcall **)(_QWORD))(v4 + 16);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 - 1) != -1850880742 )
        __break(0x8228u);
      v5(a2);
    }
  }
  core_unlock(a2);
  v6 = *(_QWORD *)(a2 + 6544);
  if ( v6 )
  {
    v7 = *(unsigned int (__fastcall **)(__int64, __int64))(v6 + 48);
    if ( v7 )
    {
      v8 = *(unsigned int *)(a2 + 3920);
      if ( *((_DWORD *)v7 - 1) != -2114196824 )
        __break(0x8228u);
      if ( v7(a2, v8) )
      {
        v40 = 0;
        v41 = 0;
        v38 = 0x500000100000000LL;
        v39 = 0;
        core_lock(a2);
        msm_vidc_change_core_state(a2, 3u, (__int64)"__response_handler");
        msm_vidc_change_core_sub_state(a2, 0, 0x20u, (__int64)"__response_handler");
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_90FCE, "err ", 0xFFFFFFFFLL, "codec", "__response_handler");
        core_unlock(a2);
        ((void (__fastcall *)(__int64, __int64 *))handle_system_error)(a2, &v38);
        goto LABEL_95;
      }
    }
  }
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  core_lock(a2);
  v10 = *(_QWORD **)(a2 + 3528);
  if ( v10 == (_QWORD *)(a2 + 3528) )
  {
    v11 = 0;
  }
  else
  {
    v11 = 0;
    do
    {
      v12 = (_QWORD *)*v10;
      if ( v10[46] )
      {
        inst_ref_locked = get_inst_ref_locked((__int64)v10);
        if ( inst_ref_locked )
        {
          if ( v11 >= 0x10 )
            goto LABEL_108;
          *(&v38 + v11++) = inst_ref_locked;
        }
      }
      else if ( v10 && (msm_vidc_debug & 4) != 0 )
      {
        printk(&unk_8DE50, "low ", (char *)v10 + 340, "__response_handler", v9);
      }
      v10 = v12;
    }
    while ( v12 != (_QWORD *)(a2 + 3528) );
  }
  v37 = a1;
  _schedule_power_collapse_work(a2);
  core_unlock(a2);
  do
  {
    memset(*(void **)(a2 + 6480), 0, *(unsigned int *)(a2 + 6472));
    v18 = 0;
    if ( !(unsigned int)venus_hfi_queue_msg_read(a2, *(_QWORD *)(a2 + 6480)) )
    {
      v19 = 1;
      while ( 1 )
      {
        v21 = *(_QWORD *)(a2 + 6480);
        v18 = v19;
        if ( (unsigned int)validate_hdr_packet(a2, v21, "__process_msg_q") )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_7FE8F, "err ", 0xFFFFFFFFLL, "codec", "__process_msg_q");
          ((void (__fastcall *)(__int64, _QWORD))handle_system_error)(a2, 0);
          goto LABEL_38;
        }
        v22 = *(_DWORD *)(v21 + 4);
        if ( !v22 )
        {
          v25 = handle_system_response(a2, v21);
          goto LABEL_53;
        }
        if ( (int)v11 < 1 )
          goto LABEL_47;
        v23 = v38;
        if ( *(_DWORD *)(v38 + 332) != v22 )
        {
          if ( v11 == 1 )
            goto LABEL_47;
          v23 = v39;
          if ( *(_DWORD *)(v39 + 332) != v22 )
          {
            if ( v11 == 2 )
              goto LABEL_47;
            v23 = v40;
            if ( *(_DWORD *)(v40 + 332) != v22 )
            {
              if ( v11 == 3 )
                goto LABEL_47;
              v23 = v41;
              if ( *(_DWORD *)(v41 + 332) != v22 )
              {
                if ( v11 == 4 )
                  goto LABEL_47;
                v23 = v42;
                if ( *(_DWORD *)(v42 + 332) != v22 )
                {
                  if ( v11 == 5 )
                    goto LABEL_47;
                  v23 = v43;
                  if ( *(_DWORD *)(v43 + 332) != v22 )
                  {
                    if ( v11 == 6 )
                      goto LABEL_47;
                    v23 = v44;
                    if ( *(_DWORD *)(v44 + 332) != v22 )
                    {
                      if ( v11 == 7 )
                        goto LABEL_47;
                      v23 = v45;
                      if ( *(_DWORD *)(v45 + 332) != v22 )
                      {
                        if ( v11 == 8 )
                          goto LABEL_47;
                        v23 = v46;
                        if ( *(_DWORD *)(v46 + 332) != v22 )
                        {
                          if ( v11 == 9 )
                            goto LABEL_47;
                          v23 = v47;
                          if ( *(_DWORD *)(v47 + 332) != v22 )
                          {
                            if ( v11 == 10 )
                              goto LABEL_47;
                            v23 = v48;
                            if ( *(_DWORD *)(v48 + 332) != v22 )
                            {
                              if ( v11 == 11 )
                                goto LABEL_47;
                              v23 = v49;
                              if ( *(_DWORD *)(v49 + 332) != v22 )
                              {
                                if ( v11 == 12 )
                                  goto LABEL_47;
                                v23 = v50;
                                if ( *(_DWORD *)(v50 + 332) != v22 )
                                {
                                  if ( v11 == 13 )
                                    goto LABEL_47;
                                  v23 = v51;
                                  if ( *(_DWORD *)(v51 + 332) != v22 )
                                  {
                                    if ( v11 == 14 )
                                      goto LABEL_47;
                                    v23 = v52;
                                    if ( *(_DWORD *)(v52 + 332) != v22 )
                                    {
                                      if ( v11 == 15 )
                                        goto LABEL_47;
                                      v23 = v53;
                                      if ( *(_DWORD *)(v53 + 332) != v22 )
                                        break;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if ( !v23 )
          goto LABEL_47;
        v24 = 0;
LABEL_51:
        inst_lock(v23);
        v25 = handle_session_response(v23, v21);
        inst_unlock(v23);
        if ( v24 )
          put_inst(v23, v27, v28, v29, v30);
LABEL_53:
        if ( !v25 )
        {
          if ( *(_DWORD *)(a2 + 3704) != 2 )
            goto LABEL_32;
          memset(*(void **)(a2 + 6480), 0, *(unsigned int *)(a2 + 6472));
        }
LABEL_38:
        v20 = venus_hfi_queue_msg_read(a2, *(_QWORD *)(a2 + 6480));
        v19 = v18 + 1;
        if ( v20 )
          goto LABEL_32;
      }
      if ( v11 != 16 )
      {
LABEL_107:
        __break(1u);
        goto LABEL_108;
      }
LABEL_47:
      if ( (msm_vidc_debug & 4) != 0 )
      {
        printk(&unk_8A142, "low ", 0xFFFFFFFFLL, "codec", "__process_msg_q");
        v22 = *(_DWORD *)(v21 + 4);
      }
      inst_using_session_id = get_inst_using_session_id(a2, v22);
      if ( !inst_using_session_id )
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_95CFD, "err ", 0xFFFFFFFFLL, "codec", "__process_msg_q");
        goto LABEL_38;
      }
      v23 = (__int64)inst_using_session_id;
      v24 = 1;
      goto LABEL_51;
    }
LABEL_32:
    ;
  }
  while ( v18 | (unsigned int)_flush_debug_queue(a2, *(_QWORD *)(a2 + 6480), *(unsigned int *)(a2 + 6472)) );
  a1 = v37;
  if ( v11 )
  {
    v31 = v11 - 1;
    v32 = 8 * v11 - 8;
    while ( v11 <= 0x10 )
    {
      if ( (v31 & 0x1FFFFFFFFFFFFFF0LL) != 0 || v32 > 0x80 )
        goto LABEL_107;
      put_inst(*(__int64 *)((char *)&v38 + v32), v14, v15, v16, v17);
      v32 -= 8LL;
      --v31;
      if ( v32 == -8 )
        goto LABEL_95;
    }
LABEL_108:
    __break(0x5512u);
  }
LABEL_95:
  v33 = *(_QWORD *)(a2 + 6544);
  if ( !v33 )
    goto LABEL_100;
  v34 = *(unsigned int (__fastcall **)(__int64, __int64))(v33 + 48);
  if ( !v34 )
    goto LABEL_100;
  v35 = *(unsigned int *)(a2 + 3920);
  if ( *((_DWORD *)v34 - 1) != -2114196824 )
    __break(0x8228u);
  if ( !v34(a2, v35) )
LABEL_100:
    enable_irq(a1);
  result = 1;
LABEL_106:
  _ReadStatusReg(SP_EL0);
  return result;
}
