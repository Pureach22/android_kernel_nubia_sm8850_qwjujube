__int64 __fastcall ufshcd_qti_crypto_keyslot_program(__int64 a1, unsigned int *a2, __int64 a3)
{
  int v3; // w12
  __int64 v4; // x19
  __int64 v5; // x10
  __int64 v6; // x14
  unsigned int v7; // w11
  __int64 v8; // x22
  __int64 v9; // x8
  unsigned int v10; // w11
  unsigned __int64 v11; // x12
  char *v12; // x13
  __int64 v13; // x9
  _BYTE *v14; // x10
  unsigned int v15; // w8
  size_t v16; // x20
  unsigned int *v17; // x23
  __int64 v18; // x21
  unsigned int v19; // w24
  __int64 result; // x0
  size_t v21; // x8
  unsigned int v22; // w24
  bool v23; // cf
  char *v24; // x20
  unsigned __int64 v25; // x9
  size_t v26; // x2
  unsigned int *v27; // x8
  unsigned __int64 v28; // x8
  unsigned int v29; // w23
  unsigned int v30; // w20
  unsigned int *v31; // x21
  __int64 v32; // x2
  unsigned int v33; // w20
  __int64 v34; // x1
  size_t v35; // [xsp+0h] [xbp-90h]
  size_t v36; // [xsp+0h] [xbp-90h]
  __int64 dest; // [xsp+8h] [xbp-88h] BYREF
  __int64 v38; // [xsp+10h] [xbp-80h]
  __int64 v39; // [xsp+18h] [xbp-78h]
  __int64 v40; // [xsp+20h] [xbp-70h]
  __int64 v41; // [xsp+28h] [xbp-68h] BYREF
  __int64 v42; // [xsp+30h] [xbp-60h]
  __int64 v43; // [xsp+38h] [xbp-58h]
  __int64 v44; // [xsp+40h] [xbp-50h]
  __int64 v45; // [xsp+48h] [xbp-48h]
  __int64 v46; // [xsp+50h] [xbp-40h]
  __int64 v47; // [xsp+58h] [xbp-38h]
  __int64 v48; // [xsp+60h] [xbp-30h]
  __int64 v49; // [xsp+68h] [xbp-28h]
  __int64 v50; // [xsp+70h] [xbp-20h]
  __int64 v51; // [xsp+78h] [xbp-18h]
  __int64 v52; // [xsp+80h] [xbp-10h]
  __int64 v53; // [xsp+88h] [xbp-8h]

  v4 = a1 - 4544;
  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 4544 )
    goto LABEL_44;
  v5 = *a2;
  if ( (unsigned int)v5 >= 6 )
    goto LABEL_40;
  v6 = *(_QWORD *)(a1 - 16);
  v7 = a2[1];
  v8 = *(_QWORD *)(a1 - 4360);
  v9 = *(unsigned __int8 *)(a1 - 24);
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  dest = 0;
  v38 = 0;
  if ( !v9 )
  {
LABEL_17:
    __break(0x800u);
    result = 4294967201LL;
    goto LABEL_18;
  }
  v10 = v7 >> 9;
  v11 = (8LL * (unsigned int)v5) | 4;
  v12 = (char *)&ufs_crypto_algs + 8 * v5;
  v13 = 0;
  v14 = (_BYTE *)(v6 + 1);
  while ( 1 )
  {
    if ( !*(v14 - 1) )
    {
      if ( v11 > 0x28 )
      {
        __break(1u);
        goto LABEL_40;
      }
      if ( *((_DWORD *)v12 + 1) == (unsigned __int8)v14[1] && ((unsigned __int8)v10 & *v14) != 0 )
        break;
    }
    ++v13;
    v14 += 4;
    if ( v9 == v13 )
      goto LABEL_17;
  }
  v15 = a2[3];
  LOBYTE(v45) = v10;
  BYTE1(v45) = v13;
  if ( v15 == 2 )
    goto LABEL_31;
  v16 = a2[5];
  v17 = a2;
  v18 = a1;
  if ( !*(v14 - 1) )
  {
    v21 = v16 >> 1;
    if ( (unsigned int)v16 >= 0x102 )
    {
LABEL_42:
      _fortify_panic(17, 128, v21);
      goto LABEL_43;
    }
    v22 = a3;
    v23 = (unsigned int)v16 >= 0x82;
    v24 = (char *)(a2 + 6);
    if ( v23 && (ufshcd_qti_crypto_keyslot_program___already_done & 1) == 0 )
    {
      ufshcd_qti_crypto_keyslot_program___already_done = 1;
      v35 = v21;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v21,
        "field \"cfg.crypto_key\" at ../soc-repo/drivers/ufs/host/ufshcd-crypto-qti.c:59",
        0x40u);
      v21 = v35;
      __break(0x800u);
    }
    memcpy(&dest, v24, v21);
    v25 = v17[5];
    if ( (unsigned int)v25 <= 0x101 )
    {
      v26 = v25 >> 1;
      if ( (unsigned int)v25 >= 0xC2 )
      {
LABEL_43:
        a1 = _fortify_panic(17, 96, v26);
LABEL_44:
        __break(0x800u);
        if ( (v3 & 0x10000000) == 0 )
          JUMPOUT(0x94A4);
        return ufshcd_qti_crypto_keyslot_evict(a1);
      }
      v27 = v17;
      if ( (unsigned int)v25 >= 0x42 && (ufshcd_qti_crypto_keyslot_program___already_done_2 & 1) == 0 )
      {
        ufshcd_qti_crypto_keyslot_program___already_done_2 = 1;
        v36 = v25 >> 1;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v26,
          "field \"cfg.crypto_key + 64 / 2\" at ../soc-repo/drivers/ufs/host/ufshcd-crypto-qti.c:61",
          0x20u);
        v26 = v36;
        v27 = v17;
        __break(0x800u);
      }
      v28 = v27[5];
      if ( (unsigned int)v28 <= 0x101 )
      {
        memcpy(&v41, &v24[v28 >> 1], v26);
        a1 = v18;
        a2 = v17;
        a3 = v22;
        goto LABEL_31;
      }
    }
