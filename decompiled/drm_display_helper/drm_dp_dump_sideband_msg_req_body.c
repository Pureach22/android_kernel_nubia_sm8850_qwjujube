__int64 __fastcall drm_dp_dump_sideband_msg_req_body(unsigned __int8 *a1, int a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  const char *v8; // x4
  unsigned __int64 v9; // x9
  char *v10; // x8
  unsigned int v11; // w8

  v3 = *a1;
  if ( (_DWORD)v3 == 1 )
    return drm_printf(a3, "%.*stype=%s\n", a2, "\t\t\t\t\tX", "LINK_ADDRESS");
  v8 = "unknown";
  if ( (unsigned int)v3 <= 0x38 )
  {
    v9 = 0xFEFFC0FFE0FFF8uLL >> v3;
    v10 = drm_dp_mst_req_type_str_req_type_str[v3];
    if ( (v9 & 1) == 0 )
      v8 = v10;
  }
  drm_printf(a3, "%.*stype=%s contents:\n", a2, "\t\t\t\t\tX", v8);
  v11 = *a1;
  if ( v11 <= 0x21 )
  {
    if ( *a1 > 0x11u )
    {
      if ( v11 != 18 )
      {
        if ( v11 == 32 )
          return drm_printf(
                   a3,
                   "%.*sport=%d dpcd_addr=%05x len=%d\n",
                   a2 + 1,
                   "\t\t\t\t\tX",
                   a1[8],
                   *((_DWORD *)a1 + 3),
                   a1[16]);
        if ( v11 == 33 )
          return drm_printf(
                   a3,
                   "%.*sport=%d addr=%05x len=%d: %*ph\n",
                   (unsigned int)(a2 + 1),
                   "\t\t\t\t\tX",
                   a1[8],
                   *((unsigned int *)a1 + 3),
                   a1[16],
                   a1[16],
                   *((_QWORD *)a1 + 3));
        return drm_printf(a3, "%.*s???\n", a2 + 1, "\t\t\t\t\tX");
      }
      return drm_printf(a3, "%.*sport=%d vcpi=%d\n", a2 + 1, "\t\t\t\t\tX", a1[8], a1[9]);
    }
    if ( v11 != 16 )
    {
      if ( v11 == 17 )
        return drm_printf(
                 a3,
                 "%.*sport=%d vcpi=%d pbn=%d sdp_streams=%d %*ph\n",
                 a2 + 1,
                 "\t\t\t\t\tX",
                 a1[8],
                 a1[10],
                 *((unsigned __int16 *)a1 + 6),
                 a1[9],
                 a1[9],
                 a1 + 14);
      return drm_printf(a3, "%.*s???\n", a2 + 1, "\t\t\t\t\tX");
    }
    return drm_printf(a3, "%.*sport=%d\n", a2 + 1, "\t\t\t\t\tX", a1[8]);
  }
  if ( *a1 > 0x23u )
  {
    if ( v11 - 36 < 2 )
      return drm_printf(a3, "%.*sport=%d\n", a2 + 1, "\t\t\t\t\tX", a1[8]);
    if ( v11 == 56 )
      return drm_printf(
               a3,
               "%.*sstream_id=%u client_id=%*ph stream_event=%x valid_event=%d stream_behavior=%x valid_behavior=%d",
               a2 + 1,
               "\t\t\t\t\tX",
               a1[8],
               7,
               a1 + 9,
               a1[16],
               a1[17],
               a1[18],
               a1[19]);
    return drm_printf(a3, "%.*s???\n", a2 + 1, "\t\t\t\t\tX");
  }
  if ( v11 == 34 )
  {
    result = drm_printf(
               a3,
               "%.*sport=%d num_tx=%d id=%d size=%d:\n",
               a2 + 1,
               "\t\t\t\t\tX",
               a1[9],
               a1[8],
               a1[112],
               a1[113]);
    if ( a1[8] )
    {
      result = drm_printf(
                 a3,
                 "%.*s%d: id=%03d size=%03d no_stop_bit=%d tx_delay=%03d: %*ph\n",
                 a2 + 2,
                 "\t\t\t\t\tX",
                 0,
                 a1[16],
                 a1[17],
                 a1[32],
                 a1[33],
                 a1[17],
                 *((const void **)a1 + 3));
      if ( a1[8] > 1u )
      {
        result = drm_printf(
                   a3,
                   "%.*s%d: id=%03d size=%03d no_stop_bit=%d tx_delay=%03d: %*ph\n",
                   a2 + 2,
                   "\t\t\t\t\tX",
                   1,
                   a1[40],
                   a1[41],
                   a1[56],
                   a1[57],
                   a1[41],
                   *((const void **)a1 + 6));
        if ( a1[8] >= 3u )
        {
          result = drm_printf(
                     a3,
                     "%.*s%d: id=%03d size=%03d no_stop_bit=%d tx_delay=%03d: %*ph\n",
                     a2 + 2,
                     "\t\t\t\t\tX",
                     2,
                     a1[64],
                     a1[65],
                     a1[80],
                     a1[81],
                     a1[65],
                     *((const void **)a1 + 9));
          if ( a1[8] >= 4u )
          {
            result = drm_printf(
                       a3,
                       "%.*s%d: id=%03d size=%03d no_stop_bit=%d tx_delay=%03d: %*ph\n",
                       a2 + 2,
                       "\t\t\t\t\tX",
                       3,
                       a1[88],
                       a1[89],
                       a1[104],
                       a1[105],
                       a1[89],
                       *((const void **)a1 + 12));
            if ( a1[8] >= 5u )
            {
              result = drm_printf(
                         a3,
                         "%.*s%d: id=%03d size=%03d no_stop_bit=%d tx_delay=%03d: %*ph\n",
                         a2 + 2,
                         "\t\t\t\t\tX",
                         4,
                         a1[112],
                         a1[113],
                         a1[128],
                         a1[129],
                         a1[113],
                         *((const void **)a1 + 15));
              if ( a1[8] > 5u )
              {
                __break(0x5512u);
                return drm_printf(a3, "%.*sport=%d vcpi=%d\n", a2 + 1, "\t\t\t\t\tX", a1[8], a1[9]);
              }
            }
          }
        }
      }
    }
  }
  else
  {
    if ( v11 != 35 )
      return drm_printf(a3, "%.*s???\n", a2 + 1, "\t\t\t\t\tX");
    return drm_printf(
             a3,
             "%.*sport=%d id=%d size=%d: %*ph\n",
             (unsigned int)(a2 + 1),
             "\t\t\t\t\tX",
             a1[8],
             a1[9],
             a1[10],
             a1[10],
             *((_QWORD *)a1 + 2));
  }
  return result;
}
