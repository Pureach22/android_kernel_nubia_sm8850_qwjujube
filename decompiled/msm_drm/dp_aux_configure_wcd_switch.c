__int64 __fastcall dp_aux_configure_wcd_switch(__int64 a1, char a2, unsigned int a3)
{
  char v4; // w23
  unsigned int v7; // w22
  unsigned int v8; // w21
  unsigned __int64 StatusReg; // x20
  unsigned __int64 v10; // x24
  unsigned int v12; // w22
  void *v13; // x0

  if ( !a1 )
  {
    _ReadStatusReg(SP_EL0);
    v13 = &unk_275B6D;
LABEL_19:
    printk(v13, "dp_aux_configure_wcd_switch");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 136) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(*(_QWORD *)(a1 + 16), "[d][%-4d]undefined wcd939x switch handle\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]undefined wcd939x switch handle\n", *(_DWORD *)(StatusReg + 1800));
    return 4294967274LL;
  }
  v4 = a2 & 1;
  if ( *(_BYTE *)(a1 + 1824) == (a2 & 1) && *(_DWORD *)(a1 + 1828) == a3 )
    return 0;
  if ( (a2 & 1) == 0 )
  {
    v8 = 0;
    v7 = 1;
    goto LABEL_13;
  }
  v7 = a3;
  v8 = a3;
  if ( a3 != 1 )
  {
    if ( a3 == 2 )
    {
      v8 = 1;
      v7 = 2;
      goto LABEL_13;
    }
    ipc_log_string(*(_QWORD *)(a1 + 16), "[e][%-4d]invalid orientation\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v13 = &unk_233E04;
    goto LABEL_19;
  }
LABEL_13:
  v10 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    *(_QWORD *)(a1 + 16),
    "[d][%-4d]enable=%d, orientation=%d, event=%d\n",
    *(_DWORD *)(v10 + 1800),
    a2 & 1,
    a3,
    v7);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]enable=%d, orientation=%d, event=%d\n",
      *(_DWORD *)(v10 + 1800),
      a2 & 1,
      a3,
      v7);
  v12 = wcd_usbss_switch_update(v7, v8);
  if ( v12 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 16),
      "[e][%-4d]failed to configure wcd939x i2c device (%d)\n",
      *(_DWORD *)(v10 + 1800),
      v12);
    printk(&unk_2610D5, "dp_aux_configure_wcd_switch");
  }
  else
  {
    *(_BYTE *)(a1 + 1824) = v4;
    *(_DWORD *)(a1 + 1828) = a3;
  }
  dp_switch_event(*(_QWORD *)(a1 + 136), v8);
  return v12;
}
