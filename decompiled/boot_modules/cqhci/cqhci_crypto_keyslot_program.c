__int64 __fastcall cqhci_crypto_keyslot_program(__int64 a1, unsigned int *a2, unsigned int a3)
{
  __int64 v3; // x10
  __int64 v4; // x19
  unsigned int v5; // w11
  __int64 v6; // x8
  __int64 v7; // x14
  unsigned int v8; // w11
  unsigned __int64 v9; // x12
  char *v10; // x13
  __int64 v11; // x9
  _BYTE *v12; // x10
  size_t v13; // x21
  __int64 *p_dest; // x0
  char *v16; // x1
  size_t v17; // x2
  __int64 result; // x0
  size_t v19; // x2
  bool v20; // cf
  unsigned int *v21; // x22
  char *v22; // x21
  unsigned __int64 v23; // x9
  unsigned int *v24; // x8
  unsigned __int64 v25; // x8
  unsigned int *v26; // x22
  __int64 v27; // x0
  int v28; // w12
  size_t v29; // [xsp+0h] [xbp-90h]
  size_t v30; // [xsp+0h] [xbp-90h]
  __int64 dest; // [xsp+8h] [xbp-88h] BYREF
  __int64 v32; // [xsp+10h] [xbp-80h]
  __int64 v33; // [xsp+18h] [xbp-78h]
  __int64 v34; // [xsp+20h] [xbp-70h]
  __int64 v35; // [xsp+28h] [xbp-68h] BYREF
  __int64 v36; // [xsp+30h] [xbp-60h]
  __int64 v37; // [xsp+38h] [xbp-58h]
  __int64 v38; // [xsp+40h] [xbp-50h]
  __int64 v39; // [xsp+48h] [xbp-48h]
  __int64 v40; // [xsp+50h] [xbp-40h]
  __int64 v41; // [xsp+58h] [xbp-38h]
  __int64 v42; // [xsp+60h] [xbp-30h]
  __int64 v43; // [xsp+68h] [xbp-28h]
  __int64 v44; // [xsp+70h] [xbp-20h]
  __int64 v45; // [xsp+78h] [xbp-18h]
  __int64 v46; // [xsp+80h] [xbp-10h]
  __int64 v47; // [xsp+88h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  if ( (unsigned int)v3 >= 6 )
    goto LABEL_31;
  v4 = *(_QWORD *)(a1 - 16);
  v5 = a2[1];
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v6 = *(unsigned __int8 *)(v4 + 192);
  v7 = *(_QWORD *)(v4 + 200);
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  dest = 0;
  v32 = 0;
  if ( !v6 )
  {
LABEL_15:
    __break(0x800u);
    result = 4294967201LL;
    goto LABEL_16;
  }
  v8 = v5 >> 9;
  v9 = (8LL * (unsigned int)v3) | 4;
  v10 = (char *)&cqhci_crypto_algs + 8 * v3;
  v11 = 0;
  v12 = (_BYTE *)(v7 + 1);
  while ( 1 )
  {
    if ( !*(v12 - 1) )
    {
      if ( v9 > 0x28 )
      {
        __break(1u);
        goto LABEL_31;
      }
      if ( *((_DWORD *)v10 + 1) == (unsigned __int8)v12[1] && ((unsigned __int8)v8 & *v12) != 0 )
        break;
    }
    ++v11;
    v12 += 4;
    if ( v6 == v11 )
      goto LABEL_15;
  }
  LOBYTE(v39) = v8;
  v13 = a2[5];
  BYTE1(v39) = v11;
  BYTE3(v39) = 0x80;
  if ( !*(v12 - 1) )
  {
    v19 = v13 >> 1;
    if ( (unsigned int)v13 >= 0x102 )
    {
LABEL_33:
      _fortify_panic(17, 128, v19);
      goto LABEL_34;
    }
    v20 = (unsigned int)v13 >= 0x82;
    v21 = a2;
    v22 = (char *)(a2 + 6);
    if ( v20 && (cqhci_crypto_keyslot_program___already_done & 1) == 0 )
    {
      cqhci_crypto_keyslot_program___already_done = 1;
      v29 = v19;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v19,
        "field \"cfg.crypto_key\" at ../soc-repo/drivers/mmc/host/cqhci-crypto.c:95",
        0x40u);
      v19 = v29;
      __break(0x800u);
    }
    memcpy(&dest, v22, v19);
    v23 = v21[5];
    if ( (unsigned int)v23 <= 0x101 )
    {
      v17 = v23 >> 1;
      if ( (unsigned int)v23 >= 0xC2 )
      {
LABEL_34:
        v27 = _fortify_panic(17, 96, v17);
        if ( (v28 & 0x10000000) == 0 )
          JUMPOUT(0xC7D8);
        return cqhci_crypto_keyslot_evict(v27);
      }
      v24 = v21;
      if ( (unsigned int)v23 >= 0x42 && (cqhci_crypto_keyslot_program___already_done_2 & 1) == 0 )
      {
        cqhci_crypto_keyslot_program___already_done_2 = 1;
        v30 = v23 >> 1;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v17,
          "field \"cfg.crypto_key + 64/2\" at ../soc-repo/drivers/mmc/host/cqhci-crypto.c:97",
          0x20u);
        v17 = v30;
        v24 = v21;
        __break(0x800u);
      }
      v25 = v24[5];
      if ( (unsigned int)v25 <= 0x101 )
      {
        v16 = &v22[v25 >> 1];
        p_dest = &v35;
        goto LABEL_29;
      }
    }
LABEL_31:
    __break(0x5512u);
  }
  if ( (unsigned int)v13 >= 0x81 )
  {
    _fortify_panic(17, 128, v13);
    goto LABEL_33;
  }
  if ( (unsigned int)v13 >= 0x41 && (cqhci_crypto_keyslot_program___already_done_4 & 1) == 0 )
  {
    v26 = a2;
    cqhci_crypto_keyslot_program___already_done_4 = 1;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v13,
      "field \"cfg.crypto_key\" at ../soc-repo/drivers/mmc/host/cqhci-crypto.c:99",
      0x40u);
    a2 = v26;
    __break(0x800u);
  }
  p_dest = &dest;
  v16 = (char *)(a2 + 6);
  v17 = v13;
LABEL_29:
  memcpy(p_dest, v16, v17);
  result = cqhci_crypto_program_key(v4, &dest, a3);
  dest = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
