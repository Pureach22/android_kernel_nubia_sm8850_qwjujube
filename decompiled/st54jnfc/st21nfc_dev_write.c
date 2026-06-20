__int64 __fastcall st21nfc_dev_write(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x21
  __int64 v4; // x20
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x19
  int v7; // w21

  v3 = *(_QWORD *)(a1 + 32);
  if ( a3 >= 0x104 )
    v4 = 260;
  else
    v4 = a3;
  v5 = memdup_user(a2, v4);
  if ( v5 && (v6 = v5, v5 < 0xFFFFFFFFFFFFF001LL) )
  {
    v7 = i2c_transfer_buffer_flags(*(_QWORD *)(v3 - 8), v5, (unsigned int)v4, 0);
    if ( v4 != v7 )
    {
      printk(&unk_8C55, "st21nfc_dev_write");
      v7 = -5;
    }
    kfree(v6);
    return v7;
  }
  else
  {
    printk(&unk_89C1, "st21nfc_dev_write");
    return -14;
  }
}
