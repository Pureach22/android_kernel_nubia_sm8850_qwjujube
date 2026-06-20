__int64 __fastcall ipa_uc_offload_reg_intf(const char **a1, _DWORD *a2)
{
  const char *v2; // x23
  __int64 v5; // x3
  unsigned int *v6; // x21
  unsigned int *v7; // x0
  unsigned int v8; // w8
  __int64 v9; // x0
  long double v10; // q0
  __int64 v11; // x0
  __int64 v12; // x10
  __int64 v13; // x8
  __int64 v14; // x11
  __int64 v15; // x22
  unsigned int is_vlan_mode; // w0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  size_t v21; // x2
  const char *v22; // x1
  int v23; // w8
  __int16 v24; // w9
  size_t v25; // x2
  const char *v26; // x1
  int v27; // w8
  __int16 v28; // w9
  __int64 v29; // x9
  __int64 v30; // x10
  int v31; // w27
  __int64 v32; // x9
  __int64 v33; // x10
  __int64 v34; // x8
  __int64 v35; // x9
  int v36; // w24
  __int64 v37; // x8
  __int64 v38; // x11
  int v39; // w9
  int v40; // w10
  int v41; // w11
  const char *v42; // x0
  unsigned int v43; // w8
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  unsigned int v53; // w23
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
  __int64 v64; // x0
  __int64 v65; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v67; // x25
  __int64 v68; // x0
  long double v69; // q0
  __int64 v70; // x0
  unsigned int v71; // w19
  __int64 v72; // x0
  __int64 v73; // x8
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  unsigned __int8 v77[4]; // [xsp+Ch] [xbp-304h] BYREF
  __int64 v78; // [xsp+10h] [xbp-300h] BYREF
  _DWORD *v79; // [xsp+18h] [xbp-2F8h]
  __int64 v80; // [xsp+20h] [xbp-2F0h] BYREF
  _DWORD *v81; // [xsp+28h] [xbp-2E8h]
  _DWORD v82[82]; // [xsp+30h] [xbp-2E0h] BYREF
  _DWORD s[100]; // [xsp+178h] [xbp-198h] BYREF
  __int64 v84; // [xsp+308h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    printk(&unk_3B98BF, "ipa_uc_offload_reg_intf");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_uc_offload %s:%d invalid params in=%pK out=%pK\n",
        "ipa_uc_offload_reg_intf",
        306,
        a1,
        a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_uc_offload %s:%d invalid params in=%pK out=%pK\n",
        "ipa_uc_offload_reg_intf",
        306,
        a1,
        a2);
      result = 4294967274LL;
      goto LABEL_87;
    }
    goto LABEL_49;
  }
  v5 = *((unsigned int *)a1 + 17);
  if ( (unsigned int)(v5 - 4) <= 0xFFFFFFFC )
  {
    printk(&unk_3AE394, "ipa_uc_offload_reg_intf");
    if ( ipa3_get_ipc_logbuf() )
    {
      v47 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v47,
        "ipa_uc_offload %s:%d invalid proto %d\n",
        "ipa_uc_offload_reg_intf",
        312,
        *((_DWORD *)a1 + 17));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v48 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v48,
        "ipa_uc_offload %s:%d invalid proto %d\n",
        "ipa_uc_offload_reg_intf",
        312,
        *((_DWORD *)a1 + 17));
      result = 4294967274LL;
      goto LABEL_87;
    }
    goto LABEL_49;
  }
  v6 = (unsigned int *)ipa_uc_offload_ctx[v5];
  if ( v6 )
  {
LABEL_8:
    if ( !v6[1] )
    {
      if ( *v6 != 2 )
      {
        result = 0;
        if ( *v6 != 3 )
          goto LABEL_87;
        goto LABEL_88;
      }
      v80 = 0;
      v81 = nullptr;
      v78 = 0;
      v79 = nullptr;
      memset(s, 0, sizeof(s));
      memset(v82, 0, sizeof(v82));
      v77[0] = 0;
      if ( ipa3_get_ipc_logbuf() )
      {
        v9 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v9,
          "ipa_uc_offload %s:%d register interface for netdev %s\n",
          "ipa_uc_offload_ntn_reg_intf",
          175,
          *a1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v11 = ipa3_get_ipc_logbuf_low();
        v10 = ipc_log_string(
                v11,
                "ipa_uc_offload %s:%d register interface for netdev %s\n",
                "ipa_uc_offload_ntn_reg_intf",
                175,
                *a1);
      }
      if ( (unsigned int)ipa_uc_offload_ntn_register_pm_client(v6, v10) )
      {
        printk(&unk_3F3D36, "ipa_uc_offload_ntn_reg_intf");
        if ( ipa3_get_ipc_logbuf() )
        {
          v51 = ipa3_get_ipc_logbuf();
          ipc_log_string(v51, "ipa_uc_offload %s:%d fail to register PM client\n", "ipa_uc_offload_ntn_reg_intf", 178);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v52 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v52, "ipa_uc_offload %s:%d fail to register PM client\n", "ipa_uc_offload_ntn_reg_intf", 178);
        }
        result = 4294967282LL;
LABEL_86:
        if ( *v6 != 3 )
          goto LABEL_87;
LABEL_88:
        printk(&unk_3C5A02, "ipa_uc_offload_reg_intf");
        if ( ipa3_get_ipc_logbuf() )
        {
          v68 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v68,
            "ipa_uc_offload %s:%d v2x hdr_len %d\n",
            "ipa_uc_offload_reg_intf",
            343,
            *((unsigned __int8 *)a1 + 32));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v70 = ipa3_get_ipc_logbuf_low();
          v69 = ipc_log_string(
                  v70,
                  "ipa_uc_offload %s:%d v2x hdr_len %d\n",
                  "ipa_uc_offload_reg_intf",
                  343,
                  *((unsigned __int8 *)a1 + 32));
        }
        *((_BYTE *)v6 + 16) = *((_BYTE *)a1 + 32);
        result = ipa_uc_offload_ntn_register_pm_client(v6, v69);
        if ( (_DWORD)result )
        {
          v71 = result;
          printk(&unk_3B691F, "ipa_uc_offload_reg_intf");
          if ( ipa3_get_ipc_logbuf() )
          {
            v72 = ipa3_get_ipc_logbuf();
            ipc_log_string(v72, "ipa_uc_offload %s:%d fail to create pm resource\n", "ipa_uc_offload_reg_intf", 349);
          }
          v73 = ipa3_get_ipc_logbuf_low();
          result = v71;
          if ( v73 )
          {
            v74 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v74, "ipa_uc_offload %s:%d fail to create pm resource\n", "ipa_uc_offload_reg_intf", 349);
            result = v71;
          }
        }
        else
        {
          *a2 = 3;
        }
        v6[1] = 1;
        goto LABEL_87;
      }
      v12 = *((_QWORD *)*a1 + 1);
      v13 = *((_QWORD *)*a1 + 2);
      v14 = *((_QWORD *)*a1 + 3);
      *(_QWORD *)(v6 + 7) = *(_QWORD *)*a1;
      v2 = (const char *)(v6 + 7);
      *(_QWORD *)(v6 + 11) = v13;
      *(_QWORD *)(v6 + 13) = v14;
      *(_QWORD *)(v6 + 9) = v12;
      *((_BYTE *)v6 + 16) = *((_BYTE *)a1 + 32);
      *((_QWORD *)v6 + 8) = a1[1];
      *((_QWORD *)v6 + 1) = a1[2];
      v15 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 620);
      if ( v15 )
      {
LABEL_16:
        is_vlan_mode = ipa_is_vlan_mode(0, v77);
        if ( is_vlan_mode )
        {
          v53 = is_vlan_mode;
          printk(&unk_3E25F1, "ipa_uc_offload_ntn_reg_intf");
          if ( ipa3_get_ipc_logbuf() )
          {
            v54 = ipa3_get_ipc_logbuf();
            ipc_log_string(v54, "ipa_uc_offload %s:%d get vlan mode failed\n", "ipa_uc_offload_ntn_reg_intf", 196);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v55 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v55, "ipa_uc_offload %s:%d get vlan mode failed\n", "ipa_uc_offload_ntn_reg_intf", 196);
          }
          goto LABEL_82;
        }
        if ( v77[0] != 1 )
          goto LABEL_30;
        if ( *((_DWORD *)a1 + 9) == 3 && *((_DWORD *)a1 + 13) == 3 )
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v17 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v17,
              "ipa_uc_offload %s:%d vlan HEADER type compatible\n",
              "ipa_uc_offload_ntn_reg_intf",
              209);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v18 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v18,
              "ipa_uc_offload %s:%d vlan HEADER type compatible\n",
              "ipa_uc_offload_ntn_reg_intf",
              209);
          }
          if ( *((unsigned __int8 *)a1 + 32) >= 0x12u && *((unsigned __int8 *)a1 + 48) > 0x11u )
          {
            if ( ipa3_get_ipc_logbuf() )
            {
              v19 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v19,
                "ipa_uc_offload %s:%d vlan HEADER len compatible (%u) (%u)\n",
                "ipa_uc_offload_ntn_reg_intf",
                226,
                *((unsigned __int8 *)a1 + 32),
                *((unsigned __int8 *)a1 + 48));
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v20 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v20,
                "ipa_uc_offload %s:%d vlan HEADER len compatible (%u) (%u)\n",
                "ipa_uc_offload_ntn_reg_intf",
                226,
                *((unsigned __int8 *)a1 + 32),
                *((unsigned __int8 *)a1 + 48));
            }
