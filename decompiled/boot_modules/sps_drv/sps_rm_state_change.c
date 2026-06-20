__int64 __fastcall sps_rm_state_change(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v10; // w8
  int v11; // w8
  __int64 v12; // x10
  int v13; // w11
  __int64 *v14; // x20
  int v15; // w11
  int v16; // w11
  int v17; // w11
  int v18; // w11
  __int64 v19; // x11
  __int64 v20; // x12
  __int64 v21; // x11
  __int64 v22; // x12
  __int64 *v23; // x0
  int v24; // w9
  _QWORD *v25; // x0
  int v26; // w10
  __int64 v27; // x8
  int v28; // w8
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x9
  __int64 v32; // x10
  int v33; // w8
  int v34; // w9
  unsigned int v35; // w26
  int v36; // w8
  _QWORD *v37; // x0
  _QWORD *v38; // x0
  __int64 *v39; // x22
  __int64 v40; // x27
  __int64 v41; // x28
  int v42; // w0
  int v43; // w0
  __int64 v44; // x9
  __int64 v45; // x2
  unsigned int v46; // w10
  __int64 v47; // x11
  unsigned int v48; // w12
  unsigned int v49; // w8
  unsigned int v50; // w9
  unsigned __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x3
  unsigned __int64 mem_ptr; // x0
  unsigned int v55; // w0
  unsigned __int64 v56; // x0
  unsigned __int64 v57; // x0
  __int64 v58; // x2
  __int64 *v59; // x1
  __int64 v60; // x0
  unsigned int v61; // w8
  int v62; // w9
  int v63; // w10
  __int64 v64; // x3
  _BOOL4 v65; // w22
  _BOOL4 v66; // w8
  __int64 v67; // x9
  __int64 v68; // x8
  __int64 v69; // x8
  __int64 v70; // x0
  __int64 v71; // x4
  const char *v72; // x1
  __int64 v73; // x21
  __int64 v74; // x8
  unsigned int v75; // w20
  __int64 v76; // x0
  __int64 v77; // x3
  __int64 result; // x0
  int v79; // w9
  __int64 v80; // x9
  __int64 *v81; // x20
  __int64 v82; // x8
  int v83; // w8
  bool v84; // zf
  __int64 **v85; // x8
  __int64 *v86; // x9
  __int64 v87; // x0
  _QWORD *v88; // x3
  __int64 v89; // [xsp+0h] [xbp-40h]
  unsigned __int64 *v90; // [xsp+8h] [xbp-38h]
  unsigned __int64 *v91; // [xsp+10h] [xbp-30h]
  unsigned __int64 *v92; // [xsp+18h] [xbp-28h]
  int v93; // [xsp+28h] [xbp-18h] BYREF
  unsigned __int64 v94; // [xsp+2Ch] [xbp-14h]
  int v95; // [xsp+34h] [xbp-Ch]
  __int64 v96; // [xsp+38h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 16);
  if ( a2 != 22237267 || v10 )
  {
LABEL_158:
    if ( a2 == 39014483 && v10 == 22237267 )
    {
      v61 = *(_DWORD *)(a1 + 84);
      v62 = *(_DWORD *)(a1 + 76);
      v95 = 0;
      v94 = 0;
      v93 = v62;
      if ( v61 != -858993460 )
      {
        v63 = *(_DWORD *)(a1 + 164);
        v94 = __PAIR64__(*(_DWORD *)(a1 + 160), v61);
        v95 = v63;
      }
      if ( (unsigned int)sps_bam_pipe_connect(a1, &v93) )
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_rm_state_change__rs_3, "sps_rm_state_change")) )
        {
          printk(&unk_27E26, "sps_rm_state_change", *(_QWORD *)(a1 + 24));
        }
        v64 = *(_QWORD *)(a1 + 24);
        if ( v64 )
          ipc_log_string(
            *(_QWORD *)(v64 + 552),
            "%s: sps:Failed to connect BAM 0x%pK pipe %d\n",
            "sps_rm_state_change",
            v64,
            *(unsigned int *)(a1 + 188));
        goto LABEL_296;
      }
      v67 = *(_QWORD *)(a1 + 32);
      *(_DWORD *)(a1 + 16) = 39014483;
      if ( (v67 == 0x7FFFFFFFFFFFFFFFLL || *(_QWORD *)(a1 + 56) == 0x7FFFFFFFFFFFFFFFLL)
        && (v68 = *(_QWORD *)(a1 + 176), *(_DWORD *)(v68 + 120)) )
      {
        v65 = 0;
        v66 = *(_QWORD *)(v68 + 104) != 3735928559LL;
      }
      else
      {
        v66 = 0;
        v65 = 0;
      }
    }
    else
    {
      v65 = a2 == 0;
      if ( v10 == 55791699 )
      {
LABEL_188:
        if ( a2 != 72568915 && a2 )
          goto LABEL_209;
        if ( (unsigned int)sps_bam_pipe_disable(
                             *(_QWORD *)(a1 + 24),
                             *(_DWORD *)(a1 + 188),
                             a3,
                             a4,
                             a5,
                             a6,
                             a7,
                             a8,
                             v89,
                             (__int64)v90) )
        {
          if ( logging_option != 1
            && ((unsigned __int8)print_limit_option < 3u
             || (unsigned int)__ratelimit(&sps_rm_state_change__rs_9, "sps_rm_state_change")) )
          {
            printk(&unk_235B2, "sps_rm_state_change", *(_QWORD *)(a1 + 24) + 24LL);
          }
          v69 = *(_QWORD *)(a1 + 24);
          if ( !v69 )
            goto LABEL_296;
          v70 = *(_QWORD *)(v69 + 552);
          v71 = *(unsigned int *)(a1 + 188);
          v72 = "%s: sps:Failed to set BAM %pa pipe %d flow off\n";
          goto LABEL_208;
        }
        *(_DWORD *)(a1 + 16) = 39014483;
        goto LABEL_197;
      }
      if ( v10 != 39014483 )
        goto LABEL_209;
      if ( !a2 || a2 == 72568915 )
      {
LABEL_197:
        if ( v65 )
        {
          v73 = *(_QWORD *)(a1 + 24);
          v74 = 72;
          if ( !*(_DWORD *)(a1 + 76) )
            v74 = 32;
          v75 = *(_DWORD *)(*(_QWORD *)(a1 + 176) + v74);
          if ( *(_DWORD *)(v73 + 44) )
            synchronize_irq();
          v76 = raw_spin_lock_irqsave(v73 + 228);
          *(_BYTE *)(a1 + 640) = 1;
          raw_spin_unlock_irqrestore(v73 + 228, v76);
          if ( (unsigned int)sps_bam_pipe_disconnect(*(_QWORD *)(a1 + 24), v75) )
          {
            if ( logging_option != 1
              && ((unsigned __int8)print_limit_option < 3u
               || (unsigned int)__ratelimit(&sps_rm_state_change__rs_12, "sps_rm_state_change")) )
            {
              printk(&unk_2754D, "sps_rm_state_change", *(_QWORD *)(a1 + 24) + 24LL);
            }
            v69 = *(_QWORD *)(a1 + 24);
            if ( !v69 )
              goto LABEL_296;
            v70 = *(_QWORD *)(v69 + 552);
            v71 = *(unsigned int *)(a1 + 188);
            v72 = "%s: sps:Failed to disconnect BAM %pa pipe %d\n";
LABEL_208:
            v77 = v69 + 24;
            goto LABEL_295;
          }
          v79 = *(_DWORD *)(a1 + 76);
          if ( v79 )
          {
            if ( v79 != 1 )
            {
LABEL_215:
              v81 = *(__int64 **)(a1 + 176);
              mutex_lock(sps_rm + 16);
              if ( *(_DWORD *)(a1 + 76) )
                v82 = 22;
              else
                v82 = 21;
              v81[v82] = 0;
              *(_QWORD *)(a1 + 176) = 0;
              *(_DWORD *)(a1 + 16) = 0;
              sps_rm_free_map_rsrc(v81);
              v83 = *((_DWORD *)v81 + 46) - 1;
              v84 = *((_DWORD *)v81 + 46) == 1;
              *((_DWORD *)v81 + 46) = v83;
              if ( v83 < 0 || v84 )
              {
                if ( v81[21] || v81[22] )
                {
                  if ( logging_option != 1
                    && ((unsigned __int8)print_limit_option < 3u
                     || (unsigned int)__ratelimit(&sps_rm_remove_ref__rs, "sps_rm_remove_ref")) )
                  {
                    printk(&unk_29C3D, "sps_rm_remove_ref", "sps_rm_remove_ref");
                  }
                  if ( sps )
                    ipc_log_string(
                      *(_QWORD *)(sps + 272),
                      "%s: sps:%s:Failed to allocate connection struct\n",
                      "sps_rm_remove_ref",
                      "sps_rm_remove_ref");
                }
                v85 = (__int64 **)v81[1];
                if ( *v85 == v81 && (v86 = (__int64 *)*v81, *(__int64 **)(*v81 + 8) == v81) )
                {
                  v86[1] = (__int64)v85;
                  *v85 = v86;
                }
                else
                {
                  _list_del_entry_valid_or_report(v81);
                }
                *v81 = 0xDEAD000000000100LL;
                v81[1] = 0xDEAD000000000122LL;
                kfree(v81);
              }
              mutex_unlock(sps_rm + 16);
              result = 0;
              *(_QWORD *)(a1 + 176) = 0;
              *(_QWORD *)(a1 + 24) = 0;
              *(_DWORD *)(a1 + 16) = 0;
              goto LABEL_297;
            }
            v80 = 176;
          }
          else
          {
            v80 = 168;
          }
          *(_QWORD *)(*(_QWORD *)(a1 + 176) + v80) = 0;
          goto LABEL_215;
        }
LABEL_209:
        result = 0;
        goto LABEL_297;
      }
      v66 = 0;
    }
    if ( a2 == 55791699 || v66 || (*(_BYTE *)(a1 + 87) & 0x20) != 0 )
    {
      if ( (unsigned int)sps_bam_pipe_enable(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 + 188)) )
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_rm_state_change__rs_6, "sps_rm_state_change")) )
        {
          printk(&unk_297BF, "sps_rm_state_change", *(_QWORD *)(a1 + 24) + 24LL);
        }
        v69 = *(_QWORD *)(a1 + 24);
        if ( !v69 )
          goto LABEL_296;
        v70 = *(_QWORD *)(v69 + 552);
        v71 = *(unsigned int *)(a1 + 188);
        v72 = "%s: sps:Failed to set BAM %pa pipe %d flow on\n";
        goto LABEL_208;
      }
      *(_DWORD *)(a1 + 16) = 55791699;
      goto LABEL_188;
    }
    goto LABEL_197;
  }
  v11 = *(_DWORD *)(a1 + 80);
  if ( *(_DWORD *)(a1 + 168) != -858993460 )
  {
    v12 = *(_QWORD *)(a1 + 56);
    v13 = *(_DWORD *)(a1 + 76);
    memset((void *)(a1 + 40), 204, 136);
    *(_QWORD *)(a1 + 56) = v12;
    *(_DWORD *)(a1 + 76) = v13;
    *(_DWORD *)(a1 + 80) = v11;
  }
  if ( v11 )
  {
    if ( v11 == -858993460 )
    {
      *(_DWORD *)(a1 + 80) = 0;
    }
    else if ( (unsigned int)sps_map_find((_DWORD *)(a1 + 32)) )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_rm_alloc__rs, "sps_rm_alloc")) )
      {
        printk(&unk_2B21F, "sps_rm_alloc", "sps_rm_alloc");
      }
      if ( sps )
        ipc_log_string(
          *(_QWORD *)(sps + 272),
          "%s: sps:%s:Failed to find connection mapping\n",
          "sps_rm_alloc",
          "sps_rm_alloc");
      goto LABEL_290;
    }
  }
  mutex_lock(sps_rm + 16);
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFF) == 0x535053 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_rm_alloc__rs_17, "sps_rm_alloc")) )
    {
      printk(&unk_22FE9, "sps_rm_alloc", "sps_rm_alloc");
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:%s:Client connection already allocated\n",
        "sps_rm_alloc",
        "sps_rm_alloc");
    goto LABEL_289;
  }
  v14 = *(__int64 **)sps_rm;
  if ( *(_QWORD *)sps_rm == sps_rm )
    goto LABEL_50;
  while ( 1 )
  {
    if ( *(_QWORD *)(a1 + 32) != v14[2] )
      goto LABEL_23;
    if ( *(_QWORD *)(a1 + 56) != v14[7] )
      goto LABEL_23;
    v15 = *(_DWORD *)(a1 + 48);
    if ( v15 != -858993460 && v15 != *((_DWORD *)v14 + 8) )
      goto LABEL_23;
    v16 = *(_DWORD *)(a1 + 72);
    if ( v16 != -858993460 && v16 != *((_DWORD *)v14 + 18) )
      goto LABEL_23;
    if ( *(_DWORD *)(a1 + 80) != *((_DWORD *)v14 + 40) )
      goto LABEL_23;
    v17 = *(_DWORD *)(a1 + 112);
    if ( v17 != -858993460 )
    {
      if ( v17 != *((_DWORD *)v14 + 30) )
        goto LABEL_23;
      v19 = *(_QWORD *)(a1 + 96);
      if ( v19 != 0xCCCCCCCCCCCCCCCCLL )
      {
        v20 = *(_QWORD *)(a1 + 88);
        if ( v20 != 0xCCCCCCCCCCCCCCCCLL && (v19 != v14[13] || v20 != v14[12]) )
          goto LABEL_23;
      }
    }
    v18 = *(_DWORD *)(a1 + 144);
    if ( v18 != -858993460 )
    {
      if ( v18 != *((_DWORD *)v14 + 38) )
        goto LABEL_23;
      v21 = *(_QWORD *)(a1 + 128);
      if ( v21 != 0xCCCCCCCCCCCCCCCCLL )
      {
        v22 = *(_QWORD *)(a1 + 120);
        if ( v22 != 0xCCCCCCCCCCCCCCCCLL && (v21 != v14[17] || v22 != v14[16]) )
          goto LABEL_23;
      }
    }
    if ( *(_DWORD *)(a1 + 76) )
      break;
    if ( !v14[21] )
      goto LABEL_48;
LABEL_23:
    v14 = (__int64 *)*v14;
    if ( v14 == (__int64 *)sps_rm )
      goto LABEL_50;
  }
  if ( v14[22] )
    goto LABEL_23;
