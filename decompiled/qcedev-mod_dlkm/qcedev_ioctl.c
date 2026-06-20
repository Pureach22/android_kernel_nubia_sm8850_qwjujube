__int64 __fastcall qcedev_ioctl(__int64 a1, unsigned int a2, char *a3)
{
  unsigned __int64 v4; // x24
  __int64 v6; // x3
  __int64 v7; // x19
  __int64 v8; // x23
  __int64 v9; // x1
  size_t v10; // x2
  __int64 v11; // x3
  int v12; // w22
  _QWORD *v13; // x25
  __int64 result; // x0
  _QWORD *StatusReg; // x25
  unsigned __int64 v16; // x8
  _QWORD *v17; // x24
  int v18; // w8
  unsigned int v19; // w4
  unsigned int v20; // w8
  unsigned int v21; // w10
  __int64 i; // x8
  void *v23; // x0
  __int64 v24; // x2
  __int64 v25; // x3
  int v26; // w8
  int v27; // w0
  __int64 v28; // x3
  unsigned int *v29; // x26
  __int64 v30; // x27
  int v31; // w0
  __int64 v32; // x2
  unsigned int v33; // t1
  __int64 v34; // x2
  __int64 v35; // x3
  __int64 v36; // x1
  size_t v37; // x2
  size_t v38; // x22
  int v39; // w0
  _QWORD *v40; // x1
  void *v41; // x0
  size_t v42; // x2
  __int64 v43; // x11
  __int64 v44; // x9
  int v45; // w13
  unsigned int v46; // w9
  __int64 v47; // x10
  unsigned int v48; // w9
  __int64 v49; // x9
  unsigned int *v50; // x10
  const char *v51; // x1
  __int64 v52; // x2
  void *v53; // x0
  size_t v54; // x22
  unsigned __int64 v55; // x22
  __int64 v56; // x23
  __int64 v57; // [xsp+0h] [xbp-160h] BYREF
  _QWORD s[43]; // [xsp+8h] [xbp-158h] BYREF

  v4 = a2;
  s[41] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = _kmalloc_cache_noprof(_arch_copy_to_user, 3520, 952);
  if ( !v7 )
  {
LABEL_209:
    result = -12;
    goto LABEL_210;
  }
  while ( 1 )
  {
    a1 = *(_QWORD *)(a1 + 32);
    v8 = *(_QWORD *)a1;
    *(_QWORD *)(v7 + 904) = a1;
    if ( !v8 || *(_DWORD *)(v8 + 240) != 1447249220 )
    {
      printk(&unk_126B9, "qcedev_ioctl", v8, v6);
      v12 = -2;
      goto LABEL_24;
    }
    if ( (v4 & 0xFF00) != 0x8700 )
      goto LABEL_23;
    *(_DWORD *)(v7 + 16) = 0;
    _init_swait_queue_head(v7 + 24, "&x->wait", &init_completion___key);
    v12 = -25;
    if ( (int)v4 > -1052211447 )
    {
      if ( (int)v4 <= -1029667072 )
      {
        if ( (_DWORD)v4 != -1052211446 )
        {
          if ( (_DWORD)v4 == -1034385652 )
            v12 = qcedev_offload_ioctl(a1, v9, v7, (unsigned __int64)a3);
          goto LABEL_24;
        }
        v57 = 0;
        memset(s, 0, 0x148u);
        StatusReg = (_QWORD *)_ReadStatusReg(SP_EL0);
        if ( (*StatusReg & 0x400000) != 0 )
        {
          memmove(s, a3, 0x148u);
        }
        else if ( (unsigned int)inline_copy_from_user((int)s, (int)a3, 0x148u) )
        {
          goto LABEL_128;
        }
        v10 = LODWORD(s[8]);
        if ( LODWORD(s[8]) <= 0x10 )
        {
          if ( !LODWORD(s[8]) )
          {
LABEL_77:
            if ( (*StatusReg & 0x400000) != 0 )
            {
              v40 = s;
              v41 = a3;
              v42 = 328;
              goto LABEL_131;
            }
            if ( !(unsigned int)inline_copy_to_user(a3, s, 328) )
              goto LABEL_132;
            goto LABEL_128;
          }
          v29 = (unsigned int *)s;
          v30 = 0;
          v4 = (unsigned __int64)"qcedev_ioctl";
          while ( v30 != 16 )
          {
            v31 = qcedev_check_and_map_buffer(a1, *v29, v29[33], v29[17], &v57);
            if ( v31 )
            {
              v52 = *v29;
              v12 = v31;
              v53 = &unk_1195B;
LABEL_192:
              printk(v53, "qcedev_ioctl", v52, (unsigned int)v12);
              goto LABEL_24;
            }
            v32 = v57;
            s[v30 + 25] = v57;
            v33 = *v29++;
            printk(&unk_1202A, "qcedev_ioctl", v32, v33);
            v16 = LODWORD(s[8]);
            if ( ++v30 >= (unsigned __int64)LODWORD(s[8]) )
              goto LABEL_77;
          }
          goto LABEL_206;
        }
LABEL_172:
        v23 = &unk_11BA8;
        v51 = "qcedev_ioctl";
LABEL_200:
        printk(v23, v51, v10, v11);
        goto LABEL_201;
      }
      if ( (unsigned int)(v4 + 1029667071) >= 2 )
      {
        if ( (_DWORD)v4 == -1023899892 )
          v12 = qcedev_ext_cipher_ioctl(a1, v9, (_DWORD *)v7, (unsigned __int64)a3);
        goto LABEL_24;
      }
      v13 = (_QWORD *)_ReadStatusReg(SP_EL0);
      if ( (*v13 & 0x400000) != 0 )
      {
        memmove((void *)(v7 + 56), a3, 0x2A0u);
      }
      else if ( (unsigned int)inline_copy_from_user((int)v7 + 56, (int)a3, 0x2A0u) )
      {
        goto LABEL_128;
      }
      v4 = v7 + 56;
      v18 = *(unsigned __int8 *)(v7 + 56);
      *(_DWORD *)(v7 + 48) = 0;
      if ( v18 )
      {
        v23 = &unk_11AD8;
        goto LABEL_199;
      }
      v10 = *(unsigned int *)(v7 + 592);
      if ( !(_DWORD)v10 || (unsigned int)v10 > 0x10 || (v19 = *(_DWORD *)(v7 + 596)) == 0 )
      {
        v23 = &unk_1204D;
        goto LABEL_199;
      }
      v20 = *(_DWORD *)(v7 + 712);
      if ( v20 > 2 || (v21 = *(_DWORD *)(v7 + 716), v21 >= 7) )
      {
        v23 = &unk_12CEA;
LABEL_176:
        v51 = "qcedev_check_cipher_params";
LABEL_177:
        v10 = v20;
        goto LABEL_200;
      }
      if ( v21 == 3 && (*(_BYTE *)(v8 + 30) & 1) == 0 )
      {
        v23 = &unk_120A0;
        goto LABEL_199;
      }
      if ( v20 == 2 )
      {
        v20 = *(_DWORD *)(v7 + 668);
        if ( v20 == 24 )
        {
          if ( (*(_BYTE *)(v8 + 29) & 1) == 0 )
          {
            v23 = &unk_11C0B;
LABEL_197:
            v51 = "qcedev_check_key";
            goto LABEL_200;
          }
          goto LABEL_135;
        }
        if ( !v20 )
        {
          for ( i = 0; i != 64; ++i )
          {
            if ( *(_BYTE *)(v7 + 601 + i) )
            {
              v23 = &unk_12C68;
              goto LABEL_197;
            }
          }
          v20 = *(_DWORD *)(v7 + 720);
          if ( (v20 & 0xFFFFFFFE) != 2 && !*(_DWORD *)(v8 + 8) )
          {
            v23 = &unk_123C1;
            goto LABEL_205;
          }
          goto LABEL_135;
        }
        if ( v21 == 3 )
        {
          if ( v20 != 32 && v20 != 64 )
          {
            v23 = &unk_1192E;
LABEL_205:
            v51 = "qcedev_check_key";
            goto LABEL_177;
          }
        }
        else if ( v20 != 16 && v20 != 32 )
        {
          v23 = &unk_12D23;
          goto LABEL_205;
        }
      }
LABEL_135:
      v16 = *(unsigned int *)(v7 + 708);
      v43 = 16 * v10;
      if ( (_DWORD)v16 )
      {
        if ( v21 == 2 )
        {
          if ( (unsigned int)v16 <= 0xF )
          {
            v44 = 0;
            while ( v44 != 256 )
            {
              v45 = *(_DWORD *)(v7 + 72 + v44);
              if ( __CFADD__(v45, (_DWORD)v16) )
              {
                v23 = &unk_11AFC;
                goto LABEL_199;
              }
              v44 += 16;
              v16 = (unsigned int)(v45 + v16);
              if ( v43 == v44 )
                goto LABEL_142;
            }
            goto LABEL_206;
          }
          v23 = &unk_12175;
        }
        else
        {
          v23 = &unk_118E0;
        }
LABEL_199:
        v51 = "qcedev_check_cipher_params";
        goto LABEL_200;
      }
LABEL_142:
      v20 = *(_DWORD *)(v7 + 704);
      if ( v20 < 0x21 )
      {
        v46 = *(_DWORD *)(v7 + 668);
        if ( v46 >= 0x41 )
        {
          v23 = &unk_11E12;
          v51 = "qcedev_check_cipher_params";
          v10 = v46;
          goto LABEL_200;
        }
        if ( v20 )
        {
          if ( v21 == 6 || v21 == 1 )
          {
            v23 = &unk_12A13;
            goto LABEL_199;
          }
        }
        else if ( v21 != 1 && v21 != 6 )
        {
          v23 = &unk_11E31;
          goto LABEL_199;
        }
        v47 = 0;
        v16 = 0;
        v11 = 0;
        while ( v47 != 256 )
        {
          v48 = *(_DWORD *)(v7 + v47 + 328);
          if ( !*(_QWORD *)(v7 + v47 + 320) && v48 )
          {
            v23 = &unk_12395;
            v51 = "qcedev_check_cipher_params";
            v10 = (unsigned int)v16;
            v11 = v48;
            goto LABEL_200;
          }
          if ( v48 >= ~(_DWORD)v11 )
          {
            v23 = &unk_12AFA;
            goto LABEL_199;
          }
          v47 += 16;
          v11 = v48 + (unsigned int)v11;
          v16 = (unsigned int)(v16 + 1);
          if ( v43 == v47 )
          {
            if ( (_DWORD)v11 != v19 )
            {
              printk(&unk_12A80, "qcedev_check_cipher_params", v10, v11);
              goto LABEL_201;
            }
            v49 = 0;
            v16 = 0;
            v50 = (unsigned int *)(v7 + 72);
            while ( v49 != 16 )
            {
              v11 = *v50;
              if ( *((_QWORD *)v50 - 1) )
              {
                if ( __CFADD__((_DWORD)v16, (_DWORD)v11) )
                {
                  v23 = &unk_12459;
                  goto LABEL_199;
                }
              }
              else if ( (_DWORD)v11 )
              {
                v23 = &unk_1242D;
                v51 = "qcedev_check_cipher_params";
                v10 = (unsigned int)v49;
                goto LABEL_200;
              }
              ++v49;
              v16 = (unsigned int)(v11 + v16);
              v50 += 4;
              if ( v10 == v49 )
              {
                if ( (_DWORD)v16 != v19 )
                {
                  v23 = &unk_124BC;
                  v51 = "qcedev_check_cipher_params";
                  v10 = (unsigned int)v16;
                  v11 = v19;
                  goto LABEL_200;
                }
                v12 = qcedev_vbuf_ablk_cipher(v7, a1);
                if ( !v12 )
                {
                  if ( (*v13 & 0x400000) != 0 )
                  {
                    memmove(a3, (const void *)(v7 + 56), 0x2A0u);
                    v12 = 0;
                  }
                  else if ( (unsigned int)inline_copy_to_user(a3, v7 + 56, 672) )
                  {
                    v12 = -14;
                  }
                  else
                  {
                    v12 = 0;
                  }
                }
                goto LABEL_24;
              }
            }
            break;
          }
        }
LABEL_206:
        __break(0x5512u);
        goto LABEL_207;
      }
      v23 = &unk_1190E;
      goto LABEL_176;
    }
    if ( (int)v4 <= -1052735740 )
    {
      if ( (_DWORD)v4 != -1069250805 )
      {
        if ( (_DWORD)v4 == -1052735741 )
        {
          v17 = (_QWORD *)_ReadStatusReg(SP_EL0);
          memset(s, 0, 32);
          if ( (*v17 & 0x400000) != 0 )
          {
            memmove((void *)(v7 + 56), a3, 0x140u);
          }
          else if ( (unsigned int)inline_copy_from_user((int)v7 + 56, (int)a3, 0x140u) )
          {
            goto LABEL_128;
          }
          mutex_lock(&hash_access_lock);
          if ( (unsigned int)qcedev_check_sha_params(v7 + 56, v8) )
            goto LABEL_105;
          *(_DWORD *)(v7 + 48) = 1;
          v12 = qcedev_hash_init(v7, a1, s);
          mutex_unlock(&hash_access_lock);
          if ( v12 )
            goto LABEL_24;
          if ( (*v17 & 0x400000) != 0 )
          {
            memmove(a3, (const void *)(v7 + 56), 0x140u);
          }
          else if ( (unsigned int)inline_copy_to_user(a3, v7 + 56, 320) )
          {
            goto LABEL_128;
          }
          v12 = 0;
          *(_BYTE *)(a1 + 194) = 1;
          goto LABEL_24;
        }
        if ( (_DWORD)v4 != -1052735740 )
          goto LABEL_24;
        goto LABEL_20;
      }
      memset(s, 0, 68);
      if ( (*(_QWORD *)_ReadStatusReg(SP_EL0) & 0x400000) != 0 )
      {
        memmove(s, a3, 0x44u);
      }
      else if ( (unsigned int)inline_copy_from_user((int)s, (int)a3, 0x44u) )
      {
        goto LABEL_128;
      }
      v10 = LODWORD(s[8]);
      if ( LODWORD(s[8]) <= 0x10 )
      {
        if ( !LODWORD(s[8]) )
          goto LABEL_132;
        a3 = nullptr;
        while ( a3 != byte_10 )
        {
          v39 = qcedev_check_and_unmap_buffer(a1, *((unsigned int *)s + (_QWORD)a3));
          if ( v39 )
          {
            v12 = v39;
            v53 = &unk_11981;
            v52 = *((unsigned int *)s + (_QWORD)a3);
            goto LABEL_192;
          }
          v16 = LODWORD(s[8]);
          if ( (unsigned __int64)++a3 >= LODWORD(s[8]) )
            goto LABEL_132;
        }
        goto LABEL_206;
      }
      goto LABEL_172;
    }
    if ( (_DWORD)v4 != -1052735739 )
    {
      if ( (_DWORD)v4 != -1052735738 )
      {
        if ( (_DWORD)v4 != -1052735735 )
          goto LABEL_24;
        if ( *(_BYTE *)(v8 + 28) != 1 )
        {
LABEL_23:
          v12 = -25;
          goto LABEL_24;
        }
LABEL_20:
        v4 = _ReadStatusReg(SP_EL0);
        memset(s, 0, 32);
        if ( (*(_QWORD *)v4 & 0x400000) != 0 )
        {
          memmove((void *)(v7 + 56), a3, 0x140u);
          goto LABEL_66;
        }
        if ( !(unsigned int)inline_copy_from_user((int)v7 + 56, (int)a3, 0x140u) )
        {
LABEL_66:
          mutex_lock(&hash_access_lock);
          if ( (unsigned int)qcedev_check_sha_params(v7 + 56, v8) )
            goto LABEL_105;
          v26 = *(_DWORD *)(v7 + 372);
          *(_DWORD *)(v7 + 48) = 1;
          if ( v26 == 4 )
          {
            v27 = qcedev_hash_cmac(v7, a1, s);
            if ( !v27 )
              goto LABEL_125;
          }
          else
          {
            if ( (*(_BYTE *)(a1 + 194) & 1) == 0 )
            {
              printk(&unk_1260A, "qcedev_ioctl", v24, v25);
              goto LABEL_105;
            }
            v27 = qcedev_sha_update(v7, a1, s);
            if ( !v27 )
            {
LABEL_125:
              v37 = *(unsigned int *)(a1 + 56);
              if ( (unsigned int)v37 >= 0x21 )
              {
                printk(&unk_11DAC, (unsigned int)v37, v37, v28);
                goto LABEL_105;
              }
              goto LABEL_126;
            }
          }
LABEL_117:
          v12 = v27;
          mutex_unlock(&hash_access_lock);
          goto LABEL_24;
        }
LABEL_128:
        v12 = -14;
        goto LABEL_24;
      }
      v4 = _ReadStatusReg(SP_EL0);
      memset(s, 0, 32);
      if ( (*(_QWORD *)v4 & 0x400000) != 0 )
      {
        memmove((void *)(v7 + 56), a3, 0x140u);
      }
      else if ( (unsigned int)inline_copy_from_user((int)v7 + 56, (int)a3, 0x140u) )
      {
        goto LABEL_128;
      }
      mutex_lock(&hash_access_lock);
      if ( (unsigned int)qcedev_check_sha_params(v7 + 56, v8) )
        goto LABEL_105;
      *(_DWORD *)(v7 + 48) = 1;
      qcedev_hash_init(v7, a1, s);
      v27 = qcedev_sha_update(v7, a1, s);
      if ( v27 )
        goto LABEL_117;
      v27 = qcedev_hash_final(v7, a1);
      if ( v27 )
        goto LABEL_117;
      v36 = *(unsigned int *)(a1 + 56);
      if ( (unsigned int)v36 >= 0x21 )
        break;
      *(_DWORD *)(v7 + 352) = v36;
      v37 = *(unsigned int *)(a1 + 56);
      if ( (unsigned int)v37 < 0x279 )
      {
        if ( (unsigned int)v37 >= 0x21 && (qcedev_ioctl___already_done_41 & 1) == 0 )
        {
          qcedev_ioctl___already_done_41 = 1;
          v38 = v37;
          _warn_printk(
            "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
            v37,
            "field \"&qcedev_areq->sha_op_req.digest[0]\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcedev.c:2597",
            0x20u);
          v37 = v38;
          __break(0x800u);
        }
LABEL_126:
        memcpy((void *)(v7 + 320), (const void *)(a1 + 24), v37);
        mutex_unlock(&hash_access_lock);
        if ( (*(_QWORD *)v4 & 0x400000) == 0 )
        {
          if ( (unsigned int)inline_copy_to_user(a3, v7 + 56, 320) )
            goto LABEL_128;
LABEL_132:
          v12 = 0;
          goto LABEL_24;
        }
        v40 = (_QWORD *)(v7 + 56);
        v41 = a3;
        v42 = 320;
LABEL_131:
        memmove(v41, v40, v42);
        goto LABEL_132;
      }
      goto LABEL_208;
    }
    if ( (*(_BYTE *)(a1 + 194) & 1) == 0 )
    {
      v23 = &unk_1260A;
      v51 = "qcedev_ioctl";
      goto LABEL_200;
    }
    v4 = _ReadStatusReg(SP_EL0);
    if ( (*(_QWORD *)v4 & 0x400000) != 0 )
    {
      memmove((void *)(v7 + 56), a3, 0x140u);
    }
    else if ( (unsigned int)inline_copy_from_user((int)v7 + 56, (int)a3, 0x140u) )
    {
      goto LABEL_128;
    }
    mutex_lock(&hash_access_lock);
    if ( (unsigned int)qcedev_check_sha_params(v7 + 56, v8) )
      goto LABEL_105;
    *(_DWORD *)(v7 + 48) = 1;
    v27 = qcedev_hash_final(v7, a1);
    if ( v27 )
      goto LABEL_117;
    v36 = *(unsigned int *)(a1 + 56);
    if ( (unsigned int)v36 >= 0x21 )
      break;
    *(_DWORD *)(v7 + 352) = v36;
    v10 = *(unsigned int *)(a1 + 56);
    if ( (unsigned int)v10 < 0x279 )
    {
      if ( (unsigned int)v10 < 0x21 || (v16 = (unsigned __int64)&unk_13000, (qcedev_ioctl___already_done_35 & 1) != 0) )
      {
LABEL_112:
        memcpy((void *)(v7 + 320), (const void *)(a1 + 24), v10);
        mutex_unlock(&hash_access_lock);
        if ( (*(_QWORD *)v4 & 0x400000) != 0 )
        {
          memmove(a3, (const void *)(v7 + 56), 0x140u);
        }
        else if ( (unsigned int)inline_copy_to_user(a3, v7 + 56, 320) )
        {
          goto LABEL_128;
        }
        v12 = 0;
        *(_BYTE *)(a1 + 194) = 0;
        goto LABEL_24;
      }
LABEL_207:
      *(_BYTE *)(v16 + 682) = 1;
      v54 = v10;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v10,
        "field \"&qcedev_areq->sha_op_req.digest[0]\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcedev.c:2548",
        0x20u);
      v10 = v54;
      __break(0x800u);
      goto LABEL_112;
    }
LABEL_208:
    _fortify_panic(17, 632);
    v55 = _ReadStatusReg(SP_EL0);
    v56 = *(_QWORD *)(v55 + 80);
    *(_QWORD *)(v55 + 80) = &qcedev_ioctl__alloc_tag;
    v7 = _kmalloc_cache_noprof(_arch_copy_to_user, 3520, 952);
    *(_QWORD *)(v55 + 80) = v56;
    if ( !v7 )
      goto LABEL_209;
  }
  printk(&unk_11DAC, v36, v34, v35);
LABEL_105:
  mutex_unlock(&hash_access_lock);
LABEL_201:
  v12 = -22;
LABEL_24:
  kfree(v7);
  result = v12;
LABEL_210:
  _ReadStatusReg(SP_EL0);
  return result;
}
