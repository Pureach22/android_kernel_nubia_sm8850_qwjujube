__int64 __fastcall dp_ctrl_update_sink_vx_px(unsigned __int8 **a1)
{
  unsigned __int8 **v1; // x19
  int v2; // w25
  unsigned __int8 *v3; // x8
  unsigned int v4; // w24
  int v5; // w21
  int v6; // w22
  size_t v7; // x20
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v10; // x0
  unsigned __int64 v11; // x26
  int v12; // w22
  __int64 v13; // x0
  unsigned __int64 v14; // x24
  int v15; // w0
  int s; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v1 = a1;
  v2 = 0;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[19];
  s = 0;
  v4 = v3[128];
  v5 = v3[124];
  v6 = v3[125];
  if ( v4 >= 4 )
    v7 = 4;
  else
    v7 = v3[128];
  if ( v5 == v3[126] )
  {
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    a1 = (unsigned __int8 **)ipc_log_string(
                               ipc_log_context,
                               "[d][%-4d]max voltage swing level reached %d\n",
                               *(_DWORD *)(StatusReg + 1800),
                               v5);
    if ( (_drm_debug & 4) != 0 )
      a1 = (unsigned __int8 **)_drm_dev_dbg(
                                 0,
                                 0,
                                 0,
                                 "[msm-dp-debug][%-4d]max voltage swing level reached %d\n",
                                 *(_DWORD *)(StatusReg + 1800),
                                 v5);
    v2 = 4;
  }
  if ( v6 == v1[19][127] )
  {
    v10 = get_ipc_log_context(a1);
    v11 = _ReadStatusReg(SP_EL0);
    a1 = (unsigned __int8 **)ipc_log_string(
                               v10,
                               "[d][%-4d]max pre-emphasis level reached %d\n",
                               *(_DWORD *)(v11 + 1800),
                               v6);
    if ( (_drm_debug & 4) != 0 )
      a1 = (unsigned __int8 **)_drm_dev_dbg(
                                 0,
                                 0,
                                 0,
                                 "[msm-dp-debug][%-4d]max pre-emphasis level reached %d\n",
                                 *(_DWORD *)(v11 + 1800),
                                 v6);
    v2 |= 0x20u;
  }
  v12 = 8 * v6;
  if ( v4 )
    a1 = (unsigned __int8 **)memset(&s, v5 | v2 | (unsigned int)v12, v7);
  v13 = get_ipc_log_context(a1);
  v14 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v13,
    "[d][%-4d]lanes: %d, swing: 0x%x, pre-emp: 0x%x\n",
    *(_DWORD *)(v14 + 1800),
    v7,
    v5,
    (unsigned __int8)v12);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]lanes: %d, swing: 0x%x, pre-emp: 0x%x\n",
      *(_DWORD *)(v14 + 1800),
      v7,
      v5,
      (unsigned __int8)v12);
  v15 = drm_dp_dpcd_write(*((_QWORD *)v1[17] + 3), 259, &s, v7);
  _ReadStatusReg(SP_EL0);
  if ( v15 <= 0 )
    return 4294967274LL;
  else
    return 0;
}
