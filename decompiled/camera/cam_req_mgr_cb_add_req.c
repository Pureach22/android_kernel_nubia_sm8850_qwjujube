__int64 __fastcall cam_req_mgr_cb_add_req(unsigned int *a1, __int64 a2)
{
  __int64 link_priv; // x0
  __int64 v4; // x19
  __int64 v5; // x24
  __int64 task; // x0
  __int64 v7; // x8
  int v8; // w9
  __int64 v10; // x26
  unsigned int v11; // w0
  unsigned int v12; // w23
  __int64 result; // x0
  __int64 v14; // x6
  int v15; // w9
  __int64 v16; // x0
  __int64 v17; // x8
  unsigned int v18; // w7
  const char *v19; // x6
  __int64 v20; // x26
  unsigned int v26; // w10

  if ( a1 )
  {
    link_priv = cam_get_link_priv(*a1, a2);
    if ( link_priv )
    {
      v4 = link_priv;
      v5 = link_priv + 0x8000;
      if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
      {
        v17 = *(unsigned int *)(link_priv + 4);
        v18 = a1[1];
        if ( (int)v17 < 1 )
        {
          v19 = "Invalid dev_hdl";
        }
        else
        {
          v19 = (const char *)(*(_QWORD *)(link_priv + 40) + 28LL);
          while ( *((_DWORD *)v19 - 7) != v18 )
          {
            --v17;
            v19 += 320;
            if ( !v17 )
            {
              v19 = "Invalid dev_hdl";
              break;
            }
          }
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000010,
          4,
          "cam_req_mgr_cb_add_req",
          4106,
          "dev name %s dev_hdl %d dev req %lld, trigger_eof %d link_state %d on link 0x%x",
          v19,
          v18,
          *((_QWORD *)a1 + 1),
          *((unsigned __int8 *)a1 + 24),
          *(_DWORD *)(link_priv + 33152),
          *(_DWORD *)link_priv);
      }
      mutex_lock(v4 + 33168);
      if ( (_cam_req_mgr_find_slot_for_req(*(int **)(v4 + 48), *((_QWORD *)a1 + 1)) & 0x80000000) != 0 )
      {
        v14 = *((_QWORD *)a1 + 1);
        v15 = *(_DWORD *)v4;
        if ( *(_QWORD *)(v5 + 496) >= (__int64)(unsigned int)v14 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            16,
            3,
            "cam_req_mgr_cb_add_req",
            4115,
            "req %lld not found in in_q; it has been flushed [last_flush_req %lld] link 0x%x",
            v14,
            *(_QWORD *)(v5 + 496),
            v15);
          v12 = -53;
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            16,
            1,
            "cam_req_mgr_cb_add_req",
            4120,
            "req %lld not found in in_q on link 0x%x [last_flush_req %lld]",
            v14,
            v15,
            *(_QWORD *)(v5 + 496));
          v12 = -2;
        }
      }
      else
      {
        task = cam_req_mgr_workq_get_task(*(_QWORD *)(v4 + 24));
        if ( task )
        {
          v7 = *(_QWORD *)(task + 8);
          *(_DWORD *)v7 = 2;
          *(_QWORD *)(v7 + 16) = *((_QWORD *)a1 + 1);
          *(_DWORD *)(v7 + 8) = *a1;
          *(_DWORD *)(v7 + 12) = a1[1];
          v8 = *((unsigned __int8 *)a1 + 24);
          *(_BYTE *)(v7 + 32) = v8;
          *(_DWORD *)(v7 + 24) = a1[4];
          *(_DWORD *)(v7 + 28) = a1[5];
          *(_BYTE *)(v7 + 33) = *((_BYTE *)a1 + 25);
          if ( v8 == 1 )
          {
            _X9 = (unsigned int *)(v5 + 572);
            while ( 1 )
            {
              __asm { PRFM            #0x11, [X9] }
              do
                v26 = __ldxr(_X9);
              while ( __stxr(v26 + 1, _X9) );
              if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
              {
                v20 = task;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x1000010,
                  4,
                  "cam_req_mgr_cb_add_req",
                  4147,
                  "Req_id: %llu, eof_event_cnt: %d, link 0x%x",
                  *(_QWORD *)(v7 + 16),
                  *(_DWORD *)(v5 + 572),
                  *(_DWORD *)v4);
                task = v20;
              }
              if ( *(int *)(v5 + 480) < 1 )
                break;
              v10 = task;
              mutex_lock(*(_QWORD *)(v5 + 456) + 33056LL);
              *(_DWORD *)(*(_QWORD *)(v5 + 456) + 33340LL) = *(_DWORD *)(v5 + 572);
              if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x1000010,
                  4,
                  "cam_req_mgr_cb_add_req",
                  4154,
                  "Sync link idx: %d, sync link_hdl: 0x%x, eof_event_cnt: %d",
                  0,
                  **(_DWORD **)(v5 + 456),
                  *(_DWORD *)(*(_QWORD *)(v5 + 456) + 33340LL));
              mutex_unlock(*(_QWORD *)(v5 + 456) + 33056LL);
              task = v10;
              if ( *(int *)(v5 + 480) < 2 )
                break;
              mutex_lock(*(_QWORD *)(v5 + 464) + 33056LL);
              *(_DWORD *)(*(_QWORD *)(v5 + 464) + 33340LL) = *(_DWORD *)(v5 + 572);
              if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x1000010,
                  4,
                  "cam_req_mgr_cb_add_req",
                  4154,
                  "Sync link idx: %d, sync link_hdl: 0x%x, eof_event_cnt: %d",
                  1,
                  **(_DWORD **)(v5 + 464),
                  *(_DWORD *)(*(_QWORD *)(v5 + 464) + 33340LL));
              mutex_unlock(*(_QWORD *)(v5 + 464) + 33056LL);
              task = v10;
              if ( *(int *)(v5 + 480) < 3 )
                break;
              mutex_lock(*(_QWORD *)(v5 + 472) + 33056LL);
              *(_DWORD *)(*(_QWORD *)(v5 + 472) + 33340LL) = *(_DWORD *)(v5 + 572);
              if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x1000010,
                  4,
                  "cam_req_mgr_cb_add_req",
                  4154,
                  "Sync link idx: %d, sync link_hdl: 0x%x, eof_event_cnt: %d",
                  2,
                  **(_DWORD **)(v5 + 472),
                  *(_DWORD *)(*(_QWORD *)(v5 + 472) + 33340LL));
              mutex_unlock(*(_QWORD *)(v5 + 472) + 33056LL);
              v7 = *(unsigned int *)(v5 + 480);
              task = v10;
              if ( (int)v7 <= 3 )
                break;
              __break(0x5512u);
            }
          }
          *(_QWORD *)(task + 16) = cam_req_mgr_process_add_req;
          v11 = cam_req_mgr_workq_enqueue_task(task, v4, 0);
          if ( (debug_mdl & 0x10) != 0 )
          {
            v12 = v11;
            if ( !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x10,
                4,
                "cam_req_mgr_cb_add_req",
                4162,
                "X: dev %x dev req %lld on link 0x%x",
                a1[1],
                *((_QWORD *)a1 + 1),
                *(_DWORD *)v4);
          }
          else
          {
            v12 = v11;
          }
        }
        else
        {
          if ( (unsigned int)__ratelimit(&cam_req_mgr_cb_add_req__rs, "cam_req_mgr_cb_add_req") )
            v16 = 3;
          else
            v16 = 2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            v16,
            16,
            1,
            "cam_req_mgr_cb_add_req",
            4129,
            "no empty task dev %x req %lld",
            a1[1],
            *((_QWORD *)a1 + 1));
          v12 = -16;
        }
      }
      mutex_unlock(v4 + 33168);
      return v12;
    }
    else
    {
      result = 4294967274LL;
      if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "cam_req_mgr_cb_add_req",
          4098,
          "link ptr NULL %x",
          *a1);
        return 4294967274LL;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_cb_add_req",
      4092,
      "sof_data is NULL");
    return 4294967274LL;
  }
  return result;
}
