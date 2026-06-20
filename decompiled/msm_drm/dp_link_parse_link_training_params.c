__int64 __fastcall dp_link_parse_link_training_params(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  int v4; // w20
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v7; // x0
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  _BYTE v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 16);
  v16[0] = 0;
  v3 = drm_dp_dpcd_read(*(_QWORD *)(v2 + 24), 537, v16, 1);
  if ( (int)v3 <= 0 )
  {
    ipc_log_context = get_ipc_log_context(v3);
    ipc_log_string(ipc_log_context, "[e][%-4d]failed to read link rate\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v12 = &unk_22D1F2;
LABEL_15:
    printk(v12, "dp_link_parse_link_training_params");
    result = 4294967274LL;
    goto LABEL_12;
  }
  v4 = v16[0];
  if ( v16[0] > 0x1Eu || ((1 << v16[0]) & 0x40100440) == 0 )
  {
    v15 = get_ipc_log_context(v3);
    ipc_log_string(v15, "[e][%-4d]invalid link rate = 0x%x\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v4);
    v12 = &unk_241A6B;
    goto LABEL_15;
  }
  *(_DWORD *)(a1 + 236) = v16[0];
  v5 = get_ipc_log_context(v3);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(v5, "[d][%-4d]link rate = 0x%x\n", *(_DWORD *)(StatusReg + 1800), *(_DWORD *)(a1 + 236));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]link rate = 0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 236));
  v7 = drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 24LL), 544, v16, 1);
  if ( (int)v7 <= 0 )
  {
    v13 = get_ipc_log_context(v7);
    ipc_log_string(v13, "[e][%-4d]failed to read lane count\n", *(_DWORD *)(StatusReg + 1800));
    v12 = &unk_256081;
    goto LABEL_15;
  }
  v8 = v16[0] & 0x1F;
  if ( v8 > 4 || ((1 << v8) & 0x16) == 0 )
  {
    v14 = get_ipc_log_context(v7);
    ipc_log_string(v14, "[e][%-4d]invalid lane count = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v8);
    v12 = &unk_23E521;
    goto LABEL_15;
  }
  *(_DWORD *)(a1 + 240) = v8;
  v9 = get_ipc_log_context(v7);
  ipc_log_string(v9, "[d][%-4d]lane count = 0x%x\n", *(_DWORD *)(StatusReg + 1800), *(_DWORD *)(a1 + 240));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]lane count = 0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 240));
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
