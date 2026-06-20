_QWORD *__fastcall _cfg80211_bss_update(__int64 a1, _QWORD *a2, char a3, __int64 a4)
{
  __int64 v4; // x24
  _QWORD *v5; // x27
  unsigned __int64 v6; // x28
  _QWORD *v8; // x25
  __int64 v10; // x19
  __int64 *v11; // x22
  int v13; // w0
  __int64 v14; // x8
  _QWORD *v15; // x19
  unsigned __int64 v16; // x20
  _QWORD *v17; // x0
  __int64 v18; // x26
  int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x8
  unsigned __int64 v22; // x11
  _BYTE *v23; // x8
  _QWORD *v24; // x9
  _BYTE *v25; // x12
  __int64 v26; // x10
  _QWORD *v27; // x9
  __int64 v28; // x26
  int v29; // w0
  __int64 v30; // x8
  __int64 *v31; // x1
  __int64 v32; // x2
  __int64 v33; // x1
  __int64 *v34; // x9
  __int64 *v35; // x1
  __int64 v36; // x9
  __int64 v37; // x8
  __int64 v38; // x9
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 *v41; // x23
  __int64 v42; // x24
  int v43; // w0
  __int64 v44; // x8
  __int64 v45; // x9
  __int64 v46; // x2
  _QWORD *v47; // x1
  __int64 v48; // x8
  __int64 v49; // x8
  __int64 v50; // x8
  __int64 v51; // x9
  __int64 v52; // x8
  __int64 v53; // x9
  __int64 v54; // x8
  __int64 v55; // x11
  int v56; // w12
  int v57; // w12
  int v58; // w13
  unsigned __int8 *v59; // x14
  __int64 v60; // x15
  int v61; // w16
  int v62; // t1
  _BYTE *v63; // x13
  __int64 v64; // x8
  unsigned __int8 *v65; // x11
  int v66; // t1
  _QWORD *v67; // x12
  int v68; // w2
  unsigned __int64 v69; // x14
  unsigned __int64 v70; // x15
  unsigned __int64 v71; // x16
  int v72; // w1
  __int64 v73; // x1
  __int64 v74; // x1
  __int64 v76; // x8
  __int64 v77; // x9
  __int64 v78; // x8
  __int64 v79; // x9
  __int64 v80; // x8
  unsigned __int64 v81; // x0
  _BYTE *v82; // x8
  _BYTE *v83; // x17
  __int64 v84; // x1
  bool v85; // zf
  int v86; // w17
  _QWORD *v87; // x25
  _QWORD *v88; // x8
  _QWORD *v89; // x0
  int v90; // w25
  unsigned __int64 v91; // x26
  _QWORD *v92; // x26
  __int64 v93; // [xsp+0h] [xbp-30h]
  int v94; // [xsp+Ch] [xbp-24h]
  _QWORD *v95; // [xsp+10h] [xbp-20h]
  unsigned __int64 v96; // [xsp+18h] [xbp-18h]
  unsigned __int64 v97; // [xsp+20h] [xbp-10h]
  unsigned __int64 v98; // [xsp+28h] [xbp-8h]

  v8 = a2 + 14;
  if ( !a2[14] || (a2[8] = a4, !a2[15]) )
  {
    __break(0x800u);
    goto LABEL_119;
  }
  v11 = (__int64 *)(a1 + 208);
  v10 = *(_QWORD *)(a1 + 208);
  if ( !v10 )
    goto LABEL_14;
  v4 = 8;
  while ( 1 )
  {
    v13 = cmp_bss(v8, v10 + 80, 0);
    if ( !v13 )
      break;
    if ( v13 >= 0 )
      v14 = 8;
    else
      v14 = 16;
    v10 = *(_QWORD *)(v10 + v14);
    if ( !v10 )
      goto LABEL_14;
  }
  v15 = (_QWORD *)(v10 - 32);
  if ( !v15 )
  {
LABEL_14:
    v16 = *(int *)(a1 + 1124) + 208LL;
    v17 = (_QWORD *)_kmalloc_noprof(v16, 2336);
    v15 = v17;
    if ( v17 )
    {
      if ( v16 <= 0xCF )
      {
        _fortify_panic(17, v16);
LABEL_138:
        __break(0x800u);
        goto LABEL_139;
      }
      memcpy(v17, a2, 0xD0u);
      if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) == 0x48 )
        goto LABEL_134;
      v4 = (__int64)(v15 + 2);
      v15[9] = 1;
      v15[2] = v15 + 2;
      v15[3] = v15 + 2;
      v15[20] = v15 + 20;
      v15[21] = v15 + 20;
      if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) == 0x98 )
        goto LABEL_134;
      v15[19] = 0;
      if ( a2[17] )
      {
        v18 = *v11;
        if ( *v11 )
        {
          while ( 1 )
          {
            v19 = cmp_bss(v8, v18 + 80, 1);
            if ( !v19 )
              break;
            if ( v19 >= 0 )
              v20 = 8;
            else
              v20 = 16;
            v18 = *(_QWORD *)(v18 + v20);
            if ( !v18 )
              goto LABEL_34;
          }
          v27 = (_QWORD *)(v18 - 32);
          if ( v18 != 32 )
            goto LABEL_42;
LABEL_34:
          v28 = *v11;
          if ( !*v11 )
            goto LABEL_51;
          while ( 1 )
          {
            v29 = cmp_bss(v8, v28 + 80, 2);
            if ( !v29 )
              break;
            if ( v29 >= 0 )
              v30 = 8;
            else
              v30 = 16;
            v28 = *(_QWORD *)(v28 + v30);
            if ( !v28 )
              goto LABEL_51;
          }
          v27 = (_QWORD *)(v28 - 32);
          if ( v28 == 32 )
            goto LABEL_51;
LABEL_42:
          if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) == 0x90 )
            goto LABEL_134;
          v15[18] = v27 + 14;
          v31 = v27 + 2;
          v32 = v27[2];
          if ( *(_QWORD **)(v32 + 8) != v27 + 2 || v15 == v27 || v32 == v4 )
          {
            _list_add_valid_or_report(v15 + 2, v31);
          }
          else
          {
            *(_QWORD *)(v32 + 8) = v4;
            if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) == 0x10 )
              goto LABEL_134;
            *(_QWORD *)v4 = v32;
            if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
              goto LABEL_134;
            v15[3] = v31;
            *v31 = v4;
          }
          ++v27[9];
          v33 = v15[16];
          atomic_store(v27[16], v15 + 16);
          if ( v33 )
            kvfree_call_rcu(v33 + 8, v33);
        }
        goto LABEL_51;
      }
      v21 = v15[16];
      if ( !v21 )
      {
        __break(0x800u);
        if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x90 )
        {
          v76 = v15[18];
          if ( v76 )
          {
            v77 = *(_QWORD *)(v76 - 40) - 1LL;
            *(_QWORD *)(v76 - 40) = v77;
            if ( !v77 )
              bss_free(v76 - 112);
          }
          if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x98 )
          {
            v78 = v15[19];
            if ( v78 )
            {
              v79 = *(_QWORD *)(v78 - 40) - 1LL;
              *(_QWORD *)(v78 - 40) = v79;
              if ( !v79 )
                bss_free(v78 - 112);
            }
            if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x48 )
            {
LABEL_99:
              v54 = v15[9] - 1LL;
              v15[9] = v54;
              if ( !v54 )
                bss_free(v15);
              return nullptr;
            }
          }
        }
        goto LABEL_134;
      }
      v22 = *(unsigned int *)(v21 + 24);
      if ( (unsigned int)v22 < 2 )
      {
LABEL_51:
        if ( *(_DWORD *)(a1 + 220) >= (unsigned int)bss_entries_limit )
        {
          v34 = *(__int64 **)(a1 + 192);
          if ( v34 == (__int64 *)(a1 + 192) )
            goto LABEL_90;
          v35 = nullptr;
          do
          {
            if ( !*((_DWORD *)v34 + 20) && ((__int64 *)v34[2] == v34 + 2 || v34[18]) && (!v35 || v35[8] - v34[8] >= 0) )
              v35 = v34;
            v34 = (__int64 *)*v34;
          }
          while ( v34 != (__int64 *)(a1 + 192) );
          if ( !v35 || (_cfg80211_unlink_bss(a1) & 1) == 0 )
            goto LABEL_90;
        }
        v36 = a2[19];
        if ( !v36 )
        {
LABEL_70:
          v40 = *v11;
          if ( *v11 )
          {
            v41 = v11;
            while ( 1 )
            {
              v42 = v40;
              v43 = cmp_bss(v15 + 14, v40 + 80, 0);
              if ( !v43 )
                break;
              v44 = *v41;
              if ( v43 >= 0 )
                v45 = 8;
              else
                v45 = 16;
              v41 = (__int64 *)(v44 + v45);
              v40 = *(_QWORD *)(v44 + v45);
              if ( !v40 )
                goto LABEL_79;
            }
            __break(0x800u);
            goto LABEL_86;
          }
          v42 = 0;
          v41 = v11;
LABEL_79:
          if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x20 )
          {
            v15[5] = 0;
            v15[6] = 0;
            v15[4] = v42;
            *v41 = (__int64)(v15 + 4);
            rb_insert_color();
            v46 = a1 + 192;
            v47 = *(_QWORD **)(a1 + 200);
            if ( (_QWORD *)(a1 + 192) == v15 || v47 == v15 || *v47 != v46 )
            {
              _list_add_valid_or_report(v15, v47);
              goto LABEL_85;
            }
            *(_QWORD *)(a1 + 200) = v15;
            *v15 = v46;
            if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) != 8 )
            {
              v15[1] = v47;
              *v47 = v15;
LABEL_85:
              ++*(_DWORD *)(a1 + 220);
              goto LABEL_86;
            }
          }
          goto LABEL_134;
        }
        if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x98 )
        {
          v37 = a2[19];
          v15[19] = v36;
          v38 = *(_QWORD *)(v37 + 32);
          ++*(_QWORD *)(v37 - 40);
          if ( v38 )
            ++*(_QWORD *)(v38 - 40);
          v39 = *(_QWORD *)(v37 + 40);
          if ( v39 )
            ++*(_QWORD *)(v39 - 40);
          goto LABEL_70;
        }
        while ( 1 )
        {
LABEL_134:
          __break(1u);
LABEL_90:
          __break(0x800u);
          if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x90 )
          {
            v50 = v15[18];
            if ( v50 )
            {
              v51 = *(_QWORD *)(v50 - 40) - 1LL;
              *(_QWORD *)(v50 - 40) = v51;
              if ( !v51 )
                bss_free(v50 - 112);
            }
            if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x98 )
            {
              v52 = v15[19];
              if ( v52 )
              {
                v53 = *(_QWORD *)(v52 - 40) - 1LL;
                *(_QWORD *)(v52 - 40) = v53;
                if ( !v53 )
                  bss_free(v52 - 112);
              }
              if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x48 )
                break;
            }
          }
        }
        goto LABEL_99;
      }
      v23 = (_BYTE *)(v21 + 29);
      v24 = v15 + 14;
      v25 = &v23[v22];
      while ( 1 )
      {
        v26 = (unsigned __int8)v23[1];
        if ( v22 < v26 + 2 )
          goto LABEL_51;
        if ( !*v23 )
          break;
        v23 += v26 + 2;
        v22 = v25 - v23;
        if ( v25 - v23 <= 1 )
          goto LABEL_51;
      }
      if ( !v23 )
        goto LABEL_51;
      if ( !v23[1] )
      {
LABEL_111:
        v5 = (_QWORD *)(a1 + 192);
        v67 = *(_QWORD **)(a1 + 192);
        if ( v67 == (_QWORD *)(a1 + 192) )
        {
          v68 = 0;
LABEL_114:
          v72 = *(_DWORD *)(a1 + 220);
          if ( v68 != v72 && (cfg80211_combine_bsses___already_done & 1) == 0 )
          {
            cfg80211_combine_bsses___already_done = 1;
            _warn_printk("rdev bss entries[%d]/list[len:%d] corruption\n", v72, v68);
            __break(0x800u);
          }
          goto LABEL_51;
        }
        v68 = 0;
        v6 = v16 & 0xFFFFFFFFFFFFFFFCLL;
        v69 = v16 & 0xFFFFFFFFFFFFFFFELL;
        v70 = v16 & 0xFFFFFFFFFFFFFFF8LL;
        v71 = 0xDEAD000000000122LL;
        while ( v6 != 184 && v69 != 188 )
        {
          if ( !(*((_DWORD *)v15 + 46) ^ *((_DWORD *)v67 + 46)
               | *((unsigned __int16 *)v15 + 94) ^ *((unsigned __int16 *)v67 + 94)) )
          {
            if ( v70 == 112 )
              goto LABEL_134;
            if ( v67[14] == *v24 && !v67[16] )
            {
              v80 = v67[15];
              if ( v80 )
              {
                v81 = *(unsigned int *)(v80 + 24);
                if ( (unsigned int)v81 >= 2 )
                {
                  v82 = (_BYTE *)(v80 + 29);
                  v83 = &v82[v81];
                  do
                  {
                    v84 = (unsigned __int8)v82[1];
                    if ( v81 < v84 + 2 )
                      break;
                    if ( !*v82 )
                    {
                      if ( (_DWORD)v26 )
                        v85 = (_DWORD)v84 == (_DWORD)v26;
                      else
                        v85 = 1;
                      v86 = v85;
                      if ( !v82 || !v86 )
                        break;
                      if ( v67[18] )
                        goto LABEL_138;
                      v87 = v67 + 2;
                      if ( (_QWORD *)v67[2] == v67 + 2 )
                      {
                        if ( v70 == 16 )
                          goto LABEL_134;
                      }
                      else
                      {
                        __break(0x800u);
                        v94 = v68;
                        v92 = v24;
                        v93 = v26;
                        v95 = v67;
                        v97 = v69;
                        v98 = v70;
                        v96 = v71;
                        _list_del_entry(v67 + 2);
                        v67 = v95;
                        v71 = v96;
                        v69 = v97;
                        v70 = v98;
                        v26 = v93;
                        v68 = v94;
                        v24 = v92;
                        v95[2] = 0xDEAD000000000100LL;
                        v95[3] = v96;
                        if ( v98 == 16 )
                          goto LABEL_134;
                      }
                      v88 = *(_QWORD **)v4;
                      if ( *(_QWORD *)(*(_QWORD *)v4 + 8LL) != v4 || v67 == v15 || v88 == v87 )
                      {
                        v89 = v87;
                        v90 = v68;
                        v91 = v71;
                        _list_add_valid_or_report(v89, v4);
                        v71 = v91;
                        v68 = v90;
                      }
                      else
                      {
                        v88[1] = v87;
                        v67[2] = v88;
                        v67[3] = v4;
                        *(_QWORD *)v4 = v87;
                      }
                      v67[18] = v24;
                      if ( v70 != 72 )
                      {
                        v15[9] += v67[9];
                        if ( v70 != 128 )
                        {
                          atomic_store(v15[16], v67 + 16);
                          break;
                        }
                      }
                      goto LABEL_134;
                    }
                    v82 += v84 + 2;
                    v81 = v83 - v82;
                  }
                  while ( v83 - v82 > 1 );
                }
              }
            }
          }
LABEL_139:
          v67 = (_QWORD *)*v67;
          ++v68;
          if ( v67 == v5 )
            goto LABEL_114;
        }
        goto LABEL_134;
      }
      if ( (_DWORD)v26 == 1 )
      {
        v55 = 0;
        v56 = 0;
      }
      else
      {
        v55 = (unsigned __int8)v26 & 0xFE;
        v57 = 0;
        v58 = 0;
        v59 = v23 + 3;
        v60 = v55;
        do
        {
          v61 = *(v59 - 1);
          v62 = *v59;
          v59 += 2;
          v60 -= 2;
          v57 |= v61;
          v58 |= v62;
        }
        while ( v60 );
        v56 = v58 | v57;
        if ( v55 == v26 )
        {
LABEL_110:
          if ( v56 )
            goto LABEL_51;
          goto LABEL_111;
        }
      }
      v63 = &v23[v55];
      v64 = v26 - v55;
      v65 = v63 + 2;
      do
      {
        v66 = *v65++;
        --v64;
        v56 |= v66;
      }
      while ( v64 );
      goto LABEL_110;
    }
LABEL_119:
    v73 = a2[16];
    if ( v73 )
      kvfree_call_rcu(v73 + 8, v73);
    v74 = a2[17];
    if ( v74 )
      kvfree_call_rcu(v74 + 8, v74);
    return nullptr;
  }
  if ( (cfg80211_update_known_bss(v15, a2, a3 & 1) & 1) == 0 )
    return nullptr;
LABEL_86:
  ++*(_DWORD *)(a1 + 216);
  v48 = v15[18];
  ++v15[9];
  if ( v48 )
    ++*(_QWORD *)(v48 - 40);
  v49 = v15[19];
  if ( v49 )
    ++*(_QWORD *)(v49 - 40);
  return v15;
}
