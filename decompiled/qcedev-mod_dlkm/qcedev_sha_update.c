__int64 __fastcall qcedev_sha_update(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x3
  __int64 *v8; // x25
  __int64 *v9; // x23
  unsigned int v10; // w12
  unsigned int v11; // w26
  __int64 *v12; // x28
  unsigned int updated; // w0
  _DWORD *v14; // x8
  int v15; // w9
  __int64 v16; // x10
  int v17; // w8
  __int64 v18; // x9
  int v19; // w11
  unsigned int v20; // w13
  int v21; // w15
  __int64 v22; // x12
  unsigned int v23; // w14
  unsigned int v24; // w28
  __int64 v25; // x11
  __int64 v26; // x12
  __int64 v27; // x10
  __int64 v28; // x13
  __int64 v29; // x10
  _DWORD *v30; // x9
  __int64 *v31; // x10
  __int64 v32; // x11
  __int64 v33; // x12
  int v34; // w13
  int v35; // w11
  __int64 result; // x0
  int v37; // w8
  __int64 v38; // x10
  __int64 v39; // x10
  __int64 v40; // x10
  __int64 v41; // x10
  __int64 v42; // x10
  __int64 v43; // x10
  __int64 v44; // x10
  __int64 v45; // x10
  __int64 v46; // x10
  __int64 v47; // x10
  __int64 v48; // x10
  __int64 v49; // x10
  __int64 v50; // x10
  __int64 v51; // x10
  __int64 v52; // x10
  __int64 v53; // x10
  unsigned int v54; // w19
  _DWORD dest[80]; // [xsp+10h] [xbp-150h] BYREF
  __int64 v56; // [xsp+150h] [xbp-10h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 194) & 1) == 0 )
  {
    printk(&unk_1260A, "qcedev_sha_update", a3, a4);
    result = 4294967274LL;
    goto LABEL_54;
  }
  if ( *(_DWORD *)(a1 + 316) >= 0xFF01u )
  {
    v8 = (__int64 *)_kmalloc_cache_noprof(memmove, 3264, 320);
    if ( !v8 )
    {
      printk(&unk_119A9, "qcedev_sha_update", 0, v7);
      result = 4294967284LL;
      goto LABEL_54;
    }
    v9 = (__int64 *)(a1 + 56);
    memcpy(dest, (const void *)(a1 + 56), sizeof(dest));
    memcpy(v8, (const void *)(a1 + 56), 0x140u);
    v10 = dest[64];
    if ( !dest[64] )
    {
      updated = 0;
      goto LABEL_36;
    }
    v11 = 0;
    while ( 1 )
    {
      if ( v11 >= 0x10 )
        goto LABEL_56;
      v12 = &v9[2 * (int)v11];
      if ( *((_DWORD *)v12 + 2) > 0xFF00u )
      {
        *(_DWORD *)(a1 + 64) = 65280;
        if ( v11 )
          *v9 = *v12;
        *(_QWORD *)(a1 + 312) = 0xFF0000000001LL;
        updated = qcedev_sha_update_max_xfer(a1, a2, a3);
        if ( ((16LL * (int)v11) | 8uLL) <= 0x140 )
        {
          v14 = &dest[4 * v11];
          v15 = v14[2] - 65280;
          v16 = *(_QWORD *)v14 + 65280LL;
          *((_DWORD *)v12 + 2) = v15;
          *v12 = v16;
          *(_QWORD *)v14 = v16;
          v14[2] = v15;
          goto LABEL_31;
        }
        goto LABEL_57;
      }
      v17 = v10 - v11;
      if ( v10 <= v11 )
      {
        *(_QWORD *)(a1 + 312) = 0;
        updated = qcedev_sha_update_max_xfer(a1, a2, a3);
        goto LABEL_27;
      }
      v18 = 16LL * v11;
      v19 = 0;
      v20 = 0;
      v21 = v11 - v10;
      v22 = v18 + 64;
      do
      {
        if ( v11 + v19 == 16 )
          goto LABEL_56;
        v23 = *(_DWORD *)(a1 + v22) + v20;
        if ( v23 >> 8 >= 0xFF )
        {
          v24 = v11 + v19;
          *(_DWORD *)(a1 + v22) = 65280 - v20;
          v17 = v19 + 1;
          *(_DWORD *)(a1 + 316) = 65280;
          if ( !v11 )
            goto LABEL_25;
LABEL_21:
          if ( v17 < 1 )
            goto LABEL_25;
          v25 = (unsigned int)v17;
          v26 = a1;
          v27 = 16 - v11;
          while ( v27 )
          {
            --v25;
            --v27;
            v28 = *(_QWORD *)(v26 + v18 + 56);
            *(_DWORD *)(v26 + 64) = *(_DWORD *)(v26 + v18 + 64);
            *(_QWORD *)(v26 + 56) = v28;
            v26 += 16;
            if ( !v25 )
              goto LABEL_25;
          }
          goto LABEL_56;
        }
        ++v19;
        v22 += 16;
        v20 = v23;
      }
      while ( v21 + v19 );
      v24 = v11 + v19;
      *(_DWORD *)(a1 + 316) = v23;
      if ( v11 )
        goto LABEL_21;
LABEL_25:
      *(_DWORD *)(a1 + 312) = v17;
      updated = qcedev_sha_update_max_xfer(a1, a2, a3);
      if ( v24 > 0xF )
        goto LABEL_56;
      v11 = v24;
LABEL_27:
      v29 = 16LL * v11;
      v30 = &dest[(unsigned __int64)v29 / 4];
      v31 = &v9[(unsigned __int64)v29 / 8];
      v32 = *((unsigned int *)v31 + 2);
      v33 = *(_QWORD *)v30 + v32;
      *v31 = v33;
      if ( ((16LL * v11) | 8uLL) > 0x140 )
        goto LABEL_57;
      v34 = v30[2];
      *(_QWORD *)v30 = v33;
      v35 = v34 - v32;
      if ( !v35 )
        ++v11;
      *((_DWORD *)v31 + 2) = v35;
      v30[2] = v35;
LABEL_31:
      v10 = dest[64];
      if ( v11 >= dest[64] || updated )
      {
LABEL_36:
        v37 = *((_DWORD *)v8 + 64);
        if ( !v37 )
          goto LABEL_53;
        v38 = *v8;
        *(_DWORD *)(a1 + 64) = *((_DWORD *)v8 + 2);
        *(_QWORD *)(a1 + 56) = v38;
        if ( v37 == 1 )
          goto LABEL_53;
        v39 = v8[2];
        *(_DWORD *)(a1 + 80) = *((_DWORD *)v8 + 6);
        *(_QWORD *)(a1 + 72) = v39;
        if ( v37 == 2 )
          goto LABEL_53;
        v40 = v8[4];
        *(_DWORD *)(a1 + 96) = *((_DWORD *)v8 + 10);
        *(_QWORD *)(a1 + 88) = v40;
        if ( v37 == 3 )
          goto LABEL_53;
        v41 = v8[6];
        *(_DWORD *)(a1 + 112) = *((_DWORD *)v8 + 14);
        *(_QWORD *)(a1 + 104) = v41;
        if ( v37 == 4 )
          goto LABEL_53;
        v42 = v8[8];
        *(_DWORD *)(a1 + 128) = *((_DWORD *)v8 + 18);
        *(_QWORD *)(a1 + 120) = v42;
        if ( v37 == 5 )
          goto LABEL_53;
        v43 = v8[10];
        *(_DWORD *)(a1 + 144) = *((_DWORD *)v8 + 22);
        *(_QWORD *)(a1 + 136) = v43;
        if ( v37 == 6 )
          goto LABEL_53;
        v44 = v8[12];
        *(_DWORD *)(a1 + 160) = *((_DWORD *)v8 + 26);
        *(_QWORD *)(a1 + 152) = v44;
        if ( v37 == 7 )
          goto LABEL_53;
        v45 = v8[14];
        *(_DWORD *)(a1 + 176) = *((_DWORD *)v8 + 30);
        *(_QWORD *)(a1 + 168) = v45;
        if ( v37 == 8 )
          goto LABEL_53;
        v46 = v8[16];
        *(_DWORD *)(a1 + 192) = *((_DWORD *)v8 + 34);
        *(_QWORD *)(a1 + 184) = v46;
        if ( v37 == 9 )
          goto LABEL_53;
        v47 = v8[18];
        *(_DWORD *)(a1 + 208) = *((_DWORD *)v8 + 38);
        *(_QWORD *)(a1 + 200) = v47;
        if ( v37 == 10 )
          goto LABEL_53;
        v48 = v8[20];
        *(_DWORD *)(a1 + 224) = *((_DWORD *)v8 + 42);
        *(_QWORD *)(a1 + 216) = v48;
        if ( v37 == 11 )
          goto LABEL_53;
        v49 = v8[22];
        *(_DWORD *)(a1 + 240) = *((_DWORD *)v8 + 46);
        *(_QWORD *)(a1 + 232) = v49;
        if ( v37 == 12 )
          goto LABEL_53;
        v50 = v8[24];
        *(_DWORD *)(a1 + 256) = *((_DWORD *)v8 + 50);
        *(_QWORD *)(a1 + 248) = v50;
        if ( v37 == 13 )
          goto LABEL_53;
        v51 = v8[26];
        *(_DWORD *)(a1 + 272) = *((_DWORD *)v8 + 54);
        *(_QWORD *)(a1 + 264) = v51;
        if ( v37 == 14
          || (v52 = v8[28], *(_DWORD *)(a1 + 288) = *((_DWORD *)v8 + 58), *(_QWORD *)(a1 + 280) = v52, v37 == 15)
          || (v53 = v8[30], *(_DWORD *)(a1 + 304) = *((_DWORD *)v8 + 62), *(_QWORD *)(a1 + 296) = v53, v37 == 16) )
        {
LABEL_53:
          *(_DWORD *)(a1 + 312) = v37;
          *(_DWORD *)(a1 + 316) = *((_DWORD *)v8 + 65);
          v54 = updated;
          memset(v8, 0, 0x140u);
          kfree(v8);
          result = v54;
          goto LABEL_54;
        }
LABEL_56:
        __break(0x5512u);
LABEL_57:
        __break(1u);
      }
    }
  }
  result = qcedev_sha_update_max_xfer(a1, a2, a3);
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
