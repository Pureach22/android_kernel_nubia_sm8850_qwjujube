__int64 __fastcall _osif_vdev_sync_trans_start_wait(__int64 a1, __int64 **a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 *v7; // x23
  unsigned __int64 v8; // x22
  unsigned __int64 v9; // x24
  __int64 v10; // x0
  unsigned __int64 *v11; // x16
  unsigned int started; // w0
  __int64 result; // x0

  *a2 = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&_osif_vdev_sync_lock);
  }
  else
  {
    raw_spin_lock_bh(&_osif_vdev_sync_lock);
    qword_85AB90 |= 1uLL;
  }
  v7 = &_osif_vdev_sync_arr;
  if ( byte_85AB08 == 1 && _osif_vdev_sync_arr == a1 )
  {
    v8 = 8;
    v9 = 144;
  }
  else
  {
    v7 = &qword_85AB10;
    if ( byte_85AB20 == 1 && qword_85AB10 == a1 )
    {
      v8 = 32;
      v9 = 144;
    }
    else
    {
      v7 = &qword_85AB28;
      if ( byte_85AB38 == 1 && qword_85AB28 == a1 )
      {
        v8 = 56;
        v9 = 144;
      }
      else
      {
        v7 = &qword_85AB40;
        if ( byte_85AB50 == 1 && qword_85AB40 == a1 )
        {
          v8 = 80;
          v9 = 144;
        }
        else
        {
          v7 = &qword_85AB58;
          if ( byte_85AB68 == 1 && qword_85AB58 == a1 )
          {
            v8 = 104;
            v9 = 144;
          }
          else
          {
            if ( ((unsigned __int8)byte_85AB80 & (qword_85AB70 == a1)) != 0 )
              v9 = 144;
            else
              v9 = 0;
            if ( ((unsigned __int8)byte_85AB80 & (qword_85AB70 == a1)) != 0 )
              v7 = &qword_85AB70;
            else
              v7 = nullptr;
            if ( ((unsigned __int8)byte_85AB80 & (qword_85AB70 == a1)) != 0 )
              v8 = 128;
            else
              v8 = 8;
          }
        }
      }
    }
  }
  if ( (qword_85AB90 & 1) == 0 )
  {
    v10 = raw_spin_unlock(&_osif_vdev_sync_lock);
    if ( v7 )
      goto LABEL_31;
    return 4294967285LL;
  }
  qword_85AB90 &= ~1uLL;
  v10 = raw_spin_unlock_bh(&_osif_vdev_sync_lock);
  if ( !v7 )
    return 4294967285LL;
LABEL_31:
  if ( v9 < v8 )
  {
    __break(1u);
    __ldaxp(v11);
    return osif_vdev_sync_trans_stop(v10);
  }
  else
  {
    started = dsc_vdev_trans_start_wait(v7[1], a3);
    if ( !started )
    {
      *a2 = v7;
      goto LABEL_36;
    }
    result = qdf_status_to_os_return(started);
    if ( !(_DWORD)result )
    {
      v7 = *a2;
LABEL_36:
      dsc_vdev_wait_for_ops(v7[1]);
      dsc_vdev_wait_for_uptree_ops((*a2)[1]);
      return 0;
    }
  }
  return result;
}
