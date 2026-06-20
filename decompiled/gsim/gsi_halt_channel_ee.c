__int64 __fastcall gsi_halt_channel_ee(unsigned int a1, __int64 a2, int *a3, __int64 a4, __int64 a5)
{
  unsigned int v7; // w20
  __int64 v8; // x0
  unsigned int v9; // w22
  __int64 v10; // x1
  int reg_nk; // w0
  __int64 v12; // x1
  __int64 v13; // x10
  __int64 v14; // x1
  __int64 v15; // x0
  int v16; // w8
  __int64 v17; // x9
  unsigned int v18; // w19
  unsigned int v19; // w20
  long double v21; // q0
  long double v22; // q0
  __int64 v23; // x8
  long double v24; // q0
  _DWORD v25[4]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[3] = 0;
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_halt_channel_ee", 4971);
    v18 = -8;
    goto LABEL_10;
  }
  if ( !a3 || *(_DWORD *)(gsi_ctx + 28608) <= a1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_idx=%d\n", "gsi_halt_channel_ee", 4976, a1);
    v18 = -6;
    goto LABEL_10;
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
  v25[0] = 1;
  v25[1] = a1;
  v13 = *(_QWORD *)(gsi_ctx + 28496);
  v14 = *(unsigned int *)(gsi_ctx + 20);
  v25[2] = v7;
  *(_QWORD *)(gsi_ctx + 28496) = v13 + 1;
  ((void (__fastcall *)(__int64, __int64, _DWORD *))gsihal_write_reg_n_fields)(118, v14, v25);
  if ( (unsigned int)wait_for_completion_timeout(gsi_ctx + 28616, 313) )
  {
    v15 = gsihal_read_reg_nk(36, *(unsigned int *)(gsi_ctx + 20), 0);
    v16 = (unsigned __int8)v15 >> 5;
    v17 = gsi_ctx;
    *(_DWORD *)(gsi_ctx + 28588) = v15;
    if ( v16 == 6 )
    {
      *a3 = 6;
      v18 = -12;
    }
    else
    {
      if ( !((unsigned __int8)v15 >> 5) )
      {
        v21 = dev_err(*(_QWORD *)(v17 + 8), "%s:%d No response received\n", "gsi_halt_channel_ee", 5015);
        v22 = gsi_dump_halt_debug_reg(a1, v7, v21);
        usleep_range_state(1000, 2000, 2, v22);
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Reading after usleep scratch 0 reg\n", "gsi_halt_channel_ee", 5018);
        v15 = gsihal_read_reg_nk(36, *(unsigned int *)(gsi_ctx + 20), 0);
        v23 = gsi_ctx;
        *(_DWORD *)(gsi_ctx + 28588) = v15;
        if ( (v15 & 0xE0) == 0 )
        {
          v24 = dev_err(
                  *(_QWORD *)(v23 + 8),
                  "%s:%d No response received second attempt\n",
                  "gsi_halt_channel_ee",
                  5022);
          gsi_dump_halt_debug_reg(a1, v7, v24);
          v18 = -1;
          goto LABEL_9;
        }
        v16 = (unsigned __int8)v15 >> 5;
      }
      v18 = 0;
      *a3 = v16;
    }
  }
  else
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan_idx=%u ee=%u timed out\n", "gsi_halt_channel_ee", 5000, a1, v7);
    v18 = -11;
  }
LABEL_9:
  v19 = *(_DWORD *)(gsi_ctx + 20);
  gsihal_get_glob_irq_en_gp_int1_mask(v15);
  gsihal_read_reg_nk(4, v19, 0);
  gsihal_write_reg_nk(4, v19, 0);
  mutex_unlock(gsi_ctx + 28512);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v18;
}
