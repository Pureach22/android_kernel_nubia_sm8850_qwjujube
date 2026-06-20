__int64 __fastcall csr_is_mcc_channel(_QWORD *a1, unsigned int a2)
{
  __int64 v4; // x23
  __int64 v5; // x21
  unsigned int operation_chan_freq_vdev_id; // w22
  int v7; // w24
  __int64 v8; // x25
  int v9; // w8
  int is_same_band_freqs; // w0

  if ( !a2 )
    return 0;
  v4 = 0;
  v5 = 0;
  operation_chan_freq_vdev_id = 0;
  v7 = policy_mgr_is_hw_dbs_capable(a1[2703]) ^ 1;
  do
  {
    if ( !a1 )
      goto LABEL_3;
    v8 = a1[2162];
    if ( !v8 || *(_BYTE *)(v8 + v4 + 1) != 1 )
      goto LABEL_3;
    v9 = wlan_get_opmode_from_vdev_id(a1[2704], v5) & 0xFFFFFFFD;
    if ( v9 == 1 )
    {
      if ( *(_DWORD *)(v8 + v4 + 4) )
        goto LABEL_12;
    }
    else if ( !v9 && cm_is_vdevid_connected(a1[2704], v5) )
    {
LABEL_12:
      operation_chan_freq_vdev_id = wlan_get_operation_chan_freq_vdev_id(a1[2704], v5);
    }
    if ( operation_chan_freq_vdev_id )
    {
      is_same_band_freqs = wlan_reg_is_same_band_freqs(a2, operation_chan_freq_vdev_id);
      if ( operation_chan_freq_vdev_id != a2 && ((v7 | is_same_band_freqs) & 1) != 0 )
        return 1;
    }
LABEL_3:
    ++v5;
    v4 += 96;
  }
  while ( v5 != 6 );
  return 0;
}
