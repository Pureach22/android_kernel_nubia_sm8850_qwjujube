__int64 __fastcall aw_cali_misc_unlocked_ioctl(__int64 a1, __int16 a2, __int64 a3)
{
  if ( (a2 & 0xFF00) == 0x6100 )
  {
    if ( (unsigned int)aw_cali_misc_ops(*(_QWORD *)(a1 + 32)) )
      return -22;
    else
      return 0;
  }
  else
  {
    printk(&unk_237BF, "aw_cali_misc_unlocked_ioctl", a3);
    return -22;
  }
}
