__int64 __fastcall ieee80211_apply_htcap_overrides(__int64 result, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x9
  __int64 v4; // x8
  __int16 *v5; // x9
  __int64 v6; // x8
  char v7; // w10
  char v8; // w11
  char v9; // w10
  char v10; // w11
  char v11; // w10
  char v12; // w11
  char v13; // w10
  char v14; // w11
  char v15; // w10
  char v16; // w11
  char v17; // w10
  char v18; // w11
  char v19; // w10
  char v20; // w11
  char v21; // w10
  char v22; // w11
  char v23; // w10
  char v24; // w11
  char v25; // w10
  char v26; // w11
  char v27; // w10
  char v28; // w11
  char v29; // w10
  char v30; // w11
  char v31; // w10
  char v32; // w11
  char v33; // w10
  char v34; // w11
  char v35; // w10
  char v36; // w11
  char v37; // w10
  char v38; // w11
  char v39; // w10
  char v40; // w11
  char v41; // w10
  char v42; // w11
  char v43; // w10
  char v44; // w11
  __int16 v45; // w10
  char v46; // w10
  unsigned int v47; // w11
  unsigned int v48; // w8

  if ( *(_BYTE *)(a2 + 2) == 1 )
  {
    v2 = *(_DWORD *)(result + 4720);
    if ( v2 == 2 )
    {
      v3 = 2562;
      v4 = 2536;
    }
    else
    {
      if ( v2 != 1 )
      {
        __break(0x800u);
        return result;
      }
      v3 = 2474;
      v4 = 2448;
    }
    v5 = (__int16 *)(result + v3);
    v6 = result + v4;
    v7 = *((_BYTE *)v5 + 3);
    v8 = *(_BYTE *)(a2 + 5) & ~v7;
    *(_BYTE *)(a2 + 5) = v8;
    v9 = *(_BYTE *)(v6 + 3) & v7 | v8;
    v10 = *(_BYTE *)(a2 + 6);
    *(_BYTE *)(a2 + 5) = v9;
    v11 = *((_BYTE *)v5 + 4);
    v12 = v10 & ~v11;
    *(_BYTE *)(a2 + 6) = v12;
    v13 = *(_BYTE *)(v6 + 4) & v11 | v12;
    v14 = *(_BYTE *)(a2 + 7);
    *(_BYTE *)(a2 + 6) = v13;
    v15 = *((_BYTE *)v5 + 5);
    v16 = v14 & ~v15;
    *(_BYTE *)(a2 + 7) = v16;
    v17 = *(_BYTE *)(v6 + 5) & v15 | v16;
    v18 = *(_BYTE *)(a2 + 8);
    *(_BYTE *)(a2 + 7) = v17;
    v19 = *((_BYTE *)v5 + 6);
    v20 = v18 & ~v19;
    *(_BYTE *)(a2 + 8) = v20;
    v21 = *(_BYTE *)(v6 + 6) & v19 | v20;
    v22 = *(_BYTE *)(a2 + 9);
    *(_BYTE *)(a2 + 8) = v21;
    v23 = *((_BYTE *)v5 + 7);
    v24 = v22 & ~v23;
    *(_BYTE *)(a2 + 9) = v24;
    v25 = *(_BYTE *)(v6 + 7) & v23 | v24;
    v26 = *(_BYTE *)(a2 + 10);
    *(_BYTE *)(a2 + 9) = v25;
    v27 = *((_BYTE *)v5 + 8);
    v28 = v26 & ~v27;
    *(_BYTE *)(a2 + 10) = v28;
    v29 = *(_BYTE *)(v6 + 8) & v27 | v28;
    v30 = *(_BYTE *)(a2 + 11);
    *(_BYTE *)(a2 + 10) = v29;
    v31 = *((_BYTE *)v5 + 9);
    v32 = v30 & ~v31;
    *(_BYTE *)(a2 + 11) = v32;
    v33 = *(_BYTE *)(v6 + 9) & v31 | v32;
    v34 = *(_BYTE *)(a2 + 12);
    *(_BYTE *)(a2 + 11) = v33;
    v35 = *((_BYTE *)v5 + 10);
    v36 = v34 & ~v35;
    *(_BYTE *)(a2 + 12) = v36;
    v37 = *(_BYTE *)(v6 + 10) & v35 | v36;
    v38 = *(_BYTE *)(a2 + 13);
    *(_BYTE *)(a2 + 12) = v37;
    v39 = *((_BYTE *)v5 + 11);
    v40 = v38 & ~v39;
    *(_BYTE *)(a2 + 13) = v40;
    v41 = *(_BYTE *)(v6 + 11) & v39 | v40;
    v42 = *(_BYTE *)(a2 + 14);
    *(_BYTE *)(a2 + 13) = v41;
    v43 = *((_BYTE *)v5 + 12);
    v44 = v42 & ~v43;
    *(_BYTE *)(a2 + 14) = v44;
    *(_BYTE *)(a2 + 14) = *(_BYTE *)(v6 + 12) & v43 | v44;
    v45 = *v5;
    if ( (*v5 & 2) != 0 && (*(_WORD *)v6 & 2) == 0 )
    {
      *(_WORD *)a2 &= ~2u;
      v45 = *v5;
    }
    if ( (v45 & 0x40) != 0 && (*(_WORD *)v6 & 0x40) == 0 )
    {
      *(_WORD *)a2 &= ~0x40u;
      v45 = *v5;
    }
    if ( (v45 & 0x20) != 0 && (*(_WORD *)v6 & 0x20) == 0 )
    {
      *(_WORD *)a2 &= ~0x20u;
      v45 = *v5;
    }
    if ( (v45 & 0x800) != 0 && (*(_WORD *)v6 & 0x800) == 0 )
    {
      *(_WORD *)a2 &= ~0x800u;
      v45 = *v5;
    }
    if ( (v45 & 1) != 0 && (*(_WORD *)v6 & 1) == 0 )
    {
      *(_WORD *)a2 &= ~1u;
      v45 = *v5;
    }
    if ( (v45 & 0x4000) != 0 && (*(_WORD *)v6 & 0x4000) != 0 )
    {
      *(_WORD *)a2 |= 0x4000u;
      v45 = *v5;
    }
    if ( (v45 & 0x80) != 0 && (*(_WORD *)v6 & 0x80) != 0 )
    {
      *(_WORD *)a2 |= 0x80u;
      v45 = *v5;
    }
    if ( (v45 & 0x300) != 0 )
      *(_WORD *)a2 |= *(_WORD *)v6 & 0x300;
    v46 = *((_BYTE *)v5 + 2);
    if ( (v46 & 3) != 0 )
    {
      v47 = *(_BYTE *)(v6 + 2) & 3;
      if ( v47 < *(unsigned __int8 *)(a2 + 3) )
      {
        *(_BYTE *)(a2 + 3) = v47;
        v46 = *((_BYTE *)v5 + 2);
      }
    }
    if ( (v46 & 0x1C) != 0 )
    {
      v48 = (*(unsigned __int8 *)(v6 + 2) >> 2) & 7;
      if ( v48 > *(unsigned __int8 *)(a2 + 4) )
        *(_BYTE *)(a2 + 4) = v48;
    }
  }
  return result;
}
