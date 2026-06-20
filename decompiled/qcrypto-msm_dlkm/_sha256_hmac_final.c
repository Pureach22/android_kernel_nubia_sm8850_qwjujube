__int64 __fastcall sha256_hmac_final(__int64 a1)
{
  __int64 result; // x0
  int v2; // w19

  if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 56LL) + 19LL) == 1 )
    return sha_final(a1);
  v2 = a1;
  result = sha_hmac_inner_hash();
  if ( !(_DWORD)result )
    return sha_hmac_outer_hash(v2, 0x20u);
  return result;
}
