__int64 __fastcall skb_header_pointer(__int64 result, __int64 a2, int a3, __int64 a4)
{
  if ( *(_DWORD *)(result + 112) - (*(_DWORD *)(result + 116) + (int)a2) >= a3 )
    return *(_QWORD *)(result + 224) + (int)a2;
  if ( result )
  {
    if ( (int)skb_copy_bits(result, a2, a4, (unsigned int)a3) >= 0 )
      return a4;
    else
      return 0;
  }
  return result;
}
