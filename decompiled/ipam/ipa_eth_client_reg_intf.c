__int64 __fastcall ipa_eth_client_reg_intf(const char **a1)
{
  char *v1; // x23
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x19
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned __int64 v9; // x24
  const char *v10; // x20
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x0
  __int64 v14; // x20
  const char *v15; // x22
  const char *v16; // x3
  size_t v17; // x2
  const char *v18; // x1
  int v19; // w8
  __int16 v20; // w9
  size_t v21; // x2
  const char *v22; // x1
  int v23; // w8
  __int16 v24; // w9
  int v25; // w9
  __int64 v26; // x0
  __int64 v27; // x0
  int v28; // w8
  unsigned __int64 v29; // x24
  unsigned __int64 v30; // x23
  __int64 v31; // x26
  __int64 v32; // x22
  __int64 v33; // x22
  int v34; // w19
  int ipa_client_type_from_pipe; // w0
  unsigned __int64 v36; // x23
  char *v37; // x0
  char *v38; // x22
  unsigned __int64 v39; // x24
  unsigned __int64 v40; // x26
  char *v41; // x19
  size_t v42; // x0
  char *v43; // x19
  char *v44; // x0
  size_t v45; // x2
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x9
  unsigned __int64 i; // x10
  char *v49; // x13
  char *v50; // x13
  __int64 v51; // x2
  unsigned __int64 *v52; // x1
  __int64 result; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  unsigned int v64; // w21
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x2
  unsigned __int64 StatusReg; // x19
  __int64 v69; // x20
  long double (*v70)(_QWORD, const char *, ...); // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x8
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x8
  __int64 v79; // x0
  __int64 v80; // x0
  unsigned __int64 v81; // [xsp+8h] [xbp-468h]
  __int64 v82; // [xsp+10h] [xbp-460h] BYREF
  char *v83; // [xsp+18h] [xbp-458h]
  __int64 v84; // [xsp+20h] [xbp-450h] BYREF
  char *v85; // [xsp+28h] [xbp-448h]
  _DWORD v86[134]; // [xsp+30h] [xbp-440h] BYREF
  _DWORD s[134]; // [xsp+248h] [xbp-228h] BYREF
  __int64 v88; // [xsp+460h] [xbp-10h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = 0;
  v85 = nullptr;
  v82 = 0;
  v83 = nullptr;
  memset(s, 0, sizeof(s));
  memset(v86, 0, sizeof(v86));
  if ( a1 )
  {
    if ( ipa_eth_ctx )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa_eth %s:%d register interface for netdev %s\n",
          "ipa_eth_client_reg_intf",
          890,
          *a1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_eth %s:%d register interface for netdev %s\n",
          "ipa_eth_client_reg_intf",
          890,
          *a1);
      }
      mutex_lock(ipa_eth_ctx + 192);
      v5 = ipa_eth_ctx + 288;
      v6 = ipa_eth_ctx + 288;
      while ( 1 )
      {
        v6 = *(_QWORD *)v6;
        if ( v6 == v5 )
          break;
        if ( !strcmp((const char *)(v6 + 16), *a1) )
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v7 = ipa3_get_ipc_logbuf();
            ipc_log_string(v7, "ipa_eth %s:%d intf was added before.\n", "ipa_eth_client_reg_intf", 899);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v8 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v8, "ipa_eth %s:%d intf was added before.\n", "ipa_eth_client_reg_intf", 899);
          }
