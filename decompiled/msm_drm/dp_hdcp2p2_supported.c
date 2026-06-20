__int64 __fastcall dp_hdcp2p2_supported(__int64 a1)
{
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v4; // x19
  __int64 v5; // x0
  int v6; // w2
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int16 v10; // [xsp+4h] [xbp-Ch] BYREF
  unsigned __int8 v11; // [xsp+6h] [xbp-Ah]
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v10 = 0;
  ipc_log_context = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(ipc_log_context, "[d][%-4d]Checking sink capability\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Checking sink capability\n", *(_DWORD *)(StatusReg + 1800));
  v4 = drm_dp_dpcd_read(*(_QWORD *)(a1 + 168), 430621, &v10, 3);
  v5 = get_ipc_log_context(v4);
  v6 = *(_DWORD *)(StatusReg + 1800);
  if ( v4 != 3 )
  {
    ipc_log_string(v5, "[e][%-4d]RxCaps read failed\n", v6);
    printk(&unk_222D50, "dp_hdcp2p2_supported");
LABEL_12:
    result = 0;
    goto LABEL_13;
  }
  v7 = ipc_log_string(v5, "[d][%-4d]HDCP_CAPABLE=%lu\n", v6, ((unsigned __int64)v11 >> 1) & 1);
  if ( (_drm_debug & 4) != 0 )
    v7 = _drm_dev_dbg(
           0,
           0,
           0,
           "[msm-dp-debug][%-4d]HDCP_CAPABLE=%lu\n",
           *(_DWORD *)(StatusReg + 1800),
           ((unsigned __int64)v11 >> 1) & 1);
  v8 = get_ipc_log_context(v7);
  ipc_log_string(v8, "[d][%-4d]VERSION=%d\n", *(_DWORD *)(StatusReg + 1800), (unsigned __int8)v10);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]VERSION=%d\n", *(_DWORD *)(StatusReg + 1800), (unsigned __int8)v10);
  if ( (v11 & 2) == 0 || (unsigned __int8)v10 != 2 )
    goto LABEL_12;
  result = 1;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
