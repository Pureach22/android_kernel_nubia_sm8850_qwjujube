__int64 __fastcall gsi_write_device_scratch(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w8
  __int64 v6; // x8

  if ( gsi_ctx )
  {
    if ( (*(_BYTE *)(gsi_ctx + 176) & 1) != 0 )
    {
      if ( gsi_ctx == a1 )
      {
        if ( *(_BYTE *)(a2 + 2) != 1 || (v5 = *(unsigned __int16 *)(a2 + 4), v5 == 64) || v5 == 512 || v5 == 1024 )
        {
          mutex_lock(gsi_ctx + 28512, a2, a3, a4, a1);
          v6 = gsi_ctx;
          if ( *(_BYTE *)a2 == 1 )
            *(_BYTE *)(gsi_ctx + 28591) = *(_BYTE *)(a2 + 1);
          if ( (*(_BYTE *)(a2 + 2) & 1) != 0 )
            *(_DWORD *)(v6 + 28588) = *(_DWORD *)(v6 + 28588) & 0xFFFF7FFF | ((*(_WORD *)(a2 + 4) == 1024) << 15);
          gsihal_write_reg_nk(36, *(unsigned int *)(v6 + 20), 0);
          mutex_unlock(gsi_ctx + 28512);
          return 0;
        }
        else
        {
          dev_err(
            *(_QWORD *)(gsi_ctx + 8),
            "%s:%d bad USB max pkt size dev_hdl=0x%lx sz=%u\n",
            "gsi_write_device_scratch",
            1813,
            a1,
            *(unsigned __int16 *)(a2 + 4));
          return 4294967290LL;
        }
      }
      else
      {
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n",
          "gsi_write_device_scratch",
          1804,
          a1,
          (const void *)gsi_ctx);
        return 4294967290LL;
      }
    }
    else
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d no client registered\n", "gsi_write_device_scratch", 1798);
      return 4294967290LL;
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_write_device_scratch", 1793);
    return 4294967288LL;
  }
}
