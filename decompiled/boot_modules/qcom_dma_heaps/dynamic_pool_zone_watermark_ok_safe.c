__int64 __fastcall dynamic_pool_zone_watermark_ok_safe(_QWORD *a1, int a2, __int64 a3, unsigned int a4)
{
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x8
  __int64 v6; // x8
  char v7; // w12
  unsigned __int64 v8; // x12
  unsigned __int64 v9; // x12
  __int64 v10; // x13
  bool v11; // cf
  int v12; // w8
  _QWORD *i; // x9

  v4 = a1[184];
  v5 = a1[192] & ~((__int64)a1[192] >> 63);
  if ( v4 && v5 < v4 )
  {
    v6 = a1[192];
    v7 = 0;
    do
    {
      v8 = _cpu_online_mask & (unsigned __int64)(-1LL << v7);
      if ( !v8 )
        break;
      v9 = __clz(__rbit64(v8));
      v10 = _per_cpu_offset[v9];
      v11 = v9 >= 0x1F;
      v7 = v9 + 1;
      v6 += *(char *)(v10 + a1[12]);
    }
    while ( !v11 );
    v5 = v6 & ~(v6 >> 63);
  }
  if ( a4 < 3 )
  {
    if ( (__int64)(v5 - (a1[5] + (a1[202] & ~((__int64)a1[202] >> 63)) + (unsigned int)~(-1 << a2))) <= a1[a4 + 7] + a3 )
      return 0;
    if ( !a2 )
      return 1;
    if ( a2 > 9 )
      return 0;
    if ( (unsigned int)a2 <= 0xB )
    {
      v12 = a2 - 1;
      for ( i = &a1[13 * (unsigned int)a2 + 32];
            !i[12] || i == (_QWORD *)*i && i + 2 == (_QWORD *)i[2] && i + 4 == (_QWORD *)i[4];
            i += 13 )
      {
        if ( ++v12 >= 9 )
          return 0;
      }
      return 1;
    }
  }
  __break(0x5512u);
  return qcom_system_heap_free();
}
