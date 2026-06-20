__int64 __fastcall wcdcal_get_fw_cal(__int64 a1, unsigned int a2)
{
  if ( a1 )
  {
    if ( a2 >= 4 )
    {
      printk(&unk_8B46, "wcdcal_get_fw_cal");
      return 0;
    }
    else
    {
      mutex_lock(a1 + 72);
      if ( (*(_QWORD *)(a1 + 8LL * a2 + 40) & 4) != 0 )
      {
        mutex_unlock(a1 + 72);
        return *(_QWORD *)(a1 + 8LL * a2);
      }
      else
      {
        printk(&unk_89AF, "wcdcal_get_fw_cal");
        mutex_unlock(a1 + 72);
        return 0;
      }
    }
  }
  else
  {
    printk(&unk_8C35, "wcdcal_get_fw_cal");
    return 0;
  }
}
