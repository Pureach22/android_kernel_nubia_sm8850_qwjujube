__int64 __fastcall adreno_hwsched_get_payload_rb_key_legacy(__int64 a1, int a2, int a3)
{
  _DWORD *v3; // x8
  int v4; // w9
  unsigned int v5; // w10
  unsigned int v6; // w9
  unsigned __int16 *v7; // x11
  int v8; // w13
  unsigned __int64 v9; // x11
  unsigned __int64 v10; // x13
  unsigned __int64 v11; // x10

  v3 = *(_DWORD **)(a1 + 22792);
  if ( !*v3 )
    return 0;
  v4 = (*v3 >> 6) & 0x3FC;
  v5 = v4 - 20;
  if ( v4 == 20 )
    return 0;
  v6 = 0;
  while ( 1 )
  {
    v7 = (unsigned __int16 *)((char *)v3 + v6 + 20);
    v8 = *v7;
    v9 = v7[1];
    if ( v8 == 2 )
      break;
LABEL_5:
    v6 += 4 * v9 + 4;
    if ( v6 >= v5 )
      return 0;
  }
  if ( !(_DWORD)v9 )
  {
    if ( !a2 )
      return 0;
    goto LABEL_5;
  }
  v10 = 0;
  while ( *(_DWORD *)((char *)&v3[v10 + 6] + v6) != 1 )
  {
    v10 += 2LL;
    if ( v10 >= v9 )
    {
      if ( a2 )
        goto LABEL_5;
      goto LABEL_14;
    }
  }
  if ( *(_DWORD *)((char *)&v3[v10 + 7] + v6) != a2 )
    goto LABEL_5;
LABEL_14:
  v11 = 0;
  while ( *(_DWORD *)((char *)&v3[v11 + 6] + v6) != a3 )
  {
    v11 += 2LL;
    if ( v11 >= v9 )
      return 0;
  }
  return *(unsigned int *)((char *)&v3[v11 + 7] + v6);
}