LABEL_30:
            *(_WORD *)v15 = 512;
            snprintf((char *)(v15 + 4), 0x20u, "%s_ipv4", v2);
            snprintf((char *)(v15 + 312), 0x20u, "%s_ipv6", v2);
            v21 = *((unsigned __int8 *)a1 + 32);
            v22 = a1[3];
            *(_BYTE *)(v15 + 291) = v21;
            memcpy((void *)(v15 + 36), v22, v21);
            v23 = *((_DWORD *)a1 + 9);
            v24 = *((unsigned __int8 *)a1 + 33);
            v25 = *((unsigned __int8 *)a1 + 48);
            v26 = a1[5];
            *(_BYTE *)(v15 + 296) = 1;
            *(_BYTE *)(v15 + 308) = 1;
            *(_DWORD *)(v15 + 292) = v23;
            *(_WORD *)(v15 + 310) = v24;
            *(_BYTE *)(v15 + 599) = v25;
            memcpy((void *)(v15 + 344), v26, v25);
            v27 = *((_DWORD *)a1 + 13);
            v28 = *((unsigned __int8 *)a1 + 49);
            *(_BYTE *)(v15 + 604) = 1;
            *(_BYTE *)(v15 + 616) = 1;
            *(_DWORD *)(v15 + 600) = v27;
            *(_WORD *)(v15 + 618) = v28;
            if ( (unsigned int)ipa_add_hdr(v15) )
            {
              printk(&unk_3DFAA9, "ipa_commit_partial_hdr");
              if ( ipa3_get_ipc_logbuf() )
              {
                v58 = ipa3_get_ipc_logbuf();
                ipc_log_string(v58, "ipa_uc_offload %s:%d fail to add partial headers\n", "ipa_commit_partial_hdr", 103);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v59 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v59, "ipa_uc_offload %s:%d fail to add partial headers\n", "ipa_commit_partial_hdr", 103);
              }
              printk(&unk_3C5A7E, "ipa_uc_offload_ntn_reg_intf");
              if ( ipa3_get_ipc_logbuf() )
              {
                v60 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v60,
                  "ipa_uc_offload %s:%d fail to commit partial headers\n",
                  "ipa_uc_offload_ntn_reg_intf",
                  230);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v61 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v61,
                  "ipa_uc_offload %s:%d fail to commit partial headers\n",
                  "ipa_uc_offload_ntn_reg_intf",
                  230);
              }
            }
            else
            {
              LODWORD(v80) = 2;
              v81 = s;
              memset(s, 0, 0x16Cu);
              v29 = *(_QWORD *)(v15 + 4);
              v30 = *(_QWORD *)(v15 + 12);
              s[39] = 49;
              v31 = *((_DWORD *)a1 + 9);
              *(_QWORD *)&s[41] = v29;
              v32 = *(_QWORD *)(v15 + 20);
              *(_QWORD *)&s[43] = v30;
              v33 = *(_QWORD *)(v15 + 28);
              *(_QWORD *)&s[45] = v32;
              s[89] = 49;
              v35 = *(_QWORD *)(v15 + 328);
              v34 = *(_QWORD *)(v15 + 336);
              *(_QWORD *)&s[47] = v33;
              v36 = *((_DWORD *)a1 + 13);
              s[49] = v31;
              *(_QWORD *)&s[95] = v35;
              *(_QWORD *)&s[97] = v34;
              v37 = *(_QWORD *)(v15 + 312);
              v38 = *(_QWORD *)(v15 + 320);
              s[50] = 1;
              s[99] = v36;
              *(_QWORD *)&s[91] = v37;
              *(_QWORD *)&s[93] = v38;
              LODWORD(v78) = 2;
              v79 = v82;
              memset(v82, 0, 0x140u);
              v39 = *((unsigned __int8 *)a1 + 56);
              v82[39] = 48;
              v82[40] = v31;
              if ( v39 )
              {
                v40 = *((_DWORD *)a1 + 15);
                v41 = *((_DWORD *)a1 + 16);
                v82[1] = 0x4000;
                v82[7] = v40;
                v82[8] = v41;
                v82[42] = 0x4000;
                v82[48] = v40;
                v82[49] = v41;
              }
              v42 = *a1;
              v82[41] = 1;
              v82[80] = 48;
              v82[81] = v36;
              if ( !(unsigned int)ipa_register_intf((__int64)v42, (__int64)&v80, (__int64)&v78) )
              {
                v6[5] = *(_DWORD *)(v15 + 300);
                v43 = *(_DWORD *)(v15 + 608);
                v6[18] = 0;
                v6[6] = v43;
                _init_swait_queue_head(v6 + 20, "&x->wait", &init_completion___key_6);
                v6[1] = 1;
                kfree(v15);
                result = 0;
                *a2 = 2;
                goto LABEL_86;
              }
              printk(&unk_3B3716, "ipa_uc_offload_ntn_reg_intf");
              if ( ipa3_get_ipc_logbuf() )
              {
                v62 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v62,
                  "ipa_uc_offload %s:%d fail to add interface prop\n",
                  "ipa_uc_offload_ntn_reg_intf",
                  276);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v63 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v63,
                  "ipa_uc_offload %s:%d fail to add interface prop\n",
                  "ipa_uc_offload_ntn_reg_intf",
                  276);
              }
              memset(v6, 0, 0x130u);
            }
            goto LABEL_81;
          }
          printk(&unk_3B6967, "ipa_uc_offload_ntn_reg_intf");
          if ( ipa3_get_ipc_logbuf() )
          {
            v64 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v64,
              "ipa_uc_offload %s:%d hdr_len shorter than vlan len (%u) (%u)\n",
              "ipa_uc_offload_ntn_reg_intf",
              218,
              *((unsigned __int8 *)a1 + 32),
              *((unsigned __int8 *)a1 + 48));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v65 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v65,
              "ipa_uc_offload %s:%d hdr_len shorter than vlan len (%u) (%u)\n",
              "ipa_uc_offload_ntn_reg_intf",
              218,
              *((unsigned __int8 *)a1 + 32),
              *((unsigned __int8 *)a1 + 48));
          }
        }
        else
        {
          printk(&unk_3D42A0, "ipa_uc_offload_ntn_reg_intf");
          if ( ipa3_get_ipc_logbuf() )
          {
            v56 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v56,
              "ipa_uc_offload %s:%d hdr_type mismatch in vlan mode\n",
              "ipa_uc_offload_ntn_reg_intf",
              204);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v57 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v57,
              "ipa_uc_offload %s:%d hdr_type mismatch in vlan mode\n",
              "ipa_uc_offload_ntn_reg_intf",
              204);
          }
        }
