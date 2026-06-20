long double __fastcall out_dword(unsigned int a1, unsigned int a2)
{
  __int64 v4; // x21
  _DWORD *v5; // x9
  __int64 v6; // x0
  long double result; // q0
  __int64 v8; // x0

  v4 = ((__int64 (*)(void))get_access_funcs)();
  v5 = *(_DWORD **)(v4 + 8);
  v6 = *(_QWORD *)(ipa3_ctx + 44872) + a1;
  if ( *(v5 - 1) != -1783303382 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, _QWORD))v5)(v6, a2);
  if ( *(__int64 (__fastcall **)())(v4 + 8) == nop_write && ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v8 )
      return ipc_log_string(v8, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, a1);
  }
  return result;
}
