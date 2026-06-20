__int64 __fastcall adreno_coresight_patch_pwrup_reglist(__int64 a1, _DWORD *a2)
{
  unsigned __int64 v2; // x9
  __int64 result; // x0
  __int64 v5; // x8
  signed int v6; // w9
  __int64 v7; // x11

  v2 = *(_QWORD *)(a1 + 20664);
  result = 0;
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( *(_BYTE *)(a1 + 20688) == 1 && (v5 = *(_QWORD *)(a1 + 20672), *(_DWORD *)(v5 + 8)) )
    {
      v6 = 0;
      do
      {
        *a2 = *(_DWORD *)(*(_QWORD *)v5 + 12LL * v6);
        v7 = *(_QWORD *)v5 + 12LL * v6++;
        a2[1] = *(_DWORD *)(v7 + 8);
        a2 += 2;
        result = *(unsigned int *)(v5 + 8);
      }
      while ( v6 < (unsigned int)result );
    }
    else
    {
      return 0;
    }
  }
  return result;
}
