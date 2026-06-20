__int64 __fastcall cqhci_crypto_init(__int64 a1)
{
  __int64 *v1; // x22
  __int64 v2; // x20
  __int64 (*v4)(void); // x8
  __int64 result; // x0
  __int64 (__fastcall *v6)(__int64, __int64); // x8
  unsigned int v7; // w0
  __int64 v8; // x0
  int v9; // w23
  unsigned __int64 v10; // x21
  __int64 v11; // x20
  _DWORD *v12; // x8
  int v13; // w0
  int v14; // w8
  unsigned int v15; // w20
  _QWORD v16[17]; // [xsp+8h] [xbp-88h] BYREF

  v16[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(__int64 **)(a1 + 16);
  if ( (*((_BYTE *)v1 + 1003) & 8) == 0 )
    goto LABEL_4;
  v2 = *v1;
  v4 = *(__int64 (**)(void))(*(_QWORD *)a1 + 16LL);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != 1427797680 )
      __break(0x8228u);
    if ( (v4() & 0x10000000) == 0 )
      goto LABEL_4;
  }
  else if ( (readl_relaxed_0(*(_QWORD *)(a1 + 8) + 4LL) & 0x10000000) == 0 )
  {
LABEL_4:
    result = 0;
    goto LABEL_5;
  }
  v6 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)a1 + 16LL);
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != 1427797680 )
      __break(0x8228u);
    v7 = v6(a1, 256);
  }
  else
  {
    v7 = readl_relaxed_0(*(_QWORD *)(a1 + 8) + 256LL);
  }
  *(_DWORD *)(a1 + 192) = v7;
  *(_DWORD *)(a1 + 208) = HIWORD(v7) & 0xFF00;
  v8 = devm_kmalloc(v2, 4 * (unsigned int)(unsigned __int8)v7, 3520);
  *(_QWORD *)(a1 + 200) = v8;
  if ( !v8 )
  {
    result = 4294967284LL;
    goto LABEL_5;
  }
  v9 = *(unsigned __int8 *)(a1 + 193);
  result = devm_blk_crypto_profile_init(v2, v1 + 185, (unsigned int)(v9 + 1));
  if ( (_DWORD)result )
  {
LABEL_5:
    *((_DWORD *)v1 + 250) &= ~0x8000000u;
    goto LABEL_6;
  }
  v1[192] = v2;
  v1[187] = 0;
  v1[185] = (__int64)cqhci_crypto_keyslot_program;
  v1[186] = (__int64)cqhci_crypto_keyslot_evict;
  v1[188] = 0x100000004LL;
  if ( *(_BYTE *)(a1 + 192) )
  {
    v10 = 0;
    v11 = 260;
    do
    {
      v12 = *(_DWORD **)(*(_QWORD *)a1 + 16LL);
      if ( v12 )
      {
        if ( *(v12 - 1) != 1427797680 )
          __break(0x8228u);
        v13 = ((__int64 (__fastcall *)(__int64, _QWORD))v12)(a1, (unsigned int)v11);
      }
      else
      {
        v13 = readl_relaxed_0(*(_QWORD *)(a1 + 8) + v11);
      }
      *(_DWORD *)(*(_QWORD *)(a1 + 200) + 4 * v10) = v13;
      v14 = *(_DWORD *)(*(_QWORD *)(a1 + 200) + 4 * v10);
      if ( (v14 & 0xFF00FF) == 0x30000 )
        *((_DWORD *)v1 + 379) |= (2 * v14) & 0x1FE00;
      ++v10;
      v11 += 4;
    }
    while ( v10 < *(unsigned __int8 *)(a1 + 192) );
  }
  v15 = 0;
  do
  {
    memset(v16, 0, 128);
    cqhci_crypto_program_key(a1, v16, v15++);
  }
  while ( v9 + 1 != v15 );
  result = 0;
  *(_DWORD *)(a1 + 48) |= 1u;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
