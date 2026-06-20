__int64 __fastcall ipa3_set_clock_plan_from_pm(int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x10
  int v5; // w20
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  _DWORD *v10; // x9
  int v11; // w10
  unsigned int v12; // w19
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d idx = %d\n", "ipa3_set_clock_plan_from_pm", 7250, a1);
      v2 = ipa3_ctx;
    }
  }
  if ( !*(_DWORD *)(v2 + 34236) )
  {
    *(_DWORD *)(v2 + 30556) = a1;
    return 0;
  }
  if ( (*(_DWORD *)(v2 + 32248) | 4) != 4 )
  {
    printk(&unk_3E5924, "ipa3_set_clock_plan_from_pm");
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d not supported in this mode\n", "ipa3_set_clock_plan_from_pm", 7258);
        v21 = ipa3_ctx;
      }
      result = *(_QWORD *)(v21 + 34160);
      if ( !result )
        return result;
      ipc_log_string(result, "ipa %s:%d not supported in this mode\n", "ipa3_set_clock_plan_from_pm", 7258);
    }
    return 0;
  }
  if ( (unsigned int)(a1 - 5) > 0xFFFFFFFB )
  {
    v4 = 8;
    if ( (unsigned int)(a1 - 1) < 3 )
      v4 = 20 - 4LL * (unsigned int)(a1 - 1);
    v5 = *(_DWORD *)(*(_QWORD *)(v2 + 34176) + v4);
    if ( v5 == *(_DWORD *)(v2 + 34244) )
    {
      if ( v2 )
      {
        result = *(_QWORD *)(v2 + 34160);
        if ( !result )
          return result;
        ipc_log_string(result, "ipa %s:%d Same voltage\n", "ipa3_set_clock_plan_from_pm", 7282);
      }
      return 0;
    }
    mutex_lock(v2 + 30504);
    v7 = ipa3_ctx;
    *(_DWORD *)(ipa3_ctx + 34244) = v5;
    *(_DWORD *)(v7 + 30556) = a1;
    if ( v7 )
    {
      v8 = *(_QWORD *)(v7 + 34160);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d setting clock rate to %u\n", "ipa3_set_clock_plan_from_pm", 7289, v5);
        v7 = ipa3_ctx;
      }
      if ( *(int *)(v7 + 30552) <= 0 )
      {
        if ( v7 )
        {
          v9 = *(_QWORD *)(v7 + 34160);
          if ( v9 )
          {
            ipc_log_string(v9, "ipa %s:%d clocks are gated, not setting rate\n", "ipa3_set_clock_plan_from_pm", 7305);
            v7 = ipa3_ctx;
          }
        }
        goto LABEL_58;
      }
    }
    else
    {
      v7 = 0;
      if ( dword_7758 < 1 )
        goto LABEL_58;
    }
    if ( ipa3_clk )
    {
      clk_set_rate(ipa3_clk, *(unsigned int *)(v7 + 34244));
      v7 = ipa3_ctx;
    }
    v10 = *(_DWORD **)(v7 + 34176);
    v11 = *(_DWORD *)(v7 + 34244);
    if ( v11 == v10[5] )
      goto LABEL_25;
    if ( v11 == v10[4] )
    {
      v12 = 2;
    }
    else if ( v11 == v10[3] )
    {
      v12 = 3;
    }
    else
    {
      if ( v11 != v10[2] )
      {
        _warn_printk("unexpected clock rate");
        __break(0x800u);
        v7 = ipa3_ctx;
LABEL_25:
        v12 = 1;
        goto LABEL_38;
      }
      v12 = 4;
    }
LABEL_38:
    if ( v7 )
    {
      v16 = *(_QWORD *)(v7 + 34160);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d curr %d idx %d\n", "ipa3_get_bus_vote", 6712, *(_DWORD *)(v7 + 34244), v12);
        v7 = ipa3_ctx;
      }
    }
    if ( *(_DWORD *)(v7 + 48564) )
    {
      v17 = *(_QWORD *)(*(_QWORD *)(v7 + 34176) + 152LL);
      if ( v17
        && (unsigned int)icc_set_bw(
                           v17,
                           *(unsigned int *)(v7 + 32LL * v12 + 48568),
                           *(unsigned int *)(v7 + 32LL * v12 + 48572)) )
      {
        _warn_printk("path %d bus scaling failed", 0);
        __break(0x800u);
      }
      v7 = ipa3_ctx;
      if ( *(_DWORD *)(ipa3_ctx + 48564) >= 2u )
      {
        v18 = *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 160LL);
        if ( v18
          && (unsigned int)icc_set_bw(
                             v18,
                             *(unsigned int *)(ipa3_ctx + 32LL * v12 + 48576),
                             *(unsigned int *)(ipa3_ctx + 32LL * v12 + 48580)) )
        {
          _warn_printk("path %d bus scaling failed", 1);
          __break(0x800u);
        }
        v7 = ipa3_ctx;
        if ( *(_DWORD *)(ipa3_ctx + 48564) >= 3u )
        {
          v19 = *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 168LL);
          if ( v19
            && (unsigned int)icc_set_bw(
                               v19,
                               *(unsigned int *)(ipa3_ctx + 32LL * v12 + 48584),
                               *(unsigned int *)(ipa3_ctx + 32LL * v12 + 48588)) )
          {
            _warn_printk("path %d bus scaling failed", 2);
            __break(0x800u);
          }
          v7 = ipa3_ctx;
          if ( *(_DWORD *)(ipa3_ctx + 48564) >= 4u )
          {
            v20 = *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 176LL);
            if ( v20
              && (unsigned int)icc_set_bw(
                                 v20,
                                 *(unsigned int *)(ipa3_ctx + 32LL * v12 + 48592),
                                 *(unsigned int *)(ipa3_ctx + 32LL * v12 + 48596)) )
            {
              _warn_printk("path %d bus scaling failed", 3);
              __break(0x800u);
            }
            v7 = ipa3_ctx;
            if ( *(_DWORD *)(ipa3_ctx + 48564) > 4u )
            {
              __break(0x5512u);
              JUMPOUT(0x70270);
            }
          }
        }
      }
    }
LABEL_58:
    mutex_unlock(v7 + 30504);
    if ( ipa3_ctx )
    {
      result = *(_QWORD *)(ipa3_ctx + 34160);
      if ( !result )
        return result;
      ipc_log_string(result, "ipa %s:%d Done\n", "ipa3_set_clock_plan_from_pm", 7308);
    }
    return 0;
  }
  printk(&unk_3F1636, "ipa3_set_clock_plan_from_pm");
  v13 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v14 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v14 )
    {
      ipc_log_string(v14, "ipa %s:%d bad voltage\n", "ipa3_set_clock_plan_from_pm", 7263);
      v13 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v13 + 34160);
    if ( v15 )
      ipc_log_string(v15, "ipa %s:%d bad voltage\n", "ipa3_set_clock_plan_from_pm", 7263);
  }
  return 4294967274LL;
}
