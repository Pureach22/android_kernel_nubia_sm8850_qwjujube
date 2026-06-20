__int64 __fastcall target_if_twt_register_ext_tx_ops(_QWORD *a1)
{
  a1[2] = target_if_twt_setup_req;
  a1[3] = target_if_twt_teardown_req;
  a1[4] = target_if_twt_pause_req;
  a1[5] = target_if_twt_resume_req;
  a1[6] = target_if_twt_nudge_req;
  a1[7] = target_if_twt_ac_param_send;
  a1[8] = target_if_twt_send_unavailability_mode;
  return 0;
}
