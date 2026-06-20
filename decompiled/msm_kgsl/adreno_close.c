__int64 __fastcall adreno_close(__int64 a1)
{
  return kgsl_pwrctrl_change_state(a1, 1);
}
