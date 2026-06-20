__int64 __fastcall cam_ife_mgr_print_blob_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x26
  _QWORD *v9; // x28
  int v10; // w23
  int v11; // w24
  const char *v12; // x25
  const char *v13; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // t1
  const char *v17; // x27
  unsigned int v18; // w8

  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             3,
             "cam_ife_mgr_print_blob_info",
             7197,
             "ctx: %u req_id:%llu config_valid[BW VFE_CLK SFE_CLK]:[%d %d %d]",
             *(_DWORD *)(a1 + 56),
             a2,
             *(unsigned __int8 *)(a3 + 1800),
             *(unsigned __int8 *)(a3 + 1872),
             *(unsigned __int8 *)(a3 + 1944));
  if ( *(_BYTE *)(a3 + 1800) == 1 && *(_DWORD *)(a3 + 196) )
  {
    v8 = 0;
    v9 = (_QWORD *)(a3 + 232);
    while ( v8 != 40 )
    {
      v17 = "USAGE_INVALID";
      v18 = *((_DWORD *)v9 - 8) - 1;
      if ( v18 <= 5 )
        v17 = off_451530[v18];
      v10 = *(_DWORD *)(a1 + 56);
      v11 = *(_DWORD *)(a3 + 192);
      v12 = cam_cpas_axi_util_path_type_to_string(*((_DWORD *)v9 - 6));
      v13 = cam_cpas_axi_util_trans_type_to_string(*((_DWORD *)v9 - 7));
      v14 = *(v9 - 2);
      v15 = *(v9 - 1);
      v16 = *v9;
      v9 += 5;
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 0x2000000,
                 3,
                 "cam_ife_mgr_print_blob_info",
                 7214,
                 "ctx_idx: %u ISP_BLOB usage_type=%u [%s] [%s] [%s] [%llu] [%llu] [%llu]",
                 v10,
                 v11,
                 v17,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16);
      if ( ++v8 >= (unsigned __int64)*(unsigned int *)(a3 + 196) )
        goto LABEL_8;
    }
    __break(0x5512u);
    return cam_ife_mgr_apply_fcg_update(result, v6, v7);
  }
  else
  {
LABEL_8:
    if ( *(_BYTE *)(a3 + 1872) == 1 )
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 0x2000000,
                 3,
                 "cam_ife_mgr_print_blob_info",
                 7223,
                 "IFE ctx_idx: %u clk update usage=%u left_clk= %lu right_clk=%lu",
                 *(_DWORD *)(a1 + 56),
                 *(_DWORD *)(a3 + 1808),
                 *(_QWORD *)(a3 + 1816),
                 *(_QWORD *)(a3 + 1824));
    if ( *(_BYTE *)(a3 + 1944) == 1 )
      return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               0x2000000,
               3,
               "cam_ife_mgr_print_blob_info",
               7231,
               "SFE ctx_idx: %u clk update usage: %u left_clk: %lu right_clk: %lu",
               *(_DWORD *)(a1 + 56),
               *(_DWORD *)(a3 + 1880),
               *(_QWORD *)(a3 + 1888),
               *(_QWORD *)(a3 + 1896));
  }
  return result;
}
