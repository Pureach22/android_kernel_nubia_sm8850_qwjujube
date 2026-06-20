__int64 __fastcall ipa3_alloc_counter_id(__int64 *a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  int v4; // w9
  __int64 v5; // x8
  __int64 v6; // x11
  int v7; // w12
  int v8; // w9
  int v9; // w10
  int v10; // w15
  int v11; // w16
  int v12; // w10
  int v13; // w12
  unsigned int v14; // w11
  char v15; // w12
  char v16; // w14
  bool v17; // zf
  int v18; // w16
  unsigned int v19; // w15
  unsigned int v20; // w14
  unsigned int v21; // w15
  unsigned int v22; // w14
  unsigned int v23; // w15
  unsigned int v24; // w14
  unsigned int v25; // w13
  int v26; // w21
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  unsigned __int64 v30; // x8
  int v31; // w9
  int v32; // w20
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x10
  unsigned __int64 v37; // x8
  __int64 v38; // x9
  __int64 v39; // x10
  __int64 v40; // x23
  unsigned int low_hdl_id; // w21
  unsigned int high_hdl_id; // w0
  __int64 v43; // x9
  __int64 v44; // x0
  unsigned __int64 v45; // x8
  __int64 v46; // x9
  __int64 v48; // x9
  __int64 v49; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v51; // x9
  __int64 v52; // x8
  unsigned __int64 v53; // x21
  __int64 v54; // x22
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0

  v2 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29408), 3520);
  while ( v2 )
  {
    idr_preload(3264);
    v3 = raw_spin_lock(ipa3_ctx + 43864);
    v5 = *a1;
    v4 = *((_DWORD *)a1 + 2);
    *(_QWORD *)v2 = *a1;
    LOBYTE(v5) = BYTE4(v5);
    *(_DWORD *)(v2 + 8) = v4;
    *(_WORD *)(v2 + 6) = 0;
    if ( BYTE4(v5) )
    {
      v6 = 0;
      v7 = 0;
      v8 = 0;
      v9 = 0;
      while ( 1 )
      {
        v10 = v6 - v7 + 2;
        if ( v7 <= v8 )
          v11 = v8;
        else
          v11 = v7;
        if ( v7 <= v8 )
          v10 = v9;
        if ( (*(_BYTE *)(ipa3_ctx + 43832 + v6) & 1) != 0 )
          v7 = 0;
        else
          ++v7;
        if ( (*(_BYTE *)(ipa3_ctx + 43832 + v6) & 1) != 0 )
        {
          v9 = v10;
          v8 = v11;
        }
        if ( v7 == BYTE4(v5) )
          break;
        if ( ++v6 == 24 )
          goto LABEL_20;
      }
      LOBYTE(v5) = v6 - BYTE4(v5) + 2;
      *(_BYTE *)(v2 + 7) = v6 + 1;
      *(_BYTE *)(v2 + 6) = v5;
      if ( (_BYTE)v6 - BYTE4(v5) != 0xFE )
      {
        v8 = 1;
        goto LABEL_23;
      }
LABEL_20:
      if ( !*(_BYTE *)(v2 + 5) || !v8 )
      {
        *(_BYTE *)(v2 + 4) = 0;
        *(_WORD *)(v2 + 6) = 0;
LABEL_111:
        v48 = ipa3_ctx;
        *(_DWORD *)v2 = -1;
        kmem_cache_free(*(_QWORD *)(v48 + 29408), v2);
        v49 = raw_spin_unlock(ipa3_ctx + 43864);
        _ReadStatusReg(TPIDR_EL1);
        StatusReg = _ReadStatusReg(SP_EL0);
        v51 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v51;
        if ( !v51 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule(v49);
        return 4294967284LL;
      }
      *(_BYTE *)(v2 + 4) = v8;
      v8 = (unsigned __int8)v8;
      *(_BYTE *)(v2 + 6) = v9;
      *(_BYTE *)(v2 + 7) = v8 + v9 - 1;
      LOBYTE(v5) = v9;
    }
    else
    {
      v8 = 0;
    }
LABEL_23:
    v12 = *(unsigned __int8 *)(v2 + 8);
    *(_WORD *)(v2 + 10) = 0;
    if ( !v12 )
    {
LABEL_80:
      if ( v8 )
        goto LABEL_81;
      goto LABEL_92;
    }
    v13 = *(unsigned __int8 *)(ipa3_ctx + 43856);
    v14 = v13 ^ 1;
    if ( (v13 ^ 1) == v12 )
    {
      v15 = 0;
      v14 = 0;
      v16 = 0;
      goto LABEL_79;
    }
    v17 = v13 == 0;
    v16 = 1;
    if ( *(_BYTE *)(ipa3_ctx + 43856) )
      v15 = 0;
    else
      v15 = 26;
    if ( v17 )
      v18 = 2;
    else
      v18 = 1;
    if ( *(_BYTE *)(ipa3_ctx + 43857) )
      v19 = 0;
    else
      v19 = v18;
    if ( !*(_BYTE *)(ipa3_ctx + 43857) )
    {
      v15 = 0;
      v14 = 0;
    }
    if ( v19 != v12 )
    {
      if ( (*(_BYTE *)(ipa3_ctx + 43858) & 1) != 0 )
      {
        v20 = 0;
        if ( v19 > v14 )
        {
          v14 = v19;
          v15 = 28 - v19;
        }
      }
      else
      {
        v20 = v19 + 1;
        if ( v19 + 1 == v12 )
        {
          v16 = 2;
          goto LABEL_79;
        }
      }
      if ( (*(_BYTE *)(ipa3_ctx + 43859) & 1) != 0 )
      {
        v21 = 0;
        if ( v20 > v14 )
        {
          v14 = v20;
          v15 = 29 - v20;
        }
      }
      else
      {
        v21 = v20 + 1;
      }
      if ( v21 == v12 )
      {
        v16 = 3;
      }
      else
      {
        if ( (*(_BYTE *)(ipa3_ctx + 43860) & 1) != 0 )
        {
          v22 = 0;
          if ( v21 > v14 )
          {
            v14 = v21;
            v15 = 30 - v21;
          }
        }
        else
        {
          v22 = v21 + 1;
        }
        if ( v22 == v12 )
        {
          v16 = 4;
        }
        else
        {
          if ( (*(_BYTE *)(ipa3_ctx + 43861) & 1) != 0 )
          {
            v23 = 0;
            if ( v22 > v14 )
            {
              v14 = v22;
              v15 = 31 - v22;
            }
          }
          else
          {
            v23 = v22 + 1;
          }
          if ( v23 == v12 )
          {
            v16 = 5;
          }
          else
          {
            if ( (*(_BYTE *)(ipa3_ctx + 43862) & 1) != 0 )
            {
              v24 = 0;
              if ( v23 > v14 )
              {
                v14 = v23;
                v15 = 32 - v23;
              }
            }
            else
            {
              v24 = v23 + 1;
            }
            if ( v24 == v12 )
            {
              v16 = 6;
            }
            else
            {
              if ( (*(_BYTE *)(ipa3_ctx + 43863) & 1) != 0 )
              {
                v25 = 0;
                if ( v24 > v14 )
                {
                  v14 = v24;
                  v15 = 33 - v24;
                }
              }
              else
              {
                v25 = v24 + 1;
              }
              if ( v25 != v12 )
                goto LABEL_100;
              v16 = 7;
            }
          }
        }
      }
    }
LABEL_79:
    *(_BYTE *)(v2 + 10) = v16 - v12 + 26;
    *(_BYTE *)(v2 + 11) = v16 + 25;
    if ( v16 - (_BYTE)v12 != 0xE6 )
      goto LABEL_80;
LABEL_100:
    if ( !*(_BYTE *)(v2 + 9) || !v14 )
    {
      *(_BYTE *)(v2 + 8) = 0;
      *(_WORD *)(v2 + 10) = 0;
      goto LABEL_111;
    }
    *(_BYTE *)(v2 + 8) = v14;
    *(_BYTE *)(v2 + 10) = v15;
    *(_BYTE *)(v2 + 11) = v14 + v15 - 1;
    LOBYTE(v12) = v14;
    if ( v8 )
    {
LABEL_81:
      v26 = (unsigned __int8)v5;
      if ( (unsigned __int8)(v5 - 25) < 0xE8u )
      {
        if ( (unsigned int)__ratelimit(&ipa3_alloc_counter_id__rs_407, "ipa3_alloc_counter_id") )
        {
          printk(&unk_3B8D81, "ipa3_alloc_counter_id");
          v27 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_111;
        }
        else
        {
          v27 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_111;
        }
        v28 = *(_QWORD *)(v27 + 34152);
        if ( v28 )
        {
          ipc_log_string(v28, "ipa %s:%d unexpected hw_counter start id %d\n", "ipa3_alloc_counter_id", 10884, v26);
          v27 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v27 + 34160);
        if ( v29 )
          ipc_log_string(v29, "ipa %s:%d unexpected hw_counter start id %d\n", "ipa3_alloc_counter_id", 10884, v26);
        goto LABEL_111;
      }
      v30 = 0;
      while ( 25 - v26 != v30 )
      {
        *(_BYTE *)(ipa3_ctx + (unsigned int)(v26 - 1) + 43832LL + v30++) = 1;
        if ( v30 >= *(unsigned __int8 *)(v2 + 4) )
        {
          LOBYTE(v12) = *(_BYTE *)(v2 + 8);
          goto LABEL_92;
        }
      }
      goto LABEL_119;
    }
LABEL_92:
    if ( !(_BYTE)v12 )
    {
LABEL_107:
      v40 = ipa3_ctx;
      low_hdl_id = ipahal_get_low_hdl_id(v3);
      high_hdl_id = ipahal_get_high_hdl_id();
      *(_DWORD *)v2 = idr_alloc(v40 + 43808, v2, low_hdl_id, high_hdl_id, 2080);
      v43 = *(_QWORD *)v2;
      *((_DWORD *)a1 + 2) = *(_DWORD *)(v2 + 8);
      *a1 = v43;
      v44 = raw_spin_unlock(ipa3_ctx + 43864);
      _ReadStatusReg(TPIDR_EL1);
      v45 = _ReadStatusReg(SP_EL0);
      v46 = *(_QWORD *)(v45 + 16) - 1LL;
      *(_DWORD *)(v45 + 16) = v46;
      if ( v46 && *(_QWORD *)(v45 + 16) )
        return 0;
      preempt_schedule(v44);
      return 0;
    }
    v31 = *(unsigned __int8 *)(v2 + 10);
    if ( (unsigned int)(v31 - 33) < 0xFFFFFFF8 )
    {
      v32 = v31 - 24;
      if ( (unsigned int)__ratelimit(&ipa3_alloc_counter_id__rs_410, "ipa3_alloc_counter_id") )
      {
        printk(&unk_3F31F3, "ipa3_alloc_counter_id");
        v33 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_111;
      }
      else
      {
        v33 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_111;
      }
      v34 = *(_QWORD *)(v33 + 34152);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d unexpected sw_counter start id %d\n", "ipa3_alloc_counter_id", 10899, v32);
        v33 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v33 + 34160);
      if ( v35 )
        ipc_log_string(v35, "ipa %s:%d unexpected sw_counter start id %d\n", "ipa3_alloc_counter_id", 10899, v32);
      goto LABEL_111;
    }
    v36 = (unsigned int)(v31 - 25);
    v37 = 0;
    v38 = (unsigned int)(33 - v31);
    v39 = v36 + 43856;
    while ( v38 != v37 )
    {
      *(_BYTE *)(ipa3_ctx + v39 + v37++) = 1;
      if ( v37 >= *(unsigned __int8 *)(v2 + 8) )
        goto LABEL_107;
    }
LABEL_119:
    __break(0x5512u);
    v52 = ipa3_ctx;
    v53 = _ReadStatusReg(SP_EL0);
    v54 = *(_QWORD *)(v53 + 80);
    *(_QWORD *)(v53 + 80) = &ipa3_alloc_counter_id__alloc_tag;
    v2 = kmem_cache_alloc_noprof(*(_QWORD *)(v52 + 29408), 3520);
    *(_QWORD *)(v53 + 80) = v54;
  }
  if ( (unsigned int)__ratelimit(&ipa3_alloc_counter_id__rs, "ipa3_alloc_counter_id") )
    printk(&unk_3B5CD1, "ipa3_alloc_counter_id");
  v55 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v56 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v56 )
    {
      ipc_log_string(v56, "ipa %s:%d failed to alloc fnr stats counter object\n", "ipa3_alloc_counter_id", 10775);
      v55 = ipa3_ctx;
    }
    v57 = *(_QWORD *)(v55 + 34160);
    if ( v57 )
    {
      ipc_log_string(v57, "ipa %s:%d failed to alloc fnr stats counter object\n", "ipa3_alloc_counter_id", 10775);
      v55 = ipa3_ctx;
    }
  }
  raw_spin_unlock(v55 + 43864);
  return 4294967284LL;
}
