__int64 __fastcall extract_nan_msg_tlv(__int64 *a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned int v3; // w9
  __int64 v6; // x9

  v2 = *a1;
  v3 = *(_DWORD *)(*a1 + 4);
  if ( v3 - 401 < 0xFFFFFE70 )
    return 16;
  if ( v3 > *((_DWORD *)a1 + 6) )
    return 16;
  *(_DWORD *)(a2 + 8) = v3;
  v6 = a1[2];
  *(_QWORD *)a2 = v6;
  *(_BYTE *)(v6 + (unsigned int)(*(_DWORD *)(v2 + 4) - 1)) = 0;
  return 0;
}
