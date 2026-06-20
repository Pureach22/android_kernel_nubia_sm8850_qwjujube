__int64 __fastcall ipa_add_socksv5_conn(unsigned __int16 *a1)
{
  int v2; // w12
  _QWORD *v3; // x22
  __int64 v4; // x11
  __int64 v5; // x10
  __int64 v6; // x13
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x12
  __int64 v10; // x13
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x12
  __int64 v14; // x13
  __int64 v15; // x9
  __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x9
  __int64 v19; // x11
  __int64 v20; // x12
  __int64 v21; // x9
  __int64 v22; // x11
  __int64 v23; // x12
  __int64 v24; // x9
  __int64 v25; // x11
  __int64 v26; // x12
  __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x11
  __int64 v30; // x8
  __int64 v31; // x20
  __int64 v32; // x9
  int v33; // w10
  __int64 v34; // x8
  __int64 v35; // x9
  __int64 v36; // x10
  __int64 v37; // x9
  __int64 v38; // x11
  __int64 v39; // x10
  __int64 v40; // x8
  __int64 v41; // x12
  __int64 v42; // x9
  unsigned int v43; // w0
  unsigned int v44; // w19
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  int v49; // w5
  int v50; // w4
  __int64 v51; // x11
  __int64 v52; // x19
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x8
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x8
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x8
  __int64 v80; // x0
  __int64 v81; // x0
  int v83; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v84; // [xsp+8h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83 = 0;
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
  {
    printk(&unk_3A7A91, "ipa_add_socksv5_conn");
    v55 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v56 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v56 )
      {
        ipc_log_string(v56, "ipa %s:%d Not support !\n", "ipa_add_socksv5_conn", 14593);
        v55 = ipa3_ctx;
      }
      v57 = *(_QWORD *)(v55 + 34160);
      if ( v57 )
        ipc_log_string(v57, "ipa %s:%d Not support !\n", "ipa_add_socksv5_conn", 14593);
    }
    v44 = -1;
  }
  else if ( (*(_BYTE *)(ipa3_ctx + 51328) & 1) != 0 )
  {
    if ( a1 )
    {
      mutex_lock(ipa3_ctx + 51336);
      if ( *(int *)(ipa3_ctx + 51384) >= 1000 )
      {
        printk(&unk_3C1CEE, "ipa_add_socksv5_conn");
        v64 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v65 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v65 )
          {
            ipc_log_string(v65, "ipa %s:%d uc act tbl is full!\n", "ipa_add_socksv5_conn", 14611);
            v64 = ipa3_ctx;
          }
          v66 = *(_QWORD *)(v64 + 34160);
          if ( v66 )
            ipc_log_string(v66, "ipa %s:%d uc act tbl is full!\n", "ipa_add_socksv5_conn", 14611);
        }
LABEL_77:
        v44 = -14;
        goto LABEL_84;
      }
      if ( *a1 == 15 && a1[64] == 15 )
      {
        if ( (unsigned int)(*((_DWORD *)a1 + 1) - 4) <= 0xFFFFFFFC )
        {
          printk(&unk_3DC379, "ipa_add_socksv5_conn");
          v70 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v71 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v71 )
            {
              ipc_log_string(
                v71,
                "ipa %s:%d ul cmd_param is not support%d!\n",
                "ipa_add_socksv5_conn",
                14634,
                *((_DWORD *)a1 + 1));
              v70 = ipa3_ctx;
            }
            v72 = *(_QWORD *)(v70 + 34160);
            if ( v72 )
              ipc_log_string(
                v72,
                "ipa %s:%d ul cmd_param is not support%d!\n",
                "ipa_add_socksv5_conn",
                14634,
                *((unsigned int *)a1 + 1));
          }
        }
        else
        {
          if ( (unsigned int)(*((_DWORD *)a1 + 33) - 4) > 0xFFFFFFFC )
          {
            v2 = *((_DWORD *)a1 + 47);
            v3 = (_QWORD *)(*(_QWORD *)(ipa3_ctx + 51304) + ((__int64)*(int *)(ipa3_ctx + 51388) << 7));
            v4 = *(_QWORD *)a1;
            *((_DWORD *)a1 + 15) |= 1u;
            v5 = *((_QWORD *)a1 + 1);
            v6 = *((_QWORD *)a1 + 2);
            *((_DWORD *)a1 + 47) = v2 | 1;
            v7 = *((_QWORD *)a1 + 3);
            v3[1] = v5;
            v3[2] = v6;
            *v3 = v4;
            v8 = *((_QWORD *)a1 + 11);
            v9 = *((_QWORD *)a1 + 8);
            v10 = *((_QWORD *)a1 + 9);
            v3[10] = *((_QWORD *)a1 + 10);
            v3[11] = v8;
            v3[8] = v9;
            v3[9] = v10;
            v12 = *((_QWORD *)a1 + 14);
            v11 = *((_QWORD *)a1 + 15);
            v13 = *((_QWORD *)a1 + 12);
            v14 = *((_QWORD *)a1 + 13);
            v3[3] = v7;
            v3[14] = v12;
            v3[15] = v11;
            v3[12] = v13;
            v3[13] = v14;
            v15 = *((_QWORD *)a1 + 7);
            v16 = *((_QWORD *)a1 + 4);
            v17 = *((_QWORD *)a1 + 5);
            v3[6] = *((_QWORD *)a1 + 6);
            v3[7] = v15;
            v3[4] = v16;
            v3[5] = v17;
            v18 = *((_QWORD *)a1 + 19);
            v19 = *((_QWORD *)a1 + 16);
            v20 = *((_QWORD *)a1 + 17);
            v3[18] = *((_QWORD *)a1 + 18);
            v3[19] = v18;
            v3[16] = v19;
            v3[17] = v20;
            v21 = *((_QWORD *)a1 + 23);
            v22 = *((_QWORD *)a1 + 20);
            v23 = *((_QWORD *)a1 + 21);
            v3[22] = *((_QWORD *)a1 + 22);
            v3[23] = v21;
            v3[20] = v22;
            v3[21] = v23;
            v24 = *((_QWORD *)a1 + 27);
            v25 = *((_QWORD *)a1 + 24);
            v26 = *((_QWORD *)a1 + 25);
            v3[26] = *((_QWORD *)a1 + 26);
            v3[27] = v24;
            v3[24] = v25;
            v3[25] = v26;
            v27 = *((_QWORD *)a1 + 31);
            v29 = *((_QWORD *)a1 + 28);
            v28 = *((_QWORD *)a1 + 29);
            v3[30] = *((_QWORD *)a1 + 30);
            v3[31] = v27;
            v3[28] = v29;
            v3[29] = v28;
            v30 = ipa3_ctx + 49152;
            a1[180] = *(_DWORD *)(ipa3_ctx + 51388);
            *(_DWORD *)(v30 + 2232) += 2;
            v31 = _kmalloc_cache_noprof(of_find_property, 3520, 108);
            if ( !v31 )
            {
              printk(&unk_3EA49C, "ipa_add_socksv5_conn");
              v79 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v80 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v80 )
                {
                  ipc_log_string(
                    v80,
                    "ipa %s:%d socksv5_msg memory allocation failed !\n",
                    "ipa_add_socksv5_conn",
                    14663);
                  v79 = ipa3_ctx;
                }
                v81 = *(_QWORD *)(v79 + 34160);
                if ( v81 )
                  ipc_log_string(
                    v81,
                    "ipa %s:%d socksv5_msg memory allocation failed !\n",
                    "ipa_add_socksv5_conn",
                    14663);
              }
              v44 = -12;
              goto LABEL_84;
            }
            v32 = *((_QWORD *)a1 + 37);
            v33 = *((_DWORD *)a1 + 76);
            *(_QWORD *)(v31 + 32) = *((_QWORD *)a1 + 36);
            *(_QWORD *)(v31 + 40) = v32;
            v34 = *((_QWORD *)a1 + 32);
            v35 = *((_QWORD *)a1 + 33);
            *(_DWORD *)(v31 + 48) = v33;
            *(_QWORD *)v31 = v34;
            *(_QWORD *)(v31 + 8) = v35;
            v36 = *((_QWORD *)a1 + 35);
            *(_QWORD *)(v31 + 16) = *((_QWORD *)a1 + 34);
            *(_QWORD *)(v31 + 24) = v36;
            v37 = *(_QWORD *)(a1 + 158);
            v38 = *(_QWORD *)(a1 + 162);
            *(_QWORD *)(v31 + 52) = *(_QWORD *)(a1 + 154);
            v39 = *(_QWORD *)(a1 + 174);
            v41 = *(_QWORD *)(a1 + 166);
            v40 = *(_QWORD *)(a1 + 170);
            *(_QWORD *)(v31 + 60) = v37;
            LODWORD(v37) = *((_DWORD *)a1 + 89);
            *(_QWORD *)(v31 + 68) = v38;
            *(_QWORD *)(v31 + 84) = v40;
            LOWORD(v40) = a1[180];
            *(_DWORD *)(v31 + 100) = v37;
            v42 = ipa3_ctx;
            *(_QWORD *)(v31 + 92) = v39;
            *(_QWORD *)(v31 + 76) = v41;
            *(_WORD *)(v31 + 104) = v40;
            *(_WORD *)(v31 + 48) = *(_DWORD *)(v42 + 51388);
            LOWORD(v40) = *(_WORD *)(v42 + 51388) + 1;
            v83 = 7077934;
            *(_WORD *)(v31 + 100) = v40;
            v43 = ipa_send_msg((unsigned __int8 *)&v83, (_WORD *)v31, ipa3_socksv5_msg_free_cb);
            if ( !v43 )
            {
              v48 = ipa3_ctx;
              v49 = *(_DWORD *)(ipa3_ctx + 51384);
              if ( v49 <= 999 )
              {
                v50 = *(_DWORD *)(ipa3_ctx + 51388);
                v51 = *(_QWORD *)(ipa3_ctx + 51304);
                while ( 1 )
                {
                  v50 = (v50 + 2) % 1000;
                  *(_DWORD *)(v48 + 51388) = v50;
                  v52 = v51 + ((__int64)v50 << 7);
                  if ( (*(_BYTE *)(v52 + 60) & 1) == 0 )
                    break;
                  if ( (_QWORD *)v52 == v3 )
                    goto LABEL_71;
                }
                if ( v48 )
                {
                  v53 = *(_QWORD *)(v48 + 34152);
                  if ( v53 )
                  {
                    ipc_log_string(
                      v53,
                      "ipa %s:%d next available entry %d, total %d\n",
                      "ipa_add_socksv5_conn",
                      14701,
                      v50,
                      v49);
                    v48 = ipa3_ctx;
                  }
                  v54 = *(_QWORD *)(v48 + 34160);
                  if ( v54 )
                    ipc_log_string(
                      v54,
                      "ipa %s:%d next available entry %d, total %d\n",
                      "ipa_add_socksv5_conn",
                      14701,
                      *(_DWORD *)(v48 + 51388),
                      *(_DWORD *)(v48 + 51384));
                }
                if ( (_QWORD *)v52 == v3 )
                {
LABEL_71:
                  printk(&unk_3B5D7A, "ipa_add_socksv5_conn");
                  v76 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v77 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v77 )
                    {
                      ipc_log_string(v77, "ipa %s:%d can't find available spot!\n", "ipa_add_socksv5_conn", 14708);
                      v76 = ipa3_ctx;
                    }
                    v78 = *(_QWORD *)(v76 + 34160);
                    if ( v78 )
                    {
                      ipc_log_string(v78, "ipa %s:%d can't find available spot!\n", "ipa_add_socksv5_conn", 14708);
                      v76 = ipa3_ctx;
                    }
                  }
                  *(_DWORD *)(v76 + 51384) = 1000;
                  goto LABEL_77;
                }
              }
              v44 = 0;
              goto LABEL_84;
            }
            v44 = v43;
            if ( (unsigned int)__ratelimit(&ipa_add_socksv5_conn__rs, "ipa_add_socksv5_conn") )
            {
              printk(&unk_3A28DF, "ipa_add_socksv5_conn");
              v45 = ipa3_ctx;
              if ( ipa3_ctx )
                goto LABEL_13;
            }
            else
            {
              v45 = ipa3_ctx;
              if ( ipa3_ctx )
              {
LABEL_13:
                v46 = *(_QWORD *)(v45 + 34152);
                if ( v46 )
                {
                  ipc_log_string(v46, "ipa %s:%d ipa_send_msg failed: %d\n", "ipa_add_socksv5_conn", 14681, v44);
                  v45 = ipa3_ctx;
                }
                v47 = *(_QWORD *)(v45 + 34160);
                if ( v47 )
                  ipc_log_string(v47, "ipa %s:%d ipa_send_msg failed: %d\n", "ipa_add_socksv5_conn", 14681, v44);
              }
            }
            kfree(v31);
