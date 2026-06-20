__int64 __fastcall sched_affinity_ctrl_store(int a1, int a2, char *src, __int64 a4)
{
  char *v5; // x0
  char *v6; // x21
  unsigned __int64 v7; // x22
  const char *v8; // x20
  __int64 v9; // x23
  unsigned __int8 *v10; // x0
  int v11; // w8
  int v12; // w9
  int v13; // t1
  int v14; // w10
  unsigned __int8 *v15; // x11
  int v16; // w10
  int v17; // t1
  int v18; // w8
  __int64 v19; // x20
  int *v20; // x23
  __int64 v21; // x0
  unsigned int v23; // w8
  __int64 v24; // x0
  _DWORD *v25; // x9
  __int64 v26; // x10
  __int64 v28; // x12
  __int64 v29; // x8
  __int64 v30; // x8
  _DWORD *v31; // x9
  __int64 v32; // x10
  __int64 v34; // x12
  unsigned __int64 v39; // x13
  unsigned __int64 v41; // x13
  char *v43; // [xsp+0h] [xbp-120h] BYREF
  __int64 v44; // [xsp+8h] [xbp-118h] BYREF
  __int64 v45; // [xsp+10h] [xbp-110h]
  char dest[256]; // [xsp+18h] [xbp-108h] BYREF
  __int64 v47; // [xsp+118h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest[255] = 0;
  v44 = 0;
  v45 = 0xFFFFFFFFLL;
  strncpy(dest, src, 0xFFu);
  printk(&unk_63627);
  if ( strchr(dest, 64) )
  {
    v43 = dest;
    v5 = strsep(&v43, "@");
    if ( v5 )
    {
      v6 = v5;
      v7 = 0;
      v8 = "@";
      v9 = 10;
      do
      {
        v10 = (unsigned __int8 *)strnlen(v6, 8u);
        if ( v10 )
        {
          if ( v10 == (unsigned __int8 *)-1LL )
            goto LABEL_44;
          v10 = (unsigned __int8 *)strim(v6);
          v11 = *v10;
          if ( v11 == 45 || v11 == 43 )
          {
            v13 = *++v10;
            v12 = v13;
          }
          else
          {
            v12 = *v10;
          }
          if ( (unsigned int)(v12 - 48) > 9 )
          {
            v14 = 0;
          }
          else
          {
            v14 = 0;
            v15 = v10 + 1;
            do
            {
              v16 = v12 + 10 * v14;
              v17 = *v15++;
              v12 = v17;
              v14 = v16 - 48;
            }
            while ( (unsigned int)(v17 - 48) < 0xA );
          }
          if ( v7 >= 2 )
            goto LABEL_43;
          if ( v11 == 45 )
            v18 = -v14;
          else
            v18 = v14;
          *(_DWORD *)&dest[4 * v7++ - 8] = v18;
        }
        v6 = strsep(&v43, "@");
      }
      while ( v6 );
      LODWORD(v8) = v45;
      LODWORD(v6) = HIDWORD(v45);
      v43 = nullptr;
      if ( !(_DWORD)v45 && (v45 & 0x8000000000000000LL) == 0 )
      {
        mutex_lock(&sysfs_store_lock);
        v19 = 0;
        while ( 1 )
        {
          v21 = (unsigned int)cmask_bundles[v19];
          if ( (_DWORD)v6 )
            break;
          if ( (int)v21 > 0 )
            goto LABEL_25;
LABEL_26:
          v19 += 2;
          if ( v19 == 200 )
            goto LABEL_62;
        }
        _ZF = (_DWORD)v21 == (_DWORD)v6;
        v21 = (unsigned int)v6;
        if ( !_ZF )
          goto LABEL_26;
LABEL_25:
        v20 = &cmask_bundles[v19];
        change_affinity(v21, &v44, 1);
        *v20 = 0;
        *((_BYTE *)v20 + 4) = 0;
        goto LABEL_26;
      }
      if ( (int)v45 >= 1 && SHIDWORD(v45) >= 1 )
      {
        if ( HIDWORD(v45) > 0xFF )
        {
          printk(&unk_65A19);
          a4 = -22;
          goto LABEL_63;
        }
        v9 = 0;
        v7 = (unsigned __int64)cmask_bundles;
        do
        {
          if ( *(int *)((char *)cmask_bundles + v9) == (_DWORD)v45 )
          {
            printk(&unk_63D4D);
            mutex_lock(&sysfs_store_lock);
            v29 = 0;
            v25 = dword_6C708;
            v26 = 1;
            _X11 = (unsigned __int64 *)&v44;
            v44 = 0;
            goto LABEL_58;
          }
          v9 += 8;
        }
        while ( v9 != 800 );
        printk(&unk_618D6);
        v10 = (unsigned __int8 *)mutex_lock(&sysfs_store_lock);
        v23 = bundles_array_index % 100;
        ++bundles_array_index;
        if ( v23 > 0x63 )
        {
LABEL_43:
          __break(0x5512u);
LABEL_44:
          _fortify_panic(2, -1, v10 + 1);
          goto LABEL_45;
        }
        v9 = 8LL * v23;
        v7 = (unsigned __int64)cmask_bundles + v9;
        v24 = *(unsigned int *)((char *)cmask_bundles + v9);
        if ( (int)v24 >= 1 )
        {
          change_affinity(v24, &v44, 1);
          v29 = v9 | 4;
          *(_DWORD *)v7 = 0;
          if ( (v9 | 4uLL) > 0x320 )
            goto LABEL_54;
          *(_BYTE *)(v7 + 4) = 0;
        }
        v30 = 0;
        v31 = dword_6C708;
        v32 = 1;
        _X11 = (unsigned __int64 *)&v44;
        v44 = 0;
        do
        {
          if ( (v31[v30] & (unsigned int)v6) != 0 )
          {
            v34 = v32 << v30;
LABEL_45:
            __asm { PRFM            #0x11, [X11] }
            do
              v39 = __ldxr(_X11);
            while ( __stxr(v39 | v34, _X11) );
          }
          ++v30;
        }
        while ( v30 != 8 );
        if ( !(_DWORD)v44 )
        {
          printk(&unk_60E52);
LABEL_62:
          mutex_unlock(&sysfs_store_lock);
          goto LABEL_63;
        }
        change_affinity((unsigned int)v8, &v44, 0);
        v29 = v9 | 4;
        *(_DWORD *)v7 = (_DWORD)v8;
        if ( (v9 | 4uLL) <= 0x320 )
        {
          *(_BYTE *)(v7 + 4) = (_BYTE)v6;
          mutex_unlock(&sysfs_store_lock);
          printk(&unk_666D6);
          goto LABEL_63;
        }
LABEL_54:
        __break(1u);
LABEL_55:
        __asm { PRFM            #0x11, [X11] }
        do
          v41 = __ldxr(_X11);
        while ( __stxr(v41 | v28, _X11) );
        while ( ++v29 != 8 )
        {
LABEL_58:
          if ( (v25[v29] & (unsigned int)v6) != 0 )
          {
            v28 = v26 << v29;
            goto LABEL_55;
          }
        }
        if ( (_DWORD)v44 )
        {
          *(_BYTE *)(v7 + v9 + 4) = (_BYTE)v6;
          change_affinity((unsigned int)v8, &v44, 0);
        }
        else
        {
          printk(&unk_63A76);
        }
        goto LABEL_62;
      }
    }
  }
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return a4;
}
