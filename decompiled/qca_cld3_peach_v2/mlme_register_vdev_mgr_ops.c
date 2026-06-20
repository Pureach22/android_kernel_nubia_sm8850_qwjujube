__int64 __fastcall mlme_register_vdev_mgr_ops(__int64 a1)
{
  int v1; // w8
  unsigned int v2; // w9
  unsigned __int64 v3; // t2
  bool v4; // cc
  int v5; // w9
  void *v7; // x8

  v1 = *(_DWORD *)(*(_QWORD *)(a1 + 520) + 16LL);
  HIDWORD(v3) = v1 - 1;
  LODWORD(v3) = v1 - 1;
  v2 = v3 >> 1;
  v4 = v2 > 5;
  v5 = (1 << v2) & 0x27;
  if ( v4 || v5 == 0 )
  {
    if ( v1 == 6 )
      v7 = &mon_mlme_ops;
    else
      v7 = &sta_mlme_ops;
  }
  else
  {
    v7 = &ap_mlme_ops;
  }
  *(_QWORD *)(a1 + 528) = v7;
  return 0;
}
