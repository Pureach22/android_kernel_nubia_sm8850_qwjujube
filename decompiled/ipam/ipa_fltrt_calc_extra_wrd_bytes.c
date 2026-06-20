__int64 __fastcall ipa_fltrt_calc_extra_wrd_bytes(_BYTE *a1)
{
  int v1; // w8
  int v2; // w8
  unsigned int v3; // w19
  __int64 ipc_logbuf_low; // x0

  if ( a1[2] )
    v1 = 2;
  else
    v1 = 1;
  if ( !a1[4] )
    v1 = a1[2] != 0;
  if ( a1[48] )
    ++v1;
  v2 = v1 + (unsigned __int8)a1[100] + (unsigned __int8)a1[20] + (unsigned __int8)a1[72] + (unsigned __int8)a1[6];
  if ( a1[62] )
    ++v2;
  if ( a1[56] )
    v3 = v2 + 1;
  else
    v3 = v2;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d extra bytes number %d\n", "ipa_fltrt_calc_extra_wrd_bytes", 2660, v3);
  }
  return v3;
}
