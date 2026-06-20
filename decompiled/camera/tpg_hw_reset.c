__int64 __fastcall tpg_hw_reset(_DWORD *a1)
{
  _QWORD *v2; // x22
  _QWORD *v3; // x1
  _QWORD *v4; // x27
  _QWORD *v5; // x8
  _QWORD *v6; // x9
  _QWORD *v7; // x9
  int v8; // w0
  __int64 v9; // x0
  _QWORD *v10; // x22
  _QWORD *v11; // x1
  _QWORD *v12; // x27
  _QWORD *v13; // x8
  _QWORD *v14; // x9
  _QWORD *v15; // x9

  if ( !a1 )
    return 4294967274LL;
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "tpg_hw_reset",
      1226,
      "TPG HW reset");
  mutex_lock(a1 + 12);
  v2 = *((_QWORD **)a1 + 26);
  if ( v2 != (_QWORD *)(a1 + 52) )
  {
    do
    {
      v3 = v2 - 13;
      v4 = (_QWORD *)*v2;
      if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x200000000LL,
          4,
          "tpg_hw_free_waiting_requests_locked",
          330,
          "TPG[%d] freeing waiting_request[%lld] ",
          *a1,
          *v3);
        v3 = v2 - 13;
      }
      v5 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v5 == v2 && (v6 = (_QWORD *)*v2, *(_QWORD **)(*v2 + 8LL) == v2) )
      {
        v6[1] = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
        v3 = v7;
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      --a1[61];
      tpg_hw_release_vc_slots_locked((__int64)a1, v3);
      v2 = v4;
    }
    while ( v4 != (_QWORD *)(a1 + 52) );
  }
  if ( a1[2] )
  {
    v8 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD))cam_soc_util_disable_platform_resource)(
           *((_QWORD *)a1 + 5),
           0xFFFFFFFFLL,
           1,
           0);
    if ( v8 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_reset",
        1239,
        "TPG[%d] Disable platform failed %d",
        *a1,
        v8);
    if ( (unsigned int)cam_cpas_stop(a1[3]) )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_reset",
        1243,
        "TPG[%d] CPAS stop failed",
        *a1);
    v9 = raw_spin_lock_irqsave(a1 + 24);
    a1[2] = 0;
    *((_QWORD *)a1 + 32) = -1;
    raw_spin_unlock_irqrestore(a1 + 24, v9);
  }
  v10 = *((_QWORD **)a1 + 28);
  if ( v10 != (_QWORD *)(a1 + 56) )
  {
    do
    {
      v11 = v10 - 13;
      v12 = (_QWORD *)*v10;
      if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x200000000LL,
          4,
          "tpg_hw_free_active_requests_locked",
          353,
          "TPG[%d] freeing active_request[%lld] ",
          *a1,
          *v11);
        v11 = v10 - 13;
      }
      v13 = (_QWORD *)v10[1];
      if ( (_QWORD *)*v13 == v10 && (v14 = (_QWORD *)*v10, *(_QWORD **)(*v10 + 8LL) == v10) )
      {
        v14[1] = v13;
        *v13 = v14;
      }
      else
      {
        _list_del_entry_valid_or_report(v10);
        v11 = v15;
      }
      *v10 = 0xDEAD000000000100LL;
      v10[1] = 0xDEAD000000000122LL;
      --a1[60];
      tpg_hw_release_vc_slots_locked((__int64)a1, v11);
      v10 = v12;
    }
    while ( v12 != (_QWORD *)(a1 + 56) );
  }
  mutex_unlock(a1 + 12);
  return 0;
}
