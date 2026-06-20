__int64 __fastcall wlan_serialization_peek_next(_QWORD *a1, _QWORD *a2, _QWORD *a3)
{
  return qdf_list_peek_next(a1, a2, a3);
}
