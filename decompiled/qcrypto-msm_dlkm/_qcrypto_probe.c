__int64 __fastcall qcrypto_probe(__int64 a1)
{
  unsigned __int64 v1; // x22
  unsigned __int64 v2; // x25
  _QWORD *v4; // x20
  unsigned __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x9
  __int64 *v9; // x10
  _QWORD *v10; // x1
  int v11; // w9
  __int64 v12; // x21
  unsigned int v13; // w8
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x10
  unsigned int v18; // w11
  int v19; // w8
  int v20; // w9
  int v21; // w10
  int v22; // w11
  int *v23; // x11
  __int64 v24; // x28
  __int64 v25; // x0
  size_t v26; // x0
  unsigned __int64 *v27; // x1
  unsigned __int64 v28; // x0
  size_t v29; // x0
  unsigned int v30; // w8
  unsigned __int64 v31; // x22
  __int64 v32; // x0
  size_t v33; // x0
  __int64 v34; // x0
  size_t v35; // x0
  __int64 v36; // x27
  __int64 v37; // x0
  size_t v38; // x0
  unsigned __int64 v39; // x0
  size_t v40; // x0
  unsigned __int64 v41; // x0
  size_t v42; // x0
  unsigned __int64 v43; // x0
  size_t v44; // x0
  unsigned __int64 v45; // x0
  size_t v46; // x0
  __int64 result; // x0
  unsigned __int64 v48; // x0
  size_t v49; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v51; // x24
  size_t v52; // x2
  __int64 v53; // x8
  unsigned int v54; // w9
  unsigned __int64 v55; // x0
  size_t v56; // x0
  unsigned int v57; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v58; // [xsp+18h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  v4 = (_QWORD *)_kmalloc_cache_noprof(crypto_register_skcipher, 3520, 264);
  if ( !v4 )
  {
    result = 4294967284LL;
    goto LABEL_149;
  }
  v5 = of_icc_get(a1 + 16, "data_path");
  v4[5] = v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1 + 16, "failed to get icc path\n");
    v57 = v4[5];
  }
  else
  {
    *((_DWORD *)v4 + 28) = 0;
    v57 = ((__int64 (*)(void))icc_set_bw)();
    if ( v57 )
    {
      dev_err(a1 + 16, "failed to set high bandwidth\n");
    }
    else
    {
      v6 = qce_open(a1, &v57);
      if ( v6 )
      {
        v7 = v6;
        v57 = icc_set_bw(v4[5], 0, 0);
        if ( v57 )
        {
          dev_err(a1 + 16, "failed to set low bandwidth\n");
        }
        else
        {
          *(_QWORD *)(a1 + 168) = v4;
          v4[3] = a1;
          v4[4] = &qcrypto_dev;
          v4[2] = v7;
          *((_DWORD *)v4 + 27) = -559038737;
          init_timer_key(v4 + 15, qcrypto_bw_reaper_timer_callback, 0, 0, 0);
          v4[20] = 0xFFFFFFFE00000LL;
          v4[21] = v4 + 21;
          v4[22] = v4 + 21;
          v4[23] = qcrypto_bw_reaper_work;
          v4[24] = 0xFFFFFFFE00000LL;
          v4[25] = v4 + 25;
          v4[26] = v4 + 25;
          *((_BYTE *)v4 + 116) = 0;
          *((_DWORD *)v4 + 65) = 0;
          *((_BYTE *)v4 + 252) = 0;
          v4[27] = qcrypto_bw_allocate_work;
          v4[28] = 0;
          *((_BYTE *)v4 + 232) = 0;
          crypto_init_queue(v4 + 6, 768);
          mutex_lock(&unk_10888);
          *((_DWORD *)v4 + 24) = ++dword_10880;
          v8 = raw_spin_lock_irqsave(&dword_10834);
          v9 = (__int64 *)qword_10870;
          *((_BYTE *)v4 + 253) = qword_10870 == (_QWORD)&qword_10870;
          if ( v9 == &qword_10870 )
            qword_10928 = (__int64)v4;
          v10 = (_QWORD *)qword_10878;
          if ( (_QWORD *)qword_10878 == v4 || *(__int64 **)qword_10878 != &qword_10870 )
          {
            _list_add_valid_or_report(v4);
          }
          else
          {
            qword_10878 = (__int64)v4;
            *v4 = &qword_10870;
            v4[1] = v10;
            *v10 = v4;
          }
          qword_108B8 = (__int64)v4;
          raw_spin_unlock_irqrestore(&dword_10834, v8);
          qce_hw_support(v4[2], &byte_10810);
          v11 = dword_10830;
          *((_DWORD *)v4 + 26) = dword_1082C;
          *((_DWORD *)v4 + 59) = v11;
          v1 = 40LL * *((unsigned int *)v4 + 59);
          v12 = _kmalloc_noprof(v1, 3520);
          while ( v12 )
          {
            v4[30] = v12;
            *((_DWORD *)v4 + 62) = 0;
            if ( *((_DWORD *)v4 + 59) )
            {
              v13 = 0;
              v14 = 0;
              while ( v1 > v14 )
              {
                v15 = v14 + 4;
                v16 = v12 + v14;
                *(_DWORD *)v16 = v13;
                if ( v1 < v15 )
                  break;
                v17 = v15 + 4;
                *(_BYTE *)(v16 + 4) = 0;
                if ( v1 <= v17 )
                  break;
                v18 = *((_DWORD *)v4 + 59);
                ++v13;
                *(_QWORD *)(v16 + 8) = v4;
                v14 = v17 + 32;
                if ( v13 >= v18 )
                  goto LABEL_18;
              }
              __break(1u);
LABEL_75:
              dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v1 + 768));
              kfree_sensitive(v1);
            }
            else
            {
LABEL_18:
              if ( byte_1081A == 1 )
              {
                v19 = 0;
                v20 = (unsigned __int8)byte_1081B;
                v21 = (unsigned __int8)byte_1081C;
                *((_DWORD *)v4 + 25) = dword_10828;
                v22 = 1;
              }
              else
              {
                v23 = *(int **)(a1 + 160);
                v20 = *v23;
                v19 = v23[1];
                v21 = v23[2];
                v22 = v23[3];
              }
              qcrypto_dev = v20;
              dword_10804 = v19;
              dword_10808 = v21;
              dword_1080C = v22;
              if ( dword_10880 != 1 )
                goto LABEL_143;
              v24 = 0;
              v1 = (unsigned __int64)&qword_10838;
              _ReadStatusReg(SP_EL0);
              do
              {
                v25 = _kmalloc_cache_noprof(dev_err, 3520, 1432);
                v2 = v25;
                if ( !v25 )
                  goto LABEL_91;
                *(_DWORD *)(v25 + 1416) = 0;
                memcpy((void *)(v25 + 16), (char *)&qcrypto_sk_cipher_algos + v24, 0x1D8u);
                *(_QWORD *)(v2 + 1424) = &qcrypto_dev;
                if ( v2 >= 0xFFFFFFFFFFFFF001LL )
                  goto LABEL_92;
                if ( byte_1081D == 1 )
                {
                  v26 = strnlen((const char *)(v2 + 160), 0x80u);
                  if ( v26 >= 0x81 )
                    goto LABEL_166;
                  if ( v26 == 128 )
                    goto LABEL_167;
                  v57 = qcrypto_prefix_alg_cra_name(v2 + 160, v26);
                  if ( v57 )
                  {
                    dev_err(a1 + 16, "The algorithm name %s is too long.\n", v2 + 160);
                    goto LABEL_46;
                  }
                }
                v57 = crypto_register_skcipher(v2 + 16);
                if ( v57 )
                {
                  dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v2 + 288));
                  kfree_sensitive(v2);
                }
                else
                {
                  v27 = (unsigned __int64 *)qword_10840;
                  if ( qword_10840 == v2 || *(__int64 **)qword_10840 != &qword_10838 )
                  {
                    _list_add_valid_or_report(v2);
                  }
                  else
                  {
                    qword_10840 = v2;
                    *(_QWORD *)v2 = &qword_10838;
                    *(_QWORD *)(v2 + 8) = v27;
                    *v27 = v2;
                  }
                  dev_info(a1 + 16, &unk_11D41, v2 + 288);
                }
                v24 += 472;
              }
              while ( v24 != 3304 );
              if ( byte_10816 == 1 )
              {
                v28 = qcrypto_cipher_alg_alloc(&qcrypto_sk_cipher_xts_algo);
                if ( v28 >= 0xFFFFFFFFFFFFF001LL )
                {
                  v57 = v28;
                  goto LABEL_93;
                }
                if ( byte_1081F == 1 )
                {
                  v1 = v28;
                  v29 = strnlen((const char *)(v28 + 160), 0x80u);
                  if ( v29 >= 0x81 )
                    goto LABEL_166;
                  if ( v29 == 128 )
                    goto LABEL_167;
                  v30 = qcrypto_prefix_alg_cra_name(v1 + 160, v29);
                  v28 = v1;
                  v57 = v30;
                  if ( v30 )
                  {
                    dev_err(a1 + 16, "The algorithm name %s is too long.\n", v1 + 160);
                    goto LABEL_73;
                  }
                }
                v31 = v28;
                v57 = crypto_register_skcipher(v28 + 16);
                if ( v57 )
                {
                  dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v31 + 288));
                  kfree_sensitive(v31);
                }
                else
                {
                  list_add_tail((_QWORD *)v31, &qword_10838);
                  dev_info(a1 + 16, &unk_11D41, v31 + 288);
                }
              }
              v32 = _kmalloc_cache_noprof(dev_err, 3520, 1432);
              v1 = v32;
              if ( !v32 )
                goto LABEL_169;
              *(_DWORD *)(v32 + 1416) = 1;
              memcpy((void *)(v32 + 488), qcrypto_ahash_algos, 0x1E0u);
              *(_QWORD *)(v1 + 1424) = &qcrypto_dev;
              if ( v1 >= 0xFFFFFFFFFFFFF001LL )
                goto LABEL_170;
              if ( byte_10820 == 1 )
              {
                v33 = strnlen((const char *)(v1 + 640), 0x80u);
                if ( v33 >= 0x81 )
                  goto LABEL_166;
                if ( v33 == 128 )
                  goto LABEL_141;
                v57 = qcrypto_prefix_alg_cra_name(v1 + 640, v33);
                if ( v57 )
                  goto LABEL_72;
              }
              v57 = crypto_register_ahash(v1 + 488);
              if ( v57 )
              {
                dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v1 + 768));
                kfree_sensitive(v1);
              }
              else
              {
                list_add_tail((_QWORD *)v1, &qword_10838);
                dev_info(a1 + 16, &unk_11D41, v1 + 768);
              }
              v34 = _kmalloc_cache_noprof(dev_err, 3520, 1432);
              v1 = v34;
              if ( !v34 )
              {
LABEL_169:
                v1 = -12;
                goto LABEL_170;
              }
              *(_DWORD *)(v34 + 1416) = 1;
              memcpy((void *)(v34 + 488), off_13030, 0x1E0u);
              *(_QWORD *)(v1 + 1424) = &qcrypto_dev;
              if ( v1 > 0xFFFFFFFFFFFFF000LL )
                goto LABEL_170;
              if ( byte_10820 == 1 )
              {
                v35 = strnlen((const char *)(v1 + 640), 0x80u);
                if ( v35 > 0x80 )
                  goto LABEL_166;
                if ( v35 == 128 )
                  goto LABEL_141;
                v57 = qcrypto_prefix_alg_cra_name(v1 + 640, v35);
                if ( v57 )
                {
LABEL_72:
                  dev_err(a1 + 16, "The algorithm name %s is too long.\n", v1 + 640);
                  goto LABEL_73;
                }
              }
              v57 = crypto_register_ahash(v1 + 488);
              if ( v57 )
                goto LABEL_75;
              list_add_tail((_QWORD *)v1, &qword_10838);
              dev_info(a1 + 16, &unk_11D41, v1 + 768);
            }
            if ( (byte_10810 & 1) != 0 || (byte_10811 & 1) != 0 || byte_10813 == 1 )
            {
              v36 = 0;
              v1 = 2;
              _ReadStatusReg(SP_EL0);
              while ( 1 )
              {
                v37 = _kmalloc_cache_noprof(dev_err, 3520, 1432);
                v2 = v37;
                if ( !v37 )
                  break;
                *(_DWORD *)(v37 + 1416) = 2;
                memcpy((void *)(v37 + 968), &qcrypto_aead_sha1_hmac_algos[v36], 0x1C0u);
                *(_QWORD *)(v2 + 1424) = &qcrypto_dev;
                if ( v2 >= 0xFFFFFFFFFFFFF001LL )
                  goto LABEL_92;
                if ( byte_1081E == 1 )
                {
                  v38 = strnlen((const char *)(v2 + 1088), 0x80u);
                  if ( v38 >= 0x81 )
                    goto LABEL_166;
                  if ( v38 == 128 )
                    goto LABEL_167;
                  v57 = qcrypto_prefix_alg_cra_name(v2 + 1088, v38);
                  if ( v57 )
                  {
                    dev_err(a1 + 16, "The algorithm name %s is too long.\n", v2 + 1088);
                    goto LABEL_46;
                  }
                }
                v57 = crypto_register_aead(v2 + 968);
                if ( v57 )
                {
                  dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v2 + 1216));
                  kfree(v2);
                }
                else
                {
                  list_add_tail((_QWORD *)v2, &qword_10838);
                  dev_info(a1 + 16, &unk_11D41, v2 + 1216);
                }
                v36 += 56;
                if ( v36 == 168 )
                {
                  if ( (byte_10813 & 1) == 0 )
                    goto LABEL_105;
                  goto LABEL_97;
                }
              }
