__int64 __fastcall qcrypto_setkey_des(__int64 a1, _QWORD *a2, int a3)
{
  int v3; // w8

  if ( a2 )
  {
    v3 = *(_DWORD *)(a1 + 72);
    if ( (v3 & 1) != 0 )
    {
      printk(&unk_11D59, "_qcrypto_setkey_des");
    }
    else
    {
      if ( a3 != 8 )
        return 4294967274LL;
      *(_DWORD *)(a1 + 224) = 8;
      if ( (v3 & 2) == 0 )
      {
        *(_QWORD *)(a1 + 160) = *a2;
        return 0;
      }
    }
    return 0;
  }
  else
  {
    printk(&unk_12422, "_qcrypto_setkey_des");
    return 4294967274LL;
  }
}