LABEL_48:
  if ( v14 && !(unsigned int)sps_rm_assign(a1, v14) )
  {
LABEL_157:
    v60 = sps_rm + 16;
    ++*((_DWORD *)v14 + 46);
    mutex_unlock(v60);
    v10 = *(_DWORD *)(a1 + 16);
    goto LABEL_158;
  }
LABEL_50:
  v23 = (__int64 *)_kmalloc_cache_noprof(ioremap_prot, 3520, 216);
  v14 = v23;
  if ( !v23 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_rm_create__rs, "sps_rm_create")) )
    {
      printk(&unk_29C3D, "sps_rm_create", "sps_rm_create");
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:%s:Failed to allocate connection struct\n",
        "sps_rm_create",
        "sps_rm_create");
    goto LABEL_284;
  }
  v23[22] = 0;
  v23[23] = 0;
  v23[20] = 0;
  v23[21] = 0;
  v23[18] = 0;
  v23[19] = 0;
  v24 = *(_DWORD *)(a1 + 112);
  v25 = *(_QWORD **)(a1 + 32);
  v14[14] = 0;
  v14[15] = 0;
  v26 = *(_DWORD *)(a1 + 80);
  v14[16] = 0;
  v14[17] = 0;
  v14[13] = 0;
  v14[24] = 0;
  v14[25] = 3735928559LL;
  v14[13] = 3735928559LL;
  v14[17] = 3735928559LL;
  v14[26] = 3735928559LL;
  *(__int64 *)((char *)v14 + 188) = -1;
  v27 = *(_QWORD *)(a1 + 56);
  v14[10] = 0;
  v14[11] = 0;
  v14[8] = 0;
  v14[9] = 0;
  v14[12] = 0;
  v14[7] = 0;
  v14[7] = v27;
  v28 = *(_DWORD *)(a1 + 144);
  v14[5] = 0;
  v14[6] = 0;
  v14[3] = 0;
  v14[4] = 0;
  *v14 = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[2] = (__int64)v25;
  *((_DWORD *)v14 + 30) = v24;
  *((_DWORD *)v14 + 38) = v28;
  *((_DWORD *)v14 + 40) = v26;
  if ( v24 != -858993460 && *(_QWORD *)(a1 + 96) != 0xCCCCCCCCCCCCCCCCLL && *(_QWORD *)(a1 + 88) != 0xCCCCCCCCCCCCCCCCLL )
  {
    v29 = *(_QWORD *)(a1 + 96);
    v14[12] = *(_QWORD *)(a1 + 88);
    v14[13] = v29;
    v30 = *(_QWORD *)(a1 + 112);
    v14[14] = *(_QWORD *)(a1 + 104);
    v14[15] = v30;
  }
  if ( v28 != -858993460
    && *(_QWORD *)(a1 + 128) != 0xCCCCCCCCCCCCCCCCLL
    && *(_QWORD *)(a1 + 120) != 0xCCCCCCCCCCCCCCCCLL )
  {
    v31 = *(_QWORD *)(a1 + 128);
    v14[16] = *(_QWORD *)(a1 + 120);
    v14[17] = v31;
    v32 = *(_QWORD *)(a1 + 144);
    v14[18] = *(_QWORD *)(a1 + 136);
    v14[19] = v32;
  }
  v33 = *(_DWORD *)(a1 + 48);
  v34 = *(_DWORD *)(a1 + 72);
  v35 = *(_DWORD *)(a1 + 76);
  if ( v33 == -858993460 )
    v33 = -1;
  *((_DWORD *)v14 + 8) = v33;
  if ( v34 == -858993460 )
    v36 = -1;
  else
    v36 = v34;
  *((_DWORD *)v14 + 18) = v36;
  v37 = sps_h2bam(v25);
  v14[6] = (__int64)v37;
  if ( !v37 )
  {
    if ( v14[2] == 0x7FFFFFFFFFFFFFFFLL )
    {
      *((_DWORD *)v14 + 8) = -1;
      if ( (*(_BYTE *)(a1 + 85) & 4) != 0 )
        goto LABEL_71;
LABEL_66:
      v38 = sps_h2bam((_QWORD *)v14[7]);
      v14[11] = (__int64)v38;
      if ( v38 )
        goto LABEL_71;
      if ( v14[7] == 0x7FFFFFFFFFFFFFFFLL )
      {
        *((_DWORD *)v14 + 18) = -1;
        goto LABEL_71;
      }
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(
                                                                        &sps_rm_create__rs_39,
                                                                        "sps_rm_create")) )
      {
        printk(&unk_25F8C, "sps_rm_create", v14 + 7);
      }
      if ( sps )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:Invalid BAM handle: %pK", "sps_rm_create", v14 + 7);
    }
    else
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(
                                                                        &sps_rm_create__rs_36,
                                                                        "sps_rm_create")) )
      {
        printk(&unk_27E55, "sps_rm_create", v14 + 2);
      }
      if ( sps )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:Invalid BAM handle: %pK\n", "sps_rm_create", v14 + 2);
    }
    goto LABEL_243;
  }
  if ( (*(_BYTE *)(a1 + 85) & 4) == 0 )
    goto LABEL_66;
