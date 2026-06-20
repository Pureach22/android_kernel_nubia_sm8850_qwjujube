__int64 __fastcall gsi_complete_clk_grant(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x0
  void (__fastcall *v6)(_QWORD); // x9

  if ( gsi_ctx )
  {
    if ( (*(_BYTE *)(gsi_ctx + 176) & 1) != 0 )
    {
      if ( gsi_ctx == a1 )
      {
        v4 = raw_spin_lock_irqsave(gsi_ctx + 28560, a2, a3, a4, a1);
        gsi_handle_irq();
        v6 = *(void (__fastcall **)(_QWORD))(gsi_ctx + 120);
        v5 = *(_QWORD *)(gsi_ctx + 128);
        if ( *((_DWORD *)v6 - 1) != -1066802076 )
          __break(0x8229u);
        v6(v5);
        raw_spin_unlock_irqrestore(gsi_ctx + 28560, v4);
        return 0;
      }
      else
      {
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n",
          "gsi_complete_clk_grant",
          1286,
          a1,
          (const void *)gsi_ctx);
        return 4294967290LL;
      }
    }
    else
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d no client registered\n", "gsi_complete_clk_grant", 1280);
      return 4294967290LL;
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_complete_clk_grant", 1275);
    return 4294967288LL;
  }
}
