__int64 ieee80211_free_ack_frame()
{
  if ( (ieee80211_free_ack_frame___already_done & 1) == 0 )
  {
    ieee80211_free_ack_frame___already_done = 1;
    _warn_printk("Have pending ack frames!\n");
    __break(0x800u);
  }
  sk_skb_reason_drop(0);
  return 0;
}
