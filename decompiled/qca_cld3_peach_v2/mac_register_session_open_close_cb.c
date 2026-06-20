__int64 __fastcall mac_register_session_open_close_cb(__int64 result, __int64 a2, __int64 a3)
{
  *(_QWORD *)(result + 22032) = a2;
  *(_QWORD *)(result + 22040) = a3;
  return result;
}
