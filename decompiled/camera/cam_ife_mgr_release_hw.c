__int64 __fastcall cam_ife_mgr_release_hw(__int64 a1, __int64 **a2)
{
  __int64 *v2; // x19
  int updated; // w0
  unsigned int v5; // w21
  unsigned int v7; // w0
  __int64 **v8; // x8
  __int64 *v9; // x9
  int v10; // w9
  _QWORD *v11; // x0
  size_t v12; // x2
  void *v13; // x0
  _QWORD *v14; // x0
  void *v15; // x0
  size_t v16; // x2
  int v17; // w8
  _QWORD *v18; // x0
  _QWORD *v19; // x0
  int v20; // w8
  _QWORD *v21; // x0
  _QWORD *v22; // x0
  _QWORD *v23; // x0
  _QWORD *v24; // x1
  int v25; // w9
  _QWORD *v26; // x0
  unsigned __int64 v27; // x8
  __int64 v28; // x22
  __int64 *v29; // x20
  __int64 **v30; // x1

  if ( a1 && a2 )
  {
    v2 = *a2;
    if ( *a2 && (v2[1172] & 1) != 0 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_mgr_release_hw",
          9366,
          "Enter...ctx id:%u",
          *((_DWORD *)v2 + 14));
      if ( *((_BYTE *)v2 + 9377) == 1 )
        cam_ife_hw_mgr_deinit_hw(v2);
      cam_ife_hw_mgr_release_hw_for_ctx(v2);
      if ( *((_DWORD *)v2 + 2328) == 2 && (updated = cam_ife_mgr_update_core_info_to_cpas(v2, 0)) != 0 )
      {
        v5 = updated;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_release_hw",
          9378,
          "Failed to update core info to cpas rc:%d, ctx_idx: %u",
          updated,
          *((_DWORD *)v2 + 14));
      }
      else
      {
        v5 = 0;
      }
      v7 = *((_DWORD *)v2 + 2180);
      v2[1073] = 0;
      v2[1089] = 0;
      v2[1074] = 0;
      v2[1075] = 0;
      v2[1076] = 0;
      v2[1077] = 0;
      v2[1078] = 0;
      v2[1079] = 0;
      v2[1080] = 0;
      v2[1081] = 0;
      v2[1082] = 0;
      v2[1083] = 0;
      v2[1084] = 0;
      v2[1085] = 0;
      v2[1086] = 0;
      v2[1087] = 0;
      v2[1088] = 0;
      cam_cdm_release(v7);
      v8 = (__int64 **)v2[1];
      if ( *v8 == v2 && (v9 = (__int64 *)*v2, *(__int64 **)(*v2 + 8) == v2) )
      {
        v9[1] = (__int64)v8;
        *v8 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      *v2 = (__int64)v2;
      v2[1] = (__int64)v2;
      v10 = (unsigned __int8)mem_trace_en;
      v11 = (_QWORD *)v2[34];
      v2[1090] = 0xFFFFFFFF00000000LL;
      v2[1091] = 0;
      *((_DWORD *)v2 + 2329) = 0;
      *((_DWORD *)v2 + 2285) = 0;
      v2[1107] = 0;
      *(__int64 *)((char *)v2 + 60) = 0x800000008LL;
      *((_DWORD *)v2 + 2338) = 0;
      v2[1064] = 0;
      if ( v10 == 1 )
        cam_mem_trace_free(v11, 0);
      else
        kvfree(v11);
      v2[34] = 0;
      v12 = (unsigned int)max_ife_out_res;
      v13 = (void *)v2[1062];
      *((_DWORD *)v2 + 2383) = dword_3A85A4;
      memset(v13, 255, v12);
      if ( *((_DWORD *)v2 + 2328) == 2 )
      {
        v14 = (_QWORD *)v2[35];
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v14, 0);
        else
          kvfree(v14);
        v15 = (void *)v2[1063];
        v16 = (unsigned int)max_sfe_out_res;
        v2[35] = 0;
        memset(v15, 255, v16);
      }
      v17 = (unsigned __int8)mem_trace_en;
      v18 = (_QWORD *)v2[1170];
      *((_DWORD *)v2 + 2328) = 0;
      v2[1167] = 0;
      v2[1168] = 0;
      if ( v17 == 1 )
        cam_mem_trace_free(v18, 0);
      else
        kvfree(v18);
      v19 = (_QWORD *)v2[1171];
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v19, 0);
      else
        kvfree(v19);
      v20 = (unsigned __int8)mem_trace_en;
      v21 = (_QWORD *)v2[1184];
      *((_DWORD *)v2 + 2362) = 0;
      v2[1182] = 0;
      *((_DWORD *)v2 + 2366) = 0;
      v2[1170] = 0;
      v2[1171] = 0;
      if ( v20 == 1 )
        cam_mem_trace_free(v21, 0);
      else
        kvfree(v21);
      v22 = (_QWORD *)v2[1185];
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v22, 0);
      else
        kvfree(v22);
      v23 = (_QWORD *)v2[1249];
      v24 = (_QWORD *)v2[1250];
      v2[1185] = 0;
      v2[1184] = 0;
      cam_packet_util_put_unique_tbl(v23, v24);
      v2[1250] = 0;
      v2[1249] = 0;
      *((_DWORD *)v2 + 2211) = 0;
      v25 = (unsigned __int8)mem_trace_en;
      v26 = (_QWORD *)v2[1092];
      *(__int64 *)((char *)v2 + 8748) = 0;
      *(__int64 *)((char *)v2 + 8756) = 0;
      *(__int64 *)((char *)v2 + 8764) = 0;
      *(__int64 *)((char *)v2 + 8772) = 0;
      *(__int64 *)((char *)v2 + 8780) = 0;
      *(__int64 *)((char *)v2 + 8788) = 0;
      *(__int64 *)((char *)v2 + 8796) = 0;
      *(__int64 *)((char *)v2 + 8804) = 0;
      *(__int64 *)((char *)v2 + 8812) = 0;
      *(__int64 *)((char *)v2 + 8820) = 0;
      *(__int64 *)((char *)v2 + 8828) = 0;
      *(__int64 *)((char *)v2 + 8836) = 0;
      if ( v25 == 1 )
        cam_mem_trace_free(v26, 0);
      else
        kvfree(v26);
      v2[1092] = 0;
      ktime_get_real_ts64(v2 + 1165);
      v27 = v2[1165];
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_ife_mgr_release_hw",
        9446,
        "%llu:%llu:%llu.%llu Release HW success ctx id: %u",
        (_QWORD)(v27 / 0xE10 - 24 * ((v27 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
        v27 / 0x3C - 60 * ((unsigned __int64)((v27 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
        v27 % 0x3C,
        v2[1166] / 1000000,
        *((_DWORD *)v2 + 14));
      *((_DWORD *)v2 + 14) = 8;
      v2[1165] = 0;
      v28 = a1;
      v29 = (__int64 *)(a1 + 368);
      v2[1166] = 0;
      mutex_lock(&unk_394A30);
      v30 = *(__int64 ***)(v28 + 376);
      if ( v2 == v29 || v30 == (__int64 **)v2 || *v30 != v29 )
      {
        _list_add_valid_or_report(v2);
      }
      else
      {
        *(_QWORD *)(v28 + 376) = v2;
        *v2 = (__int64)v29;
        v2[1] = (__int64)v30;
        *v30 = v2;
      }
      mutex_unlock(&unk_394A30);
      return v5;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_release_hw",
        9361,
        "Invalid context is used");
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_release_hw",
      9355,
      "Invalid arguments");
    return 4294967274LL;
  }
}
