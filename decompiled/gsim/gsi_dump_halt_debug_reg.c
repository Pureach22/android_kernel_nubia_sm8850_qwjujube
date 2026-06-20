void __fastcall gsi_dump_halt_debug_reg(unsigned int a1, unsigned int a2)
{
  __int64 v4; // x21
  int reg_nk; // w0
  __int64 v6; // x8
  __int64 v7; // x21
  int v8; // w0
  __int64 v9; // x8
  __int64 v10; // x21
  int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x21
  int v14; // w0
  __int64 v15; // x8
  __int64 v16; // x21
  int v17; // w0
  __int64 v18; // x8
  __int64 v19; // x21
  int v20; // w0
  __int64 v21; // x8
  _QWORD v22[5]; // [xsp+8h] [xbp-28h] BYREF

  v22[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v22, 0, 32);
  v4 = *(_QWORD *)(gsi_ctx + 8);
  reg_nk = gsihal_read_reg_nk(148, 0, 0);
  dev_err(v4, "%s:%d DEBUG_PC_FOR_DEBUG = 0x%x\n", "gsi_dump_halt_debug_reg", 4943, reg_nk);
  v6 = 0;
  if ( gsi_ctx )
  {
    v6 = gsi_ctx;
    if ( *(_QWORD *)(gsi_ctx + 28648) )
    {
      gsihal_read_reg_nk(148, 0, 0);
      v6 = gsi_ctx;
    }
    if ( *(_QWORD *)(v6 + 28656) )
    {
      gsihal_read_reg_nk(148, 0, 0);
      v6 = gsi_ctx;
    }
  }
  v7 = *(_QWORD *)(v6 + 8);
  v8 = gsihal_read_reg_nk(149, 0, 0);
  dev_err(v7, "%s:%d GSI_DEBUG_BUSY_REG 0x%x\n", "gsi_dump_halt_debug_reg", 4946, v8);
  v9 = gsi_ctx;
  if ( gsi_ctx )
  {
    if ( *(_QWORD *)(gsi_ctx + 28648) )
    {
      gsihal_read_reg_nk(149, 0, 0);
      v9 = gsi_ctx;
    }
    if ( *(_QWORD *)(v9 + 28656) )
    {
      gsihal_read_reg_nk(149, 0, 0);
      v9 = gsi_ctx;
    }
  }
  v10 = *(_QWORD *)(v9 + 8);
  v11 = gsihal_read_reg_nk(4, *(unsigned int *)(v9 + 20), 0);
  dev_err(v10, "%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_EN_OFFS = 0x%x\n", "gsi_dump_halt_debug_reg", 4949, v11);
  v12 = gsi_ctx;
  if ( gsi_ctx )
  {
    if ( *(_QWORD *)(gsi_ctx + 28648) )
    {
      gsihal_read_reg_nk(4, *(unsigned int *)(gsi_ctx + 20), 0);
      v12 = gsi_ctx;
    }
    if ( *(_QWORD *)(v12 + 28656) )
    {
      gsihal_read_reg_nk(4, *(unsigned int *)(v12 + 20), 0);
      v12 = gsi_ctx;
    }
  }
  v13 = *(_QWORD *)(v12 + 8);
  v14 = gsihal_read_reg_nk(4, *(unsigned int *)(v12 + 20), 0);
  dev_err(v13, "%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_STTS_OFFS IRQ type = 0x%x\n", "gsi_dump_halt_debug_reg", 4952, v14);
  v15 = gsi_ctx;
  if ( gsi_ctx )
  {
    if ( *(_QWORD *)(gsi_ctx + 28648) )
    {
      gsihal_read_reg_nk(4, *(unsigned int *)(gsi_ctx + 20), 0);
      v15 = gsi_ctx;
    }
    if ( *(_QWORD *)(v15 + 28656) )
    {
      gsihal_read_reg_nk(4, *(unsigned int *)(v15 + 20), 0);
      v15 = gsi_ctx;
    }
  }
  v16 = *(_QWORD *)(v15 + 8);
  v17 = gsihal_read_reg_nk(36, *(unsigned int *)(v15 + 20), 0);
  dev_err(v16, "%s:%d GSI_EE_n_CNTXT_SCRATCH_0_OFFS = 0x%x\n", "gsi_dump_halt_debug_reg", 4955, v17);
  v18 = gsi_ctx;
  if ( gsi_ctx )
  {
    if ( *(_QWORD *)(gsi_ctx + 28648) )
    {
      gsihal_read_reg_nk(36, *(unsigned int *)(gsi_ctx + 20), 0);
      v18 = gsi_ctx;
    }
    if ( *(_QWORD *)(v18 + 28656) )
    {
      gsihal_read_reg_nk(36, *(unsigned int *)(v18 + 20), 0);
      v18 = gsi_ctx;
    }
  }
  if ( *(_DWORD *)(v18 + 16) >= 8u )
  {
    v19 = *(_QWORD *)(v18 + 8);
    v20 = gsihal_read_reg_nk(60, a2, a1);
    dev_err(v19, "%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_4 = 0x%x\n", "gsi_dump_halt_debug_reg", 4958, v20);
    v21 = gsi_ctx;
    if ( gsi_ctx )
    {
      if ( *(_QWORD *)(gsi_ctx + 28648) )
      {
        gsihal_read_reg_nk(60, a2, a1);
        v21 = gsi_ctx;
      }
      if ( *(_QWORD *)(v21 + 28656) )
        gsihal_read_reg_nk(60, a2, a1);
    }
  }
  gsihal_read_reg_nk_fields(8, a2, a1, v22);
  dev_err(
    *(_QWORD *)(gsi_ctx + 8),
    "%s:%d Q6 channel [%d] state =  %d\n",
    "gsi_dump_halt_debug_reg",
    4961,
    a1,
    HIDWORD(v22[0]));
  _ReadStatusReg(SP_EL0);
}
