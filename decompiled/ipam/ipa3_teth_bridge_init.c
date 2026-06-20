__int64 __fastcall ipa3_teth_bridge_init(__int64 a1)
{
  if ( a1 )
  {
    *(_QWORD *)a1 = teth_bridge_ipa_cb;
    *(_QWORD *)(a1 + 8) = 0;
    *(_BYTE *)(a1 + 20) = 1;
    return 0;
  }
  else
  {
    printk(&unk_3B6579, "ipa3_teth_bridge_init");
    return 4294967274LL;
  }
}
