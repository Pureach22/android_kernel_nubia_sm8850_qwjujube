__int64 __fastcall store_updown_migrate_handle(int a1, int a2, char *src, __int64 a4, char a5)
{
  char *v7; // x0
  const char *v8; // x22
  unsigned __int64 v9; // x23
  unsigned __int8 *v10; // x0
  int v11; // w8
  int v12; // w9
  int v13; // t1
  int v14; // w10
  unsigned __int8 *v15; // x11
  int v16; // w10
  int v17; // t1
  int v18; // w8
  char *v19; // x0
  __int64 result; // x0
  unsigned __int64 v21; // x24
  __int64 *v22; // x25
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x27
  unsigned __int64 v25; // x23
  _BOOL4 v27; // w8
  void *v28; // x0
  __int64 v29; // [xsp+0h] [xbp-130h]
  char *stringp; // [xsp+8h] [xbp-128h] BYREF
  __int64 v31; // [xsp+10h] [xbp-120h]
  int v32; // [xsp+18h] [xbp-118h]
  char dest[256]; // [xsp+20h] [xbp-110h] BYREF
  __int64 v34; // [xsp+120h] [xbp-10h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest[255] = 0;
  v32 = 0;
  v31 = 0xFFFFFFFFLL;
  strncpy(dest, src, 0xFFu);
  printk(&unk_62490);
  if ( strchr(dest, 64) )
  {
    stringp = dest;
    v7 = strsep(&stringp, "@");
    if ( v7 )
    {
      v8 = v7;
      v29 = a4;
      v9 = 0;
      do
      {
        v10 = (unsigned __int8 *)strnlen(v8, 8u);
        if ( v10 )
        {
          if ( v10 == (unsigned __int8 *)-1LL )
            goto LABEL_53;
          v10 = (unsigned __int8 *)strim(v8);
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
          if ( v9 >= 3 )
          {
LABEL_52:
            __break(0x5512u);
LABEL_53:
            _fortify_panic(2, -1, v10 + 1);
          }
          if ( v11 == 45 )
            v18 = -v14;
          else
            v18 = v14;
          *((_DWORD *)&v31 + v9++) = v18;
        }
        v19 = strsep(&stringp, "@");
        if ( !v19 )
          break;
        v8 = v19;
      }
      while ( (int)v9 < 3 );
      result = -22;
      stringp = nullptr;
      if ( (v31 & 0x80000000) == 0 && (v31 & 0x8000000000000000LL) == 0 && (v32 & 0x80000000) == 0 )
      {
        v10 = (unsigned __int8 *)mutex_lock(&ud_value_data_lock);
        v21 = 0;
        v22 = &cluster_head;
        do
        {
          v22 = (__int64 *)*v22;
          if ( v22 == &cluster_head )
            break;
          v23 = *((unsigned int *)v22 + 4);
          if ( *((_DWORD *)v22 + 4) )
          {
            v24 = 4 * v21;
            do
            {
              v25 = __clz(__rbit64(v23));
              v27 = v21 < 3 && v25 < 8;
              if ( (a5 & 1) != 0 )
              {
                if ( !v27 )
                  goto LABEL_52;
                if ( v24 > 0xB || v25 > 8 )
                  goto LABEL_51;
                *((_DWORD *)&sched_early_up_migrate + v25) = *((_DWORD *)&v31 + v21);
                v28 = &unk_646E7;
              }
              else
              {
                if ( !v27 )
                  goto LABEL_52;
                if ( v24 > 0xB || v25 > 8 )
                {
LABEL_51:
                  __break(1u);
                  goto LABEL_52;
                }
                v28 = &unk_61265;
                *((_DWORD *)&sched_early_down_migrate + v25) = *((_DWORD *)&v31 + v21);
              }
              v10 = (unsigned __int8 *)printk(v28);
              v23 = (unsigned int)(-2LL << v25) & (_DWORD)v22[2];
            }
            while ( ((unsigned int)(-2LL << v25) & (_DWORD)v22[2]) != 0 );
          }
          ++v21;
        }
        while ( (__int64)v21 < num_sched_clusters - 1 );
        mutex_unlock(&ud_value_data_lock);
        result = v29;
      }
    }
    else
    {
      result = -22;
    }
  }
  else
  {
    result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
