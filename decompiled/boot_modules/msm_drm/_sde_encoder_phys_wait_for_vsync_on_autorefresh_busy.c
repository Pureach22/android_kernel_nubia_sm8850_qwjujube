__int64 __fastcall sde_encoder_phys_wait_for_vsync_on_autorefresh_busy(__int64 *a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 (__fastcall *v5)(_QWORD); // x9
  __int64 v6; // x0
  void (*v7)(void); // x8
  void *v8; // x0

  result = sde_encoder_get_disp_op(*a1);
  if ( !a1 || (v3 = a1[53]) == 0 )
  {
    v8 = &unk_223EAA;
    return printk(v8, "_sde_encoder_phys_wait_for_vsync_on_autorefresh_busy");
  }
  if ( (unsigned int)result >= 3 )
  {
    __break(0x5512u);
    return sde_encoder_phys_cmd_setup_irq_hw_idx(result);
  }
  v4 = (unsigned int)result;
  v5 = *(__int64 (__fastcall **)(_QWORD))(v3 + 8LL * (unsigned int)result + 440);
  if ( !v5 )
  {
    if ( (_DWORD)result )
      return result;
    v8 = &unk_23867A;
    return printk(v8, "_sde_encoder_phys_wait_for_vsync_on_autorefresh_busy");
  }
  v6 = a1[53];
  if ( *((_DWORD *)v5 - 1) != 1550245701 )
    __break(0x8229u);
  result = v5(v6);
  if ( (_DWORD)result )
  {
    result = sde_encoder_wait_for_event(*a1, 2u);
    if ( (_DWORD)result )
    {
      v7 = *(void (**)(void))(a1[53] + 8 * v4 + 440);
      if ( *((_DWORD *)v7 - 1) != 1550245701 )
        __break(0x8228u);
      v7();
      return printk(&unk_2386C0, "_sde_encoder_phys_wait_for_vsync_on_autorefresh_busy");
    }
  }
  return result;
}
