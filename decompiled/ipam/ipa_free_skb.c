__int64 __fastcall ipa_free_skb(_QWORD *a1)
{
  _QWORD *v2; // x20
  __int64 v3; // x2
  _QWORD *v4; // x1
  __int64 v5; // x8

  raw_spin_lock_bh(ipa3_ctx + 34608);
  ++*(_DWORD *)(ipa3_ctx + 34624);
  ipa3_skb_recycle(*a1);
  v2 = a1 - 2;
  skb_put(*a1, 2048);
  v3 = ipa3_ctx + 34632;
  v4 = *(_QWORD **)(ipa3_ctx + 34640);
  if ( a1 - 2 == (_QWORD *)(ipa3_ctx + 34632) || v2 == v4 || *v4 != v3 )
  {
    _list_add_valid_or_report(a1 - 2, v4);
  }
  else
  {
    *(_QWORD *)(ipa3_ctx + 34640) = v2;
    *(a1 - 2) = v3;
    *(a1 - 1) = v4;
    *v4 = v2;
  }
  v5 = ipa3_ctx;
  ++*(_DWORD *)(ipa3_ctx + 34620);
  return raw_spin_unlock_bh(v5 + 34608);
}