LABEL_71:
  v90 = (unsigned __int64 *)(v14 + 16);
  v91 = (unsigned __int64 *)(v14 + 17);
  v92 = (unsigned __int64 *)(v14 + 13);
  if ( !v35 )
  {
    v41 = v14[6];
    if ( v41 )
    {
LABEL_76:
      v42 = sps_bam_pipe_alloc(v41, *((_DWORD *)v14 + 8));
      *((_DWORD *)v14 + 47) = v42;
      if ( v42 == -1 )
        goto LABEL_243;
      v39 = v14 + 11;
      v40 = v14[11];
      *((_DWORD *)v14 + 8) = v42;
      v14[3] = *(_QWORD *)(v41 + 24);
      *((_DWORD *)v14 + 9) = *(_DWORD *)(v41 + 84);
      if ( v40 )
        goto LABEL_78;
LABEL_80:
      v44 = v14[6];
      if ( v44 )
      {
        v46 = *(_DWORD *)(v44 + 88);
        v45 = *(unsigned int *)(v44 + 92);
      }
      else
      {
        v45 = 0;
        v46 = 0;
      }
      v47 = *v39;
      if ( *v39 )
      {
        v48 = *(_DWORD *)(v47 + 92);
        if ( *(_DWORD *)(v47 + 88) > v46 )
          v46 = *(_DWORD *)(v47 + 88);
        if ( v48 <= (unsigned int)v45 )
          v45 = (unsigned int)v45;
        else
          v45 = v48;
      }
      v49 = *((_DWORD *)v14 + 30);
      if ( v49 == -858993460 )
      {
        v49 = v46;
        *((_DWORD *)v14 + 30) = v46;
      }
      if ( v44 && v47 )
      {
        v50 = *((_DWORD *)v14 + 38);
        if ( v50 == -858993460 )
        {
          *((_DWORD *)v14 + 38) = v45;
          if ( v49 <= 0x10000 )
          {
LABEL_122:
            if ( (unsigned int)v45 >= 0x10000 )
            {
              if ( logging_option == 1 )
                goto LABEL_126;
              if ( (unsigned __int8)print_limit_option >= 3u )
              {
                if ( !(unsigned int)__ratelimit(&sps_rm_create__rs_48, "sps_rm_create") )
                {
LABEL_126:
                  if ( sps )
                    ipc_log_string(
                      *(_QWORD *)(sps + 272),
                      "%s: sps:Invalid data FIFO size: 0x%x\n",
                      "sps_rm_create",
                      *((unsigned int *)v14 + 38));
                  goto LABEL_243;
                }
                v45 = *((unsigned int *)v14 + 38);
              }
              printk(&unk_25FAE, "sps_rm_create", v45);
              goto LABEL_126;
            }
            goto LABEL_128;
          }
        }
        else
        {
          v45 = v50;
          if ( v49 <= 0x10000 )
            goto LABEL_122;
        }
LABEL_117:
        if ( logging_option == 1 )
          goto LABEL_120;
        if ( (unsigned __int8)print_limit_option >= 3u )
        {
          if ( !(unsigned int)__ratelimit(&sps_rm_create__rs_45, "sps_rm_create") )
          {
LABEL_120:
            if ( sps )
              ipc_log_string(
                *(_QWORD *)(sps + 272),
                "%s: sps:Invalid desc FIFO size: 0x%x\n",
                "sps_rm_create",
                *((unsigned int *)v14 + 30));
            goto LABEL_243;
          }
          v49 = *((_DWORD *)v14 + 30);
        }
        printk(&unk_2AC8E, "sps_rm_create", v49);
        goto LABEL_120;
      }
      if ( (*(_BYTE *)(a1 + 85) & 4) != 0 )
      {
        if ( v49 > 0x10000 )
          goto LABEL_117;
      }
      else
      {
        *((_DWORD *)v14 + 38) = 0;
        if ( v49 > 0x10000 )
          goto LABEL_117;
      }
LABEL_128:
      if ( !v49 || *v92 != 3735928559 )
        goto LABEL_137;
      v51 = sps_mem_alloc_io(v49);
      v14[25] = v51;
      if ( v51 == 3735928559 )
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_rm_create__rs_51, "sps_rm_create")) )
        {
          printk(&unk_29F6F, "sps_rm_create", *((unsigned int *)v14 + 30));
        }
        if ( !sps )
          goto LABEL_243;
        v52 = *(_QWORD *)(sps + 272);
        v53 = *((unsigned int *)v14 + 30);
        goto LABEL_145;
      }
      *v92 = v51;
      mem_ptr = spsi_get_mem_ptr(v51);
      v14[12] = mem_ptr;
      if ( !mem_ptr )
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_rm_create__rs_54, "sps_rm_create")) )
        {
          printk(&unk_2361A, "sps_rm_create", v92);
        }
        if ( !sps )
          goto LABEL_243;
        v87 = *(_QWORD *)(sps + 272);
        v88 = v14 + 13;
      }
      else
      {
LABEL_137:
        v55 = *((_DWORD *)v14 + 38);
        if ( !v55 || *v91 != 3735928559 )
          goto LABEL_307;
        v56 = sps_mem_alloc_io(v55);
        v14[26] = v56;
        if ( v56 == 3735928559 )
        {
          if ( logging_option != 1
            && ((unsigned __int8)print_limit_option < 3u
             || (unsigned int)__ratelimit(&sps_rm_create__rs_57, "sps_rm_create")) )
          {
            printk(&unk_29F6F, "sps_rm_create", *((unsigned int *)v14 + 38));
          }
          if ( !sps )
            goto LABEL_243;
          v52 = *(_QWORD *)(sps + 272);
          v53 = *((unsigned int *)v14 + 38);
LABEL_145:
          ipc_log_string(v52, "%s: sps:I/O memory allocation failure:0x%x\n", "sps_rm_create", v53);
          goto LABEL_243;
        }
        *v91 = v56;
        v57 = spsi_get_mem_ptr(v56);
        *v90 = v57;
        if ( v57 )
        {
LABEL_307:
          if ( (unsigned int)sps_rm_assign(a1, v14) )
          {
            if ( logging_option != 1
              && ((unsigned __int8)print_limit_option < 3u
               || (unsigned int)__ratelimit(&sps_rm_create__rs_59, "sps_rm_create")) )
            {
              printk(&unk_22BC3, "sps_rm_create", "sps_rm_create");
            }
            if ( sps )
              ipc_log_string(
                *(_QWORD *)(sps + 272),
                "%s: sps:%s:failed to assign a connection to the client\n",
                "sps_rm_create",
                "sps_rm_create");
            goto LABEL_243;
          }
          v58 = sps_rm;
          v59 = *(__int64 **)(sps_rm + 8);
          if ( v14 == (__int64 *)sps_rm || v59 == v14 || *v59 != sps_rm )
          {
            _list_add_valid_or_report(v14, v59);
          }
          else
          {
            *(_QWORD *)(sps_rm + 8) = v14;
            *v14 = v58;
            v14[1] = (__int64)v59;
            *v59 = (__int64)v14;
          }
          goto LABEL_157;
        }
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_rm_create__rs_58, "sps_rm_create")) )
        {
          printk(&unk_2361A, "sps_rm_create", v91);
        }
        if ( !sps )
          goto LABEL_243;
        v87 = *(_QWORD *)(sps + 272);
        v88 = v14 + 17;
      }
      ipc_log_string(v87, "%s: sps:Cannot get virt addr for I/O buffer:%pa\n", "sps_rm_create", v88);
      goto LABEL_243;
    }
