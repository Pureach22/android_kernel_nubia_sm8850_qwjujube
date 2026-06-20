__int64 __fastcall mhi_controller_set_sfr_support(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x0

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  v4 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, &print_fmt_mhi_intvec_states[1192], 72);
  v5 = v4;
  if ( !v4 )
    return 4294967284LL;
  *(_QWORD *)(v4 + 16) = a2;
  v6 = _kmalloc_noprof(a2, 3520);
  *(_QWORD *)(v5 + 24) = v6;
  if ( !v6 )
    return 4294967284LL;
  *(_QWORD *)(v3 + 96) = v5;
  return 0;
}
