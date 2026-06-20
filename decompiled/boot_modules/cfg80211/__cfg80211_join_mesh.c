__int64 __fastcall _cfg80211_join_mesh(__int64 a1, __int64 a2, unsigned int **a3, __int64 a4)
{
  __int64 v4; // x23
  unsigned int v5; // w8
  unsigned int *v7; // x9
  unsigned int *v8; // x8
  unsigned int *v9; // x11
  unsigned int **v10; // x9
  __int64 v11; // x8
  unsigned int **v12; // x9
  __int64 v13; // x8
  unsigned int **v14; // x9
  __int64 v15; // x8
  unsigned int **v16; // x9
  __int64 v17; // x8
  unsigned int **v18; // x9
  __int64 v19; // x8
  unsigned int **v20; // x8
  __int64 v21; // x10
  __int64 v22; // x9
  __int64 v23; // x8
  __int64 v24; // x19
  unsigned int **v25; // x20
  __int64 v26; // x22
  __int64 v27; // x21
  int v28; // w0
  __int64 v29; // x8
  __int64 v30; // x21
  __int64 v31; // x22
  __int64 v32; // x19
  __int64 v33; // x20
  __int64 v34; // x2
  __int64 v35; // x20
  size_t v36; // x2
  __int64 v37; // x9
  __int64 v38; // x11
  __int64 v39; // x12
  __int64 v40; // x9
  __int64 v41; // x10
  unsigned __int16 *v42; // x8
  int v43; // t1
  size_t v44; // x20
  unsigned int v45; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v46; // [xsp+10h] [xbp-10h]
  __int64 v47; // [xsp+18h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 992);
  if ( *(_DWORD *)(v4 + 8) != 7 || (*(_BYTE *)(a1 + 1093) & 4) == 0 && (*((_BYTE *)a3 + 58) & 1) != 0 )
    goto LABEL_10;
  if ( *(_BYTE *)(v4 + 384) )
  {
    v5 = -114;
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return v5;
  }
  if ( !*((_BYTE *)a3 + 40) )
  {
LABEL_71:
    v5 = -22;
    goto LABEL_11;
  }
  if ( !*(_QWORD *)(*(_QWORD *)a1 + 248LL) )
  {
LABEL_10:
    v5 = -95;
    goto LABEL_11;
  }
  if ( (*(_BYTE *)(v4 + 440) & 1) != 0 )
  {
    v5 = -16;
    goto LABEL_11;
  }
  v7 = *a3;
  if ( !*a3 )
  {
    v8 = *(unsigned int **)(v4 + 312);
    v7 = *(unsigned int **)(v4 + 288);
    v9 = *(unsigned int **)(v4 + 296);
    a3[2] = *(unsigned int **)(v4 + 304);
    a3[3] = v8;
    *a3 = v7;
    a3[1] = v9;
    if ( !v7 )
    {
      v10 = *(unsigned int ***)(a1 + 1320);
      if ( !v10 )
        goto LABEL_21;
      v11 = *((unsigned int *)v10 + 5);
      if ( (int)v11 < 1 )
        goto LABEL_21;
      v7 = *v10;
      while ( (v7[3] & 0xB) != 0 )
      {
        --v11;
        v7 += 16;
        if ( !v11 )
          goto LABEL_21;
      }
      *a3 = v7;
      if ( !v7 )
      {
LABEL_21:
        v12 = *(unsigned int ***)(a1 + 1328);
        if ( !v12 )
          goto LABEL_28;
        v13 = *((unsigned int *)v12 + 5);
        if ( (int)v13 < 1 )
          goto LABEL_28;
        v7 = *v12;
        while ( (v7[3] & 0xB) != 0 )
        {
          --v13;
          v7 += 16;
          if ( !v13 )
            goto LABEL_28;
        }
        *a3 = v7;
        if ( !v7 )
        {
LABEL_28:
          v14 = *(unsigned int ***)(a1 + 1336);
          if ( !v14 )
            goto LABEL_35;
          v15 = *((unsigned int *)v14 + 5);
          if ( (int)v15 < 1 )
            goto LABEL_35;
          v7 = *v14;
          while ( (v7[3] & 0xB) != 0 )
          {
            --v15;
            v7 += 16;
            if ( !v15 )
              goto LABEL_35;
          }
          *a3 = v7;
          if ( !v7 )
          {
LABEL_35:
            v16 = *(unsigned int ***)(a1 + 1344);
            if ( !v16 )
              goto LABEL_42;
            v17 = *((unsigned int *)v16 + 5);
            if ( (int)v17 < 1 )
              goto LABEL_42;
            v7 = *v16;
            while ( (v7[3] & 0xB) != 0 )
            {
              --v17;
              v7 += 16;
              if ( !v17 )
                goto LABEL_42;
            }
            *a3 = v7;
            if ( !v7 )
            {
LABEL_42:
              v18 = *(unsigned int ***)(a1 + 1352);
              if ( !v18 )
                goto LABEL_49;
              v19 = *((unsigned int *)v18 + 5);
              if ( (int)v19 < 1 )
                goto LABEL_49;
              v7 = *v18;
              while ( (v7[3] & 0xB) != 0 )
              {
                --v19;
                v7 += 16;
                if ( !v19 )
                  goto LABEL_49;
              }
              *a3 = v7;
              if ( !v7 )
              {
LABEL_49:
                v20 = *(unsigned int ***)(a1 + 1360);
                if ( !v20 )
                  goto LABEL_71;
                v21 = *((unsigned int *)v20 + 5);
                if ( (int)v21 < 1 )
                  goto LABEL_71;
                v7 = *v20;
                while ( (v7[3] & 0xB) != 0 )
                {
                  --v21;
                  v7 += 16;
                  v5 = -22;
                  if ( !v21 )
                    goto LABEL_11;
                }
                *a3 = v7;
                if ( !v7 )
                  goto LABEL_71;
              }
            }
          }
        }
      }
      *((_DWORD *)a3 + 2) = 0;
      *((_DWORD *)a3 + 3) = v7[1];
    }
  }
  if ( *((_DWORD *)a3 + 22) )
    goto LABEL_62;
  v22 = *v7;
  if ( (unsigned int)v22 <= 5 )
  {
    v23 = *(_QWORD *)(a1 + 8 * v22 + 1320);
    if ( (_DWORD)v22 )
    {
      v24 = a1;
      v25 = a3;
      v26 = a4;
      v27 = a2;
      v28 = ieee80211_mandatory_rates(*(_QWORD *)(a1 + 8 * v22 + 1320));
      a2 = v27;
      a4 = v26;
      a3 = v25;
      LODWORD(v29) = v28;
      a1 = v24;
    }
    else
    {
      v40 = *(unsigned int *)(v23 + 24);
      if ( (int)v40 < 1 )
        goto LABEL_62;
      v41 = 0;
      v42 = (unsigned __int16 *)(*(_QWORD *)(v23 + 8) + 4LL);
      while ( 1 )
      {
        v43 = *v42;
        v42 += 6;
        if ( v43 == 10 )
          break;
        if ( v40 == ++v41 )
          goto LABEL_62;
      }
      v29 = 1LL << v41;
    }
    *((_DWORD *)a3 + 22) = v29;
LABEL_62:
    v30 = a2;
    v31 = a1;
    v32 = (__int64)a3;
    v33 = a4;
    v5 = ((__int64 (__fastcall *)(__int64, unsigned int **, __int64))cfg80211_chandef_dfs_required)(a1 + 992, a3, 7);
    if ( (v5 & 0x80000000) != 0 )
      goto LABEL_11;
    if ( !v5 || *(_BYTE *)(v32 + 452) == 1 )
    {
      v45 = 7;
      v46 = 0;
      if ( (cfg80211_reg_check_beaconing(v31 + 992, v32, &v45) & 1) != 0 )
      {
        v34 = v33;
        v35 = v32;
        v5 = rdev_join_mesh(v31, v30, v34, v32);
        if ( !v5 )
        {
          v36 = *(unsigned __int8 *)(v32 + 40);
          if ( v36 >= 0x21 && (_cfg80211_join_mesh___already_done & 1) == 0 )
          {
            _cfg80211_join_mesh___already_done = 1;
            v44 = v36;
            _warn_printk(
              "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
              v36,
              "field \"wdev->u.mesh.id\" at ../soc-repo/net/wireless/mesh.c:216",
              0x20u);
            v36 = v44;
            v35 = v32;
            __break(0x800u);
          }
          memcpy((void *)(v4 + 352), *(const void **)(v35 + 32), v36);
          v5 = 0;
          *(_BYTE *)(v4 + 384) = *(_BYTE *)(v35 + 40);
          v37 = *(_QWORD *)(v35 + 24);
          v38 = *(_QWORD *)v35;
          v39 = *(_QWORD *)(v35 + 8);
          *(_QWORD *)(v4 + 336) = *(_QWORD *)(v35 + 16);
          *(_QWORD *)(v4 + 344) = v37;
          *(_QWORD *)(v4 + 320) = v38;
          *(_QWORD *)(v4 + 328) = v39;
          *(_DWORD *)(v4 + 280) = *(unsigned __int16 *)(v35 + 62);
        }
        goto LABEL_11;
      }
    }
    goto LABEL_71;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))rdev_join_mesh)();
}
