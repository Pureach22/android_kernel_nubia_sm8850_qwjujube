__int64 __fastcall htc_fw_event_handler(__int64 result)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  v1 = *(__int64 (__fastcall **)(_QWORD))(result + 3032);
  if ( v1 )
  {
    v2 = *(_QWORD *)(result + 3024);
    if ( *((_DWORD *)v1 - 1) != -963780396 )
      __break(0x8228u);
    return v1(v2);
  }
  return result;
}
