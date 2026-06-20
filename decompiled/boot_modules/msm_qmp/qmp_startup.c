__int64 __fastcall qmp_startup(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x0

  v1 = *(_QWORD *)(a1 + 240);
  if ( !v1 )
    return 4294967274LL;
  if ( !wait_for_completion_timeout(v1 + 328, 1250) )
    return 4294967285LL;
  mutex_lock(v1 + 272);
  if ( *(_DWORD *)(v1 + 264) == 2 )
  {
    writel(0xFFFF, *(_QWORD *)(v1 + 168) + 44LL);
    v2 = *(_QWORD *)(v1 + 496);
    *(_DWORD *)(v1 + 264) = 3;
    __dsb(0xEu);
    v3 = *(_QWORD *)(v2 + 128);
    if ( v3 )
    {
      mbox_send_message(v3, 0);
      mbox_client_txdone(*(_QWORD *)(v2 + 128), 0);
    }
    else
    {
      writel_relaxed(*(unsigned int *)(v2 + 56));
    }
    ++*(_DWORD *)(v2 + 64);
  }
  mutex_unlock(v1 + 272);
  if ( wait_for_completion_timeout(v1 + 360, 1250) )
    return 0;
  else
    return 4294967234LL;
}
