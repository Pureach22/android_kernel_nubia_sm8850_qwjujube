__int64 __fastcall skb_header_pointer(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  if ( *(_DWORD *)(a1 + 112) - (*(_DWORD *)(a1 + 116) + (int)a2) >= a3 )
    return *(_QWORD *)(a1 + 224) + (unsigned int)a2;
  if ( (int)skb_copy_bits(a1, a2) >= 0 )
    return a4;
  return 0;
}
