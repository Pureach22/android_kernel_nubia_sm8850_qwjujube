__int64 __fastcall cm_get_wmi_auth_type(unsigned int a1)
{
  if ( a1 > 0x1D )
    return 0;
  else
    return dword_AEFC94[a1];
}
