__int64 __fastcall dsi_deregister_clk_handle(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w20
  _QWORD *v4; // x8
  _QWORD *v5; // x9
  const char *v6; // x21
  _QWORD *v7; // x10

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 80);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: ENTER\n", (const char *)v1);
    mutex_lock(v1 + 32);
    *(_QWORD *)(a1 + 48) = 0;
    v3 = ((__int64 (__fastcall *)(__int64))dsi_recheck_clk_state)(v1);
    if ( v3 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: clock state recheck failed rc = %d\n", v3);
    }
    else
    {
      v4 = *(_QWORD **)(v1 + 80);
      while ( v4 != (_QWORD *)(v1 + 80) )
      {
        v5 = v4;
        v6 = (const char *)(v4 - 8);
        v4 = (_QWORD *)*v4;
        if ( v6 == (const char *)a1 )
        {
          v7 = (_QWORD *)v5[1];
          if ( (_QWORD *)*v7 == v5 && (_QWORD *)v4[1] == v5 )
          {
            v4[1] = v7;
            *v7 = v4;
          }
          else
          {
            _list_del_entry_valid_or_report(v5);
          }
          *v5 = 0xDEAD000000000100LL;
          v5[1] = 0xDEAD000000000122LL;
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Removed device (%s)\n", v6);
          kfree(v6);
          break;
        }
      }
    }
    mutex_unlock(v1 + 32);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: EXIT, rc = %d\n", (const char *)v1, v3);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return (unsigned int)-22;
  }
  return v3;
}
