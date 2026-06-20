__int64 __fastcall gsi_flow_control_ee(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, int *a6)
{
  __int64 v6; // x8
  int v7; // w27
  char v10; // w22
  int v11; // w21
  int v12; // w23
  char v13; // w28
  __int64 v14; // x0
  unsigned int v15; // w24
  __int64 v16; // x1
  int reg_nk; // w0
  __int64 v18; // x1
  __int64 v19; // x9
  __int64 v20; // x1
  unsigned int v21; // w23
  int v22; // w24
  __int64 v23; // x0
  int v24; // w9
  __int64 v25; // x8
  unsigned int v26; // w20
  unsigned int v27; // w19
  int v29; // w24
  int v30; // w24
  int v31; // w24
  int v32; // w24
  __int64 v33; // x22
  int v34; // w0
  __int64 v35; // x8
  __int64 v36; // x22
  int v37; // w0
  __int64 v38; // x8
  long double v39; // q0
  _DWORD v40[3]; // [xsp+8h] [xbp-18h] BYREF
  int v41; // [xsp+14h] [xbp-Ch]
  __int64 v42; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a4 & 1) != 0 )
    v7 = 3;
  else
    v7 = 4;
  v42 = v6;
  v41 = 0;
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_flow_control_ee", 5212);
    v26 = -8;
    goto LABEL_15;
  }
  if ( !a6 || *(_DWORD *)(gsi_ctx + 28608) <= a1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_idx=%d\n", "gsi_flow_control_ee", 5217, a1);
    v26 = -6;
    goto LABEL_15;
  }
  v10 = a4;
  v11 = a3;
  v12 = a2;
  v13 = a5 & 1;
  v14 = mutex_lock(gsi_ctx + 28512, a2, a3, a4, a5);
  v15 = *(_DWORD *)(gsi_ctx + 20);
  gsihal_get_glob_irq_en_gp_int1_mask(v14);
  gsihal_read_reg_nk(4, v15, 0);
  gsihal_write_reg_nk(4, v15, 0);
  v16 = *(unsigned int *)(gsi_ctx + 20);
  *(_DWORD *)(gsi_ctx + 28616) = 0;
  reg_nk = gsihal_read_reg_nk(36, v16, 0);
  v18 = *(unsigned int *)(gsi_ctx + 20);
  *(_DWORD *)(gsi_ctx + 28588) = reg_nk & 0xFFFFFF1F;
  gsihal_write_reg_nk(36, v18, 0);
  v40[0] = v7;
  v40[1] = a1;
  v19 = *(_QWORD *)(gsi_ctx + 28504);
  v20 = *(unsigned int *)(gsi_ctx + 20);
  v40[2] = v11;
  LOBYTE(v41) = v13;
  *(_QWORD *)(gsi_ctx + 28504) = v19 + 1;
  ((void (__fastcall *)(__int64, __int64, _DWORD *))gsihal_write_reg_n_fields)(118, v20, v40);
  v21 = 20 * v12 + 7;
  v22 = gsihal_read_reg_nk(138, v21, 0);
  if ( !(unsigned int)wait_for_completion_timeout(gsi_ctx + 28616, 625) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan_idx=%u ee=%u timed out\n", "gsi_flow_control_ee", 5251, a1, v11);
    if ( (v10 & 1) != 0 && (v22 & 0x80000) != 0 )
    {
      v29 = gsihal_read_reg_nk(138, v21, 0);
      if ( (unsigned int)wait_for_completion_timeout(gsi_ctx + 28616, 625) )
        goto LABEL_8;
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan_idx=%u ee=%u timed out\n", "gsi_flow_control_ee", 5251, a1, v11);
      if ( (v10 & 1) != 0 && (v29 & 0x80000) != 0 )
      {
        v30 = gsihal_read_reg_nk(138, v21, 0);
        if ( (unsigned int)wait_for_completion_timeout(gsi_ctx + 28616, 625) )
          goto LABEL_8;
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan_idx=%u ee=%u timed out\n", "gsi_flow_control_ee", 5251, a1, v11);
        if ( (v10 & 1) != 0 && (v30 & 0x80000) != 0 )
        {
          v31 = gsihal_read_reg_nk(138, v21, 0);
          if ( (unsigned int)wait_for_completion_timeout(gsi_ctx + 28616, 625) )
            goto LABEL_8;
          dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan_idx=%u ee=%u timed out\n", "gsi_flow_control_ee", 5251, a1, v11);
          if ( (v10 & 1) != 0 && (v31 & 0x80000) != 0 )
          {
            v32 = gsihal_read_reg_nk(138, v21, 0);
            if ( (unsigned int)wait_for_completion_timeout(gsi_ctx + 28616, 625) )
              goto LABEL_8;
            dev_err(
              *(_QWORD *)(gsi_ctx + 8),
              "%s:%d chan_idx=%u ee=%u timed out\n",
              "gsi_flow_control_ee",
              5251,
              a1,
              v11);
            if ( (v10 & 1) != 0 && (v32 & 0x80000) != 0 )
            {
              gsihal_read_reg_nk(138, v21, 0);
              if ( (unsigned int)wait_for_completion_timeout(gsi_ctx + 28616, 625) )
                goto LABEL_8;
              dev_err(
                *(_QWORD *)(gsi_ctx + 8),
                "%s:%d chan_idx=%u ee=%u timed out\n",
                "gsi_flow_control_ee",
                5251,
                a1,
                v11);
            }
          }
        }
      }
    }
    v33 = *(_QWORD *)(gsi_ctx + 8);
    v34 = gsihal_read_reg_nk(4, *(unsigned int *)(gsi_ctx + 20), 0);
    dev_err(v33, "%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_EN_OFFS = 0x%x\n", "gsi_flow_control_ee", 5259, v34);
    v35 = gsi_ctx;
    if ( gsi_ctx )
    {
      if ( *(_QWORD *)(gsi_ctx + 28648) )
      {
        gsihal_read_reg_nk(4, *(unsigned int *)(gsi_ctx + 20), 0);
        v35 = gsi_ctx;
      }
      if ( *(_QWORD *)(v35 + 28656) )
      {
        gsihal_read_reg_nk(4, *(unsigned int *)(v35 + 20), 0);
        v35 = gsi_ctx;
      }
    }
    v36 = *(_QWORD *)(v35 + 8);
    v37 = gsihal_read_reg_nk(13, *(unsigned int *)(v35 + 20), 0);
    dev_err(v36, "%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_STTS_OFFS IRQ type = 0x%x\n", "gsi_flow_control_ee", 5261, v37);
    v38 = gsi_ctx;
    if ( gsi_ctx )
    {
      if ( *(_QWORD *)(gsi_ctx + 28648) )
      {
        gsihal_read_reg_nk(13, *(unsigned int *)(gsi_ctx + 20), 0);
        v38 = gsi_ctx;
      }
      if ( *(_QWORD *)(v38 + 28656) )
        gsihal_read_reg_nk(13, *(unsigned int *)(v38 + 20), 0);
    }
  }
