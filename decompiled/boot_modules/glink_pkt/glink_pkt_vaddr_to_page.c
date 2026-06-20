unsigned __int64 __fastcall glink_pkt_vaddr_to_page(__int64 a1)
{
  if ( (is_vmalloc_addr() & 1) != 0 )
    return vmalloc_to_page(a1);
  else
    return ((unsigned __int64)((a1 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
}
