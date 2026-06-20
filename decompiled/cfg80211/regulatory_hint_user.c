__int64 __fastcall regulatory_hint_user(unsigned __int8 *a1, int a2)
{
  __int64 v2; // x8
  __int64 v5; // x8
  __int64 v6; // x0
  __int16 v7; // w9

  if ( !a1 )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  v2 = *a1;
  if ( v2 != 48 )
  {
    if ( (v2 & 0x80) != 0 )
      return 4294967274LL;
    goto LABEL_6;
  }
  if ( a1[1] != 48 )
  {
LABEL_6:
    if ( (*((_BYTE *)&ctype + v2) & 3) != 0 )
    {
      v5 = (char)a1[1];
      if ( (v5 & 0x8000000000000000LL) == 0 && (*((_BYTE *)&ctype + v5) & 3) != 0 )
        goto LABEL_9;
    }
    return 4294967274LL;
  }
LABEL_9:
  v6 = _kmalloc_cache_noprof(timer_delete, 3520, 64);
  if ( !v6 )
    return 4294967284LL;
  v7 = *(_WORD *)a1;
  *(_DWORD *)(v6 + 24) = a2;
  *(_QWORD *)(v6 + 16) = 0x1FFFFFFFFLL;
  *(_WORD *)(v6 + 28) = v7;
  queue_regulatory_request();
  return 0;
}
