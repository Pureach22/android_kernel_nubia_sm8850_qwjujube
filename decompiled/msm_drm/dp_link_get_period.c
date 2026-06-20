__int64 __fastcall dp_link_get_period(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v7; // x0
  int v8; // w19
  __int64 v9; // x0
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v2 = a2;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 16);
  v10[0] = 0;
  v4 = drm_dp_dpcd_read(*(_QWORD *)(v3 + 24), a2, v10, 1);
  if ( v4 <= 0 )
  {
    ipc_log_context = get_ipc_log_context(v4);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]failed to read test_audio_period (0x%x)\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v2);
    v7 = &unk_2648C2;
LABEL_6:
    printk(v7, "dp_link_get_period");
    result = 4294967274LL;
    goto LABEL_3;
  }
  result = v10[0] & 0xF;
  if ( (unsigned int)result >= 0xB )
  {
    v8 = v10[0] & 0xF;
    v9 = get_ipc_log_context(result);
    ipc_log_string(
      v9,
      "[e][%-4d]invalid test_audio_period_ch_1 = 0x%x\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v8);
    v7 = &unk_26B7C2;
    goto LABEL_6;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
