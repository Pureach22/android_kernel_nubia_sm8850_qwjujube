__int64 __fastcall gen8_counter_bv_enable(__int64 a1, _QWORD *a2, unsigned int a3)
{
  __int64 v4; // x19
  unsigned int v6; // w20

  v4 = *a2 + 48LL * a3;
  gen8_host_aperture_set(a1, 2, 0, 0);
  v6 = gen8_perfcounter_update(a1, (int *)v4, 1, 0x2000, a2[3]);
  gen8_host_aperture_set(a1, 0, 0, 0);
  if ( !v6 )
    *(_QWORD *)(v4 + 32) = 0;
  return v6;
}
