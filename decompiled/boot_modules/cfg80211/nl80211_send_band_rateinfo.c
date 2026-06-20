__int64 __fastcall nl80211_send_band_rateinfo(__int64 a1, __int64 a2, char a3)
{
  __int64 v6; // x21
  __int64 v7; // x22
  int v8; // w8
  __int64 result; // x0
  _WORD *v10; // x24
  unsigned __int16 *v11; // x28
  unsigned __int64 v12; // x21
  __int64 v13; // x22
  __int64 v14; // x23
  int v15; // w8
  _WORD *v16; // x25
  unsigned int v17; // w23
  __int64 v18; // x22
  __int64 v19; // x26
  int v20; // w8
  _WORD *v21; // x26
  unsigned int v22; // w22
  bool v23; // cc
  int v24; // w8
  int v25; // w9
  int v26; // w8
  int v27; // w9
  unsigned int v28; // w22
  unsigned int v29; // w23
  unsigned __int16 v30; // w23
  __int64 v31; // x3
  __int64 v32; // x2
  __int64 v33; // x21
  __int64 v34; // x22
  int v35; // w8
  _WORD *v36; // x22
  __int64 v37; // x23
  __int64 v38; // x21
  __int64 v39; // x24
  __int64 v40; // x25
  int v41; // w8
  _WORD *v42; // x24
  __int64 v43; // x25
  int v44; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a2 + 30) == 1 )
  {
    if ( (unsigned int)nla_put(a1, 3, 16, a2 + 33) )
      goto LABEL_79;
    LOWORD(v44) = *(_WORD *)(a2 + 28);
    if ( (unsigned int)nla_put(a1, 4, 2, &v44) )
      goto LABEL_79;
    LOBYTE(v44) = *(_BYTE *)(a2 + 31);
    if ( (unsigned int)nla_put(a1, 5, 1, &v44) )
      goto LABEL_79;
    LOBYTE(v44) = *(_BYTE *)(a2 + 32);
    if ( (unsigned int)nla_put(a1, 6, 1, &v44) )
      goto LABEL_79;
  }
  if ( *(_BYTE *)(a2 + 52) == 1 )
  {
    if ( (unsigned int)nla_put(a1, 7, 8, a2 + 60) )
      goto LABEL_79;
    v44 = *(_DWORD *)(a2 + 56);
    if ( (unsigned int)nla_put(a1, 8, 4, &v44) )
      goto LABEL_79;
  }
  if ( (a3 & 1) == 0 )
  {
LABEL_64:
    v33 = *(_QWORD *)(a1 + 216);
    v34 = *(unsigned int *)(a1 + 208);
    v35 = nla_put(a1, 2, 0, 0);
    result = 4294967191LL;
    if ( v35 < 0 )
      goto LABEL_80;
    v36 = (_WORD *)(v33 + v34);
    if ( !v36 )
      goto LABEL_80;
    if ( *(int *)(a2 + 24) >= 1 )
    {
      v37 = 0;
      v38 = 0;
      do
      {
        v39 = *(_QWORD *)(a1 + 216);
        v40 = *(unsigned int *)(a1 + 208);
        v41 = nla_put(a1, (unsigned int)v38, 0, 0);
        result = 4294967191LL;
        if ( v41 < 0 )
          goto LABEL_80;
        v42 = (_WORD *)(v39 + v40);
        if ( !v42 )
          goto LABEL_80;
        v43 = *(_QWORD *)(a2 + 8);
        v44 = *(unsigned __int16 *)(v43 + v37 + 4);
        if ( (unsigned int)nla_put(a1, 1, 4, &v44)
          || (*(_BYTE *)(v43 + v37) & 1) != 0 && (unsigned int)nla_put(a1, 2, 0, 0) )
        {
          goto LABEL_79;
        }
        ++v38;
        v37 += 12;
        *v42 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v42;
      }
      while ( v38 < *(int *)(a2 + 24) );
    }
    *v36 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v36;
    if ( *(_DWORD *)(a2 + 16) != 4
      || *(_BYTE *)(a2 + 68) != 1
      || !(unsigned int)nla_put(a1, 13, 10, a2 + 69) && !(unsigned int)nla_put(a1, 12, 5, a2 + 79) )
    {
      result = 0;
      goto LABEL_80;
    }
LABEL_79:
    result = 4294967191LL;
    goto LABEL_80;
  }
  if ( !*(_WORD *)(a2 + 92) )
  {
LABEL_61:
    if ( *(_BYTE *)(a2 + 84) )
    {
      LOBYTE(v44) = *(_BYTE *)(a2 + 84);
      if ( (unsigned int)nla_put(a1, 10, 1, &v44) )
        goto LABEL_79;
      LOBYTE(v44) = *(_DWORD *)(a2 + 88);
      if ( (unsigned int)nla_put(a1, 11, 1, &v44) )
        goto LABEL_79;
    }
    goto LABEL_64;
  }
  v6 = *(_QWORD *)(a1 + 216);
  v7 = *(unsigned int *)(a1 + 208);
  v8 = nla_put(a1, 9, 0, 0);
  result = 4294967191LL;
  if ( v8 < 0 )
    goto LABEL_80;
  v10 = (_WORD *)(v6 + v7);
  if ( !(v6 + v7) )
    goto LABEL_80;
  if ( !*(_WORD *)(a2 + 92) )
  {
LABEL_60:
    *v10 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v10;
    goto LABEL_61;
  }
  v11 = *(unsigned __int16 **)(a2 + 96);
  v12 = 0;
  while ( 1 )
  {
    ++v12;
    v13 = *(_QWORD *)(a1 + 216);
    v14 = *(unsigned int *)(a1 + 208);
    v15 = nla_put(a1, (unsigned int)v12, 0, 0);
    result = 4294967191LL;
    if ( v15 < 0 )
      break;
    v16 = (_WORD *)(v13 + v14);
    if ( !(v13 + v14) )
      break;
    v17 = *v11;
    v18 = *(_QWORD *)(a1 + 216);
    v19 = *(unsigned int *)(a1 + 208);
    v20 = nla_put(a1, 1, 0, 0);
    result = 4294967191LL;
    if ( v20 < 0 )
      break;
    v21 = (_WORD *)(v18 + v19);
    if ( !v21 )
      break;
    if ( v17 )
    {
      v22 = 0;
      while ( (v17 & 1) == 0 || !(unsigned int)nla_put(a1, v22, 0, 0) )
      {
        v23 = v17 > 1;
        ++v22;
        v17 >>= 1;
        if ( !v23 )
          goto LABEL_27;
      }
      goto LABEL_79;
    }
LABEL_27:
    *v21 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v21;
    if ( *((_BYTE *)v11 + 2) == 1
      && ((unsigned int)nla_put(a1, 2, 6, (char *)v11 + 3)
       || (unsigned int)nla_put(a1, 3, 11, (char *)v11 + 9)
       || (unsigned int)nla_put(a1, 4, 12, v11 + 10)
       || (unsigned int)nla_put(a1, 5, 25, v11 + 16)) )
    {
      goto LABEL_79;
    }
    if ( *((_BYTE *)v11 + 59) == 1 && *((_BYTE *)v11 + 2) == 1 )
    {
      v24 = *((unsigned __int8 *)v11 + 9);
      if ( (v24 & 2) != 0 )
      {
        v28 = 3;
      }
      else
      {
        v25 = (v24 << 29 >> 31) & 3;
        if ( (v24 & 8) != 0 )
          v25 += 3;
        v26 = (v11[31] & 2) != 0 ? v25 + 3 : v25;
        v27 = (*v11 & 0x208) != 0 ? 3 : 4;
        v28 = v26 ? v26 : v27;
      }
      if ( (*((_BYTE *)v11 + 67) & 8) != 0 )
      {
        v30 = v11[40];
        v29 = (unsigned __int8)(((unsigned int)_sw_hweight16(v30 & 0x1F0) * (6 * (v30 & 0xF) + 6) + 16) >> 3);
      }
      else
      {
        v29 = 0;
      }
      if ( (unsigned int)nla_put(a1, 8, 2, v11 + 30)
        || (unsigned int)nla_put(a1, 9, 9, v11 + 31)
        || (unsigned int)nla_put(a1, 10, v28, (char *)v11 + 71)
        || (unsigned int)nla_put(a1, 11, v29, v11 + 40) )
      {
        goto LABEL_79;
      }
    }
    if ( *(_DWORD *)(a2 + 16) == 3 && (unsigned int)nla_put(a1, 6, 2, (char *)v11 + 57) )
      goto LABEL_79;
    v31 = *((_QWORD *)v11 + 14);
    if ( v31 )
    {
      v32 = *((unsigned int *)v11 + 30);
      if ( (_DWORD)v32 )
      {
        if ( (unsigned int)nla_put(a1, 7, v32, v31) )
          goto LABEL_79;
      }
    }
    *v16 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v16;
    v11 = (unsigned __int16 *)(*(_QWORD *)(a2 + 96) + (v12 << 7));
    if ( v12 >= *(unsigned __int16 *)(a2 + 92) )
      goto LABEL_60;
  }
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return result;
}
