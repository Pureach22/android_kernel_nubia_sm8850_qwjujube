__int64 __fastcall gsi_update_mhi_channel_scratch(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w19
  __int64 v5; // x4
  __int64 v7; // x26
  int reg_nk; // w20
  int v9; // w22
  int v10; // w23
  unsigned int v11; // w0
  unsigned __int64 v12; // x23
  unsigned __int64 v13; // x21
  __int64 vars0; // [xsp+0h] [xbp+0h] BYREF

  if ( gsi_ctx )
  {
    v4 = a1;
    if ( *(unsigned int *)(gsi_ctx + 28608) <= a1 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_hdl=%lu\n", "gsi_update_mhi_channel_scratch", 3363, a1);
      return 4294967290LL;
    }
    else
    {
      if ( a1 >= 0x24 )
      {
        __break(0x5512u);
        if ( !&vars0 )
          JUMPOUT(0x1ED74);
        JUMPOUT(0x1FAAC);
      }
      v5 = *(unsigned int *)(gsi_ctx + 184 + 448 * a1 + 120);
      if ( ((unsigned int)v5 | 2) == 3 )
      {
        v7 = gsi_ctx + 184 + 448 * a1;
        mutex_lock(v7 + 216, a2, a3, a4, v5);
        reg_nk = gsihal_read_reg_nk(56, *(unsigned int *)(gsi_ctx + 20), v4);
        v9 = gsihal_read_reg_nk(57, *(unsigned int *)(gsi_ctx + 20), v4);
        v10 = gsihal_read_reg_nk(58, *(unsigned int *)(gsi_ctx + 20), v4);
        v11 = gsihal_read_reg_nk(59, *(unsigned int *)(gsi_ctx + 20), v4);
        v12 = a3 & 0x100 | v10 & 0xFFFFFEFF | ((unsigned __int64)v11 << 32);
        if ( *(_DWORD *)(gsi_ctx + 16) > 5u )
        {
          v13 = (unsigned __int64)v11 << 32;
        }
        else
        {
          v12 = v12 & 0xFFFF0000FFFFLL | a3 & 0xFFFF0000FFFF0000LL;
          v13 = v12 & 0xFFFFFFFF00000000LL;
        }
        gsihal_write_reg_nk(56, *(unsigned int *)(gsi_ctx + 20), v4);
        gsihal_write_reg_nk(57, *(unsigned int *)(gsi_ctx + 20), v4);
        gsihal_write_reg_nk(58, *(unsigned int *)(gsi_ctx + 20), v4);
        gsihal_write_reg_nk(59, *(unsigned int *)(gsi_ctx + 20), v4);
        *(_DWORD *)(v7 + 304) = reg_nk;
        *(_DWORD *)(v7 + 308) = v9;
        *(_QWORD *)(v7 + 312) = (unsigned int)v12 | v13;
        *(_QWORD *)(v7 + 320) = 0;
        mutex_unlock(v7 + 216);
        return 0;
      }
      else
      {
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_update_mhi_channel_scratch", 3370, v5);
        return 4294967289LL;
      }
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_update_mhi_channel_scratch", 3358);
    return 4294967288LL;
  }
}
