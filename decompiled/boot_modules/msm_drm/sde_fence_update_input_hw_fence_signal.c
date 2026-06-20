__int64 __fastcall sde_fence_update_input_hw_fence_signal(unsigned int *a1, char a2, __int64 a3, char a4, char a5)
{
  unsigned int v5; // w8
  __int64 v6; // x8
  unsigned int *v7; // x22
  unsigned int v8; // w21
  unsigned int *v9; // x23
  void (*v10)(void); // x9
  void (*v11)(void); // x8
  __int64 v12; // x8
  _DWORD *v13; // x8
  unsigned int *v14; // x19
  int v15; // w21
  int v16; // w19
  int v17; // w20
  unsigned int *v18; // x24
  __int64 v19; // x8
  __int64 (*v20)(void); // x8
  unsigned int *v21; // x22
  __int64 v22; // x0
  __int64 v23; // x8
  _DWORD *v24; // x8
  __int64 (__fastcall *v25)(__int64); // x8
  __int64 v26; // x0

  v5 = -22;
  if ( !a1 || !a3 )
    return v5;
  v6 = a1[7];
  if ( (unsigned int)v6 >= 3 )
    goto LABEL_39;
  v7 = a1 + 136;
  if ( *(_QWORD *)&a1[2 * v6 + 136] && *(_QWORD *)&a1[2 * v6 + 88] )
  {
    v8 = a1[16];
    v9 = a1 + 76;
    if ( (a4 & 1) != 0 )
    {
      v10 = *(void (**)(void))&v9[2 * v6];
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != -1975722870 )
          __break(0x8229u);
        v10();
        return (unsigned int)-1;
      }
    }
    if ( (a5 & 1) != 0 )
    {
      v11 = *(void (**)(void))&v9[2 * v6];
      if ( v11 )
      {
        if ( *((_DWORD *)v11 - 1) != -1975722870 )
          __break(0x8228u);
        v11();
        return (unsigned int)-1;
      }
    }
    if ( (a2 & 1) != 0 )
    {
      v12 = *(unsigned int *)(a3 + 28);
      if ( (unsigned int)v12 > 2 )
        goto LABEL_39;
      v13 = *(_DWORD **)(a3 + 8 * v12 + 416);
      if ( v13 )
      {
        v14 = a1;
        if ( *(v13 - 1) != 1066508607 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v13)(a3, 1, 0);
        a1 = v14;
      }
    }
    v15 = v8 - 1;
    v17 = a1[60];
    v16 = a1[61];
    if ( (_drm_debug & 4) != 0 )
    {
      v18 = a1;
      _drm_dev_dbg(0, 0, 0, "configure input signal:%d out client:%d ctl_id:%d\n", v16, v17, v15);
      a1 = v18;
    }
    v19 = a1[7];
    if ( (unsigned int)v19 <= 2 )
    {
      v20 = *(__int64 (**)(void))&v7[2 * v19];
      v21 = a1;
      if ( *((_DWORD *)v20 - 1) != -1400796485 )
        __break(0x8228u);
      v22 = v20();
      v23 = v21[7];
      if ( (unsigned int)v23 <= 2 )
      {
        v24 = *(_DWORD **)&v9[2 * v23];
        if ( v24 )
        {
          if ( *(v24 - 1) != -1975722870 )
            __break(0x8228u);
          v22 = ((__int64 (__fastcall *)(unsigned int *, __int64, __int64, __int64, _QWORD, _QWORD))v24)(
                  v21,
                  1,
                  1,
                  1,
                  0,
                  0);
        }
        v25 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
        if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
          __break(0x8228u);
        v26 = v25(v22);
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_fence_update_input_hw_fence_signal",
          828,
          -1,
          v15,
          v16,
          v17,
          SHIDWORD(v26),
          v26);
        return 0;
      }
    }
LABEL_39:
    __break(0x5512u);
    JUMPOUT(0xF0544);
  }
  if ( !(_DWORD)v6 )
    printk(&unk_216E02, "sde_fence_update_input_hw_fence_signal");
  return (unsigned int)-22;
}
