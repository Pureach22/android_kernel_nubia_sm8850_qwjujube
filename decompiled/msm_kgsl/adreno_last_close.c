__int64 __fastcall adreno_last_close(_QWORD *a1)
{
  __int64 v2; // x21
  __int64 (__fastcall *v3)(_QWORD); // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1[1783] + 40LL) + 160LL);
  if ( (unsigned int)((__int64 (*)(void))kgsl_active_count_wait)() )
  {
    dev_err(*a1, "Waiting for the active count to become 0\n");
    while ( (unsigned int)kgsl_active_count_wait(a1, 0, 250) )
      dev_err(*a1, "Still waiting for the active count\n");
  }
  v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 8);
  if ( *((_DWORD *)v3 - 1) != -83892780 )
    __break(0x8228u);
  return v3(a1);
}
