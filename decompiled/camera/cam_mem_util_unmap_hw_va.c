__int64 __usercall cam_mem_util_unmap_hw_va@<X0>(
        int a1@<W0>,
        unsigned int a2@<W1>,
        int a3@<W2>,
        char a4@<W3>,
        int a5@<W8>)
{
  char *v6; // x27
  int v7; // w26
  unsigned int v8; // w9
  int v9; // w28
  __int64 v11; // x24
  __int64 v12; // x19
  int v13; // w8
  __int64 v14; // x22
  __int64 v15; // x25
  __int64 result; // x0
  __int64 v17; // x19
  unsigned int *v18; // x23
  unsigned int v19; // w19
  int v20; // w9
  const char *v21; // x6
  unsigned int v22; // w19
  __int64 v23; // [xsp+38h] [xbp-18h]
  unsigned int v26; // [xsp+4Ch] [xbp-4h]

  if ( a1 > 0 )
  {
    if ( (unsigned int)a1 > 0x800 || a1 == 2048 )
    {
      __break(1u);
    }
    else
    {
      v6 = (char *)&tbl + 296 * (unsigned int)a1;
      a5 = debug_mdl;
      v7 = *((_DWORD *)v6 + 42);
      v8 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 22);
      if ( v7 )
      {
        v9 = *((_DWORD *)v6 + 38);
        v11 = *((_QWORD *)v6 + 8);
        v12 = *((_QWORD *)v6 + 16);
        v26 = *((_DWORD *)v6 + 30);
        if ( v8 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x400000,
            4,
            "cam_mem_util_unmap_hw_va",
            2587,
            "unmap_hw_va : idx=%d, fd=%x, i_ino=%lu flags=0x%x, num_hdls=%d, client=%d",
            a1,
            v26,
            v12,
            v9,
            v7,
            a3);
        v13 = dword_391BA8;
        if ( dword_391BA8 >= 1 )
        {
          v14 = 0;
          v15 = 0;
          result = 0;
          v23 = v12;
          while ( 1 )
          {
            v17 = *((_QWORD *)v6 + 22);
            v18 = (unsigned int *)(v17 + v14);
            if ( *(_BYTE *)(v17 + v14 + 33) == 1 )
            {
              if ( (v9 & 0x20) != 0 )
              {
                result = cam_smmu_unmap_stage2_iova(*v18, v26, v11, a4 & 1);
                if ( (result & 0x80000000) != 0 )
                  goto LABEL_27;
              }
              else if ( a3 == 1 )
              {
                result = cam_smmu_unmap_kernel_iova(*v18, *((_QWORD *)v6 + 8), a2);
                if ( (result & 0x80000000) != 0 )
                  goto LABEL_27;
              }
              else
              {
                if ( a3 )
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x400000,
                    1,
                    "cam_mem_util_unmap_hw_va",
                    2605,
                    "invalid caller for unmapping : %d",
                    a3);
                  return 4294967274LL;
                }
                result = cam_smmu_unmap_user_iova(*v18, v26, v11, a2, a4 & 1);
                if ( (result & 0x80000000) != 0 )
                {
LABEL_27:
                  v20 = *(_DWORD *)(v17 + v14);
                  if ( (v9 & 0x20) != 0 )
                    v21 = "secure";
                  else
                    v21 = "non-secure";
                  v22 = result;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x400000,
                    1,
                    "cam_mem_util_unmap_hw_va",
                    2614,
                    "Failed in %s unmap, i=%d, fd=%d, i_ino=%lu, mmu_hdl=%d, rc=%d",
                    v21,
                    v15,
                    v26,
                    v23,
                    v20,
                    result);
                  return v22;
                }
              }
              if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
              {
                v19 = result;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x400000,
                  4,
                  "cam_mem_util_unmap_hw_va",
                  2621,
                  "i: %d unmap_hw_va : idx=%d, fd=%x, i_ino=%lu flags=0x%x, num_hdls=%d, client=%d hdl: %d",
                  v15,
                  a1,
                  v26,
                  v23,
                  v9,
                  *((_DWORD *)v6 + 42),
                  a3,
                  *v18);
                result = v19;
                if ( !--v7 )
                  return result;
              }
              else if ( !--v7 )
              {
                return result;
              }
              v13 = dword_391BA8;
            }
            ++v15;
            v14 += 40;
            if ( v15 >= v13 )
              return result;
          }
        }
        return 0;
      }
      if ( !v8 )
        return 0;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      *(_QWORD *)&a5 & 0x400000LL,
      4,
      "cam_mem_util_unmap_hw_va",
      2581,
      "No valid handles to unmap");
    return 0;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x400000,
    1,
    "cam_mem_util_unmap_hw_va",
    2570,
    "Incorrect index");
  return 4294967274LL;
}
