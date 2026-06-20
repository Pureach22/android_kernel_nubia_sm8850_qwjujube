__int64 __fastcall i2c_w_bytes(__int64 a1, char a2, const void *a3, unsigned int a4)
{
  __int64 v8; // x24
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  _BYTE *v13; // x20
  unsigned __int64 v14; // x1
  unsigned int v15; // w21
  unsigned __int64 StatusReg; // x25
  __int64 v18; // x26

  v8 = a4 + 1;
  v9 = _kmalloc_noprof(v8, 3264);
  v13 = (_BYTE *)v9;
  if ( v8 )
  {
    while ( 1 )
    {
      *v13 = a2;
      v14 = v8 ? v8 - 1 : 0LL;
      if ( v14 >= a4 )
        break;
      _fortify_panic(17);
      v8 = a4 + 1;
      StatusReg = _ReadStatusReg(SP_EL0);
      v18 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v9 = _kmalloc_noprof(v8, 3264);
      v13 = (_BYTE *)v9;
      *(_QWORD *)(StatusReg + 80) = v18;
      if ( a4 == -1 )
        goto LABEL_10;
    }
    memcpy(v13 + 1, a3, a4);
    v15 = i2c_transfer_buffer_flags(*(_QWORD *)(a1 + 808), v13, a4 + 1, 0);
    if ( (v15 & 0x80000000) != 0 )
      printk(&unk_15520, "haptic_hv", 122, "i2c_w_bytes");
    kfree(v13);
    return v15;
  }
  else
  {
LABEL_10:
    __break(1u);
    return i2c_w_bits(v9, v10, v11, v12);
  }
}
