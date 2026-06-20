int *__fastcall ipa3_replenish_rx_page_recycle(int *result)
{
  int v1; // w8
  int v2; // w9
  int *v3; // x19
  int v4; // w8
  unsigned int v5; // w10
  __int64 v6; // x11
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x9
  unsigned int v11; // w26
  unsigned int v12; // w22
  __int64 v13; // x28
  __int64 v14; // x8
  int v15; // w20
  _QWORD *v16; // x8
  _QWORD *v17; // x25
  __int64 v18; // x9
  __int64 v19; // x12
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x8
  _QWORD *v27; // x8
  _QWORD *v28; // x10
  __int64 v29; // x8
  _QWORD *v30; // x8
  __int64 v31; // x10
  __int16 v32; // w9
  int v33; // w9
  unsigned int v34; // w8
  __int64 v35; // x9
  int v36; // w0
  unsigned __int64 v42; // x9
  unsigned int v45; // w10
  unsigned int v47; // w9
  int *v48; // x9
  _DWORD *v49; // x10
  _DWORD *v50; // x8
  unsigned int v51; // w11
  int v52; // w12
  unsigned int v53; // w10
  unsigned int v54; // w11
  _DWORD *v55; // x9
  unsigned int v56; // w10
  int v57; // w11
  unsigned int v58; // w9
  unsigned int v59; // w10
  int v60; // w8
  int v61; // w8
  __int64 v62; // x9
  __int64 v63; // x8
  _BYTE *v64; // x8
  __int64 v66; // x8
  __int64 v68; // x8
  int v70; // w8
  _BYTE *v71; // x8
  int v75; // w20
  __int64 v76; // x0
  __int64 v77; // x8
  __int64 v78; // x0
  int v79; // w20
  __int64 v80; // x0
  __int64 v81; // x8
  __int64 v82; // x0
  unsigned int v84; // w9
  unsigned int v86; // w9
  unsigned int v88; // w9
  unsigned int v90; // w9
  unsigned int v92; // w9
  unsigned int v94; // w9
  __int64 v95; // [xsp+18h] [xbp-388h]
  __int64 v96; // [xsp+20h] [xbp-380h]
  int v97; // [xsp+2Ch] [xbp-374h] BYREF
  _QWORD s[110]; // [xsp+30h] [xbp-370h] BYREF

  s[108] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = result[41];
  v2 = *result;
  v97 = 0;
  if ( (unsigned int)(v1 - v2) < 0x14 )
    goto LABEL_118;
  v3 = result;
  memset(s, 0, 0x360u);
  v4 = *(_DWORD *)(*((_QWORD *)v3 + 203) + 4LL);
  if ( v4 != 121 )
  {
    if ( v4 != 95 )
    {
      if ( v4 == 35 )
      {
        v5 = 1;
LABEL_15:
        v6 = 7;
        goto LABEL_16;
      }
      if ( (unsigned int)__ratelimit(&ipa3_replenish_rx_page_recycle__rs, "ipa3_replenish_rx_page_recycle") )
        printk(&unk_3F204D, "ipa3_replenish_rx_page_recycle");
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(
            v8,
            "ipa %s:%d Unexpected client%d\n",
            "ipa3_replenish_rx_page_recycle",
            3068,
            *(_DWORD *)(*((_QWORD *)v3 + 203) + 4LL));
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
          ipc_log_string(
            v9,
            "ipa %s:%d Unexpected client%d\n",
            "ipa3_replenish_rx_page_recycle",
            3068,
            *(_DWORD *)(*((_QWORD *)v3 + 203) + 4LL));
      }
    }
    v5 = 0;
    goto LABEL_15;
  }
  v5 = 2;
  v6 = 8;
