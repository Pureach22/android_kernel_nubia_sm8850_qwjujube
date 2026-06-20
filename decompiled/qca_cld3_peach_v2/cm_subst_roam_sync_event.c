__int64 __fastcall cm_subst_roam_sync_event(
        __int64 *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  char v13; // w0
  __int64 *v14; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  unsigned int v26; // w1
  unsigned int v27; // w2
  __int64 v28; // x3
  __int64 *v30; // x22
  __int64 *v35; // x19

  v13 = 0;
  if ( (unsigned __int16)a2 <= 0x11u )
  {
    if ( !(_WORD)a2 || (unsigned __int16)a2 == 13 || (unsigned __int16)a2 == 15 )
      v13 = cm_handle_connect_disconnect_in_roam(a1, a2, a3, a4);
  }
  else if ( (unsigned __int16)a2 > 0x1Eu )
  {
    if ( (unsigned __int16)a2 == 31 )
    {
LABEL_13:
      v30 = a1;
      wlan_sm_transition_to(a1[9], 2u, a5, a6, a7, a8, a9, a10, a11, a12);
      v25 = v30[9];
      v26 = a2;
      v27 = a3;
      v28 = (__int64)a4;
      goto LABEL_14;
    }
    if ( (unsigned __int16)a2 == 32 )
    {
      v14 = a1;
      wlan_sm_transition_to(a1[9], 2u, a5, a6, a7, a8, a9, a10, a11, a12);
      v25 = v14[9];
      v26 = 32;
      v27 = a3;
      v28 = (__int64)a4;
LABEL_14:
      wlan_sm_dispatch(v25, v26, v27, v28, v17, v18, v19, v20, v21, v22, v23, v24);
      v13 = 1;
    }
  }
  else
  {
    if ( (unsigned __int16)a2 != 18 )
    {
      if ( (unsigned __int16)a2 != 20 )
        return v13 & 1;
      goto LABEL_13;
    }
    v35 = a1;
    if ( (unsigned int)mlo_cm_roam_sync_cb(*a1, a4, (unsigned __int16)a3) )
      v13 = 0;
    else
      v13 = (unsigned int)cm_fw_send_vdev_roam_event(v35, a3, a4) == 0;
  }
  return v13 & 1;
}
