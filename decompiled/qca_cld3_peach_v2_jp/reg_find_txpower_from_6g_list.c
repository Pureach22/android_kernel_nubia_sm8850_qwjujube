__int64 __fastcall reg_find_txpower_from_6g_list(int a1, __int64 a2, _WORD *a3)
{
  __int64 v3; // x8

  v3 = 0;
  *a3 = 0;
  while ( *(_DWORD *)(a2 + v3) != a1 )
  {
    v3 += 36;
    if ( v3 == 2160 )
      return 16;
  }
  *a3 = *(_DWORD *)(a2 + v3 + 16);
  return 0;
}
