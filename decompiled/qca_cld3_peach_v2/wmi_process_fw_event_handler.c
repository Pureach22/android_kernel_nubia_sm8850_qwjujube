__int64 __fastcall wmi_process_fw_event_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v11; // x1
  __int64 *v12; // x20
  int v13; // w21
  __int64 v14; // x8
  unsigned int v22; // w10

  v9 = *(_QWORD *)(a1 + 8);
  v12 = *(__int64 **)v9;
  v11 = *(_QWORD *)(v9 + 8);
  v13 = **(_DWORD **)(v11 + 224) & 0xFFFFFF;
  _wmi_control_rx(*(__int64 **)v9, v11, a2, a3, a4, a5, a6, a7, a8, a9);
  v14 = v12[93];
  if ( *(_DWORD *)(v14 + 308) == v13 || *(_DWORD *)(v14 + 140) == v13 )
  {
    _X8 = (unsigned int *)(v12 + 106);
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 - 1, _X8) );
  }
  _qdf_mem_free(*(_QWORD *)(a1 + 8));
  return 0;
}
