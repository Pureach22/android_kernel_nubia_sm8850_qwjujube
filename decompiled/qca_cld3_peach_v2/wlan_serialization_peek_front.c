__int64 __fastcall wlan_serialization_peek_front(_QWORD *a1, _QWORD *a2)
{
  return qdf_list_peek_front(a1, a2);
}
