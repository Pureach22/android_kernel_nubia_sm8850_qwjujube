__int64 __fastcall msm_pinmux_request_gpio(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x8
  __int64 v6; // x9

  v5 = *(_QWORD *)(pinctrl_dev_get_drvdata() + 968);
  v6 = *(_QWORD *)(v5 + 32) + 112LL * a3;
  if ( *(_DWORD *)(v6 + 56) )
    return msm_pinmux_set_mux(a1, *(_DWORD *)(*(_QWORD *)(v6 + 48) + 4LL * *(unsigned int *)(v5 + 108)), a3);
  else
    return 0;
}
