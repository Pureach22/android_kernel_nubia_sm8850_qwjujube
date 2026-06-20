__int64 __fastcall mlme_vdev_subst_mlo_sync_wait_event(
        __int64 a1,
        unsigned __int16 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v14; // w8
  __int64 *v15; // x21
  unsigned int v16; // w1
  __int64 v17; // x21
  char is_mlo_vdev; // w8
  char v19; // w8

  v14 = 0;
  if ( a2 <= 0x16u )
  {
    if ( a2 == 7 )
    {
      if ( *(_DWORD *)(*(_QWORD *)(a1 + 520) + 16LL) == 1 )
      {
        v17 = a1;
        is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a1 + 520), a5, a6, a7, a8, a9, a10, a11, a12);
        a1 = v17;
        if ( (is_mlo_vdev & 1) != 0 )
        {
          v19 = mlo_ap_link_sync_wait_notify(*(_QWORD *)(v17 + 520));
          a1 = v17;
          if ( (v19 & 1) == 0 )
            return 1;
        }
      }
      v15 = (__int64 *)(a1 + 504);
      v16 = 31;
LABEL_15:
      wlan_sm_dispatch(*v15, v16, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
      return 1;
    }
    if ( a2 == 12 )
    {
      v15 = (__int64 *)(a1 + 504);
      wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 4u, a5, a6, a7, a8, a9, a10, a11, a12);
      v16 = 12;
      goto LABEL_15;
    }
    if ( a2 != 21 )
      return v14;
LABEL_7:
    v15 = (__int64 *)(a1 + 504);
    wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 1u, a5, a6, a7, a8, a9, a10, a11, a12);
    v16 = 2;
    goto LABEL_15;
  }
  if ( (unsigned int)a2 - 23 < 2 )
    goto LABEL_7;
  if ( a2 == 31 )
  {
    v15 = (__int64 *)(a1 + 504);
    wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 0x13u, a5, a6, a7, a8, a9, a10, a11, a12);
    v16 = 31;
    goto LABEL_15;
  }
  return v14;
}
