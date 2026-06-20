__int64 __fastcall wireless_fw_update_time_ms_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (unsigned int)kstrtouint(a3, 0, a1 + 1080) )
    return -22;
  else
    return a4;
}
