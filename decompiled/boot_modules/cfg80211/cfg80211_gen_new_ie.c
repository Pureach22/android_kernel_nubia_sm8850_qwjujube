__int64 __fastcall cfg80211_gen_new_ie(unsigned __int8 *src, __int64 a2, unsigned __int8 *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x27
  unsigned __int8 *v6; // x23
  unsigned __int8 *v7; // x22
  unsigned __int8 *v8; // x28
  unsigned __int64 v9; // x9
  unsigned __int8 *v10; // x21
  __int64 v11; // x8
  unsigned __int8 *v12; // x24
  unsigned __int64 v13; // x8
  __int64 result; // x0
  int v15; // w19
  size_t v16; // x25
  unsigned __int64 v17; // x9
  unsigned __int8 *v18; // x26
  size_t v19; // x8
  char v20; // w20
  int v21; // w8
  unsigned __int64 v22; // x9
  __int64 v23; // x23
  unsigned __int8 *v24; // x27
  size_t v25; // x8
  unsigned int v26; // w12
  __int64 v27; // x11
  __int64 v28; // x9
  __int64 v29; // x10
  unsigned __int8 *v30; // x9
  bool v31; // zf
  char v32; // w8
  unsigned __int64 v33; // x9
  unsigned __int8 *v34; // x20
  size_t v35; // x8
  int v36; // t1
  unsigned __int8 *v37; // x23
  unsigned __int64 v38; // x9
  unsigned __int8 *v39; // x21
  char *v40; // x25
  int v41; // w20
  size_t v42; // x24
  char *v43; // x22
  unsigned __int64 v44; // x9
  size_t v45; // x8
  unsigned __int8 *v46; // [xsp+10h] [xbp-60h]
  unsigned __int8 *v47; // [xsp+18h] [xbp-58h]
  unsigned __int64 v48; // [xsp+20h] [xbp-50h]
  __int64 v52; // [xsp+40h] [xbp-30h]
  unsigned int v53; // [xsp+48h] [xbp-28h]
  char *v54; // [xsp+50h] [xbp-20h]
  _BYTE s2[4]; // [xsp+5Ch] [xbp-14h] BYREF
  __int64 v56; // [xsp+60h] [xbp-10h]
  __int64 v57; // [xsp+68h] [xbp-8h]

  v53 = a2;
  v5 = a5;
  v6 = a3;
  v7 = src;
  v8 = &a3[(unsigned int)a4];
  v52 = (unsigned int)a4 & 0xFFFFFFFE;
  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = a5;
  v48 = (unsigned int)a4;
  if ( (a4 & 0xFFFFFFFE) != 0 )
  {
    v9 = (unsigned int)a4;
    v10 = a3;
    do
    {
      v11 = v10[1];
      if ( v9 < v11 + 2 )
        break;
      if ( v10[1] && *v10 == 255 && v10[2] == 56 )
        goto LABEL_10;
      v10 += v11 + 2;
      v9 = v8 - v10;
    }
    while ( v8 - v10 > 1 );
  }
  v10 = nullptr;
LABEL_10:
  s2[0] = 0;
  if ( a2 < 2 )
  {
LABEL_73:
    if ( a4 < 2 )
    {
LABEL_95:
      result = v56 - v5;
      goto LABEL_96;
    }
    v37 = a3;
    v38 = a4;
    v39 = &a3[a4];
    v40 = (char *)&src[v53];
    while ( 1 )
    {
      if ( v38 < (unsigned __int64)v37[1] + 2 )
        goto LABEL_95;
      v41 = *v37;
      if ( v41 != 83 && v41 != 242 )
      {
        if ( v41 != 255 )
        {
          v42 = 0;
          if ( (v53 & 0xFFFFFFFE) == 0 )
            goto LABEL_75;
LABEL_86:
          v43 = (char *)src;
          v44 = v53;
          do
          {
            v45 = (unsigned __int8)v43[1];
            if ( v44 < v45 + 2 )
              break;
            if ( v42 <= v45 && (unsigned __int8)*v43 == v41 )
            {
              if ( !bcmp(v43 + 2, s2, v42) )
              {
                if ( v43 )
                  goto LABEL_76;
                break;
              }
              v45 = (unsigned __int8)v43[1];
            }
            v43 += v45 + 2;
            v44 = v40 - v43;
          }
          while ( v40 - v43 > 1 );
LABEL_75:
          result = cfg80211_copy_elem_with_frags(v37);
          if ( !result )
            goto LABEL_96;
          goto LABEL_76;
        }
        if ( v37[1] )
        {
          s2[0] = v37[2];
          if ( s2[0] != 56 )
          {
            v42 = 1;
            if ( (v53 & 0xFFFFFFFE) == 0 )
              goto LABEL_75;
            goto LABEL_86;
          }
        }
      }
LABEL_76:
      v37 += v37[1] + 2;
      v38 = v39 - v37;
      if ( v39 - v37 <= 1 )
        goto LABEL_95;
    }
  }
  v12 = src;
  v54 = (char *)&src[a2];
  v46 = v10 + 2;
  v47 = &a3[a4];
  v13 = a2;
  while ( 2 )
  {
    if ( v13 < (unsigned __int64)v12[1] + 2 )
      goto LABEL_73;
    v15 = *v12;
    if ( v15 == 242 )
      goto LABEL_13;
    if ( v15 == 255 )
    {
      if ( !v12[1] )
        goto LABEL_13;
      v16 = 1;
      s2[0] = v12[2];
      if ( !v52 )
        goto LABEL_30;
    }
    else
    {
      v16 = 0;
      if ( !v52 )
        goto LABEL_30;
    }
    v17 = v48;
    v18 = v6;
    while ( 1 )
    {
      v19 = v18[1];
      if ( v17 < v19 + 2 )
        goto LABEL_30;
      if ( v16 <= v19 && *v18 == v15 )
        break;
LABEL_22:
      v18 += v19 + 2;
      v17 = v8 - v18;
      if ( v8 - v18 <= 1 )
        goto LABEL_30;
    }
    if ( bcmp(v18 + 2, s2, v16) )
    {
      v19 = v18[1];
      goto LABEL_22;
    }
    if ( v18 )
    {
      v20 = 1;
      goto LABEL_35;
    }
LABEL_30:
    v21 = *v12;
    if ( v21 == 71 || v21 == 255 && v12[1] >= 2u && v12[2] == 107 )
    {
LABEL_34:
      v20 = 0;
      v18 = nullptr;
LABEL_35:
      if ( ((v12 - v7) & 0xFFFFFFFELL) != 0 )
      {
        v22 = (unsigned int)((_DWORD)v12 - (_DWORD)v7);
        v23 = v5;
        v24 = &v7[v22];
        do
        {
          v25 = v7[1];
          if ( v22 < v25 + 2 )
            break;
          if ( v16 <= v25 && *v7 == v15 )
          {
            if ( !bcmp(v7 + 2, s2, v16) )
              goto LABEL_52;
            v25 = v7[1];
          }
          v7 += v25 + 2;
          v22 = v24 - v7;
        }
        while ( v24 - v7 > 1 );
        v7 = nullptr;
LABEL_52:
        v5 = v23;
        v6 = a3;
      }
      else
      {
        v7 = nullptr;
      }
      v31 = v7 == nullptr;
      v32 = v20 ^ 1;
      v7 = src;
      if ( !v31 )
        v32 = 1;
      if ( (v32 & 1) == 0 )
      {
LABEL_57:
        result = cfg80211_copy_elem_with_frags(v18);
        if ( !result )
          goto LABEL_96;
        v18 += v18[1] + 2;
        if ( ((v47 - v18) & 0xFFFFFFFELL) == 0 )
          goto LABEL_13;
        v33 = (unsigned int)((_DWORD)v47 - (_DWORD)v18);
        v34 = &v18[v33];
        do
        {
          v35 = v18[1];
          if ( v33 < v35 + 2 )
            break;
          if ( v16 <= v35 && *v18 == v15 )
          {
            if ( !bcmp(v18 + 2, s2, v16) )
            {
              if ( !v18 )
                break;
              goto LABEL_57;
            }
            v35 = v18[1];
          }
          v18 += v35 + 2;
          v33 = v34 - v18;
        }
        while ( v34 - v18 > 1 );
      }
LABEL_13:
      v12 += v12[1] + 2;
      v13 = v54 - (char *)v12;
      if ( v54 - (char *)v12 <= 1 )
        goto LABEL_73;
      continue;
    }
    break;
  }
  if ( v10 )
  {
    v26 = v10[1];
    if ( v26 >= 2 )
    {
      v27 = v10[3];
      v28 = v27 + 3;
      if ( (int)v27 + 3 <= v26 && (unsigned int)v28 + v46[v27 + 2] <= v26 )
      {
        if ( v21 == 255 )
        {
          if ( v46[v27 + 2] )
          {
            v21 = v12[2];
            v29 = v46[v27 + 2];
            v30 = &v46[v28];
            goto LABEL_70;
          }
        }
        else
        {
          v30 = v10 + 4;
          if ( v10[3] )
          {
            v29 = v10[3];
LABEL_70:
            do
            {
              v36 = *v30++;
              if ( v36 == v21 )
                goto LABEL_34;
            }
            while ( --v29 );
          }
        }
      }
    }
  }
  result = cfg80211_copy_elem_with_frags(v12);
  if ( result )
    goto LABEL_13;
LABEL_96:
  _ReadStatusReg(SP_EL0);
  return result;
}