LABEL_40:
    __break(0x5512u);
  }
  if ( (unsigned int)v16 >= 0x81 )
  {
    _fortify_panic(17, 128, v16);
    goto LABEL_42;
  }
  v19 = a3;
  if ( (unsigned int)v16 >= 0x41 && (ufshcd_qti_crypto_keyslot_program___already_done_4 & 1) == 0 )
  {
    v34 = a2[5];
    ufshcd_qti_crypto_keyslot_program___already_done_4 = 1;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v34,
      "field \"cfg.crypto_key\" at ../soc-repo/drivers/ufs/host/ufshcd-crypto-qti.c:63",
      0x40u);
    __break(0x800u);
  }
  memcpy(&dest, v17 + 6, v16);
  a2 = v17;
  a3 = v19;
  a1 = v18;
LABEL_31:
  if ( *(_BYTE *)(v8 + 176) == 1 )
  {
    printk(&unk_6822, *(unsigned int *)(a1 - 4048), a3);
    result = 4294967274LL;
  }
  else
  {
    v29 = a2[3];
    v30 = a3;
    v31 = a2;
    ufshcd_hold(v4);
    if ( v29 == 2 )
      v32 = 5;
    else
      v32 = 3;
    v33 = qcom_ice_program_key_hwkm(*(_QWORD *)(v8 + 152), 0, v32, v31, (unsigned __int8)v45, v30);
    if ( v33 )
      printk(&unk_6870, "ufshcd_qti_crypto_keyslot_program", v33);
    ufshcd_release(v4);
    v51 = 0;
    v52 = 0;
    result = v33;
    v49 = 0;
    v50 = 0;
    v47 = 0;
    v48 = 0;
    v45 = 0;
    v46 = 0;
    v43 = 0;
    v44 = 0;
    v41 = 0;
    v42 = 0;
    v39 = 0;
    v40 = 0;
    dest = 0;
    v38 = 0;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
