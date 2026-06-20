void __fastcall os_if_get_ndi_vdev_by_ifname_cb(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 *v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8

  if ( !*(_QWORD *)(a3 + 8) )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 1272);
      v6 = *(__int64 **)(a2 + 608);
      if ( v6 )
      {
LABEL_6:
        v7 = *v6;
        if ( v7 && !strcmp((const char *)(*(_QWORD *)(v7 + 32) + 296LL), *(const char **)a3) )
          *(_QWORD *)(a3 + 8) = a2;
      }
    }
    else
    {
      raw_spin_lock_bh(a2 + 1272);
      *(_QWORD *)(a2 + 1280) |= 1uLL;
      v6 = *(__int64 **)(a2 + 608);
      if ( v6 )
        goto LABEL_6;
    }
    v8 = *(_QWORD *)(a2 + 1280);
    if ( (v8 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 1280) = v8 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 1272);
    }
    else
    {
      raw_spin_unlock(a2 + 1272);
    }
  }
}
