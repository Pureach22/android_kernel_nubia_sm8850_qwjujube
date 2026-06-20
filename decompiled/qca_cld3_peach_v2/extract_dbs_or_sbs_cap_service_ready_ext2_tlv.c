__int64 __fastcall extract_dbs_or_sbs_cap_service_ready_ext2_tlv(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x8

  if ( !a2 )
    return 4;
  v3 = *(_QWORD *)(a2 + 144);
  if ( !v3 )
    return 4;
  *a3 = *(_DWORD *)(v3 + 8);
  return 0;
}
