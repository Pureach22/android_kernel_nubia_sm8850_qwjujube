_QWORD *__fastcall get_active_cmdobj(__int64 a1)
{
  _QWORD *v1; // x21
  _QWORD *v2; // x22
  _QWORD *v4; // x19
  unsigned int v5; // w26
  bool v6; // cc
  _QWORD *v7; // x27
  _QWORD *v8; // x27
  __int64 v9; // x28
  __int64 v10; // t1
  __int64 v11; // x1
  __int64 v12; // x8
  unsigned int v13; // w9
  unsigned int v14; // w9
  unsigned int v15; // w8
  __int64 v16; // x20
  unsigned int v18; // w8
  unsigned int v19; // w21
  unsigned int v25; // w9
  unsigned __int64 v29; // x9
  _QWORD v30[2]; // [xsp+0h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD **)(a1 + 22768);
  v2 = (_QWORD *)(a1 + 22768);
  v30[0] = 0;
  if ( v1 == (_QWORD *)(a1 + 22768) )
    goto LABEL_42;
  v4 = nullptr;
  v5 = -1;
  do
  {
    v7 = v1;
    v1 = (_QWORD *)*v1;
    v10 = *(v7 - 1);
    v8 = v7 - 1;
    v9 = v10;
    if ( (*(_BYTE *)(v10 + 16) & 1) == 0 )
      continue;
    v11 = *(_QWORD *)(v9 + 8);
    if ( v11 )
    {
      if ( (*(_BYTE *)(v11 + 203) & 0x20) != 0 )
        continue;
    }
    kgsl_readtimestamp(a1, v11, 1, (char *)v30 + 4);
    kgsl_readtimestamp(a1, *(_QWORD *)(v9 + 8), 2, v30);
    if ( !HIDWORD(v30[0]) || HIDWORD(v30[0]) == LODWORD(v30[0]) )
      continue;
    v12 = *(_QWORD *)(v9 + 8);
    if ( !v4 )
    {
      if ( v12 && (*(_BYTE *)(v12 + 203) & 0x20) != 0 )
      {
        v5 = 4;
      }
      else
      {
LABEL_24:
        v15 = *(_DWORD *)(v12 + 8) >> 2;
        if ( v15 >= 3 )
          v5 = 3;
        else
          v5 = v15;
      }
      v4 = v8;
      continue;
    }
    if ( v12 )
    {
      if ( (*(_BYTE *)(v12 + 203) & 0x20) != 0 )
      {
        v6 = v5 > 4;
        if ( v5 >= 4 )
          v5 = 4;
        if ( v6 )
          v4 = v8;
        continue;
      }
      v13 = *(_DWORD *)(v12 + 8);
    }
    else
    {
      v13 = 1586547;
    }
    v14 = v13 >> 2;
    if ( v14 >= 3 )
      v14 = 3;
    if ( v14 < v5 )
      goto LABEL_24;
  }
  while ( v1 != v2 );
  if ( !v4 )
    goto LABEL_43;
  v16 = *v4;
  _X0 = (unsigned int *)(*v4 + 32LL);
  v18 = *_X0;
  if ( *_X0 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v25 = __ldxr(_X0);
      while ( v25 == v18 && __stxr(v18 + 1, _X0) );
      v19 = v18;
      if ( v25 == v18 )
        break;
      v19 = 0;
      v18 = v25;
    }
    while ( v25 );
  }
  else
  {
    v19 = 0;
  }
  if ( (((v19 + 1) | v19) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(_X0, 0);
    if ( v19 )
      goto LABEL_40;
    goto LABEL_42;
  }
  if ( !v19 )
  {
LABEL_42:
    v4 = nullptr;
    goto LABEL_43;
  }
LABEL_40:
  _X8 = (unsigned __int64 *)(v16 + 56);
  __asm { PRFM            #0x11, [X8] }
  do
    v29 = __ldxr(_X8);
  while ( __stxr(v29 | 0x10, _X8) );
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v4;
}
