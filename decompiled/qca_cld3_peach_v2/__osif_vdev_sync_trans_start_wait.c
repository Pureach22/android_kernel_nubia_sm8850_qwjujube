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
    qword_923DB0 |= 1uLL;
  }
  v7 = &_osif_vdev_sync_arr;
  if ( byte_923CE0 == 1 && _osif_vdev_sync_arr == a1 )
  {
    v8 = 8;
    v9 = 216;
  }
  else
  {
    v7 = &qword_923CE8;
    if ( byte_923CF8 == 1 && qword_923CE8 == a1 )
    {
      v8 = 32;
      v9 = 216;
    }
    else
    {
      v7 = &qword_923D00;
      if ( byte_923D10 == 1 && qword_923D00 == a1 )
      {
        v8 = 56;
        v9 = 216;
      }
      else
      {
        v7 = &qword_923D18;
        if ( byte_923D28 == 1 && qword_923D18 == a1 )
        {
          v8 = 80;
          v9 = 216;
        }
        else
        {
          v7 = &qword_923D30;
          if ( byte_923D40 == 1 && qword_923D30 == a1 )
          {
            v8 = 104;
            v9 = 216;
          }
          else
          {
            v7 = &qword_923D48;
            if ( byte_923D58 == 1 && qword_923D48 == a1 )
            {
              v8 = 128;
              v9 = 216;
            }
            else
            {
              v7 = &qword_923D60;
              if ( byte_923D70 == 1 && qword_923D60 == a1 )
              {
                v8 = 152;
                v9 = 216;
              }
              else
              {
                v7 = &qword_923D78;
                if ( byte_923D88 == 1 && qword_923D78 == a1 )
                {
                  v8 = 176;
                  v9 = 216;
                }
                else
                {
                  if ( ((unsigned __int8)byte_923DA0 & (qword_923D90 == a1)) != 0 )
                    v9 = 216;
                  else
                    v9 = 0;
                  if ( ((unsigned __int8)byte_923DA0 & (qword_923D90 == a1)) != 0 )
                    v7 = &qword_923D90;
                  else
                    v7 = nullptr;
                  if ( ((unsigned __int8)byte_923DA0 & (qword_923D90 == a1)) != 0 )
                    v8 = 200;
                  else
                    v8 = 8;
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (qword_923DB0 & 1) == 0 )
  {
    v10 = raw_spin_unlock(&_osif_vdev_sync_lock);
    if ( v7 )
      goto LABEL_40;
    return 4294967285LL;
  }
  qword_923DB0 &= ~1uLL;
  v10 = raw_spin_unlock_bh(&_osif_vdev_sync_lock);
  if ( !v7 )
    return 4294967285LL;
LABEL_40:
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
      goto LABEL_45;
    }
    result = qdf_status_to_os_return(started);
    if ( !(_DWORD)result )
    {
      v7 = *a2;
LABEL_45:
      dsc_vdev_wait_for_ops(v7[1]);
      dsc_vdev_wait_for_uptree_ops((*a2)[1]);
      return 0;
    }
  }
  return result;
}
