__int64 __fastcall dp_link_adjust_levels(__int64 adjust_request_voltage, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v4; // w21
  int v5; // w23
  unsigned int v6; // w8
  _BYTE *v7; // x22
  unsigned int v8; // w21
  int v9; // w23
  __int64 v10; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v12; // x0
  unsigned int v13; // w8
  unsigned int v14; // w9
  unsigned int v15; // w9
  unsigned int v16; // w10
  char v17; // w8
  __int64 v18; // x0
  __int64 ipc_log_context; // x0

  if ( !adjust_request_voltage )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_link_adjust_levels");
    return 4294967274LL;
  }
  v2 = adjust_request_voltage;
  if ( *(_DWORD *)(adjust_request_voltage + 128) )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      adjust_request_voltage = drm_dp_get_adjust_request_voltage(a2, v4);
      v6 = *(_DWORD *)(v2 + 128);
      ++v4;
      if ( v5 <= (unsigned __int8)adjust_request_voltage )
        v5 = (unsigned __int8)adjust_request_voltage;
    }
    while ( v4 < v6 );
    *(_BYTE *)(v2 + 124) = v5;
    v7 = (_BYTE *)(v2 + 124);
    if ( v6 )
    {
      v8 = 0;
      v9 = 0;
      do
      {
        adjust_request_voltage = drm_dp_get_adjust_request_pre_emphasis(a2, v8++);
        if ( v9 <= (unsigned __int8)adjust_request_voltage >> 3 )
          v9 = (unsigned __int8)adjust_request_voltage >> 3;
      }
      while ( v8 < *(_DWORD *)(v2 + 128) );
    }
    else
    {
      LOBYTE(v9) = 0;
    }
  }
  else
  {
    LOBYTE(v9) = 0;
    *(_BYTE *)(adjust_request_voltage + 124) = 0;
    v7 = (_BYTE *)(adjust_request_voltage + 124);
  }
  *(_BYTE *)(v2 + 125) = v9;
  v10 = get_ipc_log_context(adjust_request_voltage);
  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = ipc_log_string(
          v10,
          "[d][%-4d]Current (VxPx): 0x%x, 0x%x\n",
          *(_DWORD *)(StatusReg + 1800),
          *(unsigned __int8 *)(v2 + 124),
          *(unsigned __int8 *)(v2 + 125));
  if ( (_drm_debug & 4) != 0 )
    v12 = _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]Current (VxPx): 0x%x, 0x%x\n",
            *(_DWORD *)(StatusReg + 1800),
            *(unsigned __int8 *)(v2 + 124),
            *(unsigned __int8 *)(v2 + 125));
  v13 = *(unsigned __int8 *)(v2 + 124);
  v14 = *(unsigned __int8 *)(v2 + 126);
  if ( v13 > v14 )
  {
    v13 = *(unsigned __int8 *)(v2 + 126);
    *v7 = v14;
  }
  v15 = *(unsigned __int8 *)(v2 + 125);
  v16 = *(unsigned __int8 *)(v2 + 127);
  if ( v15 > v16 )
  {
    v15 = *(unsigned __int8 *)(v2 + 127);
    *(_BYTE *)(v2 + 125) = v16;
  }
  if ( v15 >= 2 )
  {
    if ( v13 == 2 )
    {
      v17 = 1;
LABEL_27:
      *(_BYTE *)(v2 + 125) = v17;
      goto LABEL_28;
    }
    if ( v15 != 2 && v13 == 1 )
    {
      v17 = 2;
      goto LABEL_27;
    }
  }
LABEL_28:
  v18 = get_ipc_log_context(v12);
  ipc_log_string(
    v18,
    "[d][%-4d]Set (VxPx): 0x%x, 0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(unsigned __int8 *)(v2 + 124),
    *(unsigned __int8 *)(v2 + 125));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]Set (VxPx): 0x%x, 0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(unsigned __int8 *)(v2 + 124),
      *(unsigned __int8 *)(v2 + 125));
  return 0;
}