LABEL_82:
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_rm_create__rs_42, "sps_rm_create")) )
    {
      printk(&unk_235E4, "sps_rm_create", v35);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:Invalid BAM endpt: dir %d src %pK dest %pK\n",
        "sps_rm_create",
        v35,
        v14 + 2,
        v14 + 7);
    goto LABEL_243;
  }
  v39 = v14 + 11;
  v40 = v14[11];
  if ( !v40 )
    goto LABEL_82;
  v41 = v14[6];
  if ( v41 )
    goto LABEL_76;
LABEL_78:
  v43 = sps_bam_pipe_alloc(v40, *((_DWORD *)v14 + 18));
  *((_DWORD *)v14 + 48) = v43;
  if ( v43 != -1 )
  {
    *((_DWORD *)v14 + 18) = v43;
    v14[8] = *(_QWORD *)(v40 + 24);
    *((_DWORD *)v14 + 19) = *(_DWORD *)(v40 + 84);
    goto LABEL_80;
  }
LABEL_243:
  sps_rm_free_map_rsrc(v14);
  kfree(v14);
LABEL_284:
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_rm_alloc__rs_20, "sps_rm_alloc")) )
  {
    printk(&unk_23AB8, "sps_rm_alloc", "sps_rm_alloc");
  }
  if ( sps )
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:%s:Failed to allocate connection\n", "sps_rm_alloc", "sps_rm_alloc");
LABEL_289:
  mutex_unlock(sps_rm + 16);
LABEL_290:
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u
     || (unsigned int)__ratelimit(&sps_rm_state_change__rs, "sps_rm_state_change")) )
  {
    printk(&unk_290F6, "sps_rm_state_change", *(_QWORD *)(a1 + 24));
  }
  v77 = *(_QWORD *)(a1 + 24);
  if ( v77 )
  {
    v70 = *(_QWORD *)(v77 + 552);
    v71 = *(unsigned int *)(a1 + 188);
    v72 = "%s: sps:Fail to allocate resource for BAM 0x%pK pipe %d\n";
LABEL_295:
    ipc_log_string(v70, v72, "sps_rm_state_change", v77, v71);
  }
LABEL_296:
  result = 0xFFFFFFFFLL;
LABEL_297:
  _ReadStatusReg(SP_EL0);
  return result;
}
