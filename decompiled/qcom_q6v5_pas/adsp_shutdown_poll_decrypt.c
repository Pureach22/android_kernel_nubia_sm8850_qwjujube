__int64 __fastcall adsp_shutdown_poll_decrypt(__int64 a1)
{
  int v2; // w8
  int v3; // w20
  __int64 result; // x0

  v2 = -49;
  do
  {
    v3 = v2;
    msleep(100);
    result = qcom_scm_pas_shutdown(*(unsigned int *)(a1 + 456));
    if ( (_DWORD)result != -22 )
      break;
    v2 = v3 + 1;
  }
  while ( v3 );
  return result;
}
