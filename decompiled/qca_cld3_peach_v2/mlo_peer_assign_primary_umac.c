__int64 __fastcall mlo_peer_assign_primary_umac(_BYTE *a1, _BYTE *a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x9
  int v14; // w8
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x9
  __int64 v20; // x9
  __int64 v21; // x10
  _BOOL4 v22; // w9
  __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x9
  int v26; // w9
  __int64 v27; // x10
  __int64 v28; // x10
  __int64 v29; // x10
  __int64 v30; // x10
  int v31; // w10

  result = wlan_objmgr_get_mlo_ctx();
  if ( !result )
    return qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: MLO context is Null",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "mlo_peer_assign_primary_umac");
  v13 = *(_QWORD *)a2;
  v14 = (unsigned __int8)a1[186];
  if ( v14 != 255 )
  {
    if ( *(_BYTE *)(*(_QWORD *)a2 + 88LL) && (unsigned __int8)a1[97] >= 2u && *(_BYTE *)(result + 378) == 1 )
      goto LABEL_38;
    v18 = *(_QWORD *)(v13 + 96);
    if ( !v18 )
      goto LABEL_38;
    v19 = *(_QWORD *)(v18 + 216);
    if ( !v19 )
      goto LABEL_38;
    v20 = *(_QWORD *)(v19 + 80);
    if ( !v20 || *(unsigned __int8 *)(v20 + 48) != v14 )
      goto LABEL_38;
    v21 = *((_QWORD *)a1 + 2);
    v22 = 1;
    if ( a1 + 16 != a2 && v21 )
    {
      v23 = *(_QWORD *)(v21 + 96);
      if ( v23 && (v24 = *(_QWORD *)(v23 + 216)) != 0 && (v25 = *(_QWORD *)(v24 + 80)) != 0 )
        v26 = *(unsigned __int8 *)(v25 + 48);
      else
        v26 = 255;
      v22 = v26 != v14 || a1[31] == 0;
    }
    v27 = *((_QWORD *)a1 + 7);
    if ( a1 + 56 != a2
      && v27
      && ((v28 = *(_QWORD *)(v27 + 96)) == 0
       || (v29 = *(_QWORD *)(v28 + 216)) == 0
       || (v30 = *(_QWORD *)(v29 + 80)) == 0
        ? (v31 = 255)
        : (v31 = *(unsigned __int8 *)(v30 + 48)),
          v31 == v14) )
    {
      if ( (v22 & ((unsigned __int8)a1[71] ^ 1) & 1) == 0 )
        goto LABEL_38;
    }
    else if ( !v22 )
    {
      goto LABEL_38;
    }
    a2[15] = 1;
    return result;
  }
  if ( !*(_BYTE *)(*(_QWORD *)a2 + 88LL) )
  {
LABEL_38:
    a2[15] = 0;
    return result;
  }
  a2[15] = 1;
  v15 = *(_QWORD *)(v13 + 96);
  if ( v15 && (v16 = *(_QWORD *)(v15 + 216)) != 0 && (v17 = *(_QWORD *)(v16 + 80)) != 0 )
    a1[186] = *(_BYTE *)(v17 + 48);
  else
    a1[186] = -1;
  return result;
}
