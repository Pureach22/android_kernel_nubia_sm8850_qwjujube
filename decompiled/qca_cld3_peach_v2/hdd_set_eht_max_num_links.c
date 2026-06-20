__int64 __fastcall hdd_set_eht_max_num_links(unsigned __int8 *a1, __int64 a2)
{
  if ( *(unsigned __int8 *)(a2 + 4) > 3u )
    return 4294967274LL;
  sme_set_mlo_max_links(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 16LL), a1[8]);
  return 0;
}