LABEL_91:
              LODWORD(v2) = -12;
              goto LABEL_92;
            }
            if ( !byte_10813 )
              goto LABEL_105;
LABEL_97:
            v39 = qcrypto_aead_alg_alloc(qcrypto_aead_sha256_hmac_algos);
            v1 = v39;
            if ( v39 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_170;
            if ( byte_1081E == 1 )
            {
              v40 = strnlen((const char *)(v39 + 1088), 0x80u);
              if ( v40 >= 0x81 )
                goto LABEL_166;
              if ( v40 == 128 )
                goto LABEL_141;
              v57 = qcrypto_prefix_alg_cra_name(v1 + 1088, v40);
              if ( v57 )
                goto LABEL_140;
            }
            v57 = crypto_register_aead(v1 + 968);
            if ( v57 )
            {
              dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v1 + 1216));
              kfree(v1);
            }
            else
            {
              list_add_tail((_QWORD *)v1, &qword_10838);
              dev_info(a1 + 16, &unk_11D41, v1 + 1216);
            }
            v43 = qcrypto_aead_alg_alloc(off_C28);
            v1 = v43;
            if ( v43 > 0xFFFFFFFFFFFFF000LL )
              goto LABEL_170;
            if ( byte_1081E == 1 )
            {
              v44 = strnlen((const char *)(v43 + 1088), 0x80u);
              if ( v44 > 0x80 )
                goto LABEL_166;
              if ( v44 == 128 )
                goto LABEL_141;
              v57 = qcrypto_prefix_alg_cra_name(v1 + 1088, v44);
              if ( v57 )
                goto LABEL_140;
            }
            v57 = crypto_register_aead(v1 + 968);
            if ( v57 )
            {
              dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v1 + 1216));
              kfree(v1);
            }
            else
            {
              list_add_tail((_QWORD *)v1, &qword_10838);
              dev_info(a1 + 16, &unk_11D41, v1 + 1216);
            }
            v48 = qcrypto_aead_alg_alloc(off_DE8);
            v1 = v48;
            if ( v48 > 0xFFFFFFFFFFFFF000LL )
              goto LABEL_170;
            if ( byte_1081E != 1 )
              goto LABEL_138;
            v49 = strnlen((const char *)(v48 + 1088), 0x80u);
            if ( v49 > 0x80 )
              goto LABEL_166;
            if ( v49 != 128 )
            {
              v57 = qcrypto_prefix_alg_cra_name(v1 + 1088, v49);
              if ( v57 )
                goto LABEL_140;
LABEL_138:
              v57 = crypto_register_aead(v1 + 968);
              if ( v57 )
              {
                dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v1 + 1216));
                kfree(v1);
              }
              else
              {
                list_add_tail((_QWORD *)v1, &qword_10838);
                dev_info(a1 + 16, &unk_11D41, v1 + 1216);
              }
              if ( (byte_10813 & 1) != 0 )
                goto LABEL_155;
