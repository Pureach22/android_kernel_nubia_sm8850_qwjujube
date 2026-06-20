__int64 __fastcall gsi_read_channel_scratch(unsigned __int64 a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w19
  __int64 v5; // x4
  __int64 v7; // x22
  int reg_nk; // w0
  __int64 v9; // x8

  if ( gsi_ctx )
  {
    v4 = a1;
    if ( *(unsigned int *)(gsi_ctx + 28608) <= a1 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_hdl=%lu\n", "gsi_read_channel_scratch", 3296, a1);
      return 4294967290LL;
    }
    else
    {
      if ( a1 >= 0x24 )
      {
        __break(0x5512u);
        JUMPOUT(0x1EA40);
      }
      v5 = *(unsigned int *)(gsi_ctx + 184 + 448 * a1 + 120);
      if ( (unsigned int)(v5 - 1) >= 3 )
      {
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_read_channel_scratch", 3304, v5);
        return 4294967289LL;
      }
      else
      {
        v7 = gsi_ctx + 184 + 448 * a1;
        mutex_lock(v7 + 216, a2, a3, a4, v5);
        *a2 = gsihal_read_reg_nk(56, *(unsigned int *)(gsi_ctx + 20), v4);
        a2[1] = gsihal_read_reg_nk(57, *(unsigned int *)(gsi_ctx + 20), v4);
        reg_nk = gsihal_read_reg_nk(58, *(unsigned int *)(gsi_ctx + 20), v4);
        v9 = gsi_ctx;
        a2[2] = reg_nk;
        a2[3] = gsihal_read_reg_nk(59, *(unsigned int *)(v9 + 20), v4);
        mutex_unlock(v7 + 216);
        return 0;
      }
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_read_channel_scratch", 3291);
    return 4294967288LL;
  }
}
