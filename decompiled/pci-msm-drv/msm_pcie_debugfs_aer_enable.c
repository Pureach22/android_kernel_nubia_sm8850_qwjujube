size_t __fastcall msm_pcie_debugfs_aer_enable(__int64 a1, unsigned __int64 a2, size_t a3)
{
  size_t v3; // x19
  int v4; // w0
  __int64 v6; // x20
  unsigned __int64 v7; // x8
  __int64 v8; // x8
  _BOOL4 v9; // w25
  __int64 v10; // x26
  int v11; // w0
  int v12; // w8
  __int64 v13; // x8
  __int64 v14; // x26
  int v15; // w0
  _BOOL4 v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v4 = msm_pcie_debugfs_parse_input(a2, a3, (__int64)&v16);
  if ( v4 )
  {
    v3 = v4;
  }
  else
  {
    v6 = 0;
    v7 = (unsigned int)rc_sel;
    v16 = v16;
    do
    {
      if ( ((v7 >> v6) & 1) != 0 )
      {
        *(_BYTE *)(msm_pcie_dev[v6] + 1235) = v16;
        v8 = msm_pcie_dev[v6];
        if ( v8 )
          ipc_log_string(
            *(_QWORD *)(v8 + 1712),
            "DBG_FS:%s: PCIe: RC%d: aer_enable is now %d\n",
            "msm_pcie_debugfs_aer_enable",
            v6,
            *(unsigned __int8 *)(v8 + 1235));
        printk(&unk_2FECB);
        v9 = v16;
        v10 = *(_QWORD *)(msm_pcie_dev[v6] + 904);
        v11 = readl_relaxed_0((unsigned int *)(v10 + 60));
        if ( v9 )
          v12 = -1;
        else
          v12 = -65537;
        writel_relaxed_0(v12 & v11 | (v9 << 16), (unsigned int *)(v10 + 60));
        readl_relaxed_0((unsigned int *)(v10 + 60));
        v13 = msm_pcie_dev[v6];
        if ( v13 )
        {
          v14 = *(_QWORD *)(v13 + 1712);
          v15 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v13 + 904) + 60LL));
          ipc_log_string(v14, "DBG_FS:%s: RC%d: PCIE20_BRIDGE_CTRL: 0x%x\n", "msm_pcie_debugfs_aer_enable", v6, v15);
          v13 = msm_pcie_dev[v6];
        }
        readl_relaxed_0((unsigned int *)(*(_QWORD *)(v13 + 904) + 60LL));
        printk(&unk_2F093);
        v7 = (unsigned int)rc_sel;
      }
      ++v6;
    }
    while ( v6 != 5 );
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
