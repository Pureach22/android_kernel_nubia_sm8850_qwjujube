void __fastcall lim_sta_add_bss_update_ht_parameter(__int64 a1, __int64 a2, __int64 a3, char a4, __int64 a5)
{
  int v5; // w8

  if ( *(_BYTE *)a2 )
  {
    *(_BYTE *)(a5 + 17) = *(_BYTE *)a2;
    if ( *(_BYTE *)a3 )
    {
      if ( (a4 & 1) != 0 && (*(_WORD *)(a2 + 1) & 2) != 0 )
        v5 = (*(_DWORD *)(a3 + 2) >> 2) & 1;
      else
        v5 = 0;
      *(_DWORD *)(a5 + 296) = v5;
    }
  }
}
