__int64 __fastcall ipa3_odu_rx_pyld_hdlr(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  _DWORD *v4; // x8
  __int64 v5; // x0

  v2 = *(_QWORD *)(a2 + 1624);
  v4 = *(_DWORD **)(v2 + 376);
  if ( v4 )
  {
    v5 = *(_QWORD *)(v2 + 368);
    if ( *(v4 - 1) != 420538815 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64))v4)(v5, 0, a1);
  }
  else
  {
    dev_kfree_skb_any_reason(a1, 2);
    _warn_printk("client notify is null");
    __break(0x800u);
  }
  return 0;
}
