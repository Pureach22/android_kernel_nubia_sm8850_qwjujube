__int64 __fastcall qcedev_vbuf_ablk_cipher(__int64 a1, __int64 a2)
{
  unsigned int v4; // w28
  int v5; // w8
  void *v6; // x19
  __int64 v7; // x21
  unsigned int v8; // w11
  unsigned int v9; // w27
  _QWORD *v10; // x23
  _QWORD *v11; // x26
  unsigned int v12; // w0
  _DWORD *v13; // x8
  unsigned int v14; // w9
  __int64 v15; // x10
  __int64 v16; // x10
  unsigned int v17; // w13
  int v18; // w8
  __int64 v19; // x9
  int v20; // w12
  int v21; // w14
  _DWORD *v22; // x11
  unsigned int v23; // w15
  unsigned int v24; // w11
  __int64 v25; // x12
  __int64 v26; // x13
  __int64 v27; // x10
  __int64 v28; // x14
  __int64 v29; // x8
  _QWORD *v30; // x9
  _DWORD *v31; // x8
  __int64 v32; // x11
  __int64 v33; // x10
  int v34; // w11
  unsigned int v35; // w8
  __int64 v36; // x10
  unsigned int v37; // w8
  __int64 v38; // x9
  __int64 v39; // x11
  __int64 v40; // x10
  unsigned int v41; // w20
  __int64 v42; // x0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v45; // x23
  int v46; // [xsp+Ch] [xbp-2B4h] BYREF
  _DWORD dest[168]; // [xsp+10h] [xbp-2B0h] BYREF
  __int64 v48; // [xsp+2B0h] [xbp-10h]

  v4 = 65280;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 716);
  v46 = 0;
  if ( v5 == 2 )
    v4 = 65280 - *(_DWORD *)(a1 + 708);
  v6 = (void *)_kmalloc_large_noprof(65408, 3264);
  if ( !v6 )
    goto LABEL_69;
  while ( 2 )
  {
    v7 = kmemdup_noprof(a1 + 56, 672, 3264);
    if ( !v7 )
    {
      memset(v6, 0, 0xFF80u);
      kfree(v6);
      break;
    }
    if ( *(_DWORD *)(a1 + 596) <= v4 )
    {
      v12 = qcedev_vbuf_ablk_cipher_max_xfer(a1, &v46, a2, v6);
LABEL_39:
      v35 = *(_DWORD *)(v7 + 536);
      if ( v35 )
        goto LABEL_40;
LABEL_58:
      if ( *(_DWORD *)(v7 + 540) )
      {
        v36 = 0;
        v37 = 0;
        while ( 1 )
        {
          v38 = v36 + 16;
          if ( v36 == 256 )
            goto LABEL_56;
          v39 = v7 + v36;
          v40 = a1 + v36;
          *(_DWORD *)(v40 + 328) = *(_DWORD *)(v39 + 272);
          *(_QWORD *)(v40 + 320) = *(_QWORD *)(v39 + 264);
          v37 += *(_DWORD *)(v39 + 272);
          v36 = v38;
          if ( v37 >= *(_DWORD *)(v7 + 540) )
          {
            v35 = *(_DWORD *)(v7 + 536);
            break;
          }
        }
      }
      *(_DWORD *)(a1 + 592) = v35;
      *(_DWORD *)(a1 + 596) = *(_DWORD *)(v7 + 540);
      *(_DWORD *)(a1 + 708) = *(_DWORD *)(v7 + 652);
      v41 = v12;
      memset((void *)v7, 0, 0x2A0u);
      memset(v6, 0, 0xFF80u);
      kfree(v7);
      v42 = (__int64)v6;
LABEL_64:
      kfree(v42);
      result = v41;
      goto LABEL_70;
    }
    memcpy(dest, (const void *)(a1 + 56), sizeof(dest));
    v8 = dest[134];
    if ( !dest[134] )
      goto LABEL_57;
    v9 = 0;
    v10 = (_QWORD *)(a1 + 64);
    while ( 1 )
    {
      if ( v9 >= 0x10 )
      {
LABEL_56:
        while ( 1 )
        {
          __break(0x5512u);
LABEL_57:
          v12 = 0;
          v35 = *(_DWORD *)(v7 + 536);
          if ( !v35 )
            goto LABEL_58;
LABEL_40:
          *(_DWORD *)(a1 + 72) = *(_DWORD *)(v7 + 16);
          *(_QWORD *)(a1 + 64) = *(_QWORD *)(v7 + 8);
          v35 = *(_DWORD *)(v7 + 536);
          if ( v35 > 1 )
          {
            *(_DWORD *)(a1 + 88) = *(_DWORD *)(v7 + 32);
            *(_QWORD *)(a1 + 80) = *(_QWORD *)(v7 + 24);
            v35 = *(_DWORD *)(v7 + 536);
            if ( v35 >= 3 )
            {
              *(_DWORD *)(a1 + 104) = *(_DWORD *)(v7 + 48);
              *(_QWORD *)(a1 + 96) = *(_QWORD *)(v7 + 40);
              v35 = *(_DWORD *)(v7 + 536);
              if ( v35 >= 4 )
              {
                *(_DWORD *)(a1 + 120) = *(_DWORD *)(v7 + 64);
                *(_QWORD *)(a1 + 112) = *(_QWORD *)(v7 + 56);
                v35 = *(_DWORD *)(v7 + 536);
                if ( v35 >= 5 )
                {
                  *(_DWORD *)(a1 + 136) = *(_DWORD *)(v7 + 80);
                  *(_QWORD *)(a1 + 128) = *(_QWORD *)(v7 + 72);
                  v35 = *(_DWORD *)(v7 + 536);
                  if ( v35 >= 6 )
                  {
                    *(_DWORD *)(a1 + 152) = *(_DWORD *)(v7 + 96);
                    *(_QWORD *)(a1 + 144) = *(_QWORD *)(v7 + 88);
                    v35 = *(_DWORD *)(v7 + 536);
                    if ( v35 >= 7 )
                    {
                      *(_DWORD *)(a1 + 168) = *(_DWORD *)(v7 + 112);
                      *(_QWORD *)(a1 + 160) = *(_QWORD *)(v7 + 104);
                      v35 = *(_DWORD *)(v7 + 536);
                      if ( v35 >= 8 )
                      {
                        *(_DWORD *)(a1 + 184) = *(_DWORD *)(v7 + 128);
                        *(_QWORD *)(a1 + 176) = *(_QWORD *)(v7 + 120);
                        v35 = *(_DWORD *)(v7 + 536);
                        if ( v35 >= 9 )
                        {
                          *(_DWORD *)(a1 + 200) = *(_DWORD *)(v7 + 144);
                          *(_QWORD *)(a1 + 192) = *(_QWORD *)(v7 + 136);
                          v35 = *(_DWORD *)(v7 + 536);
                          if ( v35 >= 0xA )
                          {
                            *(_DWORD *)(a1 + 216) = *(_DWORD *)(v7 + 160);
                            *(_QWORD *)(a1 + 208) = *(_QWORD *)(v7 + 152);
                            v35 = *(_DWORD *)(v7 + 536);
                            if ( v35 >= 0xB )
                            {
                              *(_DWORD *)(a1 + 232) = *(_DWORD *)(v7 + 176);
                              *(_QWORD *)(a1 + 224) = *(_QWORD *)(v7 + 168);
                              v35 = *(_DWORD *)(v7 + 536);
                              if ( v35 >= 0xC )
                              {
                                *(_DWORD *)(a1 + 248) = *(_DWORD *)(v7 + 192);
                                *(_QWORD *)(a1 + 240) = *(_QWORD *)(v7 + 184);
                                v35 = *(_DWORD *)(v7 + 536);
                                if ( v35 >= 0xD )
                                {
                                  *(_DWORD *)(a1 + 264) = *(_DWORD *)(v7 + 208);
                                  *(_QWORD *)(a1 + 256) = *(_QWORD *)(v7 + 200);
                                  v35 = *(_DWORD *)(v7 + 536);
                                  if ( v35 >= 0xE )
                                  {
                                    *(_DWORD *)(a1 + 280) = *(_DWORD *)(v7 + 224);
                                    *(_QWORD *)(a1 + 272) = *(_QWORD *)(v7 + 216);
                                    v35 = *(_DWORD *)(v7 + 536);
                                    if ( v35 >= 0xF )
                                    {
                                      *(_DWORD *)(a1 + 296) = *(_DWORD *)(v7 + 240);
                                      *(_QWORD *)(a1 + 288) = *(_QWORD *)(v7 + 232);
                                      v35 = *(_DWORD *)(v7 + 536);
                                      if ( v35 >= 0x10 )
                                      {
                                        *(_DWORD *)(a1 + 312) = *(_DWORD *)(v7 + 256);
                                        *(_QWORD *)(a1 + 304) = *(_QWORD *)(v7 + 248);
                                        v35 = *(_DWORD *)(v7 + 536);
                                        if ( v35 > 0x10 )
                                          continue;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          goto LABEL_58;
        }
      }
      v11 = &v10[2 * (int)v9];
      if ( *((_DWORD *)v11 + 2) <= v4 )
        break;
      *(_DWORD *)(a1 + 72) = v4;
      if ( v9 )
        *v10 = *v11;
      *(_DWORD *)(a1 + 596) = v4;
      *(_DWORD *)(a1 + 592) = 1;
      v12 = qcedev_vbuf_ablk_cipher_max_xfer(a1, &v46, a2, v6);
      if ( (v12 & 0x80000000) != 0 )
        goto LABEL_65;
      v13 = &dest[4 * v9 + 2];
      v14 = v13[2] - v4;
      *((_DWORD *)v11 + 2) = v14;
      if ( ((16LL * (int)v9) | 8uLL) > 0x2A0 )
        goto LABEL_66;
      v15 = *(_QWORD *)v13;
      v13[2] = v14;
      v16 = v15 + v4;
      *v11 = v16;
      *(_QWORD *)v13 = v16;
LABEL_35:
      *(_DWORD *)(a1 + 708) = 0;
      if ( !v12 )
      {
        v8 = dest[134];
        v4 = 65280;
        if ( v9 < dest[134] )
          continue;
      }
      goto LABEL_39;
    }
    v17 = *(_DWORD *)(a1 + 708);
    v18 = v8 - v9;
    if ( v8 <= v9 )
    {
      v18 = 0;
      *(_DWORD *)(a1 + 596) = v17;
    }
    else
    {
      v19 = 16LL * v9;
      v20 = 0;
      v21 = v9 - v8;
      v22 = (_DWORD *)(a1 + 72 + v19);
      while ( 1 )
      {
        if ( v9 + v20 == 16 )
          goto LABEL_56;
        v23 = *v22 + v17;
        if ( v23 >= v4 )
          break;
        ++v20;
        v22 += 4;
        v17 = v23;
        if ( !(v21 + v20) )
        {
          v24 = v9 + v20;
          v4 = v23;
          *(_DWORD *)(a1 + 596) = v23;
          if ( !v9 )
            goto LABEL_28;
          goto LABEL_24;
        }
      }
      *v22 = v4 - v17;
      v24 = v9 + v20;
      v18 = v20 + 1;
      *(_DWORD *)(a1 + 596) = v4;
      if ( !v9 )
        goto LABEL_28;
LABEL_24:
      if ( v18 >= 1 )
      {
        v25 = (unsigned int)v18;
        v26 = a1;
        v27 = 16 - v9;
        do
        {
          if ( !v27 )
            goto LABEL_56;
          --v25;
          --v27;
          v28 = *(_QWORD *)(v26 + v19 + 64);
          *(_DWORD *)(v26 + 72) = *(_DWORD *)(v26 + v19 + 72);
          *(_QWORD *)(v26 + 64) = v28;
          v26 += 16;
        }
        while ( v25 );
      }
LABEL_28:
      v9 = v24;
    }
    *(_DWORD *)(a1 + 592) = v18;
    v12 = qcedev_vbuf_ablk_cipher_max_xfer(a1, &v46, a2, v6);
    if ( (v12 & 0x80000000) != 0 )
    {
LABEL_65:
      v41 = v12;
      memset((void *)v7, 0, 0x2A0u);
      memset(v6, 0, 0xFF80u);
      kfree(v6);
      v42 = v7;
      goto LABEL_64;
    }
    *(_DWORD *)(a1 + 708) = 0;
    if ( v9 > 0xF )
      goto LABEL_56;
    if ( ((16LL * v9) | 8uLL) <= 0x2A0 )
    {
      v29 = 4LL * v9;
      v30 = &v10[(unsigned __int64)v29 / 2];
      v31 = &dest[v29 + 2];
      v32 = *((unsigned int *)v30 + 2);
      v33 = *(_QWORD *)v31 + v32;
      v34 = v31[2] - v32;
      if ( !v34 )
        ++v9;
      *v30 = v33;
      *((_DWORD *)v30 + 2) = v34;
      *(_QWORD *)v31 = v33;
      v31[2] = v34;
      goto LABEL_35;
    }
LABEL_66:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v45 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &qcedev_vbuf_ablk_cipher__alloc_tag;
    v6 = (void *)_kmalloc_large_noprof(65408, 3264);
    *(_QWORD *)(StatusReg + 80) = v45;
    if ( v6 )
      continue;
    break;
  }
LABEL_69:
  result = 4294967284LL;
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
