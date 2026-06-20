void *__fastcall ieee80211_add_rx_radiotap_header(__int64 a1, __int64 a2, __int64 a3, int a4, char a5)
{
  char v10; // w28
  int v11; // w8
  __int64 *v12; // x8
  int v13; // w8
  unsigned int v14; // w23
  __int64 v15; // x8
  size_t v16; // x26
  __int64 v17; // x20
  void *result; // x0
  unsigned __int64 v19; // x26
  int v20; // w8
  unsigned int *v21; // x24
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x9
  _QWORD *v24; // x24
  char v25; // w21
  __int64 v26; // x25
  __int64 v27; // x22
  char *v28; // x8
  unsigned int v29; // w8
  int v30; // w8
  int v31; // w9
  unsigned int v32; // w8
  unsigned int v33; // w9
  int v34; // w8
  __int16 v35; // w8
  __int16 v36; // w9
  _BYTE *v37; // x8
  _BYTE *v38; // x22
  char v39; // w9
  char v40; // w10
  char v41; // w9
  unsigned int v42; // w10
  _BYTE *v43; // x8
  char v44; // w9
  int v45; // w10
  __int16 v46; // w9
  char v47; // w8
  char v48; // w8
  _BYTE *v49; // x8
  __int64 v50; // x10
  char v51; // w9
  int v52; // w10
  int v53; // w11
  char v54; // w9
  int v55; // w8
  int v56; // w8
  unsigned int v57; // w9
  unsigned int v58; // w1
  int v59; // w23
  __int16 v60; // w21
  __int16 v61; // w24
  _BYTE *v62; // x10
  _BYTE *v63; // x9
  _DWORD *v64; // x22
  char v65; // w10
  unsigned __int64 v66; // x10
  unsigned __int64 v67; // x10
  char v68; // w11
  bool v69; // cf
  __int16 v70; // [xsp+8h] [xbp-38h]
  int v71; // [xsp+Ch] [xbp-34h]
  __int64 v72; // [xsp+10h] [xbp-30h]
  __int64 v73; // [xsp+18h] [xbp-28h]
  _DWORD *v74; // [xsp+20h] [xbp-20h]
  __int64 v75; // [xsp+28h] [xbp-18h]
  int v76; // [xsp+30h] [xbp-10h]

  _ReadStatusReg(SP_EL0);
  v10 = *(_BYTE *)(a2 + 79);
  v76 = 0;
  v75 = 0;
  if ( (*(_BYTE *)(a2 + 67) & 4) != 0 )
  {
    v15 = *(_QWORD *)(a2 + 224);
    LODWORD(v73) = *(_DWORD *)v15;
    HIDWORD(v73) = *(unsigned __int16 *)(v15 + 4);
    LOWORD(v72) = *(_WORD *)(v15 + 8);
    WORD2(v72) = *(_WORD *)(v15 + 6);
    v70 = *(_WORD *)(v15 + 10);
    skb_pull(a2, 12);
    if ( (*(_BYTE *)(a2 + 71) & 7) == 3 )
    {
      v11 = *(_DWORD *)(a2 + 64);
      if ( (v11 & 0x8000000) == 0 )
        goto LABEL_9;
    }
    else
    {
      __break(0x800u);
      v11 = *(_DWORD *)(a2 + 64);
      if ( (v11 & 0x8000000) == 0 )
        goto LABEL_9;
    }
LABEL_3:
    v12 = *(__int64 **)(a2 + 224);
    v75 = *v12;
    v76 = *((_DWORD *)v12 + 2);
    skb_pull(a2, 12);
    v11 = *(_DWORD *)(a2 + 64);
    if ( (v11 & 0x10000000) != 0 )
      goto LABEL_4;
    goto LABEL_10;
  }
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v11 = *(_DWORD *)(a2 + 64);
  if ( (v11 & 0x8000000) != 0 )
    goto LABEL_3;
LABEL_9:
  if ( (v11 & 0x10000000) != 0 )
  {
LABEL_4:
    v71 = **(_DWORD **)(a2 + 224);
    skb_pull(a2, 4);
    if ( (*(_DWORD *)(a2 + 64) & 0x100000) == 0 )
      goto LABEL_5;
LABEL_11:
    v13 = *(_DWORD *)(a2 + 224) - (*(_DWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 186));
    v14 = *(_DWORD *)(a2 + 112);
    if ( (a5 & 1) != 0 )
      goto LABEL_12;
    goto LABEL_13;
  }
LABEL_10:
  v71 = 0;
  if ( (v11 & 0x100000) != 0 )
    goto LABEL_11;
LABEL_5:
  v13 = 0;
  v14 = *(_DWORD *)(a2 + 112);
  if ( (a5 & 1) != 0 )
  {
LABEL_12:
    if ( (*(_QWORD *)(a1 + 96) & 2) != 0 )
      goto LABEL_14;
  }
LABEL_13:
  v14 += 4;
LABEL_14:
  v16 = (unsigned int)(v13 + a4);
  v17 = skb_push(a2, (unsigned int)v16);
  result = memset((void *)v17, 0, v16);
  *(_WORD *)(v17 + 2) = a4;
  v19 = v10 & 0xF;
  v74 = (_DWORD *)(v17 + 4);
  if ( *(_BYTE *)(a2 + 79) )
    v20 = 16394;
  else
    v20 = 18442;
  if ( (v10 & 0xF) != 0 )
  {
    v21 = (unsigned int *)(v17 + 8);
    v22 = __clz(__rbit64(v19));
    *(_DWORD *)(v17 + 4) = v20 | 0xA0000000;
    if ( v22 <= 2 )
    {
      do
      {
        v23 = (-2LL << v22) & v19;
        if ( !v23 )
          break;
        *v21++ = -1610610656;
        v22 = __clz(__rbit64(v23));
      }
      while ( v22 < 3 );
    }
    v20 = 2080;
  }
  else
  {
    v21 = (unsigned int *)(v17 + 4);
  }
  *v21 = v20 & 0xEFFFFFFF | (((*(_DWORD *)(a2 + 64) >> 20) & 1) << 28);
  v24 = v21 + 1;
  if ( (*(_BYTE *)(a2 + 66) & 3) != 0 )
  {
    if ( (((int)v24 - (int)v17) & 7LL) != 0 )
    {
      v25 = a5;
      v26 = a3;
      v27 = (12 - ((_BYTE)v24 - (_BYTE)v17)) & 7;
      memset(v24, 0, v27 + 4);
      v28 = (char *)v24 + v27 - 8;
      a3 = v26;
      a5 = v25;
      v24 = v28 + 12;
    }
    result = (void *)((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))ieee80211_calculate_rx_timestamp)(
                       a1,
                       a2 + 40,
                       v14,
                       0);
    *v24++ = result;
    *v74 |= 1u;
  }
  if ( (a5 & 1) != 0 && (*(_QWORD *)(a1 + 96) & 2) != 0 )
    *(_BYTE *)v24 |= 0x10u;
  if ( (*(_BYTE *)(a2 + 64) & 0x60) != 0 )
    *(_BYTE *)v24 |= 0x40u;
  if ( (*(_BYTE *)(a2 + 70) & 1) != 0 )
    *(_BYTE *)v24 |= 2u;
  if ( a3 && (*(_BYTE *)(a2 + 71) & 7) == 0 )
  {
    *v74 |= 4u;
    v30 = (*(unsigned __int8 *)(a2 + 71) >> 3) & 0xF;
    if ( v30 == 1 )
      v31 = 20;
    else
      v31 = 5;
    if ( v30 == 2 )
      v32 = 10;
    else
      v32 = v31;
    v29 = (*(unsigned __int16 *)(a3 + 4) + v32 - 1) / v32;
  }
  else
  {
    LOBYTE(v29) = 0;
  }
  *((_BYTE *)v24 + 1) = v29;
  *((_WORD *)v24 + 1) = *(_WORD *)(a2 + 68) & 0x1FFF;
  v33 = *(unsigned __int8 *)(a2 + 71);
  v34 = (v33 >> 3) & 0xF;
  if ( v34 == 2 )
    v35 = 0x4000;
  else
    v35 = (v34 == 1) << 15;
  if ( (*(unsigned __int8 *)(a2 + 76) | 2) == 3 )
  {
    v36 = 320;
  }
  else
  {
    v45 = v33 & 7;
    if ( (v33 & 7) != 0 )
      v36 = 1152;
    else
      v36 = 128;
    if ( !v45 && a3 )
    {
      if ( (*(_BYTE *)a3 & 0x10) != 0 )
        v36 = 192;
      else
        v36 = 160;
    }
  }
  *((_WORD *)v24 + 2) = v35 | v36;
  v37 = (char *)v24 + 6;
  if ( (*(_QWORD *)(a1 + 96) & 0x10) != 0 && (*(_BYTE *)(a2 + 65) & 1) == 0 )
  {
    *((_BYTE *)v24 + 6) = *(_BYTE *)(a2 + 78);
    *v74 |= 0x20u;
    v37 = (char *)v24 + 7;
  }
  if ( *(_BYTE *)(a2 + 79) )
  {
    if ( (((_DWORD)v37 - (_DWORD)v17) & 1) == 0 )
      goto LABEL_55;
    goto LABEL_54;
  }
  *v37++ = *(_BYTE *)(a2 + 77);
  if ( (((_DWORD)v37 - (_DWORD)v17) & 1) != 0 )
