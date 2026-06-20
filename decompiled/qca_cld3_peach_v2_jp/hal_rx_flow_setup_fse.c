__int64 __fastcall hal_rx_flow_setup_fse(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  _DWORD *v4; // x8

  v4 = *(_DWORD **)(*(_QWORD *)(a1 + 74392) + 1024LL);
  if ( !v4 )
    return 0;
  if ( *(v4 - 1) != 2046309326 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v4)(a2, a3, a4);
}
