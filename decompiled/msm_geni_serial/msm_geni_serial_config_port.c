__int64 __fastcall msm_geni_serial_config_port(__int64 result, char a2)
{
  if ( (a2 & 1) != 0 )
    *(_DWORD *)(result + 296) = 88;
  return result;
}
