__int64 __fastcall wmi_send_time_stamp_sync_cmd_tlv(__int64 result)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(result + 728) + 3976LL);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != -725170640 )
      __break(0x8228u);
    return v1();
  }
  return result;
}
