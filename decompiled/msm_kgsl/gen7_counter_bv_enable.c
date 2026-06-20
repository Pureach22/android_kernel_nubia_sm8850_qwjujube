__int64 __fastcall gen7_counter_bv_enable(__int64 a1, _QWORD *a2, unsigned int a3)
{
  __int64 v4; // x19
  unsigned int v6; // w20

  v4 = *a2 + 48LL * a3;
  gen7_host_aperture_set(a1, 2);
  v6 = gen7_perfcounter_update(a1, (int *)v4, 1, 0x2000, a2[3]);
  gen7_host_aperture_set(a1, 0);
  if ( !v6 )
    *(_QWORD *)(v4 + 32) = 0;
  return v6;
}
