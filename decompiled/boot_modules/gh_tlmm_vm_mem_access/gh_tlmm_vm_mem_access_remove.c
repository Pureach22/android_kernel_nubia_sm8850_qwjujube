__int64 __fastcall gh_tlmm_vm_mem_access_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,master", 0) )
    gh_mem_notifier_unregister(*(_QWORD *)(v1 + 56));
  gh_rm_unregister_notifier(v1 + 32);
  return gunyah_qtvm_unregister_notifier(v1 + 8);
}
