__int64 __fastcall qdf_nbuf_unshare(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x20

  if ( (*(_BYTE *)(result + 126) & 1) != 0
    && (unsigned __int16)*(_DWORD *)(*(_QWORD *)(result + 216) + *(unsigned int *)(result + 212) + 32LL) != 1 )
  {
    v1 = result;
    v2 = skb_copy(result, 2080);
    if ( v2 )
    {
      v3 = v2;
      consume_skb(v1);
      return v3;
    }
    else
    {
      sk_skb_reason_drop(0, v1, 2);
      return 0;
    }
  }
  return result;
}