LABEL_54:
    *v37++ = 0;
LABEL_55:
  *(_WORD *)v37 = (*(_WORD *)(a2 + 64) >> 5) & 2;
  v38 = v37 + 2;
  if ( (*(_BYTE *)(a2 + 71) & 7) != 1 )
    goto LABEL_68;
  *v74 |= 0x80000u;
  v39 = *(_BYTE *)(a1 + 142);
  *v38 = v39;
  v40 = *(_BYTE *)(a2 + 70);
  if ( (v40 & 8) != 0 )
  {
    v39 |= 8u;
    *v38 = v39;
    v40 = *(_BYTE *)(a2 + 70);
  }
  if ( (v40 & 0x40) != 0 )
    *v38 = v39 | 0x10;
  v37[3] = 0;
  v41 = *(_BYTE *)(a2 + 70) & 4;
  v37[3] = v41;
  if ( (*(_BYTE *)(a2 + 71) & 0x78) == 0x18 )
  {
    v41 |= 1u;
    v37[3] = v41;
    v42 = *(unsigned __int8 *)(a2 + 70);
    if ( (v42 & 8) != 0 )
      goto LABEL_62;
  }
  else
  {
    v42 = *(unsigned __int8 *)(a2 + 70);
    if ( (v42 & 8) != 0 )
    {
LABEL_62:
      v41 |= 8u;
      v37[3] = v41;
      v42 = *(unsigned __int8 *)(a2 + 70);
      if ( (v42 & 0x40) == 0 )
        goto LABEL_67;
      goto LABEL_66;
    }
  }
  if ( (v42 & 0x40) != 0 )
  {
LABEL_66:
    v41 |= 0x10u;
    v37[3] = v41;
    v42 = *(unsigned __int8 *)(a2 + 70);
  }
