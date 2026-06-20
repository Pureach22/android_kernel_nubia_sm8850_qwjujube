__int64 __fastcall qcom_mhi_qrtr_ul_callback(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  int v10; // w10

  v2 = *(_QWORD *)(a1 + 192);
  v3 = *(_QWORD *)(*(_QWORD *)a2 + 24LL);
  if ( v3 )
  {
    _X9 = (unsigned int *)(v3 + 128);
    __asm { PRFM            #0x11, [X9] }
    do
      v10 = __ldxr(_X9);
    while ( __stlxr(v10 - 1, _X9) );
    if ( v10 == 1 )
    {
      __dmb(9u);
      sk_free(v3);
    }
    else if ( v10 <= 0 )
    {
      refcount_warn_saturate(v3 + 128, 3);
    }
  }
  consume_skb();
  return complete_all(v2 + 72);
}
