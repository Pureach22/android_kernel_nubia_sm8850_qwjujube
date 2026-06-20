__int64 __fastcall msm_cvp_open(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  unsigned __int64 v6; // x8
  __int64 v8; // x0
  __int64 *v10; // x8
  __int64 *v11; // x20
  unsigned int v12; // w22
  unsigned int v13; // w21
  char v14; // w9
  unsigned __int64 v15; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v17; // x1
  __int64 v18; // x2
  void *v19; // x0
  __int64 *i; // x21
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  __int64 v23; // x21
  int v24; // w8
  size_t v25; // x0
  unsigned __int64 v26; // x2
  unsigned __int64 v27; // x8
  unsigned int v34; // w9

  v4 = *(_QWORD *)(cvp_driver + 48);
  if ( v4 )
  {
    if ( a1 == 3 && (msm_cvp_auto_pil & 1) == 0 )
    {
      result = 0;
      if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8E256, "sess", a3, a4);
        return 0;
      }
      return result;
    }
    v8 = *(_QWORD *)(cvp_driver + 48);
    *(_DWORD *)(v4 + 1016) = 32;
    mutex_lock(v8);
    v10 = *(__int64 **)(v4 + 280);
    v11 = (__int64 *)(v4 + 280);
    if ( v10 == (__int64 *)(v4 + 280) )
    {
      v12 = 0;
      v13 = 0;
    }
    else
    {
      v12 = 0;
      v13 = 0;
      do
      {
        v14 = *((_DWORD *)v10 + 3522);
        v10 = (__int64 *)*v10;
        ++v12;
        v13 += v14 & 1;
      }
      while ( v10 != v11 );
    }
    mutex_unlock(v4);
    if ( v12 >= *(_DWORD *)(v4 + 1016) )
    {
      if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
        goto LABEL_26;
      StatusReg = _ReadStatusReg(SP_EL0);
      v17 = *(unsigned int *)(StatusReg + 1800);
      v18 = *(unsigned int *)(StatusReg + 1804);
      v19 = &unk_85B5F;
    }
    else
    {
      if ( v13 < *(_DWORD *)(v4 + 1020) )
      {
        result = _kmalloc_large_noprof(15416, 3520);
        if ( result )
        {
          v23 = result;
          printk(&unk_9341F, *(unsigned int *)(a2 + 1800), *(unsigned int *)(a2 + 1804), "sess");
          _mutex_init(v23 + 32, "&inst->sync_lock", &msm_cvp_open___key);
          _mutex_init(v23 + 80, "&inst->lock", &msm_cvp_open___key_11);
          *(_DWORD *)(v23 + 288) = 0;
          _mutex_init(v23 + 416, "&mlist->lock", &INIT_MSM_CVP_LIST___key);
          *(_QWORD *)(v23 + 400) = v23 + 400;
          *(_QWORD *)(v23 + 408) = v23 + 400;
          _mutex_init(v23 + 480, "&mlist->lock", &INIT_MSM_CVP_LIST___key);
          *(_QWORD *)(v23 + 464) = v23 + 464;
          *(_QWORD *)(v23 + 472) = v23 + 464;
          _mutex_init(v23 + 536, "&cache->lock", &INIT_DMAMAP_CACHE___key);
          *(_QWORD *)(v23 + 584) = 0;
          *(_DWORD *)(v23 + 592) = 0;
          _mutex_init(v23 + 616, "&mlist->lock", &INIT_MSM_CVP_LIST___key);
          *(_QWORD *)(v23 + 600) = v23 + 600;
          *(_QWORD *)(v23 + 608) = v23 + 600;
          _mutex_init(v23 + 680, "&mlist->lock", &INIT_MSM_CVP_LIST___key);
          *(_QWORD *)(v23 + 664) = v23 + 664;
          *(_QWORD *)(v23 + 672) = v23 + 664;
          *(_DWORD *)(v23 + 12920) = 0;
          *(_QWORD *)(v23 + 12928) = 0;
          _init_waitqueue_head(v23 + 296, "&inst->event_handler.wq", &msm_cvp_open___key_13);
          *(_DWORD *)(v23 + 14824) = 1;
          *(_DWORD *)(v23 + 136) = a1;
          *(_DWORD *)(v23 + 328) = 1;
          *(_QWORD *)(v23 + 128) = v4;
          *(_QWORD *)(v23 + 14048) = 0;
          *(_QWORD *)(v23 + 14056) = 0;
          *(_QWORD *)(v23 + 14064) = 0;
          *(_QWORD *)(v23 + 14072) = 0;
          v24 = *(_DWORD *)(v4 + 996);
          *(_DWORD *)(v23 + 12936) = 0;
          *(_DWORD *)(v23 + 15408) = v24;
          _init_swait_queue_head(v23 + 12944, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 12968) = 0;
          _init_swait_queue_head(v23 + 12976, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13000) = 0;
          _init_swait_queue_head(v23 + 13008, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13032) = 0;
          _init_swait_queue_head(v23 + 13040, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13064) = 0;
          _init_swait_queue_head(v23 + 13072, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13096) = 0;
          _init_swait_queue_head(v23 + 13104, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13128) = 0;
          _init_swait_queue_head(v23 + 13136, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13160) = 0;
          _init_swait_queue_head(v23 + 13168, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13192) = 0;
          _init_swait_queue_head(v23 + 13200, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13224) = 0;
          _init_swait_queue_head(v23 + 13232, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13256) = 0;
          _init_swait_queue_head(v23 + 13264, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13288) = 0;
          _init_swait_queue_head(v23 + 13296, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13320) = 0;
          _init_swait_queue_head(v23 + 13328, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13352) = 0;
          _init_swait_queue_head(v23 + 13360, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13384) = 0;
          _init_swait_queue_head(v23 + 13392, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13416) = 0;
          _init_swait_queue_head(v23 + 13424, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13448) = 0;
          _init_swait_queue_head(v23 + 13456, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13480) = 0;
          _init_swait_queue_head(v23 + 13488, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13512) = 0;
          _init_swait_queue_head(v23 + 13520, "&x->wait", &init_completion___key_0);
          *(_DWORD *)(v23 + 13544) = 0;
          _init_swait_queue_head(v23 + 13552, "&x->wait", &init_completion___key_0);
          msm_cvp_session_init(v23);
          _init_fence_queue(v23);
          mutex_lock(v4);
          mutex_lock(v4 + 48);
          list_add_tail_1(v23, v4 + 280);
          while ( 1 )
          {
            _X8 = &nr_insts;
            __asm { PRFM            #0x11, [X8] }
            do
              v34 = __ldxr((unsigned int *)&nr_insts);
            while ( __stxr(v34 + 1, (unsigned int *)&nr_insts) );
            mutex_unlock(v4 + 48);
            mutex_unlock(v4);
            *(_DWORD *)(v23 + 176) = 0;
            *(_QWORD *)(v23 + 192) = v23 + 192;
            *(_QWORD *)(v23 + 200) = v23 + 192;
            *(_DWORD *)(v23 + 184) = 0;
            _init_waitqueue_head(v23 + 208, "&inst->session_queue.wq", &_init_session_queue___key);
            *(_DWORD *)(v23 + 180) = 1;
            if ( (unsigned int)msm_cvp_comm_try_state(v23, 3u) )
              break;
            *(_QWORD *)(v23 + 13576) = msm_cvp_debugfs_init_inst(v23, *(_QWORD *)(v4 + 296));
            v25 = strnlen((const char *)(a2 + 2320), 0x10u);
            if ( v25 >= 0x11 )
            {
              _fortify_panic(2);
            }
            else
            {
              if ( v25 == 16 )
                v26 = 16;
              else
                v26 = v25 + 1;
              if ( v26 < 0x11 )
              {
                sized_strscpy(v23 + 15392, a2 + 2320);
                return v23;
              }
            }
            _fortify_panic(7);
          }
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v27 = _ReadStatusReg(SP_EL0);
            printk(&unk_87A43, *(unsigned int *)(v27 + 1800), *(unsigned int *)(v27 + 1804), &unk_8E7CE);
          }
          kref_put(v23 + 14824);
          return v23;
        }
        else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v15 = _ReadStatusReg(SP_EL0);
          printk(&unk_933E9, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
          return 0;
        }
        return result;
      }
      if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      {
LABEL_26:
        if ( (msm_cvp_debug & 1) != 0 )
          goto LABEL_27;
        goto LABEL_29;
      }
      v22 = _ReadStatusReg(SP_EL0);
      v17 = *(unsigned int *)(v22 + 1800);
      v18 = *(unsigned int *)(v22 + 1804);
      v19 = &unk_83E08;
    }
    printk(v19, v17, v18, "warn");
    if ( (msm_cvp_debug & 1) != 0 )
    {
LABEL_27:
      if ( !msm_cvp_debug_out )
      {
        v21 = _ReadStatusReg(SP_EL0);
        printk(&unk_933A5, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
      }
    }
LABEL_29:
    mutex_lock(v4);
    for ( i = *(__int64 **)(v4 + 280); i != v11; i = (__int64 *)*i )
      cvp_print_inst(1, (__int64)i);
    mutex_unlock(v4);
    return 0;
  }
  result = 0;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v6 = _ReadStatusReg(SP_EL0);
    printk(&unk_88574, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
    return 0;
  }
  return result;
}
