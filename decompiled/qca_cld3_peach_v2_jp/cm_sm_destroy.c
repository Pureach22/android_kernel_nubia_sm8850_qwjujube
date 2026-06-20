__int64 __fastcall cm_sm_destroy(__int64 a1)
{
  qdf_mutex_destroy(a1 + 8);
  wlan_sm_delete(*(_QWORD *)(a1 + 72));
  return 0;
}
