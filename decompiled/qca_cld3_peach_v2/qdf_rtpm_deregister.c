__int64 __fastcall qdf_rtpm_deregister(unsigned int a1)
{
  __int64 v1; // x0

  if ( a1 > 3 )
    v1 = 12;
  else
    v1 = (unsigned int)dword_B35888[a1];
  return ((__int64 (__fastcall *)(__int64))hif_rtpm_deregister)(v1);
}
