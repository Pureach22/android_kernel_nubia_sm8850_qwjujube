__int64 __fastcall st21nfc_ping(__int64 a1)
{
  void *v1; // x0
  unsigned int v2; // w19
  int v5; // w24
  int v6; // w8
  int v7; // w8
  __int64 v8; // x0
  bool v9; // cf
  char v10; // w9
  __int64 v11; // x0

  if ( *(_BYTE *)(a1 + 529) == 1 )
  {
    v1 = &unk_847D;
    v2 = -16;
LABEL_3:
    printk(v1, "st21nfc_ping");
  }
  else
  {
    i2c_transfer_buffer_flags(*(_QWORD *)(a1 + 168), a1 + 256, 1, 1);
    gpiod_set_value(*(_QWORD *)(a1 + 952), 0);
    msleep(20);
    gpiod_set_value(*(_QWORD *)(a1 + 952), 1);
    usleep_range_state(10000, 11000, 2);
    gpiod_set_value(*(_QWORD *)(a1 + 952), 0);
    msleep(20);
    gpiod_set_value(*(_QWORD *)(a1 + 952), 1);
    printk(&unk_8AEA, "st21nfc_ping");
    msleep(10);
    v2 = -19;
    v5 = -4;
    while ( (unsigned int)gpiod_get_value(*(_QWORD *)(a1 + 944)) )
    {
      if ( (unsigned int)i2c_transfer_buffer_flags(*(_QWORD *)(a1 + 168), a1 + 256, 3, 1) == 3 )
      {
        if ( *(_BYTE *)(a1 + 256) == 126 )
        {
          v6 = *(unsigned __int8 *)(a1 + 257);
          if ( v6 == 126 )
          {
            v7 = *(unsigned __int8 *)(a1 + 258);
            if ( v7 == 126 )
            {
              printk(&unk_8A14, "st21nfc_ping");
              return v2;
            }
            v8 = *(_QWORD *)(a1 + 168);
            *(_BYTE *)(a1 + 256) = v7;
            if ( (unsigned int)i2c_transfer_buffer_flags(v8, a1 + 257, 2, 1) != 2 )
            {
              v1 = &unk_850C;
              goto LABEL_3;
            }
          }
          else
          {
            v10 = *(_BYTE *)(a1 + 258);
            v11 = *(_QWORD *)(a1 + 168);
            *(_BYTE *)(a1 + 256) = v6;
            *(_BYTE *)(a1 + 257) = v10;
            if ( (unsigned int)i2c_transfer_buffer_flags(v11, a1 + 258, 1, 1) != 1 )
            {
              v1 = &unk_90E6;
              goto LABEL_3;
            }
          }
        }
        if ( (unsigned int)i2c_transfer_buffer_flags(*(_QWORD *)(a1 + 168), a1 + 259, *(unsigned __int8 *)(a1 + 258), 1) != *(unsigned __int8 *)(a1 + 258) )
        {
          v1 = &unk_880E;
          goto LABEL_3;
        }
        printk(&unk_910E, "st21nfc_ping");
        if ( *(_BYTE *)(a1 + 256) == 96 && !*(_BYTE *)(a1 + 257) )
          v2 = 0;
        msleep(5);
        v9 = __CFADD__(v5++, 1);
        if ( v9 )
          return v2;
      }
      else
      {
        printk(&unk_875E, "st21nfc_ping");
        v9 = __CFADD__(v5++, 1);
        if ( v9 )
          return v2;
      }
    }
  }
  return v2;
}
