_QWORD *__fastcall tgt_twt_register_ext_rx_ops(_QWORD *result)
{
  result[155] = tgt_twt_setup_complete_resp_handler;
  result[156] = tgt_twt_teardown_complete_resp_handler;
  result[157] = tgt_twt_pause_complete_resp_handler;
  result[158] = tgt_twt_resume_complete_resp_handler;
  result[159] = tgt_twt_nudge_complete_resp_handler;
  result[160] = tgt_twt_notify_complete_resp_handler;
  result[161] = tgt_twt_ack_complete_resp_handler;
  return result;
}
