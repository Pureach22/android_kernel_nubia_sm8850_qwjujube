__int64 __fastcall ois_debugfs_getvalue(__int64 *a1, _QWORD *a2)
{
  __int64 v3; // x8
  __int64 v4; // x4
  unsigned int v5; // w0
  unsigned int v6; // w19
  __int64 result; // x0
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v4 = *((unsigned int *)a1 + 2);
  v8 = 0;
  v5 = camera_io_dev_read(v3 + 3656, *((unsigned int *)a1 + 4), (__int64)&v8, *((unsigned int *)a1 + 3), v4, 0);
  if ( (v5 & 0x80000000) != 0 )
  {
    v6 = v5;
    printk(&unk_43A85B);
    result = v6;
  }
  else
  {
    *a2 = v8;
    printk(&unk_3E7E89);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
