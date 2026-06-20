__int64 __fastcall dp_txrx_get_peer_per_pkt_stats_param(__int64 *a1, int a2, __int64 a3)
{
  __int64 v3; // x10
  __int64 v4; // x9
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x11
  __int64 v9; // x12
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x11
  __int64 v13; // x12
  __int64 v14; // x13
  __int64 v15; // x14
  __int64 v16; // x16
  _QWORD *v17; // x17
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x10
  __int64 v23; // x8
  __int64 *v24; // x10
  __int64 v25; // x9
  __int64 v26; // x13
  __int64 v27; // x11
  __int64 v28; // x12
  __int64 v29; // x13
  __int64 v30; // x14
  __int64 v31; // x16
  _QWORD *v32; // x17
  __int64 v33; // x0
  __int64 v34; // x1
  __int64 v35; // x3
  __int64 v36; // x4
  __int64 v37; // x10
  __int64 v38; // x8
  __int64 *v39; // x10
  __int64 v40; // x9
  __int64 v41; // x13
  __int64 v42; // x11
  __int64 v43; // x12
  __int64 v44; // x13
  __int64 v45; // x14
  __int64 v46; // x16
  _QWORD *v47; // x17
  __int64 v48; // x0
  __int64 v49; // x1
  __int64 v50; // x3
  __int64 v51; // x4
  __int64 v52; // x10
  __int64 v53; // x8
  __int64 *v54; // x10
  __int64 v55; // x9
  __int64 v56; // x13

  v3 = *a1;
  if ( !*a1 )
    return 16;
  v4 = *(unsigned __int8 *)(v3 + 2221);
  result = 16;
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      if ( a1 )
      {
        *(_DWORD *)a3 = *((_DWORD *)a1 + 47);
        return 0;
      }
    }
    else if ( a2 == 3 )
    {
      if ( *(_BYTE *)(v3 + 2221) )
      {
        if ( (_DWORD)v4 == 1 )
        {
          v10 = 0;
          v8 = 0;
          v9 = 0;
        }
        else
        {
          v10 = (unsigned __int8)v4 & 0xFE;
          v27 = 0;
          v28 = 0;
          v29 = 0;
          v30 = 0;
          v31 = v10;
          v32 = (_QWORD *)v3;
          do
          {
            v33 = v32[374];
            v34 = v32[781];
            v31 -= 2;
            v35 = v32[375];
            v36 = v32[782];
            v32 += 814;
            v29 += v33;
            v30 += v34;
            v27 += v35;
            v28 += v36;
          }
          while ( v31 );
          v8 = v28 + v27;
          v9 = v30 + v29;
          if ( v10 == v4 )
            goto LABEL_38;
        }
        v37 = v3 + 3256LL * (unsigned int)v10;
        v38 = v4 - v10;
        v39 = (__int64 *)(v37 + 3000);
        do
        {
          v40 = *(v39 - 1);
          v41 = *v39;
          --v38;
          v39 += 407;
          v9 += v40;
          v8 += v41;
        }
        while ( v38 );
        goto LABEL_38;
      }
      goto LABEL_18;
    }
  }
  else
  {
    if ( !a2 )
    {
      if ( *(_BYTE *)(v3 + 2221) )
      {
        if ( (_DWORD)v4 == 1 )
        {
          v11 = 0;
          v8 = 0;
          v9 = 0;
        }
        else
        {
          v11 = (unsigned __int8)v4 & 0xFE;
          v42 = 0;
          v43 = 0;
          v44 = 0;
          v45 = 0;
          v46 = v11;
          v47 = (_QWORD *)v3;
          do
          {
            v48 = v47[278];
            v49 = v47[685];
            v46 -= 2;
            v50 = v47[279];
            v51 = v47[686];
            v47 += 814;
            v44 += v48;
            v45 += v49;
            v42 += v50;
            v43 += v51;
          }
          while ( v46 );
          v8 = v43 + v42;
          v9 = v45 + v44;
          if ( v11 == v4 )
            goto LABEL_38;
        }
        v52 = v3 + 3256LL * (unsigned int)v11;
        v53 = v4 - v11;
        v54 = (__int64 *)(v52 + 2232);
        do
        {
          v55 = *(v54 - 1);
          v56 = *v54;
          --v53;
          v54 += 407;
          v9 += v55;
          v8 += v56;
        }
        while ( v53 );
        goto LABEL_38;
      }
LABEL_18:
      v9 = 0;
      v8 = 0;
      goto LABEL_38;
    }
    if ( a2 == 1 )
    {
      if ( *(_BYTE *)(v3 + 2221) )
      {
        if ( (_DWORD)v4 == 1 )
        {
          v7 = 0;
          v8 = 0;
          v9 = 0;
        }
        else
        {
          v7 = (unsigned __int8)v4 & 0xFE;
          v12 = 0;
          v13 = 0;
          v14 = 0;
          v15 = 0;
          v16 = v7;
          v17 = (_QWORD *)v3;
          do
          {
            v18 = v17[280];
            v19 = v17[687];
            v16 -= 2;
            v20 = v17[281];
            v21 = v17[688];
            v17 += 814;
            v14 += v18;
            v15 += v19;
            v12 += v20;
            v13 += v21;
          }
          while ( v16 );
          v8 = v13 + v12;
          v9 = v15 + v14;
          if ( v7 == v4 )
            goto LABEL_38;
        }
        v22 = v3 + 3256LL * (unsigned int)v7;
        v23 = v4 - v7;
        v24 = (__int64 *)(v22 + 2248);
        do
        {
          v25 = *(v24 - 1);
          v26 = *v24;
          --v23;
          v24 += 407;
          v9 += v25;
          v8 += v26;
        }
        while ( v23 );
LABEL_38:
        *(_QWORD *)a3 = v9;
        *(_QWORD *)(a3 + 8) = v8;
        return 0;
      }
      goto LABEL_18;
    }
  }
  return result;
}
