__int64 __fastcall icnss_unregister_ims_service(__int64 a1)
{
  return qmi_handle_release(a1 + 1232);
}