LABEL_80:
          mutex_unlock(ipa_eth_ctx + 192);
          result = 0;
          goto LABEL_81;
        }
      }
      v9 = _kmalloc_cache_noprof(ipc_log_string, 3520, 64);
      while ( v9 )
      {
        *(_QWORD *)v9 = v9;
        *(_QWORD *)(v9 + 8) = v9;
        v10 = *a1;
        v11 = strnlen(*a1, 0x20u);
        if ( v11 == -1 )
        {
          _fortify_panic(2, -1, 0);
          _fortify_panic(15, v1, v67);
        }
        else
        {
          if ( v11 == 32 )
            v12 = 32;
          else
            v12 = v11 + 1;
          if ( v12 >= 0x21 )
            goto LABEL_115;
          sized_strscpy(v9 + 16, v10);
          *(_BYTE *)(v9 + 48) = *((_BYTE *)a1 + 16);
          v13 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 620);
          v14 = v13;
          if ( !v13 )
          {
            printk(&unk_3D99D4, "ipa_eth_client_reg_intf");
            if ( ipa3_get_ipc_logbuf() )
            {
              v73 = ipa3_get_ipc_logbuf();
              ipc_log_string(v73, "ipa_eth %s:%d fail to alloc %d bytes\n", "ipa_eth_client_reg_intf", 960, 620);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v74 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v74, "ipa_eth %s:%d fail to alloc %d bytes\n", "ipa_eth_client_reg_intf", 960, 620);
            }
            v64 = -14;
            goto LABEL_146;
          }
          v15 = *a1;
          if ( !*a1 )
          {
            printk(&unk_3AE0DC, "ipa_eth_commit_partial_hdr");
            if ( ipa3_get_ipc_logbuf() )
            {
              v58 = ipa3_get_ipc_logbuf();
              ipc_log_string(v58, "ipa_eth %s:%d Invalid input\n", "ipa_eth_commit_partial_hdr", 535);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v59 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v59, "ipa_eth %s:%d Invalid input\n", "ipa_eth_commit_partial_hdr", 535);
            }
