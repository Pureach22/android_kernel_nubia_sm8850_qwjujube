__int64 __fastcall vmperm_rcu_cb(__int64 a1)
{
  kfree(*(_QWORD *)(a1 - 128));
  kfree(*(_QWORD *)(a1 - 136));
  return kfree(a1 - 168);
}
