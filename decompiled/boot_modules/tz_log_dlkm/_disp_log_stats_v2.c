__int64 __fastcall disp_log_stats_v2(_DWORD *a1, _DWORD *a2, unsigned int a3, unsigned __int64 a4, unsigned int a5)
{
  unsigned int v10; // w9
  unsigned int v11; // w8
  unsigned int v12; // w8
  unsigned int v13; // w9
  unsigned int v14; // w25
  __int64 v15; // x24
  __int64 v16; // x23
  int v17; // w26
  unsigned int v18; // w11
  __int64 v19; // x5
  _DWORD *v20; // x27
  unsigned int v21; // w8
  int v22; // w28
  unsigned int v23; // w9
  bool v24; // zf
  unsigned int v25; // w10
  unsigned int realtime_timestamp; // w0
  __int64 v27; // x3
  __int64 v28; // x4
  unsigned int v29; // w5
  unsigned int v30; // w11
  unsigned int v31; // w8
  unsigned int v32; // w9
  unsigned int v34; // w8
  __int64 v37; // x0
  __int64 v38; // x1
  __int64 v39; // x2
  __int64 v40; // x3
  __int64 v41; // x4
  __int64 v42; // x5
  unsigned int v43; // [xsp+0h] [xbp-C0h]
  unsigned int v44; // [xsp+Ch] [xbp-B4h]
  unsigned int v45; // [xsp+10h] [xbp-B0h]
  unsigned int v46; // [xsp+1Ch] [xbp-A4h]
  unsigned int v47; // [xsp+20h] [xbp-A0h]
  _QWORD src[18]; // [xsp+30h] [xbp-90h] BYREF

  src[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1 - *a2;
  if ( *a1 < *a2 )
    v10 = 2;
  if ( v10 >= 2 )
  {
    *a2 = *a1 - 1;
    v11 = a1[1] + 1;
LABEL_5:
    v12 = v11 % a3;
    a2[1] = v12;
    goto LABEL_10;
  }
  if ( v10 == 1 )
  {
    v13 = a1[1];
    v12 = a2[1];
    if ( v13 > v12 )
    {
      v11 = v13 + 1;
      goto LABEL_5;
    }
  }
  else
  {
    v12 = a2[1];
  }
LABEL_10:
  if ( v12 == a1[1] )
  {
    while ( !msleep_interruptible(50) )
    {
      if ( a5 == 5 )
      {
        mutex_lock(&tzdbg_mutex);
        _memcpy_fromio(qword_110, tzdbg[0], (unsigned int)debug_rw_buf_size);
        mutex_unlock(&tzdbg_mutex);
      }
      if ( a2[1] != a1[1] )
        goto LABEL_16;
    }
    LODWORD(v16) = 0;
LABEL_71:
    _ReadStatusReg(SP_EL0);
    return (unsigned int)v16;
  }
LABEL_16:
  if ( (unsigned int)debug_rw_buf_size >= a4 )
    v14 = a4;
  else
    v14 = debug_rw_buf_size;
  mutex_lock(&tzdbg_mutex);
  is_rd_locked = 1;
  v15 = qword_130;
  if ( g_realtime_consolidation_enable != 1 )
  {
    LODWORD(v16) = 0;
    if ( a3 )
    {
      if ( v14 )
      {
        v34 = a2[1];
        if ( v34 != a1[1] )
        {
          v16 = 0;
          do
          {
            *(_BYTE *)(v15 + v16) = *((_BYTE *)a1 + v34 + 8);
            v34 = (a2[1] + 1) % a3;
            a2[1] = v34;
            if ( !v34 )
              ++*a2;
            ++v16;
          }
          while ( v34 != a1[1] && (unsigned int)v16 < v14 );
        }
      }
    }
    goto LABEL_69;
  }
  LODWORD(v16) = 0;
  memset(src, 0, 128);
  if ( !a3 )
    goto LABEL_69;
  if ( !v14 )
    goto LABEL_69;
  v17 = a1[1];
  v18 = a2[1];
  v47 = v14;
  if ( v18 == v17 )
    goto LABEL_69;
  v19 = 0;
  LODWORD(v16) = 0;
  v20 = a1 + 2;
  while ( 1 )
  {
    if ( v14 < 2 )
      goto LABEL_68;
    v21 = (v18 + 1) % a3;
    if ( v21 == v17 )
      goto LABEL_68;
    v22 = 0;
    v23 = v18;
    while ( 1 )
    {
      v24 = *((_BYTE *)v20 + v23) == 13;
      v23 = v21;
      if ( v24 && *((_BYTE *)v20 + v21) == 10 )
        break;
      if ( v21 + 1 == a3 )
        v21 = 0;
      else
        ++v21;
      if ( v23 != v17 && v21 != v17 )
      {
        v25 = v22 + 3;
        ++v22;
        if ( v25 <= v14 )
          continue;
      }
      goto LABEL_68;
    }
    if ( v22 == -24 )
    {
LABEL_68:
      if ( !(_DWORD)v16 )
      {
        LODWORD(v16) = copy_to_dispbuf_v2(a1, a2, a3, v14, v15, v19);
        printk(&unk_A7BB, "_copy_to_dispbuf_with_realtime_v2", (unsigned int)v16);
        if ( a5 <= 0xB )
          goto LABEL_70;
        goto LABEL_73;
      }
LABEL_69:
      if ( a5 <= 0xB )
      {
LABEL_70:
        tzdbg[5 * a5 + 18] = qword_130;
        goto LABEL_71;
      }
LABEL_73:
      __break(1u);
    }
    v44 = v18;
    v45 = v19;
    v46 = v22 + 2;
    realtime_timestamp = generate_realtime_timestamp(a1 + 2, v18);
    if ( realtime_timestamp == -22 )
    {
      v30 = v44;
      v29 = v45;
      goto LABEL_45;
    }
    v29 = v45;
    if ( realtime_timestamp > v14 - v22 - 2 )
    {
      v30 = v44;
      if ( (_DWORD)v16 )
        goto LABEL_69;
      goto LABEL_45;
    }
    v43 = realtime_timestamp;
    if ( realtime_timestamp >= 0x81 )
      break;
    v46 = v22 + 2;
    memcpy((void *)(v15 + v45), src, (int)realtime_timestamp);
    v30 = v44;
    v29 = v45 + v43;
    LODWORD(v16) = v43 + v16;
LABEL_45:
    v31 = 0;
    if ( v46 )
    {
      v32 = a2[1];
      if ( v32 != a1[1] )
      {
        v31 = 0;
        do
        {
          *(_BYTE *)(v15 + v29 + v31) = *((_BYTE *)v20 + v32);
          v32 = (a2[1] + 1) % a3;
          a2[1] = v32;
          if ( !v32 )
            ++*a2;
          ++v31;
        }
        while ( v32 != a1[1] && v31 < v46 );
      }
    }
    LODWORD(v16) = v16 + v46;
    v18 = (v30 + v22 + 2) % a3;
    if ( v18 != v17 )
    {
      v19 = v31 + v29;
      v14 = v47 - v16;
      if ( v47 > (unsigned int)v16 )
        continue;
    }
    goto LABEL_69;
  }
  v37 = _fortify_panic(16, -1, (int)realtime_timestamp, v27, v28, v45);
  return copy_to_dispbuf(v37, v38, v39, v40, v41, v42);
}
