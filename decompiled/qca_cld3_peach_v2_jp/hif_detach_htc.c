__int64 __fastcall hif_detach_htc(int a1)
{
  qdf_mem_set(a1 + 29048, 0x30u, 0);
  return qdf_mem_set(a1 + 29096, 0x30u, 0);
}
