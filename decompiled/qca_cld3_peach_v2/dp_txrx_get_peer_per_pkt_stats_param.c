__int64 __fastcall dp_txrx_get_peer_per_pkt_stats_param(__int64 *a1, int a2, __int64 a3)
{
  int v3; // w10
  __int64 *v4; // x8
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x9
  __int64 v9; // x10
  __int64 v10; // x11
  __int64 v11; // x12
  __int64 v12; // x10
  __int64 v13; // x10
  __int64 *v14; // x8
  __int64 v15; // x11
  __int64 v16; // x12
  __int64 v17; // x13
  __int64 v18; // x14
  __int64 v19; // x16
  _QWORD *v20; // x17
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v25; // x9
  __int64 *v26; // x8
  __int64 v27; // x10
  __int64 v28; // x13
  __int64 v29; // x11
  __int64 v30; // x12
  __int64 v31; // x13
  __int64 v32; // x14
  __int64 v33; // x16
  _QWORD *v34; // x17
  __int64 v35; // x0
  __int64 v36; // x1
  __int64 v37; // x3
  __int64 v38; // x4
  __int64 v39; // x9
  __int64 *v40; // x8
  __int64 v41; // x10
  __int64 v42; // x13
  __int64 v43; // x11
  __int64 v44; // x12
  __int64 v45; // x13
  __int64 v46; // x14
  __int64 v47; // x16
  _QWORD *v48; // x17
  __int64 v49; // x0
  __int64 v50; // x1
  __int64 v51; // x3
  __int64 v52; // x4
  __int64 v53; // x9
  __int64 *v54; // x8
  __int64 v55; // x10
  __int64 v56; // x13

  v3 = *((_DWORD *)a1 + 102);
  if ( v3 == 1 && (v4 = (__int64 *)a1[52]) != nullptr )
  {
    v5 = *v4;
    if ( !v5 )
      return 16;
  }
  else
  {
    v5 = *a1;
    if ( !*a1 )
      return 16;
  }
  v7 = *(unsigned __int8 *)(v5 + 2281);
  result = 16;
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      if ( v3 == 1 && (v14 = (__int64 *)a1[52]) != nullptr || (v14 = a1) != nullptr )
      {
        result = 0;
        *(_DWORD *)a3 = *((_DWORD *)v14 + 49);
      }
    }
    else if ( a2 == 3 )
    {
      if ( *(_BYTE *)(v5 + 2281) )
      {
        if ( (_DWORD)v7 == 1 )
        {
          v12 = 0;
          v10 = 0;
          v11 = 0;
        }
        else
        {
          v12 = (unsigned __int8)v7 & 0xFE;
          v29 = 0;
          v30 = 0;
          v31 = 0;
          v32 = 0;
          v33 = v12;
          v34 = (_QWORD *)v5;
          do
          {
            v35 = v34[382];
            v36 = v34[891];
            v33 -= 2;
            v37 = v34[383];
            v38 = v34[892];
            v34 += 1018;
            v31 += v35;
            v32 += v36;
            v29 += v37;
            v30 += v38;
          }
          while ( v33 );
          v10 = v30 + v29;
          v11 = v32 + v31;
          if ( v12 == v7 )
            goto LABEL_43;
        }
        v39 = v7 - v12;
        v40 = (__int64 *)(v5 + 4072LL * (unsigned int)v12 + 3064);
        do
        {
          v41 = *(v40 - 1);
          v42 = *v40;
          --v39;
          v40 += 509;
          v11 += v41;
          v10 += v42;
        }
        while ( v39 );
        goto LABEL_43;
      }
      goto LABEL_20;
    }
  }
  else
  {
    if ( !a2 )
    {
      if ( *(_BYTE *)(v5 + 2281) )
      {
        if ( (_DWORD)v7 == 1 )
        {
          v13 = 0;
          v10 = 0;
          v11 = 0;
        }
        else
        {
          v13 = (unsigned __int8)v7 & 0xFE;
          v43 = 0;
          v44 = 0;
          v45 = 0;
          v46 = 0;
          v47 = v13;
          v48 = (_QWORD *)v5;
          do
          {
            v49 = v48[286];
            v50 = v48[795];
            v47 -= 2;
            v51 = v48[287];
            v52 = v48[796];
            v48 += 1018;
            v45 += v49;
            v46 += v50;
            v43 += v51;
            v44 += v52;
          }
          while ( v47 );
          v10 = v44 + v43;
          v11 = v46 + v45;
          if ( v13 == v7 )
            goto LABEL_43;
        }
        v53 = v7 - v13;
        v54 = (__int64 *)(v5 + 4072LL * (unsigned int)v13 + 2296);
        do
        {
          v55 = *(v54 - 1);
          v56 = *v54;
          --v53;
          v54 += 509;
          v11 += v55;
          v10 += v56;
        }
        while ( v53 );
        goto LABEL_43;
      }
LABEL_20:
      v11 = 0;
      v10 = 0;
      goto LABEL_43;
    }
    if ( a2 == 1 )
    {
      if ( *(_BYTE *)(v5 + 2281) )
      {
        if ( (_DWORD)v7 == 1 )
        {
          v9 = 0;
          v10 = 0;
          v11 = 0;
        }
        else
        {
          v9 = (unsigned __int8)v7 & 0xFE;
          v15 = 0;
          v16 = 0;
          v17 = 0;
          v18 = 0;
          v19 = v9;
          v20 = (_QWORD *)v5;
          do
          {
            v21 = v20[288];
            v22 = v20[797];
            v19 -= 2;
            v23 = v20[289];
            v24 = v20[798];
            v20 += 1018;
            v17 += v21;
            v18 += v22;
            v15 += v23;
            v16 += v24;
          }
          while ( v19 );
          v10 = v16 + v15;
          v11 = v18 + v17;
          if ( v9 == v7 )
            goto LABEL_43;
        }
        v25 = v7 - v9;
        v26 = (__int64 *)(v5 + 4072LL * (unsigned int)v9 + 2312);
        do
        {
          v27 = *(v26 - 1);
          v28 = *v26;
          --v25;
          v26 += 509;
          v11 += v27;
          v10 += v28;
        }
        while ( v25 );
LABEL_43:
        *(_QWORD *)a3 = v11;
        *(_QWORD *)(a3 + 8) = v10;
        return 0;
      }
      goto LABEL_20;
    }
  }
  return result;
}
