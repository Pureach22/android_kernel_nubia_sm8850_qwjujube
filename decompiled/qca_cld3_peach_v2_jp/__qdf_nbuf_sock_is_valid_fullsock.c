__int64 __fastcall _qdf_nbuf_sock_is_valid_fullsock(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 24);
  if ( !v1 )
    return 0;
  result = 1;
  if ( ((1 << *(_BYTE *)(v1 + 18)) & 0xFFFFEFBF) == 0 )
    return 0;
  return result;
}
