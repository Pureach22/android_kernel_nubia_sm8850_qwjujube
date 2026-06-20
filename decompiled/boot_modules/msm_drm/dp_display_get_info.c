__int64 __fastcall dp_display_get_info(_DWORD *a1, _DWORD *a2)
{
  unsigned int v2; // w8
  __int64 v3; // x0
  unsigned __int64 StatusReg; // x19

  if ( !a1 )
  {
    if ( !g_dp_display || (v3 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v3 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v3, "[d][%-4d]dp display not initialized\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]dp display not initialized\n", *(_DWORD *)(StatusReg + 1800));
    return (unsigned int)-22;
  }
  *a2 = a1[830];
  a2[1] = a1[831];
  if ( a1[834] < 2u || (a2[2] = a1[832], a1[834] < 3u) )
  {
    v2 = 0;
    a2[3] = a1[833];
    a2[4] = a1[834];
    return v2;
  }
  __break(0x5512u);
  return dp_display_host_unready(a1);
}
