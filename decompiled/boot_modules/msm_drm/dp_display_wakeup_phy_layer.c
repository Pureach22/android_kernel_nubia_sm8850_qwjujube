__int64 __fastcall dp_display_wakeup_phy_layer(__int64 a1)
{
  __int64 result; // x0
  __int64 (*v2)(void); // x8
  __int64 v3; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x0

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 665) & 1) != 0 )
    {
      result = *(_QWORD *)(a1 - 1040);
      if ( result )
      {
        v2 = *(__int64 (**)(void))(result + 64);
        if ( v2 )
        {
          if ( *((_DWORD *)v2 - 1) != -1860722790 )
            __break(0x8228u);
          return v2();
        }
      }
    }
    else
    {
      if ( !g_dp_display || (v3 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v3 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      result = ipc_log_string(v3, "[d][%-4d]drm mst not registered\n", *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]drm mst not registered\n", *(_DWORD *)(StatusReg + 1800));
    }
  }
  else
  {
    if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v5 = 0;
    ipc_log_string(v5, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_display_wakeup_phy_layer");
  }
  return result;
}
