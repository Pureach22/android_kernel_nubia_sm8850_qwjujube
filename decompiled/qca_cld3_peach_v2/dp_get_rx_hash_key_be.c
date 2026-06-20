__int64 __fastcall dp_get_rx_hash_key_be(__int64 a1, __int64 a2)
{
  get_random_bytes(a2 + 8, 20);
  return get_random_bytes(a2 + 28, 44);
}