LABEL_8:
  v23 = gsihal_read_reg_nk(36, *(unsigned int *)(gsi_ctx + 20), 0);
  v24 = (unsigned __int8)v23 >> 5;
  v25 = gsi_ctx;
  *(_DWORD *)(gsi_ctx + 28588) = v23;
  if ( v24 == 2 )
  {
    v26 = -4;
    goto LABEL_14;
  }
  if ( v24 == 5 )
  {
    dev_err(*(_QWORD *)(v25 + 8), "%s:%d Channel ID = %u ee = %u not allocated\n", "gsi_flow_control_ee", 5286, a1, v11);
    v25 = gsi_ctx;
    v24 = (*(_DWORD *)(gsi_ctx + 28588) >> 5) & 7;
    if ( v24 )
      goto LABEL_12;
    goto LABEL_45;
  }
  if ( v24 != 4 )
  {
    v24 = (unsigned __int8)v23 >> 5;
    if ( (unsigned __int8)v23 >> 5 )
    {
LABEL_12:
      v26 = 0;
LABEL_14:
      *a6 = v24;
      v27 = *(_DWORD *)(gsi_ctx + 20);
      gsihal_get_glob_irq_en_gp_int1_mask(v23);
      gsihal_read_reg_nk(4, v27, 0);
      gsihal_write_reg_nk(4, v27, 0);
      mutex_unlock(gsi_ctx + 28512);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return v26;
    }
LABEL_45:
    dev_err(*(_QWORD *)(v25 + 8), "%s:%d No response received\n", "gsi_flow_control_ee", 5290);
    __break(0x800u);
  }
  v39 = dev_err(
          *(_QWORD *)(v25 + 8),
          "%s:%d chan_idx=%u ee=%u not in correct state\n",
          "gsi_flow_control_ee",
          5282,
          a1,
          v11);
  __break(0x800u);
  return gsi_query_flow_control_state_ee(v39);
}
