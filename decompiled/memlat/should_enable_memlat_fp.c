bool should_enable_memlat_fp()
{
  __int64 v1; // x9
  __int64 v2; // x9
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x8

  if ( *(_DWORD *)(memlat_data + 292) < *(_DWORD *)(memlat_data + 288) )
    return 0;
  v1 = *(_QWORD *)(memlat_data + 248);
  if ( v1 && (*(_BYTE *)(v1 + 52) & 1) != 0 )
    return 1;
  v2 = *(_QWORD *)(memlat_data + 256);
  if ( v2 && (*(_BYTE *)(v2 + 52) & 1) != 0 )
    return 1;
  v3 = *(_QWORD *)(memlat_data + 264);
  if ( v3 && (*(_BYTE *)(v3 + 52) & 1) != 0 )
    return 1;
  v4 = *(_QWORD *)(memlat_data + 272);
  if ( v4 && (*(_BYTE *)(v4 + 52) & 1) != 0 )
    return 1;
  v5 = *(_QWORD *)(memlat_data + 280);
  return v5 && (*(_BYTE *)(v5 + 52) & 1) != 0;
}
