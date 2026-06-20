__int64 __fastcall ipa3_reset_rt(unsigned int a1, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  char v7; // w1
  __int64 v9; // x9
  int v10; // w24
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x22
  _QWORD *v15; // x23
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  _QWORD *v19; // x20
  __int64 *v20; // x21
  int v21; // w28
  unsigned int v22; // w27
  __int64 *v23; // x22
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  _QWORD *v29; // x27
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 **v36; // x8
  __int64 *v37; // x9
  __int64 v38; // x0
  __int64 v39; // x0
  int v40; // w8
  char v41; // w8
  unsigned int v42; // w21
  _QWORD *v43; // x8
  __int64 v44; // x9
  _QWORD *v45; // x2
  unsigned __int64 v46; // x10
  __int64 v47; // x8
  int v48; // w5
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  _QWORD *v52; // x8
  __int64 v53; // x9
  unsigned __int64 v54; // x10
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  unsigned __int64 v65; // x10
  unsigned __int64 v68; // x10
  unsigned int (__fastcall *v69)(_QWORD); // x8
  unsigned int (__fastcall *v70)(_QWORD); // x8
  __int64 v71; // x8
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // [xsp+8h] [xbp-28h]
  __int64 v75; // [xsp+10h] [xbp-20h]
  __int64 v76; // [xsp+20h] [xbp-10h]
  _QWORD *v77; // [xsp+28h] [xbp-8h]

  if ( a1 < 2 )
  {
    v7 = a2 & 1;
    v9 = 108;
    if ( !a1 )
      v9 = 64;
    v10 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + v9);
    if ( (unsigned int)ipa3_reset_flt(a1, v7) )
    {
      if ( (unsigned int)__ratelimit(&ipa3_reset_rt__rs_83, "ipa3_reset_rt") )
      {
        printk(&unk_3CD188, "ipa3_reset_rt");
        v11 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_19;
      }
      else
      {
        v11 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_19;
      }
      v12 = *(_QWORD *)(v11 + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d fail to reset flt ip=%d\n", "ipa3_reset_rt", 1969, a1);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d fail to reset flt ip=%d\n", "ipa3_reset_rt", 1969, a1);
    }
LABEL_19:
    v14 = ipa3_ctx + 48LL * a1;
    v15 = (_QWORD *)(v14 + 29184);
    mutex_lock(ipa3_ctx + 29472);
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d reset rt ip=%d\n", "ipa3_reset_rt", 1974, a1);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d reset rt ip=%d\n", "ipa3_reset_rt", 1974, a1);
    }
    v19 = (_QWORD *)*v15;
    if ( (_QWORD *)*v15 != v15 )
    {
      v76 = v14 + 29184;
      v74 = v14 + 29280;
      v75 = a1;
      while ( 1 )
      {
        v20 = (__int64 *)v19[3];
        v77 = (_QWORD *)*v19;
        if ( v20 != v19 + 3 )
          break;
        v21 = 0;
LABEL_77:
        if ( !ipa3_id_find(*((unsigned int *)v19 + 52)) )
        {
LABEL_115:
          mutex_unlock(ipa3_ctx + 29472);
          return 4294967282LL;
        }
        if ( *((_DWORD *)v19 + 18) != v10 && ((a2 ^ 1 | v21) & 1) != 0 )
        {
          v41 = *((_BYTE *)v19 + 96);
          v42 = *((_DWORD *)v19 + 52);
          v19[27] = 0;
          if ( (v41 & 1) != 0 || *((_BYTE *)v19 + 97) == 1 )
          {
            v43 = (_QWORD *)v19[1];
            if ( (_QWORD *)*v43 == v19 && (v44 = *v19, *(_QWORD **)(*v19 + 8LL) == v19) )
            {
              *(_QWORD *)(v44 + 8) = v43;
              *v43 = v44;
            }
            else
            {
              _list_del_entry_valid_or_report(v19);
            }
            v45 = *(_QWORD **)v74;
            if ( *(_QWORD *)(*(_QWORD *)v74 + 8LL) != v74 || v19 == (_QWORD *)v74 || v45 == v19 )
            {
              _list_add_valid_or_report(v19, v74);
            }
            else
            {
              v45[1] = v19;
              *v19 = v45;
              v19[1] = v74;
              *(_QWORD *)v74 = v19;
            }
            v46 = *((unsigned int *)v19 + 18);
            v47 = 1LL << v46;
            _X9 = (unsigned __int64 *)(ipa3_ctx + 8 * v75 + 29456 + 8 * (v46 >> 6));
            __asm { PRFM            #0x11, [X9] }
            do
              v65 = __ldxr(_X9);
            while ( __stxr(v65 & ~v47, _X9) );
            v48 = *(_DWORD *)(v76 + 16) - 1;
            *(_DWORD *)(v76 + 16) = v48;
            v49 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v50 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v50 )
              {
                ipc_log_string(
                  v50,
                  "ipa %s:%d rst tbl_idx=%d cnt=%d\n",
                  "ipa3_reset_rt",
                  2063,
                  *((_DWORD *)v19 + 18),
                  v48);
                v49 = ipa3_ctx;
              }
              v51 = *(_QWORD *)(v49 + 34160);
              if ( v51 )
                ipc_log_string(
                  v51,
                  "ipa %s:%d rst tbl_idx=%d cnt=%d\n",
                  "ipa3_reset_rt",
                  2063,
                  *((_DWORD *)v19 + 18),
                  *(_DWORD *)(v76 + 16));
            }
          }
          else
          {
            v52 = (_QWORD *)v19[1];
            if ( (_QWORD *)*v52 == v19 && (v53 = *v19, *(_QWORD **)(*v19 + 8LL) == v19) )
            {
              *(_QWORD *)(v53 + 8) = v52;
              *v52 = v53;
            }
            else
            {
              _list_del_entry_valid_or_report(v19);
            }
            *v19 = 0xDEAD000000000100LL;
            v19[1] = 0xDEAD000000000122LL;
            --*(_DWORD *)(v76 + 16);
            v54 = *((unsigned int *)v19 + 18);
            v55 = 1LL << v54;
            _X9 = (unsigned __int64 *)(ipa3_ctx + 8 * v75 + 29456 + 8 * (v54 >> 6));
            __asm { PRFM            #0x11, [X9] }
            do
              v68 = __ldxr(_X9);
            while ( __stxr(v68 & ~v55, _X9) );
            v57 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v56 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v56 )
              {
                ipc_log_string(
                  v56,
                  "ipa %s:%d rst rt tbl_idx=%d tbl_cnt=%d\n",
                  "ipa3_reset_rt",
                  2070,
                  *((_DWORD *)v19 + 18),
                  *(_DWORD *)(v76 + 16));
                v57 = ipa3_ctx;
              }
              v58 = *(_QWORD *)(v57 + 34160);
              if ( v58 )
              {
                ipc_log_string(
                  v58,
                  "ipa %s:%d rst rt tbl_idx=%d tbl_cnt=%d\n",
                  "ipa3_reset_rt",
                  2070,
                  *((_DWORD *)v19 + 18),
                  *(_DWORD *)(v76 + 16));
                v57 = ipa3_ctx;
              }
            }
            kmem_cache_free(*(_QWORD *)(v57 + 29432), v19);
          }
          ipa3_id_remove(v42);
        }
        v19 = v77;
        if ( v77 == (_QWORD *)v76 )
          goto LABEL_116;
      }
      v21 = 0;
      while ( 1 )
      {
        v23 = (__int64 *)*v20;
        if ( !ipa3_id_find(*((unsigned int *)v20 + 57)) )
          goto LABEL_115;
        if ( *((_BYTE *)v20 + 239) == 1 )
        {
          v24 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v25 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v25 )
            {
              ipc_log_string(
                v25,
                "ipa %s:%d tbl_user %d, tbl-index %d\n",
                "ipa3_reset_rt",
                1988,
                v21 & 1,
                *((_DWORD *)v19 + 52));
              v24 = ipa3_ctx;
            }
            v26 = *(_QWORD *)(v24 + 34160);
            if ( v26 )
              ipc_log_string(
                v26,
                "ipa %s:%d tbl_user %d, tbl-index %d\n",
                "ipa3_reset_rt",
                1988,
                v21 & 1,
                *((_DWORD *)v19 + 52));
          }
          v21 = 1;
        }
        if ( (*((_DWORD *)v19 + 18) != v10 || *((_DWORD *)v19 + 19) != 1)
          && ((a2 & 1) == 0 || *((_BYTE *)v20 + 239) == 1) )
        {
          break;
        }
