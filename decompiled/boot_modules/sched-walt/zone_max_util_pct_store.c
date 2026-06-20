__int64 __fastcall zone_max_util_pct_store(__int64 a1, const char *a2, __int64 a3)
{
  size_t v5; // x22
  __int64 v6; // x0
  unsigned __int64 v7; // x2
  __int64 v8; // x22
  unsigned __int64 v9; // x23
  _QWORD *v10; // x25
  __int64 v11; // x22
  bool v13; // cf
  bool v14; // cf
  char v15; // w8
  __int64 v16; // x8
  __int64 v17; // x24
  char v18; // w8
  __int64 v19; // x0
  __int64 v20; // x8
  unsigned int v21; // w9
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x22
  __int64 v25; // x8
  char v27; // [xsp+Ch] [xbp-4A4h]
  unsigned int v28; // [xsp+10h] [xbp-4A0h]
  unsigned int v29; // [xsp+14h] [xbp-49Ch]
  unsigned int v30; // [xsp+18h] [xbp-498h]
  unsigned int v31; // [xsp+1Ch] [xbp-494h]
  unsigned int v32; // [xsp+20h] [xbp-490h]
  unsigned int v33; // [xsp+24h] [xbp-48Ch]
  unsigned int v34; // [xsp+28h] [xbp-488h]
  unsigned int v35; // [xsp+2Ch] [xbp-484h]
  char *stringp; // [xsp+40h] [xbp-470h] BYREF
  int v38; // [xsp+4Ch] [xbp-464h] BYREF
  __int64 v39; // [xsp+50h] [xbp-460h]
  __int64 v40; // [xsp+58h] [xbp-458h]
  __int64 v41; // [xsp+60h] [xbp-450h]
  __int64 v42; // [xsp+68h] [xbp-448h]
  __int64 v43; // [xsp+70h] [xbp-440h]
  __int64 v44; // [xsp+78h] [xbp-438h]
  __int64 v45; // [xsp+80h] [xbp-430h]
  __int64 v46; // [xsp+88h] [xbp-428h]
  __int64 v47; // [xsp+90h] [xbp-420h]
  __int64 v48; // [xsp+98h] [xbp-418h]
  _BYTE s[1024]; // [xsp+A0h] [xbp-410h] BYREF
  __int64 v50; // [xsp+4A0h] [xbp-10h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  memset(s, 0, sizeof(s));
  v5 = strlen(a2) + 1;
  stringp = s;
  v6 = strnlen(a2, v5);
  if ( v6 == -1 && v5 != -1 )
  {
LABEL_63:
    _fortify_panic(2, -1, v6 + 1);
    goto LABEL_64;
  }
  if ( v6 == v5 )
    v7 = v5;
  else
    v7 = v6 + 1;
  if ( v7 >= 0x401 )
LABEL_64:
    _fortify_panic(7, 1024, v7);
  sized_strscpy(s, a2);
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  mutex_lock(&zone_max_util_pct_store_target_load_lock);
  v6 = (__int64)strsep(&stringp, " ");
  if ( v6 )
  {
    v8 = 0;
    do
    {
      if ( v8 == 20 )
        goto LABEL_59;
      v6 = kstrtouint(v6, 10, &v38);
      if ( (_DWORD)v6 )
        goto LABEL_59;
      if ( (v8 & 0x3FFFFFFFFFFFFFFFLL) == 0x14 )
        goto LABEL_62;
      v9 = v8 + 1;
      *((_DWORD *)&v39 + v8) = v38;
      v6 = (__int64)strsep(&stringp, " ");
      ++v8;
    }
    while ( v6 );
    if ( (((_DWORD)v9 - 1) & 1) == 0 )
    {
LABEL_59:
      v11 = -22;
      goto LABEL_60;
    }
  }
  else
  {
    v9 = 0;
  }
  v10 = *(_QWORD **)(a1 + 96);
  if ( v10 == (_QWORD *)(a1 + 96) )
    goto LABEL_59;
  v11 = -22;
  v35 = HIDWORD(v39) - 101;
  v34 = HIDWORD(v40) - 101;
  v33 = HIDWORD(v41) - 101;
  v32 = HIDWORD(v42) - 101;
  v13 = v9 >= 0x14 && (unsigned int)(HIDWORD(v48) - 1) >= 0x64 || (unsigned int)(HIDWORD(v47) - 1) >= 0x64;
  v31 = HIDWORD(v43) - 101;
  v14 = v13 && v9 >= 0x12;
  v30 = HIDWORD(v44) - 101;
  v29 = HIDWORD(v45) - 101;
  v15 = !v14;
  v27 = v15 ^ 1;
  v28 = HIDWORD(v46) - 101;
  do
  {
    v16 = *(unsigned int *)(*(v10 - 6) + 28LL);
    if ( (unsigned int)v16 >= 0x20 )
      goto LABEL_61;
    v17 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v16) + 8];
    if ( v9 >= 2 )
    {
      if ( v35 < 0xFFFFFF9C )
        goto LABEL_60;
      if ( v9 >= 4 )
      {
        if ( v34 < 0xFFFFFF9C )
          goto LABEL_60;
        if ( v9 >= 6 )
        {
          if ( v33 < 0xFFFFFF9C )
            goto LABEL_60;
          if ( v9 >= 8 )
          {
            if ( v32 < 0xFFFFFF9C )
              goto LABEL_60;
            if ( v9 >= 0xA )
            {
              if ( v31 < 0xFFFFFF9C )
                goto LABEL_60;
              if ( v9 >= 0xC )
              {
                if ( v30 < 0xFFFFFF9C )
                  goto LABEL_60;
                if ( v9 >= 0xE )
                {
                  if ( v29 < 0xFFFFFF9C )
                    goto LABEL_60;
                  v18 = v27;
                  if ( v28 < 0xFFFFFF9C )
                    v18 = 1;
                  if ( v9 >= 0x10 && (v18 & 1) != 0 )
                    goto LABEL_60;
                }
              }
            }
          }
        }
      }
    }
    v19 = raw_spin_lock_irqsave(v10 + 13);
    *(_QWORD *)(a1 + 224) = -1;
    v10[3] = -1;
    *(_QWORD *)(a1 + 232) = -1;
    v10[4] = -1;
    *(_QWORD *)(a1 + 240) = -1;
    v10[5] = -1;
    *(_QWORD *)(a1 + 248) = -1;
    v10[6] = -1;
    *(_QWORD *)(a1 + 256) = -1;
    v10[7] = -1;
    *(_QWORD *)(a1 + 264) = -1;
    v10[8] = -1;
    *(_QWORD *)(a1 + 272) = -1;
    v10[9] = -1;
    *(_QWORD *)(a1 + 280) = -1;
    v10[10] = -1;
    *(_QWORD *)(a1 + 288) = -1;
    v10[11] = -1;
    *(_QWORD *)(a1 + 296) = -1;
    v10[12] = -1;
    v6 = raw_spin_unlock_irqrestore(v10 + 13, v19);
    if ( v9 )
    {
      v20 = 0;
      v21 = 0;
      while ( v20 != 80 )
      {
        if ( v21 > 0x13uLL )
          goto LABEL_62;
        *(_DWORD *)(a1 + v20 + 224) = *((_DWORD *)&v39 + v21);
        if ( v21 == 19 )
          break;
        v22 = v21 + 1LL;
        if ( v21 == 19 )
          goto LABEL_62;
        v23 = a1 + v20;
        v20 += 8;
        v21 += 2;
        *(_DWORD *)(v23 + 228) = *((_DWORD *)&v39 + v22);
        if ( 8 * (v9 >> 1) == v20 )
          goto LABEL_56;
      }
LABEL_61:
      __break(0x5512u);
LABEL_62:
      __break(1u);
      goto LABEL_63;
    }
LABEL_56:
    v24 = raw_spin_lock_irqsave(v10 + 13);
    update_util_inflate_factor((int *)a1, (_DWORD *)v10 - 12);
    v6 = raw_spin_unlock_irqrestore(v10 + 13, v24);
    v25 = *(unsigned int *)(v17 + 32);
    if ( (unsigned int)v25 > 3 )
      goto LABEL_61;
    cluster_zones_initialized[v25] = 1;
    v11 = a3;
    v10 = (_QWORD *)*v10;
  }
  while ( v10 != (_QWORD *)(a1 + 96) );
  v11 = a3;
LABEL_60:
  mutex_unlock(&zone_max_util_pct_store_target_load_lock);
  _ReadStatusReg(SP_EL0);
  return v11;
}
