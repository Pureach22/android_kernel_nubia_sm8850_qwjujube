__int64 __fastcall cam_vfe_top_set_axi_bw_vote(
        __int64 a1,
        __int64 a2,
        const char *a3,
        const char *a4,
        char a5,
        __int64 a6)
{
  unsigned int *v7; // x20
  const char *v8; // x25
  unsigned __int64 v12; // x8
  int updated; // w0
  __int64 v16; // x7
  int v17; // w6
  __int64 v18; // x27
  const char *v19; // x26
  const char *v20; // x0
  __int64 v21; // x28
  unsigned __int64 v22; // x27
  const char *v23; // x26
  const char *v24; // x0
  unsigned int v26; // w9
  const char *v27; // x7
  __int64 v28; // x9
  unsigned int v29; // [xsp+3Ch] [xbp-14h]
  __int64 i; // [xsp+48h] [xbp-8h]

  v7 = *(unsigned int **)(*(_QWORD *)(a1 + 10408) + 3296LL);
  LOBYTE(v8) = a5;
  v12 = debug_mdl & 0x2000008;
  if ( (debug_mdl & 0x2000008) != 0 && debug_priority == 0 )
  {
    v17 = *(_DWORD *)(a1 + 1068);
    v26 = *(_DWORD *)(a1 + 10372) - 1;
    if ( v26 <= 2 )
    {
      v27 = off_44EBB0[v26];
      goto LABEL_26;
    }
    goto LABEL_25;
  }
  while ( 1 )
  {
    updated = cam_cpas_update_axi_vote(*v7, a2);
    v29 = updated;
    if ( !updated )
      break;
    if ( ((unsigned __int8)v8 & 1) != 0 )
      v16 = -1;
    else
      v16 = a6;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000000,
      1,
      "cam_vfe_top_set_axi_bw_vote",
      48,
      "VFE:%d BW request failed, req_id: %ld, final num_paths: %d, rc=%d",
      *(_DWORD *)(a1 + 1068),
      v16,
      *(_DWORD *)a2,
      updated);
    v12 = *(unsigned int *)a2;
    if ( (_DWORD)v12 )
    {
      v7 = nullptr;
      a4 = "cam_vfe_top_set_axi_bw_vote";
      v18 = a2 + 20;
      a3 = "ife[%d] : Applied BW Vote : [%s][%s][%s] [%llu %llu %llu]";
      while ( v7 != (unsigned int *)&unk_F )
      {
        a6 = *(unsigned int *)(a1 + 1068);
        v8 = cam_cpas_axi_util_path_type_to_string(*(_DWORD *)(v18 - 4));
        v19 = cam_cpas_axi_util_trans_type_to_string(*(_DWORD *)(v18 - 8));
        v20 = cam_cpas_axi_util_drv_vote_lvl_to_string(*(_DWORD *)v18);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000000,
          3,
          "cam_vfe_top_set_axi_bw_vote",
          61,
          "ife[%d] : Applied BW Vote : [%s][%s][%s] [%llu %llu %llu]",
          a6,
          v8,
          v19,
          v20,
          *(_QWORD *)(v18 + 4),
          *(_QWORD *)(v18 + 12),
          *(_QWORD *)(v18 + 20));
        v12 = *(unsigned int *)a2;
        v7 = (unsigned int *)((char *)v7 + 1);
        v18 += 40;
        if ( (unsigned __int64)v7 >= v12 )
          goto LABEL_13;
      }
    }
    else
    {
LABEL_13:
      a2 = 0;
      a4 = "cam_vfe_top_set_axi_bw_vote";
      a3 = "ife[%d] : History[%d] BW Vote : [%s][%s] [%s] [%llu %llu %llu]";
      for ( i = a1 + 6556; ; i += 608 )
      {
        v7 = (unsigned int *)(a1 + 6544 + 608 * a2);
        v12 = *v7;
        if ( (_DWORD)v12 )
          break;
LABEL_14:
        if ( ++a2 == 6 )
          return v29;
      }
      v21 = i;
      v22 = 0;
      while ( v22 != 15 )
      {
        a6 = *(unsigned int *)(a1 + 1068);
        v8 = cam_cpas_axi_util_path_type_to_string(*(_DWORD *)(v21 + 4));
        v23 = cam_cpas_axi_util_trans_type_to_string(*(_DWORD *)v21);
        v24 = cam_cpas_axi_util_drv_vote_lvl_to_string(*(_DWORD *)(v21 + 8));
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000000,
          3,
          "cam_vfe_top_set_axi_bw_vote",
          77,
          "ife[%d] : History[%d] BW Vote : [%s][%s] [%s] [%llu %llu %llu]",
          a6,
          a2,
          v8,
          v23,
          v24,
          *(_QWORD *)(v21 + 12),
          *(_QWORD *)(v21 + 20),
          *(_QWORD *)(v21 + 28));
        v12 = *v7;
        ++v22;
        v21 += 40;
        if ( v22 >= v12 )
          goto LABEL_14;
      }
    }
    __break(0x5512u);
LABEL_25:
    v27 = "Invalid State";
LABEL_26:
    if ( ((unsigned __int8)v8 & 1) != 0 )
      v28 = -1;
    else
      v28 = a6;
    ((void (*)(__int64, unsigned __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v12,
      4,
      "cam_vfe_top_set_axi_bw_vote",
      38,
      "VFE:%d Sending final BW to cpas bw_state:%s camnoc_bw:%llu mnoc_bw:%llu req_id:%ld",
      v17,
      v27,
      a3,
      a4,
      v28);
  }
  memcpy((void *)(a1 + 1072), (const void *)a2, 0x260u);
  *(_QWORD *)(a1 + 10352) = a3;
  *(_QWORD *)(a1 + 10360) = a4;
  return v29;
}
