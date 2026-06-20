__int64 **__fastcall dp_rtpm_tput_policy_apply(__int64 a1, unsigned int a2)
{
  __int64 **result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  void (*v14)(void); // x8
  __int64 v15; // x8
  void (*v16)(void); // x8
  unsigned __int64 v23; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v29; // x10
  unsigned __int64 v32; // x9

  result = (__int64 **)_cds_get_context(71, "dp_rtpm_tput_policy_apply");
  if ( !result )
    return result;
  if ( a2 < 3 )
  {
    _X9 = (unsigned __int64 *)(a1 + 1120);
    __asm { PRFM            #0x11, [X9] }
    do
      v26 = __ldxr(_X9);
    while ( __stlxr(v26 & 0xFFFFFFFFFFFFFFFELL, _X9) );
    __dmb(0xBu);
    if ( (v26 & 1) != 0 )
    {
      if ( *result )
      {
        v15 = **result;
        if ( v15 )
        {
          v16 = *(void (**)(void))(v15 + 888);
          if ( v16 )
          {
            if ( *((_DWORD *)v16 - 1) != -251540498 )
              __break(0x8228u);
            v16();
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "cdp_set_rtpm_tput_policy_requirement");
      }
      result = (__int64 **)qdf_runtime_pm_allow_suspend((__int64 *)(a1 + 1112));
    }
  }
  else
  {
    _X9 = (unsigned __int64 *)(a1 + 1120);
    __asm { PRFM            #0x11, [X9] }
    do
      v23 = __ldxr(_X9);
    while ( __stlxr(v23 | 1, _X9) );
    __dmb(0xBu);
    if ( (v23 & 1) == 0 )
    {
      if ( *result )
      {
        v13 = **result;
        if ( v13 )
        {
          v14 = *(void (**)(void))(v13 + 888);
          if ( v14 )
          {
            if ( *((_DWORD *)v14 - 1) != -251540498 )
              __break(0x8228u);
            v14();
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "cdp_set_rtpm_tput_policy_requirement");
      }
      result = (__int64 **)qdf_runtime_pm_prevent_suspend((__int64 *)(a1 + 1112));
    }
    if ( a2 != 3 )
    {
      if ( (*(_QWORD *)(a1 + 1120) & 2) == 0 )
      {
        _X8 = (unsigned __int64 *)(a1 + 1120);
        __asm { PRFM            #0x11, [X8] }
        do
          v32 = __ldxr(_X8);
        while ( __stxr(v32 | 2, _X8) );
      }
      return result;
    }
  }
  if ( (*(_QWORD *)(a1 + 1120) & 2) != 0 )
  {
    _X8 = (unsigned __int64 *)(a1 + 1120);
    __asm { PRFM            #0x11, [X8] }
    do
      v29 = __ldxr(_X8);
    while ( __stxr(v29 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  }
  return result;
}