LABEL_67:
  v38 = v37 + 5;
  v37[3] = v41 & 0x9F | (32 * ((v42 >> 4) & 3));
  v37[4] = *(_BYTE *)(a2 + 73);
LABEL_68:
  if ( (*(_BYTE *)(a2 + 65) & 2) != 0 )
  {
    *(_DWORD *)(v17 + 4) |= 0x100000u;
    v43 = &v38[((_BYTE)v17 - (_BYTE)v38) & 3];
    *(_DWORD *)v43 = *(_DWORD *)(a2 + 60);
    *((_WORD *)v43 + 2) = (*(_DWORD *)(a2 + 64) >> 10) & 0x3C | (*(_DWORD *)(a2 + 64) >> 18) & 0xC0;
    if ( (*(_BYTE *)(a2 + 65) & 0x80) != 0 )
      v44 = *(_BYTE *)(a2 + 84);
    else
      v44 = 0;
    v38 = v43 + 8;
    v43[6] = v44;
    v43[7] = 0;
  }
  if ( (*(_BYTE *)(a2 + 71) & 7) == 2 )
  {
    v46 = *(_WORD *)(a1 + 144);
    *v74 |= 0x200000u;
    *(_WORD *)v38 = v46;
    v47 = *(_BYTE *)(a2 + 70);
    if ( (v47 & 4) != 0 )
    {
      v38[2] |= 4u;
      v47 = *(_BYTE *)(a2 + 70);
    }
    if ( (v47 & 0x30) != 0 )
    {
      v38[2] |= 1u;
      v47 = *(_BYTE *)(a2 + 70);
    }
    if ( v47 < 0 )
      v38[2] |= 0x20u;
    if ( ((*(unsigned __int8 *)(a2 + 71) >> 3) & 0xFu) >= 6 )
      v48 = 0;
    else
      v48 = 0xB0401000000uLL >> (8 * ((*(_BYTE *)(a2 + 71) >> 3) & 0xFu));
    v38[3] = v48;
    v38[4] = *(_BYTE *)(a2 + 74) | (16 * *(_BYTE *)(a2 + 73));
    if ( (*(_BYTE *)(a2 + 70) & 0x40) != 0 )
      v38[8] |= 1u;
    v38 += 12;
  }
  if ( (*(_DWORD *)(a1 + 148) & 0x80000000) == 0 )
  {
    *(_DWORD *)(v17 + 4) |= 0x400000u;
    v49 = &v38[((_BYTE)v17 - (_BYTE)v38) & 7];
    if ( (*(_BYTE *)(a2 + 64) & 0x80) != 0 )
    {
      v50 = *(_QWORD *)(a2 + 40);
      v51 = 0;
    }
    else
    {
      v50 = *(unsigned int *)(a2 + 56);
      v51 = 1;
    }
    *(_QWORD *)v49 = v50;
    v38 = v49 + 12;
    v52 = *(__int16 *)(a1 + 152);
    if ( v52 >= 0 )
      v51 |= 2u;
    *((_WORD *)v49 + 4) = v52 & ~(unsigned __int16)((unsigned int)v52 >> 15);
    v53 = *(_DWORD *)(a1 + 148);
    v49[11] = v51;
    v49[10] = v53;
  }
  v54 = *(_BYTE *)(a2 + 71);
  v55 = *(_DWORD *)(a2 + 64);
  if ( (v54 & 7) == 3 && (v55 & 0x4000000) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 70) & 0x30) != 0 )
    {
      v56 = (unsigned __int8)(*(_BYTE *)(a2 + 70) & 0x30) >> 4;
      HIDWORD(v73) = WORD2(v73) | 0xFFFF8000;
    }
    else
    {
      LOWORD(v56) = *(_BYTE *)(a2 + 74) & 0xF;
    }
    v57 = *(unsigned __int8 *)(a2 + 72);
    v58 = (*(unsigned __int8 *)(a2 + 71) >> 3) & 0xF;
    v59 = HIDWORD(v73)
        | ((*(_BYTE *)(a2 + 73) & 0xF) << 8)
        | (((v57 >> 5) & 1) << 12)
        | (((*(unsigned __int8 *)(a2 + 70) >> 6) & 1) << 13);
    v60 = v70 | v56;
    v61 = v72 | (2 * v57) & 0x30;
    if ( v58 <= 3 )
    {
      if ( !v58 )
        goto LABEL_120;
      if ( v58 == 3 )
      {
        v61 |= 1u;
        goto LABEL_120;
      }
    }
    else
    {
      switch ( v58 )
      {
        case 4u:
          v61 |= 2u;
          goto LABEL_120;
        case 5u:
          v61 |= 3u;
          goto LABEL_120;
        case 6u:
          v61 |= (v57 & 7) + 4;
LABEL_120:
          v62 = &v38[((_BYTE)v38 - (_BYTE)v17) & 1];
          *(_DWORD *)(v17 + 4) |= 0x800000u;
          v38 = v62 + 12;
          *((_WORD *)v62 + 2) = v59;
          *((_WORD *)v62 + 4) = v61;
          *(_DWORD *)v62 = v73;
          *((_WORD *)v62 + 3) = WORD2(v72);
          *((_WORD *)v62 + 5) = v60;
          v54 = *(_BYTE *)(a2 + 71);
          v55 = *(_DWORD *)(a2 + 64);
          goto LABEL_121;
      }
    }
    if ( (ieee80211_add_rx_radiotap_header___already_done & 1) == 0 )
    {
      ieee80211_add_rx_radiotap_header___already_done = 1;
      result = (void *)_warn_printk("Invalid SU BW %d\n", v58);
      __break(0x800u);
    }
    goto LABEL_120;
  }
