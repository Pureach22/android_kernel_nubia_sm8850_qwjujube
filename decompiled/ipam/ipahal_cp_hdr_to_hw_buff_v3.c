void *__fastcall ipahal_cp_hdr_to_hw_buff_v3(__int64 a1, unsigned int a2, void *src, size_t n)
{
  return memcpy((void *)(a1 + a2), src, (unsigned int)n);
}
