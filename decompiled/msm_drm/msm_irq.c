__int64 __fastcall msm_irq(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 (*v3)(void); // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 56) + 8LL);
  if ( v2 )
  {
    v3 = *(__int64 (**)(void))(*(_QWORD *)v2 + 40LL);
    if ( *((_DWORD *)v3 - 1) != 282891845 )
      __break(0x8228u);
    return v3();
  }
  else
  {
    __break(0x800u);
    return msm_pm_suspend();
  }
}
