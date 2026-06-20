__int64 __fastcall skb_header_pointer(__int64 result, __int64 a2)
{
  if ( *(_DWORD *)(result + 112) - *(_DWORD *)(result + 116) - 40 >= 2 )
    return *(_QWORD *)(result + 224) + 40LL;
  if ( result )
  {
    if ( (int)skb_copy_bits(result, 40, a2, 2) >= 0 )
      return a2;
    else
      return 0;
  }
  return result;
}
