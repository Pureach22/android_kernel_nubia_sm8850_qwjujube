__int64 sub_6EE07C()
{
  atomic_ullong *v0; // x13
  unsigned __int64 v1; // x16

  atomic_fetch_xor_explicit(v0, v1, memory_order_release);
  return target_if_disa_encrypt_decrypt_req();
}
