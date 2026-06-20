__int64 __fastcall sde_rm_init(char *s)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x22
  void *v5; // x8
  unsigned __int64 v6; // x0
  unsigned int v7; // w22
  unsigned __int64 v8; // x25
  unsigned int *v9; // x26
  unsigned int v10; // w0
  int v11; // w9
  unsigned int v12; // w8
  unsigned __int64 v13; // x23
  __int64 v14; // x24
  unsigned int v15; // w0
  unsigned __int64 v16; // x23
  __int64 v17; // x24
  unsigned int v18; // w0
  unsigned __int64 v19; // x23
  __int64 v20; // x24
  unsigned int v21; // w0
  unsigned __int64 v22; // x23
  __int64 v23; // x24
  unsigned int v24; // w0
  unsigned __int64 v25; // x23
  __int64 v26; // x24
  unsigned int v27; // w0
  unsigned __int64 v28; // x23
  _DWORD *v29; // x25
  unsigned int v30; // w0
  unsigned __int64 v31; // x23
  __int64 v32; // x24
  unsigned int v33; // w0
  unsigned __int64 v34; // x23
  __int64 v35; // x24
  unsigned int v36; // w0
  _DWORD *v37; // x26
  unsigned __int64 v38; // x23
  int v39; // w28
  __int64 v40; // x23
  char *v41; // x24
  __int64 v42; // x25
  void *v43; // x0
  const char *v44; // x1
  __int64 v45; // x1
  unsigned __int64 v46; // x23
  __int64 v47; // x24
  unsigned int v48; // w0
  unsigned __int64 v49; // x23
  __int64 v50; // x24
  unsigned int v51; // w0
  unsigned __int64 v52; // x23
  __int64 v53; // x24
  unsigned int v54; // w0
  __int64 v56; // [xsp+8h] [xbp-38h] BYREF
  __int64 v57; // [xsp+10h] [xbp-30h]
  int v58; // [xsp+18h] [xbp-28h]
  int v59; // [xsp+1Ch] [xbp-24h]
  __int64 v60; // [xsp+20h] [xbp-20h] BYREF
  __int64 v61; // [xsp+28h] [xbp-18h]
  int v62; // [xsp+30h] [xbp-10h]
  int v63; // [xsp+34h] [xbp-Ch]
  __int64 v64; // [xsp+38h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( s && (v2 = *((_QWORD *)s - 249)) != 0 && (v3 = *((_QWORD *)s - 49)) != 0 && (v4 = *((_QWORD *)s - 251)) != 0 )
  {
    memset(s, 0, 0x180u);
    _mutex_init(s + 280, "&rm->rm_lock", &sde_rm_init___key);
    *((_QWORD *)s + 1) = s + 8;
    *((_QWORD *)s + 2) = s + 8;
    *((_QWORD *)s + 3) = s + 24;
    *((_QWORD *)s + 4) = s + 24;
    *((_QWORD *)s + 5) = s + 40;
    *((_QWORD *)s + 6) = s + 40;
    *((_QWORD *)s + 7) = s + 56;
    *((_QWORD *)s + 8) = s + 56;
    *((_QWORD *)s + 9) = s + 72;
    *((_QWORD *)s + 10) = s + 72;
    *((_QWORD *)s + 11) = s + 88;
    *((_QWORD *)s + 12) = s + 88;
    *((_QWORD *)s + 13) = s + 104;
    *((_QWORD *)s + 14) = s + 104;
    *((_QWORD *)s + 15) = s + 120;
    *((_QWORD *)s + 16) = s + 120;
    *((_QWORD *)s + 17) = s + 136;
    *((_QWORD *)s + 18) = s + 136;
    *((_QWORD *)s + 19) = s + 152;
    *((_QWORD *)s + 20) = s + 152;
    *((_QWORD *)s + 21) = s + 168;
    *((_QWORD *)s + 22) = s + 168;
    *((_QWORD *)s + 23) = s + 184;
    *((_QWORD *)s + 24) = s + 184;
    *((_QWORD *)s + 25) = s + 200;
    *((_QWORD *)s + 26) = s + 200;
    *((_QWORD *)s + 27) = s + 216;
    *((_QWORD *)s + 28) = s + 216;
    *((_QWORD *)s + 29) = s + 232;
    *((_QWORD *)s + 30) = s + 232;
    *((_QWORD *)s + 31) = s + 248;
    *((_QWORD *)s + 32) = s + 248;
    *(_QWORD *)s = v4;
    *((_DWORD *)s + 94) = *(_DWORD *)(*(_QWORD *)(v4 + 56) + 5912LL);
    v5 = &g_top_table_v1;
    if ( *(_DWORD *)(v2 + 28) != 256 )
      v5 = &g_top_table;
    *((_QWORD *)s + 41) = v5;
    v6 = sde_hw_mdptop_init(1, v3, v2);
    v7 = v6;
    *((_QWORD *)s + 33) = v6;
    if ( !v6 || v6 > 0xFFFFFFFFFFFFF000LL )
    {
      *((_QWORD *)s + 33) = 0;
      v43 = &unk_24CB42;
      v44 = "sde_rm_init";
      goto LABEL_115;
    }
    if ( *(_DWORD *)(v2 + 6952) )
    {
      v8 = 0;
      v9 = (unsigned int *)(v2 + 6976);
      while ( v9[11] != 14 )
      {
        if ( v8 == 12 )
          goto LABEL_118;
        v10 = sde_rm_hw_blk_create(s, v2, v3, 2, *v9);
        if ( v10 )
        {
          v7 = v10;
          v43 = &unk_219B20;
          v44 = "sde_rm_init";
          goto LABEL_115;
        }
        v11 = *((_DWORD *)s + 68);
        v12 = **((_DWORD **)v9 + 4);
        if ( !v11
          || v11 != v12 && (printk(&unk_269129, "sde_rm_init"), v12 = **((_DWORD **)v9 + 4), *((_DWORD *)s + 68) > v12) )
        {
          *((_DWORD *)s + 68) = v12;
        }
        ++v8;
        v9 += 24;
        if ( v8 >= *(unsigned int *)(v2 + 6952) )
          goto LABEL_20;
      }
      printk(&unk_242E5A, "sde_rm_init");
      v7 = 0;
      goto LABEL_116;
    }
LABEL_20:
    if ( *(_DWORD *)(v2 + 8160) )
    {
      v13 = 0;
      v14 = 8184;
      while ( v13 != 12 )
      {
        v15 = sde_rm_hw_blk_create(s, v2, v3, 3, *(unsigned int *)(v2 + v14));
        if ( v15 )
        {
          v7 = v15;
          v43 = &unk_23530E;
          v44 = "_sde_rm_hw_blk_create_new";
          goto LABEL_115;
        }
        ++v13;
        v14 += 56;
        if ( v13 >= *(unsigned int *)(v2 + 8160) )
          goto LABEL_25;
      }
LABEL_118:
      __break(0x5512u);
    }
LABEL_25:
    if ( *(_BYTE *)(v2 + 708) == 1 && *(_DWORD *)(v2 + 8840) )
    {
      v16 = 0;
      v17 = 8864;
      while ( 1 )
      {
        if ( v16 == 12 )
          goto LABEL_118;
        v18 = sde_rm_hw_blk_create(s, v2, v3, 4, *(unsigned int *)(v2 + v17));
        if ( v18 )
          break;
        ++v16;
        v17 += 64;
        if ( v16 >= *(unsigned int *)(v2 + 8840) )
          goto LABEL_31;
      }
      v7 = v18;
      v43 = &unk_21273A;
      v44 = "_sde_rm_hw_blk_create_new";
      goto LABEL_115;
    }
LABEL_31:
    if ( *(_DWORD *)(v2 + 9616) )
    {
      v19 = 0;
      v20 = 9640;
      while ( v19 != 12 )
      {
        v21 = sde_rm_hw_blk_create(s, v2, v3, 7, *(unsigned int *)(v2 + v20));
        if ( v21 )
        {
          v7 = v21;
          v43 = &unk_22E3C5;
          v44 = "_sde_rm_hw_blk_create_new";
          goto LABEL_115;
        }
        ++v19;
        v20 += 64;
        if ( v19 >= *(unsigned int *)(v2 + 9616) )
          goto LABEL_36;
      }
      goto LABEL_118;
    }
LABEL_36:
    if ( *(_DWORD *)(v2 + 10392) )
    {
      v22 = 0;
      v23 = 10416;
      while ( v22 != 12 )
      {
        v24 = sde_rm_hw_blk_create(s, v2, v3, 10, *(unsigned int *)(v2 + v23));
        if ( v24 )
        {
          v7 = v24;
          v43 = &unk_235346;
          v44 = "_sde_rm_hw_blk_create_new";
          goto LABEL_115;
        }
        ++v22;
        v23 += 64;
        if ( v22 >= *(unsigned int *)(v2 + 10392) )
          goto LABEL_41;
      }
      goto LABEL_118;
    }
LABEL_41:
    if ( *(_DWORD *)(v2 + 11168) )
    {
      v25 = 0;
      v26 = 11192;
      while ( v25 != 12 )
      {
        v27 = sde_rm_hw_blk_create(s, v2, v3, 11, *(unsigned int *)(v2 + v26));
        if ( v27 )
        {
          v7 = v27;
          v43 = &unk_2572B0;
          v44 = "_sde_rm_hw_blk_create_new";
          goto LABEL_115;
        }
        ++v25;
        v26 += 56;
        if ( v25 >= *(unsigned int *)(v2 + 11168) )
          goto LABEL_46;
      }
      goto LABEL_118;
    }
LABEL_46:
    if ( *(_DWORD *)(v2 + 13400) )
    {
      v28 = 0;
      v29 = (_DWORD *)(v2 + 13456);
      do
      {
        if ( v28 == 12 )
          goto LABEL_118;
        if ( *v29 )
        {
          v30 = sde_rm_hw_blk_create(s, v2, v3, 8, (unsigned int)*(v29 - 8));
          if ( v30 )
          {
            v7 = v30;
            v43 = &unk_2160E5;
            v44 = "_sde_rm_hw_blk_create_new";
            goto LABEL_115;
          }
        }
        else if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "skip intf %d with type none\n", v28);
        }
        ++v28;
        v29 += 18;
      }
      while ( v28 < *(unsigned int *)(v2 + 13400) );
    }
    if ( *(_DWORD *)(v2 + 14272) )
    {
      v31 = 0;
      v32 = 14296;
      while ( 1 )
      {
        if ( v31 == 12 )
          goto LABEL_118;
        v33 = sde_rm_hw_blk_create(s, v2, v3, 9, *(unsigned int *)(v2 + v32));
        if ( v33 )
          break;
        ++v31;
        v32 += 88;
        if ( v31 >= *(unsigned int *)(v2 + 14272) )
          goto LABEL_59;
      }
      v7 = v33;
      v43 = &unk_227796;
      v44 = "_sde_rm_hw_blk_create_new";
      goto LABEL_115;
    }
