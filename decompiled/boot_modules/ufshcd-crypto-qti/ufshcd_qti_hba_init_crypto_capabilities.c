__int64 __fastcall ufshcd_qti_hba_init_crypto_capabilities(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  int v7; // w10
  unsigned __int64 v8; // x20
  __int64 v9; // x22
  int v10; // w8

  if ( (readl(*(_QWORD *)a1) & 0x10000000) == 0 || (*(_BYTE *)(a1 + 3001) & 1) == 0 )
  {
    result = 0;
    goto LABEL_4;
  }
  v3 = readl(*(_QWORD *)a1 + 256LL);
  v4 = *(_QWORD *)(a1 + 64);
  *(_DWORD *)(a1 + 4520) = v3;
  *(_DWORD *)(a1 + 4536) = HIWORD(v3) & 0xFF00;
  v5 = devm_kmalloc(v4, 4 * (unsigned int)(unsigned __int8)v3, 3520);
  *(_QWORD *)(a1 + 4528) = v5;
  if ( !v5 )
  {
    result = 4294967284LL;
    goto LABEL_4;
  }
  result = devm_blk_crypto_profile_init(
             *(_QWORD *)(a1 + 64),
             a1 + 4544,
             (unsigned int)*(unsigned __int8 *)(a1 + 4521) + 1);
  if ( (_DWORD)result )
  {
LABEL_4:
    *(_DWORD *)(a1 + 3000) &= ~0x100u;
    return result;
  }
  *(_QWORD *)(a1 + 4560) = ufshcd_qti_crypto_derive_sw_secret;
  v6 = *(_QWORD *)(a1 + 64);
  *(_QWORD *)(a1 + 4544) = ufshcd_qti_crypto_keyslot_program;
  *(_QWORD *)(a1 + 4552) = ufshcd_qti_crypto_keyslot_evict;
  v7 = *(unsigned __int8 *)(a1 + 4520);
  *(_QWORD *)(a1 + 4600) = v6;
  *(_QWORD *)(a1 + 4568) = 0x200000008LL;
  if ( v7 )
  {
    v8 = 0;
    v9 = 260;
    do
    {
      *(_DWORD *)(*(_QWORD *)(a1 + 4528) + 4 * v8) = readl(*(_QWORD *)a1 + v9);
      v10 = *(_DWORD *)(*(_QWORD *)(a1 + 4528) + 4 * v8);
      if ( (v10 & 0xFF00FF) == 0x30000 )
        *(_DWORD *)(a1 + 4580) |= (2 * v10) & 0x1FE00;
      ++v8;
      v9 += 4;
    }
    while ( v8 < *(unsigned __int8 *)(a1 + 4520) );
  }
  return 0;
}
