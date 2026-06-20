__int64 __fastcall sde_rm_request_hw_blk(__int64 a1, __int64 a2)
{
  __int64 v4; // x4
  __int64 v5; // x8
  unsigned int v6; // w20

  mutex_lock(a1 + 280);
  if ( a1 && a2 && (v4 = *(unsigned int *)(a2 + 8), (unsigned int)v4 < 0xF) )
  {
    *(_QWORD *)a2 = 0;
    v5 = a1 + 16 * v4 + 24;
    while ( 1 )
    {
      v5 = *(_QWORD *)v5;
      if ( v5 == a1 + 16 * v4 + 24 )
        break;
      if ( *(_DWORD *)(v5 + 32) != (_DWORD)v4 )
      {
        printk(&unk_262490, "_sde_rm_request_hw_blk_locked");
        goto LABEL_14;
      }
      if ( *(_DWORD *)(v5 + 36) == *(_DWORD *)(a2 + 12) )
      {
        *(_QWORD *)a2 = *(_QWORD *)(v5 + 40);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found type %d id %d\n", *(_DWORD *)(v5 + 32), *(_DWORD *)(v5 + 36));
        v6 = 1;
        goto LABEL_15;
      }
    }
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "no match, type %d id %d\n", v4, *(_DWORD *)(a2 + 12));
  }
  else
  {
    printk(&unk_26246B, "_sde_rm_request_hw_blk_locked");
  }
LABEL_14:
  v6 = 0;
LABEL_15:
  mutex_unlock(a1 + 280);
  return v6;
}
