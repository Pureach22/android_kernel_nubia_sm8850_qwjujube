__int64 __fastcall tpg_hw_release_vc_slots_locked(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  int v5; // w8
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // x24
  int v9; // w9
  __int64 v10; // x8
  __int64 v11; // x10
  _QWORD *v12; // x9
  _QWORD *v13; // x8
  _QWORD *v14; // x25
  _QWORD *v15; // x0
  __int64 v16; // x10
  _QWORD *v17; // x9
  _QWORD *v18; // x8
  _QWORD *v19; // x25
  _QWORD *v20; // x0
  int v22; // w8
  _QWORD *v23; // x0

  if ( a2 && (v2 = *(_QWORD *)(a1 + 32)) != 0 )
  {
    if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x200000000LL,
        4,
        "tpg_hw_release_vc_slots_locked",
        283,
        "TPG[%d]  req[%lld] Freeing all the streams",
        *(_DWORD *)a1,
        *a2);
      v2 = *(_QWORD *)(a1 + 32);
    }
    if ( *(_DWORD *)(v2 + 4) )
    {
      v5 = 0;
      do
      {
        v7 = 32LL * v5;
        v8 = v5;
        *(_DWORD *)(a2[11] + v7) = v5;
        *(_QWORD *)(a2[11] + v7 + 4) = 0xFFFFFFFFLL;
        v9 = *(_DWORD *)(a1 + 4);
        v10 = a2[11];
        if ( v9 == 3 )
        {
          v16 = v10 + 32 * v8;
          v17 = *(_QWORD **)(v16 + 16);
          if ( v17 != (_QWORD *)(v16 + 16) )
          {
            do
            {
              v19 = (_QWORD *)*v17;
              v18 = (_QWORD *)v17[1];
              if ( (_QWORD *)*v18 == v17 && (_QWORD *)v19[1] == v17 )
              {
                v19[1] = v18;
                *v18 = v19;
              }
              else
              {
                _list_del_entry_valid_or_report(v17);
              }
              v20 = v17 - 145;
              *v17 = 0xDEAD000000000100LL;
              v17[1] = 0xDEAD000000000122LL;
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v20, 0);
              else
                kvfree(v20);
              v10 = a2[11];
              v17 = v19;
            }
            while ( v19 != (_QWORD *)(v10 + 32 * v8 + 16) );
          }
        }
        else if ( v9 == 1 )
        {
          v11 = v10 + 32 * v8;
          v12 = *(_QWORD **)(v11 + 16);
          if ( v12 != (_QWORD *)(v11 + 16) )
          {
            do
            {
              v14 = (_QWORD *)*v12;
              v13 = (_QWORD *)v12[1];
              if ( (_QWORD *)*v13 == v12 && (_QWORD *)v14[1] == v12 )
              {
                v14[1] = v13;
                *v13 = v14;
              }
              else
              {
                _list_del_entry_valid_or_report(v12);
              }
              v15 = v12 - 14;
              *v12 = 0xDEAD000000000100LL;
              v12[1] = 0xDEAD000000000122LL;
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v15, 0);
              else
                kvfree(v15);
              v10 = a2[11];
              v12 = v14;
            }
            while ( v14 != (_QWORD *)(v10 + 32 * v8 + 16) );
          }
        }
        v6 = v10 + 32 * v8;
        *(_QWORD *)(v6 + 16) = v6 + 16;
        *(_QWORD *)(v6 + 24) = v6 + 16;
        v5 = v8 + 1;
      }
      while ( (unsigned int)(v8 + 1) < *(_DWORD *)(*(_QWORD *)(a1 + 32) + 4LL) );
    }
    v22 = (unsigned __int8)mem_trace_en;
    *(_DWORD *)(a1 + 16) = 0;
    v23 = (_QWORD *)a2[11];
    if ( v22 == 1 )
      cam_mem_trace_free(v23, 0);
    else
      kvfree(v23);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(a2, 0);
    else
      kvfree(a2);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_release_vc_slots_locked",
      278,
      "Invalid Params");
    return 4294967274LL;
  }
}
