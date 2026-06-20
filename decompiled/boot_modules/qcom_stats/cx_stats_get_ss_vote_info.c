__int64 __fastcall cx_stats_get_ss_vote_info(int a1, __int64 a2)
{
  bool v2; // zf
  __int64 result; // x0
  unsigned int v5; // w0
  unsigned int v6; // w0
  __int64 v7; // x1
  __int64 v8; // x10
  __int64 v9; // x8
  __int64 v10; // x9
  unsigned int *v11; // x19
  int v12; // w22
  __int64 v13; // x9
  int v14; // w8
  int v15; // w10
  int v16; // w8
  __int64 v17; // x8
  __int64 v18; // x9
  unsigned int v19; // w19
  int v20; // [xsp+8h] [xbp-38h]
  int v21; // [xsp+Ch] [xbp-34h]
  __int64 v22; // [xsp+10h] [xbp-30h]
  __int64 v23; // [xsp+18h] [xbp-28h]
  int v24; // [xsp+20h] [xbp-20h]
  int v25; // [xsp+24h] [xbp-1Ch]
  int v26; // [xsp+28h] [xbp-18h]
  int v27; // [xsp+2Ch] [xbp-14h]
  int v28; // [xsp+30h] [xbp-10h]
  int v29; // [xsp+34h] [xbp-Ch]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v2 = a1 == 42;
  result = 4294967277LL;
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( v2 && a2 && drv )
  {
    if ( *(_QWORD *)(drv + 240) && *(_QWORD *)(*(_QWORD *)(drv + 8) + 16LL) )
    {
      mutex_lock(drv + 192);
      v5 = qmp_send(*(_QWORD *)(drv + 240), "{class: misc_debug, res: cx_vote}", 64);
      if ( v5 )
      {
        v19 = v5;
        printk(&unk_A305, v5);
        v17 = drv;
      }
      else
      {
        v6 = readl_relaxed((unsigned int *)(*(_QWORD *)drv + *(_QWORD *)(*(_QWORD *)(drv + 8) + 8LL) + 4LL));
        if ( v6 >= 0x15 )
        {
          printk(&unk_A209, v7);
        }
        else
        {
          v8 = (16 * v6) | 8;
          v9 = *(_QWORD *)(drv + 8);
          v10 = *(_QWORD *)drv + *(_QWORD *)(v9 + 8);
          v11 = (unsigned int *)(v10 + v8);
          if ( v10 + v8 )
          {
            v12 = *(unsigned __int8 *)(v9 + 37);
            v29 = 0;
            v20 = readl_relaxed((unsigned int *)(v10 + v8));
            v21 = readl_relaxed(v11 + 1);
            LODWORD(v22) = readl_relaxed(v11 + 2);
            HIDWORD(v22) = readl_relaxed(v11 + 3);
            LODWORD(v23) = readl_relaxed(v11 + 4);
            HIDWORD(v23) = readl_relaxed(v11 + 5);
            v24 = readl_relaxed(v11 + 6);
            v25 = readl_relaxed(v11 + 7);
            v26 = readl_relaxed(v11 + 8);
            v27 = readl_relaxed(v11 + 9);
            v28 = readl_relaxed(v11 + 10);
            if ( v12 == 1 )
              v29 = readl_relaxed(v11 + 11);
            v13 = v23;
            *(_QWORD *)(a2 + 8) = v22;
            *(_QWORD *)(a2 + 16) = v13;
            LODWORD(v13) = v24;
            v14 = v20;
            v15 = v21;
            *(_DWORD *)a2 = v20;
            *(_DWORD *)(a2 + 4) = v15;
            *(_DWORD *)(a2 + 24) = v13;
            *(_DWORD *)(a2 + 28) = v14;
            v16 = v22;
            LOWORD(v13) = WORD2(v22);
            *(_DWORD *)(a2 + 32) = v15;
            *(_DWORD *)(a2 + 36) = v16;
            *(_WORD *)(a2 + 40) = v13;
            v17 = drv;
            if ( *(_BYTE *)(*(_QWORD *)(drv + 8) + 37LL) == 1 )
            {
              v18 = 40;
              if ( v12 )
                v18 = 44;
              v19 = 0;
              *(_BYTE *)(a2 + 42) = *(int *)((char *)&v20 + v18);
            }
            else
            {
              v19 = 0;
            }
            goto LABEL_21;
          }
        }
        printk(&unk_A326, v7);
        v17 = drv;
        v19 = -22;
      }
LABEL_21:
      mutex_unlock(v17 + 192);
      result = v19;
      goto LABEL_22;
    }
    result = 4294967201LL;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
