__int64 __fastcall msm_stub_dev_remove(__int64 a1)
{
  return snd_soc_unregister_component(a1 + 16);
}
