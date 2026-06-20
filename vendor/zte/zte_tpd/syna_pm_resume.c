__int64 __fastcall syna_pm_resume(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19

  v3 = *(_QWORD *)(a1 + 152);
  printk(unk_36ADB, "syna_pm_resume", a3);
  *(_BYTE *)(v3 + 1400) = 0;
  complete(v3 + 1368);
  return 0;
}
