__int64 __fastcall extract_sar_cap_service_ready_ext_tlv(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  if ( !a2 )
    return 4;
  v3 = *(_QWORD *)(a2 + 144);
  if ( v3 )
    LODWORD(v3) = *(_DWORD *)(v3 + 4);
  *(_DWORD *)(a3 + 168) = v3;
  return 0;
}