LABEL_16:
  v10 = *((_QWORD *)v3 + 46);
  v97 = *v3;
  v11 = *(_DWORD *)(v10 + 8);
  if ( v97 >= (unsigned int)v3[41] )
  {
    v12 = 0;
    goto LABEL_63;
  }
  v12 = 0;
  v13 = v5;
  v95 = v6;
  v96 = 240LL * v5 + 33096;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v14 = *((_QWORD *)v3 + 243);
    if ( *(_DWORD *)(v14 + 1612) )
    {
      v15 = *(unsigned __int8 *)(ipa3_ctx + 51103);
      raw_spin_lock_bh(v14 + 1684);
      v16 = *((_QWORD **)v3 + 223);
      v17 = (_QWORD *)*v16;
      if ( (_QWORD *)*v16 == v16 || !v15 )
      {
LABEL_27:
        raw_spin_unlock_bh(*((_QWORD *)v3 + 243) + 1684LL);
        v21 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v22 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v22 )
          {
            ipc_log_string(
              v22,
              "ipa %s:%d napi_sort_page_thrshld_cnt = %d ipa_max_napi_sort_page_thrshld = %d\n",
              "ipa3_get_free_page",
              2969,
              *(_DWORD *)(*((_QWORD *)v3 + 243) + 1616LL),
              *(_DWORD *)(ipa3_ctx + 51396));
            v21 = ipa3_ctx;
          }
        }
        v23 = *((_QWORD *)v3 + 243);
        if ( *(_DWORD *)(v23 + 1616) >= *(_DWORD *)(v21 + 51396) )
        {
          *(_DWORD *)(v23 + 1612) = 0;
          v24 = *((_QWORD *)v3 + 243);
          _X10 = (unsigned __int64 *)(v24 + 1912);
          __asm { PRFM            #0x11, [X10] }
          do
            v42 = __ldxr(_X10);
          while ( __stlxr(v42 | 1, _X10) );
          __dmb(0xBu);
          if ( (v42 & 1) == 0 )
            _tasklet_schedule(v24 + 1904);
          ++*(_QWORD *)(ipa3_ctx + 8 * v13 + 34096);
          raw_spin_lock(ipa3_ctx + 51256);
          v25 = ipa3_ctx;
          if ( *(_BYTE *)(ipa3_ctx + 51288) == 1 && (*(_BYTE *)(ipa3_ctx + 51295) & 1) == 0 )
          {
            _X8 = (unsigned int *)(ipa3_ctx + 33840);
            __asm { PRFM            #0x11, [X8] }
            do
              v47 = __ldxr(_X8);
            while ( __stxr(v47 + 1, _X8) );
            raw_notifier_call_chain(*(_QWORD *)(ipa3_ctx + 51264), v95, *((_QWORD *)v3 + 243) + 1616LL);
            v25 = ipa3_ctx;
            *(_BYTE *)(ipa3_ctx + 51295) = 1;
          }
          raw_spin_unlock(v25 + 51256);
        }
      }
      else
      {
        v18 = 0;
        while ( 1 )
        {
          v19 = v17[2];
          if ( *(_DWORD *)(v19 + 52) == 1 )
            break;
          if ( (_QWORD *)*v17 != v16 )
          {
            _ZF = v15 - 1 == (_DWORD)v18++;
            v17 = (_QWORD *)*v17;
            if ( !_ZF )
              continue;
          }
          goto LABEL_27;
        }
        _X8 = (unsigned int *)(v19 + 52);
        __asm { PRFM            #0x11, [X8] }
        do
          v45 = __ldxr(_X8);
        while ( __stxr(v45 + 1, _X8) );
        v27 = (_QWORD *)v17[1];
        if ( (_QWORD *)*v27 == v17 && (v28 = (_QWORD *)*v17, *(_QWORD **)(*v17 + 8LL) == v17) )
        {
          v28[1] = v27;
          *v27 = v28;
        }
        else
        {
          _list_del_entry_valid_or_report(v17);
        }
        *v17 = v17;
        v17[1] = v17;
        if ( (unsigned int)v18 >= 0x1F )
LABEL_131:
          __break(0x5512u);
        ++*(_QWORD *)(ipa3_ctx + v96 + 8 * v18);
        *(_DWORD *)(*((_QWORD *)v3 + 243) + 1616LL) = 0;
        raw_spin_unlock_bh(*((_QWORD *)v3 + 243) + 1684LL);
        if ( v17 )
        {
          ++*(_QWORD *)(ipa3_ctx + 24LL * (unsigned int)v13 + 32920);
          goto LABEL_48;
        }
      }
    }
    if ( v11 == *(_DWORD *)(*((_QWORD *)v3 + 46) + 12LL) )
      goto LABEL_63;
    ++*(_QWORD *)(ipa3_ctx + 24LL * (unsigned int)v13 + 32928);
    v29 = *((_QWORD *)v3 + 46);
    v17 = *(_QWORD **)(*(_QWORD *)v29 + 8LL * v11);
    if ( v11 + 1 == *(_DWORD *)(v29 + 16) )
      v11 = 0;
    else
      ++v11;
LABEL_48:
    v17[10] = v3;
    if ( (*(_BYTE *)(*(_QWORD *)(ipa3_ctx + 34216) + 844LL) & 0x40) == 0 )
      _dma_sync_single_for_device();
    if ( v12 > 0x23 )
      goto LABEL_131;
    v30 = &s[3 * v12++];
    v31 = ipa3_ctx + 24LL * (unsigned int)v13;
    *v30 = v17[3];
    v32 = *((_DWORD *)v17 + 10);
    v30[2] = v17;
    *((_WORD *)v30 + 5) = 1792;
    *((_WORD *)v30 + 4) = v32;
    v33 = v97;
    *((_DWORD *)v30 + 3) = 0;
    v34 = v33 + 1;
    v35 = *(_QWORD *)(v31 + 32912);
    v97 = v34;
    *(_QWORD *)(v31 + 32912) = v35 + 1;
    if ( v12 == 36 )
      break;
LABEL_18:
    if ( v34 >= v3[41] )
      goto LABEL_63;
  }
  v36 = gsi_queue_xfer(*(_QWORD *)(*((_QWORD *)v3 + 203) + 8LL), 36, s, 0);
  if ( !v36 )
  {
    v34 = v97;
    v12 = 0;
    goto LABEL_18;
  }
  v79 = v36;
  v80 = printk(&unk_3D5757, "ipa3_replenish_rx_page_recycle");
  v81 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v82 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v82 )
    {
      ipc_log_string(v82, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_replenish_rx_page_recycle", 3121, v79);
      v81 = ipa3_ctx;
    }
    v80 = *(_QWORD *)(v81 + 34160);
    if ( v80 )
      v80 = ipc_log_string(v80, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_replenish_rx_page_recycle", 3121, v79);
  }
  ((void (__fastcall *)(__int64))ipa_assert)(v80);
  v12 = 36;
LABEL_63:
  result = (int *)gsi_queue_xfer(*(_QWORD *)(*((_QWORD *)v3 + 203) + 8LL), v12, s, 1);
  if ( (_DWORD)result )
  {
    v75 = (int)result;
    v76 = printk(&unk_3D5757, "ipa3_replenish_rx_page_recycle");
    v77 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v78 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v78 )
      {
        ipc_log_string(v78, "ipa %s:%d failed to provide buffer: %d\n", "ipa3_replenish_rx_page_recycle", 3138, v75);
        v77 = ipa3_ctx;
      }
      v76 = *(_QWORD *)(v77 + 34160);
      if ( v76 )
        v76 = ipc_log_string(
                v76,
                "ipa %s:%d failed to provide buffer: %d\n",
                "ipa3_replenish_rx_page_recycle",
                3138,
                v75);
    }
    result = (int *)((__int64 (__fastcall *)(__int64))ipa_assert)(v76);
  }
  else
  {
    __dsb(0xFu);
    *(_DWORD *)(*((_QWORD *)v3 + 46) + 8LL) = v11;
    *v3 = v97;
  }
  if ( *((_BYTE *)v3 + 1609) == 1 )
  {
    v48 = *((int **)v3 + 243);
    v49 = *((_DWORD **)v48 + 46);
    v50 = v49 + 5;
    if ( v49[5] )
      goto LABEL_82;
    if ( ((v51 = v49[4], v52 = *(_DWORD *)(*((_QWORD *)v48 + 203) + 4LL), v53 = (v49[3] - v49[2]) % v51, v52 == 95)
       || v52 == 35)
      && *(_BYTE *)(ipa3_ctx + 45386) == 1 )
    {
      v54 = *(_DWORD *)(ipa3_ctx + 48792) / 2;
    }
    else
    {
      v54 = v51 >> 1;
    }
    if ( v53 >= v54 )
      goto LABEL_82;
LABEL_81:
    *v50 = 1;
    result = (int *)queue_work_on(32, *((_QWORD *)v48 + 220), v48 + 82);
    goto LABEL_82;
  }
  v55 = *((_DWORD **)v3 + 46);
  v50 = v55 + 5;
  if ( !v55[5] )
  {
    if ( ((v56 = v55[4], v57 = *(_DWORD *)(*((_QWORD *)v3 + 203) + 4LL), v58 = (v55[3] - v55[2]) % v56, v57 == 95)
       || v57 == 35)
      && *(_BYTE *)(ipa3_ctx + 45386) == 1 )
    {
      v59 = *(_DWORD *)(ipa3_ctx + 48792) / 2;
    }
    else
    {
      v59 = v56 >> 1;
    }
    _CF = v58 >= v59;
    v48 = v3;
    if ( !_CF )
      goto LABEL_81;
  }
