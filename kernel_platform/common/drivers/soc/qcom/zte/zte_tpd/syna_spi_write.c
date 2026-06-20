__int64 __fastcall syna_spi_write(__int64 **a1, const void *a2, __int64 a3)
{
  __int64 *v3; // x23
  __int64 v4; // x20
  unsigned int v5; // w19
  __int64 v7; // x0
  unsigned int v8; // w0
  __int64 v9; // x2
  __int64 v10; // x9
  __int64 v11; // x10
  _QWORD *v12; // x11
  int v13; // w12
  __int64 *v14; // x13
  __int64 v15; // x8
  __int64 *v16; // x0
  __int64 *v17; // x1
  __int64 **v18; // x8
  __int64 v19; // x8
  __int64 **v20; // x0
  __int64 **v21; // x1
  unsigned int v22; // w0
  void *v24; // x0
  struct spi_transfer *xfers;
  struct spi_message msg;
  __int64 v39; // [xsp+78h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  if ( !v3 )
  {
    v24 = unk_3A459;
LABEL_30:
    printk(v24, "syna_spi_write", a3);
    v5 = -6;
    goto LABEL_27;
  }
  v4 = *v3;
  if ( !*v3 )
  {
    v24 = unk_39DDD;
    goto LABEL_30;
  }
  v5 = a3;
  mutex_lock(v3 + 14);
  if ( (_WORD)v5 == 0xFFFF )
  {
    printk(unk_370F6, "syna_spi_write", 0xFFFF);
    v5 = -22;
  }
  else
  {
    if ( *((_DWORD *)v3 + 25) )
      v7 = v5;
    else
      v7 = 1;
    v8 = syna_spi_alloc_mem(v7, v5);
    if ( (v8 & 0x80000000) != 0 )
    {
      v5 = v8;
      printk(unk_35B63, "syna_spi_write", v9);
    }
    else if ( a2 && tx_buf )
    {
      memcpy((void *)tx_buf, a2, v5);
      spi_message_init(&msg);
      xfers = (struct spi_transfer *)xfer;
      if ( *((_DWORD *)v3 + 25) )
      {
        if ( v5 )
        {
          v10 = 0;
          do
          {
            struct spi_transfer *t = &xfers[v10];
            t->len = 1;
            t->tx_buf = tx_buf + v10;
            spi_message_add_tail(t, &msg);
            ++v10;
          }
          while ( v5 != v10 );
        }
      }
      else
      {
        struct spi_transfer *t = xfers;
        t->tx_buf = tx_buf;
        t->len = v5;
        spi_message_add_tail(t, &msg);
      }
      v22 = spi_sync((struct spi_device *)v4, &msg);
      if ( v22 )
      {
        v5 = v22;
        printk(unk_394FC, "syna_spi_write", v22);
      }
    }
    else
    {
      printk(unk_38E4F, "syna_spi_write", v9);
      v5 = -22;
    }
  }
  mutex_unlock(v3 + 14);
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v5;
}
