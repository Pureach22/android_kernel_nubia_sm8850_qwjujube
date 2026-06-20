__int64 __fastcall ipa_wigig_reg_intf(const char **a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x19
  const char *v7; // x21
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x19
  __int64 v14; // x22
  const char *v15; // x21
  size_t v16; // x0
  unsigned __int64 v17; // x2
  int v18; // w8
  __int16 v19; // w10
  __int64 v20; // x21
  const char *v21; // x24
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  size_t v26; // x2
  const char *v27; // x1
  int v28; // w8
  __int16 v29; // w9
  size_t v30; // x2
  const char *v31; // x1
  int v32; // w8
  __int16 v33; // w9
  __int64 v34; // x0
  __int64 v35; // x0
  int v36; // w9
  __int64 v37; // x0
  __int64 v38; // x0
  int v39; // w9
  size_t v40; // x0
  int v41; // w10
  int v42; // w24
  int v43; // w9
  const char *v44; // x0
  __int64 *v45; // x1
  __int64 v46; // x2
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  long double v62; // q0
  __int64 v63; // x0
  __int64 v64; // x0
  int v65; // w9
  int v66; // w10
  __int64 v67; // x20
  unsigned int v68; // w19
  unsigned __int64 StatusReg; // x21
  __int64 v70; // x22
  long double (*v71)(_QWORD, const char *, ...); // x0
  __int64 v72; // [xsp+20h] [xbp-300h] BYREF
  _DWORD *v73; // [xsp+28h] [xbp-2F8h]
  __int64 v74; // [xsp+30h] [xbp-2F0h] BYREF
  _DWORD *v75; // [xsp+38h] [xbp-2E8h]
  _DWORD v76[82]; // [xsp+40h] [xbp-2E0h] BYREF
  _DWORD s[100]; // [xsp+188h] [xbp-198h] BYREF
  __int64 v78; // [xsp+318h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v74 = 0;
  v75 = nullptr;
  v72 = 0;
  v73 = nullptr;
  memset(s, 0, sizeof(s));
  memset(v76, 0, sizeof(v76));
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d \n", "ipa_wigig_reg_intf", 336);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_reg_intf", 336);
  }
  if ( a1 )
  {
    if ( ipa_wigig_ctx )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v4 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v4,
          "ipa_wigig %s:%d register interface for netdev %s, MAC 0x[%X][%X][%X][%X][%X][%X]\n",
          "ipa_wigig_reg_intf",
          352,
          *a1,
          *((unsigned __int8 *)a1 + 8),
          *((unsigned __int8 *)a1 + 9),
          *((unsigned __int8 *)a1 + 10),
          *((unsigned __int8 *)a1 + 11),
          *((unsigned __int8 *)a1 + 12),
          *((unsigned __int8 *)a1 + 13));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v5 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v5,
          "ipa_wigig %s:%d register interface for netdev %s, MAC 0x[%X][%X][%X][%X][%X][%X]\n",
          "ipa_wigig_reg_intf",
          352,
          *a1,
          *((unsigned __int8 *)a1 + 8),
          *((unsigned __int8 *)a1 + 9),
          *((unsigned __int8 *)a1 + 10),
          *((unsigned __int8 *)a1 + 11),
          *((unsigned __int8 *)a1 + 12),
          *((unsigned __int8 *)a1 + 13));
      }
      mutex_lock(ipa_wigig_ctx + 16);
      v6 = ipa_wigig_ctx;
      v7 = (const char *)ipa_wigig_ctx;
      while ( 1 )
      {
        v7 = *(const char **)v7;
        if ( v7 == (const char *)v6 )
          break;
        if ( !strcmp(v7 - 48, *a1) )
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v8 = ipa3_get_ipc_logbuf();
            ipc_log_string(v8, "ipa_wigig %s:%d intf was added before.\n", "ipa_wigig_reg_intf", 357);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v9 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v9, "ipa_wigig %s:%d intf was added before.\n", "ipa_wigig_reg_intf", 357);
          }
          mutex_unlock(ipa_wigig_ctx + 16);
          result = 0;
          goto LABEL_112;
        }
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v11 = ipa3_get_ipc_logbuf();
        ipc_log_string(v11, "ipa_wigig %s:%d intf was not added before, proceed.\n", "ipa_wigig_reg_intf", 362);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v12 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v12, "ipa_wigig %s:%d intf was not added before, proceed.\n", "ipa_wigig_reg_intf", 362);
      }
      v13 = _kmalloc_cache_noprof(ipc_log_string, 3520, 64);
      if ( v13 )
      {
        while ( 1 )
        {
          v14 = v13 + 48;
          *(_QWORD *)(v13 + 48) = v13 + 48;
          *(_QWORD *)(v13 + 56) = v13 + 48;
          v15 = *a1;
          v16 = strnlen(*a1, 0x20u);
          if ( v16 != -1 )
            break;
LABEL_109:
          _fortify_panic(2, -1, v16 + 1);
          StatusReg = _ReadStatusReg(SP_EL0);
          v70 = *(_QWORD *)(StatusReg + 80);
          v71 = ipc_log_string;
          *(_QWORD *)(StatusReg + 80) = &ipa_wigig_reg_intf__alloc_tag;
          v13 = _kmalloc_cache_noprof(v71, 3520, 64);
          *(_QWORD *)(StatusReg + 80) = v70;
          if ( !v13 )
            goto LABEL_110;
        }
        if ( v16 == 32 )
          v17 = 32;
        else
          v17 = v16 + 1;
        if ( v17 < 0x21 )
        {
          sized_strscpy(v13, v15);
          v18 = *((_DWORD *)a1 + 2);
          v19 = *((_WORD *)a1 + 6);
          *(_BYTE *)(v13 + 38) = *((_BYTE *)a1 + 24);
          *(_DWORD *)(v13 + 32) = v18;
          *(_WORD *)(v13 + 36) = v19;
          v20 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 620);
          if ( !v20 )
            goto LABEL_105;
          v21 = *a1;
          if ( ipa3_get_ipc_logbuf() )
          {
            v22 = ipa3_get_ipc_logbuf();
            ipc_log_string(v22, "ipa_wigig %s:%d \n", "ipa_wigig_commit_partial_hdr", 263);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v23 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v23, "ipa_wigig %s:%d \n", "ipa_wigig_commit_partial_hdr", 263);
          }
          if ( !v21 )
          {
            printk(&unk_3B9F6A, "ipa_wigig_commit_partial_hdr");
            if ( ipa3_get_ipc_logbuf() )
            {
              v53 = ipa3_get_ipc_logbuf();
              ipc_log_string(v53, "ipa_wigig %s:%d Invalid input\n", "ipa_wigig_commit_partial_hdr", 266);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v54 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v54, "ipa_wigig %s:%d Invalid input\n", "ipa_wigig_commit_partial_hdr", 266);
            }
