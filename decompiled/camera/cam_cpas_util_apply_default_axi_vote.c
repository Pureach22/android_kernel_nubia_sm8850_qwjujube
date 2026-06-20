__int64 __fastcall cam_cpas_util_apply_default_axi_vote(__int64 a1, char a2)
{
  __int64 v2; // x19
  __int64 v5; // x0
  unsigned __int64 v6; // x8
  __int64 v7; // x24
  unsigned __int64 v8; // x25
  __int64 v9; // x21
  __int64 v10; // x28
  unsigned int v11; // w20

  v2 = *(_QWORD *)(a1 + 3680);
  v5 = mutex_lock(v2 + 2728);
  v6 = *(unsigned int *)(v2 + 2780);
  if ( (_DWORD)v6 )
  {
    v7 = 0;
    v8 = 0;
    if ( (a2 & 1) != 0 )
      v9 = 1024;
    else
      v9 = 0;
    while ( v8 != 6 )
    {
      v10 = v2 + v7;
      if ( (*(_BYTE *)(v2 + v7 + 3184) & 1) == 0 && (!*(_QWORD *)(v10 + 3392) || !*(_QWORD *)(v2 + v7 + 3400)) )
      {
        if ( (debug_mdl & 4) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_util_apply_default_axi_vote",
            2464,
            "Port=[%s] :ab[%llu] ib[%llu]",
            *(const char **)(v10 + 3096),
            0,
            v9);
        *(_QWORD *)(v10 + 3392) = 0;
        *(_QWORD *)(v2 + v7 + 3400) = v9;
        v5 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD, __int64, __int64))cam_cpas_util_vote_hlos_bus_client_bw)(
               *(_QWORD *)(a1 + 3392),
               v2,
               v10 + 3104,
               0,
               v10 + 3384,
               v2 + v7 + 3448);
        if ( (_DWORD)v5 )
        {
          v11 = v5;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_util_apply_default_axi_vote",
            2472,
            "Failed in mnoc vote ab[%llu] ib[%llu] rc=%d",
            0,
            v9,
            v5);
          goto LABEL_16;
        }
        v6 = *(unsigned int *)(v2 + 2780);
      }
      ++v8;
      v7 += 408;
      if ( v8 >= v6 )
        goto LABEL_15;
    }
    __break(0x5512u);
    return cam_cpas_reset_niu_priorities(v5);
  }
  else
  {
LABEL_15:
    v11 = 0;
LABEL_16:
    mutex_unlock(v2 + 2728);
    return v11;
  }
}
