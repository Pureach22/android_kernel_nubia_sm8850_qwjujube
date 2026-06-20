__int64 __fastcall hw_fence_index_to_handle(__int64 a1, int a2)
{
  if ( a1 )
    return (*(_DWORD *)(a1 + 12) << 27) | 0x80000000 | a2;
  else
    return a2 | 0x80000000;
}
