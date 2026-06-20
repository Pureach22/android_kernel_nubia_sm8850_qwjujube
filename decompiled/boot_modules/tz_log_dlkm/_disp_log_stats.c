__int64 __fastcall disp_log_stats(
        unsigned __int16 *a1,
        unsigned __int16 *a2,
        unsigned int a3,
        unsigned __int64 a4,
        unsigned int a5)
{
  unsigned int v9; // w9
  unsigned int v10; // w8
  unsigned int v11; // w9
  unsigned int v12; // w8
  unsigned int v13; // w8
  unsigned int v14; // w23
  int v15; // w28
  unsigned __int64 v16; // x26
  __int64 v17; // x24
  __int64 v18; // x4
  unsigned __int64 v19; // x11
  __int64 v20; // x5
  unsigned __int16 *v21; // x27
  unsigned int v22; // w26
  unsigned int v23; // w8
  int v24; // w25
  unsigned int v25; // w9
  bool v26; // zf
  unsigned int v27; // w10
  unsigned int realtime_timestamp; // w0
  __int64 v29; // x3
  unsigned int v30; // w5
  int v31; // w8
  unsigned int v32; // w9
  bool v33; // cf
  unsigned int v35; // w9
  __int64 v37; // x0
  unsigned int v38; // [xsp+0h] [xbp-C0h]
  unsigned __int64 v39; // [xsp+8h] [xbp-B8h]
  unsigned int v40; // [xsp+10h] [xbp-B0h]
  unsigned int v41; // [xsp+1Ch] [xbp-A4h]
  __int64 v42; // [xsp+20h] [xbp-A0h]
  _QWORD src[18]; // [xsp+30h] [xbp-90h] BYREF

  src[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a2;
  v10 = *a1;
  v33 = v10 >= v9;
  v11 = v10 - v9;
  if ( !v33 )
    v11 = 2;
  if ( v11 >= 2 )
  {
    *a2 = v10 - 1;
    v12 = a1[1];
LABEL_5:
    v13 = (v12 + 1) % a3;
    v14 = (unsigned __int16)v13;
    a2[1] = v13;
    goto LABEL_10;
  }
  if ( v11 == 1 )
  {
    v12 = a1[1];
    v14 = a2[1];
    if ( v12 > v14 )
      goto LABEL_5;
  }
  else
  {
    v14 = a2[1];
  }
LABEL_10:
  v15 = a1[1];
  if ( v14 == v15 )
  {
    v16 = a4;
    do
    {
      if ( msleep_interruptible(50) )
      {
        LODWORD(v17) = 0;
        goto LABEL_78;
      }
      if ( a5 == 5 )
      {
        mutex_lock(&tzdbg_mutex);
        _memcpy_fromio(qword_110, tzdbg[0], (unsigned int)debug_rw_buf_size);
        mutex_unlock(&tzdbg_mutex);
      }
      v14 = a2[1];
      v15 = a1[1];
    }
    while ( v14 == v15 );
    a4 = v16;
  }
  v18 = qword_130;
  if ( (unsigned int)debug_rw_buf_size >= a4 )
    v19 = a4;
  else
    v19 = (unsigned int)debug_rw_buf_size;
  if ( g_realtime_consolidation_enable != 1 )
  {
    if ( !a3 )
      goto LABEL_73;
    LODWORD(v17) = 0;
    if ( v14 != v15 && (_DWORD)v19 )
    {
      v17 = 0;
      do
      {
        *(_BYTE *)(v18 + v17) = *((_BYTE *)a1 + v14 + 4);
        v35 = ((unsigned int)a2[1] + 1) % a3;
        v14 = (unsigned __int16)v35;
        a2[1] = v35;
        if ( !(_WORD)v35 )
          ++*a2;
        ++v17;
      }
      while ( a1[1] != (unsigned __int16)v35 && (unsigned int)v17 < (unsigned int)v19 );
    }
    goto LABEL_76;
  }
  memset(src, 0, 128);
  if ( !a3 )
  {
    LODWORD(v17) = 0;
    goto LABEL_71;
  }
  LODWORD(v17) = 0;
  if ( v14 == v15 || !(_DWORD)v19 )
  {
LABEL_76:
    if ( a5 > 0xB )
      goto LABEL_72;
    goto LABEL_77;
  }
  v20 = 0;
  LODWORD(v17) = 0;
  v21 = a1 + 2;
  v22 = v19;
  while ( v22 >= 2 )
  {
    v23 = (v14 + 1) % a3;
    if ( v23 == v15 )
      break;
    v24 = 0;
    v25 = v14;
    while ( 1 )
    {
      v26 = *((_BYTE *)v21 + v25) == 13;
      v25 = v23;
      if ( v26 && *((_BYTE *)v21 + v23) == 10 )
        break;
      if ( v23 + 1 == a3 )
        v23 = 0;
      else
        ++v23;
      if ( v25 != v15 && v23 != v15 )
      {
        v27 = v24 + 3;
        ++v24;
        if ( v27 <= v22 )
          continue;
      }
      goto LABEL_75;
    }
    if ( v24 == -24 )
      break;
    v40 = v20;
    v42 = v18;
    v39 = v19;
    v41 = v24 + 2;
    realtime_timestamp = generate_realtime_timestamp(a1 + 2, v14);
    if ( realtime_timestamp == -22 )
    {
      v18 = v42;
      v30 = v40;
    }
    else
    {
      v18 = v42;
      v30 = v40;
      if ( realtime_timestamp <= v22 - v24 - 2 )
      {
        v38 = realtime_timestamp;
        if ( realtime_timestamp >= 0x81 )
        {
          v37 = _fortify_panic(16, -1, (int)realtime_timestamp, v29, v42, v40);
          return disp_log_stats_v2(v37);
        }
        v41 = v24 + 2;
        memcpy((void *)(v42 + v40), src, (int)realtime_timestamp);
        v18 = v42;
        v30 = v40 + v38;
        LODWORD(v17) = v38 + v17;
      }
      else if ( (_DWORD)v17 )
      {
        goto LABEL_76;
      }
    }
    v31 = 0;
    if ( v41 )
    {
      v32 = a2[1];
      v19 = v39;
      if ( v32 != a1[1] )
      {
        v31 = 0;
        do
        {
          *(_BYTE *)(v18 + v30 + v31) = *((_BYTE *)v21 + v32);
          v32 = (unsigned __int16)(((unsigned int)a2[1] + 1) % a3);
          a2[1] = ((unsigned int)a2[1] + 1) % a3;
          if ( !v32 )
            ++*a2;
          v33 = a1[1] == v32 || ++v31 >= v41;
        }
        while ( !v33 );
      }
    }
    else
    {
      v19 = v39;
    }
    LODWORD(v17) = v17 + v41;
    v14 = (v14 + v24 + 2) % a3;
    if ( v14 != v15 )
    {
      v20 = v31 + v30;
      v22 = v19 - v17;
      if ( (unsigned int)v19 > (unsigned int)v17 )
        continue;
    }
    goto LABEL_76;
  }
LABEL_75:
  if ( (_DWORD)v17 )
    goto LABEL_76;
  LODWORD(v17) = copy_to_dispbuf(a1, a2, a3, v22, v18, v20);
  printk(&unk_A7BB, "_copy_to_dispbuf_with_realtime", (unsigned int)v17);
LABEL_71:
  while ( a5 > 0xB )
  {
LABEL_72:
    __break(1u);
LABEL_73:
    LODWORD(v17) = 0;
  }
LABEL_77:
  tzdbg[5 * a5 + 18] = qword_130;
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v17;
}
