__int64 __fastcall get_data_interval_from_si(__int64 a1, unsigned int a2)
{
  __int64 v2; // x9
  __int64 result; // x0
  unsigned int v4; // w8
  unsigned int v5; // w9
  unsigned int v6; // w10
  unsigned int v7; // w10
  bool v8; // cf

  v2 = *(_QWORD *)(a1 + 8);
  result = 4294967274LL;
  if ( *(_DWORD *)(v2 + 28) <= 2u )
    v4 = 1000;
  else
    v4 = 125;
  v5 = a2 / v4;
  if ( !(a2 % v4) )
  {
    v6 = __clz(__rbit32(v5));
    if ( v4 <= a2 )
      v7 = v6 + 1;
    else
      v7 = 0;
    if ( v5 >> v7 )
      v8 = 1;
    else
      v8 = v7 >= 0x11;
    if ( v8 || v4 > a2 )
      return 4294967274LL;
    else
      return v7 - 1;
  }
  return result;
}
