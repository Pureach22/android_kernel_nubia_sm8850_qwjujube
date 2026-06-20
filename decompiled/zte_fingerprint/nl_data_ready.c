__int64 __fastcall nl_data_ready(__int64 a1)
{
  __int64 v2; // x19
  __int64 v4; // x19
  __int64 v5; // x1
  unsigned int v11; // w9

  _X8 = (unsigned int *)(a1 + 236);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 + 1, _X8) );
  if ( v11 )
  {
    if ( (((v11 + 1) | v11) & 0x80000000) == 0 )
      goto LABEL_3;
    v4 = a1;
    v5 = 1;
  }
  else
  {
    v4 = a1;
    v5 = 2;
  }
  refcount_warn_saturate(a1 + 236, v5);
  a1 = v4;
LABEL_3:
  if ( *(_DWORD *)(a1 + 112) >= 0x10u )
  {
    v2 = a1;
    pid = *(_DWORD *)(*(_QWORD *)(a1 + 224) + 12LL);
    printk(&unk_9580);
    sk_skb_reason_drop(0, v2, 2);
  }
  return printk(&unk_8BF5);
}
