__int64 __fastcall walt_cpu_frequency_limits(__int64 a1, _DWORD *a2)
{
  int v2; // w18
  __int64 v3; // x28
  __int64 v4; // x9
  char v6; // w8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x20
  __int64 result; // x0

  if ( (walt_disabled & 1) == 0 )
  {
    v4 = (unsigned int)a2[7];
    if ( (unsigned int)v4 >= 0x20 )
    {
      __break(0x5512u);
      *(_DWORD *)(v3 + 144) = v2;
      JUMPOUT(0x281E4);
    }
    v6 = 0;
    *(_DWORD *)(*(_QWORD *)((char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v4) + 8) + 44LL) = a2[14];
    do
    {
      v7 = (unsigned int)(-1LL << v6) & a2[2];
      if ( !(_DWORD)v7 )
        break;
      v8 = __clz(__rbit64(v7));
      result = update_cpu_capacity_helper((unsigned int)v8);
      v6 = v8 + 1;
    }
    while ( v8 < 0x1F );
  }
  return result;
}
