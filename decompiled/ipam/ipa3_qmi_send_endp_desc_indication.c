__int64 __fastcall ipa3_qmi_send_endp_desc_indication(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0

  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v3,
                   "ipa-wan %s:%d Sending QMI_IPA_ENDP_DESC_INDICATION_V01\n",
                   "ipa3_qmi_send_endp_desc_indication",
                   3088);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v5,
      "ipa-wan %s:%d Sending QMI_IPA_ENDP_DESC_INDICATION_V01\n",
      "ipa3_qmi_send_endp_desc_indication",
      3088);
  }
  if ( ipa3_svc_handle )
    return qmi_send_indication(ipa3_svc_handle, ipa3_qmi_ctx + 28864, 63, 507, &ipa_endp_desc_indication_msg_v01_ei, a1);
  else
    return 4294967186LL;
}