LABEL_82:
  v60 = v97;
  if ( v97 > 32 )
    goto LABEL_104;
  v61 = *(_DWORD *)(*((_QWORD *)v3 + 203) + 4LL);
  if ( v61 <= 94 )
  {
    if ( v61 == 33 )
    {
      v62 = 32860;
LABEL_101:
      ++*(_DWORD *)(ipa3_ctx + v62);
      goto LABEL_103;
    }
    if ( v61 != 35 )
      goto LABEL_102;
    v63 = ipa3_ctx;
    ++*(_DWORD *)(ipa3_ctx + 32840);
    raw_spin_lock(v63 + 51256);
    v64 = (_BYTE *)ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 51288) == 1 && (*(_BYTE *)(ipa3_ctx + 51292) & 1) == 0 )
    {
      _X8 = (unsigned int *)(ipa3_ctx + 33824);
      __asm { PRFM            #0x11, [X8] }
      do
        v90 = __ldxr(_X8);
      while ( __stxr(v90 + 1, _X8) );
      raw_notifier_call_chain(*(_QWORD *)(ipa3_ctx + 51264), 3, &v97);
      v64 = (_BYTE *)ipa3_ctx;
      *(_BYTE *)(ipa3_ctx + 51289) = 0;
      v64[51292] = 1;
    }
LABEL_99:
    result = (int *)raw_spin_unlock(v64 + 51256);
    goto LABEL_103;
  }
  switch ( v61 )
  {
    case '_':
      v66 = ipa3_ctx;
      ++*(_DWORD *)(ipa3_ctx + 32844);
      raw_spin_lock(v66 + 51256);
      v64 = (_BYTE *)ipa3_ctx;
      if ( *(_BYTE *)(ipa3_ctx + 51288) == 1 && (*(_BYTE *)(ipa3_ctx + 51293) & 1) == 0 )
      {
        _X8 = (unsigned int *)(ipa3_ctx + 33828);
        __asm { PRFM            #0x11, [X8] }
        do
          v92 = __ldxr(_X8);
        while ( __stxr(v92 + 1, _X8) );
        raw_notifier_call_chain(*(_QWORD *)(ipa3_ctx + 51264), 4, &v97);
        v64 = (_BYTE *)ipa3_ctx;
        *(_BYTE *)(ipa3_ctx + 51290) = 0;
        v64[51293] = 1;
      }
      goto LABEL_99;
    case 'y':
      v68 = ipa3_ctx;
      ++*(_DWORD *)(ipa3_ctx + 32852);
      raw_spin_lock(v68 + 51256);
      v64 = (_BYTE *)ipa3_ctx;
      if ( *(_BYTE *)(ipa3_ctx + 51288) == 1 && (*(_BYTE *)(ipa3_ctx + 51294) & 1) == 0 )
      {
        _X8 = (unsigned int *)(ipa3_ctx + 33836);
        __asm { PRFM            #0x11, [X8] }
        do
          v94 = __ldxr(_X8);
        while ( __stxr(v94 + 1, _X8) );
        raw_notifier_call_chain(*(_QWORD *)(ipa3_ctx + 51264), 6, &v97);
        v64 = (_BYTE *)ipa3_ctx;
        *(_BYTE *)(ipa3_ctx + 51291) = 0;
        v64[51294] = 1;
      }
      goto LABEL_99;
    case '\x7F':
      v62 = 32864;
      goto LABEL_101;
  }
LABEL_102:
  __break(0x800u);
LABEL_103:
  v60 = v97;
LABEL_104:
  if ( v60 < 112 )
    goto LABEL_118;
  v70 = *(_DWORD *)(*((_QWORD *)v3 + 203) + 4LL);
  switch ( v70 )
  {
    case 'y':
      raw_spin_lock(ipa3_ctx + 51256);
      v71 = (_BYTE *)ipa3_ctx;
      if ( *(_BYTE *)(ipa3_ctx + 51288) == 1 && (*(_BYTE *)(ipa3_ctx + 51291) & 1) == 0 )
      {
        _X8 = (unsigned int *)(ipa3_ctx + 33832);
        __asm { PRFM            #0x11, [X8] }
        do
          v88 = __ldxr(_X8);
        while ( __stxr(v88 + 1, _X8) );
        raw_notifier_call_chain(*(_QWORD *)(ipa3_ctx + 51264), 5, &v97);
        v71 = (_BYTE *)ipa3_ctx;
        *(_BYTE *)(ipa3_ctx + 51291) = 1;
        v71[51294] = 0;
      }
      goto LABEL_117;
    case '_':
      raw_spin_lock(ipa3_ctx + 51256);
      v71 = (_BYTE *)ipa3_ctx;
      if ( *(_BYTE *)(ipa3_ctx + 51288) == 1 && (*(_BYTE *)(ipa3_ctx + 51290) & 1) == 0 )
      {
        _X8 = (unsigned int *)(ipa3_ctx + 33820);
        __asm { PRFM            #0x11, [X8] }
        do
          v86 = __ldxr(_X8);
        while ( __stxr(v86 + 1, _X8) );
        raw_notifier_call_chain(*(_QWORD *)(ipa3_ctx + 51264), 2, &v97);
        v71 = (_BYTE *)ipa3_ctx;
        *(_BYTE *)(ipa3_ctx + 51290) = 1;
        v71[51293] = 0;
      }
LABEL_117:
      result = (int *)raw_spin_unlock(v71 + 51256);
      break;
    case '#':
      raw_spin_lock(ipa3_ctx + 51256);
      v71 = (_BYTE *)ipa3_ctx;
      if ( *(_BYTE *)(ipa3_ctx + 51288) == 1 && (*(_BYTE *)(ipa3_ctx + 51289) & 1) == 0 )
      {
        _X8 = (unsigned int *)(ipa3_ctx + 33816);
        __asm { PRFM            #0x11, [X8] }
        do
          v84 = __ldxr(_X8);
        while ( __stxr(v84 + 1, _X8) );
        raw_notifier_call_chain(*(_QWORD *)(ipa3_ctx + 51264), 1, &v97);
        v71 = (_BYTE *)ipa3_ctx;
        *(_BYTE *)(ipa3_ctx + 51289) = 1;
        v71[51292] = 0;
      }
      goto LABEL_117;
  }
LABEL_118:
  _ReadStatusReg(SP_EL0);
  return result;
}
