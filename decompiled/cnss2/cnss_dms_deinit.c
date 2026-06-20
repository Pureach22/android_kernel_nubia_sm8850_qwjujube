__int64 __fastcall cnss_dms_deinit(__int64 a1)
{
  unsigned __int64 v8; // x9

  _X8 = (unsigned __int64 *)(a1 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v8 = __ldxr(_X8);
  while ( __stxr(v8 | 0x8000000, _X8) );
  return qmi_handle_release(a1 + 1160);
}
