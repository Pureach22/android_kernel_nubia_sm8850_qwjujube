_QWORD *__fastcall tgt_twt_register_ext_rx_ops(_QWORD *result)
{
  result[166] = tgt_twt_setup_complete_resp_handler;
  result[167] = tgt_twt_teardown_complete_resp_handler;
  result[168] = tgt_twt_pause_complete_resp_handler;
  result[169] = tgt_twt_resume_complete_resp_handler;
  result[170] = tgt_twt_nudge_complete_resp_handler;
  result[171] = tgt_twt_notify_complete_resp_handler;
  result[172] = tgt_twt_ack_complete_resp_handler;
  return result;
}
