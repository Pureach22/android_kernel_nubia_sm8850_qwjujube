__int64 init_module()
{
  unsigned int v0; // w19

  v0 = gh_rm_register_notifier(&gh_irq_lent_nb);
  if ( !v0 )
  {
    v0 = gunyah_qtvm_register_notifier(&gh_irq_vm_nb);
    if ( v0 )
    {
LABEL_5:
      gh_rm_unregister_notifier(&gh_irq_lent_nb);
      return v0;
    }
    v0 = gh_rm_register_notifier(&gh_irq_released_accepted_nb);
    if ( v0 )
    {
      gunyah_qtvm_unregister_notifier(&gh_irq_vm_nb);
      goto LABEL_5;
    }
  }
  return v0;
}
