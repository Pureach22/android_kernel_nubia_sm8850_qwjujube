__int64 __fastcall qrtr_node_release(__int64 result)
{
  _QWORD *v2; // x19
  __int64 v3; // x20
  bool v4; // cc
  __int64 v5; // x9
  __int64 v6; // x8
  _QWORD *v7; // x22
  __int64 v8; // t1
  _QWORD *v9; // x8
  _QWORD *v10; // x0
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x8
  _QWORD *v14; // x20
  __int64 v15; // t1
  __int64 v16; // x21
  _QWORD *v17; // x26
  _QWORD *v18; // x27
  _QWORD *v19; // x22
  _QWORD *v20; // x8
  _QWORD *v21; // t2
  __int64 v22; // x0
  int v25; // w9
  int v31; // w8
  __int64 v32; // [xsp+8h] [xbp-28h] BYREF
  __int64 v33; // [xsp+10h] [xbp-20h]
  __int64 v34; // [xsp+18h] [xbp-18h]
  __int64 v35; // [xsp+20h] [xbp-10h]
  __int64 v36; // [xsp+28h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    _X20 = (unsigned int *)(result + 56);
    v2 = (_QWORD *)result;
    result = refcount_dec_not_one(result + 56);
    if ( (result & 1) == 0 )
    {
      down_write(&qrtr_epts_lock);
      __asm { PRFM            #0x11, [X20] }
      do
        v31 = __ldxr(_X20);
      while ( __stlxr(v31 - 1, _X20) );
      if ( v31 == 1 )
      {
        __dmb(9u);
        v34 = 0;
        v35 = 0;
        v3 = raw_spin_lock_irqsave(&qrtr_nodes_lock);
        v32 = 0;
        v33 = 0;
LABEL_8:
        while ( 1 )
        {
          v7 = (_QWORD *)radix_tree_next_chunk(&qrtr_nodes, &v32, 0);
          if ( !v7 )
            break;
LABEL_9:
          if ( (_QWORD *)*v7 == v2 )
            radix_tree_iter_delete(&qrtr_nodes, &v32, v7);
          v6 = v32 + 1;
          v5 = ~v32 + v33;
          while ( 1 )
          {
            v4 = v5-- < 1;
            if ( v4 )
              break;
            v32 = v6++;
            v8 = v7[1];
            ++v7;
            if ( v8 )
            {
              if ( v7 )
                goto LABEL_9;
              goto LABEL_8;
            }
          }
        }
        raw_spin_unlock_irqrestore(&qrtr_nodes_lock, v3);
        v9 = (_QWORD *)v2[22];
        v10 = v2 + 21;
        if ( (_QWORD *)*v9 == v2 + 21 && (v11 = *v10, *(_QWORD **)(*v10 + 8LL) == v10) )
        {
          *(_QWORD *)(v11 + 8) = v9;
          *v9 = v11;
        }
        else
        {
          _list_del_entry_valid_or_report(v10);
        }
        v2[21] = 0xDEAD000000000100LL;
        v2[22] = 0xDEAD000000000122LL;
        up_write(&qrtr_epts_lock);
        kthread_flush_worker(v2 + 23);
        kthread_stop(v2[30]);
        skb_queue_purge_reason(v2 + 18, 85);
        wakeup_source_unregister(v2[41]);
        xa_destroy(v2 + 42);
        mutex_lock(v2 + 12);
        v32 = 0;
        v33 = 0;
LABEL_20:
        while ( 1 )
        {
          v14 = (_QWORD *)radix_tree_next_chunk(v2 + 10, &v32, 0);
          if ( !v14 )
            break;
LABEL_21:
          v16 = *v14;
          v17 = (_QWORD *)(*v14 + 32LL);
          v18 = (_QWORD *)*v17;
          while ( v18 != v17 )
          {
            v19 = v18;
            v21 = v18;
            v18 = (_QWORD *)*v18;
            v20 = (_QWORD *)v21[1];
            if ( (_QWORD *)*v20 == v19 && (_QWORD *)v18[1] == v19 )
            {
              v18[1] = v20;
              *v20 = v18;
            }
            else
            {
              _list_del_entry_valid_or_report(v19);
            }
            v22 = v19[2];
            *v19 = 0xDEAD000000000100LL;
            v19[1] = 0xDEAD000000000122LL;
            _X8 = (unsigned int *)(v22 + 128);
            __asm { PRFM            #0x11, [X8] }
            do
              v25 = __ldxr(_X8);
            while ( __stlxr(v25 - 1, _X8) );
            if ( v25 == 1 )
            {
              __dmb(9u);
              sk_free(v22);
            }
            else if ( v25 <= 0 )
            {
              refcount_warn_saturate(v22 + 128, 3);
            }
            kfree(v19);
          }
          radix_tree_iter_delete(v2 + 10, &v32, v14);
          kfree(v16);
          v13 = v32 + 1;
          v12 = ~v32 + v33;
          while ( 1 )
          {
            v4 = v12-- < 1;
            if ( v4 )
              break;
            v32 = v13++;
            v15 = v14[1];
            ++v14;
            if ( v15 )
            {
              if ( v14 )
                goto LABEL_21;
              goto LABEL_20;
            }
          }
        }
        mutex_unlock(v2 + 12);
        result = kfree(v2);
      }
      else
      {
        if ( v31 <= 0 )
          refcount_warn_saturate(_X20, 3);
        result = up_write(&qrtr_epts_lock);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
