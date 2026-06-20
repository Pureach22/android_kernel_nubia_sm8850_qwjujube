void __fastcall lpm_idle_exit(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  _BYTE *v4; // x20
  _BYTE *v5; // x19

  v3 = *(unsigned int *)(a3 + 4);
  if ( (unsigned int)v3 >= 0x20 )
  {
    __break(0x5512u);
    JUMPOUT(0xBFFC);
  }
  if ( *(_DWORD *)&lpm_cpu_data[_per_cpu_offset[v3] + 4] )
  {
    v4 = &lpm_cpu_data[_ReadStatusReg(TPIDR_EL1)];
    if ( (hrtimer_active(v4 + 80) & 1) != 0 && _hrtimer_get_remaining(v4 + 80, 0) >= 1000 )
      hrtimer_try_to_cancel(v4 + 80);
    v5 = &lpm_cpu_data[_ReadStatusReg(TPIDR_EL1)];
    if ( *((_QWORD *)v5 + 37) )
    {
      *((_QWORD *)v5 + 37) = 0;
      if ( _hrtimer_get_remaining(v5 + 144, 0) >= 1000 )
        hrtimer_try_to_cancel(v5 + 144);
    }
  }
}
