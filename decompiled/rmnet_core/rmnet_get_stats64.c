__int64 __fastcall rmnet_get_stats64(__int64 result, _QWORD *a2)
{
  char v2; // w16
  unsigned int v3; // w8
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x11
  __int64 v7; // x12
  unsigned __int64 v8; // x16
  unsigned __int64 v9; // x16
  __int64 v10; // x2
  bool v11; // cf
  __int64 v12; // x17

  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  do
  {
    v8 = (unsigned int)(-1LL << v2) & _cpu_possible_mask;
    if ( !(_DWORD)v8 )
      break;
    v9 = __clz(__rbit64(v8));
    v10 = _per_cpu_offset[v9];
    v11 = v9 >= 0x1F;
    v2 = v9 + 1;
    v12 = v10 + *(_QWORD *)(result + 2704);
    v4 += *(_QWORD *)(v12 + 24);
    v5 += *(_QWORD *)(v12 + 16);
    v6 += *(_QWORD *)(v12 + 8);
    v7 += *(_QWORD *)v12;
    v3 += *(_DWORD *)(v12 + 32);
  }
  while ( !v11 );
  *a2 = v7;
  a2[1] = v5;
  a2[2] = v6;
  a2[3] = v4;
  a2[7] = v3;
  return result;
}
