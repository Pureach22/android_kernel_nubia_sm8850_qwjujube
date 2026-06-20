__int64 __fastcall tdls_scan_done_callback(__int64 result)
{
  __int64 v1; // x1

  if ( result )
  {
    v1 = *(unsigned int *)(result + 12);
    if ( (unsigned int)(v1 - 2) <= 2 )
      return tdls_set_current_mode(result, v1);
  }
  return result;
}
