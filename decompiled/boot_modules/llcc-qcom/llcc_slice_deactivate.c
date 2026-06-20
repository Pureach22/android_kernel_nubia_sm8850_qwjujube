__int64 __fastcall llcc_slice_deactivate(unsigned __int64 a1)
{
  __int64 result; // x0
  unsigned int *v3; // x20
  unsigned __int64 v4; // x0
  unsigned int updated; // w0
  unsigned int v6; // w19
  __int64 v7; // x0
  unsigned int v14; // w10

  if ( (unsigned __int64)drv_data >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)drv_data;
  result = 4294967274LL;
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL )
  {
    v3 = (unsigned int *)a1;
    mutex_lock(drv_data + 40);
    if ( (int)v3[4] < 2 )
    {
      v4 = *v3;
      if ( ((*(_QWORD *)(*(_QWORD *)(drv_data + 104) + ((v4 >> 3) & 0x1FFFFFF8)) >> v4) & 1) != 0 )
      {
        updated = llcc_update_act_ctrl(v4, 4, 1);
        if ( updated )
        {
          v6 = updated;
          mutex_unlock(drv_data + 40);
          return v6;
        }
        v3[4] = 0;
        v7 = drv_data + 40;
        *(_QWORD *)(*(_QWORD *)(drv_data + 104) + (((unsigned __int64)*v3 >> 3) & 0x1FFFFFF8)) &= ~(1LL << *v3);
      }
      else
      {
        v7 = drv_data + 40;
      }
    }
    else
    {
      _X8 = v3 + 4;
      __asm { PRFM            #0x11, [X8] }
      do
        v14 = __ldxr(_X8);
      while ( __stlxr(v14 - 1, _X8) );
      __dmb(0xBu);
      v7 = drv_data + 40;
    }
    mutex_unlock(v7);
    return 0;
  }
  return result;
}