LABEL_84:
            mutex_unlock(ipa3_ctx + 51336);
            goto LABEL_85;
          }
          printk(&unk_3ADA72, "ipa_add_socksv5_conn");
          v73 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v74 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v74 )
            {
              ipc_log_string(
                v74,
                "ipa %s:%d dl cmd_param is not support%d!\n",
                "ipa_add_socksv5_conn",
                14642,
                *((_DWORD *)a1 + 33));
              v73 = ipa3_ctx;
            }
            v75 = *(_QWORD *)(v73 + 34160);
            if ( v75 )
              ipc_log_string(
                v75,
                "ipa %s:%d dl cmd_param is not support%d!\n",
                "ipa_add_socksv5_conn",
                14642,
                *((unsigned int *)a1 + 33));
          }
        }
      }
      else
      {
        printk(&unk_3BED15, "ipa_add_socksv5_conn");
        v67 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v68 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v68 )
          {
            ipc_log_string(v68, "ipa %s:%d cmd_id not set UL%d DL%d!\n", "ipa_add_socksv5_conn", 14626, *a1, a1[64]);
            v67 = ipa3_ctx;
          }
          v69 = *(_QWORD *)(v67 + 34160);
          if ( v69 )
            ipc_log_string(v69, "ipa %s:%d cmd_id not set UL%d DL%d!\n", "ipa_add_socksv5_conn", 14626, *a1, a1[64]);
        }
      }
      v44 = -22;
      goto LABEL_84;
    }
    printk(&unk_3CA7CE, "ipa_add_socksv5_conn");
    v61 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_68;
    v62 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v62 )
    {
      ipc_log_string(v62, "ipa %s:%d Null info\n", "ipa_add_socksv5_conn", 14603);
      v61 = ipa3_ctx;
    }
    v63 = *(_QWORD *)(v61 + 34160);
    if ( v63 )
    {
      ipc_log_string(v63, "ipa %s:%d Null info\n", "ipa_add_socksv5_conn", 14603);
      v44 = -5;
    }
    else
    {
LABEL_68:
      v44 = -5;
    }
  }
  else
  {
    printk(&unk_3F8EB2, "ipa_add_socksv5_conn");
    v58 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v59 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v59 )
      {
        ipc_log_string(v59, "ipa %s:%d uC act tbl haven't allocated\n", "ipa_add_socksv5_conn", 14598);
        v58 = ipa3_ctx;
      }
      v60 = *(_QWORD *)(v58 + 34160);
      if ( v60 )
        ipc_log_string(v60, "ipa %s:%d uC act tbl haven't allocated\n", "ipa_add_socksv5_conn", 14598);
    }
    v44 = -2;
  }
LABEL_85:
  _ReadStatusReg(SP_EL0);
  return v44;
}
