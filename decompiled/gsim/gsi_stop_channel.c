__int64 __fastcall gsi_stop_channel(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x4
  unsigned int v7; // w19
  __int64 v8; // x20
  int reg_nk; // w0
  _DWORD *v10; // x8
  int v11; // w4
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  int v16; // w5
  __int64 v17; // x8
  __int64 v18; // x19
  unsigned int v19; // w21
  unsigned int ch_reg_idx; // w22
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  long double v25; // q0
  _DWORD v26[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_stop_channel", 3604);
    v7 = -8;
    goto LABEL_24;
  }
  if ( *(unsigned int *)(gsi_ctx + 28608) <= a1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_hdl=%lu\n", "gsi_stop_channel", 3609, a1);
    v7 = -6;
    goto LABEL_24;
  }
  if ( a1 >= 0x25 )
    goto LABEL_29;
  v5 = gsi_ctx + 448 * a1;
  v6 = *(unsigned int *)(v5 + 304);
  if ( (int)v6 > 3 )
  {
    if ( (_DWORD)v6 != 4 && (_DWORD)v6 != 15 )
      goto LABEL_28;
  }
  else if ( (_DWORD)v6 != 2 )
  {
    if ( (_DWORD)v6 == 3 )
    {
      v7 = 0;
LABEL_24:
      _ReadStatusReg(SP_EL0);
      return v7;
    }
LABEL_28:
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_stop_channel", 3623, v6);
    v7 = -7;
    goto LABEL_24;
  }
  v8 = v5 + 184;
  mutex_lock(gsi_ctx + 28512, a2, a3, a4, v6);
  *(_DWORD *)(v8 + 264) = 0;
  reg_nk = gsihal_read_reg_nk(32, *(unsigned int *)(gsi_ctx + 20), 0);
  v10 = *(_DWORD **)(v8 + 208);
  if ( !v10 || *v10 != 2 || (v11 = reg_nk, reg_nk == 1) )
  {
    if ( a1 != 36 )
    {
      ++*(_QWORD *)(gsi_ctx + 56 * a1 + 16328);
      v26[0] = 2;
      v26[1] = a1;
      ((void (__fastcall *)(__int64, _QWORD, _DWORD *))gsihal_write_reg_n_fields)(
        55,
        *(unsigned int *)(gsi_ctx + 20),
        v26);
      gsi_channel_state_change_wait(a1, v8, 0xC8u, 2);
      v16 = *(_DWORD *)(v8 + 120);
      if ( (unsigned int)(v16 - 3) < 2 )
      {
        if ( v16 == 4 )
        {
          dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan=%lu busy try again\n", "gsi_stop_channel", 3660, a1);
          v7 = -12;
        }
        else
        {
          v17 = *(_QWORD *)(v8 + 208);
          if ( v17 && !*(_DWORD *)(v17 + 4) )
          {
            v18 = raw_spin_lock_irqsave(v17 + 136, v12, v13, v14, v15);
            v19 = *(_DWORD *)(gsi_ctx + 20);
            if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
            {
              v21 = 20;
              v22 = v19;
              v23 = 0;
            }
            else
            {
              ch_reg_idx = gsihal_get_ch_reg_idx(*(unsigned __int8 *)(*(_QWORD *)(v8 + 208) + 132LL));
              gsihal_get_ch_reg_mask(*(unsigned __int8 *)(*(_QWORD *)(v8 + 208) + 132LL));
              v21 = 133;
              v22 = v19;
              v23 = ch_reg_idx;
            }
            gsihal_write_reg_nk(v21, v22, v23);
            raw_spin_unlock_irqrestore(*(_QWORD *)(v8 + 208) + 136LL, v18);
          }
          v7 = 0;
        }
        mutex_unlock(gsi_ctx + 28512);
        goto LABEL_24;
      }
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan=%lu unexpected state=%u\n", "gsi_stop_channel", 3652, a1, v16);
      gsi_dump_ch_info(a1);
      __break(0x800u);
      goto LABEL_31;
    }
LABEL_29:
    __break(0x5512u);
  }
LABEL_31:
  v25 = dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d GSI_EE_n_CNTXT_INTSET %d\n", "gsi_stop_channel", 3635, v11);
  __break(0x800u);
  return gsi_stop_db_channel(v25);
}
