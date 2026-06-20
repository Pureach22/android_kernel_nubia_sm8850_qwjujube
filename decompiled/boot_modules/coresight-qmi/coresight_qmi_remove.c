__int64 __fastcall coresight_qmi_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  qmi_handle_release(v1 + 64);
  return coresight_unregister(*(_QWORD *)(v1 + 8));
}
