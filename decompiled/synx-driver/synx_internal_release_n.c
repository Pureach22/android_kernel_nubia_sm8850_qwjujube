__int64 __fastcall synx_internal_release_n(__int64 a1, unsigned int *a2)
{
  unsigned __int64 client; // x0
  __int64 v4; // x4
  __int64 v5; // x5
  unsigned __int64 v6; // x19
  __int64 v7; // x4
  unsigned __int64 v8; // x8
  void *v9; // x0
  __int64 v10; // x3
  unsigned int v11; // w21
  unsigned int v12; // w25
  char v13; // w24
  __int64 v14; // x22
  __int64 i; // x8
  __int64 v16; // x8
  int v17; // w9
  __int64 v18; // x5
  unsigned __int64 v20; // x22
  __int64 v21; // x8
  int v22; // w25
  __int64 v23; // x9
  __int64 v24; // x8
  bool v25; // zf
  __int64 v26; // x28
  char v27; // w24
  unsigned int v28; // w27
  int v29; // w9
  __int64 v30; // x8
  __int64 v31; // x5

  client = synx_get_client(a1);
  if ( !client || (v6 = client, client >= 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (synx_debug & 1) != 0 )
    {
      v9 = &unk_2B010;
      v10 = 1791;
      goto LABEL_36;
    }
    return (unsigned int)-22;
  }
  if ( a2 && (unsigned __int64)a2 < 0xFFFFFFFFFFFFF001LL )
  {
    v7 = *a2;
    if ( (_DWORD)v7 == 1 )
    {
      v12 = a2[2];
      raw_spin_lock_bh(client + 264920);
      v13 = 0;
      v14 = 0;
      v11 = -22;
      for ( i = *(_QWORD *)(v6 + 8LL * ((1640531527 * v12) >> 24) + 262872); i; v14 = 0 )
      {
        v16 = i - 72;
        if ( !v16 )
          break;
        if ( *(_DWORD *)(v16 + 28) == v12 )
        {
          v17 = *(_DWORD *)(v16 + 32);
          if ( v17 )
          {
            v11 = 0;
            v13 = 1;
            *(_DWORD *)(v16 + 32) = v17 - 1;
            v14 = v16;
            break;
          }
        }
        i = *(_QWORD *)(v16 + 72);
        v13 = 0;
      }
      raw_spin_unlock_bh(v6 + 264920);
      synx_util_release_handle(v14);
      if ( (v13 & 1) != 0 )
      {
        if ( (synx_debug & 0x10) != 0 )
          printk(&unk_27DA6, "verb", "synx_internal_release_n", 1835, a2[2], v18);
      }
      else if ( (synx_debug & 1) != 0 )
      {
        printk(&unk_25FB5, &unk_29207, "synx_internal_release_n", 1831, a2[2], v11);
      }
      a2[3] = v11;
    }
    else if ( (_DWORD)v7 == 2 )
    {
      v8 = *((_QWORD *)a2 + 1);
      if ( !v8 || v8 > 0xFFFFFFFFFFFFF000LL || a2[4] - 4096 < 0xFFFFF001 )
      {
        synx_put_client(client);
        if ( (synx_debug & 1) != 0 )
        {
          v9 = &unk_2B3D9;
          v10 = 1805;
LABEL_36:
          printk(v9, &unk_29207, "synx_internal_release_n", v10, v4, v5);
          return (unsigned int)-22;
        }
        return (unsigned int)-22;
      }
      v20 = 0;
      v11 = 0;
      do
      {
        v22 = *(_DWORD *)(*((_QWORD *)a2 + 1) + 8 * v20);
        raw_spin_lock_bh(v6 + 264920);
        v23 = *(_QWORD *)(v6 + 262872 + 8LL * ((unsigned int)(1640531527 * v22) >> 24));
        v24 = v23 - 72;
        if ( v23 )
          v25 = v23 == 72;
        else
          v25 = 1;
        if ( v25 )
        {
          v26 = 0;
          v27 = 0;
          v28 = -22;
        }
        else
        {
          while ( 1 )
          {
            if ( *(_DWORD *)(v24 + 28) == v22 )
            {
              v29 = *(_DWORD *)(v24 + 32);
              if ( v29 )
                break;
            }
            v30 = *(_QWORD *)(v24 + 72);
            v27 = 0;
            v26 = 0;
            v28 = -22;
            if ( v30 )
            {
              v24 = v30 - 72;
              if ( v24 )
                continue;
            }
            goto LABEL_53;
          }
          v28 = 0;
          v27 = 1;
          *(_DWORD *)(v24 + 32) = v29 - 1;
          v26 = v24;
        }
LABEL_53:
        raw_spin_unlock_bh(v6 + 264920);
        synx_util_release_handle(v26);
        if ( (v27 & 1) != 0 )
        {
          if ( (synx_debug & 0x10) != 0 )
            printk(
              &unk_27DA6,
              "verb",
              "synx_internal_release_n",
              1822,
              *(unsigned int *)(*((_QWORD *)a2 + 1) + 8 * v20),
              v31);
        }
        else
        {
          if ( (synx_debug & 1) != 0 )
            printk(
              &unk_25FB5,
              &unk_29207,
              "synx_internal_release_n",
              1813,
              *(unsigned int *)(*((_QWORD *)a2 + 1) + 8 * v20),
              v28);
          if ( !v11 )
            v11 = v28;
        }
        v21 = *((_QWORD *)a2 + 1) + 8 * v20++;
        *(_DWORD *)(v21 + 4) = v28;
      }
      while ( v20 < a2[4] );
    }
    else
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_26BC5, &unk_29207, "synx_internal_release_n", 1839, v7, v5);
      v11 = -22;
    }
    synx_put_client(v6);
    return v11;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_2A1F0, &unk_29207, "synx_internal_release_n", 1796, v4, v5);
  synx_put_client(v6);
  return (unsigned int)-22;
}
