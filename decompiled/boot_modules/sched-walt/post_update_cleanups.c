__int64 __fastcall post_update_cleanups(__int64 result)
{
  _DWORD *v1; // x9
  char v2; // w12
  unsigned __int64 v3; // x12
  unsigned __int64 v4; // x12
  __int64 v5; // x13
  bool v6; // cf
  char *v7; // x13

  v1 = *(_DWORD **)result;
  v2 = 0;
  do
  {
    v3 = (unsigned int)(-1LL << v2) & *v1;
    if ( !(_DWORD)v3 )
      break;
    v4 = __clz(__rbit64(v3));
    v5 = *((_QWORD *)&_per_cpu_offset + v4);
    v6 = v4 >= 0x1F;
    v2 = v4 + 1;
    v7 = (char *)&waltgov_cpu + v5;
    *(_DWORD *)(v7 + 79) = 0;
    *((_DWORD *)v7 + 19) = 0;
  }
  while ( !v6 );
  *(_BYTE *)(result + 397) = 0;
  *(_WORD *)(result + 395) = 0;
  return result;
}
