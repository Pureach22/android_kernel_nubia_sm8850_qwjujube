__int64 __fastcall tpg_hw_flush_requests(unsigned int *a1, unsigned int a2, char a3)
{
  unsigned int *v6; // x22
  unsigned int v7; // w20
  unsigned int *v8; // x8
  __int64 v9; // x11
  unsigned int *v10; // x20
  unsigned int **v11; // x9
  unsigned int *v12; // x1
  __int64 v13; // x6
  __int64 v14; // x7
  const char *v15; // x5
  __int64 v16; // x4
  unsigned int *v17; // x9
  unsigned int *v18; // x1
  unsigned int *v19; // x28
  unsigned int **v20; // x8
  unsigned int *v21; // x9
  unsigned int *v23; // x9

  if ( a1 )
  {
    mutex_lock(a1 + 12);
    if ( (a3 & 1) != 0 )
    {
      v6 = *((unsigned int **)a1 + 26);
      if ( v6 != a1 + 52 )
      {
        do
        {
          v19 = *(unsigned int **)v6;
          v18 = v6 - 26;
          if ( *((_QWORD *)v6 - 13) <= (unsigned __int64)a2 )
          {
            if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                debug_mdl & 0x200000000LL,
                4,
                "tpg_hw_free_waiting_requests_locked",
                330,
                "TPG[%d] freeing waiting_request[%lld] ",
                *a1);
              v18 = v6 - 26;
            }
            v20 = *((unsigned int ***)v6 + 1);
            if ( *v20 == v6 && (v21 = *(unsigned int **)v6, *(unsigned int **)(*(_QWORD *)v6 + 8LL) == v6) )
            {
              *((_QWORD *)v21 + 1) = v20;
              *v20 = v21;
            }
            else
            {
              _list_del_entry_valid_or_report(v6);
              v18 = v17;
            }
            *(_QWORD *)v6 = 0xDEAD000000000100LL;
            *((_QWORD *)v6 + 1) = 0xDEAD000000000122LL;
            --a1[61];
            tpg_hw_release_vc_slots_locked((__int64)a1, v18);
          }
          v6 = v19;
        }
        while ( v19 != a1 + 52 );
      }
      v13 = *a1;
      v15 = "TPG[%d] Last Req pending to be flushed: %lld";
      v16 = 1460;
      v14 = a2;
      *((_QWORD *)a1 + 32) = a2;
    }
    else
    {
      v8 = *((unsigned int **)a1 + 26);
      do
      {
        if ( v8 == a1 + 52 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x200000000LL,
            1,
            "tpg_hw_flush_requests",
            1477,
            "TPG[%d] Flush req_id[%lld] not found in waiting queue",
            *a1,
            a2);
          v7 = -22;
          goto LABEL_26;
        }
        v9 = *((_QWORD *)v8 - 13);
        v10 = v8;
        v8 = *(unsigned int **)v8;
      }
      while ( v9 != a2 );
      v11 = *((unsigned int ***)v10 + 1);
      v12 = v10 - 26;
      if ( *v11 == v10 && *((unsigned int **)v8 + 1) == v10 )
      {
        *((_QWORD *)v8 + 1) = v11;
        *v11 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v10);
        v12 = v23;
      }
      *(_QWORD *)v10 = 0xDEAD000000000100LL;
      *((_QWORD *)v10 + 1) = 0xDEAD000000000122LL;
      --a1[61];
      tpg_hw_release_vc_slots_locked((__int64)a1, v12);
      v13 = *a1;
      v14 = *((_QWORD *)v10 - 13);
      v15 = "TPG[%d] Req[%lld] deleted from wait_queue";
      v16 = 1471;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      0x200000000LL,
      3,
      "tpg_hw_flush_requests",
      v16,
      v15,
      v13,
      v14);
    v7 = 0;
LABEL_26:
    mutex_unlock(a1 + 12);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_flush_requests",
      1446,
      "Invalid tpg_hw param");
    return (unsigned int)-22;
  }
  return v7;
}
