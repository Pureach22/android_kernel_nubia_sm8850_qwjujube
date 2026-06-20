__int64 __fastcall osif_vdev_sync_create(__int64 a1, __int64 **a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 *v6; // x21
  unsigned int v7; // w20
  unsigned __int64 v8; // x8

  result = 4294967274LL;
  if ( !a1 || !a2 )
    return result;
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
  v6 = &_osif_vdev_sync_arr;
  if ( byte_85AB08 == 1
    && (v6 = &qword_85AB10, byte_85AB20 == 1)
    && (v6 = &qword_85AB28, byte_85AB38 == 1)
    && (v6 = &qword_85AB40, byte_85AB50 == 1)
    && (v6 = &qword_85AB58, byte_85AB68 == 1)
    && (v6 = &qword_85AB70, (byte_85AB80 & 1) != 0) )
  {
    v6 = nullptr;
  }
  else
  {
    *((_BYTE *)v6 + 16) = 1;
  }
  if ( (qword_85AB90 & 1) == 0 )
  {
    raw_spin_unlock(&_osif_vdev_sync_lock);
    if ( v6 )
      goto LABEL_17;
    return 4294967284LL;
  }
  qword_85AB90 &= ~1uLL;
  raw_spin_unlock_bh(&_osif_vdev_sync_lock);
  if ( !v6 )
    return 4294967284LL;
LABEL_17:
  result = osif_psoc_sync_dsc_vdev_create(a1, v6 + 1);
  if ( (_DWORD)result )
  {
    v7 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v8 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v8 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v8 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(&_osif_vdev_sync_lock);
    }
    else
    {
      raw_spin_lock_bh(&_osif_vdev_sync_lock);
      qword_85AB90 |= 1uLL;
    }
    qdf_mem_set(v6, 0x18u, 0);
    if ( (qword_85AB90 & 1) != 0 )
    {
      qword_85AB90 &= ~1uLL;
      raw_spin_unlock_bh(&_osif_vdev_sync_lock);
    }
    else
    {
      raw_spin_unlock(&_osif_vdev_sync_lock);
    }
    return qdf_status_to_os_return(v7);
  }
  else
  {
    *a2 = v6;
  }
  return result;
}
