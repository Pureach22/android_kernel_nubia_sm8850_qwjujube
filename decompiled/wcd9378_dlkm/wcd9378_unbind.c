__int64 __fastcall wcd9378_unbind(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 152);
  wcd_free_irq(v1 + 408, 14, 0);
  wcd_free_irq(v1 + 408, 13, 0);
  wcd_free_irq(v1 + 408, 15, 0);
  wcd_irq_exit(v1 + 408, *(_QWORD *)(v1 + 400));
  snd_soc_unregister_component(a1);
  return component_unbind_all(a1, v1);
}