LABEL_29:
        v20 = v23;
        if ( v23 == v19 + 3 )
          goto LABEL_77;
      }
      if ( v20[26] )
      {
        v27 = ipa3_id_find(*((unsigned int *)v20 + 6));
        if ( v27 && *(_DWORD *)(v27 + 16) == 1468208647 )
          goto LABEL_62;
        if ( (unsigned int)__ratelimit(&ipa3_reset_rt__rs_88, "ipa3_reset_rt") )
          printk(&unk_3B8928, "ipa3_reset_rt");
        v28 = ipa3_ctx;
        v29 = v20 + 26;
        if ( ipa3_ctx )
        {
          v30 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v30 )
          {
            ipc_log_string(v30, "ipa %s:%d Header already deleted\n", "ipa3_reset_rt", 2006);
            v28 = ipa3_ctx;
          }
          v29 = v20 + 26;
          v31 = *(_QWORD *)(v28 + 34160);
          if ( v31 )
          {
            ipc_log_string(v31, "ipa %s:%d Header already deleted\n", "ipa3_reset_rt", 2006);
            v29 = v20 + 26;
          }
        }
LABEL_61:
        *v29 = 0;
LABEL_62:
        --*((_DWORD *)v19 + 19);
        v36 = (__int64 **)v20[1];
        if ( *v36 == v20 && (v37 = (__int64 *)*v20, *(__int64 **)(*v20 + 8) == v20) )
        {
          v37[1] = (__int64)v36;
          *v36 = v37;
        }
        else
        {
          _list_del_entry_valid_or_report(v20);
        }
        v38 = v20[26];
        *v20 = 0xDEAD000000000100LL;
        v20[1] = 0xDEAD000000000122LL;
        if ( v38 && (ipa3_check_idr_if_freed(v38) & 1) == 0 )
        {
          _ipa3_release_hdr(*(unsigned int *)(v20[26] + 340));
        }
        else
        {
          v39 = v20[27];
          if ( v39 && (ipa3_check_idr_if_freed(v39) & 1) == 0 )
            _ipa3_release_hdr_proc_ctx(*(unsigned int *)(v20[27] + 76));
        }
        v40 = *((unsigned __int16 *)v20 + 118);
        *((_DWORD *)v20 + 4) = 0;
        if ( !v40 )
          idr_remove(v19[27], *((unsigned __int16 *)v20 + 117));
        v22 = *((_DWORD *)v20 + 57);
        kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29384), v20);
        ipa3_id_remove(v22);
        goto LABEL_29;
      }
      v29 = v20 + 27;
      if ( !v20[27] )
        goto LABEL_62;
      v32 = ipa3_id_find(*((unsigned int *)v20 + 7));
      if ( v32 )
      {
        if ( *(_DWORD *)(v32 + 16) == 1468208648 )
          goto LABEL_62;
      }
      if ( (unsigned int)__ratelimit(&ipa3_reset_rt__rs_91, "ipa3_reset_rt") )
      {
        printk(&unk_3C47C4, "ipa3_reset_rt");
        v33 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_61;
      }
      else
      {
        v33 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_61;
      }
      v34 = *(_QWORD *)(v33 + 34152);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d Proc entry already deleted\n", "ipa3_reset_rt", 2017);
        v33 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v33 + 34160);
      if ( v35 )
        ipc_log_string(v35, "ipa %s:%d Proc entry already deleted\n", "ipa3_reset_rt", 2017);
      goto LABEL_61;
    }
