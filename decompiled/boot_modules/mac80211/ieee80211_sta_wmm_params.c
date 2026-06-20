__int64 __fastcall ieee80211_sta_wmm_params(__int64 a1, unsigned int *a2, _BYTE *a3, unsigned __int64 a4, __int64 a5)
{
  unsigned __int64 v6; // x25
  __int64 result; // x0
  __int64 v8; // x21
  char v10; // w8
  int v11; // w9
  int v12; // w10
  unsigned __int8 *v13; // x26
  bool v14; // w23
  unsigned int v15; // w8
  unsigned int v16; // w24
  int v17; // w19
  char v18; // w9
  int v19; // w27
  __int64 v20; // x2
  char v21; // w9
  char v22; // w9
  char v23; // w9
  char *v24; // x1
  __int64 v25; // x3
  unsigned int v26; // w8
  __int16 v27; // w11
  unsigned int v28; // w9
  bool v29; // zf
  int v30; // w8
  unsigned int v31; // w8
  unsigned int v32; // w9
  __int64 v33; // x3
  __int64 v34; // x8
  __int64 v35; // x9
  __int64 v36; // x8
  __int64 v37; // x10
  __int64 v38; // x9
  __int64 v39; // x8
  __int64 v40; // x11
  __int64 v41; // x3
  __int64 v42; // x8
  __int64 v43; // x8
  char *v44; // [xsp+8h] [xbp-68h]
  unsigned int v45; // [xsp+14h] [xbp-5Ch]
  unsigned int *v46; // [xsp+18h] [xbp-58h]
  int v47; // [xsp+20h] [xbp-50h]
  int v48; // [xsp+24h] [xbp-4Ch]
  int v49; // [xsp+28h] [xbp-48h]
  int v50; // [xsp+2Ch] [xbp-44h]
  __int64 v51; // [xsp+30h] [xbp-40h] BYREF
  __int64 v52; // [xsp+38h] [xbp-38h]
  __int64 v53; // [xsp+40h] [xbp-30h]
  __int64 v54; // [xsp+48h] [xbp-28h]
  __int64 v55; // [xsp+50h] [xbp-20h]
  __int64 v56; // [xsp+58h] [xbp-18h]
  __int64 v57; // [xsp+60h] [xbp-10h]
  __int64 v58; // [xsp+68h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 464) + 336LL) )
  {
LABEL_14:
    result = 0;
    goto LABEL_15;
  }
  v6 = a4 - 8;
  result = 0;
  if ( a4 >= 8 && a3 && *(unsigned __int16 *)(a1 + 128) >= 4u )
  {
    if ( a3[5] != 1 )
      goto LABEL_14;
    v8 = *(_QWORD *)a2;
    v10 = (*(_BYTE *)(*(_QWORD *)a2 + 2500LL) & 0x80) != 0 ? *(_BYTE *)(v8 + 2516) : 0;
    v11 = a3[6] & 0xF;
    v12 = a5 ? *(_BYTE *)a5 & 0xF : -1;
    if ( a2[218] == v11 && v12 == a2[219] )
      goto LABEL_14;
    a2[218] = v11;
    a2[219] = v12;
    v51 = 0;
    v52 = 0;
    v53 = 0;
    v54 = 0;
    v55 = 0;
    v56 = 0;
    v57 = 0;
    *(_BYTE *)(v8 + 1890) = 0;
    if ( v6 < 4 )
    {
      v41 = 0;
    }
    else
    {
      v13 = a3 + 8;
      v49 = v10 & 2;
      v50 = v10 & 1;
      v14 = a5 != 0;
      v46 = a2;
      v47 = v10 & 8;
      v48 = v10 & 4;
      do
      {
        v15 = *v13;
        v16 = (v15 >> 5) & 3;
        v17 = (v15 >> 4) & 1;
        switch ( v16 )
        {
          case 3u:
            if ( v17 )
              *(_BYTE *)(v8 + 1890) |= 0xC0u;
            v20 = 0;
            BYTE1(v52) = v14;
            if ( a5 )
            {
              v22 = *(_BYTE *)(a5 + 12);
              v19 = v50;
              WORD1(v52) = *(_WORD *)(a5 + 10);
              BYTE4(v52) = v22;
            }
            else
            {
              v19 = v50;
            }
            break;
          case 2u:
            if ( v17 )
              *(_BYTE *)(v8 + 1890) |= 0x30u;
            HIBYTE(v53) = v14;
            if ( a5 )
            {
              v21 = *(_BYTE *)(a5 + 9);
              LOWORD(v54) = *(_WORD *)(a5 + 7);
              BYTE2(v54) = v21;
            }
            v19 = v49;
            v20 = 1;
            break;
          case 1u:
            if ( v17 )
              *(_BYTE *)(v8 + 1890) |= 6u;
            BYTE3(v57) = v14;
            if ( a5 )
            {
              v18 = *(_BYTE *)(a5 + 6);
              WORD2(v57) = *(_WORD *)(a5 + 4);
              BYTE6(v57) = v18;
            }
            v19 = v48;
            v20 = 3;
            break;
          default:
            if ( v17 )
              *(_BYTE *)(v8 + 1890) |= 9u;
            BYTE5(v55) = v14;
            if ( a5 )
            {
              v23 = *(_BYTE *)(a5 + 3);
              HIWORD(v55) = *(_WORD *)(a5 + 1);
              LOBYTE(v56) = v23;
            }
            v19 = v47;
            v20 = 2;
            break;
        }
        v24 = (char *)&v51 + 14 * (unsigned int)v20;
        v25 = *v13 & 0xF;
        v24[6] = *v13 & 0xF;
        if ( (unsigned int)v25 <= 1 )
        {
          v44 = (char *)&v51 + 14 * (unsigned int)v20;
          v45 = v20;
          v34 = *(_QWORD *)v46;
          if ( *(_WORD *)(*(_QWORD *)v46 + 5800LL) )
            printk(&unk_BAF1A, v34 + 1640, v46[2], v25);
          else
            printk(&unk_B7A16, v34 + 1640, (unsigned int)v25, v16);
          v24 = v44;
          v20 = v45;
          v44[6] = 2;
        }
        v26 = v13[1];
        v27 = *((_WORD *)v13 + 1);
        v24[7] = v17;
        v28 = v26 >> 4;
        v30 = v26 & 0xF;
        v29 = v30 == 0;
        *(_WORD *)v24 = v27;
        v31 = -1 << v30;
        v24[8] = v19 != 0;
        v32 = -1 << v28;
        v33 = ~v31;
        *((_WORD *)v24 + 1) = ~(_WORD)v31;
        *((_WORD *)v24 + 2) = ~(_WORD)v32;
        if ( v29 || v31 < v32 )
        {
          v42 = *(_QWORD *)v46;
          if ( *(_WORD *)(*(_QWORD *)v46 + 5800LL) )
            printk(&unk_B8E23, v42 + 1640, v46[2], v33);
          else
            printk(&unk_BBC78, v42 + 1640, (unsigned int)v33, ~v32);
          result = 0;
          goto LABEL_15;
        }
        ieee80211_regulatory_limit_wmm_params(v8, v24, v20);
        v6 -= 4LL;
        v13 += 4;
      }
      while ( v6 > 3 );
      if ( WORD1(v51) )
      {
        a2 = v46;
        if ( (_WORD)v53 )
        {
          if ( HIWORD(v54) )
          {
            if ( WORD2(v56) )
            {
              v35 = v55;
              *((_QWORD *)v46 + 114) = v54;
              v37 = v56;
              v36 = v57;
              *((_QWORD *)v46 + 115) = v35;
              v38 = v51;
              *((_QWORD *)v46 + 117) = v36;
              v39 = v52;
              v40 = v53;
              *((_QWORD *)v46 + 116) = v37;
              *((_QWORD *)v46 + 111) = v38;
              *((_QWORD *)v46 + 112) = v39;
              *((_QWORD *)v46 + 113) = v40;
              ieee80211_mgd_set_link_qos_params(v46);
              result = 1;
              *(_BYTE *)(*((_QWORD *)v46 + 118) + 224LL) = 1;
              goto LABEL_15;
            }
            v41 = 3;
          }
          else
          {
            v41 = 2;
          }
        }
        else
        {
          v41 = 1;
        }
      }
      else
      {
        a2 = v46;
        v41 = 0;
      }
    }
    v43 = *(_QWORD *)a2;
    if ( *(_WORD *)(*(_QWORD *)a2 + 5800LL) )
      printk(&unk_BB54B, v43 + 1640, a2[2], v41);
    else
      printk(&unk_BB93C, v43 + 1640, (unsigned int)v41, v41);
    result = 0;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
