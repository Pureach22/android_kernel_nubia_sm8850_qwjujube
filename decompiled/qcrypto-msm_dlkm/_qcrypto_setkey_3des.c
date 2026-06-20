__int64 __fastcall qcrypto_setkey_3des(__int64 a1, __int64 *a2, int a3)
{
  int v3; // w8
  __int64 v4; // x9
  __int64 v5; // x11

  v3 = *(_DWORD *)(a1 + 72);
  if ( (v3 & 1) != 0 )
  {
    printk(&unk_11E8F, "_qcrypto_setkey_3des");
    return 0;
  }
  else
  {
    if ( a3 == 24 )
    {
      *(_DWORD *)(a1 + 224) = 24;
      if ( (v3 & 2) != 0 )
        return 0;
      if ( a2 )
      {
        v4 = a2[2];
        v5 = *a2;
        *(_QWORD *)(a1 + 168) = a2[1];
        *(_QWORD *)(a1 + 176) = v4;
        *(_QWORD *)(a1 + 160) = v5;
        return 0;
      }
      printk(&unk_12422, "_qcrypto_setkey_3des");
    }
    return 4294967274LL;
  }
}
