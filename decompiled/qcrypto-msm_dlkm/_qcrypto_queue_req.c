__int64 __fastcall qcrypto_queue_req(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x21
  unsigned int v7; // w20
  __int64 v8; // x8
  __int64 *v9; // x10
  __int64 v10; // x10
  int v11; // w11
  unsigned int v12; // w8
  int v13; // w8

  v6 = raw_spin_lock_irqsave(a1 + 52);
  if ( a2 )
  {
    v7 = crypto_enqueue_request(a2 + 48, a3);
  }
  else
  {
    v7 = crypto_enqueue_request(a1 + 192, a3);
    v8 = a1 + 112;
    if ( *(_QWORD *)(a1 + 112) == a1 + 112 )
    {
      printk(&unk_12ACF, "_avail_eng");
      a2 = 0;
    }
    else
    {
      v9 = *(__int64 **)(a1 + 304);
      if ( !v9 || (v10 = *v9, v10 == v8) )
        v10 = *(_QWORD *)(a1 + 112);
      v11 = *(_DWORD *)(a1 + 128) + 1;
      a2 = v10;
      do
      {
        if ( --v11 < 1 )
          break;
        if ( (*(_BYTE *)(a2 + 252) & 1) == 0 && *(_DWORD *)(a2 + 248) < *(_DWORD *)(a2 + 236) )
          goto LABEL_17;
        if ( a2 )
        {
          a2 = *(_QWORD *)a2;
          if ( a2 != v8 )
            continue;
        }
        a2 = *(_QWORD *)(a1 + 112);
      }
      while ( v10 != a2 );
      a2 = 0;
LABEL_17:
      *(_QWORD *)(a1 + 304) = a2;
    }
    v12 = *(_DWORD *)(a1 + 216);
    if ( v12 > *(_DWORD *)(a1 + 324) )
      *(_DWORD *)(a1 + 324) = v12;
    if ( !a2 )
    {
      ++*(_DWORD *)(a1 + 312);
      goto LABEL_30;
    }
  }
  v13 = *(_DWORD *)(a2 + 112);
  if ( v13 == 2 )
  {
LABEL_26:
    *(_BYTE *)(a2 + 116) = 1;
LABEL_30:
    raw_spin_unlock_irqrestore(a1 + 52, v6);
    return v7;
  }
  if ( v13 != 1 )
  {
    if ( v13 || (*(_BYTE *)(a2 + 116) & 1) != 0 )
      goto LABEL_30;
    queue_work_on(32, system_wq, a2 + 192);
    goto LABEL_26;
  }
  raw_spin_unlock_irqrestore(a1 + 52, v6);
  if ( *(_DWORD *)(a1 + 284) == 1 )
    start_qcrypto_process((_DWORD *)a1, a2);
  return v7;
}
