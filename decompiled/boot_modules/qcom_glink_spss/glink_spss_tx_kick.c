__int64 __fastcall glink_spss_tx_kick(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 72);
  mbox_send_message(*(_QWORD *)(v1 + 1016), 0);
  return mbox_client_txdone(*(_QWORD *)(v1 + 1016), 0);
}
