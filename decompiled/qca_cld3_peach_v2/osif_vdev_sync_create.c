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
    qword_923DB0 |= 1uLL;
  }
  v6 = &_osif_vdev_sync_arr;
  if ( byte_923CE0 != 1 )
    goto LABEL_17;
  v6 = &qword_923CE8;
  if ( byte_923CF8 != 1 )
    goto LABEL_17;
  v6 = &qword_923D00;
  if ( byte_923D10 == 1
    && (v6 = &qword_923D18, byte_923D28 == 1)
    && (v6 = &qword_923D30, byte_923D40 == 1)
    && (v6 = &qword_923D48, byte_923D58 == 1)
    && (v6 = &qword_923D60, byte_923D70 == 1)
    && (v6 = &qword_923D78, byte_923D88 == 1)
    && (v6 = &qword_923D90, (byte_923DA0 & 1) != 0) )
  {
    v6 = nullptr;
  }
  else
  {
LABEL_17:
    *((_BYTE *)v6 + 16) = 1;
  }
  if ( (qword_923DB0 & 1) == 0 )
  {
    raw_spin_unlock(&_osif_vdev_sync_lock);
    if ( v6 )
      goto LABEL_20;
    return 4294967284LL;
  }
  qword_923DB0 &= ~1uLL;
  raw_spin_unlock_bh(&_osif_vdev_sync_lock);
  if ( !v6 )
    return 4294967284LL;
LABEL_20:
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
      qword_923DB0 |= 1uLL;
    }
    qdf_mem_set(v6, 0x18u, 0);
    if ( (qword_923DB0 & 1) != 0 )
    {
      qword_923DB0 &= ~1uLL;
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
