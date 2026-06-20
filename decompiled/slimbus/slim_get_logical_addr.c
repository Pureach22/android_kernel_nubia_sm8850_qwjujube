__int64 __fastcall slim_get_logical_addr(__int64 a1)
{
  if ( (*(_BYTE *)(a1 + 933) & 1) != 0 )
    return 0;
  else
    return slim_device_alloc_laddr(a1, 0);
}
