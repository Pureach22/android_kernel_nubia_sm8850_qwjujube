__int64 __fastcall ims_del_server(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 v9; // x10

  result = ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: IMS server exit\n");
  _X8 = (unsigned __int64 *)(a1 + 600);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 & 0xFFFFFFFFFFF7FFFFLL, _X8) );
  return result;
}
