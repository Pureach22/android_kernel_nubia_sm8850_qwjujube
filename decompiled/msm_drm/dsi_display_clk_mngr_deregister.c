__int64 __fastcall dsi_display_clk_mngr_deregister(__int64 a1)
{
  char *v2; // x9
  char **v3; // x8
  char *v4; // x24
  char *v5; // x21
  unsigned int v6; // w20

  if ( a1 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: ENTER\n", (const char *)a1);
    mutex_lock(a1 + 32);
    v2 = *(char **)(a1 + 80);
    if ( v2 != (char *)(a1 + 80) )
    {
      do
      {
        v4 = *(char **)v2;
        v3 = *((char ***)v2 + 1);
        if ( *v3 == v2 && *((char **)v4 + 1) == v2 )
        {
          *((_QWORD *)v4 + 1) = v3;
          *v3 = v4;
        }
        else
        {
          _list_del_entry_valid_or_report(v2);
        }
        v5 = v2 - 64;
        *(_QWORD *)v2 = 0xDEAD000000000100LL;
        *((_QWORD *)v2 + 1) = 0xDEAD000000000122LL;
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Removed device (%s)\n", v2 - 64);
        kfree(v5);
        v2 = v4;
      }
      while ( v4 != (char *)(a1 + 80) );
    }
    v6 = ((__int64 (__fastcall *)(__int64))dsi_recheck_clk_state)(a1);
    if ( v6 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to disable all clocks\n");
    mutex_unlock(a1 + 32);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: EXIT, rc = %d\n", (const char *)a1, v6);
    kfree(a1);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return (unsigned int)-22;
  }
  return v6;
}
