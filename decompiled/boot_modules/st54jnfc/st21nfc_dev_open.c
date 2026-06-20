__int64 __fastcall st21nfc_dev_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a2 + 32);
  if ( *(_BYTE *)(v2 + 353) == 1 )
  {
    printk(&unk_847D, "st21nfc_dev_open");
    return 4294967280LL;
  }
  else
  {
    *(_BYTE *)(v2 + 353) = 1;
    return 0;
  }
}
