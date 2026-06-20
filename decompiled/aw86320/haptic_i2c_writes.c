__int64 __fastcall haptic_i2c_writes(__int64 a1, unsigned __int8 a2, const void *a3, unsigned int a4)
{
  __int64 v8; // x24
  unsigned __int8 *v9; // x20
  __int64 v10; // x5
  __int64 v11; // x6
  unsigned int v12; // w21
  unsigned __int64 StatusReg; // x25
  __int64 v14; // x26

  v8 = a4 + 1;
  v9 = (unsigned __int8 *)_kmalloc_noprof(v8, 3264);
  if ( !v9 )
    return (unsigned int)-12;
  while ( 1 )
  {
    if ( !v8 )
    {
      __break(1u);
      goto LABEL_8;
    }
    *v9 = a2;
    if ( v8 - 1 >= (unsigned __int64)a4 )
      break;
LABEL_8:
    _fortify_panic(17);
    v8 = a4 + 1;
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v9 = (unsigned __int8 *)_kmalloc_noprof(v8, 3264);
    *(_QWORD *)(StatusReg + 80) = v14;
    if ( !v9 )
      return (unsigned int)-12;
  }
  memcpy(v9 + 1, a3, a4);
  v12 = i2c_transfer_buffer_flags(*(_QWORD *)(a1 + 488), v9, a4 + 1, 0);
  if ( (v12 & 0x80000000) != 0 )
    printk(&unk_9EAD, "aw86320", 52, "haptic_i2c_writes", a2, v10, v11);
  kfree(v9);
  return v12;
}