LABEL_105:
              if ( !dword_1080C )
              {
LABEL_106:
                if ( byte_10817 != 1 )
                  goto LABEL_152;
                v41 = qcrypto_aead_alg_alloc(&qcrypto_aead_ccm_algo);
                v1 = v41;
                if ( v41 < 0xFFFFFFFFFFFFF001LL )
                {
                  if ( byte_10822 != 1 )
                    goto LABEL_112;
                  v42 = strnlen((const char *)(v41 + 1088), 0x80u);
                  if ( v42 >= 0x81 )
                    goto LABEL_166;
                  if ( v42 == 128 )
                    goto LABEL_167;
                  v57 = qcrypto_prefix_alg_cra_name(v1 + 1088, v42);
                  if ( v57 )
                    goto LABEL_140;
LABEL_112:
                  v57 = crypto_register_aead(v1 + 968);
                  if ( v57 )
                  {
                    dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v1 + 1216));
                    kfree_sensitive(v1);
                  }
                  else
                  {
                    list_add_tail((_QWORD *)v1, &qword_10838);
                    dev_info(a1 + 16, &unk_11D41, v1 + 1216);
                  }
                  v45 = qcrypto_aead_alg_alloc(qcrypto_aead_rfc4309_ccm_algo);
                  v1 = v45;
                  if ( v45 < 0xFFFFFFFFFFFFF001LL )
                  {
                    if ( byte_10822 != 1 )
                      goto LABEL_128;
                    v46 = strnlen((const char *)(v45 + 1088), 0x80u);
                    if ( v46 < 0x81 )
                    {
                      if ( v46 != 128 )
                      {
                        v57 = qcrypto_prefix_alg_cra_name(v1 + 1088, v46);
                        if ( !v57 )
                        {
LABEL_128:
                          v57 = crypto_register_aead(v1 + 968);
                          if ( !v57 )
                          {
                            list_add_tail((_QWORD *)v1, &qword_10838);
                            dev_info(a1 + 16, &unk_11D41, v1 + 1216);
                            goto LABEL_152;
                          }
LABEL_151:
                          dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v1 + 1216));
                          kfree(v1);
LABEL_152:
                          mutex_unlock(&unk_10888);
                          result = 0;
                          goto LABEL_149;
                        }
LABEL_140:
                        dev_err(a1 + 16, "The algorithm name %s is too long.\n", v1 + 1088);
LABEL_73:
                        kfree(v1);
LABEL_93:
                        qcrypto_remove_engine(v4);
                        kfree_sensitive(v12);
                        goto LABEL_143;
                      }
