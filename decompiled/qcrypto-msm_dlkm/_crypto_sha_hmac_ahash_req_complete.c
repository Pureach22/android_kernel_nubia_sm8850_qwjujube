__int64 __fastcall crypto_sha_hmac_ahash_req_complete(__int64 result, __int64 a2)
{
  if ( (_DWORD)a2 != -115 )
    return complete(result, a2);
  return result;
}
