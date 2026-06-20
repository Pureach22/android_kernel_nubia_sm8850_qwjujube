__int64 __fastcall hdd_dev_private_ioctl(_QWORD *a1, __int64 a2, unsigned __int64 a3, unsigned int a4)
{
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w19
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  result = _osif_vdev_sync_op_start(a1, v17, "hdd_dev_private_ioctl");
  if ( !(_DWORD)result )
  {
    v16 = _hdd_ioctl(a1, a3, a4, v8, v9, v10, v11, v12, v13, v14, v15);
    _osif_vdev_sync_op_stop(v17[0], "hdd_dev_private_ioctl");
    result = v16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
