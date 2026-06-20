__int64 __fastcall btfm_slim_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 152);
  snd_soc_unregister_component();
  return kfree(v1);
}
