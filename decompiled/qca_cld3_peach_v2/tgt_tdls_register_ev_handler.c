__int64 __fastcall tgt_tdls_register_ev_handler(__int64 a1)
{
  __int64 v1; // x8
  _DWORD *v2; // x8

  v1 = *(_QWORD *)(a1 + 2128);
  if ( v1 == -1336 )
    return 0;
  v2 = *(_DWORD **)(v1 + 1360);
  if ( !v2 )
    return 0;
  if ( *(v2 - 1) != -1796695762 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v2)(a1, 0);
}
