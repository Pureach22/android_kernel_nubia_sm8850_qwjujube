__int64 __fastcall mlo_dev_mlpeer_list_init(__int64 a1)
{
  __int64 v2; // x8
  _QWORD *v3; // x10
  __int64 v4; // x8
  _QWORD *v5; // x8
  __int64 v6; // x8

  qdf_mutex_create(a1 + 1584);
  v2 = 0;
  do
  {
    v3 = (_QWORD *)(a1 + v2);
    v2 += 24;
    v3[6] = v3 + 6;
    v3[7] = v3 + 6;
    v3[8] = 0x68600000000LL;
  }
  while ( v2 != 1536 );
  v4 = *(_QWORD *)(a1 + 2232);
  if ( v4 )
  {
    *(_DWORD *)(v4 + 184) = 0;
    *(_QWORD *)(v4 + 192) = 0;
    v5 = *(_QWORD **)(a1 + 2232);
    v5[12] = v5 + 12;
    v5[13] = v5 + 12;
    v5[14] = 0x60600000000LL;
    *(_BYTE *)(*(_QWORD *)(a1 + 2232) + 120LL) = 0;
    v6 = *(_QWORD *)(a1 + 2232);
    *(_QWORD *)(v6 + 168) = wlan_mlo_ap_delete_assoc_list_entries;
    *(_QWORD *)(v6 + 176) = v6 + 96;
    init_timer_key(v6 + 128, _os_timer_shim_18, 0, 0, 0);
  }
  return 0;
}
