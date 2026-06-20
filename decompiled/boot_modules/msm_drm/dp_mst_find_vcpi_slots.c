__int64 __fastcall dp_mst_find_vcpi_slots(__int64 a1, int a2)
{
  unsigned int v2; // w9
  signed int v3; // w9

  v2 = *(_DWORD *)(*(_QWORD *)(a1 + 88) + 76LL) >> 12;
  v3 = (a2 + v2 - 1) / v2;
  if ( v3 <= 63 )
    return (unsigned int)v3;
  else
    return 4294967268LL;
}
