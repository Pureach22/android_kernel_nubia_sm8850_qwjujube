__int64 __fastcall sde_rm_update_topology(__int64 a1, __int64 *a2, _DWORD *a3)
{
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x14
  __int64 v6; // x3
  __int64 v7; // x8
  _QWORD *v8; // x1
  __int64 v9; // x0

  if ( !a2 )
    return 4294967274LL;
  if ( a3 )
  {
    v3 = *(_QWORD *)(a1 + 328);
    v4 = 0;
    v5 = v3 + 12;
    while ( *(_DWORD *)(v5 + v4 - 8) != *a3
         || *(_DWORD *)(v5 + v4 - 4) != a3[1]
         || *(_DWORD *)(v5 + v4) != a3[2]
         || *(_DWORD *)(v5 + v4 + 12) != a3[3] )
    {
      v4 += 28;
      if ( v4 == 476 )
        goto LABEL_10;
    }
    v6 = *(unsigned int *)(v3 + v4);
  }
  else
  {
LABEL_10:
    v6 = 0;
  }
  v7 = *a2;
  v8 = a2 + 56;
  if ( v7 )
    v9 = v7 + 3312;
  else
    v9 = 0;
  return msm_property_set_property(v9, v8, 28, v6);
}
