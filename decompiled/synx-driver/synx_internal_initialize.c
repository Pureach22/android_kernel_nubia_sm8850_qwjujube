__int64 __fastcall synx_internal_initialize(const char **a1)
{
  unsigned __int64 v1; // x19
  __int64 v3; // x4
  __int64 v4; // x5
  const char *v5; // x20
  size_t v6; // x0
  unsigned __int64 v7; // x2
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x9
  unsigned __int64 *v10; // x8
  __int64 v11; // x10
  __int64 v12; // t1
  unsigned __int64 StatusReg; // x20
  __int64 v14; // x23
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x8
  unsigned __int64 v26; // x9

  v1 = -22;
  if ( a1 && (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( *((_DWORD *)a1 + 4) <= 0xDu )
    {
      if ( synx_dev )
      {
        v1 = vzalloc_noprof(264976);
        if ( v1 )
        {
          while ( v1 < 0xFFFFFFFFFFFFF001LL )
          {
            v5 = *a1;
            if ( !*a1 )
              goto LABEL_15;
            v6 = strnlen(*a1, 0x40u);
            if ( v6 == -1 )
            {
              _fortify_panic(2);
            }
            else
            {
              if ( v6 == 64 )
                v7 = 64;
              else
                v7 = v6 + 1;
              if ( v7 < 0x41 )
              {
                sized_strscpy(v1 + 40, v5);
LABEL_15:
                *(_BYTE *)(v1 + 24) = 1;
                *(_QWORD *)(v1 + 112) = dma_fence_context_alloc(1);
                _X9 = &synx_counter;
                __asm { PRFM            #0x11, [X9] }
                do
                {
                  v22 = __ldxr((unsigned __int64 *)&synx_counter);
                  v23 = v22 + 1;
                }
                while ( __stlxr(v23, (unsigned __int64 *)&synx_counter) );
                __dmb(0xBu);
                *(_QWORD *)(v1 + 104) = v23;
                *(_DWORD *)(v1 + 120) = 1;
                *(_DWORD *)(v1 + 264920) = 0;
                _mutex_init(v1 + 128, "&client->event_q_lock", &synx_internal_initialize___key);
                *(_QWORD *)(v1 + 176) = v1 + 176;
                *(_QWORD *)(v1 + 184) = v1 + 176;
                _init_waitqueue_head(v1 + 192, "&client->event_wq", &synx_internal_initialize___key_108);
                _X8 = (unsigned __int64 *)(v1 + 216);
                __asm { PRFM            #0x11, [X8] }
                do
                  v26 = __ldxr(_X8);
                while ( __stxr(v26 | 1, _X8) );
                raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152));
                v8 = *(_QWORD *)(synx_dev + 152) + 8 * ((0x61C8864680B583EBLL * v1) >> 56);
                v9 = v1 + 264960;
                v12 = *(_QWORD *)(v8 + 8);
                v10 = (unsigned __int64 *)(v8 + 8);
                v11 = v12;
                *(_QWORD *)(v1 + 264960) = v12;
                if ( v12 )
                  *(_QWORD *)(v11 + 8) = v9;
                *v10 = v9;
                *(_QWORD *)(v1 + 264968) = v10;
                raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152));
                if ( (unsigned int)__ratelimit(&synx_ratelimit_state, "synx_internal_initialize")
                  && (synx_debug & 4) != 0 )
                {
                  printk(&unk_291D1, "info", "synx_internal_initialize", 3757, *(_QWORD *)(v1 + 104), *a1);
                }
                return v1;
              }
            }
            _fortify_panic(7);
            StatusReg = _ReadStatusReg(SP_EL0);
            v14 = *(_QWORD *)(StatusReg + 80);
            *(_QWORD *)(StatusReg + 80) = &synx_internal_initialize__alloc_tag;
            v1 = vzalloc_noprof(264976);
            *(_QWORD *)(StatusReg + 80) = v14;
            if ( !v1 )
              break;
          }
        }
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2B8CA, &unk_29207, "synx_internal_initialize", 3732, v3, v4);
        return -12;
      }
    }
    else
    {
      return -95;
    }
  }
  return v1;
}
