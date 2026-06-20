__int64 __fastcall dsi_ctrl_check_state(__int64 a1, int a2, unsigned int a3)
{
  __int64 result; // x0
  int v5; // w22
  int v8; // w5
  int v9; // w6
  int v10; // w8
  int v11; // w5
  int v12; // w6
  int v13; // w5
  int v14; // w5
  int v15; // w5
  int v16; // w5
  int v17; // w6
  int v18; // w5
  int v19; // w6

  if ( *(_DWORD *)(a1 + 1608) == 1 )
    return 0;
  v5 = *(unsigned __int8 *)(a1 + 2584);
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_ctrl_check_state", 535, -1, v5, *(_DWORD *)(a1 + 8), a2, a3, 239);
  result = 4294966772LL;
  if ( a2 > 3 )
  {
    if ( a2 <= 5 )
    {
      if ( a2 == 4 )
      {
        v11 = *(_DWORD *)(a1 + 1612);
        v12 = *(unsigned __int8 *)(a1 + 1628);
        if ( v11 != 1 || (v12 & 1) == 0 || *(_DWORD *)(a1 + 1616) != 1 )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: %s: State error: op=%d: %d, %d, %d\n",
            *(const char **)(a1 + 16),
            4,
            v11,
            v12,
            *(_DWORD *)(a1 + 1616));
          return 4294967274LL;
        }
      }
      else
      {
        if ( *(unsigned __int8 *)(a1 + 1628) == a3 )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: %s: No change in state, host_init=%d\n",
            *(_QWORD *)(a1 + 16),
            a3);
          return 4294967274LL;
        }
        v15 = *(_DWORD *)(a1 + 1612);
        if ( v15 != 1 )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: %s: State error: op=%d: %d\n",
            *(const char **)(a1 + 16),
            5,
            v15);
          return 4294967274LL;
        }
      }
    }
    else
    {
      switch ( a2 )
      {
        case 6:
          if ( *(unsigned __int8 *)(a1 + 1629) == a3 )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: %s: No change in state, tpg_enabled=%d\n",
              *(_QWORD *)(a1 + 16),
              a3);
            return 4294967274LL;
          }
          v18 = *(_DWORD *)(a1 + 1612);
          v19 = *(_DWORD *)(a1 + 1624);
          if ( v18 != 1 || v19 != 1 )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: %s: State error: op=%d: %d, %d\n",
              *(const char **)(a1 + 16),
              6,
              v18,
              v19);
            return 4294967274LL;
          }
          break;
        case 7:
          v13 = *(_DWORD *)(a1 + 1612);
          if ( v13 != 1 )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: %s: State error: op=%d: %d\n",
              *(const char **)(a1 + 16),
              7,
              v13);
            return 4294967274LL;
          }
          break;
        case 8:
          if ( *(_DWORD *)(a1 + 1620) != a3 )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: %s: Unexpected engine state vid_state=%d\n",
              *(_QWORD *)(a1 + 16),
              a3);
            return 4294967274LL;
          }
          break;
        default:
          return result;
      }
    }
    return 0;
  }
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      if ( *(_DWORD *)(a1 + 1620) == a3 )
        goto LABEL_26;
      if ( (v5 & 1) == 0 )
      {
        v16 = *(_DWORD *)(a1 + 1612);
        v17 = *(_DWORD *)(a1 + 1624);
        if ( v16 != 1 || v17 != 1 )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: %s: State error: op=%d: %d, %d\n",
            *(const char **)(a1 + 16),
            2,
            v16,
            v17);
          return 4294967274LL;
        }
      }
    }
    else
    {
      if ( *(_DWORD *)(a1 + 1624) == a3 )
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: No change in state, ctrl_state=%d\n",
          *(_QWORD *)(a1 + 16),
          a3);
        return 4294967274LL;
      }
      v14 = *(_DWORD *)(a1 + 1612);
      if ( v14 != 1 )
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: State error (link is off): op=%d:, %d\n",
          *(const char **)(a1 + 16),
          a3,
          v14);
        return 4294967274LL;
      }
      if ( !a3 && *(_QWORD *)(a1 + 1616) )
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: State error (eng on): op=%d: %d, %d\n",
          *(const char **)(a1 + 16),
          0,
          *(_DWORD *)(a1 + 1616),
          *(_DWORD *)(a1 + 1620));
        return 4294967274LL;
      }
    }
    return 0;
  }
  if ( a2 )
  {
    if ( a2 != 1 )
      return result;
    if ( *(_DWORD *)(a1 + 1616) != a3 )
    {
      v8 = *(_DWORD *)(a1 + 1612);
      v9 = *(_DWORD *)(a1 + 1624);
      if ( v8 != 1 || v9 != 1 )
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: State error: op=%d: %d, %d\n",
          *(const char **)(a1 + 16),
          1,
          v8,
          v9);
        return 4294967274LL;
      }
      return 0;
    }
LABEL_26:
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: No change in state, cmd_state=%d\n",
      *(_QWORD *)(a1 + 16),
      a3);
    return 4294967274LL;
  }
  v10 = *(_DWORD *)(a1 + 1612);
  if ( v10 == a3 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: No change in state, pwr_state=%d\n",
      *(_QWORD *)(a1 + 16),
      a3);
    return 4294967274LL;
  }
  if ( v10 != 1 )
    return 0;
  result = 0;
  if ( *(_DWORD *)(a1 + 1620) == 1 && (v5 & 1) == 0 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: State error: op=%d: %d\n",
      *(const char **)(a1 + 16),
      a3,
      1);
    return 4294967274LL;
  }
  return result;
}
