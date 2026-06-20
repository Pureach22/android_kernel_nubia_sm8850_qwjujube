__int64 __fastcall charging_enabled_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v7; // w2

  if ( (unsigned int)kstrtobool(a3, a1 + 1038) )
    return -22;
  if ( *(_BYTE *)(a1 + 1038) )
    v7 = -1;
  else
    v7 = 49000;
  usb_psy_set_icl((_DWORD *)(a1 - 8), 5, v7);
  printk(&unk_11EA4, "charging_enabled_store", 5);
  return a4;
}
