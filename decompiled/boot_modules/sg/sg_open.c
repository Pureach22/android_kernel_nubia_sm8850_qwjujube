__int64 __fastcall sg_open(__int64 a1, __int64 a2)
{
  int v2; // w19
  unsigned int v3; // w23
  unsigned int device; // w25
  __int64 lock_irqsave; // x21
  __int64 v7; // x0
  unsigned __int64 v8; // x19
  __int64 v11; // x21
  unsigned int v12; // w24
  __int64 v13; // x21
  unsigned __int64 v14; // x26
  unsigned int v15; // w0
  unsigned __int64 v16; // x0
  __int64 v17; // x22
  __int64 v18; // x1
  unsigned int v24; // w8
  int v26; // w8
  int v28; // w8

  v2 = *(_DWORD *)(a1 + 76);
  v3 = *(_DWORD *)(a2 + 48);
  nonseekable_open();
  if ( (v3 & 0x83) == 0x80 )
    return (unsigned int)-1;
  lock_irqsave = raw_read_lock_irqsave(&sg_index_lock);
  v7 = idr_find(&sg_index_idr, *(_QWORD *)&v2 & 0xFFFFFLL);
  if ( !v7 )
  {
    LODWORD(v8) = -6;
    goto LABEL_7;
  }
  v8 = v7;
  if ( *(_DWORD *)(v7 + 112) )
  {
    LODWORD(v8) = -19;
LABEL_7:
    raw_read_unlock_irqrestore(&sg_index_lock, lock_irqsave);
    return (unsigned int)v8;
  }
  _X20 = (unsigned int *)(v7 + 168);
  __asm { PRFM            #0x11, [X20] }
  do
    v24 = __ldxr(_X20);
  while ( __stxr(v24 + 1, _X20) );
  if ( v24 )
  {
    if ( (((v24 + 1) | v24) & 0x80000000) == 0 )
      goto LABEL_12;
    v18 = 1;
  }
  else
  {
    v18 = 2;
  }
  refcount_warn_saturate(v7 + 168, v18);
LABEL_12:
  raw_read_unlock_irqrestore(&sg_index_lock, lock_irqsave);
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)v8;
  v11 = *(_QWORD *)v8;
  v12 = scsi_device_get(*(_QWORD *)v8);
  if ( v12 )
    goto LABEL_44;
  device = scsi_autopm_get_device(v11);
  if ( !device )
  {
    if ( (v3 & 0x800) == 0 )
    {
      if ( !(unsigned int)scsi_block_when_processing_errors(v11) )
      {
        device = -6;
LABEL_35:
        scsi_autopm_put_device(v11);
        goto LABEL_36;
      }
      v14 = v8 + 32;
      mutex_lock(v8 + 32);
      v15 = open_wait(v8, v3);
      if ( v15 )
      {
        device = v15;
LABEL_34:
        mutex_unlock(v14);
        goto LABEL_35;
      }
      if ( (v3 & 0x80) == 0 )
      {
LABEL_29:
        if ( *(int *)(v8 + 120) <= 0 )
        {
          *(_BYTE *)(v8 + 124) = 0;
          *(_DWORD *)(v8 + 80) = *(unsigned __int16 *)(*(_QWORD *)(v11 + 8) + 260LL);
        }
        v16 = sg_add_sfp(v8);
        device = v16;
        if ( v16 < 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)(a2 + 32) = v16;
          ++*(_DWORD *)(v8 + 120);
          mutex_unlock(v14);
LABEL_44:
          __asm { PRFM            #0x11, [X20] }
          do
            v26 = __ldxr(_X20);
          while ( __stlxr(v26 - 1, _X20) );
          if ( v26 == 1 )
          {
            __dmb(9u);
            blk_put_queue(*(_QWORD *)(*(_QWORD *)v8 + 8LL));
            v13 = raw_write_lock_irqsave(&sg_index_lock);
            idr_remove(&sg_index_idr, *(unsigned int *)(v8 + 84));
            raw_write_unlock_irqrestore(&sg_index_lock, v13);
            kfree(v8);
            return v12;
          }
          else
          {
            if ( v26 <= 0 )
              refcount_warn_saturate(v8 + 168, 3);
            return v12;
          }
        }
        if ( (v3 & 0x80) != 0 )
        {
          *(_BYTE *)(v8 + 116) = 0;
          _wake_up(v8 + 8, 1, 1, 0);
        }
        goto LABEL_34;
      }
LABEL_28:
      *(_BYTE *)(v8 + 116) = 1;
      goto LABEL_29;
    }
    v14 = v8 + 32;
    mutex_lock(v8 + 32);
    if ( (v3 & 0x80) != 0 )
    {
      if ( *(int *)(v8 + 120) <= 0 )
        goto LABEL_28;
    }
    else if ( (*(_BYTE *)(v8 + 116) & 1) == 0 )
    {
      goto LABEL_29;
    }
    device = -16;
    goto LABEL_34;
  }
LABEL_36:
  __asm { PRFM            #0x11, [X20] }
  do
    v28 = __ldxr(_X20);
  while ( __stlxr(v28 - 1, _X20) );
  if ( v28 == 1 )
  {
    __dmb(9u);
    blk_put_queue(*(_QWORD *)(*(_QWORD *)v8 + 8LL));
    v17 = raw_write_lock_irqsave(&sg_index_lock);
    idr_remove(&sg_index_idr, *(unsigned int *)(v8 + 84));
    raw_write_unlock_irqrestore(&sg_index_lock, v17);
    kfree(v8);
  }
  else if ( v28 <= 0 )
  {
    refcount_warn_saturate(v8 + 168, 3);
  }
  scsi_device_put(v11);
  return device;
}
