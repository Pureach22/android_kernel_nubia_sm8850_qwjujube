__int64 __fastcall cfg80211_get_drvinfo(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  const char **v4; // x8
  const char *v5; // x20
  size_t v6; // x0
  unsigned __int64 v7; // x2
  size_t v8; // x0
  unsigned __int64 v9; // x2
  _BYTE *v10; // x20
  size_t v11; // x0
  unsigned __int64 v12; // x2
  const char **v13; // x8
  const char *v14; // x20
  size_t v15; // x0
  unsigned __int64 v16; // x2

  v2 = *(_QWORD *)(a1 + 992);
  v4 = *(const char ***)(*(_QWORD *)(*(_QWORD *)v2 + 488LL) + 136LL);
  if ( v4 )
  {
    v5 = *v4;
    v6 = strnlen(*v4, 0x20u);
    if ( v6 == -1 )
    {
LABEL_31:
      _fortify_panic(2, -1);
      goto LABEL_32;
    }
    if ( v6 == 32 )
      v7 = 32;
    else
      v7 = v6 + 1;
    if ( v7 >= 0x21 )
      goto LABEL_30;
    sized_strscpy(a2 + 4, v5);
  }
  else
  {
    *(_DWORD *)(a2 + 4) = 4271950;
  }
  v8 = strnlen((const char *)&_alloc_skb + 2, 0x20u);
  if ( v8 >= 0x41 )
  {
LABEL_32:
    _fortify_panic(2, 65);
    goto LABEL_33;
  }
  if ( v8 == 32 )
    v9 = 32;
  else
    v9 = v8 + 1;
  if ( v9 >= 0x21 )
    goto LABEL_30;
  sized_strscpy(a2 + 36, (char *)&_alloc_skb + 2);
  v10 = (_BYTE *)(*(_QWORD *)v2 + 209LL);
  if ( !*v10 )
  {
    *(_DWORD *)(a2 + 68) = 4271950;
    goto LABEL_22;
  }
  v11 = strnlen((const char *)(*(_QWORD *)v2 + 209LL), 0x20u);
  if ( v11 < 0x21 )
  {
    if ( v11 == 32 )
      v12 = 32;
    else
      v12 = v11 + 1;
    if ( v12 < 0x21 )
    {
      sized_strscpy(a2 + 68, v10);
LABEL_22:
      v13 = *(const char ***)(*(_QWORD *)v2 + 488LL);
      v14 = v13[14];
      if ( !v14 )
        v14 = *v13;
      v15 = strnlen(v14, 0x20u);
      if ( v15 == -1 )
        goto LABEL_31;
      if ( v15 == 32 )
        v16 = 32;
      else
        v16 = v15 + 1;
      if ( v16 < 0x21 )
        return sized_strscpy(a2 + 100, v14);
    }
LABEL_30:
    _fortify_panic(7, 32);
    goto LABEL_31;
  }
LABEL_33:
  _fortify_panic(2, 32);
  return _cfg80211_ibss_joined(460);
}