LABEL_59:
    if ( *(_DWORD *)(v2 + 5448) )
    {
      v34 = 0;
      v35 = 5472;
      while ( 1 )
      {
        if ( v34 == 12 )
          goto LABEL_118;
        v36 = sde_rm_hw_blk_create(s, v2, v3, 5, *(unsigned int *)(v2 + v35));
        if ( v36 )
          break;
        ++v34;
        v35 += 48;
        if ( v34 >= *(unsigned int *)(v2 + 5448) )
          goto LABEL_64;
      }
      v7 = v36;
      v43 = &unk_269164;
      v44 = "_sde_rm_hw_blk_create_new";
      goto LABEL_115;
    }
LABEL_64:
    v37 = (_DWORD *)(v2 + 19288);
    if ( *(_DWORD *)(v2 + 52) )
    {
      v38 = *(_QWORD *)(v2 + 22008);
      v39 = *(_DWORD *)(v2 + 22136);
      v57 = 0;
      v58 = 0;
      v56 = 0;
      v59 = 5;
      if ( (sde_rm_get_hw_locked((__int64)s, (__int64)&v56, 1) & 1) != 0 )
      {
        v40 = (v38 >> 43) & 1;
        v41 = s - 440;
        while ( 1 )
        {
          v42 = *(_QWORD *)(v57 + 40);
          if ( !*(_QWORD *)v41 || !*(_QWORD *)(*(_QWORD *)v41 + 256LL) )
            break;
          if ( (unsigned int)sde_hw_fence_init(*(_QWORD *)(v57 + 40), s - 2144, (unsigned int)v40, v39 != 0) )
          {
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "failed to init hw_fence idx:%d\n", *(unsigned int *)(v42 + 64));
            goto LABEL_89;
          }
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "init hw-fence for ctl %d", *(_DWORD *)(v57 + 36));
          if ( (sde_rm_get_hw_locked((__int64)s, (__int64)&v56, 1) & 1) == 0 )
            goto LABEL_96;
        }
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "failed to init hw_fence idx:%d, no aspace to map memory\n",
            *(unsigned int *)(v42 + 64));
