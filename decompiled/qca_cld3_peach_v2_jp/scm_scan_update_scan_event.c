char *__fastcall scm_scan_update_scan_event(char *result, __int64 a2, const void *a3)
{
  _DWORD *v4; // x21
  char *v5; // x20
  _QWORD *v6; // x22

  if ( a2 )
  {
    v4 = result + 20480;
    v5 = result + 18744;
    v6 = result;
    result = (char *)qdf_mem_copy(result + 18744, a3, 0x8F0u);
    v6[2597] = 0;
    v4[72] = 0;
    v6[2599] = 0;
    v4[76] = 0;
    v6[2601] = 0;
    v4[80] = 0;
    *(_QWORD *)(a2 + 32) = v5;
  }
  return result;
}
