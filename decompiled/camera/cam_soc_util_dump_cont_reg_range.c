__int64 __fastcall cam_soc_util_dump_cont_reg_range(
        _DWORD *a1,
        _DWORD *a2,
        unsigned int a3,
        unsigned int *a4,
        _BYTE *a5)
{
  __int64 v8; // x7
  __int64 v9; // x6
  __int64 v10; // x8
  __int64 result; // x0
  unsigned int v12; // w28
  int v13; // w26
  unsigned int v14; // w27
  unsigned int v15; // w24
  unsigned int *v16; // x22
  __int64 v17; // x4
  const char *v18; // x5
  unsigned int v19; // w6
  unsigned int v20; // w8
  unsigned int v21; // w9
  _QWORD *v22; // [xsp+10h] [xbp-10h]

  if ( a5 && a2 && a1 && a4 )
  {
    v8 = (unsigned int)a2[1];
    if ( (_DWORD)v8 )
    {
      v9 = a4[2];
      if ( (v8 & 0x80000000) != 0 || (v10 = 2 * v8, (4294967279LL - v9) / (unsigned __int64)(2 * v8) <= 3) )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_dump_cont_reg_range",
          4884,
          "Integer Overflow bytes_written: [%u] num_values: [%u]",
          v9);
        return 4294967221LL;
      }
    }
    else
    {
      v9 = a4[2];
      v10 = 0;
    }
    if ( a5 - (_BYTE *)a4 <= (unsigned __int64)(v9 + 4 * v10 + 12) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_dump_cont_reg_range",
        4896,
        "Insufficient space in out buffer num_values: [%d] cmd_buf_end: %pK dump_out_buf: %pK",
        v8,
        a5,
        a4);
      return 4294967274LL;
    }
    else
    {
      if ( a3 >= 8 )
      {
        __break(0x5512u);
        JUMPOUT(0x119B10);
      }
      if ( (_DWORD)v8 )
      {
        v12 = (unsigned int)v9 >> 2;
        v13 = 0;
        v14 = 0;
        v15 = a1[6 * a3 + 76];
        v16 = a4 + 3;
        v22 = &a1[6 * a3 + 72];
        while ( 1 )
        {
          v19 = v13 + *a2;
          if ( (*a2 & 3) != 0 )
          {
            v17 = 4848;
            v18 = "Offset: 0x%X of %s is not memory aligned";
          }
          else
          {
            if ( v19 <= v15 )
            {
              v16[v12] = v19;
              if ( a1[120] > a3 && *v22 )
              {
                v20 = cam_io_r(*v22 + (unsigned int)(v13 + *a2));
              }
              else
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  0x20000,
                  1,
                  "cam_soc_util_r",
                  853,
                  "No valid mapped starting address found");
                v20 = 0;
              }
              v21 = a4[2];
              result = 0;
              v16[v12 + 1] = v20;
              v12 += 2;
              a4[2] = v21 + 8;
              goto LABEL_17;
            }
            v17 = 4853;
            v18 = "Reg offset: 0x%X of %s out of range, reg_map size: 0x%X";
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x20000,
            1,
            "cam_soc_util_reg_addr_validation",
            v17,
            v18);
          result = 4294967274LL;
LABEL_17:
          ++v14;
          v13 += 4;
          if ( v14 >= a2[1] )
            return result;
        }
      }
      return 0;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_dump_cont_reg_range",
      4872,
      "Invalid input args soc_info: %pK, dump_out_buffer: %pK reg_read: %pK cmd_buf_end: %pK",
      a1,
      a4,
      a2,
      a5);
    return 4294967274LL;
  }
}
