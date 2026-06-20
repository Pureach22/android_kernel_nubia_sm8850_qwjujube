__int64 __fastcall target_if_tdls_register_tx_ops(_QWORD *a1)
{
  a1[167] = target_if_tdls_update_fw_state;
  a1[169] = target_if_tdls_set_offchan_mode;
  a1[170] = target_if_tdls_register_event_handler;
  a1[171] = target_if_tdls_unregister_event_handler;
  return 0;
}
