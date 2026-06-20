__int64 __fastcall mac_close(_QWORD *a1)
{
  unsigned int *v2; // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0

  if ( !a1 )
    return 16;
  pe_close((__int64)a1);
  v11 = a1[2695];
  if ( v11 )
  {
    wlan_objmgr_pdev_release_ref(v11, 7u, v2, v3, v4, v5, v6, v7, v8, v9, v10);
    a1[2695] = 0;
  }
  wlan_objmgr_psoc_release_ref(a1[2694], 7u, v3, v4, v5, v6, v7, v8, v9, v10);
  a1[1] = 0;
  a1[2694] = 0;
  qdf_mem_set(a1, 0x55F0u, 0);
  return 0;
}
