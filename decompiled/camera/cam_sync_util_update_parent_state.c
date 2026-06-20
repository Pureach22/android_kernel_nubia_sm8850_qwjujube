__int64 __fastcall cam_sync_util_update_parent_state(__int64 a1, int a2)
{
  int v2; // w8

  v2 = *(_DWORD *)(a1 + 104);
  if ( (unsigned int)(v2 - 3) < 2 )
    return 0;
  if ( (unsigned int)(v2 - 1) <= 1 )
  {
    *(_DWORD *)(a1 + 104) = a2;
    return 0;
  }
  return 4294967274LL;
}
