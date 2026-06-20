__int64 __fastcall geni_i2c_shutdown(__int64 a1)
{
  __int64 v1; // x19
  void (__fastcall *v2)(__int64, __int64); // x8
  __int64 (__fastcall *v3)(__int64, __int64); // x8
  unsigned __int64 v11; // x9

  v1 = *(_QWORD *)(a1 + 168);
  ipc_log_string(*(_QWORD *)(v1 + 5096), "Enter %s:%d\n", "geni_i2c_shutdown", 1);
  if ( *(_QWORD *)v1 )
    i2c_trace_log();
  v2 = **(void (__fastcall ***)(__int64, __int64))(v1 + 64);
  if ( *((_DWORD *)v2 - 1) != 181739622 )
    __break(0x8228u);
  v2(v1 + 32, 1);
  _X8 = (unsigned __int64 *)(v1 + 1056);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 | 1, _X8) );
  v3 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v1 + 64) + 16LL);
  if ( *((_DWORD *)v3 - 1) != 181739622 )
    __break(0x8228u);
  return v3(v1 + 32, 1);
}
