__int64 __fastcall cfg80211_roamed(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  int v5; // w21
  __int64 v6; // x22
  __int64 v7; // x23
  unsigned int v8; // w8
  unsigned __int64 v10; // x24
  __int64 v11; // x20
  __int64 *v12; // x25
  bool v13; // w9
  __int64 v14; // x2
  __int64 v15; // x9
  __int64 v16; // x9
  __int64 v17; // x11
  __int64 result; // x0
  bool v19; // cc
  __int64 v20; // x9
  unsigned __int64 v21; // x20
  __int64 *v22; // x1
  __int64 v23; // x21
  __int64 v24; // x8
  __int64 v25; // x24
  size_t v26; // x2
  __int64 v27; // x8
  unsigned __int64 v28; // x25
  size_t v29; // x2
  __int64 v30; // x8
  size_t v31; // x2
  __int64 v32; // x8
  size_t v33; // x2
  __int64 v34; // x8
  _QWORD *v35; // x9
  __int64 v36; // x10
  int v37; // w9
  __int64 v38; // x8
  __int64 v39; // x9
  __int16 v40; // w10
  unsigned int v41; // w14
  unsigned __int64 v42; // x8
  __int64 v43; // x9
  unsigned __int64 v44; // x10
  __int64 v45; // x11
  unsigned __int64 v46; // x12
  unsigned __int64 v47; // x13
  bool v48; // w15
  __int64 v49; // x14
  __int64 v50; // x17
  unsigned __int64 v51; // x16
  __int64 v52; // x15
  __int64 v53; // x16
  __int16 v54; // w17
  unsigned __int64 v55; // x15
  __int64 v56; // x14
  __int64 v57; // x15
  __int16 v58; // w16
  bool v59; // cf
  __int64 v60; // x0
  __int64 v61; // x2
  __int64 v62; // x9
  unsigned int v63; // w8
  unsigned __int64 v64; // x20
  _QWORD **v65; // x21
  bool v66; // w9
  unsigned __int64 StatusReg; // x24
  __int64 v68; // x25
  __int64 v69; // x9

  v6 = *(_QWORD *)(a1 + 992);
  v7 = *(_QWORD *)v6;
  if ( *(_QWORD *)v6 )
  {
    v8 = *(unsigned __int16 *)(a2 + 88);
    v3 = a2;
    v10 = 0;
    v11 = 0;
    v12 = (__int64 *)(a2 + 120);
    v13 = *(_WORD *)(a2 + 88) == 0;
    do
    {
      if ( v13 || ((v8 >> v10) & 1) != 0 )
      {
        v14 = *(v12 - 2);
        v15 = *(v12 - 3) ? 6LL : 0LL;
        v16 = v15 + v11;
        v17 = v14 ? 6LL : 0LL;
        v11 = v16 + v17;
        if ( !*v12 )
        {
          result = (__int64)_cfg80211_get_bss(
                              *(_QWORD *)v6,
                              (_DWORD *)*(v12 - 1),
                              v14,
                              (void *)(v6 + 286),
                              *(unsigned __int8 *)(v6 + 318),
                              *(_DWORD *)(v6 + 96),
                              2u,
                              1);
          *v12 = result;
          if ( !result )
          {
            __break(0x800u);
            goto LABEL_129;
          }
          v8 = *(unsigned __int16 *)(v3 + 88);
        }
      }
      v13 = v8 == 0;
      if ( !v8 )
        break;
      v19 = v10++ > 0xD;
      v12 += 4;
    }
    while ( !v19 );
    v20 = 6;
    if ( !*(_QWORD *)(v3 + 80) )
      v20 = 0;
    v21 = v11
        + *(_QWORD *)(v3 + 8)
        + *(_QWORD *)(v3 + 24)
        + *(_QWORD *)(v3 + 40)
        + *(_QWORD *)(v3 + 64)
        + 16LL * (*(_QWORD *)(v3 + 72) != 0)
        + v20
        + 616;
    result = _kmalloc_noprof(v21, a3 | 0x100u);
    v23 = result;
    if ( result )
    {
LABEL_20:
      if ( v21 < 0x10 || (v21 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
        goto LABEL_137;
      v24 = *(_QWORD *)(v3 + 8);
      v25 = v23 + 616;
      *(_DWORD *)(v23 + 16) = 1;
      if ( v24 )
      {
        if ( v21 < 0x18 )
          goto LABEL_137;
        if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
          goto LABEL_137;
        *(_QWORD *)(v23 + 24) = v25;
        if ( v21 < 0x20 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x20 )
          goto LABEL_137;
        v26 = *(_QWORD *)(v3 + 8);
        if ( v21 >= 0x268 )
          v22 = (__int64 *)(v21 - 616);
        else
          v22 = nullptr;
        *(_QWORD *)(v23 + 32) = v26;
        if ( (unsigned __int64)v22 < v26 )
          goto LABEL_139;
        if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
          goto LABEL_137;
        memcpy(*(void **)(v23 + 24), *(const void **)v3, v26);
        v27 = *(_QWORD *)(v3 + 8);
        v28 = v27 + 616;
        v25 += v27;
        if ( !*(_QWORD *)(v3 + 24) )
        {
LABEL_33:
          if ( !*(_QWORD *)(v3 + 40) )
            goto LABEL_34;
          goto LABEL_48;
        }
      }
      else
      {
        v28 = 616;
        if ( !*(_QWORD *)(v3 + 24) )
          goto LABEL_33;
      }
      if ( v21 < 0x28 )
        goto LABEL_137;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x28 )
        goto LABEL_137;
      *(_QWORD *)(v23 + 40) = v25;
      if ( v21 < 0x30 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
        goto LABEL_137;
      v29 = *(_QWORD *)(v3 + 24);
      if ( v21 >= v28 )
        v22 = (__int64 *)(v21 - v28);
      else
        v22 = nullptr;
      *(_QWORD *)(v23 + 48) = v29;
      if ( (unsigned __int64)v22 < v29 )
        goto LABEL_139;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x28 )
        goto LABEL_137;
      memcpy(*(void **)(v23 + 40), *(const void **)(v3 + 16), v29);
      v30 = *(_QWORD *)(v3 + 24);
      v28 += v30;
      v25 += v30;
      if ( !*(_QWORD *)(v3 + 40) )
      {
LABEL_34:
        if ( !*(_QWORD *)(v3 + 64) )
          goto LABEL_35;
        goto LABEL_58;
      }
LABEL_48:
      if ( v21 < 0x38 )
        goto LABEL_137;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x38 )
        goto LABEL_137;
      *(_QWORD *)(v23 + 56) = v25;
      if ( v21 < 0x40 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x40 )
        goto LABEL_137;
      v31 = *(_QWORD *)(v3 + 40);
      if ( v21 >= v28 )
        v22 = (__int64 *)(v21 - v28);
      else
        v22 = nullptr;
      *(_QWORD *)(v23 + 64) = v31;
      if ( (unsigned __int64)v22 < v31 )
        goto LABEL_139;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x38 )
        goto LABEL_137;
      memcpy(*(void **)(v23 + 56), *(const void **)(v3 + 32), v31);
      v32 = *(_QWORD *)(v3 + 40);
      v28 += v32;
      v25 += v32;
      if ( !*(_QWORD *)(v3 + 64) )
      {
LABEL_35:
        if ( !*(_QWORD *)(v3 + 72) )
          goto LABEL_76;
LABEL_68:
        if ( v21 < 0x60 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x60 )
          goto LABEL_137;
        *(_QWORD *)(v23 + 96) = v25;
        if ( v21 >= v28 )
          v22 = (__int64 *)(v21 - v28);
        else
          v22 = nullptr;
        if ( (unsigned __int64)v22 <= 0xF )
          goto LABEL_140;
        if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x60 )
          goto LABEL_137;
        v35 = *(_QWORD **)(v23 + 96);
        v28 += 16LL;
        v25 += 16;
        v36 = *(_QWORD *)(*(_QWORD *)(v3 + 72) + 8LL);
        *v35 = **(_QWORD **)(v3 + 72);
        v35[1] = v36;
LABEL_76:
        if ( v21 >= 0x49 )
        {
          v37 = *(unsigned __int8 *)(v3 + 48);
          *(_BYTE *)(v23 + 72) = v37;
          if ( v37 == 1 )
          {
            if ( v21 - 73 < 3 )
              goto LABEL_137;
            *(_WORD *)(v23 + 74) = *(_WORD *)(v3 + 50);
          }
          if ( !*(_QWORD *)(v3 + 80) )
          {
LABEL_89:
            if ( v21 >= 0x70 && (v21 & 0xFFFFFFFFFFFFFFFELL) != 0x70 )
            {
              v41 = *(unsigned __int16 *)(v3 + 88);
              v42 = 0;
              v43 = v23 + 120;
              v44 = v21 - 144;
              v45 = v3 + 120;
              v46 = 144;
              v47 = v28;
              *(_WORD *)(v23 + 112) = v41;
              v48 = v41 == 0;
              do
              {
                if ( v48 || ((v41 >> v42) & 1) != 0 )
                {
                  if ( (v46 & 0x8000000000000000LL) != 0 || v21 < v46 || v44 < 8 )
                    goto LABEL_137;
                  v49 = v45 + v46;
                  v50 = *(_QWORD *)(v45 + v46 - 168);
                  *(_QWORD *)(v23 + v46) = *(_QWORD *)(v45 + v46 - 144);
                  if ( v50 )
                  {
                    v51 = v46 - 24;
                    if ( ((v46 - 24) & 0x8000000000000000LL) != 0 || v21 < v51 || v44 + 24 < 8 )
                      goto LABEL_137;
                    if ( v21 >= v47 )
                      v22 = (__int64 *)(v21 - v47);
                    else
                      v22 = nullptr;
                    *(_QWORD *)(v43 + v46 - 144) = v25;
                    if ( (unsigned __int64)v22 <= 5 )
                      goto LABEL_138;
                    if ( v21 < v51 || v44 + 24 < 8 )
                      goto LABEL_137;
                    v52 = *(_QWORD *)(v45 + v46 - 168);
                    v53 = *(_QWORD *)(v43 + v46 - 144);
                    v47 += 6LL;
                    v28 += 6LL;
                    v25 += 6;
                    v54 = *(_WORD *)(v52 + 4);
                    LODWORD(v52) = *(_DWORD *)v52;
                    *(_WORD *)(v53 + 4) = v54;
                    *(_DWORD *)v53 = v52;
                  }
                  if ( *(_QWORD *)(v49 - 160) )
                  {
                    v55 = v46 - 16;
                    if ( (__int64)(v46 - 16) < 0 || v21 < v55 || v44 + 16 < 8 )
                      goto LABEL_137;
                    if ( v21 >= v28 )
                      v22 = (__int64 *)(v21 - v28);
                    else
                      v22 = nullptr;
                    *(_QWORD *)(v43 + v46 - 136) = v25;
                    if ( (unsigned __int64)v22 <= 5 )
                      goto LABEL_138;
                    if ( v21 < v55 || v44 + 16 < 8 )
                      goto LABEL_137;
                    v56 = *(_QWORD *)(v49 - 160);
                    v57 = *(_QWORD *)(v43 + v46 - 136);
                    v47 += 6LL;
                    v28 += 6LL;
                    v25 += 6;
                    v58 = *(_WORD *)(v56 + 4);
                    LODWORD(v56) = *(_DWORD *)v56;
                    *(_WORD *)(v57 + 4) = v58;
                    *(_DWORD *)v57 = v56;
                  }
                }
                v41 = *(unsigned __int16 *)(v3 + 88);
                v48 = *(_WORD *)(v3 + 88) == 0;
                if ( !*(_WORD *)(v3 + 88) )
                  break;
                v59 = v42++ >= 0xE;
                v46 += 32LL;
                v44 -= 32LL;
              }
              while ( !v59 );
              v60 = raw_spin_lock_irqsave(v6 + 160);
              v61 = v6 + 144;
              v22 = *(__int64 **)(v6 + 152);
              v62 = v60;
              if ( v23 == v6 + 144 || v22 == (__int64 *)v23 || *v22 != v61 )
                goto LABEL_141;
              *(_QWORD *)(v6 + 152) = v23;
              *(_QWORD *)v23 = v61;
              if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) != 8 )
              {
                *(_QWORD *)(v23 + 8) = v22;
                *v22 = v23;
LABEL_127:
                raw_spin_unlock_irqrestore(v6 + 160, v62);
                return queue_work_on(32, cfg80211_wq, v7 - 656);
              }
            }
            goto LABEL_137;
          }
          if ( v21 >= 0x68 && (v21 & 0xFFFFFFFFFFFFFFF8LL) != 0x68 )
          {
            *(_QWORD *)(v23 + 104) = v25;
            if ( v21 >= v28 )
              v22 = (__int64 *)(v21 - v28);
            else
              v22 = nullptr;
            if ( (unsigned __int64)v22 <= 5 )
              goto LABEL_138;
            if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) != 0x68 )
            {
              v38 = *(_QWORD *)(v3 + 80);
              v39 = *(_QWORD *)(v23 + 104);
              v28 += 6LL;
              v25 += 6;
              v40 = *(_WORD *)(v38 + 4);
              LODWORD(v38) = *(_DWORD *)v38;
              *(_WORD *)(v39 + 4) = v40;
              *(_DWORD *)v39 = v38;
              goto LABEL_89;
            }
          }
        }
