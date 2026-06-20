__int64 __fastcall ufs_qcom_testbus_config(__int64 a1)
{
  unsigned __int64 StatusReg; // x25
  __int64 v2; // x22
  __int64 v4; // x1
  unsigned __int64 v6; // x20
  __int64 v7; // x21
  int v8; // w23
  int v9; // w24
  __int64 v10; // x22
  int v11; // w0
  _QWORD *v12; // x20
  int v13; // w0
  __int64 v14; // x20
  int v15; // w0
  __int64 v16; // x19
  int v17; // w0

  if ( !a1 )
    return 4294967274LL;
  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(a1 + 16);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFF0100) != 0 )
    v4 = 0;
  else
    v4 = raw_spin_lock_irqsave(*(_QWORD *)(*(_QWORD *)(v2 + 56) + 56LL));
  v6 = *(unsigned __int8 *)(a1 + 188);
  if ( v6 >= 0xC )
  {
    dev_err(
      *(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL),
      "%s: UFS_CFG1[TEST_BUS_SEL} may not equal 0x%05X\n",
      "ufs_qcom_testbus_cfg_is_ok",
      v6);
    return 0xFFFFFFFFLL;
  }
  else
  {
    v7 = (__int64)*(&off_18550 + v6);
    v8 = dword_185B0[v6];
    v9 = dword_185E0[v6];
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFF0100) == 0 )
    {
      raw_spin_unlock_irqrestore(*(_QWORD *)(*(_QWORD *)(v2 + 56) + 56LL), v4);
      LOBYTE(v6) = *(_BYTE *)(a1 + 188);
    }
    v10 = *(_QWORD *)(a1 + 16);
    v11 = readl((unsigned int *)(*(_QWORD *)v10 + 220LL));
    writel(v11 & 0xFF87FFFF | ((v6 & 0xF) << 19), (unsigned int *)(*(_QWORD *)v10 + 220LL));
    v12 = *(_QWORD **)(a1 + 16);
    LODWORD(v10) = *(unsigned __int8 *)(a1 + 189);
    v13 = readl((unsigned int *)(*v12 + v7));
    writel((v13 & ~(v9 << v8)) + ((v9 & (unsigned int)v10) << v8), (unsigned int *)(*v12 + v7));
    v14 = *(_QWORD *)(a1 + 16);
    v15 = readl((unsigned int *)(*(_QWORD *)v14 + 220LL));
    writel(v15 | 0x40000000, (unsigned int *)(*(_QWORD *)v14 + 220LL));
    v16 = *(_QWORD *)(a1 + 16);
    v17 = readl((unsigned int *)(*(_QWORD *)v16 + 220LL));
    writel(v17 | 0x40000, (unsigned int *)(*(_QWORD *)v16 + 220LL));
    return 0;
  }
}
