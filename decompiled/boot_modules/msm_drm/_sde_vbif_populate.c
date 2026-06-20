__int64 __fastcall sde_vbif_populate(__int64 a1, _DWORD *a2, __int64 a3, int a4, unsigned int a5)
{
  __int64 v5; // x21
  __int64 v6; // x22
  __int64 v7; // x23
  unsigned __int64 v8; // x26
  char *v9; // x27
  int *v10; // x28
  _DWORD *v11; // x9
  __int64 v12; // x8
  int v14; // w3
  int v15; // w4
  char v16; // w8
  int v17; // w4
  int v18; // w4
  __int64 v19; // x0
  __int64 v20; // x19
  unsigned __int64 v21; // x24
  _DWORD *v22; // x20
  int v23; // w4
  __int64 v24; // x0
  unsigned __int64 v25; // x8
  __int64 v26; // x19
  unsigned __int64 v27; // x24
  _DWORD *v28; // x20
  __int64 v29; // x25
  int *v30; // x20
  unsigned int v31; // w5
  int v32; // w19
  __int64 v33; // x0
  unsigned __int64 v36; // x9
  __int64 v38; // x19
  unsigned int v39; // w8
  __int64 v40; // x8
  char v41; // w9
  __int64 v42; // x9
  unsigned __int64 StatusReg; // x19
  __int64 v44; // x20
  __int64 v45; // x0
  unsigned __int64 v52; // x9
  unsigned __int64 v55; // x9
  unsigned int v56; // [xsp+10h] [xbp-20h]
  _DWORD *v57; // [xsp+18h] [xbp-18h]
  __int64 v58; // [xsp+20h] [xbp-10h]

  if ( a5 >= 0xD )
    goto LABEL_96;
  v11 = &a2[a5];
  v12 = a1 + 280LL * a5;
  v6 = a3;
  LODWORD(v7) = a5;
  *(_DWORD *)(v12 + 15364) = *v11;
  *(_DWORD *)(v12 + 15368) = a4;
  v14 = v11[384];
  v5 = v12 + 15344;
  *(_DWORD *)(v12 + 15360) = v14;
  snprintf((char *)(v12 + 15344), 0x10u, "vbif_%u", v14);
  v9 = "ress";
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "vbif:%d\n", *(_DWORD *)(v5 + 16));
  v57 = a2;
  *(_DWORD *)(v5 + 56) = 0x4000;
  v15 = a2[576];
  *(_DWORD *)(v5 + 48) = v15;
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "default_ot_rd_limit=%u\n", v15);
    v16 = _drm_debug;
    v17 = a2[768];
    *(_DWORD *)(v5 + 52) = v17;
    v8 = v5 + 52;
    if ( (v16 & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "default_ot_wr_limit=%u\n", v17);
      v41 = _drm_debug;
      v18 = *(_DWORD *)(v6 + 20) / 2;
      *(_DWORD *)(v5 + 64) = v18;
      v10 = (int *)(v5 + 64);
      if ( (v41 & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "dynamic_ot_rd_tbl.count=%u\n", v18);
        v18 = *v10;
      }
      goto LABEL_8;
    }
  }
  else
  {
    *(_DWORD *)(v5 + 52) = a2[768];
    v8 = v5 + 52;
  }
  v18 = *(_DWORD *)(v6 + 20) / 2;
  *(_DWORD *)(v5 + 64) = v18;
  v10 = (int *)(v5 + 64);
