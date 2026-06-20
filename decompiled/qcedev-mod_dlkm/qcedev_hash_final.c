__int64 __fastcall qcedev_hash_final(__int64 a1, __int64 *a2)
{
  __int64 result; // x0
  __int64 v5; // x21
  __int64 v6; // x8
  _BYTE *v7; // x10
  char v8; // w12
  unsigned int v9; // w24
  int v10; // w8
  unsigned int v11; // w25
  unsigned __int64 v12; // x22
  void *v13; // x23
  size_t v14; // x2
  int v15; // w8
  unsigned int v16; // w0
  unsigned int v17; // w21
  unsigned __int64 StatusReg; // x26
  __int64 v19; // x27
  _QWORD v20[5]; // [xsp+8h] [xbp-28h] BYREF

  v20[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 372) <= 1u )
  {
LABEL_2:
    result = qcedev_sha_final(a1, a2);
    goto LABEL_23;
  }
  v5 = *a2;
  result = qcedev_sha_final(a1, a2);
  if ( (*(_BYTE *)(v5 + 27) & 1) != 0 )
    goto LABEL_23;
  v6 = 0;
  *(__int64 *)((char *)a2 + 60) = 0;
  *(__int64 *)((char *)a2 + 108) = 0;
  *(__int64 *)((char *)a2 + 116) = 0;
  *(__int64 *)((char *)a2 + 92) = 0;
  *(__int64 *)((char *)a2 + 100) = 0;
  *(__int64 *)((char *)a2 + 76) = 0;
  *(__int64 *)((char *)a2 + 84) = 0;
  *(__int64 *)((char *)a2 + 68) = 0;
  do
  {
    v7 = (char *)a2 + v6;
    v6 += 2;
    v8 = v7[131] ^ 0x5C;
    v7[60] = v7[130] ^ 0x5C;
    v7[61] = v8;
  }
  while ( v6 != 64 );
  v9 = 64;
  *((_DWORD *)a2 + 31) = 64;
  v10 = *(_DWORD *)(a1 + 372);
  if ( v10 == 2 )
  {
    v11 = 20;
  }
  else if ( v10 == 3 )
  {
    v11 = 32;
  }
  else
  {
    v11 = 0;
    v9 = 0;
  }
  memset(v20, 0, 32);
  v12 = v9;
  v13 = (void *)_kmalloc_noprof(v9, 3264);
  if ( !v13 )
  {
LABEL_22:
    result = 4294967284LL;
    goto LABEL_23;
  }
  while ( 1 )
  {
    v14 = *((unsigned int *)a2 + 31);
    if ( v12 >= v14 )
      break;
    _fortify_panic(17, v12);
LABEL_21:
    _fortify_panic(15, v12);
    v12 = v9;
    StatusReg = _ReadStatusReg(SP_EL0);
    v19 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &qcedev_hmac_get_ohash__alloc_tag;
    v13 = (void *)_kmalloc_noprof(v9, 3264);
    *(_QWORD *)(StatusReg + 80) = v19;
    if ( !v13 )
      goto LABEL_22;
  }
  memcpy(v13, (char *)a2 + 60, v14);
  *(_QWORD *)(a1 + 872) = v20;
  sg_init_one(v20, v13, v9);
  *(_DWORD *)(a1 + 864) = v9;
  memset((char *)a2 + 60, 0, v9);
  memcpy((char *)a2 + 60, a2 + 3, v11);
  *((_DWORD *)a2 + 31) = v11;
  *((_WORD *)a2 + 64) = 1;
  a2[1] = 0;
  v15 = *(_DWORD *)(a1 + 372);
  if ( v15 == 2 )
  {
    *((_DWORD *)a2 + 10) = -253635901;
    *((_DWORD *)a2 + 14) = 20;
    a2[3] = 0x89ABCDEF01234567LL;
    a2[4] = 0x76543210FEDCBA98LL;
    v15 = *(_DWORD *)(a1 + 372);
  }
  if ( v15 == 3 )
  {
    a2[3] = 0x85AE67BB67E6096ALL;
    a2[4] = 0x3AF54FA572F36E3CLL;
    a2[5] = 0x8C68059B7F520E51LL;
    a2[6] = 0x19CDE05BABD9831FLL;
    *((_DWORD *)a2 + 14) = 32;
  }
  v16 = submit_req(a1, a2);
  *((_WORD *)a2 + 64) = 0;
  if ( v12 < v9 )
    goto LABEL_21;
  v17 = v16;
  memset(v13, 0, v9);
  kfree(v13);
  result = v17;
  *(_QWORD *)(a1 + 872) = 0;
  if ( !v17 )
    goto LABEL_2;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
