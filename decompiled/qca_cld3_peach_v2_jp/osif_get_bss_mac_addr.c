__int64 __fastcall osif_get_bss_mac_addr(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 120);
  if ( v1 )
    return v1 + 48;
  else
    return 0;
}
