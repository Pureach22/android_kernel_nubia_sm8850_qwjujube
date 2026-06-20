void __fastcall htc_print_credit_history(__int64 a1, unsigned int a2, _DWORD *a3, __int64 a4)
{
  unsigned int v4; // w22
  unsigned __int64 StatusReg; // x8

  v4 = a2;
  if ( *(a3 - 1) != 1872960511 )
    __break(0x8234u);
  ((void (__fastcall *)(__int64, const char *, _QWORD))a3)(a4, "HTC Credit History (count %u)", a2);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&g_htc_credit_lock);
    if ( v4 >= g_htc_credit_history_length )
      v4 = g_htc_credit_history_length;
    if ( *(a3 - 1) != 1872960511 )
      __break(0x8234u);
    ((void (__fastcall *)(__int64, const char *))a3)(
      a4,
      "Time (seconds)     Type                         Credits    Queue Depth");
    if ( v4 )
      JUMPOUT(0x550FD4);
    JUMPOUT(0x55103C);
  }
  JUMPOUT(0x55108C);
}