LABEL_137:
        __break(1u);
LABEL_138:
        _fortify_panic(17, v22);
LABEL_139:
        _fortify_panic(17, v22);
LABEL_140:
        _fortify_panic(17, v22);
LABEL_141:
        _list_add_valid_or_report(v23, v22);
        goto LABEL_127;
      }
LABEL_58:
      if ( v21 < 0x50 )
        goto LABEL_137;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x50 )
        goto LABEL_137;
      *(_QWORD *)(v23 + 80) = v25;
      if ( v21 < 0x58 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x58 )
        goto LABEL_137;
      v33 = *(_QWORD *)(v3 + 64);
      if ( v21 >= v28 )
        v22 = (__int64 *)(v21 - v28);
      else
        v22 = nullptr;
      *(_QWORD *)(v23 + 88) = v33;
      if ( (unsigned __int64)v22 < v33 )
        goto LABEL_139;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x50 )
        goto LABEL_137;
      memcpy(*(void **)(v23 + 80), *(const void **)(v3 + 56), v33);
      v34 = *(_QWORD *)(v3 + 64);
      v28 += v34;
      v25 += v34;
      if ( !*(_QWORD *)(v3 + 72) )
        goto LABEL_76;
      goto LABEL_68;
    }
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v68 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cfg80211_roamed__alloc_tag;
    if ( *(_QWORD *)(v3 + 80) )
      v69 = 6;
    else
      v69 = 0;
    v21 = v4
        + *(_QWORD *)(v3 + 8)
        + *(_QWORD *)(v3 + 24)
        + *(_QWORD *)(v3 + 40)
        + *(_QWORD *)(v3 + 64)
        + 16LL * (*(_QWORD *)(v3 + 72) != 0)
        + v69
        + 616;
    result = _kmalloc_noprof(v21, v5 | 0x100u);
    v23 = result;
    *(_QWORD *)(StatusReg + 80) = v68;
    if ( result )
      goto LABEL_20;
  }
LABEL_129:
  v63 = *(unsigned __int16 *)(v3 + 88);
  v64 = 0;
  v65 = (_QWORD **)(v3 + 120);
  v66 = *(_WORD *)(v3 + 88) == 0;
  do
  {
    if ( v66 || ((v63 >> v64) & 1) != 0 )
    {
      result = cfg80211_put_bss(*(_QWORD *)v6, *v65);
      v63 = *(unsigned __int16 *)(v3 + 88);
    }
    v66 = v63 == 0;
    if ( !v63 )
      break;
    v59 = v64++ >= 0xE;
    v65 += 4;
  }
  while ( !v59 );
  return result;
}
