__int64 __fastcall spec_sync_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v3; // w19
  unsigned int v11; // w10

  v2 = *(_QWORD *)(a2 + 32);
  mutex_lock(&unk_7B60);
  if ( *(_DWORD *)(v2 + 88) )
  {
    _X8 = (unsigned int *)(v2 + 88);
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 - 1, _X8) );
    if ( !*(_DWORD *)(v2 + 88) )
      clear_fence_array_tracker(1);
    v3 = 0;
  }
  else
  {
    printk(&unk_7945, "spec_sync_release");
    v3 = -19;
  }
  mutex_unlock(&unk_7B60);
  return v3;
}