LABEL_8:
  if ( !v18 )
    goto LABEL_16;
  v19 = _kvmalloc_node_noprof(16LL * (unsigned int)*v10, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v5 + 72) = v19;
  if ( !v19 )
    return 4294967284LL;
  do
  {
    if ( *v10 )
    {
      v20 = 0;
      v21 = 0;
      v22 = v57 + 961;
      do
      {
        if ( v20 == 512 )
          goto LABEL_96;
        *(_QWORD *)(*(_QWORD *)(v5 + 72) + v20) = (unsigned int)*(v22 - 1);
        *(_DWORD *)(*(_QWORD *)(v5 + 72) + v20 + 8) = *v22;
        if ( (v9[4000] & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "dynamic_ot_rd_tbl[%d].cfg=<%llu %u>\n",
            v21,
            *(_QWORD *)(*(_QWORD *)(v5 + 72) + v20),
            *(_DWORD *)(*(_QWORD *)(v5 + 72) + v20 + 8));
        ++v21;
        v20 += 16;
        v22 += 2;
      }
      while ( v21 < (unsigned int)*v10 );
    }
LABEL_16:
    v23 = *(_DWORD *)(v6 + 24) / 2;
    *(_DWORD *)(v5 + 80) = v23;
    if ( (v9[4000] & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "dynamic_ot_wr_tbl.count=%u\n", v23);
      v23 = *(_DWORD *)(v5 + 80);
    }
    if ( v23 )
    {
      v24 = _kvmalloc_node_noprof(16LL * *(unsigned int *)(v5 + 80), 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v5 + 88) = v24;
      if ( !v24 )
        return 4294967284LL;
      LODWORD(v25) = *(_DWORD *)(v5 + 80);
      if ( (_DWORD)v25 )
      {
        v26 = 0;
        v27 = 0;
        v28 = v57 + 1153;
        do
        {
          if ( v26 == 512 )
            goto LABEL_96;
          *(_QWORD *)(*(_QWORD *)(v5 + 88) + v26) = (unsigned int)*(v28 - 1);
          *(_DWORD *)(*(_QWORD *)(v5 + 88) + v26 + 8) = *v28;
          if ( (v9[4000] & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "dynamic_ot_wr_tbl[%d].cfg=<%llu %u>\n",
              v27,
              *(_QWORD *)(*(_QWORD *)(v5 + 88) + v26),
              *(_DWORD *)(*(_QWORD *)(v5 + 88) + v26 + 8));
          v25 = *(unsigned int *)(v5 + 80);
          ++v27;
          v26 += 16;
          v28 += 2;
        }
        while ( v27 < v25 );
      }
    }
    else
    {
      LODWORD(v25) = 0;
    }
    v56 = v7;
    if ( *(_DWORD *)(v5 + 48) || *(_DWORD *)v8 || *v10 | (unsigned int)v25 )
    {
      _X8 = (unsigned __int64 *)(v5 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v52 = __ldxr(_X8);
      while ( __stxr(v52 | 2, _X8) );
    }
    v58 = v6;
    v7 = 0;
    v6 = v5 + 96;
    v10 = v57 + 1728;
    v29 = 9;
    _ReadStatusReg(SP_EL0);
    do
    {
      v30 = (int *)(v6 + 16 * v7);
      v31 = *(_DWORD *)(v58 + 4 * v29);
      *v30 = v31;
      if ( (v9[4000] & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "qos_tbl[%d].count=%u\n", v7, v31);
        v31 = *v30;
      }
      v32 = 2 * *(_DWORD *)(a1 + 21592);
      if ( v31 == v32 )
      {
        v33 = _kvmalloc_node_noprof(4LL * v31, 0, 3520, 0xFFFFFFFFLL);
        *((_QWORD *)v30 + 1) = v33;
        if ( !v33 )
        {
          *v30 = 0;
          return 4294967284LL;
        }
        if ( *v30 )
        {
          v8 = 0;
          while ( v8 != 64 )
          {
            *(_DWORD *)(*((_QWORD *)v30 + 1) + 4 * v8) = v10[v8];
            if ( (v9[4000] & 4) != 0 )
              _drm_dev_dbg(
                0,
                0,
                0,
                "client:%d, prop:%d, lvl[%d]=%u\n",
                v7,
                v29,
                v8,
                *(_DWORD *)(*((_QWORD *)v30 + 1) + 4 * v8));
            if ( ++v8 >= (unsigned int)*v30 )
              goto LABEL_43;
          }
          goto LABEL_96;
        }
      }
      else if ( v31 )
      {
        *v30 = 0;
        *((_QWORD *)v30 + 1) = 0;
        printk(&unk_269AFD, "_sde_vbif_populate_qos_parsing");
        goto LABEL_44;
      }
LABEL_43:
      *v30 = v32;
      _X8 = (unsigned __int64 *)(v5 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v36 = __ldxr(_X8);
      while ( __stxr(v36 | 4, _X8) );
LABEL_44:
      ++v7;
      ++v29;
      v10 += 192;
    }
    while ( v7 != 7 );
    v38 = v58;
    v39 = *(_DWORD *)(v38 + 32) + *(_DWORD *)(v38 + 28);
    *(_DWORD *)(v5 + 208) = v39;
    if ( v39 >= 0x11 )
    {
      *(_DWORD *)(v5 + 208) = 0;
      printk(&unk_243A6B, "_sde_vbif_populate");
    }
    if ( *(int *)(v58 + 28) < 1 )
    {
      v40 = 0;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 212) = v57[1344];
    if ( *(int *)(v58 + 28) < 2 )
    {
      v40 = 1;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 216) = v57[1345];
    if ( *(int *)(v58 + 28) <= 2 )
    {
      v40 = 2;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 220) = v57[1346];
    if ( *(int *)(v58 + 28) < 4 )
    {
      v40 = 3;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 224) = v57[1347];
    if ( *(int *)(v58 + 28) < 5 )
    {
      v40 = 4;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 228) = v57[1348];
    if ( *(int *)(v58 + 28) < 6 )
    {
      v40 = 5;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 232) = v57[1349];
    if ( *(int *)(v58 + 28) < 7 )
    {
      v40 = 6;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 236) = v57[1350];
    if ( *(int *)(v58 + 28) < 8 )
    {
      v40 = 7;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 240) = v57[1351];
    if ( *(int *)(v58 + 28) < 9 )
    {
      v40 = 8;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 244) = v57[1352];
    if ( *(int *)(v58 + 28) < 10 )
    {
      v40 = 9;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 248) = v57[1353];
    if ( *(int *)(v58 + 28) < 11 )
    {
      v40 = 10;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 252) = v57[1354];
    if ( *(int *)(v58 + 28) < 12 )
    {
      v40 = 11;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 256) = v57[1355];
    if ( *(int *)(v58 + 28) < 13 )
    {
      v40 = 12;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 260) = v57[1356];
    if ( *(int *)(v58 + 28) < 14 )
    {
      v40 = 13;
LABEL_89:
      v38 = v58;
      goto LABEL_90;
    }
    *(_DWORD *)(v5 + 264) = v57[1357];
    if ( *(int *)(v58 + 28) < 15 )
    {
      v40 = 14;
      goto LABEL_89;
    }
    *(_DWORD *)(v5 + 268) = v57[1358];
    if ( *(int *)(v58 + 28) < 16 )
    {
      v40 = 15;
      goto LABEL_89;
    }
    v38 = v58;
    *(_DWORD *)(v5 + 272) = v57[1359];
    if ( *(int *)(v58 + 28) > 16 )
      goto LABEL_96;
    v40 = 16;
LABEL_90:
    if ( *(int *)(v38 + 32) < 1 )
    {
LABEL_94:
      if ( (*(_QWORD *)(a1 + 22008) & 0x8000000) != 0 )
      {
        _X8 = (unsigned __int64 *)(v5 + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v55 = __ldxr(_X8);
        while ( __stxr(v55 | 8, _X8) );
      }
      return 0;
    }
    v42 = 0;
    while ( (unsigned __int64)(v40 + v42) <= 0xF )
    {
      *(_DWORD *)(4 * v40 + 280LL * v56 + a1 + 15556 + 4 * v42) = v57[v42 + 1536];
      if ( ++v42 >= *(int *)(v38 + 32) )
        goto LABEL_94;
    }
LABEL_96:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v44 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sde_vbif_populate_ot_parsing__alloc_tag;
    v45 = _kvmalloc_node_noprof(16LL * (unsigned int)*v10, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v44;
    *(_QWORD *)(v5 + 72) = v45;
  }
  while ( v45 );
  return 4294967284LL;
}
