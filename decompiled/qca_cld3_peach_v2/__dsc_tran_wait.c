__int64 __fastcall _dsc_tran_wait(_BYTE *a1)
{
  unsigned int v2; // w20
  __int64 v3; // x1

  v2 = qdf_wait_single_event((__int64)(a1 + 32), 0);
  qdf_event_destroy((__int64)(a1 + 32), v3);
  if ( !v2 )
  {
    if ( *a1 )
      return 10;
    else
      return 0;
  }
  return v2;
}
