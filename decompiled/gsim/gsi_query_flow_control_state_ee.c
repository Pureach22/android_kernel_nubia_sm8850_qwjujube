__int64 __fastcall gsi_query_flow_control_state_ee(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        unsigned int *a4,
        __int64 a5)
{
  char v7; // w19
  int v8; // w22
  char v9; // w26
  __int64 v10; // x0
  unsigned int v11; // w23
  __int64 v12; // x1
  int reg_nk; // w0
  __int64 v14; // x1
  __int64 v15; // x10
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v18; // x8
  int v19; // w9
  bool v20; // zf
  unsigned int v21; // w19
  unsigned int v22; // w20
  _DWORD v24[3]; // [xsp+8h] [xbp-18h] BYREF
  int v25; // [xsp+14h] [xbp-Ch]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  if ( gsi_ctx )
  {
    if ( a4 && *(_DWORD *)(gsi_ctx + 28608) > a1 )
    {
      v7 = a3;
      v8 = a2;
      v9 = a3 & 1;
      v10 = mutex_lock(gsi_ctx + 28512, a2, a3, a4, a5);
      v11 = *(_DWORD *)(gsi_ctx + 20);
      gsihal_get_glob_irq_en_gp_int1_mask(v10);
      gsihal_read_reg_nk(4, v11, 0);
      gsihal_write_reg_nk(4, v11, 0);
      v12 = *(unsigned int *)(gsi_ctx + 20);
      *(_DWORD *)(gsi_ctx + 28616) = 0;
      reg_nk = gsihal_read_reg_nk(36, v12, 0);
      v14 = *(unsigned int *)(gsi_ctx + 20);
      *(_DWORD *)(gsi_ctx + 28588) = reg_nk & 0xFFFFFF1F;
      gsihal_write_reg_nk(36, v14, 0);
      v24[0] = 5;
      v15 = *(_QWORD *)(gsi_ctx + 28504);
      v16 = *(unsigned int *)(gsi_ctx + 20);
      v24[1] = a1;
      v24[2] = v8;
      LOBYTE(v25) = v9;
      *(_QWORD *)(gsi_ctx + 28504) = v15 + 1;
      ((void (__fastcall *)(__int64, __int64, _DWORD *))gsihal_write_reg_n_fields)(118, v16, v24);
      if ( (unsigned int)wait_for_completion_timeout(gsi_ctx + 28616, 313) )
      {
        v17 = gsihal_read_reg_nk(36, *(unsigned int *)(gsi_ctx + 20), 0);
        *(_DWORD *)(gsi_ctx + 28588) = v17;
        *a4 = ((unsigned int)v17 >> 10) & 7;
        v18 = gsi_ctx;
        v19 = *(_DWORD *)(gsi_ctx + 28588) & 0x1C00;
        if ( (v7 & 1) != 0 )
          v20 = v19 == 1024;
        else
          v20 = v19 == 0;
        if ( v20 )
          v21 = 0;
        else
          v21 = -1;
      }
      else
      {
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d chan_idx=%u ee=%u timed out\n",
          "gsi_query_flow_control_state_ee",
          5347,
          a1,
          v8);
        v18 = gsi_ctx;
        v21 = -11;
      }
      v22 = *(_DWORD *)(v18 + 20);
      gsihal_get_glob_irq_en_gp_int1_mask(v17);
      gsihal_read_reg_nk(4, v22, 0);
      gsihal_write_reg_nk(4, v22, 0);
      mutex_unlock(gsi_ctx + 28512);
    }
    else
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_idx=%d\n", "gsi_query_flow_control_state_ee", 5320, a1);
      v21 = -6;
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_query_flow_control_state_ee", 5315);
    v21 = -8;
  }
  _ReadStatusReg(SP_EL0);
  return v21;
}
