__int64 __fastcall sched_prio_adjusted_info_store(int a1, int a2, char *src, __int64 a4)
{
  char *v5; // x0
  const char *v6; // x21
  unsigned __int64 v7; // x22
  unsigned __int8 *v8; // x0
  int v9; // w8
  int v10; // w9
  int v11; // t1
  int v12; // w10
  unsigned __int8 *v13; // x11
  int v14; // w10
  int v15; // t1
  int v16; // w8
  char *v17; // x0
  int v18; // w25
  int v19; // w21
  int v20; // w22
  int v21; // w23
  int v22; // w24
  __int64 v23; // x9
  int *v24; // x10
  __int64 v25; // x9
  int *v26; // x10
  void *v28; // x0
  __int64 v29; // x9
  char *stringp; // [xsp+8h] [xbp-128h] BYREF
  __int64 v31; // [xsp+10h] [xbp-120h]
  __int64 v32; // [xsp+18h] [xbp-118h]
  int v33; // [xsp+20h] [xbp-110h]
  char dest[256]; // [xsp+28h] [xbp-108h] BYREF
  __int64 v35; // [xsp+128h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest[255] = 0;
  v33 = 0;
  v31 = 0xFFFFFFFFLL;
  v32 = 0;
  strncpy(dest, src, 0xFFu);
  printk(&unk_615AB);
  if ( strchr(dest, 64) )
  {
    stringp = dest;
    v5 = strsep(&stringp, "@");
    if ( !v5 )
      goto LABEL_48;
    v6 = v5;
    v7 = 0;
    do
    {
      v8 = (unsigned __int8 *)strnlen(v6, 8u);
      if ( v8 )
      {
        if ( v8 == (unsigned __int8 *)-1LL )
          goto LABEL_60;
        v8 = (unsigned __int8 *)strim(v6);
        v9 = *v8;
        if ( v9 == 45 || v9 == 43 )
        {
          v11 = *++v8;
          v10 = v11;
        }
        else
        {
          v10 = *v8;
        }
        if ( (unsigned int)(v10 - 48) > 9 )
        {
          v12 = 0;
        }
        else
        {
          v12 = 0;
          v13 = v8 + 1;
          do
          {
            v14 = v10 + 10 * v12;
            v15 = *v13++;
            v10 = v15;
            v12 = v14 - 48;
          }
          while ( (unsigned int)(v15 - 48) < 0xA );
        }
        if ( v7 >= 5 )
          goto LABEL_59;
        if ( v9 == 45 )
          v16 = -v12;
        else
          v16 = v12;
        *((_DWORD *)&v31 + v7++) = v16;
      }
      v17 = strsep(&stringp, "@");
      if ( !v17 )
        break;
      v6 = v17;
    }
    while ( (int)v7 < 5 );
    if ( (int)v7 < 4 || (v18 = v31, (v31 & 0x80000000) != 0) )
    {
LABEL_48:
      v28 = &unk_659E8;
    }
    else
    {
      v19 = HIDWORD(v31);
      v20 = v32;
      v21 = HIDWORD(v32);
      v22 = v33;
      if ( !(_DWORD)v31 && __PAIR64__(HIDWORD(v31), 0) == (unsigned int)v32 && __PAIR64__(HIDWORD(v32), 0) == v33 )
      {
        mutex_lock(&sysfs_store_lock);
        memset(sched_prio_adjusted_info, 0, 0x1F4u);
LABEL_46:
        mutex_unlock(&sysfs_store_lock);
        goto LABEL_47;
      }
      if ( (_DWORD)v31 )
      {
        if ( SHIDWORD(v31) <= 0 )
        {
          v28 = &unk_64362;
        }
        else if ( (unsigned int)v32 <= 7 && ((1 << v32) & 0x89) != 0 )
        {
          if ( (unsigned int)(HIDWORD(v32) - 141) > 0xFFFFFFD7 )
          {
            v8 = (unsigned __int8 *)mutex_lock(&sysfs_store_lock);
            v23 = 0;
            v24 = sched_prio_adjusted_info;
            while ( v24[1] != v19 )
            {
              ++v23;
              v24 += 5;
              if ( v23 == 100 )
              {
                v23 = (unsigned int)(ring_array_index % 100);
                ++ring_array_index;
                if ( (unsigned int)v23 <= 0x63 )
                {
                  v24 = &sched_prio_adjusted_info[5 * (unsigned int)v23];
                  *v24 = v18;
                  v24[1] = v19;
                  goto LABEL_44;
                }
LABEL_59:
                __break(0x5512u);
LABEL_60:
                _fortify_panic(2, -1, v8 + 1);
              }
            }
            *v24 = v18;
LABEL_44:
            v24[2] = v20;
            v24[3] = v21;
            sched_prio_adjusted_info[5 * v23 + 4] = v22;
LABEL_45:
            prio_adj_info_data_changed = 1;
            goto LABEL_46;
          }
          v28 = &unk_66E2D;
        }
        else
        {
          v28 = &unk_64CE7;
        }
      }
      else
      {
        if ( SHIDWORD(v31) > 0 )
        {
          mutex_lock(&sysfs_store_lock);
          v25 = 0;
          while ( 1 )
          {
            v26 = &sched_prio_adjusted_info[v25];
            if ( sched_prio_adjusted_info[v25 + 1] == v19 )
              break;
            v25 += 5;
            if ( v25 == 500 )
              goto LABEL_51;
          }
          v26[4] = 0;
          *(_QWORD *)v26 = 0;
          *((_QWORD *)v26 + 1) = 0;
LABEL_51:
          v29 = 0;
          while ( !sched_prio_adjusted_info[v29] )
          {
            v29 += 5;
            prio_adj_info_data_changed = 0;
            if ( v29 == 500 )
              goto LABEL_46;
          }
          goto LABEL_45;
        }
        v28 = &unk_61D05;
      }
    }
    printk(v28);
    a4 = -22;
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return a4;
}
