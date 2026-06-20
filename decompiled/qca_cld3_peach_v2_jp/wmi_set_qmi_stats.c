__int64 __fastcall wmi_set_qmi_stats(__int64 result, char a2)
{
  *(_BYTE *)(result + 704) = a2;
  return result;
}
