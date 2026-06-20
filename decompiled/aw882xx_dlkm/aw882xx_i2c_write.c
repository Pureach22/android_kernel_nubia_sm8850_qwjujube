__int64 __fastcall aw882xx_i2c_write(__int64 a1, char a2, unsigned int a3)
{
  unsigned int v4; // w25
  int v6; // w22
  __int64 v7; // x28
  unsigned int v8; // w27
  __int64 v9; // x1
  __int64 v10; // x1
  __int64 v12; // x1

  v4 = bswap32(a3) >> 16;
  v6 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v7 = _kmalloc_cache_noprof(i2c_transfer_buffer_flags, 3264, 3);
    if ( !v7 )
    {
      v8 = -12;
      v10 = *(_QWORD *)(a1 + 144);
      if ( v10 )
        goto LABEL_2;
      goto LABEL_8;
    }
    *(_BYTE *)v7 = a2;
    *(_WORD *)(v7 + 1) = v4;
    v8 = i2c_transfer_buffer_flags(a1, v7, 3, 0);
    if ( (v8 & 0x80000000) == 0 )
      break;
    v9 = *(_QWORD *)(a1 + 144);
    if ( !v9 )
      v9 = *(_QWORD *)(a1 + 32);
    printk(&unk_27620, v9, "aw882xx_i2c_writes");
    kfree(v7);
    v10 = *(_QWORD *)(a1 + 144);
    if ( v10 )
      goto LABEL_2;
LABEL_8:
    v10 = *(_QWORD *)(a1 + 32);
LABEL_2:
    printk(&unk_27238, v10, "aw882xx_i2c_write");
    if ( ++v6 == 5 )
      return v8;
  }
  kfree(v7);
  if ( g_print_dbg )
  {
    v12 = *(_QWORD *)(a1 + 144);
    if ( !v12 )
      v12 = *(_QWORD *)(a1 + 32);
    printk(&unk_23D1E, v12, "aw882xx_i2c_write");
  }
  return v8;
}
