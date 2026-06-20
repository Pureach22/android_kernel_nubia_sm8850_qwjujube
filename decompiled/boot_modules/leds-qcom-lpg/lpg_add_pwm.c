__int64 __fastcall lpg_add_pwm(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  unsigned int v3; // w19

  v2 = devm_pwmchip_alloc(*a1, *((unsigned int *)a1 + 38), 0);
  v3 = v2;
  a1[8] = v2;
  if ( v2 < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v2 + 152) = a1;
    *(_QWORD *)(v2 + 912) = &lpg_pwm_ops;
    v3 = _devm_pwmchip_add(*a1, v2, &_this_module);
    if ( v3 )
      dev_err_probe(*a1, v3, "failed to add PWM chip\n");
  }
  return v3;
}
