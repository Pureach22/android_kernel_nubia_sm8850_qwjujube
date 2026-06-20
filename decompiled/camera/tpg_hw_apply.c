__int64 __fastcall tpg_hw_apply(_DWORD *a1, unsigned __int64 a2)
{
  unsigned __int64 v4; // x8
  unsigned int v5; // w21
  _QWORD *v6; // x21
  _QWORD *v7; // x1
  _QWORD *v8; // x8
  __int64 v9; // x9
  _DWORD *v10; // x0
  _QWORD *v11; // x22
  _QWORD *v12; // x23
  _QWORD *v13; // x1
  char *v14; // x9
  char *v15; // x1
  __int64 v16; // x8
  char *v17; // x9
  char *v19; // x21

  if ( a1 )
  {
    mutex_lock(a1 + 12);
    v4 = *((_QWORD *)a1 + 32);
    if ( v4 >= a2 && v4 != -1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_lookup_queues_and_apply_req_locked",
        657,
        "TPG[%d] Reject Request: %lld, last request flushed: %lld",
        *a1,
        a2,
        *((_QWORD *)a1 + 32));
      v5 = -53;
LABEL_45:
      mutex_unlock(a1 + 12);
      return v5;
    }
    v6 = *((_QWORD **)a1 + 26);
    if ( v6 == (_QWORD *)(a1 + 52) )
    {
      if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x200000000LL,
          4,
          "tpg_hw_lookup_queues_and_apply_req_locked",
          696,
          "TPG[%d] got apply for request %d when waiting queue is empty",
          *a1,
          a2);
      v14 = (char *)(a1 + 56);
      while ( 1 )
      {
        v14 = *(char **)v14;
        if ( v14 == (char *)(a1 + 56) )
          break;
        if ( *((_QWORD *)v14 - 13) == a2 )
        {
          v15 = v14 - 104;
          if ( v14 == &byte_68 )
            break;
          v16 = debug_mdl;
          if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
          {
LABEL_48:
            v19 = v15;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v16 & 0x200000000LL,
              4,
              "tpg_hw_reapply_from_active_queue_locked",
              632,
              "TPG[%d] got reapply request %d",
              *a1,
              a2);
            v15 = v19;
          }
LABEL_39:
          if ( (unsigned int)tpg_hw_check_hw_state_and_apply_settings_locked(a1, v15) )
            goto LABEL_44;
          goto LABEL_40;
        }
      }
    }
    else
    {
      *((_QWORD *)a1 + 32) = -1;
      v7 = v6 - 13;
      if ( *(v6 - 13) == a2 )
      {
        if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200000000LL,
            4,
            "tpg_hw_lookup_queues_and_apply_req_locked",
            667,
            "TPG[%d] request %d got matched",
            *a1,
            a2);
          v7 = v6 - 13;
        }
        if ( !(unsigned int)tpg_hw_check_hw_state_and_apply_settings_locked(a1, v7) )
        {
          v8 = (_QWORD *)v6[1];
          if ( (_QWORD *)*v8 == v6 && (v9 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
          {
            *(_QWORD *)(v9 + 8) = v8;
            *v8 = v9;
          }
          else
          {
            _list_del_entry_valid_or_report(v6);
          }
          *v6 = 0xDEAD000000000100LL;
          v6[1] = 0xDEAD000000000122LL;
          v11 = a1 + 56;
          v10 = *((_DWORD **)a1 + 28);
          --a1[61];
          if ( v10 != a1 + 56 && a1[60] >= 2u )
          {
            v12 = v10 - 26;
            list_del_0();
            --a1[60];
            tpg_hw_release_vc_slots_locked((__int64)a1, v12);
          }
          v13 = *((_QWORD **)a1 + 29);
          if ( v6 == v11 || v13 == v6 || (_QWORD *)*v13 != v11 )
          {
            _list_add_valid_or_report(v6);
          }
          else
          {
            *((_QWORD *)a1 + 29) = v6;
            *v6 = v11;
            v6[1] = v13;
            *v13 = v6;
          }
          ++a1[60];
LABEL_40:
          v5 = 0;
          if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x200000000LL,
              4,
              "tpg_hw_lookup_queues_and_apply_req_locked",
              701,
              "TPG[%d] Hw Apply done for req %lld",
              *a1,
              a2);
            v5 = 0;
          }
          goto LABEL_45;
        }
        goto LABEL_44;
      }
      v17 = (char *)(a1 + 56);
      while ( 1 )
      {
        v17 = *(char **)v17;
        if ( v17 == (char *)(a1 + 56) )
          break;
        if ( *((_QWORD *)v17 - 13) == a2 )
        {
          v15 = v17 - 104;
          if ( v17 == &byte_68 )
            break;
          v16 = debug_mdl;
          if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
            goto LABEL_48;
          goto LABEL_39;
        }
      }
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_reapply_from_active_queue_locked",
      635,
      "Could not find reapply request in active queue %d",
      a2);
LABEL_44:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_lookup_queues_and_apply_req_locked",
      703,
      "TPG[%d] Hw Apply Failed for req %lld",
      *a1,
      a2);
    v5 = -11;
    goto LABEL_45;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x200000000LL,
    1,
    "tpg_hw_apply",
    1396,
    "Invalid params");
  return (unsigned int)-22;
}
