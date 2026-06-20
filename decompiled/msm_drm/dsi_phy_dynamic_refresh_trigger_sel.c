__int64 __fastcall dsi_phy_dynamic_refresh_trigger_sel(__int64 result, char a2)
{
  __int64 v2; // x19
  int v4; // w7
  __int64 v5; // x8
  _DWORD *v6; // x8
  int v7; // w5
  size_t v8; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    v2 = result;
    mutex_lock(result + 32);
    v5 = *(unsigned int *)(v2 + 776);
    if ( (unsigned int)v5 >= 3 )
    {
      __break(0x5512u);
      JUMPOUT(0x1B9E7C);
    }
    v6 = *(_DWORD **)(v2 + 8 * v5 + 632);
    if ( v6 )
    {
      if ( *(v6 - 1) != -928920875 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v6)(v2 + 88, a2 & 1);
    }
    v7 = *(_DWORD *)(v2 + 8);
    v8 = sde_dbg_base_evtlog;
    *(_BYTE *)(v2 + 1361) = 1;
    sde_evtlog_log(v8, "dsi_phy_dynamic_refresh_trigger_sel", 1420, -1, a2 & 1, v7, -1059143953, v4, vars0);
    return mutex_unlock(v2 + 32);
  }
  return result;
}
