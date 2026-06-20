__int64 __fastcall slumber(__int64 a1)
{
  int v1; // w8
  __int64 (*v3)(void); // x8
  unsigned int v4; // w0
  __int64 (__fastcall *v5)(_QWORD); // x8
  unsigned int v6; // w20
  void (__fastcall *v7)(_QWORD); // x8
  void (__fastcall *v8)(_QWORD); // x8
  void (__fastcall *v10)(_QWORD); // x8

  v1 = *(_DWORD *)(a1 + 11120);
  switch ( v1 )
  {
    case 32:
      kgsl_pwrctrl_disable(a1);
LABEL_20:
      kgsl_pwrctrl_set_state(a1, 128);
      return 0;
    case 16:
      complete_all(a1 + 8688);
      v10 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8752) + 192LL);
      if ( *((_DWORD *)v10 - 1) != 1058568764 )
        __break(0x8228u);
      v10(a1);
      goto LABEL_20;
    case 2:
      v3 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 8752) + 208LL);
      if ( *((_DWORD *)v3 - 1) != 33171575 )
        __break(0x8228u);
      if ( (v3() & 1) != 0 )
      {
        timer_delete_sync(a1 + 8792);
        kgsl_pwrctrl_irq(a1, 0);
        kgsl_pwrctrl_pwrlevel_change(a1);
        v4 = kgsl_pwrctrl_pwrrail(a1, 1);
        if ( !v4 )
        {
          kgsl_pwrctrl_clk(a1, 1, 2);
          kgsl_pwrctrl_axi(a1, 1);
          v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8752) + 200LL);
          if ( *((_DWORD *)v5 - 1) != -1357770785 )
            __break(0x8228u);
          v4 = v5(a1);
        }
        v6 = v4;
        v7 = **(void (__fastcall ***)(_QWORD))(a1 + 8752);
        if ( *((_DWORD *)v7 - 1) != 1058568764 )
          __break(0x8228u);
        v7(a1);
        v8 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8752) + 32LL);
        if ( *((_DWORD *)v8 - 1) != -1357770785 )
          __break(0x8228u);
        v8(a1);
        kgsl_pwrctrl_disable(a1);
        kgsl_pwrscale_sleep(a1);
        kgsl_pwrctrl_set_state(a1, 128);
        return v6;
      }
      else
      {
        *(_DWORD *)(a1 + 11124) = 0;
        return 4294967280LL;
      }
    default:
      *(_DWORD *)(a1 + 11124) = 0;
      return 0;
  }
}