LABEL_81:
        v53 = -14;
LABEL_82:
        kfree(v15);
LABEL_85:
        ((void (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(v6[26]);
        ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(v6[26]);
        result = v53;
        goto LABEL_86;
      }
LABEL_84:
      v53 = -12;
      goto LABEL_85;
    }
    printk(&unk_3B68F3, "ipa_uc_offload_reg_intf");
    if ( ipa3_get_ipc_logbuf() )
    {
      v49 = ipa3_get_ipc_logbuf();
      ipc_log_string(v49, "ipa_uc_offload %s:%d Already Initialized\n", "ipa_uc_offload_reg_intf", 328);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v50 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v50, "ipa_uc_offload %s:%d Already Initialized\n", "ipa_uc_offload_reg_intf", 328);
      result = 4294967274LL;
      goto LABEL_87;
    }
LABEL_49:
    result = 4294967274LL;
    goto LABEL_87;
  }
  v7 = (unsigned int *)_kmalloc_cache_noprof(scnprintf, 3520, 304);
  v6 = v7;
  if ( v7 )
  {
    v8 = *((_DWORD *)a1 + 17);
    if ( v8 > 3 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v67 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &ipa_uc_offload_ntn_reg_intf__alloc_tag;
      v15 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 620);
      *(_QWORD *)(StatusReg + 80) = v67;
      if ( v15 )
        goto LABEL_16;
      goto LABEL_84;
    }
    ipa_uc_offload_ctx[v8] = v7;
    *v7 = v8;
    goto LABEL_8;
  }
  printk(&unk_3D129A, "ipa_uc_offload_reg_intf");
  if ( ipa3_get_ipc_logbuf() )
  {
    v75 = ipa3_get_ipc_logbuf();
    ipc_log_string(v75, "ipa_uc_offload %s:%d fail to alloc uc offload ctx\n", "ipa_uc_offload_reg_intf", 319);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v76 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v76, "ipa_uc_offload %s:%d fail to alloc uc offload ctx\n", "ipa_uc_offload_reg_intf", 319);
  }
  result = 4294967282LL;
LABEL_87:
  _ReadStatusReg(SP_EL0);
  return result;
}
