__int64 __fastcall btfmcodec_dequeue_transport(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  unsigned int v4; // w20

  mutex_lock(a1 + 192);
  v2 = skb_dequeue(a1 + 344);
  if ( v2 )
  {
    v3 = v2;
    v4 = **(unsigned __int8 **)(v2 + 224);
    skb_pull();
    sk_skb_reason_drop(0, v3, 2);
    mutex_unlock(a1 + 192);
  }
  else
  {
    mutex_unlock(a1 + 192);
    return 255;
  }
  return v4;
}