LABEL_100:
            printk(&unk_3A4F8E, "ipa_eth_client_reg_intf");
            if ( ipa3_get_ipc_logbuf() )
            {
              v62 = ipa3_get_ipc_logbuf();
              ipc_log_string(v62, "ipa_eth %s:%d fail to commit partial headers\n", "ipa_eth_client_reg_intf", 970);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v63 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v63, "ipa_eth %s:%d fail to commit partial headers\n", "ipa_eth_client_reg_intf", 970);
            }
            v1 = nullptr;
            v38 = nullptr;
            v64 = -14;
            goto LABEL_145;
          }
          v16 = *a1;
          *(_WORD *)v13 = 512;
          snprintf((char *)(v13 + 4), 0x20u, "%s_ipv4", v16);
          snprintf((char *)(v14 + 312), 0x20u, "%s_ipv6", v15);
          v17 = *((unsigned __int8 *)a1 + 16);
          v18 = a1[1];
          *(_BYTE *)(v14 + 291) = v17;
          memcpy((void *)(v14 + 36), v18, v17);
          v19 = *((_DWORD *)a1 + 5);
          v20 = *((unsigned __int8 *)a1 + 17);
          v21 = *((unsigned __int8 *)a1 + 32);
          v22 = a1[3];
          *(_BYTE *)(v14 + 296) = 1;
          *(_BYTE *)(v14 + 308) = 1;
          *(_DWORD *)(v14 + 292) = v19;
          *(_WORD *)(v14 + 310) = v20;
          *(_BYTE *)(v14 + 599) = v21;
          memcpy((void *)(v14 + 344), v22, v21);
          v23 = *((_DWORD *)a1 + 9);
          v24 = *((unsigned __int8 *)a1 + 33);
          *(_BYTE *)(v14 + 604) = 1;
          *(_BYTE *)(v14 + 616) = 1;
          *(_DWORD *)(v14 + 600) = v23;
          *(_WORD *)(v14 + 618) = v24;
          if ( (unsigned int)ipa_add_hdr(v14) )
          {
            printk(&unk_3ED757, "ipa_eth_commit_partial_hdr");
            if ( ipa3_get_ipc_logbuf() )
            {
              v60 = ipa3_get_ipc_logbuf();
              ipc_log_string(v60, "ipa_eth %s:%d fail to add partial headers\n", "ipa_eth_commit_partial_hdr", 556);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v61 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v61, "ipa_eth %s:%d fail to add partial headers\n", "ipa_eth_commit_partial_hdr", 556);
            }
            goto LABEL_100;
          }
          v25 = *(_DWORD *)(v14 + 608);
          *(_DWORD *)(v9 + 52) = *(_DWORD *)(v14 + 300);
          *(_DWORD *)(v9 + 56) = v25;
          if ( ipa3_get_ipc_logbuf() )
          {
            v26 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v26,
              "ipa_eth %s:%d IPv4 hdr hdl: %d IPv6 hdr hdl: %d\n",
              "ipa_eth_client_reg_intf",
              978,
              *(_DWORD *)(v14 + 300),
              *(_DWORD *)(v14 + 608));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v27 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v27,
              "ipa_eth %s:%d IPv4 hdr hdl: %d IPv6 hdr hdl: %d\n",
              "ipa_eth_client_reg_intf",
              978,
              *(_DWORD *)(v14 + 300),
              *(_DWORD *)(v14 + 608));
          }
          v28 = *((_DWORD *)a1 + 10);
          v84 = 0;
          v85 = nullptr;
          v82 = 0;
          v83 = nullptr;
          if ( v28 < 1 )
          {
            v38 = nullptr;
LABEL_73:
            v1 = nullptr;
LABEL_74:
            if ( !(unsigned int)ipa_register_intf((__int64)*a1, (__int64)&v84, (__int64)&v82) )
            {
              v51 = *(_QWORD *)(ipa_eth_ctx + 288);
              v52 = (unsigned __int64 *)(ipa_eth_ctx + 288);
              if ( *(_QWORD *)(v51 + 8) != ipa_eth_ctx + 288 || (unsigned __int64 *)v9 == v52 || v51 == v9 )
              {
                _list_add_valid_or_report(v9, v52);
              }
              else
              {
                *(_QWORD *)(v51 + 8) = v9;
                *(_QWORD *)v9 = v51;
                *(_QWORD *)(v9 + 8) = v52;
                *v52 = v9;
              }
              kfree(v14);
              kfree(v38);
              kfree(v1);
              goto LABEL_80;
            }
            printk(&unk_3A4FBE, "ipa_eth_client_reg_intf");
            if ( ipa3_get_ipc_logbuf() )
            {
              v65 = ipa3_get_ipc_logbuf();
              ipc_log_string(v65, "ipa_eth %s:%d fail to add interface prop\n", "ipa_eth_client_reg_intf", 1070);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v66 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v66, "ipa_eth %s:%d fail to add interface prop\n", "ipa_eth_client_reg_intf", 1070);
            }
            v64 = -14;
LABEL_145:
            kfree(v14);
            kfree(v38);
            kfree(v1);
