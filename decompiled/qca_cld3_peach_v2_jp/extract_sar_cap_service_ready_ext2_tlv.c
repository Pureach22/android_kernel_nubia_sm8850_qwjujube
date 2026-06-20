__int64 __fastcall extract_sar_cap_service_ready_ext2_tlv(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v4; // w8

  if ( !a2 || !*(_DWORD *)(a2 + 280) )
    return 4;
  v3 = *(_QWORD *)(a2 + 272);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    if ( v4 == 1 )
      LODWORD(v3) = 1;
    else
      LODWORD(v3) = 2 * (v4 == 2);
  }
  *(_DWORD *)(a3 + 92) = v3;
  return 0;
}
