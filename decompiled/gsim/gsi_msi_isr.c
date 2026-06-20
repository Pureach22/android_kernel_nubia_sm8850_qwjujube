__int64 __fastcall gsi_msi_isr(int a1)
{
  unsigned int v1; // w19
  int v2; // w10
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x20
  int v6; // w4
  unsigned int ch_reg_idx; // w21
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x21
  __int64 v13; // x2
  _DWORD *v14; // x8
  __int64 v15; // x1
  unsigned __int64 v16; // x22
  __int64 v17; // x8
  __int64 v18; // x24
  __int64 v20; // x0
  _QWORD v21[4]; // [xsp+0h] [xbp-20h] BYREF

  v21[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v21, 0, 24);
  v1 = *(_DWORD *)(gsi_ctx + 20);
  v2 = *(_DWORD *)(gsi_ctx + 28680);
  if ( v2 && *(_DWORD *)(gsi_ctx + 28728) != a1 )
  {
    if ( v2 != 1 && *(_DWORD *)(gsi_ctx + 28732) != a1 )
LABEL_23:
      __break(0x5512u);
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  if ( *(unsigned __int8 *)(gsi_ctx + 4 * v3 + 28736) > 0x1Fu )
    goto LABEL_23;
  v4 = gsi_ctx + 328LL * *(unsigned __int8 *)(gsi_ctx + 4 * v3 + 28736);
  v5 = v4 + 18328;
  v6 = *(_DWORD *)(v4 + 18328);
  if ( v6 == 2 )
  {
    ch_reg_idx = gsihal_get_ch_reg_idx(*(unsigned __int8 *)(v4 + 18460));
    gsihal_get_ch_reg_mask(*(unsigned __int8 *)(v5 + 132));
    gsihal_write_reg_nk(133, v1, ch_reg_idx);
    v12 = raw_spin_lock_irqsave(v5 + 136, v8, v9, v10, v11);
    do
    {
      v14 = *(_DWORD **)(v5 + 120);
      v15 = *(unsigned __int8 *)(v5 + 132);
      if ( *(v14 - 1) != -1228272253 )
        __break(0x8228u);
      v16 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v14)(v5, v15, v1)
          | ((unsigned __int64)*(unsigned int *)(v5 + 172) << 32);
      v17 = *(_QWORD *)(v5 + 184);
      *(_QWORD *)(v5 + 168) = v16;
      if ( v17 == v16 || *(_BYTE *)(v5 + 88) == 1 && *(_DWORD *)(*(_QWORD *)(v5 + 288) + 300LL) )
        break;
      gsi_process_evt_re(v5, (__int64)v21, 1);
      v18 = 1;
      if ( *(_QWORD *)(v5 + 184) != v16 )
      {
        while ( *(_BYTE *)(v5 + 88) != 1 || !*(_DWORD *)(*(_QWORD *)(v5 + 288) + 300LL) )
        {
          gsi_process_evt_re(v5, (__int64)v21, 1);
          ++v18;
          if ( *(_QWORD *)(v5 + 184) == v16 )
            goto LABEL_10;
        }
        v18 = 0;
      }
LABEL_10:
      v13 = *(unsigned __int8 *)(v5 + 132);
      *(_QWORD *)(v5 + 160) = *(_QWORD *)(v5 + 176);
      gsihal_write_reg_nk(17, *(unsigned int *)(gsi_ctx + 20), v13);
    }
    while ( v18 );
    raw_spin_unlock_irqrestore(v5 + 136, v12);
    _ReadStatusReg(SP_EL0);
    return 1;
  }
  else
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Unexpected irq intf %d\n", "gsi_msi_isr", 1160, v6);
    __break(0x800u);
    return readl_relaxed(v20);
  }
}
