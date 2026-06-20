__int64 __fastcall llcc_slice_activate(unsigned __int64 a1)
{
  __int64 result; // x0
  unsigned int *v3; // x20
  __int64 v4; // x8
  __int64 v5; // x0
  unsigned int updated; // w0
  unsigned int v7; // w19
  unsigned int v14; // w9
  unsigned int v17; // w9

  if ( (unsigned __int64)drv_data >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)drv_data;
  result = 4294967274LL;
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL )
  {
    v3 = (unsigned int *)a1;
    mutex_lock(drv_data + 40);
    if ( (int)v3[4] < 1 )
    {
      v4 = drv_data;
      if ( ((*(_QWORD *)(*(_QWORD *)(drv_data + 104) + (((unsigned __int64)*v3 >> 3) & 0x1FFFFFF8)) >> *v3) & 1) == 0 )
      {
        updated = llcc_update_act_ctrl();
        if ( updated )
        {
          v7 = updated;
          mutex_unlock(drv_data + 40);
          return v7;
        }
        _X8 = v3 + 4;
        __asm { PRFM            #0x11, [X8] }
        do
          v17 = __ldxr(_X8);
        while ( __stlxr(v17 + 1, _X8) );
        __dmb(0xBu);
        v5 = drv_data + 40;
        *(_QWORD *)(*(_QWORD *)(drv_data + 104) + (((unsigned __int64)*v3 >> 3) & 0x1FFFFFF8)) |= 1LL << *v3;
        goto LABEL_9;
      }
    }
    else
    {
      _X8 = v3 + 4;
      __asm { PRFM            #0x11, [X8] }
      do
        v14 = __ldxr(_X8);
      while ( __stlxr(v14 + 1, _X8) );
      __dmb(0xBu);
      v4 = drv_data;
    }
    v5 = v4 + 40;
LABEL_9:
    mutex_unlock(v5);
    return 0;
  }
  return result;
}
