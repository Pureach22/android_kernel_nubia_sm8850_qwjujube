void *__fastcall skb_put_data_1(__int64 a1, const void *a2, unsigned int a3)
{
  void *v5; // x0

  v5 = (void *)skb_put(a1, a3);
  return memcpy(v5, a2, a3);
}
