__int64 cleanup_module()
{
  gh_rm_unregister_notifier(&gh_irq_lent_nb);
  gh_rm_unregister_notifier(&gh_irq_released_accepted_nb);
  return gunyah_qtvm_unregister_notifier(&gh_irq_vm_nb);
}
