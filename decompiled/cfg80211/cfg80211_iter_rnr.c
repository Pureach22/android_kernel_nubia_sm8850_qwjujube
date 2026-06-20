__int64 __fastcall cfg80211_iter_rnr(unsigned __int8 *a1, __int64 a2, _DWORD *a3, __int64 a4)
{
  unsigned __int8 *v6; // x23
  __int64 result; // x0
  __int64 v8; // x8
  unsigned __int8 *v9; // x21
  unsigned __int8 *v10; // x24
  unsigned __int64 v11; // x26
  __int64 v12; // x22
  int v13; // w25
  __int64 v14; // x28
  bool v15; // cc
  signed __int64 v16; // x8
  unsigned __int8 *v17; // [xsp+0h] [xbp-70h]
  unsigned __int8 *v18; // [xsp+8h] [xbp-68h]

  if ( a2 < 2 )
    return 1;
  v6 = &a1[a2];
  while ( 1 )
  {
    v8 = a1[1];
    if ( a2 < (unsigned __int64)(v8 + 2) )
      return 1;
    if ( *a1 == 201 )
      break;
LABEL_6:
    a1 += v8 + 2;
    a2 = v6 - a1;
    if ( v6 - a1 <= 1 )
      return 1;
  }
  v9 = a1 + 2;
  v10 = &a1[v8 + 2];
  if ( (unsigned int)v8 < 4 )
  {
LABEL_4:
    if ( v9 != v10 )
      return 0;
    v8 = a1[1];
    goto LABEL_6;
  }
  v17 = &a1[v8];
  v18 = a1;
LABEL_11:
  v11 = *v9;
  v12 = v9[1];
  if ( v10 - v9 - 4 < v12 + v12 * (unsigned int)(v11 >> 4) )
    return 0;
  v13 = 0;
  v14 = 2;
  while ( 1 )
  {
    if ( *(a3 - 1) != 1678572006 )
      __break(0x8234u);
    result = ((__int64 (__fastcall *)(__int64, unsigned __int64, unsigned __int8 *, unsigned __int8 *, _QWORD))a3)(
               a4,
               v11 & 3,
               v9,
               &v9[v14 + 2],
               (unsigned int)v12);
    if ( (_DWORD)result == 1 )
      return result;
    if ( (_DWORD)result == 2 )
      return 0;
    v15 = (unsigned int)(v11 >> 4) > (unsigned __int8)v13++;
    v14 += v12;
    if ( !v15 )
    {
      a1 = v18;
      v16 = v17 - v9;
      v9 += v14 + 2;
      if ( (unsigned __int64)(v16 - v14) >= 4 )
        goto LABEL_11;
      goto LABEL_4;
    }
  }
}
