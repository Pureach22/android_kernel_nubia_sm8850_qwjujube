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
  __int64 v10; // x24
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
  _DWORD *v23; // x22
  unsigned int v24; // w20
  const char *v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int per_link_speed; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  __int64 v44; // x9
  __int64 v45; // x10

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
    if ( (v22 | 2) != 2 )
    {
      v25 = qdf_opmode_str(v22);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Link Speed is not allowed in Device mode %s(%d)",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlan_hdd_get_link_speed",
        v25,
        *(unsigned int *)(v10 + 40));
      return 4294966772LL;
    }
    if ( (wlan_hdd_is_mlo_connection(a1, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
    {
      if ( v10 )
      {
        if ( (*(_QWORD *)(v10 + 1640) & 1) != 0 )
        {
          v23 = (_DWORD *)(v10 + 52840);
        }
        else
        {
          v23 = (_DWORD *)(v10 + 58928);
          if ( v10 == -58928 || (*(_QWORD *)(v10 + 1640) & 2) == 0 )
          {
            v24 = 0;
            v23 = (_DWORD *)(v10 + 65016);
            if ( v10 == -65016 || (*(_QWORD *)(v10 + 1640) & 4) == 0 )
              goto LABEL_14;
          }
        }
        v24 = 0;
        do
        {
          per_link_speed = wlan_hdd_get_per_link_speed(v23);
          v24 += per_link_speed;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: per_speed=%d, link_speed=%d",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "wlan_hdd_get_mlo_link_speed",
            per_link_speed,
            v24);
          if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v23 - *v23 - 52840) >> 3) + 1) > 2u )
            break;
          v43 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v23 - *v23 - 52840) >> 3) + 1);
          v23 = nullptr;
          v44 = v10 + 52840 + 6088LL * (unsigned int)v43;
          do
          {
            if ( v23 )
              break;
            v45 = *(_QWORD *)(v10 + 1640) >> v43++;
            v23 = (_DWORD *)((v45 << 63 >> 63) & v44);
            v44 += 6088;
          }
          while ( v43 != 3 );
        }
        while ( v23 );
        goto LABEL_14;
      }
      v24 = 0;
    }
    else
    {
      v24 = wlan_hdd_get_per_link_speed(a1);
    }
LABEL_14:
    result = 0;
    *a2 = v24 / 0x1F4;
  }
  return result;
}