LABEL_167:
                      _fortify_panic(4);
LABEL_168:
                      dev_err(a1 + 16, "The algorithm name %s is too long.\n", v2 + 640);
LABEL_46:
                      kfree(v2);
                      goto LABEL_93;
                    }
LABEL_166:
                    _fortify_panic(2);
                    goto LABEL_167;
                  }
                }
LABEL_170:
                v57 = v1;
                goto LABEL_93;
              }
LABEL_155:
              v53 = 0;
              v54 = 1;
              while ( 1 )
              {
                v1 = v54;
                v55 = qcrypto_sha_alg_alloc(&qcrypto_sha_hmac_algos[60 * v53]);
                v2 = v55;
                if ( v55 >= 0xFFFFFFFFFFFFF001LL )
                  break;
                if ( byte_10821 == 1 )
                {
                  v56 = strnlen((const char *)(v55 + 640), 0x80u);
                  if ( v56 >= 0x81 )
                    goto LABEL_166;
                  if ( v56 == 128 )
                    goto LABEL_167;
                  v57 = qcrypto_prefix_alg_cra_name(v2 + 640, v56);
                  if ( v57 )
                    goto LABEL_168;
                }
                v57 = crypto_register_ahash(v2 + 488);
                if ( v57 )
                {
                  dev_err(a1 + 16, "%s alg registration failed\n", (const char *)(v2 + 768));
                  kfree_sensitive(v2);
                }
                else
                {
                  list_add_tail((_QWORD *)v2, &qword_10838);
                  dev_info(a1 + 16, &unk_11D41, v2 + 768);
                }
                v54 = 0;
                v53 = 1;
                if ( (v1 & 1) == 0 )
                  goto LABEL_106;
              }
LABEL_92:
              v57 = v2;
              goto LABEL_93;
            }
LABEL_141:
            _fortify_panic(4);
            StatusReg = _ReadStatusReg(SP_EL0);
            v51 = *(_QWORD *)(StatusReg + 80);
            *(_QWORD *)(StatusReg + 80) = &qcrypto_probe__alloc_tag_78;
            v1 = 40LL * *((unsigned int *)v4 + 59);
            v12 = _kmalloc_noprof(v1, 3520);
            *(_QWORD *)(StatusReg + 80) = v51;
          }
          v57 = -12;
LABEL_143:
          mutex_unlock(&unk_10888);
        }
        if ( v4[2] )
          qce_close();
      }
      else
      {
        v57 = -19;
      }
      icc_set_bw(v4[5], 0, 0);
      *(_QWORD *)(a1 + 168) = 0;
    }
  }
  v52 = ksize(v4);
  if ( v52 >= 0x109 )
  {
    _fortify_panic(15);
    goto LABEL_151;
  }
  memset(v4, 0, v52);
  kfree(v4);
  result = v57;
LABEL_149:
  _ReadStatusReg(SP_EL0);
  return result;
}
