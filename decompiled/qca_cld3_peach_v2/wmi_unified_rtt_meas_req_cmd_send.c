__int64 __fastcall wmi_unified_rtt_meas_req_cmd_send(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2480LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != -1058660041 )
    __break(0x8228u);
  return v1();
}
