__int64 __fastcall dsi_ctrl_host_init(__int64 a1, char a2)
{
  size_t v5; // x0
  __int64 v6; // x8
  __int64 (__fastcall *v7)(__int64, __int64); // x8
  __int64 v8; // x8
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x8
  __int64 (__fastcall *v11)(__int64, __int64, __int64); // x8
  __int64 v12; // x8
  _DWORD *v13; // x8
  int v14; // w5
  unsigned int v15; // w20
  __int64 (__fastcall *v16)(__int64, __int64, __int64); // x8
  __int64 v17; // x8
  __int64 (__fastcall *v18)(__int64, __int64); // x8
  __int64 v19; // x8
  _DWORD *v20; // x8
  __int64 v21; // x8
  void (__fastcall *v22)(__int64, __int64); // x8
  __int64 v23; // x0
  __int64 v24; // x1
  __int64 v25; // x8

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a1 + 1608) == 1 )
    return 0;
  v5 = mutex_lock(a1 + 32);
  if ( *(_DWORD *)(a1 + 1608) == 1 )
  {
LABEL_6:
    if ( (a2 & 1) == 0 )
    {
      v6 = *(unsigned int *)(a1 + 1608);
      if ( (unsigned int)v6 >= 3 )
        goto LABEL_51;
      v7 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 8 * v6 + 456);
      if ( *((_DWORD *)v7 - 1) != -440038337 )
        __break(0x8228u);
      v5 = v7(a1 + 96, a1 + 2744);
      v8 = *(unsigned int *)(a1 + 1608);
      if ( (unsigned int)v8 > 2 )
        goto LABEL_51;
      v9 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 168 + 8 * v8);
      if ( *((_DWORD *)v9 - 1) != -25817620 )
        __break(0x8228u);
      v5 = v9(a1 + 96, a1 + 2444);
      v10 = *(unsigned int *)(a1 + 1608);
      if ( *(_DWORD *)(a1 + 2440) == 2 )
      {
        if ( (unsigned int)v10 > 2 )
          goto LABEL_51;
        v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 8 * v10 + 288);
        if ( *((_DWORD *)v11 - 1) != 1675679774 )
          __break(0x8228u);
        v5 = v11(a1 + 96, a1 + 2444, a1 + 2536);
        v12 = *(unsigned int *)(a1 + 1608);
        if ( (unsigned int)v12 > 2 )
          goto LABEL_51;
        v13 = *(_DWORD **)(a1 + 8 * v12 + 312);
        if ( *(v13 - 1) != 1379136512 )
          __break(0x8228u);
        v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD))v13)(
               a1 + 96,
               a1 + 2592,
               a1 + 2444,
               0,
               0);
      }
      else
      {
        if ( (unsigned int)v10 > 2 )
          goto LABEL_51;
        v16 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 8 * v10 + 240);
        if ( *((_DWORD *)v16 - 1) != 1838921532 )
          __break(0x8228u);
        v5 = v16(a1 + 96, a1 + 2444, a1 + 2536);
        v17 = *(unsigned int *)(a1 + 1608);
        if ( (unsigned int)v17 > 2 )
          goto LABEL_51;
        v18 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 8 * v17 + 264);
        if ( *((_DWORD *)v18 - 1) != -1866437525 )
          __break(0x8228u);
        v5 = v18(a1 + 96, a1 + 2440);
      }
    }
    v19 = *(unsigned int *)(a1 + 1608);
    if ( (unsigned int)v19 <= 2 )
    {
      v20 = *(_DWORD **)(a1 + 8 * v19 + 864);
      if ( *(v20 - 1) != -200804075 )
        __break(0x8228u);
      v5 = ((__int64 (__fastcall *)(__int64, _QWORD))v20)(a1 + 96, 0);
      if ( *(_DWORD *)(a1 + 2440) != 1 || (*(_BYTE *)(a1 + 2542) & 1) != 0 || (*(_BYTE *)(a1 + 2541) & 1) != 0 )
      {
        v21 = *(unsigned int *)(a1 + 1608);
        if ( (unsigned int)v21 <= 2 )
        {
          v22 = *(void (__fastcall **)(__int64, __int64))(a1 + 8 * v21 + 936);
          if ( v22 )
          {
            v23 = a1 + 96;
            v24 = 16711904;
LABEL_42:
            if ( *((_DWORD *)v22 - 1) != 2055766805 )
              __break(0x8228u);
            v22(v23, v24);
            goto LABEL_45;
          }
          goto LABEL_45;
        }
      }
      else
      {
        v25 = *(unsigned int *)(a1 + 1608);
        if ( (unsigned int)v25 <= 2 )
        {
          v22 = *(void (__fastcall **)(__int64, __int64))(a1 + 8 * v25 + 936);
          if ( v22 )
          {
            v23 = a1 + 96;
            v24 = 16711840;
            goto LABEL_42;
          }
LABEL_45:
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dsi-debug]: %s: Host initialization complete, skip op: %d\n",
            *(const char **)(a1 + 16),
            a2 & 1);
          v15 = 0;
          *(_BYTE *)(a1 + 1628) = 1;
          goto LABEL_46;
        }
      }
    }
LABEL_51:
    __break(0x5512u);
    return dsi_ctrl_isr_configure(v5);
  }
  v5 = sde_evtlog_log(
         sde_dbg_base_evtlog,
         "dsi_ctrl_check_state",
         535,
         -1,
         *(unsigned __int8 *)(a1 + 2584),
         *(_DWORD *)(a1 + 8),
         5,
         1,
         239);
  if ( *(_BYTE *)(a1 + 1628) )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: No change in state, host_init=%d\n",
      *(const char **)(a1 + 16),
      1);
  }
  else
  {
    v14 = *(_DWORD *)(a1 + 1612);
    if ( v14 == 1 )
      goto LABEL_6;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: State error: op=%d: %d\n",
      *(const char **)(a1 + 16),
      5,
      v14);
  }
  v15 = -22;
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: %s: Controller state check failed, rc=%d\n",
    *(const char **)(a1 + 16),
    -22);
LABEL_46:
  mutex_unlock(a1 + 32);
  return v15;
}
