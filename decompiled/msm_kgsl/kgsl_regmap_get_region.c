__int64 __fastcall kgsl_regmap_get_region(_DWORD *a1, __int64 a2)
{
  int v2; // w8
  unsigned int v3; // w9
  unsigned int v5; // w9
  unsigned int v6; // w9
  unsigned int v7; // w9
  unsigned int v8; // w9
  unsigned int v9; // w9

  v2 = a1[42];
  if ( v2 < 1 )
    return 0;
  v3 = a1[4];
  if ( v3 <= (unsigned int)a2 && a1[5] + v3 > (unsigned int)a2 )
    return (__int64)(a1 + 2);
  if ( v2 == 1 )
    return 0;
  v5 = a1[12];
  if ( v5 <= (unsigned int)a2 && a1[13] + v5 > (unsigned int)a2 )
    return (__int64)(a1 + 10);
  if ( v2 == 2 )
    return 0;
  v6 = a1[20];
  if ( v6 <= (unsigned int)a2 && a1[21] + v6 > (unsigned int)a2 )
    return (__int64)(a1 + 18);
  if ( v2 == 3 )
    return 0;
  v7 = a1[28];
  if ( v7 <= (unsigned int)a2 && a1[29] + v7 > (unsigned int)a2 )
    return (__int64)(a1 + 26);
  if ( v2 == 4 )
    return 0;
  v8 = a1[36];
  if ( v8 <= (unsigned int)a2 && a1[37] + v8 > (unsigned int)a2 )
    return (__int64)(a1 + 34);
  if ( v2 == 5 )
    return 0;
  v9 = a1[44];
  if ( v9 <= (unsigned int)a2 && a1[45] + v9 > (unsigned int)a2 )
    return (__int64)(a1 + 42);
  if ( v2 == 6 )
    return 0;
  __break(0x5512u);
  return kgsl_regmap_valid_offset(a1, a2);
}
