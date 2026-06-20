__int64 __fastcall cam_icp_process_presil_hangdump_info(__int64 a1, _DWORD *a2, unsigned int a3)
{
  int v4; // w7
  __int64 result; // x0
  __int64 v7; // x23
  _DWORD *v8; // x24
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x21
  int *v15; // x26
  _DWORD *v16; // x27
  int v17; // w8
  int v18; // w9
  int v19; // w10

  if ( a1 )
  {
    v4 = a2[1];
    if ( (unsigned int)(v4 - 11) > 0xFFFFFFF5 )
    {
      v7 = *(_QWORD *)(a1 + 29184);
      v8 = (_DWORD *)(v7 + 164LL * a3);
      v10 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              3,
              "cam_icp_process_presil_hangdump_info",
              6751,
              "%s Hangdump Mem Num Regions %d index %d  mem_regions 0x%pK",
              (const char *)(a1 + 29824),
              v4,
              a3,
              v8);
      LODWORD(v13) = a2[1];
      if ( (_DWORD)v13 )
      {
        v14 = 0;
        v15 = a2 + 2;
        v16 = (_DWORD *)(v7 + 164LL * a3 + 8);
        while ( v14 != 10 )
        {
          *(v16 - 1) = *v15;
          *v16 = v15[1];
          v17 = v15[2];
          v16[1] = v17;
          v18 = *v15;
          v19 = v15[1];
          v15 += 4;
          v10 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  256,
                  3,
                  "cam_icp_process_presil_hangdump_info",
                  6764,
                  "%s Hangdump Mem Region %u mem_handle 0x%08x iova 0x%08x len %u",
                  (const char *)(a1 + 29824),
                  v14,
                  v18,
                  v19,
                  v17);
          v13 = (unsigned int)a2[1];
          ++v14;
          v16 += 4;
          if ( v14 >= v13 )
            goto LABEL_9;
        }
        __break(0x5512u);
        return cam_icp_update_clk_util(v10, v11, v12);
      }
      else
      {
LABEL_9:
        result = 0;
        *v8 = v13;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_process_presil_hangdump_info",
        6745,
        "%s Invalid num hangdump mem regions %d ",
        a1 + 29824);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_process_presil_hangdump_info",
      6738,
      "Invalid hangdump info blob ctx %pK mem_region %pK",
      nullptr,
      a2);
    return 4294967274LL;
  }
  return result;
}
