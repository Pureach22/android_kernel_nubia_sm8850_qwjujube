__int64 __fastcall adreno_gmu_bus_ab_quantize(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8
  unsigned __int64 v3; // x8
  int v4; // w8
  bool v5; // zf

  v2 = -65536;
  if ( a2 != 0xFFFF && (*(_BYTE *)(a1 + 24032) & 1) != 0 )
  {
    v3 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 80LL)
                      * *(_DWORD *)(*(_QWORD *)(a1 + 10392) + 4LL * (*(_DWORD *)(a1 + 10400) - 1)));
    if ( (unsigned int)v3 / 0x3E8 <= a2 )
      v4 = 65534;
    else
      v4 = (unsigned __int16)(65536000 * (unsigned __int64)a2 / v3);
    v5 = v4 == 0;
    v2 = (v4 << 16) | 0x100;
    v5 = !v5 || a2 == 0;
    if ( !v5 )
      return 65792;
  }
  return v2;
}
