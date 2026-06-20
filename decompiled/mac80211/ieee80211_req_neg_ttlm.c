__int64 __fastcall ieee80211_req_neg_ttlm(__int64 a1, unsigned __int16 *a2)
{
  int v2; // w8
  int v3; // w11
  int v4; // w8
  int v5; // w10
  int v6; // w11
  int v7; // w9
  int v8; // w11
  int v9; // w10
  int v10; // w11
  int v11; // w9
  int v12; // w11
  int v13; // w10
  int v14; // w11
  int v15; // w9
  int v16; // w11
  int v17; // w10
  int v18; // w9
  __int64 v21; // x0
  __int64 result; // x0
  unsigned __int16 v23; // w27
  unsigned __int16 v24; // w28
  unsigned __int16 v25; // w21
  unsigned __int16 v26; // w22
  unsigned __int16 v27; // w19
  unsigned __int16 v28; // w23
  unsigned __int16 v29; // w26
  unsigned __int16 v30; // w24
  unsigned __int16 v31; // w25
  int v32; // w8
  int v33; // w11
  int v34; // w9
  __int64 v35; // x21
  char v36; // w22
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x19
  __int64 v40; // x9
  __int64 v41; // x0
  int v42; // w10
  int v43; // w8
  __int16 v44; // w9
  __int16 v45; // [xsp+4h] [xbp-4Ch]
  unsigned __int16 v46; // [xsp+8h] [xbp-48h]
  unsigned __int16 v47; // [xsp+Ch] [xbp-44h]
  unsigned __int16 v48; // [xsp+10h] [xbp-40h]
  unsigned __int16 v49; // [xsp+14h] [xbp-3Ch]
  unsigned __int16 v50; // [xsp+18h] [xbp-38h]
  unsigned __int16 v51; // [xsp+1Ch] [xbp-34h]
  unsigned __int16 v52; // [xsp+20h] [xbp-30h]
  unsigned __int16 v53; // [xsp+24h] [xbp-2Ch] BYREF
  unsigned __int16 v54; // [xsp+26h] [xbp-2Ah]
  unsigned __int16 v55; // [xsp+28h] [xbp-28h]
  unsigned __int16 v56; // [xsp+2Ah] [xbp-26h]
  unsigned __int16 v57; // [xsp+2Ch] [xbp-24h]
  unsigned __int16 v58; // [xsp+2Eh] [xbp-22h]
  unsigned __int16 v59; // [xsp+30h] [xbp-20h]
  unsigned __int16 v60; // [xsp+32h] [xbp-1Eh]
  unsigned __int16 v61; // [xsp+34h] [xbp-1Ch]
  unsigned __int16 v62; // [xsp+36h] [xbp-1Ah]
  unsigned __int16 v63; // [xsp+38h] [xbp-18h]
  unsigned __int16 v64; // [xsp+3Ah] [xbp-16h]
  unsigned __int16 v65; // [xsp+3Ch] [xbp-14h]
  unsigned __int16 v66; // [xsp+3Eh] [xbp-12h]
  unsigned __int16 v67; // [xsp+40h] [xbp-10h]
  unsigned __int16 v68; // [xsp+42h] [xbp-Eh]
  __int16 v69; // [xsp+44h] [xbp-Ch]
  __int64 v70; // [xsp+48h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int16 *)(a1 + 5800);
  v69 = 0;
  if ( !v2 )
    goto LABEL_20;
  if ( (*(_WORD *)(a1 + 4738) & 0x60) == 0 )
    goto LABEL_20;
  if ( (*a2 & ~v2) != 0 )
    goto LABEL_20;
  v3 = a2[8];
  v4 = ~v2;
  if ( (v3 & v4) != 0 )
    goto LABEL_20;
  v5 = a2[1];
  v53 = *a2;
  v61 = v3;
  if ( (v4 & v5) != 0 )
    goto LABEL_20;
  v6 = a2[9];
  if ( (v6 & v4) != 0 )
    goto LABEL_20;
  v7 = a2[2];
  v54 = v5;
  v62 = v6;
  if ( (v4 & v7) != 0 )
    goto LABEL_20;
  v8 = a2[10];
  if ( (v8 & v4) != 0 )
    goto LABEL_20;
  v9 = a2[3];
  v55 = v7;
  v63 = v8;
  if ( (v4 & v9) != 0 )
    goto LABEL_20;
  v10 = a2[11];
  if ( (v10 & v4) != 0 )
    goto LABEL_20;
  v11 = a2[4];
  v56 = v9;
  v64 = v10;
  if ( (v4 & v11) != 0 )
    goto LABEL_20;
  v12 = a2[12];
  if ( (v12 & v4) != 0 )
    goto LABEL_20;
  v13 = a2[5];
  v57 = v11;
  v65 = v12;
  if ( (v4 & v13) != 0 )
    goto LABEL_20;
  v14 = a2[13];
  if ( (v14 & v4) != 0 )
    goto LABEL_20;
  v15 = a2[6];
  v58 = v13;
  v66 = v14;
  if ( (v4 & v15) != 0 )
    goto LABEL_20;
  v16 = a2[14];
  if ( (v16 & v4) != 0
    || (v17 = a2[7], v59 = v15, v67 = v16, (v4 & v17) != 0)
    || (v18 = a2[15], (v18 & v4) != 0)
    || (v21 = *(_QWORD *)(a1 + 1616), v60 = v17, v68 = v18, (unsigned int)drv_can_neg_ttlm(v21, a1, &v53)) )
  {
LABEL_20:
    result = 4294967274LL;
  }
  else
  {
    v51 = v54;
    v52 = v53;
    v23 = v60;
    v49 = v56;
    v50 = v55;
    v24 = v61;
    v25 = v64;
    v26 = v65;
    v27 = v62;
    v28 = v66;
    v29 = v63;
    v30 = v67;
    v31 = v68;
    v46 = v59;
    v47 = v58;
    v48 = v57;
    v32 = v54 | v53 | v55 | v56 | v57 | v58 | v59 | v60 | v61 | v62 | v63 | v64 | v65 | v66 | v67 | v68;
    if ( (*(_BYTE *)(a1 + 5840) & 1) != 0 )
    {
      v33 = *(unsigned __int16 *)(a1 + 5804);
      v34 = v33 & ~*(unsigned __int16 *)(a1 + 5806);
      *(_WORD *)(a1 + 5804) = v33 & ~*(_WORD *)(a1 + 5806);
    }
    else
    {
      v34 = *(unsigned __int16 *)(a1 + 5804);
    }
    v45 = v69;
    if ( !(unsigned int)ieee80211_ttlm_set_links(
                          a1,
                          v32 & ~v34 & (unsigned int)*(unsigned __int16 *)(a1 + 5800),
                          *(unsigned __int16 *)(a1 + 5800) & ~(v34 | v32) | (unsigned int)v34) )
    {
      *(_WORD *)(a1 + 5822) = v23;
      *(_WORD *)(a1 + 5824) = v24;
      *(_WORD *)(a1 + 5808) = v52;
      *(_WORD *)(a1 + 5810) = v51;
      *(_WORD *)(a1 + 5826) = v27;
      *(_WORD *)(a1 + 5828) = v29;
      *(_WORD *)(a1 + 5812) = v50;
      *(_WORD *)(a1 + 5814) = v49;
      *(_WORD *)(a1 + 5830) = v25;
      *(_WORD *)(a1 + 5832) = v26;
      *(_WORD *)(a1 + 5816) = v48;
      *(_WORD *)(a1 + 5818) = v47;
      *(_WORD *)(a1 + 5834) = v28;
      *(_WORD *)(a1 + 5836) = v30;
      *(_WORD *)(a1 + 5820) = v46;
      *(_WORD *)(a1 + 5838) = v31;
      *(_WORD *)(a1 + 5840) = v45;
      *(_BYTE *)(a1 + 5840) = 1;
    }
    v35 = *(_QWORD *)(a1 + 1616);
    v36 = *(_BYTE *)(a1 + 3152) + 1;
    *(_BYTE *)(a1 + 3152) = v36;
    v37 = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v35 + 1508) + 64), 2080);
    if ( v37 )
    {
      v38 = *(int *)(v35 + 1508);
      v39 = v37;
      v40 = *(_QWORD *)(v37 + 224) + v38;
      LODWORD(v38) = *(_DWORD *)(v37 + 208) + v38;
      *(_QWORD *)(v37 + 224) = v40;
      *(_DWORD *)(v37 + 208) = v38;
      v41 = skb_put(v37, 27);
      *(_QWORD *)(v41 + 2) = 0;
      *(_QWORD *)(v41 + 10) = 0;
      *(_QWORD *)(v41 + 18) = 0;
      *(_BYTE *)(v41 + 26) = 0;
      *(_WORD *)v41 = 208;
      v42 = *(_DWORD *)(a1 + 4802);
      *(_WORD *)(v41 + 8) = *(_WORD *)(a1 + 4806);
      *(_DWORD *)(v41 + 4) = v42;
      LOWORD(v42) = *(_WORD *)(a1 + 5846);
      *(_DWORD *)(v41 + 10) = *(_DWORD *)(a1 + 5842);
      *(_WORD *)(v41 + 14) = v42;
      v43 = *(_DWORD *)(a1 + 4802);
      v44 = *(_WORD *)(a1 + 4806);
      *(_BYTE *)(v41 + 26) = v36;
      *(_DWORD *)(v41 + 16) = v43;
      *(_WORD *)(v41 + 20) = v44;
      *(_WORD *)(v41 + 24) = 37;
      ieee80211_neg_ttlm_add_suggested_map(v39, a1 + 5808);
      ieee80211_tx_skb_tid(a1, v39, 7, 0xFFFFFFFFLL);
    }
    wiphy_delayed_work_cancel(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), a1 + 3160);
    wiphy_delayed_work_queue(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), a1 + 3160, 50);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
