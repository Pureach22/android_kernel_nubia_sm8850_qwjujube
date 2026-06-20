void __fastcall lim_release_mlo_conn_idx(__int64 a1, unsigned int a2, __int64 a3, char a4)
{
  --*(_WORD *)(a3 + 7250);
  if ( (a4 & 1) != 0 )
  {
    if ( wlan_mlo_get_mlpeer_by_aid(*(_QWORD *)(*(_QWORD *)(a3 + 16) + 1360LL)) )
      mlo_free_aid(*(_QWORD *)(a3 + 16), a2);
  }
}
