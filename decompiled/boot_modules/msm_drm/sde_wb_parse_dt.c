__int64 __fastcall sde_wb_parse_dt(__int64 a1, int *a2)
{
  __int64 v4; // x20
  unsigned int v5; // w24
  __int64 dt_entry; // x0
  __int64 v7; // x1
  unsigned int v8; // w28
  int *v9; // x27
  unsigned __int64 v10; // x25
  __int64 v11; // x26
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x8
  _DWORD *v17; // x24
  int v18; // w3
  __int64 v19; // x23
  int v20; // w8
  unsigned int v21; // w4
  int v22; // w8
  unsigned int v23; // w9
  int v24; // w10
  int v25; // w9
  int v26; // w8
  int v27; // w8
  __int64 v28; // x8
  __int64 v29; // x9
  int *v30; // x10
  int *v31; // x12
  int *v32; // x13
  int v33; // w11
  __int64 v34; // x14
  int *v35; // x14
  int v36; // w15
  __int64 v37; // x14
  int v38; // w16
  int *v39; // x14
  __int64 v40; // x7
  int v41; // w8
  unsigned __int64 v48; // x9
  unsigned __int64 v51; // x9
  unsigned __int64 v54; // x9
  unsigned __int64 v57; // x9
  unsigned __int64 v60; // x9
  unsigned __int64 v63; // x9
  unsigned __int64 v66; // x9
  unsigned __int64 v69; // x9
  unsigned __int64 v72; // x9
  unsigned __int64 v75; // x9
  unsigned __int64 v78; // x9
  unsigned __int64 v81; // x9
  unsigned __int64 v84; // x9
  unsigned __int64 v87; // x9
  unsigned __int64 v90; // x9
  unsigned __int64 v93; // x9
  __int64 v94; // [xsp+44h] [xbp-2Ch] BYREF
  __int16 v95; // [xsp+4Ch] [xbp-24h]
  _QWORD v96[4]; // [xsp+50h] [xbp-20h] BYREF

  v96[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v96, 0, 24);
  v95 = 0;
  v94 = 0;
  v4 = _kvmalloc_node_noprof(4608, 0, 3520, 0xFFFFFFFFLL);
  if ( !v4 )
  {
LABEL_7:
    v5 = -12;
    goto LABEL_8;
  }
  v5 = validate_dt_entry(a1, &wb_prop, 6, v96, &v94);
  if ( v5 )
    goto LABEL_8;
  a2[3568] = v94;
  dt_entry = read_dt_entry(a1, &wb_prop, 6, v96, (char *)&v94 + 4, v4);
  v5 = dt_entry;
  if ( (_DWORD)dt_entry )
    goto LABEL_8;
  if ( !(_DWORD)v94 )
  {
    v5 = 0;
LABEL_8:
    kvfree(v4);
    _ReadStatusReg(SP_EL0);
    return v5;
  }
  v8 = *a2;
  v9 = a2 + 4968;
  v10 = 0;
  v11 = v4 + 1536;
  _ReadStatusReg(SP_EL0);
  while ( v10 != 13 )
  {
    v17 = (_DWORD *)_kvmalloc_node_noprof(8, 0, 3520, 0xFFFFFFFFLL);
    if ( !v17 )
      goto LABEL_7;
    v18 = *(_DWORD *)(v11 + 4 * v10);
    v19 = (__int64)&a2[22 * v10 + 3570];
    v20 = *(_DWORD *)(v4 + 4 * v10);
    *(_QWORD *)(v19 + 48) = v17;
    *(_DWORD *)(v19 + 16) = v18 + 1;
    *(_DWORD *)(v19 + 20) = v20;
    snprintf((char *)v19, 0x10u, "wb_%u", v18);
    v21 = *(_DWORD *)(v11 + 4 * v10) + 15;
    *(_DWORD *)(v19 + 76) = *(_DWORD *)(v4 + 2304 + 4 * v10);
    *(_DWORD *)(v19 + 80) = v21;
    if ( v21 >= 0x14 )
    {
      printk(&unk_249F33, "sde_wb_parse_dt");
      v5 = -22;
      goto LABEL_8;
    }
    v22 = *(_DWORD *)(v4 + 768);
    if ( !BYTE5(v94) )
      v22 = 256;
    *(_DWORD *)(v19 + 72) = *((unsigned __int16 *)a2 + 1) == 4103;
    v23 = *(_DWORD *)(v19 + 16);
    *(_DWORD *)(v19 + 24) = v22;
    v24 = a2[5392];
    *v17 = a2[5391];
    v17[1] = v24;
    if ( v23 < 2 )
    {
      _X8 = (unsigned __int64 *)(v19 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v51 = __ldxr(_X8);
      while ( __stxr(v51 | 4, _X8) );
    }
    else
    {
      _X8 = (unsigned __int64 *)(v19 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v48 = __ldxr(_X8);
      while ( __stxr(v48 | 2, _X8) );
    }
    if ( (*((_QWORD *)a2 + 2751) & 1) != 0 )
    {
      _X8 = (unsigned __int64 *)(v19 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v54 = __ldxr(_X8);
      while ( __stxr(v54 | 0x400, _X8) );
    }
    if ( a2[5398] == 8 )
    {
      _X8 = (unsigned __int64 *)(v19 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v57 = __ldxr(_X8);
      while ( __stxr(v57 | 0x200, _X8) );
      if ( (*((_QWORD *)a2 + 2751) & 4) == 0 )
      {
LABEL_25:
        if ( (*((_QWORD *)a2 + 2751) & 0x10) == 0 )
          goto LABEL_27;
LABEL_26:
        _X8 = (unsigned __int64 *)(v19 + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v63 = __ldxr(_X8);
        while ( __stxr(v63 | 0x8000, _X8) );
        goto LABEL_27;
      }
    }
    else if ( (*((_QWORD *)a2 + 2751) & 4) == 0 )
    {
      goto LABEL_25;
    }
    _X8 = (unsigned __int64 *)(v19 + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v60 = __ldxr(_X8);
    while ( __stxr(v60 | 0x80, _X8) );
    if ( (*((_QWORD *)a2 + 2751) & 0x10) != 0 )
      goto LABEL_26;
LABEL_27:
    if ( a2[7] == 256 )
    {
      _X8 = (unsigned __int64 *)(v19 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v66 = __ldxr(_X8);
      while ( __stxr(v66 | 0x800, _X8) );
    }
    if ( (unsigned int)*a2 >> 28 >= 9 )
    {
      _X8 = (unsigned __int64 *)(v19 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v69 = __ldxr(_X8);
      while ( __stxr(v69 | 0x100000, _X8) );
      _X8 = (unsigned __int64 *)(v19 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v72 = __ldxr(_X8);
      while ( __stxr(v72 | 0x10000, _X8) );
      if ( (unsigned int)*a2 >> 28 >= 0xB )
      {
        _X8 = (unsigned __int64 *)(v19 + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v78 = __ldxr(_X8);
        while ( __stxr(v78 | 0x400000, _X8) );
      }
    }
    dt_entry = add_to_irq_offset_list(a2, 5, *(unsigned int *)(v19 + 16), *(unsigned int *)(v19 + 20));
    v5 = dt_entry;
    if ( (*((_QWORD *)a2 + 2751) & 0x40) != 0 )
    {
      _X8 = (unsigned __int64 *)(v19 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v75 = __ldxr(_X8);
      while ( __stxr(v75 | 0x2000, _X8) );
      if ( (*((_QWORD *)a2 + 2751) & 0x80) != 0 )
      {
        _X8 = (unsigned __int64 *)(v19 + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v84 = __ldxr(_X8);
        while ( __stxr(v84 | 0x4000, _X8) );
      }
      if ( a2[7] == 256 )
      {
        _X8 = (unsigned __int64 *)(v19 + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v87 = __ldxr(_X8);
        while ( __stxr(v87 | 0x40000, _X8) );
      }
      if ( v8 >> 28 >= 0xD )
      {
        v25 = 1483264;
        v26 = 1487360;
        goto LABEL_49;
      }
      if ( v8 >> 29 >= 5 )
      {
        v25 = 422400;
        v26 = 520704;
LABEL_49:
        *v9 = v25;
        a2[4969] = v26;
LABEL_50:
        v27 = 1024;
LABEL_51:
        a2[4972] = v27;
        if ( (*((_QWORD *)a2 + 2751) & 0x20) == 0 )
          goto LABEL_54;
        _X8 = (unsigned __int64 *)(v19 + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v90 = __ldxr(_X8);
        while ( __stxr(v90 | 0x80000, _X8) );
        if ( (*((_QWORD *)a2 + 2751) & 0x8000000000LL) != 0 )
          goto LABEL_64;
        goto LABEL_55;
      }
      if ( v8 >> 28 < 9 )
      {
        if ( (v8 & 0x80000000) == 0 )
        {
          *v9 = 536576;
          v27 = 256;
          goto LABEL_51;
        }
        v41 = 420352;
      }
      else
      {
        v41 = 422400;
      }
      *v9 = v41;
      goto LABEL_50;
    }
    if ( (*((_QWORD *)a2 + 2751) & 8) == 0 )
      goto LABEL_54;
    _X8 = (unsigned __int64 *)(v19 + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v81 = __ldxr(_X8);
    while ( __stxr(v81 | 0x1000, _X8) );
    if ( a2[7] == 256 )
    {
      _X8 = (unsigned __int64 *)(v19 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v93 = __ldxr(_X8);
      while ( __stxr(v93 | 0x20000, _X8) );
    }
    if ( v8 >> 28 < 7 )
    {
      *v9 = 536576;
      a2[4972] = 256;
LABEL_54:
      if ( (*((_QWORD *)a2 + 2751) & 0x8000000000LL) != 0 )
        goto LABEL_64;
      goto LABEL_55;
    }
    *v9 = 434688;
    a2[4972] = 4096;
    if ( (*((_QWORD *)a2 + 2751) & 0x8000000000LL) != 0 )
      goto LABEL_64;
LABEL_55:
    v28 = (unsigned int)a2[161];
    if ( (_DWORD)v28 )
    {
      v29 = 0;
      v30 = (int *)(v4 + 3328 + 8 * v10);
      v31 = (int *)(v4 + 4096 + 8 * v10);
      v32 = a2 + 222;
      v33 = *v30;
      while ( v29 != 12 )
      {
        v34 = *(unsigned int *)(v19 + 80);
        if ( (unsigned int)v34 > 0x13 )
          break;
        v35 = &v32[2 * v34];
        v36 = v30[1];
        *(v35 - 41) = v33;
        *(v35 - 40) = v36;
        v37 = *(unsigned int *)(v19 + 80);
        if ( (unsigned int)v37 > 0x13 )
          break;
        v38 = v31[1];
        v39 = &v32[2 * v37];
        ++v29;
        v32 += 100;
        *(v39 - 1) = *v31;
        *v39 = v38;
        if ( v28 == v29 )
          goto LABEL_61;
      }
      break;
    }
LABEL_61:
    if ( (_drm_debug & 4) != 0 )
    {
      v40 = *(unsigned int *)(v19 + 80);
      if ( (unsigned int)v40 > 0x13 )
        break;
      _drm_dev_dbg(
        0,
        0,
        0,
        "wb:%d xin:%d vbif:%d clk%d:%x/%d\n",
        *(_DWORD *)(v19 + 16) - 1,
        *(_DWORD *)(v19 + 76),
        *(_DWORD *)(v19 + 72),
        v40,
        a2[2 * v40 + 181],
        a2[2 * v40 + 182]);
    }
LABEL_64:
    if ( (*((_QWORD *)a2 + 2751) & 0x100) != 0 )
    {
      _X8 = (unsigned __int64 *)(v19 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v15 = __ldxr(_X8);
      while ( __stxr(v15 | 0x200000, _X8) );
      *(_QWORD *)(v19 + 64) = *((_QWORD *)a2 + 2757);
    }
    v16 = (unsigned int)v94;
    ++v10;
    *(_QWORD *)(v19 + 56) = *((_QWORD *)a2 + 2756);
    if ( v10 >= v16 )
      goto LABEL_8;
  }
  __break(0x5512u);
  return sde_cdm_parse_dt(dt_entry, v7);
}
