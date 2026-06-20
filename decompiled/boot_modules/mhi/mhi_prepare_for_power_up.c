__int64 __fastcall mhi_prepare_for_power_up(__int64 a1)
{
  __int64 v2; // x21
  unsigned int inited; // w20
  unsigned int reg; // w0
  unsigned __int64 v5; // x4
  __int64 v6; // x1
  __int64 v7; // x8
  unsigned int v8; // w0
  unsigned __int64 v9; // x4
  __int64 *v10; // x1
  __int64 v11; // x22
  __int64 v12; // x20
  __int64 v13; // x22
  __int64 v14; // x20
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 16);
  v16[0] = 0;
  mutex_lock(a1 + 272);
  inited = mhi_init_dev_ctxt(a1);
  if ( inited )
    goto LABEL_30;
  reg = mhi_read_reg(a1, *(_QWORD *)(a1 + 32), 40, (char *)v16 + 4);
  if ( reg )
  {
    inited = reg;
    v11 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v2 + 40, "[E][%s] Error getting BHI offset\n", "mhi_prepare_for_power_up");
    if ( v11 && *(_DWORD *)(v11 + 24) <= 2u )
      ipc_log_string(*(_QWORD *)(v11 + 32), "[E][%s] Error getting BHI offset\n", "mhi_prepare_for_power_up");
    goto LABEL_29;
  }
  v5 = *(_QWORD *)(a1 + 144);
  if ( v5 <= HIDWORD(v16[0]) )
  {
    v12 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(
      v2 + 40,
      "[E][%s] BHI offset: 0x%x is out of range: 0x%zx\n",
      "mhi_prepare_for_power_up",
      HIDWORD(v16[0]),
      v5);
    if ( v12 && *(_DWORD *)(v12 + 24) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v12 + 32),
        "[E][%s] BHI offset: 0x%x is out of range: 0x%zx\n",
        "mhi_prepare_for_power_up",
        HIDWORD(v16[0]),
        *(_QWORD *)(a1 + 144));
    goto LABEL_28;
  }
  v6 = *(_QWORD *)(a1 + 32);
  v7 = *(_QWORD *)(a1 + 48);
  *(_QWORD *)(a1 + 40) = v6 + HIDWORD(v16[0]);
  if ( !v7 && ((*(_BYTE *)(a1 + 614) & 1) != 0 || (v7 = *(_QWORD *)(a1 + 120)) != 0) )
  {
    v8 = mhi_read_reg(a1, v6, 44, v16);
    if ( v8 )
    {
      inited = v8;
      v13 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      dev_err(v2 + 40, "[E][%s] Error getting BHIE offset\n", "mhi_prepare_for_power_up");
      if ( v13 && *(_DWORD *)(v13 + 24) <= 2u )
        ipc_log_string(*(_QWORD *)(v13 + 32), "[E][%s] Error getting BHIE offset\n", "mhi_prepare_for_power_up");
      goto LABEL_29;
    }
    v9 = *(_QWORD *)(a1 + 144);
    if ( v9 > LODWORD(v16[0]) )
    {
      v7 = *(_QWORD *)(a1 + 32) + LODWORD(v16[0]);
      *(_QWORD *)(a1 + 48) = v7;
      goto LABEL_10;
    }
    v14 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(
      v2 + 40,
      "[E][%s] BHIe offset: 0x%x is out of range: 0x%zx\n",
      "mhi_prepare_for_power_up",
      LODWORD(v16[0]),
      v9);
    if ( v14 && *(_DWORD *)(v14 + 24) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v14 + 32),
        "[E][%s] BHIe offset: 0x%x is out of range: 0x%zx\n",
        "mhi_prepare_for_power_up",
        LODWORD(v16[0]),
        *(_QWORD *)(a1 + 144));
LABEL_28:
    inited = -34;
    goto LABEL_29;
  }
LABEL_10:
  if ( *(_QWORD *)(a1 + 120)
    && (_memset_io(v7 + 96, 0, 28),
        mhi_alloc_bhie_table(a1, (__int64 *)(a1 + 160), *(_QWORD *)(a1 + 120)),
        (v10 = *(__int64 **)(a1 + 160)) != nullptr) )
  {
    inited = mhi_rddm_prepare(a1, v10);
    if ( inited )
    {
      mhi_free_bhie_table(a1, (_QWORD *)(a1 + 160));
LABEL_29:
      mhi_deinit_dev_ctxt(a1);
    }
  }
  else
  {
    inited = 0;
  }
LABEL_30:
  mutex_unlock(a1 + 272);
  _ReadStatusReg(SP_EL0);
  return inited;
}
