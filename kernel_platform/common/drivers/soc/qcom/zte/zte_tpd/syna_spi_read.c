__int64 __fastcall syna_spi_read(__int64 **a1, void *a2, __int64 a3)
{
  __int64 *v3; // x22
  __int64 v4; // x21
  unsigned int v5; // w19
  __int64 v7; // x0
  unsigned int v8; // w0
  __int64 v9; // x2
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x11
  _QWORD *v13; // x12
  int v14; // w13
  __int64 *v15; // x14
  __int64 v16; // x8
  __int64 *v17; // x0
  __int64 *v18; // x1
  __int64 **v19; // x8
  __int64 v20; // x8
  unsigned int v24; // w0
  __int64 v25; // x2
  void *v27; // x0
  struct spi_transfer *xfers;
  struct spi_message msg;
  __int64 v42; // [xsp+78h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  if ( !v3 )
  {
    v27 = unk_3A459;
LABEL_30:
    printk(v27, "syna_spi_read", a3);
    v5 = -6;
    goto LABEL_27;
  }
  v4 = *v3;
  if ( !*v3 )
  {
    v27 = unk_39DDD;
    goto LABEL_30;
  }
  v5 = a3;
  mutex_lock(v3 + 14);
  if ( (_WORD)v5 == 0xFFFF )
  {
    printk(unk_325AE, "syna_spi_read", 0xFFFF);
LABEL_35:
    v5 = -22;
    goto LABEL_26;
  }
  if ( *((_DWORD *)v3 + 25) )
    v7 = v5;
  else
    v7 = 1;
  v8 = syna_spi_alloc_mem(v7, v5);
  if ( (v8 & 0x80000000) != 0 )
  {
    v5 = v8;
    printk(unk_3BFF0, "syna_spi_read", v9);
    goto LABEL_26;
  }
  spi_message_init(&msg);
  xfers = (struct spi_transfer *)xfer;
  if ( *((_DWORD *)v3 + 25) )
  {
    *(_BYTE *)tx_buf = -1;
    if ( v5 )
    {
      v10 = 0;
      do
      {
        struct spi_transfer *t = &xfers[v10];
        t->len = 1;
        t->tx_buf = tx_buf;
        t->rx_buf = rx_buf + v10;
        spi_message_add_tail(t, &msg);
        ++v10;
      }
      while ( v5 != v10 );
    }
  }
  else
  {
    memset((void *)tx_buf, 255, v5);
    struct spi_transfer *t = xfers;
    t->tx_buf = tx_buf;
    t->rx_buf = rx_buf;
    t->len = v5;
    spi_message_add_tail(t, &msg);
  }
  v24 = spi_sync((struct spi_device *)v4, &msg);
  if ( v24 )
  {
    v5 = v24;
    printk(unk_355EA, "syna_spi_read", v24);
    goto LABEL_26;
  }
  if ( !a2 || !rx_buf )
  {
    printk(unk_3AB30, "syna_spi_read", v25);
    goto LABEL_35;
  }
  memcpy(a2, (const void *)rx_buf, v5);
LABEL_26:
  mutex_unlock(v3 + 14);
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v5;
}
