__int64 __fastcall fastrpc_multidomain_ctx_manage(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  int v4; // w5
  __int64 v5; // x22
  __int64 v6; // x27
  __int64 v7; // x19
  unsigned __int64 v8; // x28
  __int64 v9; // x0
  __int64 v10; // x26
  unsigned __int64 v11; // x20
  int v12; // w2
  __int64 v13; // x0
  __int64 v14; // x23
  unsigned __int64 v15; // x20
  int v16; // w2
  __int64 v17; // x24
  __int64 v18; // x0
  __int64 v19; // x25
  __int64 v20; // x23
  unsigned int v21; // w22
  __int64 i; // x8
  int *v23; // x9
  __int64 v24; // x27
  __int64 v25; // x19
  __int64 v26; // x8
  __int64 *v27; // x26
  int v28; // w8
  __int64 v29; // x0
  unsigned int v30; // w27
  __int64 v31; // x25
  int v32; // w8
  __int64 v33; // x28
  unsigned int v34; // w23
  unsigned int v35; // w22
  __int64 v36; // x8
  __int64 *v37; // x9
  __int64 v38; // x8
  int *v39; // x9
  unsigned int frpc_tgid; // w0
  unsigned int v41; // w0
  __int64 v42; // x20
  unsigned int v43; // w4
  int v44; // w1
  unsigned __int64 StatusReg; // x9
  __int64 v46; // x8
  unsigned __int64 v47; // x10
  unsigned __int64 v48; // x10
  unsigned __int64 v54; // x9
  int v55; // w2
  unsigned __int64 v56; // x8
  unsigned __int64 v58; // x9
  __int64 v59; // x8
  __int64 v60; // x2
  __int64 *v61; // x1
  unsigned int v62; // w20
  int v63; // w5
  __int64 result; // x0
  __int64 v65; // x4
  int v66; // w4
  const char *v67; // x1
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x21
  __int64 v71; // x4
  __int64 v72; // x5
  const char *v73; // x1
  const char *v74; // x1
  __int64 v75; // x0
  __int64 v76; // x4
  __int64 v77; // x5
  __int64 v78; // x6
  const char *v79; // x1
  __int64 v80; // [xsp+8h] [xbp-38h]
  __int64 v81; // [xsp+10h] [xbp-30h]
  __int64 v83; // [xsp+20h] [xbp-20h]
  _QWORD v84[2]; // [xsp+30h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)a2 == 1 )
  {
    v63 = *(_DWORD *)(a2 + 48);
    if ( v63 )
    {
      v66 = 0;
    }
    else
    {
      v63 = *(_DWORD *)(a2 + 52);
      if ( v63 )
      {
        v66 = 1;
      }
      else
      {
        v63 = *(_DWORD *)(a2 + 56);
        if ( v63 )
        {
          v66 = 2;
        }
        else
        {
          v63 = *(_DWORD *)(a2 + 60);
          if ( v63 )
          {
            v66 = 3;
          }
          else
          {
            v63 = *(_DWORD *)(a2 + 64);
            if ( v63 )
            {
              v66 = 4;
            }
            else
            {
              v63 = *(_DWORD *)(a2 + 68);
              if ( v63 )
              {
                v66 = 5;
              }
              else
              {
                v63 = *(_DWORD *)(a2 + 72);
                if ( v63 )
                {
                  v66 = 6;
                }
                else
                {
                  v63 = *(_DWORD *)(a2 + 76);
                  if ( !v63 )
                  {
                    result = fastrpc_multidomain_ctx_cleanup(a1, 1u, *(_QWORD *)(a2 + 40));
                    goto LABEL_116;
                  }
                  v66 = 7;
                }
              }
            }
          }
        }
      }
    }
    dev_err(
      *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL),
      "Error %d: %s: rsvd[%d] %u expected to be 0",
      -22,
      "fastrpc_multidomain_ctx_remove",
      v66,
      v63);
    result = 4294967274LL;
    goto LABEL_116;
  }
  if ( !*(_DWORD *)a2 )
  {
    v3 = *(_QWORD *)(a1 + 128);
    v4 = *(_DWORD *)(a2 + 48);
    v84[0] = 0;
    v5 = *(_QWORD *)(v3 + 168);
    if ( v4 )
    {
      v65 = 0;
    }
    else if ( *(_DWORD *)(a2 + 52) )
    {
      v65 = 1;
    }
    else if ( *(_DWORD *)(a2 + 56) )
    {
      v65 = 2;
    }
    else if ( *(_DWORD *)(a2 + 60) )
    {
      v65 = 3;
    }
    else if ( *(_DWORD *)(a2 + 64) )
    {
      v65 = 4;
    }
    else if ( *(_DWORD *)(a2 + 68) )
    {
      v65 = 5;
    }
    else if ( *(_DWORD *)(a2 + 72) )
    {
      v65 = 6;
    }
    else
    {
      if ( !*(_DWORD *)(a2 + 76) )
      {
        v6 = *(unsigned int *)(a2 + 32);
        if ( (unsigned int)v6 < 0xC )
        {
          v7 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
          if ( v7 )
          {
            v8 = 4 * v6;
            v9 = _kmalloc_noprof(4 * v6, 3520);
            v10 = v9;
            if ( !v9 )
            {
              v62 = -12;
              dev_err(
                v5,
                "Error %d: %s: failed to alloc domains array of size %zu",
                -12,
                "fastrpc_multidomain_ctx_obj_init",
                4 * v6);
              v69 = 0;
              v17 = 0;
              v70 = 0;
              v14 = 0;
              goto LABEL_97;
            }
            v11 = *(_QWORD *)(a2 + 16);
            _check_object_size(v9, 4 * v6, 0);
            v12 = inline_copy_from_user(v10, v11, 4 * v6);
            if ( v12 )
            {
              dev_err(
                v5,
                "Error %d: %s: failed to copy domain ids from user (size %zu)",
                v12,
                "fastrpc_multidomain_ctx_obj_init",
                4 * v6);
              v69 = 0;
              v17 = 0;
              v70 = 0;
              v14 = 0;
            }
            else
            {
              v13 = _kmalloc_noprof(4 * v6, 3520);
              v14 = v13;
              if ( !v13 )
              {
                v62 = -12;
                dev_err(
                  v5,
                  "Error %d: %s: failed to alloc sessions array of size %zu",
                  -12,
                  "fastrpc_multidomain_ctx_obj_init",
                  4 * v6);
                v69 = 0;
                v17 = 0;
                v70 = 0;
                goto LABEL_97;
              }
              v15 = *(_QWORD *)(a2 + 24);
              _check_object_size(v13, 4 * v6, 0);
              v16 = inline_copy_from_user(v14, v15, 4 * v6);
              if ( !v16 )
              {
                v17 = _kmalloc_noprof(4 * v6, 3520);
                if ( v17 )
                {
                  v18 = _kmalloc_noprof(4 * v6, 3520);
                  if ( v18 )
                  {
                    v19 = v6;
                    v83 = v18;
                    v80 = v5;
                    v81 = v14;
                    if ( (_DWORD)v6 )
                    {
                      v20 = 0;
                      while ( 1 )
                      {
                        if ( v20 == v8 >> 2 || v8 <= 4 * v20 )
                          goto LABEL_128;
                        v21 = *(_DWORD *)(v10 + 4 * v20);
                        if ( v21 <= 4 )
                          break;
LABEL_30:
                        v24 = v7;
                        v25 = v10;
                        mutex_lock(&unk_26CD8);
                        v26 = 0;
                        while ( 1 )
                        {
                          v27 = *(__int64 **)&g_frpc[2 * v26 + 26];
                          if ( v27 )
                            break;
LABEL_31:
                          if ( ++v26 == 256 )
                          {
                            mutex_unlock(&unk_26CD8);
                            v62 = -22;
                            printk(&unk_252ED, 4294967274LL, "fastrpc_multidomain_ctx_obj_init", v21, v71, v72);
                            v69 = 0;
                            v10 = v25;
                            v7 = v24;
                            goto LABEL_124;
                          }
                        }
                        while ( *((_DWORD *)v27 + 4) != v21 )
                        {
                          v27 = (__int64 *)*v27;
                          if ( !v27 )
                            goto LABEL_31;
                        }
                        mutex_unlock(&unk_26CD8);
                        if ( v8 <= 4 * v20 )
                          goto LABEL_128;
                        *(_DWORD *)(v17 + 4 * v20) = *((_DWORD *)v27 + 13);
                        v28 = *((_DWORD *)v27 + 14);
                        v10 = v25;
                        v7 = v24;
                        *(_DWORD *)(v83 + 4 * v20++) = v28;
                        if ( v20 == v19 )
                          goto LABEL_38;
                      }
                      mutex_lock(&unk_26CD8);
                      for ( i = 0; i != 256; ++i )
                      {
                        v23 = &g_frpc[2 * i + 26];
                        while ( 1 )
                        {
                          v23 = *(int **)v23;
                          if ( !v23 )
                            break;
                          if ( v23[18] == v21 )
                          {
                            v21 = v23[4];
                            mutex_unlock(&unk_26CD8);
                            goto LABEL_30;
                          }
                        }
                      }
                      mutex_unlock(&unk_26CD8);
                      if ( v8 <= 4 * v20 )
LABEL_128:
                        __break(1u);
                      v62 = -22;
                      dev_err(
                        v80,
                        "Error %d: %s: failed to get logical id for legacy domain %u",
                        -22,
                        "fastrpc_multidomain_ctx_obj_init",
                        *(_DWORD *)(v10 + 4 * v20));
                      goto LABEL_123;
                    }
LABEL_38:
                    v29 = _kmalloc_noprof(v8, 3520);
                    v30 = v19;
                    if ( !v29 )
                    {
                      v62 = -12;
                      dev_err(
                        v80,
                        "Error %d: %s: failed to alloc tgids array of size %zu",
                        -12,
                        "fastrpc_multidomain_ctx_obj_init",
                        v8);
LABEL_123:
                      v69 = 0;
LABEL_124:
                      v14 = v81;
                      v70 = v83;
                      goto LABEL_97;
                    }
                    *(_DWORD *)(v7 + 56) = v19;
                    *(_QWORD *)(v7 + 16) = v10;
                    *(_QWORD *)(v7 + 24) = v83;
                    *(_QWORD *)(v7 + 40) = v81;
                    *(_QWORD *)(v7 + 48) = v29;
                    *(_QWORD *)(v7 + 32) = v17;
                    *(_QWORD *)v7 = v7;
                    *(_QWORD *)(v7 + 8) = v7;
                    if ( (_DWORD)v19 )
                    {
                      v31 = v29;
                      v32 = 0;
                      while ( 2 )
                      {
                        v33 = v32;
                        v34 = *(_DWORD *)(*(_QWORD *)(v7 + 16) + 4LL * v32);
                        v35 = *(_DWORD *)(*(_QWORD *)(v7 + 40) + 4LL * v32);
                        mutex_lock(&unk_26CD8);
                        v36 = 0;
                        while ( 1 )
                        {
                          v37 = *(__int64 **)&g_frpc[2 * v36 + 26];
                          if ( v37 )
                            break;
LABEL_42:
                          if ( ++v36 == 256 )
                          {
                            mutex_unlock(&unk_26CD8);
                            if ( v34 > 4 )
                            {
                              v74 = "Error %d: %s: [%u of %u]: %u is not a valid logical domain id";
                            }
                            else
                            {
                              mutex_lock(&unk_26CD8);
                              v38 = 0;
                              while ( 2 )
                              {
                                v39 = &g_frpc[2 * v38 + 26];
                                while ( 1 )
                                {
                                  v39 = *(int **)v39;
                                  if ( !v39 )
                                    break;
                                  if ( v39[18] == v34 )
                                  {
                                    v34 = v39[4];
                                    goto LABEL_54;
                                  }
                                }
                                if ( ++v38 != 256 )
                                  continue;
                                break;
                              }
                              mutex_unlock(&unk_26CD8);
                              v74 = "Error %d: %s: [%u of %u]: no domain found for legacy domain id %u";
                            }
                            v75 = v80;
                            v76 = (unsigned int)v33;
                            v77 = v30;
                            v78 = v34;
LABEL_118:
                            v62 = -22;
                            dev_err(v75, v74, 4294967274LL, "fastrpc_multidomain_ctx_get_tgids", v76, v77, v78);
LABEL_120:
                            v14 = v81;
                            v69 = v31;
                            v70 = v83;
                            goto LABEL_97;
                          }
                        }
                        while ( *((_DWORD *)v37 + 4) != v34 )
                        {
                          v37 = (__int64 *)*v37;
                          if ( !v37 )
                            goto LABEL_42;
                        }
LABEL_54:
                        mutex_unlock(&unk_26CD8);
                        if ( v35 >= 4 )
                        {
                          v74 = "Error %d: %s: [%u of %u]: session %u is invalid";
                          v75 = v80;
                          v76 = (unsigned int)v33;
                          v77 = v30;
                          v78 = v35;
                          goto LABEL_118;
                        }
                        frpc_tgid = fastrpc_get_frpc_tgid(v34, v35, *(_QWORD *)(v7 + 48) + 4 * v33);
                        if ( frpc_tgid )
                        {
                          v62 = frpc_tgid;
                          dev_err(
                            v80,
                            "Error %d: %s: [%d of %d]: unable to get frpc tgid for domain %u, session %u",
                            frpc_tgid,
                            "fastrpc_multidomain_ctx_get_tgids",
                            v33,
                            v30,
                            v34,
                            v35);
                          goto LABEL_120;
                        }
                        v32 = v33 + 1;
                        if ( (_DWORD)v33 + 1 != v30 )
                          continue;
                        break;
                      }
                    }
                    mutex_lock(&unk_26CA8);
                    v41 = idr_alloc_cyclic(&qword_27518, v7, 1, 1024, 2080);
                    if ( (v41 & 0x80000000) != 0 )
                    {
                      v73 = "Error %d: %s: idr alloc failed";
                    }
                    else
                    {
                      v42 = v41;
                      v43 = *(_DWORD *)(v7 + 56);
                      v44 = *(_DWORD *)a2;
                      v84[0] = v41;
                      v41 = fastrpc_multidomain_ctx_dsp_manage(a1, v44, v41, (_QWORD *)v7, v43);
                      if ( !v41 )
                      {
                        StatusReg = _ReadStatusReg(SP_EL0);
                        v46 = *(_QWORD *)(a2 + 40);
                        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0
                          || (v47 = *(_QWORD *)(a2 + 40), (*(_QWORD *)StatusReg & 0x4000000) != 0) )
                        {
                          v47 = v46 & (v46 << 8 >> 8);
                        }
                        if ( v47 > 0x7FFFFFFFF8LL )
                        {
                          v55 = 8;
                        }
                        else
                        {
                          v48 = _ReadStatusReg(DAIF);
                          __asm { MSR             DAIFSet, #3 }
                          v54 = *(_QWORD *)(StatusReg + 8);
                          _WriteStatusReg(
                            TTBR1_EL1,
                            v54 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                          _WriteStatusReg(TTBR0_EL1, v54);
                          __isb(0xFu);
                          _WriteStatusReg(DAIF, v48);
                          v55 = _arch_copy_to_user(v46 & 0xFF7FFFFFFFFFFFFFLL, v84, 8);
                          v56 = _ReadStatusReg(DAIF);
                          __asm { MSR             DAIFSet, #3 }
                          v58 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                          _WriteStatusReg(TTBR0_EL1, v58 - 4096);
                          _WriteStatusReg(TTBR1_EL1, v58);
                          __isb(0xFu);
                          _WriteStatusReg(DAIF, v56);
                          v42 = v84[0];
                          if ( !v55 )
                          {
                            *(_QWORD *)(v7 + 64) = a1;
                            *(_QWORD *)(v7 + 72) = v42;
                            raw_spin_lock(a1 + 320);
                            v59 = a1;
                            v60 = a1 + 112;
                            v61 = *(__int64 **)(a1 + 120);
                            if ( v7 == a1 + 112 || (__int64 *)v7 == v61 || *v61 != v60 )
                            {
                              _list_add_valid_or_report(v7, v61, v60);
                              v59 = a1;
                            }
                            else
                            {
                              *(_QWORD *)(a1 + 120) = v7;
                              *(_QWORD *)v7 = v60;
                              *(_QWORD *)(v7 + 8) = v61;
                              *v61 = v7;
                            }
                            raw_spin_unlock(v59 + 320);
                            v62 = 0;
LABEL_114:
                            mutex_unlock(&unk_26CA8);
                            goto LABEL_115;
                          }
                        }
                        dev_err(
                          v80,
                          "Error %d: %s: failed to copy ctx 0x%llx to user",
                          v55,
                          "fastrpc_multidomain_ctx_setup",
                          v42);
                        v62 = -14;
LABEL_111:
                        if ( v84[0] )
                          idr_remove(&qword_27518, v84[0]);
                        kfree(*(_QWORD *)(v7 + 48));
                        kfree(*(_QWORD *)(v7 + 40));
                        kfree(*(_QWORD *)(v7 + 16));
                        kfree(v7);
                        goto LABEL_114;
                      }
                      v73 = "Error 0x%x: %s: peer-info register failed";
                    }
                    v62 = v41;
                    dev_err(v80, v73);
                    goto LABEL_111;
                  }
                  v79 = "Error %d: %s: failed to alloc phy_ids array of size %zu";
                }
                else
                {
                  v79 = "Error %d: %s: failed to alloc instance_ids array of size %zu";
                }
                v62 = -12;
                dev_err(v5, v79, 4294967284LL, "fastrpc_multidomain_ctx_obj_init", 4 * v6);
                v69 = 0;
                v70 = 0;
LABEL_97:
                kfree(v69);
                kfree(v14);
                kfree(v10);
                kfree(v7);
                kfree(v70);
                kfree(v17);
LABEL_115:
                result = v62;
                goto LABEL_116;
              }
              dev_err(
                v5,
                "Error %d: %s: failed to copy session ids from user (size %zu)",
                v16,
                "fastrpc_multidomain_ctx_obj_init",
                4 * v6);
              v69 = 0;
              v17 = 0;
              v70 = 0;
            }
            v62 = -14;
            goto LABEL_97;
          }
          v62 = -12;
          dev_err(v5, "Error %d: %s: failed to alloc mdctx obj", -12, "fastrpc_multidomain_ctx_obj_init");
LABEL_96:
          v69 = 0;
          v17 = 0;
          v70 = 0;
          v14 = 0;
          v10 = 0;
          goto LABEL_97;
        }
        v67 = "Error %d: %s: num domains %u more than max domains %u";
        v68 = *(_QWORD *)(v3 + 168);
        v65 = (unsigned int)v6;
LABEL_95:
        v62 = -22;
        dev_err(v68, v67, 4294967274LL, "fastrpc_multidomain_ctx_obj_init", v65);
        v7 = 0;
        goto LABEL_96;
      }
      v65 = 7;
    }
    v67 = "Error %d: %s: rsvd[%d] %u expected to be 0";
    v68 = *(_QWORD *)(v3 + 168);
    goto LABEL_95;
  }
  result = 4294967240LL;
LABEL_116:
  _ReadStatusReg(SP_EL0);
  return result;
}
