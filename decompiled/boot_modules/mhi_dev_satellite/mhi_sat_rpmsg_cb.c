__int64 __fastcall mhi_sat_rpmsg_cb(__int64 a1, unsigned __int16 *a2, signed int a3)
{
  _QWORD *v3; // x21
  int v6; // w22
  __int64 v7; // x0
  _QWORD *v8; // x23
  unsigned int v9; // w8
  unsigned int v10; // w20
  char *v11; // x21
  unsigned __int64 v13; // x21
  __int64 v14; // x0
  _QWORD *v15; // x22
  unsigned __int64 v16; // x1
  __int64 v17; // x0
  _QWORD *v18; // x2
  _QWORD *v19; // x1
  __int64 v20; // x9

  v3 = *(_QWORD **)(a1 + 152);
  if ( (unsigned int)a3 < 0x18 || a2[5] + 24LL != a3 || *a2 != 1 || a2[1] || (a2[2] & 0xFFFD) != 0xC )
    __break(0x800u);
  v6 = *((_DWORD *)a2 + 3);
  v7 = raw_spin_lock_irqsave(v3 + 10);
  v8 = v3 + 2;
  do
  {
    v8 = (_QWORD *)*v8;
    if ( v8 == v3 + 2 )
    {
      raw_spin_unlock_irqrestore(v3 + 10, v7);
      return 0;
    }
  }
  while ( *((_DWORD *)v8 + 58) != v6 );
  raw_spin_unlock_irqrestore(v3 + 10, v7);
  if ( !v8 )
    return 0;
  if ( a2[2] == 14 )
  {
    v9 = a2[5];
    if ( v9 >= 0x10 )
    {
      v10 = v9 >> 4;
      v11 = (char *)(a2 + 18);
      do
      {
        if ( (unsigned __int8)v11[2] << 16 == 2162688 && a2[4] == *((unsigned __int16 *)v8 + 134) )
        {
          *((_DWORD *)v8 + 68) = (unsigned __int8)*(v11 - 1);
          complete(v8 + 35);
        }
        --v10;
        v11 += 16;
      }
      while ( v10 );
    }
    return 0;
  }
  if ( *((_DWORD *)v8 + 65) == 1 )
  {
    v13 = a3 + 32LL;
    v14 = _kmalloc_noprof(v13, 2080);
    v15 = (_QWORD *)v14;
    if ( !v14 )
      return 0;
    if ( v13 >= 0x10 && (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x10 )
    {
      *(_QWORD *)(v14 + 16) = v8;
      if ( v13 >= 0x18 && (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x18 )
      {
        if ( v13 >= 0x20 )
          v16 = a3;
        else
          v16 = 0;
        *(_QWORD *)(v14 + 24) = v14 + 32;
        if ( v16 < a3 )
          goto LABEL_40;
        if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x18 )
        {
          memcpy(*(void **)(v14 + 24), a2, a3);
          v17 = raw_spin_lock_irqsave(v8 + 16);
          v18 = v8 + 14;
          v19 = (_QWORD *)v8[15];
          v20 = v17;
          if ( v15 == v8 + 14 || v19 == v15 || (_QWORD *)*v19 != v18 )
            goto LABEL_41;
          v8[15] = v15;
          *v15 = v18;
          if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 8 )
          {
            v15[1] = v19;
            *v19 = v15;
LABEL_35:
            raw_spin_unlock_irqrestore(v8 + 16, v20);
            queue_work_on(32, system_wq, v8 + 21);
            return 0;
          }
        }
      }
    }
    __break(1u);
LABEL_40:
    _fortify_panic(17);
LABEL_41:
    _list_add_valid_or_report(v15, v19);
    goto LABEL_35;
  }
  if ( v3 )
  {
    printk(&unk_8156, "mhi_sat_rpmsg_cb", *v3, *((unsigned int *)v8 + 58));
    ipc_log_string(
      v3[11],
      "%s[E][%s][%x] Message for inactive controller!\n",
      (const char *)&unk_8360,
      "mhi_sat_rpmsg_cb",
      *((_DWORD *)v8 + 58));
  }
  return 0;
}
