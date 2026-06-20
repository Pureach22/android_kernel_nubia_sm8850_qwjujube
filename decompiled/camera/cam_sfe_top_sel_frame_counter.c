__int64 __fastcall cam_sfe_top_sel_frame_counter(int a1, _DWORD *a2, char a3, _QWORD *a4)
{
  __int64 v7; // x21
  unsigned int v9; // w0
  __int64 v10; // x9
  unsigned int v11; // w21
  __int64 result; // x0
  __int64 v13; // x6
  const char *v14; // x5
  __int64 v15; // x4

  if ( (a3 & 1) != 0 )
  {
    v7 = a4[3];
    v9 = cam_io_r(*a4 + *(unsigned int *)(v7 + 40));
    v10 = *(unsigned int *)(v7 + 44);
    v11 = v9;
    result = cam_io_r(*a4 + v10);
    if ( a1 > 2 )
      goto LABEL_3;
  }
  else
  {
    v11 = 0;
    result = 0;
    if ( a1 > 2 )
    {
LABEL_3:
      switch ( a1 )
      {
        case 3:
          *a2 |= 0x80u;
          if ( (a3 & 1) == 0 )
            return result;
          v14 = "RDI2 frame_cnt 0x%x";
          v13 = (unsigned __int8)result;
          v15 = 1774;
          return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                   3,
                   0x40000000,
                   3,
                   "cam_sfe_top_sel_frame_counter",
                   v15,
                   v14,
                   v13);
        case 4:
          *a2 |= 0x100u;
          if ( (a3 & 1) == 0 )
            return result;
          v13 = BYTE2(result);
          v14 = "RDI3 frame_cnt 0x%x";
          v15 = 1780;
          return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                   3,
                   0x40000000,
                   3,
                   "cam_sfe_top_sel_frame_counter",
                   v15,
                   v14,
                   v13);
        case 5:
          *a2 |= 0x200u;
          if ( (a3 & 1) != 0 )
          {
            v13 = BYTE3(result);
            v14 = "RDI4 frame_cnt 0x%x";
            v15 = 1786;
            return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
                     3,
                     0x40000000,
                     3,
                     "cam_sfe_top_sel_frame_counter",
                     v15,
                     v14,
                     v13);
          }
          break;
      }
      return result;
    }
  }
  switch ( a1 )
  {
    case 0:
      *a2 |= 0x10u;
      if ( (a3 & 1) == 0 )
        return result;
      v14 = "IPP frame_cnt 0x%x";
      v13 = (unsigned __int8)v11;
      v15 = 1756;
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
               3,
               0x40000000,
               3,
               "cam_sfe_top_sel_frame_counter",
               v15,
               v14,
               v13);
    case 1:
      *a2 |= 0x20u;
      if ( (a3 & 1) == 0 )
        return result;
      v13 = BYTE2(v11);
      v14 = "RDI0 frame_cnt 0x%x";
      v15 = 1762;
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
               3,
               0x40000000,
               3,
               "cam_sfe_top_sel_frame_counter",
               v15,
               v14,
               v13);
    case 2:
      *a2 |= 0x40u;
      if ( (a3 & 1) != 0 )
      {
        v13 = HIBYTE(v11);
        v14 = "RDI1 frame_cnt 0x%x";
        v15 = 1768;
        return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
                 3,
                 0x40000000,
                 3,
                 "cam_sfe_top_sel_frame_counter",
                 v15,
                 v14,
                 v13);
      }
      break;
  }
  return result;
}
