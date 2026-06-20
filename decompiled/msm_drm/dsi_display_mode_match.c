__int64 __fastcall dsi_display_mode_match(__int64 a1, __int64 a2, char a3)
{
  unsigned int v3; // w8

  if ( !(a1 | a2) )
    return 1;
  v3 = 0;
  if ( !a1 || !a2 )
    return v3;
  if ( (a3 & 3) == 0 )
    return ((a3 & 4) == 0
         || *(unsigned __int8 *)(*(_QWORD *)(a1 + 184) + 3400LL) == *(unsigned __int8 *)(*(_QWORD *)(a2 + 184) + 3400LL))
        && ((a3 & 8) == 0 || *(_DWORD *)(a1 + 164) == *(_DWORD *)(a2 + 164));
  if ( (a3 & 1) != 0 )
  {
    if ( *(_DWORD *)a1 != *(_DWORD *)a2
      || *(_DWORD *)(a1 + 24) != *(_DWORD *)(a2 + 24)
      || *(_DWORD *)(a1 + 44) != *(_DWORD *)(a2 + 44) )
    {
      return 0;
    }
    if ( (a3 & 2) != 0 )
    {
LABEL_7:
      if ( *(_DWORD *)(a1 + 4) != *(_DWORD *)(a2 + 4)
        || *(_DWORD *)(a1 + 12) != *(_DWORD *)(a2 + 12)
        || *(_DWORD *)(a1 + 8) != *(_DWORD *)(a2 + 8)
        || *(_DWORD *)(a1 + 16) != *(_DWORD *)(a2 + 16)
        || *(_DWORD *)(a1 + 28) != *(_DWORD *)(a2 + 28)
        || *(_DWORD *)(a1 + 36) != *(_DWORD *)(a2 + 36)
        || *(_DWORD *)(a1 + 32) != *(_DWORD *)(a2 + 32) )
      {
        return 0;
      }
    }
    return ((a3 & 4) == 0
         || *(unsigned __int8 *)(*(_QWORD *)(a1 + 184) + 3400LL) == *(unsigned __int8 *)(*(_QWORD *)(a2 + 184) + 3400LL))
        && ((a3 & 8) == 0 || *(_DWORD *)(a1 + 164) == *(_DWORD *)(a2 + 164));
  }
  if ( (a3 & 2) != 0 )
    goto LABEL_7;
  return 0;
}