LABEL_116:
    v69 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 120LL);
    if ( *((_DWORD *)v69 - 1) != 1856640366 )
      __break(0x8228u);
    if ( !v69(0) )
    {
      v70 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 120LL);
      if ( *((_DWORD *)v70 - 1) != 1856640366 )
        __break(0x8228u);
      if ( !v70(1) )
      {
        mutex_unlock(ipa3_ctx + 29472);
        return 0;
      }
    }
    if ( (unsigned int)__ratelimit(&ipa3_reset_rt__rs_96, "ipa3_reset_rt") )
    {
      printk(&unk_3ECA96, "ipa3_reset_rt");
      v71 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_124;
    }
    else
    {
      v71 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_124:
        v72 = *(_QWORD *)(v71 + 34152);
        if ( v72 )
        {
          ipc_log_string(v72, "ipa %s:%d fail to commit rt-rule\n", "ipa3_reset_rt", 2083);
          v71 = ipa3_ctx;
        }
        v73 = *(_QWORD *)(v71 + 34160);
        if ( v73 )
        {
          ipc_log_string(v73, "ipa %s:%d fail to commit rt-rule\n", "ipa3_reset_rt", 2083);
          v71 = ipa3_ctx;
        }
      }
    }
    mutex_unlock(v71 + 29472);
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned int)__ratelimit(&ipa3_reset_rt__rs, "ipa3_reset_rt") )
    printk(&unk_3C3EF1, "ipa3_reset_rt");
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d bad param\n", "ipa3_reset_rt", 1953);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d bad param\n", "ipa3_reset_rt", 1953);
  }
  return 4294967274LL;
}
