__int64 __fastcall ieee80211_update_p2p_noa(__int64 result, int a2)
{
  __int64 v2; // x9
  int v3; // w8
  __int64 v4; // x10
  __int64 v5; // x14
  signed int v6; // w15
  __int64 v7; // x13
  int v8; // w12
  int v9; // w17
  int v11; // w12
  unsigned int v12; // w16
  signed int v13; // w17
  signed int v14; // w9
  int v15; // w8
  int v16; // w10
  int v17; // w12
  unsigned int v18; // w11
  signed int v19; // w12
  int v20; // w10
  signed int v21; // w10
  int v22; // w11
  int v23; // w12
  int v24; // w14
  unsigned int v25; // w13
  signed int v26; // w14
  int v27; // w12
  int v28; // w11
  signed int v29; // w11
  int v30; // w12
  int v31; // w13
  int v32; // w15
  unsigned int v33; // w14
  signed int v34; // w15
  int v35; // w13
  int v36; // w12
  signed int v37; // w12
  int v38; // w13
  int v39; // w14
  int v40; // w16
  unsigned int v41; // w15
  signed int v42; // w16
  int v43; // w14
  int v44; // w13
  unsigned int v45; // w13
  int v46; // w15
  int v47; // w16
  int v48; // w17
  unsigned int v49; // w14
  signed int v50; // w17
  int v51; // w16
  int v52; // w15
  int v53; // w15
  int v54; // w16
  int v55; // w2
  unsigned int v56; // w17
  signed int v57; // w2
  int v58; // w16
  int v59; // w15
  int v60; // w15
  int v61; // w16
  int v62; // w2
  unsigned int v63; // w17
  signed int v64; // w2
  int v65; // w16
  int v66; // w15
  int v67; // w15
  int v68; // w16
  int v69; // w2
  unsigned int v70; // w17
  signed int v71; // w2
  int v72; // w16
  int v73; // w15

  v2 = 0;
  v3 = 0x7FFFFFFF;
  v4 = 20;
  *(_WORD *)(result + 4) = 0;
  do
  {
    v5 = result + v2;
    v6 = *(unsigned __int8 *)(result + v2 + 6);
    if ( !*(_BYTE *)(result + v2 + 6) )
      goto LABEL_4;
    v7 = result + v4;
    v8 = *(_DWORD *)(result + v4 - 8);
    v9 = a2 - (v8 + *(_DWORD *)(result + v4 - 4));
    if ( v9 >= -1 && v6 != 1 )
    {
      v12 = *(_DWORD *)(result + v4);
      if ( v12 )
      {
        v13 = (v12 + v9) / v12;
        if ( v6 != 255 )
        {
          if ( v13 >= v6 )
          {
            *(_BYTE *)(v5 + 6) = 0;
            v8 = *(_DWORD *)(v7 - 8);
            goto LABEL_11;
          }
          *(_BYTE *)(v5 + 6) = v6 - v13;
        }
        v8 += v13 * v12;
        *(_DWORD *)(v7 - 8) = v8;
      }
    }
LABEL_11:
    v11 = v8 - a2;
    if ( v11 <= 0 )
      *(_BYTE *)(result + 5) |= 1LL << v2;
    *(_BYTE *)(result + 4) = 1;
    if ( v3 >= (unsigned int)v11 )
      v3 = v11;
LABEL_4:
    ++v2;
    v4 += 12;
  }
  while ( v2 != 4 );
  if ( *(_BYTE *)(result + 5) )
  {
    v14 = *(unsigned __int8 *)(result + 6);
    if ( !*(_BYTE *)(result + 6) )
      goto LABEL_30;
    v16 = *(_DWORD *)(result + 12);
    v15 = *(_DWORD *)(result + 16);
    v17 = a2 - (v16 + v15);
    if ( v17 >= -1 && v14 != 1 )
    {
      v18 = *(_DWORD *)(result + 20);
      if ( v18 )
      {
        v19 = (v18 + v17) / v18;
        if ( v14 == 255 )
          goto LABEL_27;
        if ( v19 >= v14 )
        {
          LOBYTE(v14) = 0;
          *(_BYTE *)(result + 6) = 0;
        }
        else
        {
          LOBYTE(v14) = v14 - v19;
          *(_BYTE *)(result + 6) = v14;
LABEL_27:
          v16 += v19 * v18;
          *(_DWORD *)(result + 12) = v16;
        }
      }
    }
    v20 = v16 - a2;
    if ( v20 <= 0 )
    {
      v3 = (v20 + v15) & ~((v20 + v15) >> 31);
      v21 = *(unsigned __int8 *)(result + 7);
      if ( !*(_BYTE *)(result + 7) )
        goto LABEL_44;
    }
    else
    {
LABEL_30:
      v3 = 0;
      v21 = *(unsigned __int8 *)(result + 7);
      if ( !*(_BYTE *)(result + 7) )
        goto LABEL_44;
    }
    v23 = *(_DWORD *)(result + 24);
    v22 = *(_DWORD *)(result + 28);
    v24 = v3 + a2 - (v23 + v22);
    if ( v24 >= -1 && v21 != 1 )
    {
      v25 = *(_DWORD *)(result + 32);
      if ( v25 )
      {
        v26 = (v25 + v24) / v25;
        if ( v21 == 255 )
          goto LABEL_39;
        if ( v26 >= v21 )
        {
          LOBYTE(v21) = 0;
          *(_BYTE *)(result + 7) = 0;
        }
        else
        {
          LOBYTE(v21) = v21 - v26;
          *(_BYTE *)(result + 7) = v21;
LABEL_39:
          v23 += v26 * v25;
          *(_DWORD *)(result + 24) = v23;
        }
      }
    }
    v27 = v23 - a2;
    if ( v27 <= v3 )
    {
      v28 = v27 + v22;
      if ( v28 > v3 )
        v3 = v28;
    }
LABEL_44:
    v29 = *(unsigned __int8 *)(result + 8);
    if ( *(_BYTE *)(result + 8) )
    {
      v31 = *(_DWORD *)(result + 36);
      v30 = *(_DWORD *)(result + 40);
      v32 = v3 + a2 - (v31 + v30);
      if ( v32 >= -1 && v29 != 1 )
      {
        v33 = *(_DWORD *)(result + 44);
        if ( v33 )
        {
          v34 = (v33 + v32) / v33;
          if ( v29 == 255 )
            goto LABEL_51;
          if ( v34 >= v29 )
          {
            LOBYTE(v29) = 0;
            *(_BYTE *)(result + 8) = 0;
          }
          else
          {
            LOBYTE(v29) = v29 - v34;
            *(_BYTE *)(result + 8) = v29;
LABEL_51:
            v31 += v34 * v33;
            *(_DWORD *)(result + 36) = v31;
          }
        }
      }
      v35 = v31 - a2;
      if ( v35 <= v3 )
      {
        v36 = v35 + v30;
        if ( v36 > v3 )
          v3 = v36;
      }
    }
    v37 = *(unsigned __int8 *)(result + 9);
    if ( *(_BYTE *)(result + 9) )
    {
      v39 = *(_DWORD *)(result + 48);
      v38 = *(_DWORD *)(result + 52);
      v40 = v3 + a2 - (v39 + v38);
      if ( v40 >= -1 && v37 != 1 )
      {
        v41 = *(_DWORD *)(result + 56);
        if ( v41 )
        {
          v42 = (v41 + v40) / v41;
          if ( v37 == 255 )
            goto LABEL_63;
          if ( v42 >= v37 )
          {
            LOBYTE(v37) = 0;
            *(_BYTE *)(result + 9) = 0;
          }
          else
          {
            LOBYTE(v37) = v37 - v42;
            *(_BYTE *)(result + 9) = v37;
LABEL_63:
            v39 += v42 * v41;
            *(_DWORD *)(result + 48) = v39;
          }
        }
      }
      v43 = v39 - a2;
      if ( v43 <= v3 )
      {
        v44 = v43 + v38;
        if ( v44 > v3 )
          v3 = v44;
      }
    }
    v45 = 0;
    while ( 2 )
    {
      if ( (_BYTE)v14 )
      {
        v47 = *(_DWORD *)(result + 12);
        v46 = *(_DWORD *)(result + 16);
        v48 = v3 + a2 - (v47 + v46);
        if ( v48 < -1 )
        {
          v49 = 0;
          goto LABEL_82;
        }
        if ( (unsigned __int8)v14 == 1 )
        {
          v49 = 0;
          LOBYTE(v14) = 1;
          goto LABEL_82;
        }
        v49 = *(_DWORD *)(result + 20);
        if ( v49 )
        {
          v50 = (v49 + v48) / v49;
          if ( (_BYTE)v14 == 0xFF )
          {
            LOBYTE(v14) = -1;
LABEL_80:
            v47 += v50 * v49;
            v49 = 1;
            *(_DWORD *)(result + 12) = v47;
          }
          else
          {
            if ( v50 < (unsigned __int8)v14 )
            {
              LOBYTE(v14) = v14 - v50;
              *(_BYTE *)(result + 6) = v14;
              goto LABEL_80;
            }
            LOBYTE(v14) = 0;
            v49 = 0;
            *(_BYTE *)(result + 6) = 0;
          }
        }
LABEL_82:
        v51 = v47 - a2;
        if ( v51 <= v3 )
        {
          v52 = v51 + v46;
          if ( v52 > v3 )
            v3 = v52;
        }
      }
      else
      {
        LOBYTE(v14) = 0;
        v49 = 0;
      }
      if ( (_BYTE)v21 )
      {
        v54 = *(_DWORD *)(result + 24);
        v53 = *(_DWORD *)(result + 28);
        v55 = v3 + a2 - (v54 + v53);
        if ( v55 < -1 )
          goto LABEL_97;
        if ( (unsigned __int8)v21 == 1 )
        {
          LOBYTE(v21) = 1;
          goto LABEL_97;
        }
        v56 = *(_DWORD *)(result + 32);
        if ( v56 )
        {
          v57 = (v56 + v55) / v56;
          if ( (_BYTE)v21 == 0xFF )
          {
            LOBYTE(v21) = -1;
LABEL_95:
            v54 += v57 * v56;
            v49 = 1;
            *(_DWORD *)(result + 24) = v54;
          }
          else
          {
            if ( v57 < (unsigned __int8)v21 )
            {
              LOBYTE(v21) = v21 - v57;
              *(_BYTE *)(result + 7) = v21;
              goto LABEL_95;
            }
            LOBYTE(v21) = 0;
            *(_BYTE *)(result + 7) = 0;
          }
        }
LABEL_97:
        v58 = v54 - a2;
        if ( v58 <= v3 )
        {
          v59 = v58 + v53;
          if ( v59 > v3 )
            v3 = v59;
        }
      }
      else
      {
        LOBYTE(v21) = 0;
      }
      if ( (_BYTE)v29 )
      {
        v61 = *(_DWORD *)(result + 36);
        v60 = *(_DWORD *)(result + 40);
        v62 = v3 + a2 - (v61 + v60);
        if ( v62 < -1 )
          goto LABEL_112;
        if ( (unsigned __int8)v29 == 1 )
        {
          LOBYTE(v29) = 1;
          goto LABEL_112;
        }
        v63 = *(_DWORD *)(result + 44);
        if ( v63 )
        {
          v64 = (v63 + v62) / v63;
          if ( (_BYTE)v29 == 0xFF )
          {
            LOBYTE(v29) = -1;
LABEL_110:
            v61 += v64 * v63;
            v49 = 1;
            *(_DWORD *)(result + 36) = v61;
          }
          else
          {
            if ( v64 < (unsigned __int8)v29 )
            {
              LOBYTE(v29) = v29 - v64;
              *(_BYTE *)(result + 8) = v29;
              goto LABEL_110;
            }
            LOBYTE(v29) = 0;
            *(_BYTE *)(result + 8) = 0;
          }
        }
LABEL_112:
        v65 = v61 - a2;
        if ( v65 <= v3 )
        {
          v66 = v65 + v60;
          if ( v66 > v3 )
            v3 = v66;
        }
      }
      else
      {
        LOBYTE(v29) = 0;
      }
      if ( (_BYTE)v37 )
      {
        v68 = *(_DWORD *)(result + 48);
        v67 = *(_DWORD *)(result + 52);
        v69 = v3 + a2 - (v68 + v67);
        if ( v69 < -1 )
          goto LABEL_127;
        if ( (unsigned __int8)v37 == 1 )
        {
          LOBYTE(v37) = 1;
          goto LABEL_127;
        }
        v70 = *(_DWORD *)(result + 56);
        if ( v70 )
        {
          v71 = (v70 + v69) / v70;
          if ( (_BYTE)v37 == 0xFF )
          {
            LOBYTE(v37) = -1;
LABEL_125:
            v68 += v71 * v70;
            v49 = 1;
            *(_DWORD *)(result + 48) = v68;
          }
          else
          {
            if ( v71 < (unsigned __int8)v37 )
            {
              LOBYTE(v37) = v37 - v71;
              *(_BYTE *)(result + 9) = v37;
              goto LABEL_125;
            }
            LOBYTE(v37) = 0;
            *(_BYTE *)(result + 9) = 0;
          }
        }
LABEL_127:
        v72 = v68 - a2;
        if ( v72 <= v3 )
        {
          v73 = v72 + v67;
          if ( v73 > v3 )
            v3 = v73;
        }
      }
      else
      {
        LOBYTE(v37) = 0;
      }
      if ( !v49 )
        break;
      if ( v45++ >= 4 )
        break;
      continue;
    }
  }
  *(_DWORD *)result = v3 + a2;
  return result;
}
