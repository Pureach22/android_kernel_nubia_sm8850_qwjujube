__int64 __fastcall cnss_unregister_coex_service(__int64 a1)
{
  return qmi_handle_release(a1 + 6760);
}
