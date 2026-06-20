__int64 __fastcall ieee80211_key_alloc(int a1, unsigned int a2, size_t a3, const void *a4, __int64 a5, _BYTE *a6)
{
  char v9; // w25
  unsigned __int64 v11; // x22
  __int64 v12; // x19
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x9
  const char *v15; // x0
  unsigned __int16 v16; // w8
  char v17; // w9
  char v18; // w10
  char v19; // w8
  char v20; // w9
  char v21; // w8
  unsigned __int64 v22; // x0
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x9
  __int64 v25; // x1
  __int64 v26; // x2
  unsigned int v27; // w3
  char v28; // w8
  char v29; // w9
  char v30; // w10
  char v31; // w8
  char v32; // w9
  char v33; // w8
  __int64 v34; // x8
  __int64 v35; // x9
  __int64 v36; // x10
  unsigned __int64 v37; // x0
  unsigned __int64 StatusReg; // x26
  __int64 v39; // x27

  if ( a2 >= 8 )
  {
    __break(0x800u);
    return -22;
  }
  v9 = a2;
  v11 = a3 + 560;
  v12 = _kmalloc_noprof(a3 + 560, 3520);
  if ( !v12 )
    return -12;
  while ( 1 )
  {
    if ( v11 < 0x228 )
      goto LABEL_124;
    if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x228 )
      goto LABEL_124;
    *(_WORD *)(v12 + 552) = 0;
    if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x28 )
      goto LABEL_124;
    *(_DWORD *)(v12 + 40) = 0;
    if ( v11 < 0x22B )
      goto LABEL_124;
    *(_BYTE *)(v12 + 554) = -1;
    if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x220 )
      goto LABEL_124;
    *(_DWORD *)(v12 + 544) = a1;
    *(_BYTE *)(v12 + 551) = v9;
    if ( v11 == 555 )
      goto LABEL_124;
    *(_BYTE *)(v12 + 555) = a3;
    if ( a1 > 1027079 )
    {
      if ( a1 <= 1027082 )
      {
        if ( (unsigned int)(a1 - 1027080) >= 2 )
        {
          *(_WORD *)(v12 + 548) = 2064;
          if ( a6 )
          {
            v23 = -1;
            v24 = 53;
            while ( (__int64)(v24 - 5) >= 0 )
            {
              if ( v11 <= v24 - 5 )
                break;
              *(_BYTE *)(v12 + v24 - 5) = a6[5];
              if ( (__int64)(v24 - 4) < 0 )
                break;
              if ( v11 <= v24 - 4 )
                break;
              *(_BYTE *)(v12 + v24 - 4) = a6[4];
              if ( (__int64)(v24 - 3) < 0 )
                break;
              if ( v11 <= v24 - 3 )
                break;
              *(_BYTE *)(v12 + v24 - 3) = a6[3];
              if ( (__int64)(v24 - 2) < 0 )
                break;
              if ( v11 <= v24 - 2 )
                break;
              *(_BYTE *)(v12 + v24 - 2) = a6[2];
              if ( (__int64)(v24 - 1) < 0 )
                break;
              if ( v11 <= v24 - 1 )
                break;
              *(_BYTE *)(v12 + v24 - 1) = a6[1];
              if ( (v24 & 0x8000000000000000LL) != 0 || v11 <= v24 )
                break;
              ++v23;
              *(_BYTE *)(v12 + v24) = *a6;
              v24 += 6LL;
              if ( v23 >= 0x10 )
                goto LABEL_90;
            }
            goto LABEL_124;
          }
LABEL_90:
          v15 = "ccm(aes)";
        }
        else
        {
          *(_WORD *)(v12 + 548) = 2064;
          if ( a6 )
          {
            v13 = -1;
            v14 = 53;
            while ( (__int64)(v14 - 5) >= 0 )
            {
              if ( v11 <= v14 - 5 )
                break;
              *(_BYTE *)(v12 + v14 - 5) = a6[5];
              if ( (__int64)(v14 - 4) < 0 )
                break;
              if ( v11 <= v14 - 4 )
                break;
              *(_BYTE *)(v12 + v14 - 4) = a6[4];
              if ( (__int64)(v14 - 3) < 0 )
                break;
              if ( v11 <= v14 - 3 )
                break;
              *(_BYTE *)(v12 + v14 - 3) = a6[3];
              if ( (__int64)(v14 - 2) < 0 )
                break;
              if ( v11 <= v14 - 2 )
                break;
              *(_BYTE *)(v12 + v14 - 2) = a6[2];
              if ( (__int64)(v14 - 1) < 0 )
                break;
              if ( v11 <= v14 - 1 )
                break;
              *(_BYTE *)(v12 + v14 - 1) = a6[1];
              if ( (v14 & 0x8000000000000000LL) != 0 || v11 <= v14 )
                break;
              ++v13;
              *(_BYTE *)(v12 + v14) = *a6;
              v14 += 6LL;
              if ( v13 >= 0x10 )
                goto LABEL_27;
            }
LABEL_124:
            __break(1u);
            goto LABEL_125;
          }
LABEL_27:
          v15 = "gcm(aes)";
        }
        v25 = (__int64)a4;
        v26 = a3;
        v27 = 16;
        goto LABEL_119;
      }
      if ( (unsigned int)(a1 - 1027083) < 2 )
      {
        *(_WORD *)(v12 + 548) = 26;
        if ( a6 )
        {
          v17 = a6[4];
          v18 = a6[3];
          *(_BYTE *)(v12 + 48) = a6[5];
          v19 = a6[2];
          *(_BYTE *)(v12 + 49) = v17;
          v20 = a6[1];
          *(_BYTE *)(v12 + 51) = v19;
          v21 = *a6;
          *(_BYTE *)(v12 + 50) = v18;
          *(_BYTE *)(v12 + 52) = v20;
          *(_BYTE *)(v12 + 53) = v21;
        }
        v22 = ieee80211_aes_gmac_key_setup();
LABEL_100:
        if ( (v11 & 0xFFFFFFFFFFFFFFF8LL) == 0x38 )
          goto LABEL_124;
        a6 = (_BYTE *)v22;
        *(_QWORD *)(v12 + 56) = v22;
        if ( v22 >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_102;
        goto LABEL_121;
      }
      v16 = -21491;
LABEL_93:
      if ( a1 != (v16 | 0xF0000) )
        goto LABEL_121;
      *(_BYTE *)(v12 + 549) = 0;
      if ( a1 == 1027078 )
        v28 = 18;
      else
        v28 = 26;
      *(_BYTE *)(v12 + 548) = v28;
      if ( a6 )
      {
        v29 = a6[4];
        v30 = a6[3];
        *(_BYTE *)(v12 + 48) = a6[5];
        v31 = a6[2];
        *(_BYTE *)(v12 + 49) = v29;
        v32 = a6[1];
        *(_BYTE *)(v12 + 51) = v31;
        v33 = *a6;
        *(_BYTE *)(v12 + 50) = v30;
        *(_BYTE *)(v12 + 52) = v32;
        *(_BYTE *)(v12 + 53) = v33;
      }
      v22 = ieee80211_aes_cmac_key_setup();
      goto LABEL_100;
    }
    if ( a1 > 1027075 )
    {
      if ( a1 == 1027076 )
      {
        *(_WORD *)(v12 + 548) = 2056;
        if ( a6 )
        {
          v34 = 0;
          v35 = v12 + 48;
          while ( v34 + 48 >= 0 )
          {
            if ( v11 <= v34 + 48 )
              break;
            *(_BYTE *)(v35 + v34) = a6[5];
            if ( v34 + 49 < 0 )
              break;
            if ( v11 <= v34 + 49 )
              break;
            *(_BYTE *)(v35 + v34 + 1) = a6[4];
            if ( v34 + 50 < 0 )
              break;
            if ( v11 <= v34 + 50 )
              break;
            *(_BYTE *)(v35 + v34 + 2) = a6[3];
            if ( v34 + 51 < 0 )
              break;
            if ( v11 <= v34 + 51 )
              break;
            *(_BYTE *)(v35 + v34 + 3) = a6[2];
            if ( v34 + 52 < 0 )
              break;
            if ( v11 <= v34 + 52 )
              break;
            *(_BYTE *)(v35 + v34 + 4) = a6[1];
            if ( v34 + 53 < 0 || v11 <= v34 + 53 )
              break;
            v36 = v35 + v34;
            v34 += 6;
            *(_BYTE *)(v36 + 5) = *a6;
            if ( v34 == 102 )
              goto LABEL_118;
          }
          goto LABEL_124;
        }
LABEL_118:
        v15 = "ccm(aes)";
        v25 = (__int64)a4;
        v26 = a3;
        v27 = 8;
LABEL_119:
        v37 = aead_key_setup_encrypt((__int64)v15, v25, v26, v27);
        if ( (v11 & 0xFFFFFFFFFFFFFFF8LL) == 0x98 )
          goto LABEL_124;
        a6 = (_BYTE *)v37;
        *(_QWORD *)(v12 + 152) = v37;
        if ( v37 >= 0xFFFFFFFFFFFFF001LL )
        {
LABEL_102:
          kfree(v12);
          return (int)a6;
        }
        goto LABEL_121;
      }
      if ( a1 == 1027077 )
        goto LABEL_74;
      v16 = -21498;
      goto LABEL_93;
    }
    if ( a1 == 1027073 )
    {
LABEL_74:
      *(_WORD *)(v12 + 548) = 1028;
      goto LABEL_121;
    }
    if ( a1 == 1027074 )
    {
      *(_WORD *)(v12 + 548) = 2052;
      if ( a6 )
      {
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x5C )
          goto LABEL_124;
        *(_DWORD *)(v12 + 92) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x60 )
          goto LABEL_124;
        *(_WORD *)(v12 + 96) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x78 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 120) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x7C )
          goto LABEL_124;
        *(_WORD *)(v12 + 124) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x94 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 148) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x98 )
          goto LABEL_124;
        *(_WORD *)(v12 + 152) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0xB0 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 176) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0xB4 )
          goto LABEL_124;
        *(_WORD *)(v12 + 180) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0xCC )
          goto LABEL_124;
        *(_DWORD *)(v12 + 204) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0xD0 )
          goto LABEL_124;
        *(_WORD *)(v12 + 208) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0xE8 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 232) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0xEC )
          goto LABEL_124;
        *(_WORD *)(v12 + 236) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x104 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 260) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x108 )
          goto LABEL_124;
        *(_WORD *)(v12 + 264) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x120 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 288) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x124 )
          goto LABEL_124;
        *(_WORD *)(v12 + 292) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x13C )
          goto LABEL_124;
        *(_DWORD *)(v12 + 316) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x140 )
          goto LABEL_124;
        *(_WORD *)(v12 + 320) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x158 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 344) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x15C )
          goto LABEL_124;
        *(_WORD *)(v12 + 348) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x174 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 372) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x178 )
          goto LABEL_124;
        *(_WORD *)(v12 + 376) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x190 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 400) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x194 )
          goto LABEL_124;
        *(_WORD *)(v12 + 404) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x1AC )
          goto LABEL_124;
        *(_DWORD *)(v12 + 428) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x1B0 )
          goto LABEL_124;
        *(_WORD *)(v12 + 432) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x1C8 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 456) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x1CC )
          goto LABEL_124;
        *(_WORD *)(v12 + 460) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x1E4 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 484) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x1E8 )
          goto LABEL_124;
        *(_WORD *)(v12 + 488) = *(_WORD *)a6;
        if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x200 )
          goto LABEL_124;
        *(_DWORD *)(v12 + 512) = *(_DWORD *)(a6 + 2);
        if ( (v11 & 0xFFFFFFFFFFFFFFFELL) == 0x204 )
          goto LABEL_124;
        *(_WORD *)(v12 + 516) = *(_WORD *)a6;
      }
      if ( (v11 & 0xFFFFFFFFFFFFFFFCLL) == 0x30 )
        goto LABEL_124;
      *(_DWORD *)(v12 + 48) = 0;
    }
LABEL_121:
    if ( v11 - 556 >= a3 )
      break;
LABEL_125:
    _fortify_panic(17);
    v11 = a3 + 560;
    StatusReg = _ReadStatusReg(SP_EL0);
    v39 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ieee80211_key_alloc__alloc_tag;
    v12 = _kmalloc_noprof(a3 + 560, 3520);
    *(_QWORD *)(StatusReg + 80) = v39;
    if ( !v12 )
      return -12;
  }
  memcpy((void *)(v12 + 556), a4, a3);
  *(_QWORD *)(v12 + 24) = v12 + 24;
  *(_QWORD *)(v12 + 32) = v12 + 24;
  return v12;
}
