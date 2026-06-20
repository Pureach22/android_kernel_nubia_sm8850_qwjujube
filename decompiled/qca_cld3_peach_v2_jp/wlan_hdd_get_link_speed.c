__int64 __fastcall wlan_hdd_get_link_speed(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w0
  unsigned int per_link_speed; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  v10 = *(_QWORD *)a1;
  result = _wlan_hdd_validate_context(
             *(_QWORD *)(*(_QWORD *)a1 + 24LL),
             (__int64)"wlan_hdd_get_link_speed",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10);
  if ( !(_DWORD)result )
  {
    v22 = *(_DWORD *)(v10 + 40);
    if ( (v22 | 2) == 2 )
    {
      if ( (wlan_hdd_is_mlo_connection(a1, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
      {
        per_link_speed = wlan_hdd_get_per_link_speed(*(_QWORD *)(v10 + 52824));
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Not support MLO, linkspeed = %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wlan_hdd_get_mlo_link_speed",
          per_link_speed);
      }
      else
      {
        per_link_speed = wlan_hdd_get_per_link_speed(a1);
      }
      *a2 = per_link_speed / 0x1F4;
      return 0;
    }
    else
    {
      v32 = qdf_opmode_str(v22);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Link Speed is not allowed in Device mode %s(%d)",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wlan_hdd_get_link_speed",
        v32,
        *(unsigned int *)(v10 + 40));
      return 4294966772LL;
    }
  }
  return result;
}