LABEL_89:
        v61 = 0;
        v62 = 0;
        v60 = 0;
        v63 = 5;
        while ( (sde_rm_get_hw_locked((__int64)s, (__int64)&v60, 1) & 1) != 0 )
          sde_hw_fence_deinit(*(_QWORD *)(v61 + 40));
        if ( (_drm_debug & 4) != 0 )
          printk(&unk_212770, v45);
        else
          printk(&unk_2624D3, "_sde_rm_hw_blk_create_new");
        *(_DWORD *)(v2 + 52) = 0;
      }
    }
LABEL_96:
    if ( *(_DWORD *)(v2 + 11848) )
    {
      v46 = 0;
      v47 = 11872;
      while ( 1 )
      {
        if ( v46 == 12 )
          goto LABEL_118;
        v48 = sde_rm_hw_blk_create(s, v2, v3, 6, *(unsigned int *)(v2 + v47));
        if ( v48 )
          break;
        ++v46;
        v47 += 64;
        if ( v46 >= *(unsigned int *)(v2 + 11848) )
          goto LABEL_101;
      }
      v7 = v48;
      v43 = &unk_265ABC;
      v44 = "_sde_rm_hw_blk_create_new";
      goto LABEL_115;
    }
LABEL_101:
    if ( *(_DWORD *)(v2 + 12624) )
    {
      v49 = 0;
      v50 = 12648;
      while ( 1 )
      {
        if ( v49 == 12 )
          goto LABEL_118;
        v51 = sde_rm_hw_blk_create(s, v2, v3, 14, *(unsigned int *)(v2 + v50));
        if ( v51 )
          break;
        ++v49;
        v50 += 64;
        if ( v49 >= *(unsigned int *)(v2 + 12624) )
          goto LABEL_106;
      }
      v7 = v51;
      v43 = &unk_2277CC;
      v44 = "_sde_rm_hw_blk_create_new";
      goto LABEL_115;
    }
LABEL_106:
    if ( *v37 )
    {
      v52 = 0;
      v53 = 19312;
      while ( 1 )
      {
        if ( v52 == 12 )
          goto LABEL_118;
        v54 = sde_rm_hw_blk_create(s, v2, v3, 13, *(unsigned int *)(v2 + v53));
        if ( v54 )
          break;
        ++v52;
        v53 += 48;
        if ( v52 >= (unsigned int)*v37 )
          goto LABEL_111;
      }
      v7 = v54;
      v43 = &unk_27A43E;
      v44 = "_sde_rm_hw_blk_create_new";
LABEL_115:
      printk(v43, v44);
LABEL_116:
      sde_rm_destroy((__int64)s);
      goto LABEL_117;
    }
LABEL_111:
    v7 = 0;
  }
  else
  {
    printk(&unk_21DA28, "sde_rm_init");
    v7 = -22;
  }
LABEL_117:
  _ReadStatusReg(SP_EL0);
  return v7;
}
