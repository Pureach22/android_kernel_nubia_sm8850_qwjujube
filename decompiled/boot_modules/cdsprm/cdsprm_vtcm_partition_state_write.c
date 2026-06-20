__int64 __fastcall cdsprm_vtcm_partition_state_write(__int64 a1, __int64 a2)
{
  cdsprm_compute_vtcm_set_partition_map(a2);
  if ( dword_99A0 == a2 )
    return 0;
  else
    return 4294967274LL;
}
