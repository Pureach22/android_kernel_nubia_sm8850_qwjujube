__int64 __fastcall gsi_start_channel(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x4
  __int64 v8; // x20
  int reg_nk; // w0
  _DWORD *v10; // x8
  int v11; // w4
  int v12; // w5
  __int64 result; // x0
  long double v14; // q0
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  _DWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_start_channel", 3436);
    result = 4294967288LL;
    goto LABEL_18;
  }
  if ( *(unsigned int *)(gsi_ctx + 28608) <= a1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_hdl=%lu\n", "gsi_start_channel", 3441, a1);
    result = 4294967290LL;
    goto LABEL_18;
  }
  if ( a1 >= 0x25 )
    goto LABEL_22;
  v5 = gsi_ctx + 448 * a1;
  v6 = *(unsigned int *)(v5 + 304);
  if ( (unsigned int)(v6 - 3) >= 2 && (_DWORD)v6 != 1 )
  {
    if ( (_DWORD)v6 != 2 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_start_channel", 3455, v6);
      result = 4294967289LL;
      goto LABEL_18;
    }
    goto LABEL_17;
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
      ++*(_QWORD *)(gsi_ctx + 56 * a1 + 16320);
      v19[0] = 1;
      v19[1] = a1;
      ((void (__fastcall *)(__int64, _QWORD, _DWORD *))gsihal_write_reg_n_fields)(
        55,
        *(unsigned int *)(gsi_ctx + 20),
        v19);
      gsi_channel_state_change_wait(a1, v8, 1000, 1);
      v12 = *(_DWORD *)(v8 + 120);
      if ( v12 == 2 || v12 == 5 )
      {
        gsihal_write_reg_nk(50, *(unsigned int *)(gsi_ctx + 20), *(unsigned __int8 *)(v8 + 8));
        mutex_unlock(gsi_ctx + 28512);
LABEL_17:
        result = 0;
LABEL_18:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v14 = dev_err(
              *(_QWORD *)(gsi_ctx + 8),
              "%s:%d chan=%lu timed out, unexpected state=%u\n",
              "gsi_start_channel",
              3488,
              a1,
              v12);
      gsi_dump_ch_info(a1, v14);
      __break(0x800u);
      goto LABEL_24;
    }
LABEL_22:
    __break(0x5512u);
  }
LABEL_24:
  dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d GSI_EE_n_CNTXT_INTSET %d\n", "gsi_start_channel", 3467, v11);
  __break(0x800u);
  return gsi_channel_state_change_wait(v15, v16, v17, v18);
}
