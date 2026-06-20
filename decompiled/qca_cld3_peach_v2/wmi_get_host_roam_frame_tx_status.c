__int64 __fastcall wmi_get_host_roam_frame_tx_status(unsigned int a1)
{
  if ( a1 < 9 )
    return a1 + 1;
  else
    return 0;
}
