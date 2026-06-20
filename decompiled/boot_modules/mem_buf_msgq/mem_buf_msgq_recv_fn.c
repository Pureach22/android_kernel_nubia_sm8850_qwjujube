__int64 __fastcall mem_buf_msgq_recv_fn(_QWORD *a1)
{
  unsigned int *v2; // x20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x27
  unsigned int v5; // w26
  unsigned int v6; // w0
  __int64 v7; // x28
  __int64 v8; // x2
  int v9; // w23
  __int64 v10; // x0
  __int64 v11; // x3
  __int64 v12; // x26
  _DWORD *v13; // x8
  __int64 v14; // x0
  _DWORD *v15; // x8
  __int64 v16; // x2
  void *v17; // x0
  const char *v18; // x1
  __int64 v19; // x1
  __int64 v20; // x2
  _DWORD *v21; // x8
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v2 = (unsigned int *)_kmalloc_cache_noprof(gh_msgq_send, 3520, 240);
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_41;
  }
  if ( (kthread_should_stop() & 1) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v6 = gh_msgq_recv(a1[11], v2, 240, v22, 0);
      if ( (v6 & 0x80000000) != 0 )
      {
        v5 = v6;
        if ( (unsigned int)__ratelimit(&mem_buf_msgq_recv_fn__rs, "mem_buf_msgq_recv_fn") )
        {
          v17 = &unk_6F0B;
          v18 = "mem_buf_msgq_recv_fn";
          v8 = v5;
LABEL_32:
          printk(v17, v18, v8);
        }
      }
      else
      {
        v7 = v22[0];
        if ( v22[0] >= 0xCu && v22[0] == v2[2] )
        {
          v8 = v2[1];
          if ( (int)v8 > 1 )
          {
            if ( (_DWORD)v8 == 2 )
            {
              v15 = *(_DWORD **)(*a1 + 16LL);
              goto LABEL_26;
            }
            if ( (_DWORD)v8 != 3 )
            {
LABEL_31:
              v17 = &unk_6FCD;
              v18 = "mem_buf_process_msg";
              goto LABEL_32;
            }
            if ( v22[0] != 20 )
            {
              printk(&unk_70B7, "mem_buf_process_relinquish_resp", v8);
              continue;
            }
            mutex_lock(a1 + 2);
            v14 = idr_find(a1 + 8, *v2);
            if ( v14 )
              complete(v14 + 8);
            else
              printk(&unk_7037, "mem_buf_process_relinquish_resp", *v2);
          }
          else
          {
            if ( !(_DWORD)v8 )
            {
              v15 = *(_DWORD **)*a1;
LABEL_26:
              v16 = v22[0];
              if ( *(v15 - 1) != 934638931 )
                __break(0x8228u);
              ((void (__fastcall *)(_QWORD *, unsigned int *, __int64))v15)(a1, v2, v16);
              continue;
            }
            if ( (_DWORD)v8 != 1 )
              goto LABEL_31;
            mutex_lock(a1 + 2);
            v9 = *(_DWORD *)(StatusReg + 68);
            *(_DWORD *)(StatusReg + 68) = v9 | 0x800;
            v10 = idr_find(a1 + 8, *v2);
            if ( v10 )
            {
              v11 = *(_QWORD *)(v10 + 40);
              v12 = v10;
              v13 = *(_DWORD **)(*a1 + 8LL);
              if ( *(v13 - 1) != 1331749862 )
                __break(0x8228u);
              *(_DWORD *)(v10 + 4) = ((__int64 (__fastcall *)(_QWORD *, unsigned int *, __int64, __int64))v13)(
                                       a1,
                                       v2,
                                       v7,
                                       v11);
              complete(v12 + 8);
            }
            else
            {
              printk(&unk_7037, "mem_buf_process_alloc_resp", *v2);
              mutex_unlock(a1 + 2);
              if ( !v2[3] )
              {
                v20 = v2[4];
                v19 = v2[5];
                v21 = *(_DWORD **)(*a1 + 24LL);
                if ( *(v21 - 1) != -1844471269 )
                  __break(0x8228u);
                ((void (__fastcall *)(_QWORD *, __int64, __int64))v21)(a1, v19, v20);
              }
              mutex_lock(a1 + 2);
            }
            *(_DWORD *)(StatusReg + 68) &= v9 | 0xFFFFF7FF;
          }
          mutex_unlock(a1 + 2);
        }
        else
        {
          printk(&unk_721D, "mem_buf_process_msg", v22[0]);
        }
      }
    }
    while ( (kthread_should_stop() & 1) == 0 );
  }
  kfree(v2);
  result = 0;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
