__int64 __fastcall qmp_shutdown(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  int v3; // w8
  unsigned int v5; // w9
  unsigned int v6; // w8
  __int64 v7; // x9
  __int64 v8; // x20
  __int64 v9; // x0

  v1 = *(_QWORD *)(a1 + 240);
  mutex_lock(v1 + 272);
  v2 = *(_DWORD *)(v1 + 264);
  if ( v2 <= 2 )
  {
    v3 = *(_DWORD *)(v1 + 156);
LABEL_5:
    *(_DWORD *)(v1 + 156) = v3 - 1;
    return mutex_unlock(v1 + 272);
  }
  if ( v2 == 3 )
  {
    v3 = *(_DWORD *)(v1 + 156);
    *(_DWORD *)(v1 + 264) = 2;
    goto LABEL_5;
  }
  v5 = *(_DWORD *)(v1 + 156);
  v6 = *(_DWORD *)(v1 + 160) + 1;
  *(_DWORD *)(v1 + 160) = v6;
  if ( v6 >= v5 )
  {
    v7 = *(_QWORD *)(v1 + 168);
    *(_DWORD *)(v1 + 264) = 6;
    writel(4294901760LL, v7 + 44);
    v8 = *(_QWORD *)(v1 + 496);
    __dsb(0xEu);
    v9 = *(_QWORD *)(v8 + 128);
    if ( v9 )
    {
      mbox_send_message(v9, 0);
      mbox_client_txdone(*(_QWORD *)(v8 + 128), 0);
    }
    else
    {
      writel_relaxed(*(unsigned int *)(v8 + 56));
    }
    ++*(_DWORD *)(v8 + 64);
    *(_QWORD *)(v1 + 156) = 0;
  }
  return mutex_unlock(v1 + 272);
}
