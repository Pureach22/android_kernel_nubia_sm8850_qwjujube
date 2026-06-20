__int64 __fastcall hdd_ioctl(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int v7; // w19
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  result = _osif_vdev_sync_op_start(a1, v8, "hdd_ioctl");
  if ( !(_DWORD)result )
  {
    v7 = _hdd_ioctl(a1, *(_QWORD *)(a2 + 16), a3);
    _osif_vdev_sync_op_stop(v8[0], "hdd_ioctl");
    result = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
