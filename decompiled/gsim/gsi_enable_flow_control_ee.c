__int64 __fastcall gsi_enable_flow_control_ee(unsigned int a1, __int64 a2, int *a3, __int64 a4, __int64 a5)
{
  int v7; // w21
  __int64 v8; // x0
  unsigned int v9; // w22
  __int64 v10; // x1
  int reg_nk; // w0
  __int64 v12; // x1
  __int64 v13; // x10
  __int64 v14; // x1
  __int64 reg_nk_fields; // x0
  int v16; // w9
  __int64 v17; // x8
  unsigned int v18; // w19
  int v19; // w8
  unsigned int v20; // w20
  long double v22; // q0
  int **v23; // x1
  _DWORD v24[4]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v25[5]; // [xsp+18h] [xbp-28h] BYREF

  v25[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v25, 0, 32);
  v24[3] = 0;
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_enable_flow_control_ee", 5119);
    v18 = -8;
    goto LABEL_14;
  }
  if ( !a3 || *(_DWORD *)(gsi_ctx + 28608) <= a1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_idx=%d\n", "gsi_enable_flow_control_ee", 5124, a1);
    v18 = -6;
    goto LABEL_14;
  }
  v7 = a2;
  v8 = mutex_lock(gsi_ctx + 28512, a2, a3, a4, a5);
  v9 = *(_DWORD *)(gsi_ctx + 20);
  gsihal_get_glob_irq_en_gp_int1_mask(v8);
  gsihal_read_reg_nk(4, v9, 0);
  gsihal_write_reg_nk(4, v9, 0);
  v10 = *(unsigned int *)(gsi_ctx + 20);
  *(_DWORD *)(gsi_ctx + 28616) = 0;
  reg_nk = gsihal_read_reg_nk(36, v10, 0);
  v12 = *(unsigned int *)(gsi_ctx + 20);
  *(_DWORD *)(gsi_ctx + 28588) = reg_nk & 0xFFFFFF1F;
  gsihal_write_reg_nk(36, v12, 0);
  v24[0] = 3;
  v24[1] = a1;
  v13 = *(_QWORD *)(gsi_ctx + 28504);
  v14 = *(unsigned int *)(gsi_ctx + 20);
  v24[2] = v7;
  *(_QWORD *)(gsi_ctx + 28504) = v13 + 1;
  ((void (__fastcall *)(__int64, __int64, _DWORD *))gsihal_write_reg_n_fields)(118, v14, v24);
  if ( !(unsigned int)wait_for_completion_timeout(gsi_ctx + 28616, 313) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan_idx=%u ee=%u timed out\n", "gsi_enable_flow_control_ee", 5150, a1, v7);
    v18 = -11;
    goto LABEL_13;
  }
  reg_nk_fields = gsihal_read_reg_nk(36, *(unsigned int *)(gsi_ctx + 20), 0);
  v16 = (unsigned __int8)reg_nk_fields >> 5;
  v17 = gsi_ctx;
  *(_DWORD *)(gsi_ctx + 28588) = reg_nk_fields;
  if ( v16 == 2 )
  {
    v19 = 2;
    v18 = -4;
LABEL_12:
    *a3 = v19;
LABEL_13:
    v20 = *(_DWORD *)(gsi_ctx + 20);
    gsihal_get_glob_irq_en_gp_int1_mask(reg_nk_fields);
    gsihal_read_reg_nk(4, v20, 0);
    gsihal_write_reg_nk(4, v20, 0);
    mutex_unlock(gsi_ctx + 28512);
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return v18;
  }
  if ( !((unsigned __int8)reg_nk_fields >> 5) )
  {
    dev_err(*(_QWORD *)(v17 + 8), "%s:%d No response received\n", "gsi_enable_flow_control_ee", 5173);
    v18 = -1;
    goto LABEL_13;
  }
  if ( (unsigned int)(v16 - 4) >= 2 )
  {
    reg_nk_fields = gsihal_read_reg_nk_fields(8, *(unsigned int *)(v17 + 20), a1, v25);
    if ( HIDWORD(v25[0]) == 5 )
    {
      v18 = 0;
    }
    else
    {
      dev_err(
        *(_QWORD *)(gsi_ctx + 8),
        "%s:%d ch %u state updated to %u incorrect state\n",
        "gsi_enable_flow_control_ee",
        5187,
        a1,
        HIDWORD(v25[0]));
      v18 = -1;
    }
    v19 = (unsigned __int8)*(_DWORD *)(gsi_ctx + 28588) >> 5;
    goto LABEL_12;
  }
  v22 = dev_err(
          *(_QWORD *)(v17 + 8),
          "%s:%d chan_idx=%u ee=%u not in correct state\n",
          "gsi_enable_flow_control_ee",
          5169,
          a1,
          v7);
  __break(0x800u);
  *v23 = a3;
  v23[1] = (int *)v23;
  return gsi_flow_control_ee(v22);
}
