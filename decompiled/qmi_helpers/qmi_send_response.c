unsigned __int64 __fastcall qmi_send_response(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int16 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  return qmi_send_message(a1, a2, a3, 2, a4, a5, a6, a7);
}
