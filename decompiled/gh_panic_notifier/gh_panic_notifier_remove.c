__int64 __fastcall gh_panic_notifier_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  if ( *(_BYTE *)(v1 + 132) == 1 )
  {
    gh_dbl_tx_unregister(*(_QWORD *)(v1 + 136));
    gunyah_qtvm_unregister_notifier(v1 + 160);
    gh_rm_unregister_notifier(v1 + 184);
    return kfree(recovery_vms);
  }
  else
  {
    gh_dbl_rx_unregister(*(_QWORD *)(v1 + 144));
    return wakeup_source_unregister(*(_QWORD *)(v1 + 152));
  }
}
