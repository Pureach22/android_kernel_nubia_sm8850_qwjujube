__int64 __fastcall cam_sfe_top_set_axi_bw_vote(__int64 a1, __int64 a2, const char *a3, char a4, __int64 a5)
{
  unsigned int *v6; // x20
  unsigned __int64 v9; // x8
  int updated; // w0
  int v12; // w6
  __int64 v13; // x27
  int v14; // w24
  const char *v15; // x25
  const char *v16; // x26
  const char *v17; // x0
  __int64 v18; // x28
  unsigned __int64 v19; // x27
  int v20; // w24
  const char *v21; // x25
  const char *v22; // x26
  const char *v23; // x0
  unsigned int v25; // w9
  const char *v26; // x7
  __int64 v27; // x9
  unsigned int v28; // [xsp+3Ch] [xbp-14h]
  __int64 i; // [xsp+48h] [xbp-8h]

  v6 = *(unsigned int **)(*(_QWORD *)a1 + 3296LL);
  v9 = debug_mdl & 0x2000008;
  if ( (debug_mdl & 0x2000008) != 0 && debug_priority == 0 )
  {
    v12 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL);
    v25 = *(_DWORD *)(a1 + 31580) - 1;
    if ( v25 <= 2 )
    {
      v26 = off_44E3E8[v25];
      goto LABEL_23;
    }
    goto LABEL_22;
  }
  while ( 1 )
  {
    updated = cam_cpas_update_axi_vote(*v6, a2);
    v28 = updated;
    if ( !updated )
      break;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000000,
      1,
      "cam_sfe_top_set_axi_bw_vote",
      136,
      "BW request failed, rc=%d",
      updated);
    v9 = *(unsigned int *)a2;
    if ( (_DWORD)v9 )
    {
      v6 = nullptr;
      a3 = "cam_sfe_top_set_axi_bw_vote";
      v13 = a2 + 20;
      while ( v6 != (unsigned int *)&unk_F )
      {
        v14 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL);
        v15 = cam_cpas_axi_util_path_type_to_string(*(_DWORD *)(v13 - 4));
        v16 = cam_cpas_axi_util_trans_type_to_string(*(_DWORD *)(v13 - 8));
        v17 = cam_cpas_axi_util_drv_vote_lvl_to_string(*(_DWORD *)v13);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000000,
          3,
          "cam_sfe_top_set_axi_bw_vote",
          149,
          "sfe[%d] : Applied BW Vote : [%s][%s][%s] [%llu %llu %llu]",
          v14,
          v15,
          v16,
          v17,
          *(_QWORD *)(v13 + 4),
          *(_QWORD *)(v13 + 12),
          *(_QWORD *)(v13 + 20));
        v9 = *(unsigned int *)a2;
        v6 = (unsigned int *)((char *)v6 + 1);
        v13 += 40;
        if ( (unsigned __int64)v6 >= v9 )
          goto LABEL_10;
      }
    }
    else
    {
LABEL_10:
      a2 = 0;
      a3 = "cam_sfe_top_set_axi_bw_vote";
      for ( i = a1 + 27844; ; i += 608 )
      {
        v6 = (unsigned int *)(a1 + 27832 + 608 * a2);
        v9 = *v6;
        if ( (_DWORD)v9 )
          break;
LABEL_11:
        if ( ++a2 == 6 )
          return v28;
      }
      v18 = i;
      v19 = 0;
      while ( v19 != 15 )
      {
        v20 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL);
        v21 = cam_cpas_axi_util_path_type_to_string(*(_DWORD *)(v18 + 4));
        v22 = cam_cpas_axi_util_trans_type_to_string(*(_DWORD *)v18);
        v23 = cam_cpas_axi_util_drv_vote_lvl_to_string(*(_DWORD *)(v18 + 8));
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000000,
          3,
          "cam_sfe_top_set_axi_bw_vote",
          165,
          "sfe[%d] : History[%d] BW Vote : [%s][%s] [%s] [%llu %llu %llu]",
          v20,
          a2,
          v21,
          v22,
          v23,
          *(_QWORD *)(v18 + 12),
          *(_QWORD *)(v18 + 20),
          *(_QWORD *)(v18 + 28));
        v9 = *v6;
        ++v19;
        v18 += 40;
        if ( v19 >= v9 )
          goto LABEL_11;
      }
    }
    __break(0x5512u);
LABEL_22:
    v26 = "Invalid State";
LABEL_23:
    if ( (a4 & 1) != 0 )
      v27 = -1;
    else
      v27 = a5;
    ((void (*)(__int64, unsigned __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v9,
      4,
      "cam_sfe_top_set_axi_bw_vote",
      127,
      "SFE:%d Sending final BW to cpas bw_state:%s bw_vote:%llu req_id:%ld",
      v12,
      v26,
      a3,
      v27);
  }
  memcpy((void *)(a1 + 31608), (const void *)a2, 0x260u);
  *(_QWORD *)(a1 + 23568) = a3;
  return v28;
}
