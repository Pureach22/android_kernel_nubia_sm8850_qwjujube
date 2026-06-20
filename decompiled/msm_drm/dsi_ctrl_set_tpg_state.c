__int64 __fastcall dsi_ctrl_set_tpg_state(__int64 a1, char a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  unsigned int v6; // w20
  __int64 v11; // x2
  __int64 v12; // x8
  _DWORD *v13; // x8
  _DWORD *v14; // x8
  __int64 v15; // x8
  __int64 v16; // x3
  _DWORD *v17; // x8

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
    return (unsigned int)-22;
  }
  if ( *(_DWORD *)(a1 + 1608) != 1 )
  {
    mutex_lock(a1 + 32);
    v6 = dsi_ctrl_check_state(a1, 6, a2 & 1);
    if ( v6 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: Controller state check failed, rc=%d\n",
        *(const char **)(a1 + 16),
        v6);
LABEL_22:
      mutex_unlock(a1 + 32);
      return v6;
    }
    v11 = a5;
    if ( (a2 & 1) != 0 )
    {
      v12 = *(unsigned int *)(a1 + 1608);
      if ( *(_DWORD *)(a1 + 2440) == 1 )
      {
        if ( (unsigned int)v12 >= 3 )
          goto LABEL_24;
        v13 = *(_DWORD **)(a1 + 8 * v12 + 960);
        if ( *(v13 - 1) != -1464578707 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD))v13)(a1 + 96, a3, a4);
      }
      else
      {
        if ( (unsigned int)v12 > 2 )
          goto LABEL_24;
        v14 = *(_DWORD **)(a1 + 8 * v12 + 984);
        if ( *(v14 - 1) != -1211731344 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v14)(a1 + 96, a3, a4, 0);
      }
      v11 = a5;
    }
    v15 = *(unsigned int *)(a1 + 1608);
    if ( (unsigned int)v15 <= 2 )
    {
      v16 = *(unsigned int *)(a1 + 2440);
      v17 = *(_DWORD **)(a1 + 8 * v15 + 1008);
      if ( *(v17 - 1) != -1173348757 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v17)(a1 + 96, a2 & 1, v11, v16);
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: Set test pattern state=%d\n", *(const char **)(a1 + 16), a2 & 1);
      *(_BYTE *)(a1 + 1629) = a2 & 1;
      goto LABEL_22;
    }
LABEL_24:
    __break(0x5512u);
    JUMPOUT(0x1D5ECC);
  }
  return 0;
}
