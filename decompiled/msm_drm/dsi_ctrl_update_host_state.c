__int64 __fastcall dsi_ctrl_update_host_state(__int64 a1, int a2, char a3)
{
  unsigned int v4; // w20
  unsigned int v7; // w21

  if ( a1 && *(_DWORD *)(a1 + 1608) != 1 )
  {
    v7 = a3 & 1;
    mutex_lock(a1 + 32);
    v4 = dsi_ctrl_check_state(a1, a2, v7);
    if ( v4 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: Controller state check failed, rc=%d\n",
        *(const char **)(a1 + 16),
        v4);
    }
    else if ( a2 > 2 )
    {
      switch ( a2 )
      {
        case 3:
          v4 = 0;
          *(_DWORD *)(a1 + 1624) = v7;
          break;
        case 5:
          v4 = 0;
          *(_BYTE *)(a1 + 1628) = a3 & 1;
          break;
        case 6:
          v4 = 0;
          *(_BYTE *)(a1 + 1629) = a3 & 1;
          break;
      }
    }
    else if ( a2 )
    {
      if ( a2 == 1 )
      {
        v4 = 0;
        *(_DWORD *)(a1 + 1616) = v7;
      }
      else if ( a2 == 2 )
      {
        v4 = 0;
        *(_DWORD *)(a1 + 1620) = v7;
      }
    }
    else
    {
      v4 = 0;
      *(_DWORD *)(a1 + 1612) = v7;
    }
    mutex_unlock(a1 + 32);
  }
  else
  {
    return 0;
  }
  return v4;
}