LABEL_121:
  if ( (v54 & 7) == 3 && (v55 & 0x8000000) != 0 )
  {
    v63 = &v38[((_BYTE)v38 - (_BYTE)v17) & 1];
    *(_DWORD *)(v17 + 4) |= 0x1000000u;
    v38 = v63 + 12;
    *((_DWORD *)v63 + 2) = v76;
    *(_QWORD *)v63 = v75;
    v55 = *(_DWORD *)(a2 + 64);
  }
  if ( (v55 & 0x20000000) != 0 )
  {
    *v74 |= 0x4000000u;
    *v38++ = *(_BYTE *)(a2 + 85);
    v55 = *(_DWORD *)(a2 + 64);
  }
  if ( (v55 & 0x10000000) != 0 )
  {
    v64 = &v38[((_BYTE)v38 - (_BYTE)v17) & 1];
    *(_DWORD *)(v17 + 4) |= 0x8000000u;
    *v64 = v71;
    v38 = v64 + 1;
  }
  v65 = 0;
  do
  {
    v66 = (-1LL << v65) & v19;
    if ( !v66 )
      break;
    v67 = __clz(__rbit64(v66));
    v68 = *(_BYTE *)(a2 + 80 + v67);
    v69 = v67 >= 3;
    v38[1] = v67;
    v65 = v67 + 1;
    *v38 = v68;
    v38 += 2;
  }
  while ( !v69 );
  _ReadStatusReg(SP_EL0);
  return result;
}
