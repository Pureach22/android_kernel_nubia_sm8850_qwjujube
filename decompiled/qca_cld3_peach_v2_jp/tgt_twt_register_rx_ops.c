__int64 __fastcall tgt_twt_register_rx_ops(__int64 a1)
{
  *(_QWORD *)(a1 + 1224) = tgt_twt_enable_complete_resp_handler;
  *(_QWORD *)(a1 + 1232) = tgt_twt_disable_complete_resp_handler;
  return tgt_twt_register_ext_rx_ops();
}
