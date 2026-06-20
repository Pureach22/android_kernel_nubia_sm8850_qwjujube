__int64 __fastcall fastrpc_user_obj_create(__int64 a1, __int64 a2)
{
  __int64 v3; // x24
  __int64 v4; // x19
  __int64 v5; // x24
  __int64 v6; // t1
  __int64 result; // x0
  __int64 v8; // x20
  __int64 v9; // x21
  unsigned __int64 StatusReg; // x22
  int v12; // w8
  int v13; // w0
  int v14; // w8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 *v21; // x1
  __int64 v22; // x9
  int v23; // w0
  __int64 v24; // x1
  unsigned int v30; // w8
  unsigned int v31; // w21
  _QWORD v32[2]; // [xsp+0h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 + 32);
    v6 = *(_QWORD *)(v3 - 8);
    v5 = v3 - 8;
    v4 = v6;
  }
  else
  {
    v4 = a2;
    v5 = 0;
  }
  if ( *(_DWORD *)(v4 + 64136) )
  {
    result = 4294967264LL;
    goto LABEL_6;
  }
  v8 = _kmalloc_cache_noprof(wait_for_completion_interruptible_timeout, 3520, 704);
  if ( !v8 )
  {
    result = 4294967284LL;
    goto LABEL_6;
  }
  v9 = v4 + 51648;
  if ( a1 )
  {
    _X0 = (unsigned int *)(v4 + 51664);
    __asm { PRFM            #0x11, [X0] }
    do
      v30 = __ldxr(_X0);
    while ( __stxr(v30 + 1, _X0) );
    if ( v30 )
    {
      if ( (((v30 + 1) | v30) & 0x80000000) == 0 )
      {
LABEL_11:
        *(_QWORD *)(a1 + 32) = v8;
        goto LABEL_12;
      }
      v24 = 1;
    }
    else
    {
      v24 = 2;
    }
    refcount_warn_saturate(_X0, v24);
    goto LABEL_11;
  }
LABEL_12:
  *(_DWORD *)(v8 + 320) = 0;
  _mutex_init(v8 + 328, "&fl->map_mutex", &fastrpc_user_obj_create___key);
  *(_DWORD *)(v8 + 324) = 0;
  _mutex_init(v8 + 376, "&fl->signal_create_mutex", &fastrpc_user_obj_create___key_344);
  _mutex_init(v8 + 424, "&fl->pm_qos_mutex", &fastrpc_user_obj_create___key_346);
  *(_QWORD *)(v8 + 32) = v8 + 32;
  *(_QWORD *)(v8 + 40) = v8 + 32;
  *(_QWORD *)(v8 + 48) = v8 + 48;
  *(_QWORD *)(v8 + 56) = v8 + 48;
  *(_QWORD *)(v8 + 16) = v8 + 16;
  *(_QWORD *)(v8 + 24) = v8 + 16;
  *(_QWORD *)(v8 + 64) = v8 + 64;
  *(_QWORD *)(v8 + 72) = v8 + 64;
  *(_QWORD *)v8 = v8;
  *(_QWORD *)(v8 + 8) = v8;
  *(_QWORD *)(v8 + 648) = v8 + 648;
  *(_QWORD *)(v8 + 656) = v8 + 648;
  *(_QWORD *)(v8 + 80) = v8 + 80;
  *(_QWORD *)(v8 + 88) = v8 + 80;
  *(_QWORD *)(v8 + 584) = v8 + 584;
  *(_QWORD *)(v8 + 592) = v8 + 584;
  *(_QWORD *)(v8 + 96) = v8 + 96;
  *(_QWORD *)(v8 + 104) = v8 + 96;
  *(_QWORD *)(v8 + 112) = v8 + 112;
  *(_QWORD *)(v8 + 120) = v8 + 112;
  _init_waitqueue_head(v8 + 552, "&fl->proc_state_notif.notif_wait_queue", &fastrpc_user_obj_create___key_348);
  *(_DWORD *)(v8 + 576) = 0;
  *(_DWORD *)(v8 + 472) = 0;
  _init_swait_queue_head(v8 + 480, "&x->wait", &init_completion___key);
  *(_DWORD *)(v8 + 664) = 1;
  *(_QWORD *)(v8 + 672) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v8 + 680) = v8 + 680;
  *(_QWORD *)(v8 + 688) = v8 + 680;
  *(_QWORD *)(v8 + 696) = fastrpc_file_put_worker;
  *(_QWORD *)(v8 + 128) = v4;
  *(_DWORD *)(v8 + 600) = -1;
  *(_DWORD *)(v8 + 268) = 0;
  *(_BYTE *)(v8 + 636) = 1;
  if ( a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = *(_DWORD *)(StatusReg + 1804);
    *(_DWORD *)(v8 + 248) = v12;
    *(_DWORD *)(v8 + 240) = v12;
    v13 = ida_alloc_range(v4 + 51632, 1, 64, 2080);
    if ( v13 < 0 )
      v14 = -1;
    else
      v14 = v13 + 1000 * *(_DWORD *)v4;
    *(_DWORD *)(v8 + 244) = v14;
    snprintf((char *)(v8 + 252), 0x10u, "%s", (const char *)(StatusReg + 2320));
    if ( *(_DWORD *)(v8 + 244) == -1 )
    {
      dev_err(*(_QWORD *)(v4 + 168), "too many fastrpc clients, max %u allowed\n", 64);
      v23 = -87;
    }
    else
    {
      *(_BYTE *)(v8 + 304) = *(_BYTE *)(v5 + 88);
      if ( *(_DWORD *)(v4 + 52696)
        && (v19 = _kmalloc_noprof(80LL * *(unsigned int *)(v4 + 52696), 3520), (*(_QWORD *)(v8 + 536) = v19) == 0) )
      {
        v23 = -12;
      }
      else
      {
        v20 = raw_spin_lock_irqsave(v4 + 51600);
        v21 = *(__int64 **)(v4 + 51656);
        v22 = v20;
        if ( v8 == v9 || (__int64 *)v8 == v21 || *v21 != v9 )
        {
          _list_add_valid_or_report(v8, v21, v4 + 51648);
        }
        else
        {
          *(_QWORD *)(v4 + 51656) = v8;
          *(_QWORD *)v8 = v9;
          *(_QWORD *)(v8 + 8) = v21;
          *v21 = v8;
        }
        raw_spin_unlock_irqrestore(v4 + 51600, v22);
        if ( byte_27530 != 1 || (v23 = fastrpc_reserve_dma_heap(v32)) == 0 )
        {
          result = 0;
          *(_QWORD *)(v8 + 640) = v32[0];
          goto LABEL_6;
        }
      }
    }
    v31 = v23;
    kfree(v8);
    fastrpc_channel_ctx_put(v4);
    result = v31;
    goto LABEL_6;
  }
  strcpy((char *)(v8 + 252), "default_user");
  *(_DWORD *)(v8 + 248) = -1;
  *(_QWORD *)(v8 + 240) = -1;
  v15 = raw_spin_lock_irqsave(v4 + 51600);
  v16 = *(unsigned int *)(v4 + 4);
  if ( (int)v16 < 1 )
  {
LABEL_22:
    raw_spin_unlock_irqrestore(v4 + 51600, v15);
    kfree(v8);
    result = 4294967233LL;
  }
  else
  {
    v17 = 0;
    v18 = v4;
    while ( 1 )
    {
      if ( v17 == 51 )
        __break(0x5512u);
      if ( *(_DWORD *)(v18 + 1184) == 1 && (*(_BYTE *)(v18 + 188) & 1) != 0 )
        break;
      ++v17;
      v18 += 1024;
      if ( v16 == v17 )
        goto LABEL_22;
    }
    *(_QWORD *)(v8 + 136) = v18 + 176;
    raw_spin_unlock_irqrestore(v4 + 51600, v15);
    result = 0;
    *(_QWORD *)(v4 + 64248) = v8;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
