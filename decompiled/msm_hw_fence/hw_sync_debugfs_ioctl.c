__int64 __fastcall hw_sync_debugfs_ioctl(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x4
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  __int64 v6; // x0

  v4 = (unsigned int)a2 - 2;
  if ( (unsigned int)v4 >= 0x12 )
  {
    printk(&unk_2AB47, "hw_sync_debugfs_ioctl", 569, v3, v4);
    return -22;
  }
  else
  {
    v5 = (__int64 (__fastcall *)(__int64, __int64))hw_sync_debugfs_ioctls[3 * (unsigned int)v4 + 1];
    if ( v5 )
    {
      v6 = *(_QWORD *)(a1 + 32);
      if ( *((_DWORD *)v5 - 1) != 602392211 )
        __break(0x8228u);
      return v5(v6, a3);
    }
    else
    {
      printk(&unk_260FE, "hw_sync_debugfs_ioctl", 575, v3, v4);
      return -25;
    }
  }
}