LABEL_88:
            printk(&unk_3CE701, "ipa_wigig_reg_intf");
            if ( ipa3_get_ipc_logbuf() )
            {
              v57 = ipa3_get_ipc_logbuf();
              ipc_log_string(v57, "ipa_wigig %s:%d fail to commit partial headers\n", "ipa_wigig_reg_intf", 386);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v58 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v58, "ipa_wigig %s:%d fail to commit partial headers\n", "ipa_wigig_reg_intf", 386);
            }
LABEL_104:
            kfree(v20);
LABEL_105:
            kfree(v13);
            v68 = -14;
            goto LABEL_111;
          }
          if ( ipa3_get_ipc_logbuf() )
          {
            v24 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v24,
              "ipa_wigig %s:%d dst_mac_addr_offset %d hdr_len %d hdr_type %d\n",
              "ipa_wigig_commit_partial_hdr",
              273,
              *((unsigned __int8 *)a1 + 25),
              *((unsigned __int8 *)a1 + 24),
              *((_DWORD *)a1 + 7));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v25 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v25,
              "ipa_wigig %s:%d dst_mac_addr_offset %d hdr_len %d hdr_type %d\n",
              "ipa_wigig_commit_partial_hdr",
              273,
              *((unsigned __int8 *)a1 + 25),
              *((unsigned __int8 *)a1 + 24),
              *((_DWORD *)a1 + 7));
          }
          *(_WORD *)v20 = 512;
          snprintf((char *)(v20 + 4), 0x20u, "%s_ipv4", v21);
          snprintf((char *)(v20 + 312), 0x20u, "%s_ipv6", v21);
          v26 = *((unsigned __int8 *)a1 + 24);
          v27 = a1[2];
          *(_BYTE *)(v20 + 291) = v26;
          memcpy((void *)(v20 + 36), v27, v26);
          v28 = *((_DWORD *)a1 + 7);
          v29 = *((unsigned __int8 *)a1 + 25);
          v30 = *((unsigned __int8 *)a1 + 40);
          v31 = a1[4];
          *(_BYTE *)(v20 + 296) = 1;
          *(_BYTE *)(v20 + 308) = 1;
          *(_DWORD *)(v20 + 292) = v28;
          *(_WORD *)(v20 + 310) = v29;
          *(_BYTE *)(v20 + 599) = v30;
          memcpy((void *)(v20 + 344), v31, v30);
          v32 = *((_DWORD *)a1 + 11);
          v33 = *((unsigned __int8 *)a1 + 41);
          *(_BYTE *)(v20 + 604) = 1;
          *(_BYTE *)(v20 + 616) = 1;
          *(_DWORD *)(v20 + 600) = v32;
          *(_WORD *)(v20 + 618) = v33;
          if ( (unsigned int)ipa_add_hdr(v20) )
          {
            printk(&unk_3B9F8B, "ipa_wigig_commit_partial_hdr");
            if ( ipa3_get_ipc_logbuf() )
            {
              v55 = ipa3_get_ipc_logbuf();
              ipc_log_string(v55, "ipa_wigig %s:%d fail to add partial headers\n", "ipa_wigig_commit_partial_hdr", 292);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v56 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v56, "ipa_wigig %s:%d fail to add partial headers\n", "ipa_wigig_commit_partial_hdr", 292);
            }
            goto LABEL_88;
          }
          if ( ipa3_get_ipc_logbuf() )
          {
            v34 = ipa3_get_ipc_logbuf();
            ipc_log_string(v34, "ipa_wigig %s:%d exit\n", "ipa_wigig_commit_partial_hdr", 296);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v35 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v35, "ipa_wigig %s:%d exit\n", "ipa_wigig_commit_partial_hdr", 296);
          }
          v36 = *(_DWORD *)(v20 + 608);
          *(_DWORD *)(v13 + 40) = *(_DWORD *)(v20 + 300);
          *(_DWORD *)(v13 + 44) = v36;
          if ( ipa3_get_ipc_logbuf() )
          {
            v37 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v37,
              "ipa_wigig %s:%d IPv4 hdr hdl: %d IPv6 hdr hdl: %d\n",
              "ipa_wigig_reg_intf",
              394,
              *(_DWORD *)(v20 + 300),
              *(_DWORD *)(v20 + 608));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v38 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v38,
              "ipa_wigig %s:%d IPv4 hdr hdl: %d IPv6 hdr hdl: %d\n",
              "ipa_wigig_reg_intf",
              394,
              *(_DWORD *)(v20 + 300),
              *(_DWORD *)(v20 + 608));
          }
          LODWORD(v74) = 2;
          v75 = s;
          memset(s, 0, sizeof(s));
          v39 = *((_DWORD *)a1 + 7);
          s[39] = 87;
          s[49] = v39;
          v40 = strnlen((const char *)(v20 + 4), 0x20u);
          if ( v40 >= 0x21 )
            goto LABEL_108;
          v17 = v40 == 32 ? 32LL : v40 + 1;
          if ( v17 < 0x21 )
          {
            sized_strscpy(&s[41], v20 + 4);
            v41 = *((_DWORD *)a1 + 11);
            s[50] = 1;
            s[89] = 87;
            s[99] = v41;
            v40 = strnlen((const char *)(v20 + 312), 0x20u);
            if ( v40 >= 0x21 )
            {
LABEL_108:
              v16 = _fortify_panic(2, 32, v40 + 1);
              goto LABEL_109;
            }
            if ( v40 == 32 )
              v17 = 32;
            else
              v17 = v40 + 1;
            if ( v17 < 0x21 )
            {
              sized_strscpy(&s[91], v20 + 312);
              v42 = *((_DWORD *)a1 + 11);
              LODWORD(v72) = 2;
              v73 = v76;
              memset(v76, 0, 0x140u);
              v43 = *((_DWORD *)a1 + 7);
              v44 = *a1;
              v76[39] = 86;
              v76[40] = v43;
              v76[41] = 1;
              v76[80] = 86;
              v76[81] = v42;
              if ( (unsigned int)ipa_register_intf((__int64)v44, (__int64)&v74, (__int64)&v72) )
              {
                printk(&unk_3F402B, "ipa_wigig_reg_intf");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v59 = ipa3_get_ipc_logbuf();
                  ipc_log_string(v59, "ipa_wigig %s:%d fail to add interface prop\n", "ipa_wigig_reg_intf", 431);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v60 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(v60, "ipa_wigig %s:%d fail to add interface prop\n", "ipa_wigig_reg_intf", 431);
                }
              }
              else
              {
                if ( !(unsigned int)ipa_wigig_send_wlan_msg(6, *a1, (int *)a1 + 2) )
                {
                  v45 = (__int64 *)ipa_wigig_ctx;
                  v46 = *(_QWORD *)ipa_wigig_ctx;
                  if ( *(_QWORD *)(*(_QWORD *)ipa_wigig_ctx + 8LL) != ipa_wigig_ctx
                    || v14 == ipa_wigig_ctx
                    || v46 == v14 )
                  {
                    _list_add_valid_or_report(v13 + 48, ipa_wigig_ctx);
                  }
                  else
                  {
                    *(_QWORD *)(v46 + 8) = v14;
                    *(_QWORD *)(v13 + 48) = v46;
                    *(_QWORD *)(v13 + 56) = v45;
                    *v45 = v14;
                  }
                  kfree(v20);
                  mutex_unlock(ipa_wigig_ctx + 16);
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v47 = ipa3_get_ipc_logbuf();
                    ipc_log_string(v47, "ipa_wigig %s:%d exit\n", "ipa_wigig_reg_intf", 449);
                  }
                  result = ipa3_get_ipc_logbuf_low();
                  if ( result )
                  {
                    v48 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(v48, "ipa_wigig %s:%d exit\n", "ipa_wigig_reg_intf", 449);
                    result = 0;
                  }
                  goto LABEL_112;
                }
                printk(&unk_3A5654, "ipa_wigig_reg_intf");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v61 = ipa3_get_ipc_logbuf();
                  ipc_log_string(v61, "ipa_wigig %s:%d couldn't send msg to IPACM\n", "ipa_wigig_reg_intf", 439);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v63 = ipa3_get_ipc_logbuf_low();
                  v62 = ipc_log_string(v63, "ipa_wigig %s:%d couldn't send msg to IPACM\n", "ipa_wigig_reg_intf", 439);
                }
                ((void (__fastcall *)(const char *, long double))ipa_deregister_intf)(*a1, v62);
              }
              v64 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 20);
              if ( v64 )
              {
                v65 = *(_DWORD *)(v13 + 40);
                v66 = *(_DWORD *)(v13 + 44);
                v67 = v64;
                *(_WORD *)v64 = 513;
                *(_DWORD *)(v64 + 4) = v65;
                *(_DWORD *)(v64 + 12) = v66;
                ipa_del_hdr((_BYTE *)v64);
                kfree(v67);
              }
              *(_QWORD *)(v13 + 40) = 0;
              goto LABEL_104;
            }
          }
        }
        v40 = _fortify_panic(7, 32, v17);
        goto LABEL_108;
      }
LABEL_110:
      v68 = -12;
LABEL_111:
      mutex_unlock(ipa_wigig_ctx + 16);
      result = v68;
    }
    else
    {
      printk(&unk_3CE6D1, "ipa_wigig_reg_intf");
      if ( ipa3_get_ipc_logbuf() )
      {
        v51 = ipa3_get_ipc_logbuf();
        ipc_log_string(v51, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_reg_intf", 344);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v52 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v52, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_reg_intf", 344);
      }
      result = 0xFFFFFFFFLL;
    }
  }
  else
  {
    printk(&unk_3A8857, "ipa_wigig_reg_intf");
    if ( ipa3_get_ipc_logbuf() )
    {
      v49 = ipa3_get_ipc_logbuf();
      ipc_log_string(v49, "ipa_wigig %s:%d invalid params in=%pK\n", "ipa_wigig_reg_intf", 339, nullptr);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v50 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v50, "ipa_wigig %s:%d invalid params in=%pK\n", "ipa_wigig_reg_intf", 339, nullptr);
    }
    result = 4294967274LL;
  }
LABEL_112:
  _ReadStatusReg(SP_EL0);
  return result;
}
