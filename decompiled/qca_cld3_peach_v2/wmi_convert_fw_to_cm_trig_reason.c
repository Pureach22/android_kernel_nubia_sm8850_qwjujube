__int64 __fastcall wmi_convert_fw_to_cm_trig_reason(__int64 result)
{
  if ( (unsigned int)(result - 1) >= 0x14 )
    return 0;
  else
    return (unsigned int)result;
}
