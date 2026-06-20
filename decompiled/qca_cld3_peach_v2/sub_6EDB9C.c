double __fastcall sub_6EDB9C(__int64 a1, __int64 a2)
{
  atomic_ullong *v2; // x13
  unsigned __int64 v3; // x16

  atomic_fetch_xor_explicit(v2, v3, memory_order_release);
  return tgt_disa_encrypt_decrypt_req(a1, a2);
}
