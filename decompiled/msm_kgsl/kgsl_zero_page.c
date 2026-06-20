__int64 __fastcall kgsl_zero_page(__int64 result, int a2, __int64 a3)
{
  char v4; // w20
  __int64 v5; // x21
  __int64 v6; // x22
  __int64 v7; // x25
  __int64 v8; // x23
  char v9; // w9
  __int64 v10; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v4 = a2;
  v5 = result;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 != 31 )
  {
    v6 = (unsigned int)(1 << a2);
    v7 = result;
    v8 = (result << 6) + 0xFFFFD000000000LL;
    do
    {
      result = clear_page(v8 & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL);
      --v6;
      v7 += 64;
      v8 += 4096;
    }
    while ( v6 );
  }
  if ( !a3 )
    goto LABEL_8;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  result = sg_init_table(&v10, 1);
  if ( (v5 & 3) == 0 )
  {
    LODWORD(v11) = 0;
    HIDWORD(v11) = 4096LL << v4;
    v10 = v10 & 3 | v5;
    v9 = *(_BYTE *)(a3 + 844);
    v12 = ((v5 - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
    if ( (v9 & 0x40) == 0 )
      result = _dma_sync_sg_for_device(a3, &v10, 1, 1);
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  return kgsl_gfp_mask(result);
}
