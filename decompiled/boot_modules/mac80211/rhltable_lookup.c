unsigned __int64 __fastcall rhltable_lookup(__int64 *a1, const void *a2, __int64 a3)
{
  unsigned int (__fastcall *v5)(__int64 **, unsigned __int64); // x24
  __int64 v6; // x21
  __int64 v7; // x2
  unsigned int (__fastcall *v8)(const void *, __int64, __int64); // x8
  __int64 v9; // x1
  __int64 v10; // x1
  __int64 v11; // x22
  unsigned __int64 v12; // x23
  unsigned __int64 v13; // x1
  __int64 *v15; // [xsp+8h] [xbp-18h] BYREF
  const void *v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = a1;
  v16 = a2;
  v5 = *(unsigned int (__fastcall **)(__int64 **, unsigned __int64))(a3 + 32);
  v6 = *a1;
  do
  {
    v7 = *(unsigned int *)(v6 + 8);
    v8 = (unsigned int (__fastcall *)(const void *, __int64, __int64))a1[4];
    v9 = *((unsigned int *)a1 + 2);
    if ( *((_DWORD *)v8 - 1) != 1342709798 )
      __break(0x8228u);
    v10 = (*(_DWORD *)v6 - 1) & v8(a2, v9, v7);
    if ( *(_DWORD *)(v6 + 4) )
      v11 = rht_bucket_nested(v6, v10);
    else
      v11 = v6 + 8LL * (unsigned int)v10 + 64;
    do
    {
      if ( (*(_QWORD *)v11 & 0xFFFFFFFFFFFFFFFELL) != 0 )
        v12 = *(_QWORD *)v11 & 0xFFFFFFFFFFFFFFFELL;
      else
        v12 = v11 | 1;
      for ( ; (v12 & 1) == 0; v12 = *(_QWORD *)v12 )
      {
        v13 = v12 - *((unsigned __int16 *)a1 + 11);
        if ( v5 )
        {
          if ( *((_DWORD *)v5 - 1) != -2113640079 )
            __break(0x8238u);
          if ( !v5(&v15, v13) )
            goto LABEL_23;
        }
        else if ( !bcmp((const void *)(v13 + *((unsigned __int16 *)v15 + 10)), v16, *((unsigned __int16 *)v15 + 9)) )
        {
          goto LABEL_23;
        }
      }
    }
    while ( v12 != (v11 | 1) );
    __dmb(9u);
    v6 = *(_QWORD *)(v6 + 48);
  }
  while ( v6 );
  v12 = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v12;
}
