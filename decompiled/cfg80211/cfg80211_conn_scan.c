__int64 __fastcall cfg80211_conn_scan(__int64 **a1)
{
  size_t v1; // x22
  __int64 *v2; // x23
  __int64 **v3; // x24
  __int64 *v4; // x19
  unsigned __int64 v6; // x21
  __int64 v7; // x20
  unsigned int **v8; // x9
  __int64 **v9; // x8
  unsigned int *v10; // x10
  __int64 v11; // x9
  __int64 v12; // x11
  unsigned __int64 v13; // x12
  bool v14; // cf
  unsigned __int64 v15; // x12
  unsigned __int64 v16; // x9
  __int64 *v17; // x11
  unsigned __int64 v18; // x9
  size_t v19; // x1
  size_t v20; // x2
  unsigned __int64 v21; // x1
  unsigned int v22; // w0
  unsigned int v23; // w19
  __int64 v24; // x9
  __int64 v25; // x12
  __int64 v26; // x14
  int v27; // w17
  __int64 v28; // x15
  __int64 v29; // x16
  char *v30; // x0
  char *v31; // x0
  char v32; // t1
  unsigned __int64 v33; // x17
  unsigned __int64 v34; // x16
  __int64 v35; // x0
  __int64 v36; // x1
  __int64 v37; // x2
  __int64 *v38; // x9
  unsigned __int64 v39; // x8
  __int64 v40; // x9
  unsigned int *v41; // x9
  unsigned int v42; // w12
  __int64 v43; // x9
  unsigned __int64 StatusReg; // x25
  __int64 v45; // x26

  v4 = *a1;
  if ( !*a1 )
    goto LABEL_70;
  v2 = v4 - 96;
  if ( *(v4 - 96) || *(v4 - 94) )
    return 4294967280LL;
  v3 = a1;
  if ( *a1[10] )
    LODWORD(v1) = 1;
  else
    LODWORD(v1) = ieee80211_get_num_supported_channels(*a1);
  v6 = 8LL * (int)v1 + 193;
  v7 = _kmalloc_noprof(v6, 3520);
  if ( !v7 )
    return 4294967284LL;
  while ( 1 )
  {
    if ( v6 < 0xC || (v6 & 0xFFFFFFFFFFFFFFFCLL) == 0xC )
      goto LABEL_58;
    v8 = (unsigned int **)v3[10];
    *(_DWORD *)(v7 + 12) = v1;
    v9 = v3;
    v10 = *v8;
    if ( !*v8 )
    {
      v24 = 0;
      LODWORD(v1) = 0;
      v25 = (__int64)(*v3 + 41);
      while ( 1 )
      {
        v26 = *(_QWORD *)(v25 + 8 * v24);
        if ( v26 )
        {
          v27 = *(_DWORD *)(v26 + 20);
          if ( v27 >= 1 )
          {
            v28 = 0;
            v29 = 12;
            do
            {
              v30 = (char *)(*(_QWORD *)v26 + v29);
              v32 = *v30;
              v31 = v30 - 12;
              if ( (v32 & 1) == 0 )
              {
                if ( (int)v1 < -20 )
                  goto LABEL_58;
                v33 = 8LL * (int)v1 + 160;
                if ( v6 < v33 || v6 - v33 < 8 )
                  goto LABEL_58;
                *(_QWORD *)(v7 + 160 + 8LL * (int)v1) = v31;
                v27 = *(_DWORD *)(v26 + 20);
                LODWORD(v1) = v1 + 1;
              }
              ++v28;
              v29 += 64;
            }
            while ( v28 < v27 );
          }
          v34 = 4 * v24 + 40;
          if ( (v34 & 0x8000000000000000LL) != 0 || v6 < v34 || v6 - v34 < 4 )
            goto LABEL_58;
          *(_DWORD *)(v7 + 40 + 4 * v24) = ~(-1 << *(_DWORD *)(v26 + 24));
        }
        if ( ++v24 == 6 )
          goto LABEL_20;
      }
    }
    v11 = *v10;
    if ( (unsigned int)v11 < 6 )
      break;
LABEL_69:
    __break(0x5512u);
LABEL_70:
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v45 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cfg80211_conn_scan__alloc_tag;
    v6 = 8LL * (int)v1 + 193;
    v7 = _kmalloc_noprof(v6, 3520);
    *(_QWORD *)(StatusReg + 80) = v45;
    if ( !v7 )
      return 4294967284LL;
  }
  v12 = (*v3)[v11 + 41];
  if ( !v12 )
  {
    kfree(v7);
    return 4294967274LL;
  }
  if ( v6 < 0xA0 )
    goto LABEL_58;
  if ( (v6 & 0xFFFFFFFFFFFFFFF8LL) == 0xA0 )
    goto LABEL_58;
  *(_QWORD *)(v7 + 160) = v10;
  v13 = 4 * v11 + 40;
  v14 = v6 >= v13;
  v15 = v6 - v13;
  if ( !v14 || v15 < 4 )
    goto LABEL_58;
  *(_DWORD *)(v7 + 4 * v11 + 40) = ~(-1 << *(_DWORD *)(v12 + 24));
LABEL_20:
  if ( (v6 & 0xFFFFFFFFFFFFFFFCLL) == 0xC )
    goto LABEL_58;
  *(_DWORD *)(v7 + 12) = v1;
  v16 = 8LL * (int)v1 + 160;
  if ( (v1 & 0x80000000) != 0LL )
    v16 = -1;
  *(_QWORD *)v7 = v7 + v16;
  if ( (v6 & 0xFFFFFFFFFFFFFFFCLL) == 8 )
    goto LABEL_58;
  v17 = v3[10];
  v14 = v6 >= v16;
  v18 = v6 - v16;
  *(_DWORD *)(v7 + 8) = 1;
  if ( v14 )
    v19 = v18;
  else
    v19 = 0;
  v20 = v17[5];
  if ( v19 < v20 )
  {
    _fortify_panic(17, v19);
LABEL_68:
    _fortify_panic(15, v21);
    goto LABEL_69;
  }
  if ( v20 >= 0x21 && (cfg80211_conn_scan___already_done & 1) == 0 )
  {
    cfg80211_conn_scan___already_done = 1;
    v1 = v20;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v20,
      "field \"request->ssids[0].ssid\" at ../soc-repo/net/wireless/sme.c:124",
      0x20u);
    v20 = v1;
    v9 = v3;
    __break(0x800u);
  }
  memcpy(*(void **)v7, (const void *)v9[10][4], v20);
  if ( v6 >= 0x54 )
    v21 = v6 - 84;
  else
    v21 = 0;
  *(_BYTE *)(*(_QWORD *)v7 + 32LL) = v3[10][5];
  if ( v21 <= 5 )
    goto LABEL_68;
  *(_WORD *)(v7 + 88) = -1;
  *(_DWORD *)(v7 + 84) = -1;
  if ( v6 < 0x40
    || (v6 & 0xFFFFFFFFFFFFFFF8LL) == 0x40
    || (*(_QWORD *)(v7 + 64) = v3, v6 < 0x60)
    || (v6 & 0xFFFFFFFFFFFFFFF8LL) == 0x60
    || (*(_QWORD *)(v7 + 96) = v4, v6 < 0x68)
    || (v6 & 0xFFFFFFFFFFFFFFF8LL) == 0x68 )
  {
LABEL_58:
    __break(1u);
    goto LABEL_59;
  }
  v4 -= 124;
  *(_QWORD *)(v7 + 104) = jiffies;
  *v2 = v7;
  v22 = cfg80211_scan(v4);
  if ( v22 )
  {
    v23 = v22;
    *v2 = 0;
    kfree(v7);
    return v23;
  }
LABEL_59:
  *((_DWORD *)v3[10] + 100) = 0;
  v35 = nl80211_send_scan_start((__int64)v4, (__int64)v3);
  v38 = v3[4];
  if ( !v38 )
    return 0;
  v39 = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(v39 + 16);
  v40 = v38[165];
  v41 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v40);
  do
    v42 = __ldxr(v41);
  while ( __stxr(v42 + 1, v41) );
  v43 = *(_QWORD *)(v39 + 16) - 1LL;
  *(_DWORD *)(v39 + 16) = v43;
  if ( v43 )
  {
    if ( *(_QWORD *)(v39 + 16) )
      return 0;
  }
  preempt_schedule_notrace(v35, v36, v37);
  return 0;
}
