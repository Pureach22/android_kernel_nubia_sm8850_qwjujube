__int64 __fastcall msm_stub_dev_probe(__int64 a1)
{
  return snd_soc_register_component(a1 + 16, &soc_msm_stub, &msm_stub_dais, 2);
}
