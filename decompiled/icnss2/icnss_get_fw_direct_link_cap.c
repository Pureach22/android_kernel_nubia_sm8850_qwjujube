__int64 __fastcall icnss_get_fw_direct_link_cap(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
    LOBYTE(v1) = *(_BYTE *)(v1 + 6152);
  return v1 & 1;
}
