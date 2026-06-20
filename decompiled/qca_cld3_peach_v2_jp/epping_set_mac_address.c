__int64 __fastcall epping_set_mac_address(__int64 a1, __int64 a2)
{
  qdf_mem_copy((void *)(a1 + 2712), (const void *)(a2 + 2), 6u);
  dev_addr_mod(a1, 0, a2 + 2, 6);
  return 0;
}
