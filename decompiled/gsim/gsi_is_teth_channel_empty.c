__int64 __fastcall gsi_is_teth_channel_empty(unsigned __int64 a1, bool *a2)
{
  unsigned int v3; // w20
  int v4; // w21
  int reg_nk; // w8
  __int64 result; // x0

  if ( gsi_ctx )
  {
    v3 = a1;
    if ( a2 && *(unsigned int *)(gsi_ctx + 28608) > a1 )
    {
      v4 = gsihal_read_reg_nk(66, *(unsigned int *)(gsi_ctx + 20), (unsigned int)a1) & 0xFFFFF;
      reg_nk = gsihal_read_reg_nk(121, *(unsigned int *)(gsi_ctx + 20), v3);
      result = 0;
      *a2 = v4 == reg_nk;
    }
    else
    {
      dev_err(
        *(_QWORD *)(gsi_ctx + 8),
        "%s:%d bad params chan_hdl=%lu is_empty=%pK\n",
        "gsi_is_teth_channel_empty",
        4055,
        a1,
        a2);
      return 4294967290LL;
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_is_teth_channel_empty", 4049);
    return 4294967288LL;
  }
  return result;
}
