__int64 __fastcall mhi_controller_setup_timesync(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x22
  _QWORD *v8; // x0
  unsigned int v9; // w8

  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  v8 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_noprof, &print_fmt_mhi_intvec_states[1192], 176);
  if ( v8 )
  {
    v9 = 0;
    *v8 = a2;
    v8[1] = a3;
    v8[2] = a4;
    *(_QWORD *)(v7 + 104) = v8;
  }
  else
  {
    return (unsigned int)-12;
  }
  return v9;
}
