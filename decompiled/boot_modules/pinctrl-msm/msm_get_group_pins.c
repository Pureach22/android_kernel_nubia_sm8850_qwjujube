__int64 __fastcall msm_get_group_pins(__int64 a1, unsigned int a2, _QWORD *a3, _DWORD *a4)
{
  __int64 drvdata; // x0
  __int64 v8; // x8

  drvdata = pinctrl_dev_get_drvdata();
  *a3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(drvdata + 968) + 32LL) + 112LL * a2 + 32);
  v8 = *(_QWORD *)(drvdata + 968);
  *a4 = *(_QWORD *)(*(_QWORD *)(v8 + 32) + 112LL * a2 + 40);
  return 0;
}
