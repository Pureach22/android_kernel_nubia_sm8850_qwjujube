__int64 __fastcall tdls_activate_send_mgmt_request_flush_cb(__int64 a1)
{
  _qdf_mem_free(*(_QWORD *)(a1 + 8));
  *(_QWORD *)(a1 + 8) = 0;
  return 0;
}
