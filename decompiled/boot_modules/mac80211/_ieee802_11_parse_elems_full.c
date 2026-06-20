__int64 __fastcall ieee802_11_parse_elems_full(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  unsigned __int8 *v5; // x24
  unsigned __int8 *v6; // x8
  __int64 v7; // x25
  _BYTE *v8; // x28
  __int64 v9; // x27
  __int64 v13; // x26
  unsigned __int64 v14; // x22
  _BYTE *v15; // x23
  __int64 v16; // x9
  char v17; // w8
  __int64 elem_match; // x0
  int v19; // w24
  unsigned int v20; // w8
  _DWORD *v21; // x25
  unsigned __int8 v22; // w26
  unsigned int v23; // w8
  unsigned int v24; // w9
  int v25; // w8
  unsigned int v26; // w27
  char v27; // w24
  __int64 v28; // x0
  unsigned __int8 *v29; // x1
  __int64 v30; // x2
  __int64 v31; // x0
  unsigned int v32; // w8
  bool v33; // cc
  _BYTE *v34; // x8
  __int64 v35; // x8
  int v36; // w8
  int v37; // w9
  int v38; // w8
  int v39; // w9
  int v40; // w27
  int v41; // w9
  unsigned int v42; // w8
  unsigned int v43; // w27
  int v44; // w19
  unsigned __int64 v45; // x8
  int v46; // w9
  unsigned int v47; // w9
  unsigned int v48; // w8
  unsigned int v49; // w10
  unsigned __int64 v50; // x9
  unsigned int v51; // w8
  unsigned __int64 v52; // x10
  unsigned int v53; // w8
  __int64 v54; // x0
  __int16 v55; // w24
  int v56; // w10
  bool v57; // zf
  int v58; // w11
  __int64 v59; // [xsp+0h] [xbp-50h]
  __int64 v60; // [xsp+8h] [xbp-48h]
  unsigned int v61; // [xsp+14h] [xbp-3Ch]
  _BYTE v63[4]; // [xsp+24h] [xbp-2Ch] BYREF
  _QWORD v64[5]; // [xsp+28h] [xbp-28h] BYREF

  v64[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v5 = *(unsigned __int8 **)(a1 + 8);
  v4 = *(_QWORD *)(a1 + 16);
  memset(v64, 0, 32);
  v60 = v3;
  v61 = *(_DWORD *)(a1 + 40);
  v6 = &v5[v4];
  if ( v4 >= 2 )
  {
    v8 = v5 + 1;
    v7 = v5[1];
    v9 = v7 + 2;
    if ( v4 >= (unsigned __int64)(v7 + 2) )
    {
      LODWORD(v13) = v5[1];
      v59 = a2 + 472;
      while ( 1 )
      {
        v15 = v5 + 2;
        v14 = *v5;
        if ( !a3 || (cfg80211_is_element_inherited(v5, a3) & 1) != 0 )
          break;
LABEL_135:
        v5 = &v15[(unsigned __int8)*v8];
        v6 = (unsigned __int8 *)(*(_QWORD *)(a1 + 8) + *(_QWORD *)(a1 + 16));
        if ( v6 - v5 > 1 )
        {
          v8 = v5 + 1;
          v13 = v5[1];
          v9 = v13 + 2;
          LODWORD(v7) = v5[1];
          if ( v6 - v5 >= (unsigned __int64)(v13 + 2) )
            continue;
        }
        goto LABEL_3;
      }
      switch ( (int)v14 )
      {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 16:
        case 32:
        case 37:
        case 42:
        case 45:
        case 48:
        case 50:
        case 56:
        case 60:
        case 61:
        case 62:
        case 90:
        case 101:
        case 104:
        case 113:
        case 114:
        case 117:
        case 118:
        case 126:
        case 127:
        case 130:
        case 131:
        case 132:
        case 191:
        case 192:
        case 194:
        case 211:
        case 213:
        case 214:
        case 217:
        case 232:
        case 244:
          if ( ((*(_QWORD *)((char *)v64 + ((v14 >> 3) & 0x18)) >> v14) & 1) == 0 )
            goto LABEL_13;
          v16 = a2;
          v17 = *(_BYTE *)(a2 + 760) | 2;
LABEL_12:
          *(_BYTE *)(v16 + 760) = v17;
          goto LABEL_135;
        default:
LABEL_13:
          if ( v60 && (unsigned int)v14 <= 0x3F && ((*(_QWORD *)(a1 + 32) >> v14) & 1) != 0 )
            v61 = crc32_be(v61, v5, v9);
          switch ( (int)v14 )
          {
            case 0:
              *(_QWORD *)(a2 + 48) = v15;
              *(_BYTE *)(a2 + 697) = v7;
              goto LABEL_134;
            case 1:
              *(_QWORD *)(a2 + 56) = v15;
              *(_BYTE *)(a2 + 698) = v7;
              goto LABEL_134;
            case 3:
              if ( !(_BYTE)v7 )
                goto LABEL_140;
              *(_QWORD *)(a2 + 64) = v15;
              goto LABEL_134;
            case 5:
              if ( (unsigned __int8)v7 < 4u )
                goto LABEL_140;
              *(_QWORD *)(a2 + 72) = v15;
              *(_BYTE *)(a2 + 699) = v7;
              goto LABEL_134;
            case 7:
              *(_QWORD *)(a2 + 304) = v15;
              *(_BYTE *)(a2 + 711) = v7;
              goto LABEL_134;
            case 32:
              if ( (unsigned __int8)v7 != 1 )
                goto LABEL_140;
              *(_QWORD *)(a2 + 312) = v15;
              goto LABEL_134;
            case 37:
              if ( (unsigned __int8)v7 != 3 )
                goto LABEL_140;
              *(_QWORD *)(a2 + 272) = v15;
              goto LABEL_134;
            case 42:
              if ( !(_BYTE)v7 )
                goto LABEL_140;
              *(_QWORD *)(a2 + 96) = v15;
              goto LABEL_134;
            case 45:
              if ( *(_DWORD *)a1 < 2u )
                goto LABEL_134;
              if ( (unsigned __int8)v7 < 0x1Au )
                goto LABEL_140;
              *(_QWORD *)(a2 + 128) = v15;
              goto LABEL_134;
            case 48:
              *(_QWORD *)(a2 + 80) = v15;
              *(_BYTE *)(a2 + 700) = v7;
              goto LABEL_134;
            case 50:
              *(_QWORD *)(a2 + 104) = v15;
              *(_BYTE *)(a2 + 702) = v7;
              goto LABEL_134;
            case 56:
              if ( (unsigned __int8)v7 < 5u )
                goto LABEL_140;
              *(_QWORD *)(a2 + 328) = v15;
              goto LABEL_134;
            case 60:
              if ( (unsigned __int8)v7 != 4 )
                goto LABEL_140;
              *(_QWORD *)(a2 + 280) = v15;
              goto LABEL_134;
            case 61:
              if ( *(_DWORD *)a1 < 2u )
                goto LABEL_134;
              if ( (unsigned __int8)v7 < 0x16u )
                goto LABEL_140;
              *(_QWORD *)(a2 + 136) = v15;
              goto LABEL_134;
            case 62:
              if ( *(_DWORD *)a1 < 2u )
                goto LABEL_134;
              if ( (unsigned __int8)v7 != 1 )
                goto LABEL_140;
              *(_QWORD *)(a2 + 344) = v15;
              goto LABEL_134;
            case 90:
              if ( (unsigned __int8)v7 >= 3u )
                *(_QWORD *)(a2 + 360) = v15;
              goto LABEL_134;
            case 101:
              if ( (unsigned __int8)v7 < 0x12u )
                goto LABEL_140;
              *(_QWORD *)(a2 + 24) = v5;
              goto LABEL_134;
            case 104:
              if ( (unsigned __int8)v7 < 4u )
                goto LABEL_140;
              *(_QWORD *)(a2 + 32) = v15;
              goto LABEL_134;
            case 113:
              if ( (unsigned __int8)v7 < 7u )
                goto LABEL_140;
              *(_QWORD *)(a2 + 160) = v15;
              goto LABEL_134;
            case 114:
              *(_QWORD *)(a2 + 216) = v15;
              *(_BYTE *)(a2 + 706) = v7;
              goto LABEL_134;
            case 117:
              *(_QWORD *)(a2 + 224) = v15;
              *(_BYTE *)(a2 + 707) = v7;
              goto LABEL_134;
            case 118:
              if ( (unsigned __int8)v7 < 6u )
                goto LABEL_140;
              *(_QWORD *)(a2 + 352) = v15;
              goto LABEL_134;
            case 119:
              if ( (unsigned __int8)v7 >= 2u )
                *(_QWORD *)(a2 + 232) = v15;
              goto LABEL_134;
            case 126:
              if ( (unsigned __int8)v7 < 0x15u )
                goto LABEL_140;
              *(_QWORD *)(a2 + 264) = v15;
              goto LABEL_134;
            case 127:
              *(_QWORD *)(a2 + 40) = v15;
              *(_BYTE *)(a2 + 696) = v7;
              goto LABEL_134;
            case 130:
              *(_QWORD *)(a2 + 240) = v15;
              *(_BYTE *)(a2 + 708) = v7;
              goto LABEL_134;
            case 131:
              *(_QWORD *)(a2 + 248) = v15;
              *(_BYTE *)(a2 + 709) = v7;
              goto LABEL_134;
            case 132:
              *(_QWORD *)(a2 + 256) = v15;
              *(_BYTE *)(a2 + 710) = v7;
              goto LABEL_134;
            case 150:
              if ( (unsigned __int8)v7 < 4u )
                goto LABEL_140;
              if ( *v15 || v5[3] != 64 || v5[4] != 150 || v5[5] )
                goto LABEL_134;
              if ( (unsigned __int8)v7 != 6 )
                goto LABEL_140;
              if ( v60 )
                v61 = crc32_be(v61, v5, v9);
              *(_QWORD *)(a2 + 320) = v15;
              goto LABEL_134;
            case 159:
              if ( !(_BYTE)v7 )
                goto LABEL_140;
              *(_QWORD *)(a2 + 392) = v15;
              goto LABEL_134;
            case 191:
              if ( *(_DWORD *)a1 < 3u )
                goto LABEL_134;
              if ( (unsigned __int8)v7 < 0xCu )
                goto LABEL_140;
              *(_QWORD *)(a2 + 144) = v15;
              goto LABEL_134;
            case 192:
              if ( *(_DWORD *)a1 < 3u )
                goto LABEL_134;
              if ( (unsigned __int8)v7 < 5u )
                goto LABEL_140;
              *(_QWORD *)(a2 + 152) = v15;
              goto LABEL_130;
            case 194:
              if ( *(_DWORD *)a1 < 3u )
                goto LABEL_134;
              if ( *(_BYTE *)(a1 + 24) != 1 )
                goto LABEL_142;
              if ( (unsigned __int8)v7 < 3u )
                goto LABEL_140;
              *(_QWORD *)(a2 + 288) = v15;
              goto LABEL_134;
            case 195:
              if ( *(_DWORD *)a1 >= 4u )
                ieee80211_parse_tpe(a2 + 488, v5 + 2, (unsigned int)v7);
              goto LABEL_134;
            case 196:
              if ( *(_DWORD *)a1 < 3u )
                goto LABEL_134;
              if ( (*(_BYTE *)(a1 + 24) & 1) != 0 )
              {
LABEL_142:
                LOBYTE(v19) = 8;
                goto LABEL_141;
              }
              elem_match = cfg80211_find_elem_match(194, v5 + 2, (unsigned int)v13, 0, 0, 0);
              if ( elem_match )
              {
                if ( *(unsigned __int8 *)(elem_match + 1) < 3u )
                {
                  v19 = 4;
                }
                else
                {
                  v19 = 0;
                  *(_QWORD *)(a2 + 288) = elem_match + 2;
                }
              }
              else
              {
                v19 = 0;
              }
              if ( *(_DWORD *)a1 >= 5u )
              {
                v63[0] = -121;
                v31 = cfg80211_find_elem_match(255, v15, (unsigned int)v13, v63, 1, 0);
                if ( v31 )
                {
                  v32 = (unsigned __int8)(*(_BYTE *)(v31 + 1) - 1);
                  if ( v32 >= 4 && ((v33 = v32 > 5, v34 = (_BYTE *)(v31 + 3), v33) || (*v34 & 2) == 0) )
                    *(_QWORD *)(a2 + 464) = v34;
                  else
                    v19 = 4;
                }
                v63[0] = -61;
                v54 = cfg80211_find_elem_match(255, v15, (unsigned int)v13, v63, 1, 0);
                if ( v54 )
                  ieee80211_parse_tpe(a2 + 592, v54 + 3, (unsigned int)*(unsigned __int8 *)(v54 + 1) - 1);
              }
              if ( !v19 )
                goto LABEL_134;
              goto LABEL_141;
            case 199:
              if ( *(_DWORD *)a1 < 3u )
                goto LABEL_134;
              if ( !(_BYTE)v7 )
                goto LABEL_140;
              *(_QWORD *)(a2 + 336) = v15;
LABEL_130:
              if ( v60 )
              {
                v28 = v61;
                v29 = v5;
                v30 = v9;
LABEL_132:
                v61 = crc32_be(v28, v29, v30);
              }
              goto LABEL_134;
            case 211:
              if ( *(_DWORD *)a1 )
                goto LABEL_134;
              if ( (unsigned __int8)v7 != 5 )
                goto LABEL_140;
              *(_QWORD *)(a2 + 424) = v15;
              goto LABEL_134;
            case 213:
              if ( *(_DWORD *)a1 )
                goto LABEL_134;
              if ( (unsigned __int8)v7 != 8 )
                goto LABEL_140;
              *(_QWORD *)(a2 + 416) = v15;
              goto LABEL_134;
            case 217:
              if ( *(_DWORD *)a1 )
                goto LABEL_134;
              if ( (unsigned __int8)v7 < 0xFu )
                goto LABEL_140;
              *(_QWORD *)(a2 + 400) = v15;
              goto LABEL_134;
            case 221:
              if ( (unsigned __int8)v7 >= 4u && !*v15 && v5[3] == 80 && v5[4] == 242 )
              {
                if ( v60 )
                  v61 = crc32_be(v61, v5, v9);
                if ( (unsigned __int8)v7 != 4 && v5[5] == 2 )
                {
                  if ( v5[6] == 1 )
                  {
                    *(_QWORD *)(a2 + 120) = v15;
                    *(_BYTE *)(a2 + 704) = v7;
                  }
                  else if ( !v5[6] )
                  {
                    *(_QWORD *)(a2 + 112) = v15;
                    *(_BYTE *)(a2 + 703) = v7;
                  }
                }
              }
              goto LABEL_134;
            case 232:
              if ( *(_DWORD *)a1 )
                goto LABEL_134;
              if ( (unsigned __int8)v7 == 6 )
              {
                *(_QWORD *)(a2 + 408) = v15;
LABEL_134:
                *(_QWORD *)((char *)v64 + ((v14 >> 3) & 0x18)) |= 1LL << v14;
                goto LABEL_135;
              }
LABEL_140:
              LOBYTE(v19) = 4;
LABEL_141:
              v16 = a2;
              v17 = *(_BYTE *)(a2 + 760) | v19;
              goto LABEL_12;
            case 244:
              *(_QWORD *)(a2 + 88) = v15;
              *(_BYTE *)(a2 + 701) = v7;
              goto LABEL_134;
            case 255:
              v20 = (unsigned __int8)*v8;
              if ( !*v8 )
                goto LABEL_134;
              break;
            default:
              goto LABEL_134;
          }
          break;
      }
      v21 = v5 + 3;
      v22 = v20 - 1;
      switch ( *v15 )
      {
        case 0x23:
          if ( v20 < 0x12 || *(_DWORD *)a1 < 4u )
            goto LABEL_134;
          v23 = v5[9];
          v24 = v23 >> 2;
          v25 = (v23 & 8) != 0 ? 8 : 4;
          v26 = v25 + (v24 & 4) + 17;
          if ( v26 > v22 )
            goto LABEL_134;
          if ( ((char)v5[15] & 0x80000000) == 0 )
            goto LABEL_122;
          if ( v26 < v22 )
          {
            v27 = *((_BYTE *)v21 + v26);
            v26 += ((unsigned int)(unsigned __int8)(_sw_hweight8(v27 & 0x78) * (6 * (v27 & 7) + 6) + 7) + 7) >> 3;
LABEL_122:
            if ( v26 <= v22 )
            {
              *(_QWORD *)(a2 + 168) = v21;
              *(_BYTE *)(a2 + 705) = v22;
            }
          }
          goto LABEL_134;
        case 0x24:
          if ( *(_DWORD *)a1 >= 4u )
          {
            if ( (unsigned __int8)(v20 - 1) >= 6u )
            {
              if ( v5 == (unsigned __int8 *)-3LL
                || ((*v21 & 0x4000) != 0 ? (v46 = 9) : (v46 = 6),
                    (v47 = v46 + ((*v21 >> 15) & 1), (*v21 & 0x20000) != 0) ? (v48 = v47 + 5) : (v48 = v47),
                    v48 <= v22) )
              {
                *(_QWORD *)(a2 + 176) = v21;
              }
            }
            goto LABEL_268;
          }
          goto LABEL_134;
        case 0x25:
          if ( (_BYTE)v20 != 1 && *(_DWORD *)a1 >= 4u )
            *(_QWORD *)(a2 + 208) = v21;
          goto LABEL_134;
        case 0x26:
          if ( *(_DWORD *)a1 >= 4u )
          {
            if ( (unsigned __int8)(v20 - 1) >= 0xDu )
              *(_QWORD *)(a2 + 192) = v21;
            goto LABEL_268;
          }
          goto LABEL_134;
        case 0x27:
          if ( (_BYTE)v20 != 1 && *(_DWORD *)a1 >= 4u )
          {
            if ( v5 == (unsigned __int8 *)-3LL
              || ((*(_BYTE *)v21 & 4) == 0 ? (v41 = 1) : (v41 = 2),
                  (*(_BYTE *)v21 & 8) != 0 ? (v42 = v41 + 18) : (v42 = v41),
                  v42 <= v22) )
            {
              *(_QWORD *)(a2 + 184) = v21;
            }
          }
          goto LABEL_134;
        case 0x34:
          if ( (unsigned __int8)(v20 - 1) == 3 )
            *(_QWORD *)(a2 + 296) = v21;
          goto LABEL_134;
        case 0x37:
          if ( (unsigned __int8)(v20 - 1) >= 2u )
            *(_QWORD *)(a2 + 368) = v21;
          goto LABEL_134;
        case 0x3B:
          if ( (unsigned __int8)(v20 - 1) >= 2u && *(_DWORD *)a1 >= 4u )
            *(_QWORD *)(a2 + 200) = v21;
          goto LABEL_134;
        case 0x6A:
          if ( *(_DWORD *)a1 >= 5u )
          {
            if ( v20 >= 6 )
            {
              v53 = (*(_BYTE *)v21 & 1) != 0 ? *(_BYTE *)v21 & 2 | 8 : 5;
              if ( v53 <= v22 )
                *(_QWORD *)(a2 + 440) = v21;
            }
            goto LABEL_268;
          }
          goto LABEL_134;
        case 0x6B:
          if ( *(_DWORD *)a1 < 5u )
            goto LABEL_134;
          if ( v5 == (unsigned __int8 *)-3LL || v20 < 3 )
            goto LABEL_268;
          v49 = *(unsigned __int16 *)v21;
          v50 = (unsigned __int8)(v20 - 1);
          v51 = v49 & 7;
          if ( v51 <= 1 )
          {
            if ( (v49 & 7) != 0 )
            {
              if ( v51 != 1 )
                goto LABEL_268;
              if ( (v49 & 0x10) != 0 )
                LOBYTE(v56) = 2;
              else
                LOBYTE(v56) = 1;
            }
            else
            {
              if ( (v49 & 0x10) != 0 )
                v58 = 8;
              else
                v58 = 7;
              v56 = v58
                  + (((unsigned __int8)(v49 & 0xE0) >> 5) & 1)
                  + (((unsigned __int8)v49 >> 5) & 2)
                  + ((v49 >> 6) & 2)
                  + ((v49 >> 7) & 2)
                  + ((v49 >> 9) & 1);
            }
          }
          else
          {
            if ( v51 == 2 )
            {
              v57 = (v49 & 0x10) == 0;
              v52 = 8;
              if ( v57 )
                v52 = 2;
              goto LABEL_253;
            }
            if ( v51 != 3 )
            {
              if ( v51 != 4 )
                goto LABEL_268;
              v52 = 9;
LABEL_253:
              if ( v52 > v50 )
                goto LABEL_268;
LABEL_262:
              if ( v51 == 2 )
              {
                *(_QWORD *)(a2 + 776) = v5;
              }
              else if ( !v51 )
              {
                if ( *(_QWORD *)(a2 + 768) )
                  *(_BYTE *)(a2 + 760) |= 0x10u;
                else
                  *(_QWORD *)(a2 + 768) = v5;
              }
              goto LABEL_268;
            }
            LOBYTE(v56) = 7;
          }
          if ( (unsigned __int64)(unsigned __int8)v56 + 2 > v50 || v5[5] < (unsigned int)(unsigned __int8)v56 )
            goto LABEL_268;
          goto LABEL_262;
        case 0x6C:
          if ( *(_DWORD *)a1 < 5u )
            goto LABEL_134;
          if ( (unsigned __int8)(v20 - 1) < 0xBu )
            goto LABEL_134;
          v35 = *(_QWORD *)(a2 + 168);
          if ( !v35 )
            goto LABEL_134;
          v36 = *(unsigned __int8 *)(v35 + 6);
          if ( (v36 & 2) != 0 )
          {
            v40 = 14;
          }
          else
          {
            v37 = (v36 << 29 >> 31) & 3;
            if ( (v36 & 8) != 0 )
              v37 += 3;
            if ( (v5[5] & 2) != 0 )
              v38 = v37 + 3;
            else
              v38 = v37;
            if ( *(_BYTE *)(a1 + 60) )
              v39 = 3;
            else
              v39 = 4;
            if ( !v38 )
              v38 = v39;
            v40 = v38 + 11;
          }
          if ( (unsigned __int8)v40 > (unsigned int)v22 )
            goto LABEL_134;
          if ( (v5[10] & 8) == 0 )
            goto LABEL_243;
          if ( (unsigned __int64)(unsigned __int8)v40 + 2 <= v22 )
          {
            v55 = *(_WORD *)((char *)v21 + (unsigned __int8)v40);
            v40 += ((unsigned int)_sw_hweight16(v55 & 0x1F0) * (6 * (v55 & 0xF) + 6) + 16) >> 3;
LABEL_243:
            if ( (unsigned __int8)v40 <= (unsigned int)v22 )
            {
              *(_QWORD *)(a2 + 432) = v21;
              *(_BYTE *)(a2 + 713) = v22;
            }
          }
          goto LABEL_134;
        case 0x6D:
          if ( *(_DWORD *)a1 < 5u )
            goto LABEL_134;
          if ( (_BYTE)v20 == 1 )
            goto LABEL_268;
          v43 = *(unsigned __int8 *)v21;
          if ( (v43 & 0x10) != 0 )
            v44 = ((v43 >> 2) & 2) + 3;
          else
            v44 = (v43 >> 2) & 2;
          if ( (v43 & 4) != 0 )
            goto LABEL_193;
          if ( v44 + 2 <= (unsigned int)v22 )
          {
            v44 += ((unsigned int)_sw_hweight8(v5[4]) << ((v43 & 0x20) == 0)) + 1;
LABEL_193:
            if ( (unsigned __int8)v44 < (unsigned int)v22 )
            {
              v45 = *(unsigned __int8 *)(a2 + 736);
              if ( v45 <= 1 )
              {
                *(_QWORD *)(v59 + 8 * v45) = v21;
                ++*(_BYTE *)(a2 + 736);
              }
            }
          }
LABEL_268:
          if ( !v60 )
            goto LABEL_134;
          v28 = v61;
          v29 = v5;
          v30 = (unsigned __int8)*v8 + 2LL;
          goto LABEL_132;
        case 0x87:
          if ( *(_DWORD *)a1 < 5u )
            goto LABEL_134;
          if ( v20 >= 5 && ((unsigned __int8)(v20 - 1) > 5u || (*(_BYTE *)v21 & 2) == 0) )
            *(_QWORD *)(a2 + 464) = v21;
          goto LABEL_268;
        default:
          goto LABEL_134;
      }
    }
  }
LABEL_3:
  if ( v6 != v5 )
    *(_BYTE *)(a2 + 760) |= 1u;
  _ReadStatusReg(SP_EL0);
  return v61;
}
