__int64 __fastcall qcedev_hash_init(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v6; // x22
  size_t v7; // x21
  __int64 v8; // x20
  __int64 v10; // x8
  int v11; // w8
  int v12; // w8
  unsigned int v13; // w0
  size_t v14; // x2
  unsigned int v15; // w21
  size_t v16; // x2
  __int64 v17; // x8
  _BYTE *v18; // x10
  char v19; // w12
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x2
  _QWORD v23[8]; // [xsp+0h] [xbp-400h] BYREF
  _QWORD s[120]; // [xsp+40h] [xbp-3C0h] BYREF

  s[119] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 372) <= 1u )
  {
    qcedev_sha_init(a1, a2);
    result = 0;
LABEL_21:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v6 = *a2;
  if ( *(_DWORD *)(a1 + 368) <= 0x40u )
  {
    qcedev_sha_init(a1, a2);
    v7 = *(unsigned int *)(a1 + 368);
    if ( (v7 & 0x80000000) != 0 )
    {
      __break(0x800u);
      result = 4294967282LL;
      goto LABEL_21;
    }
    v8 = *(_QWORD *)(a1 + 360);
    _check_object_size((char *)a2 + 130, v7, 0);
    if ( inline_copy_from_user((int)a2 + 130, v8, v7) )
    {
      result = 4294967282LL;
      goto LABEL_21;
    }
LABEL_16:
    if ( (*(_BYTE *)(v6 + 27) & 1) != 0 )
    {
      result = 0;
    }
    else
    {
      v17 = 0;
      *(__int64 *)((char *)a2 + 116) = 0;
      *(__int64 *)((char *)a2 + 108) = 0;
      *(__int64 *)((char *)a2 + 100) = 0;
      *(__int64 *)((char *)a2 + 92) = 0;
      *(__int64 *)((char *)a2 + 84) = 0;
      *(__int64 *)((char *)a2 + 76) = 0;
      *(__int64 *)((char *)a2 + 68) = 0;
      *(__int64 *)((char *)a2 + 60) = 0;
      do
      {
        v18 = (char *)a2 + v17;
        v17 += 2;
        v19 = v18[131] ^ 0x36;
        v18[60] = v18[130] ^ 0x36;
        v18[61] = v19;
      }
      while ( v17 != 64 );
      result = 0;
      *((_DWORD *)a2 + 31) = 64;
    }
    goto LABEL_21;
  }
  memset(s, 0, 0x3B8u);
  memset(v23, 0, sizeof(v23));
  LODWORD(s[2]) = 0;
  _init_swait_queue_head(&s[3], "&x->wait", &init_completion___key);
  v10 = *(_QWORD *)(a1 + 360);
  LODWORD(s[39]) = 1;
  s[7] = v10;
  LODWORD(v10) = *(_DWORD *)(a1 + 368);
  s[113] = a2;
  LODWORD(s[8]) = v10;
  HIDWORD(s[39]) = v10;
  v11 = *(_DWORD *)(a1 + 372);
  memset(&s[40], 0, 36);
  if ( v11 == 2 )
  {
    v12 = 0;
  }
  else
  {
    if ( v11 != 3 )
      goto LABEL_12;
    v12 = 1;
  }
  HIDWORD(s[46]) = v12;
LABEL_12:
  LODWORD(s[6]) = 1;
  qcedev_sha_init(s, a2);
  result = qcedev_sha_update(s, a2, a3);
  if ( (_DWORD)result )
    goto LABEL_21;
  v13 = qcedev_sha_final(s, a2);
  v14 = *((unsigned int *)a2 + 14);
  if ( (unsigned int)v14 >= 0x41 )
  {
    _fortify_panic(17, 64);
  }
  else
  {
    v15 = v13;
    memcpy(v23, a2 + 3, v14);
    qcedev_sha_init(a1, a2);
    v16 = *((unsigned int *)a2 + 14);
    if ( (unsigned int)v16 < 0x41 )
    {
      memcpy((char *)a2 + 130, v23, v16);
      result = v15;
      if ( v15 )
        goto LABEL_21;
      goto LABEL_16;
    }
  }
  v20 = _fortify_panic(16, -1);
  return qcedev_hash_cmac(v20, v21, v22);
}
