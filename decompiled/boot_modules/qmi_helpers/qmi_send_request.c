__int64 __fastcall qmi_send_request(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  return qmi_send_message(a1, a2, a3, 0, a4, a5, a6, a7);
}