LABEL_146:
            kfree(v9);
            mutex_unlock(ipa_eth_ctx + 192);
            result = v64;
            goto LABEL_81;
          }
          v81 = v9;
          v29 = 0;
          v30 = 0;
          v31 = 0;
          do
          {
            v32 = *(unsigned int *)&a1[6][4 * v31];
            raw_spin_lock(ipa_eth_ctx + 280);
            v33 = idr_find(ipa_eth_ctx + 256, v32);
            raw_spin_unlock(ipa_eth_ctx + 280);
            v34 = *(_DWORD *)(v33 + 16);
            ipa_client_type_from_pipe = ipa_eth_get_ipa_client_type_from_pipe(v33);
            if ( v34 )
            {
              if ( v30 > 0x85 )
                goto LABEL_114;
              v86[v30++] = ipa_client_type_from_pipe;
              LODWORD(v82) = v30;
            }
            else
            {
              if ( v29 > 0x85 )
                goto LABEL_114;
              s[v29++] = ipa_client_type_from_pipe;
              LODWORD(v84) = v29;
            }
            ++v31;
          }
          while ( v31 < *((int *)a1 + 10) );
          if ( v29 )
          {
            v36 = 400 * v29;
            v37 = (char *)_kmalloc_noprof(400 * v29, 3264);
            v38 = v37;
            if ( !v37 )
            {
              printk(&unk_3CFD12, "ipa_eth_client_reg_intf");
              v75 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v9 = v81;
                v76 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v76 )
                {
                  ipc_log_string(v76, "ipa %s:%d failed to allocate memory\n", "ipa_eth_client_reg_intf", 1004);
                  v75 = ipa3_ctx;
                }
                v77 = *(_QWORD *)(v75 + 34160);
                if ( v77 )
                  ipc_log_string(v77, "ipa %s:%d failed to allocate memory\n", "ipa_eth_client_reg_intf", 1004);
                v1 = nullptr;
                v38 = nullptr;
                goto LABEL_144;
              }
              v1 = nullptr;
              v38 = nullptr;
              goto LABEL_143;
            }
            memset(v37, 0, 400 * v29);
            v85 = v38;
            if ( (_DWORD)v84 )
            {
              v39 = 0;
              v40 = 0;
              while ( v36 > v39 )
              {
                *(_DWORD *)&v38[v39] = 0;
                if ( v40 == 134 )
                  goto LABEL_114;
                if ( v36 < v39 + 156 )
                  break;
                v41 = &v38[v39];
                *(_DWORD *)&v38[v39 + 156] = s[v40];
                if ( v36 < v39 + 196 )
                  break;
                *((_DWORD *)v41 + 49) = *((_DWORD *)a1 + 5);
                v42 = strnlen((const char *)(v14 + 4), 0x20u);
                if ( v42 >= 0x21 )
                  goto LABEL_116;
                if ( v42 == 32 )
                  v12 = 32;
                else
                  v12 = v42 + 1;
                if ( v12 >= 0x21 )
                  goto LABEL_115;
                sized_strscpy(v41 + 164, v14 + 4);
                if ( v36 <= v39 + 200 )
                  break;
                *(_DWORD *)&v38[v39 + 200] = 1;
                if ( v36 < v39 + 356 )
                  break;
                v43 = &v38[v39];
                *(_DWORD *)&v38[v39 + 356] = s[v40];
                if ( v36 < v39 + 396 )
                  break;
                *((_DWORD *)v43 + 99) = *((_DWORD *)a1 + 9);
                v42 = strnlen((const char *)(v14 + 312), 0x20u);
                if ( v42 >= 0x21 )
                  goto LABEL_116;
                v12 = v42 == 32 ? 32LL : v42 + 1;
                if ( v12 >= 0x21 )
                  goto LABEL_115;
                ++v40;
                sized_strscpy(v43 + 364, v14 + 312);
                v39 += 200LL;
                if ( v40 >= (unsigned int)v84 )
                  goto LABEL_60;
              }
LABEL_113:
              __break(1u);
LABEL_114:
              __break(0x5512u);
LABEL_115:
              v42 = _fortify_panic(7, 32, v12);
LABEL_116:
              _fortify_panic(2, 32, v42 + 1);
            }
          }
          else
          {
            v38 = nullptr;
          }
LABEL_60:
          v9 = v81;
          if ( !(_DWORD)v82 )
            goto LABEL_73;
          v9 = 328LL * (unsigned int)v82;
          v44 = (char *)_kmalloc_noprof(v9, 3264);
          v1 = v44;
          if ( !v44 )
          {
            printk(&unk_3CFD12, "ipa_eth_client_reg_intf");
            v78 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v9 = v81;
              v79 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v79 )
              {
                ipc_log_string(v79, "ipa %s:%d failed to allocate memory\n", "ipa_eth_client_reg_intf", 1039);
                v78 = ipa3_ctx;
              }
              v80 = *(_QWORD *)(v78 + 34160);
              if ( v80 )
                ipc_log_string(v80, "ipa %s:%d failed to allocate memory\n", "ipa_eth_client_reg_intf", 1039);
              v1 = nullptr;
              goto LABEL_144;
            }
            v1 = nullptr;
