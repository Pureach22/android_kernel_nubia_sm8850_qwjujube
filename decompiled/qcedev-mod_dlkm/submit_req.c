__int64 __fastcall submit_req(__int64 *a1, __int64 *a2)
{
  __int64 v3; // x20
  unsigned int v4; // w22
  unsigned int v5; // w25
  int v6; // w24
  __int64 *v7; // x23
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 **v10; // x1
  __int64 v11; // x0
  __int64 v12; // x28
  __int64 v13; // x0
  bool v14; // zf
  int v15; // w8
  __int64 v16; // x25
  __int64 v17; // x9
  int v18; // w8
  int v19; // w8
  __int64 v20; // x25
  int v21; // w8
  __int64 v22; // x9
  int v23; // w8
  int v24; // w8
  int v25; // w9
  __int64 v26; // x2
  unsigned int v27; // w10
  int v28; // w9
  __int64 v29; // x25
  __int64 v30; // x1
  __int64 v31; // x8
  int v32; // w10
  int v33; // w10
  int v34; // w9
  _BOOL4 v35; // w8
  int v36; // w9
  int v37; // w10
  __int64 (__fastcall *v38)(__int64, _BYTE *); // x10
  int v39; // w9
  int v40; // w8
  char v41; // w10
  __int64 v42; // x9
  int v43; // w10
  __int64 v44; // x0
  int v45; // w0
  int v46; // w8
  unsigned int v47; // w9
  int v48; // w10
  unsigned int v49; // w9
  __int64 v50; // x0
  int v51; // w0
  int v52; // w8
  __int64 v53; // x9
  int v54; // w10
  int v55; // w8
  int v56; // w10
  int v57; // w8
  int v58; // w9
  int v59; // w9
  int v60; // w8
  int v61; // w8
  __int64 v62; // x0
  int v63; // w0
  int v64; // w8
  unsigned int v65; // w9
  __int64 *v66; // x9
  __int64 **v67; // x8
  __int64 *v68; // x10
  int v69; // w21
  __int64 v70; // x0
  int v71; // w23
  __int64 v72; // x0
  int v73; // w25
  __int64 v74; // x3
  int v75; // w8
  int v76; // w8
  __int64 **v77; // x8
  __int64 *v78; // x9
  char v80; // w8
  unsigned int v81; // w0
  __int64 v82; // x3
  unsigned int v83; // w24
  __int64 v84; // [xsp+0h] [xbp-E0h]
  __int64 v85; // [xsp+8h] [xbp-D8h] BYREF
  char v86; // [xsp+10h] [xbp-D0h]
  __int64 (__fastcall *v87)(__int64, __int64 *, _DWORD *); // [xsp+18h] [xbp-C8h] BYREF
  _QWORD *(__fastcall *v88)(_QWORD *, int, void *); // [xsp+20h] [xbp-C0h]
  __int64 (__fastcall *v89)(__int64, _BYTE *); // [xsp+28h] [xbp-B8h]
  __int64 v90; // [xsp+30h] [xbp-B0h]
  __int64 v91; // [xsp+38h] [xbp-A8h]
  __int64 v92; // [xsp+40h] [xbp-A0h]
  __int64 v93; // [xsp+48h] [xbp-98h]
  __int64 v94; // [xsp+50h] [xbp-90h]
  __int64 v95; // [xsp+58h] [xbp-88h]
  __int64 v96; // [xsp+60h] [xbp-80h]
  __int64 v97; // [xsp+68h] [xbp-78h]
  __int64 v98; // [xsp+70h] [xbp-70h]
  __int64 v99; // [xsp+78h] [xbp-68h]
  __int64 v100; // [xsp+80h] [xbp-60h]
  __int64 v101; // [xsp+88h] [xbp-58h]
  __int64 v102; // [xsp+90h] [xbp-50h]
  unsigned __int64 v103; // [xsp+98h] [xbp-48h]
  __int64 v104; // [xsp+A0h] [xbp-40h]
  __int64 v105; // [xsp+A8h] [xbp-38h]
  __int64 v106; // [xsp+B0h] [xbp-30h]
  __int64 v107; // [xsp+B8h] [xbp-28h]
  __int64 v108; // [xsp+C0h] [xbp-20h]
  __int64 v109; // [xsp+C8h] [xbp-18h]
  __int64 v110; // [xsp+D0h] [xbp-10h]

  v110 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *((_DWORD *)a1 + 228) = 0;
  v3 = *a2;
  v86 = 0;
  v85 = 0;
  _init_waitqueue_head(a1 + 115, "&qcedev_areq->wait_q", &submit_req___key);
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = (__int64 *)(v3 + 248);
  v84 = raw_spin_lock_irqsave(v3 + 272);
  do
  {
    if ( !*(_QWORD *)(v3 + 264) )
    {
      *(_QWORD *)(v3 + 264) = a1;
      v15 = *((_DWORD *)a1 + 12);
      *((_WORD *)a1 + 472) = 2;
      if ( v15 == 2 )
      {
        v20 = *(_QWORD *)(v3 + 264);
        v108 = 0;
        v109 = 0;
        v106 = 0;
        v107 = 0;
        v21 = *(_DWORD *)(v20 + 800);
        v22 = *(_QWORD *)(v20 + 904);
        v104 = 0;
        v105 = 0;
        v102 = 0;
        v103 = 0;
        v100 = 0;
        v101 = 0;
        v98 = 0;
        v99 = 0;
        v96 = 0;
        v97 = 0;
        v94 = 0;
        v95 = 0;
        v92 = 0;
        v93 = 0;
        v90 = 0;
        v91 = 0;
        v88 = nullptr;
        v89 = nullptr;
        v87 = nullptr;
        *(_QWORD *)(v20 + 896) = v22;
        if ( v21 != 2 )
          goto LABEL_3;
        v23 = *(_DWORD *)(v20 + 804);
        LODWORD(v91) = 2;
        if ( v23 )
        {
          if ( v23 == 2 )
          {
            LODWORD(v92) = 2;
            goto LABEL_39;
          }
LABEL_3:
          v6 = -22;
LABEL_4:
          if ( (qce_supports_core_irqs(*(_QWORD *)(v3 + 224)) & 1) != 0 )
            v5 = 1500;
          else
            v5 = 50;
          continue;
        }
LABEL_39:
        v24 = *(unsigned __int8 *)(v20 + 579);
        if ( *(_BYTE *)(v20 + 579) || *(_BYTE *)(v20 + 577) )
        {
          v25 = 0;
        }
        else
        {
          v65 = *(_DWORD *)(v20 + 808) - 1;
          if ( v65 > 4 )
            goto LABEL_3;
          v25 = dword_13878[v65];
        }
        v26 = *(unsigned int *)(v20 + 724);
        HIDWORD(v91) = v25;
        v27 = *(_DWORD *)(v20 + 592);
        v102 = v20 + 600;
        v103 = __PAIR64__(*(_DWORD *)(v20 + 588), v27);
        if ( (unsigned int)(v26 - 2) >= 2 )
        {
          if ( (_DWORD)v26 == 4 )
          {
            LODWORD(v106) = 0;
            v100 = v20 + 728;
            LODWORD(v87) = 0;
          }
          else
          {
            if ( (_DWORD)v26 != 1 )
            {
              printk(&unk_11D1D, "start_offload_cipher_req", v26, v9);
              goto LABEL_3;
            }
            v28 = -1;
LABEL_81:
            LODWORD(v106) = 2;
            HIDWORD(v101) = v28;
            LODWORD(v87) = 1;
          }
          v54 = *(_DWORD *)(v20 + 808);
          LODWORD(v101) = *(_DWORD *)(v20 + 720);
          HIDWORD(v106) = v54;
          if ( v24 )
            BYTE4(v108) = 1;
          v55 = *(_DWORD *)(v20 + 816);
          v88 = qcedev_offload_cipher_req_cb;
          v89 = qcedev_offload_cipher_req_err_cb;
          v56 = *(unsigned __int8 *)(v20 + 578);
          LODWORD(v104) = v55;
          v57 = *(unsigned __int8 *)(v20 + 793);
          v90 = v20 + 816;
          v58 = *(unsigned __int8 *)(v20 + 792);
          LOBYTE(v107) = v56 != 0;
          if ( v56 )
          {
            if ( v58 )
              v59 = 16 * v58 - 15;
            else
              v59 = 1;
            if ( v57 )
              v60 = (v57 << 8) - 256;
            else
              v60 = 0;
            HIDWORD(v107) = v60 | v59 | (*(unsigned __int8 *)(v20 + 794) << 12);
          }
          v61 = *(unsigned __int8 *)(v20 + 576);
          v62 = *(_QWORD *)(v3 + 224);
          BYTE4(v109) = 1;
          LODWORD(v108) = v61;
          v63 = qce_ablk_cipher_req(v62, &v87);
          v4 = v109;
          v6 = v63;
          if ( v63 )
            v64 = -6;
          else
            v64 = 0;
          *(_DWORD *)(v20 + 912) = v64;
          goto LABEL_4;
        }
        v28 = *(_DWORD *)(v20 + 728);
        goto LABEL_81;
      }
      if ( !v15 )
      {
        v16 = *(_QWORD *)(v3 + 264);
        v108 = 0;
        v109 = 0;
        v106 = 0;
        v107 = 0;
        v104 = 0;
        v105 = 0;
        v17 = *(_QWORD *)(v16 + 904);
        v102 = 0;
        v103 = 0;
        v100 = 0;
        v101 = 0;
        v98 = 0;
        v99 = 0;
        v96 = 0;
        v97 = 0;
        v94 = 0;
        v95 = 0;
        v18 = *(unsigned __int8 *)(v16 + 56);
        v92 = 0;
        v93 = 0;
        v90 = 0;
        v91 = 0;
        v88 = nullptr;
        v89 = nullptr;
        v87 = nullptr;
        *(_QWORD *)(v16 + 896) = v17;
        if ( v18 == 1 )
        {
          printk(&unk_11AD8, "start_cipher_req", v8, v9);
          v6 = 0;
          v52 = 0;
          goto LABEL_92;
        }
        v19 = *(_DWORD *)(v16 + 712);
        if ( (unsigned int)(v19 - 1) >= 2 )
        {
          if ( v19 )
            goto LABEL_61;
        }
        else
        {
          LODWORD(v91) = *(_DWORD *)(v16 + 712);
        }
        v33 = *(_DWORD *)(v16 + 716);
        v34 = 0;
        v6 = -22;
        if ( v33 > 2 )
        {
          switch ( v33 )
          {
            case 3:
              v34 = 3;
              break;
            case 5:
              break;
            case 6:
              goto LABEL_65;
            default:
              goto LABEL_93;
          }
        }
        else if ( v33 )
        {
          if ( v33 != 1 )
          {
            if ( v33 == 2 )
            {
              LODWORD(v92) = 2;
              if ( v19 == 2 )
              {
                v35 = 0;
                goto LABEL_85;
              }
LABEL_84:
              v35 = *(_DWORD *)(v16 + 720) != 1;
LABEL_85:
              v47 = *(_DWORD *)(v16 + 704);
              HIDWORD(v91) = v35;
              v48 = *(_DWORD *)(v16 + 816);
              v102 = v16 + 672;
              v103 = v47;
              v49 = *(_DWORD *)(v16 + 668);
              v100 = v16 + 601;
              v101 = v49;
              LODWORD(v104) = v48;
              if ( v49 )
              {
LABEL_86:
                LODWORD(v87) = 0;
LABEL_89:
                v50 = *(_QWORD *)(v3 + 224);
                v88 = qcedev_cipher_req_cb;
                v89 = nullptr;
                v90 = v16 + 816;
                v106 = 0;
                v51 = qce_ablk_cipher_req(v50, &v87);
                v4 = v109;
                v6 = v51;
                if ( v51 )
                  v52 = -6;
                else
                  v52 = 0;
              }
              else
              {
                if ( (*(_DWORD *)(v16 + 720) & 0xFFFFFFFE) == 2 )
                {
                  LODWORD(v87) = 1;
                  goto LABEL_89;
                }
                v53 = 0;
                while ( !*(_BYTE *)(v16 + 601 + v53) )
                {
                  if ( ++v53 == 64 )
                  {
                    if ( *(_DWORD *)(v3 + 8) == 1 )
                      goto LABEL_86;
                    break;
                  }
                }
                v52 = -6;
                v6 = -22;
              }
LABEL_92:
              *(_DWORD *)(v16 + 912) = v52;
            }
LABEL_93:
            v5 = 1500;
            continue;
          }
LABEL_65:
          v34 = 1;
        }
        LODWORD(v92) = v34;
        goto LABEL_84;
      }
      v29 = *(_QWORD *)(v3 + 264);
      v97 = 0;
      v98 = 0;
      v95 = 0;
      v96 = 0;
      v30 = *(unsigned int *)(v29 + 372);
      v31 = *(_QWORD *)(v29 + 904);
      v93 = 0;
      v94 = 0;
      v91 = 0;
      v92 = 0;
      v89 = nullptr;
      v90 = 0;
      v87 = nullptr;
      v88 = nullptr;
      if ( (int)v30 <= 1 )
      {
        if ( (_DWORD)v30 )
        {
          if ( (_DWORD)v30 != 1 )
          {
LABEL_60:
            printk(&unk_12564, v30, v8, v9);
LABEL_61:
            v6 = -22;
            v5 = 1500;
            continue;
          }
          goto LABEL_71;
        }
      }
      else
      {
        if ( (_DWORD)v30 != 2 )
        {
          if ( (_DWORD)v30 != 3 )
          {
            if ( (_DWORD)v30 != 4 )
              goto LABEL_60;
            v32 = *(_DWORD *)(v29 + 368);
            *(_QWORD *)(v29 + 896) = v31;
            LODWORD(v88) = 4;
            v94 = v31 + 130;
            LODWORD(v95) = v32;
            v87 = qcedev_sha_req_cb;
            goto LABEL_76;
          }
          if ( *(_BYTE *)(v3 + 27) == 1 )
          {
            LODWORD(v88) = 3;
            goto LABEL_70;
          }
LABEL_71:
          LODWORD(v88) = 1;
          goto LABEL_72;
        }
        if ( *(_BYTE *)(v3 + 27) == 1 )
        {
          LODWORD(v88) = 2;
LABEL_70:
          v94 = v31 + 130;
          LODWORD(v95) = 64;
        }
      }
LABEL_72:
      *(_QWORD *)(v29 + 896) = v31;
      v36 = *(_DWORD *)(v31 + 8);
      v87 = qcedev_sha_req_cb;
      v37 = *(unsigned __int8 *)(v31 + 128);
      LODWORD(v91) = v36;
      v14 = v37 == 0;
      v38 = (__int64 (__fastcall *)(__int64, _BYTE *))(v31 + 24);
      HIDWORD(v91) = *(_DWORD *)(v31 + 12);
      LODWORD(v92) = *(_DWORD *)(v31 + 16);
      v39 = *(unsigned __int8 *)(v31 + 129);
      v40 = *(_DWORD *)(v31 + 20);
      v89 = v38;
      v41 = !v14;
      BYTE4(v95) = v41;
      HIDWORD(v92) = v40;
      BYTE5(v95) = v39 != 0;
LABEL_76:
      v42 = *(_QWORD *)(v29 + 872);
      v43 = *(_DWORD *)(v29 + 864);
      v44 = *(_QWORD *)(v3 + 224);
      LODWORD(v98) = 0;
      v97 = v29 + 816;
      v90 = v42;
      LODWORD(v96) = v43;
      LODWORD(v93) = 0;
      v45 = qce_process_sha_req(v44, &v87);
      v4 = HIDWORD(v98);
      v6 = v45;
      if ( v45 )
        v46 = -6;
      else
        v46 = 0;
      *(_DWORD *)(v29 + 912) = v46;
      v5 = 1500;
      continue;
    }
    v10 = *(__int64 ***)(v3 + 256);
    if ( v7 == a1 || v10 == (__int64 **)a1 || *v10 != v7 )
    {
      _list_add_valid_or_report(a1, v10, v3 + 248);
    }
    else
    {
      *(_QWORD *)(v3 + 256) = a1;
      *a1 = (__int64)v7;
      a1[1] = (__int64)v10;
      *v10 = a1;
    }
    *((_WORD *)a1 + 472) = 1;
    v90 = 0;
    v91 = 0;
    v88 = nullptr;
    v89 = nullptr;
    v87 = nullptr;
    init_wait_entry(&v87, 0);
    v11 = prepare_to_wait_event(a1 + 115, &v87, 1);
    if ( *((_WORD *)a1 + 472) )
    {
      v8 = v11;
      v12 = 1250;
      while ( !v8 )
      {
        raw_spin_unlock_irq(v3 + 272);
        v12 = schedule_timeout(v12);
        raw_spin_lock_irq(v3 + 272);
        v13 = prepare_to_wait_event(a1 + 115, &v87, 1);
        if ( v12 )
          v14 = 0;
        else
          v14 = *((unsigned __int16 *)a1 + 472) == 0;
        if ( v14 )
          v12 = 1;
        if ( *((_WORD *)a1 + 472) )
        {
          v8 = v13;
          if ( v12 )
            continue;
        }
        goto LABEL_31;
      }
    }
    else
    {
      v12 = 1250;
LABEL_31:
      finish_wait(a1 + 115, &v87);
      v8 = v12;
    }
    if ( !(_DWORD)v8 || (_DWORD)v8 == -512 )
    {
      printk(&unk_11A2B, "submit_req", v8, v9);
      v77 = (__int64 **)a1[1];
      if ( *v77 == a1 && (v78 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
      {
        v78[1] = (__int64)v77;
        *v77 = v78;
      }
      else
      {
        _list_del_entry_valid_or_report(a1);
      }
      *a1 = 0xDEAD000000000100LL;
      a1[1] = 0xDEAD000000000122LL;
      *(_QWORD *)(v3 + 264) = 0;
      raw_spin_unlock_irqrestore(v3 + 272, v84);
      goto LABEL_149;
    }
  }
  while ( *((_WORD *)a1 + 472) != 2 );
  if ( v6 )
  {
    *(_QWORD *)(v3 + 264) = 0;
    v66 = *(__int64 **)(v3 + 248);
    if ( v66 != v7 )
    {
      v67 = (__int64 **)v66[1];
      if ( *v67 == v66 && (v68 = (__int64 *)*v66, *(__int64 **)(*v66 + 8) == v66) )
      {
        v68[1] = (__int64)v67;
        *v67 = v68;
      }
      else
      {
        _list_del_entry_valid_or_report(*(_QWORD *)(v3 + 248));
      }
      *((_WORD *)v66 + 472) = 0;
      *v66 = 0xDEAD000000000100LL;
      v66[1] = 0xDEAD000000000122LL;
      _wake_up(v66 + 115, 1, 1, 0);
    }
    raw_spin_unlock_irqrestore(v3 + 272, v84);
    v69 = 1500;
    *((_BYTE *)a1 + 946) = 0;
LABEL_126:
    if ( *((_BYTE *)a1 + 947) == 1 )
    {
      v71 = 0;
      goto LABEL_129;
    }
    goto LABEL_130;
  }
  raw_spin_unlock_irqrestore(v3 + 272, v84);
  *((_BYTE *)a1 + 946) = 0;
  v70 = _msecs_to_jiffies(v5);
  v69 = wait_for_completion_timeout(a1 + 2, v70);
  if ( v69 )
    goto LABEL_126;
  v69 = 0;
  v71 = 1;
LABEL_129:
  v72 = raw_spin_lock_irqsave(v3 + 272);
  v73 = *((unsigned __int16 *)a1 + 472);
  raw_spin_unlock_irqrestore(v3 + 272, v72);
  if ( v73 == 3 )
  {
LABEL_130:
    if ( v6 )
      goto LABEL_131;
  }
  else
  {
    if ( v71 )
    {
      *((_BYTE *)a1 + 946) = 1;
      printk(&unk_12955, "submit_req", v4, v74);
      qce_get_crypto_status(*(_QWORD *)(v3 + 224), &v85);
      v80 = BYTE1(v85);
      *((_DWORD *)a1 + 203) = 0;
      if ( (v80 & 1) != 0 )
      {
        *((_DWORD *)a1 + 203) = 2;
      }
      else if ( (v85 & 0x10000) != 0 )
      {
        *((_DWORD *)a1 + 203) = 3;
      }
      else if ( (v85 & 0x1000000) != 0 )
      {
        *((_DWORD *)a1 + 203) = 1;
      }
      else if ( (v85 & 0x100000000LL) != 0 )
      {
        *((_DWORD *)a1 + 203) = 4;
      }
      else if ( (v85 & 0x1000000000000LL) != 0 )
      {
        *((_DWORD *)a1 + 203) = 6;
      }
      else if ( (v86 & 1) != 0 )
      {
        *((_DWORD *)a1 + 203) = 7;
      }
      else if ( (v85 & 0x100000000000000LL) != 0 )
      {
        *((_DWORD *)a1 + 203) = 8;
      }
      else if ( BYTE5(v85) == 1 )
      {
        *((_DWORD *)a1 + 203) = 5;
      }
    }
    else
    {
      v81 = jiffies_to_msecs(v69);
      printk(&unk_11A53, "submit_req", v4, v81);
    }
    v83 = qce_manage_timeout(*(_QWORD *)(v3 + 224), v4);
    if ( v83 )
      printk(&unk_12219, "submit_req", v83, v82);
    req_done(v3);
    if ( v83 )
LABEL_131:
      *((_DWORD *)a1 + 228) = -5;
  }
  v75 = *((_DWORD *)a1 + 12);
  if ( v75 != 2 )
  {
    if ( v75 )
    {
      if ( *((_DWORD *)a1 + 228) )
        ++HIDWORD(qword_132C0);
      else
        LODWORD(qword_132C0) = qword_132C0 + 1;
    }
    else
    {
      v76 = *((_DWORD *)a1 + 180);
      if ( v76 == 1 )
      {
        if ( *((_DWORD *)a1 + 228) )
          ++HIDWORD(qword_132B8);
        else
          LODWORD(qword_132B8) = qword_132B8 + 1;
      }
      else if ( !v76 )
      {
        if ( *((_DWORD *)a1 + 228) )
          ++HIDWORD(qcedev_stat);
        else
          LODWORD(qcedev_stat) = qcedev_stat + 1;
      }
    }
  }
LABEL_149:
  _ReadStatusReg(SP_EL0);
  return *((unsigned int *)a1 + 228);
}
