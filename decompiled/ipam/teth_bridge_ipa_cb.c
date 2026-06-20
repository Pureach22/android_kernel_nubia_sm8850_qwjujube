__int64 __fastcall teth_bridge_ipa_cb(__int64 a1, int a2, __int64 a3)
{
  __int64 result; // x0

  if ( a2 )
  {
    result = printk(&unk_3E4CAA, "teth_bridge_ipa_cb");
    __break(0x800u);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&teth_bridge_ipa_cb__rs, "teth_bridge_ipa_cb") )
      printk(&unk_3FC866, "teth_bridge_ipa_cb");
    return dev_kfree_skb_any_reason(a3, 2);
  }
  return result;
}
