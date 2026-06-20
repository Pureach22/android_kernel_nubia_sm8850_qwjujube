__int64 __fastcall csr_roam_call_callback(
        _QWORD *a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v14; // x8
  _DWORD *v19; // x8
  __int64 v20; // x0

  if ( a1 && a2 <= 5 && (v14 = a1[2153]) != 0 && (*(_BYTE *)(v14 + 96LL * a2 + 1) & 1) != 0 )
  {
    wlan_get_operation_chan_freq_vdev_id(a1[2695], a2);
    v19 = (_DWORD *)a1[2746];
    if ( v19 )
    {
      v20 = a1[2694];
      if ( *(v19 - 1) != 1469140685 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD, _QWORD))v19)(v20, a2, a3, a4, a5);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Session ID: %d is not valid",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "csr_roam_call_callback",
      a2);
    return 16;
  }
}
