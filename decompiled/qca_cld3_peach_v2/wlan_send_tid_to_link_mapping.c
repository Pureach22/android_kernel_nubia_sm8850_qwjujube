__int64 __fastcall wlan_send_tid_to_link_mapping(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 (__fastcall *v23)(__int64, __int64); // x8
  __int64 result; // x0
  unsigned int v25; // w19
  const char *v26; // x2
  const char *v27; // x2

  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v27 = "%s: null psoc";
LABEL_11:
    qdf_trace_msg(0x99u, 2u, v27, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_send_tid_to_link_mapping");
    return 29;
  }
  v12 = *(_QWORD *)(v11 + 2128);
  if ( v12 == -1984 )
  {
    v27 = "%s: tx_ops is null!";
    goto LABEL_11;
  }
  if ( !*(_QWORD *)(v12 + 2024) )
  {
    v27 = "%s: send_tid_to_link_mapping is null";
    goto LABEL_11;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
  {
    v25 = 16;
    v26 = "%s: vdev is not MLO vdev";
    goto LABEL_16;
  }
  v23 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 2024);
  if ( *((_DWORD *)v23 - 1) != 1533165245 )
    __break(0x8228u);
  result = v23(a1, a2);
  if ( (_DWORD)result )
  {
    v25 = result;
    v26 = "%s: Failed to send T2LM command to FW";
LABEL_16:
    qdf_trace_msg(0x99u, 2u, v26, v15, v16, v17, v18, v19, v20, v21, v22, "wlan_send_t2lm_info");
    return v25;
  }
  return result;
}
