__int64 __fastcall wmi_unified_bss_chan_info_request_cmd_send(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2120LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 199598642 )
    __break(0x8228u);
  return v1();
}
