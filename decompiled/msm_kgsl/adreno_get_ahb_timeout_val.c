__int64 __fastcall adreno_get_ahb_timeout_val(_QWORD *a1, unsigned int a2)
{
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x9
  int v4; // w9
  int v5; // w2

  if ( !a2 )
    return 0;
  v2 = a1[2997] / 0xF4240uLL;
  v3 = v2 * a2;
  if ( v3 )
    v3 = (__PAIR128__(v3, v3 & (v3 - 1)) - 1) >> 64;
  v4 = __clz(v3);
  v5 = 63 - v4;
  if ( (unsigned int)(63 - v4) <= 0x1F && 1000 * v2 <= 1 << v5 )
    return (unsigned int)(62 - v4);
  dev_warn(*a1, "Invalid AHB timeout_val %u\n", v5);
  return 0;
}
