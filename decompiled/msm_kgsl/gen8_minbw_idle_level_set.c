__int64 __fastcall gen8_minbw_idle_level_set(__int64 result, int a2)
{
  int v2; // w10

  if ( (~*(_DWORD *)(*(_QWORD *)(result + 14264) + 32LL) & 0x2000040) == 0 && *(_DWORD *)(result - 816) )
  {
    if ( a2 )
      v2 = 6;
    else
      v2 = 3;
    *(_DWORD *)(result - 816) = v2;
    *(_DWORD *)(result + 23996) = a2;
    *(_BYTE *)(result + 20442) = a2 != 0;
  }
  return result;
}