LABEL_143:
            v9 = v81;
LABEL_144:
            v64 = -12;
            goto LABEL_145;
          }
          v45 = 328LL * (unsigned int)v82;
          if ( v9 >= v45 )
          {
            memset(v44, 0, v45);
            v83 = v1;
            v46 = (unsigned int)v82;
            v47 = 0;
            for ( i = 0; i < v46; ++i )
            {
              if ( v9 <= v47 )
                goto LABEL_113;
              *(_DWORD *)&v1[v47] = 0;
              if ( i == 134 )
                goto LABEL_114;
              if ( v9 <= v47 + 156 )
                goto LABEL_113;
              v49 = &v1[v47];
              *(_DWORD *)&v1[v47 + 156] = v86[i];
              if ( v9 <= v47 + 160 )
                goto LABEL_113;
              *((_DWORD *)v49 + 40) = *((_DWORD *)a1 + 5);
              if ( v9 <= v47 + 164 )
                goto LABEL_113;
              *((_DWORD *)v49 + 41) = 1;
              if ( v9 <= v47 + 320 )
                goto LABEL_113;
              v50 = &v1[v47];
              *(_DWORD *)&v1[v47 + 320] = v86[i];
              if ( v9 <= v47 + 324 )
                goto LABEL_113;
              v47 += 164LL;
              *((_DWORD *)v50 + 81) = *((_DWORD *)a1 + 9);
            }
            v9 = v81;
            LODWORD(v82) = 2 * v46;
            LODWORD(v84) = 2 * v84;
            goto LABEL_74;
          }
        }
        _fortify_panic(15, v9, v45);
        StatusReg = _ReadStatusReg(SP_EL0);
        v69 = *(_QWORD *)(StatusReg + 80);
        v70 = ipc_log_string;
        *(_QWORD *)(StatusReg + 80) = &ipa_eth_client_reg_intf__alloc_tag;
        v9 = _kmalloc_cache_noprof(v70, 3520, 64);
        *(_QWORD *)(StatusReg + 80) = v69;
      }
      printk(&unk_3CAE81, "ipa_eth_client_reg_intf");
      if ( ipa3_get_ipc_logbuf() )
      {
        v71 = ipa3_get_ipc_logbuf();
        ipc_log_string(v71, "ipa_eth %s:%d fail to alloc new intf\n", "ipa_eth_client_reg_intf", 943);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v72 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v72, "ipa_eth %s:%d fail to alloc new intf\n", "ipa_eth_client_reg_intf", 943);
      }
      mutex_unlock(ipa_eth_ctx + 192);
      result = 4294967284LL;
    }
    else
    {
      printk(&unk_3AB226, "ipa_eth_client_reg_intf");
      if ( ipa3_get_ipc_logbuf() )
      {
        v56 = ipa3_get_ipc_logbuf();
        ipc_log_string(v56, "ipa_eth %s:%d disconn called before register readiness\n", "ipa_eth_client_reg_intf", 852);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v57 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v57, "ipa_eth %s:%d disconn called before register readiness\n", "ipa_eth_client_reg_intf", 852);
      }
      result = 4294967282LL;
    }
  }
  else
  {
    printk(&unk_3DCBF3, "ipa_eth_client_reg_intf");
    if ( ipa3_get_ipc_logbuf() )
    {
      v54 = ipa3_get_ipc_logbuf();
      ipc_log_string(v54, "ipa_eth %s:%d invalid params intf=%pK\n", "ipa_eth_client_reg_intf", 848, nullptr);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v55 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v55, "ipa_eth %s:%d invalid params intf=%pK\n", "ipa_eth_client_reg_intf", 848, nullptr);
    }
    result = 4294967274LL;
  }
LABEL_81:
  _ReadStatusReg(SP_EL0);
  return result;
}
