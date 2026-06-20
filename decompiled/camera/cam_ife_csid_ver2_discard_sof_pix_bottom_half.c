__int64 __fastcall cam_ife_csid_ver2_discard_sof_pix_bottom_half(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x21
  __int64 v4; // x25
  __int64 v5; // x19
  __int64 v6; // x26
  char v7; // w9
  __int64 v8; // x27
  int v9; // w8
  __int64 v10; // x26
  unsigned int v11; // w0
  int v13; // [xsp+8h] [xbp-8h]

  if ( a1 )
  {
    v1 = *(unsigned int *)(a1 + 4);
    if ( (unsigned int)v1 >= 0xC )
    {
      __break(0x5512u);
      return cam_ife_csid_ver2_path_irq_subscribe();
    }
    else
    {
      v2 = *(_QWORD *)(a1 + 24);
      v4 = *(_QWORD *)(v2 + 264);
      v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 112LL) + 3680LL);
      v6 = *(_QWORD *)(*(_QWORD *)(v5 + 31128) + 384LL);
      v7 = debug_mdl;
      v8 = *(unsigned int *)(*(_QWORD *)(**(_QWORD **)(v5 + 31136) + 8 * v1 + 136) + 316LL);
      v9 = *(_DWORD *)(v2 + 224) + 1;
      *(_DWORD *)(v2 + 224) = v9;
      if ( (v7 & 8) != 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v7 & 8,
          4,
          "cam_ife_csid_ver2_discard_sof_pix_bottom_half",
          1221,
          "CSID[%u] Discard frame on %s path, num SOFs: %u",
          *(_DWORD *)(*(_QWORD *)(v5 + 31120) + 4LL),
          (const char *)(a1 + 128),
          v9);
      raw_spin_lock(v5 + 30968);
      if ( *(_DWORD *)(*(_QWORD *)(v5 + 31128) + 92LL) == 1 )
      {
        if ( *(_DWORD *)(v2 + 224) == *(_DWORD *)(v2 + 228) )
        {
          if ( *(_DWORD *)(v2 + 240) <= 1u )
          {
            v10 = v6 + v8;
            v11 = cam_io_r_mb(v10 + *(unsigned int *)(v4 + 20));
            cam_io_w_mb(*(_DWORD *)(v4 + 348) | v11, v10 + *(unsigned int *)(v4 + 20));
            if ( (debug_mdl & 8) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_csid_ver2_discard_sof_pix_bottom_half",
                1241,
                "CSID[%u] start cmd programmed for %s sof_cnt %u value:0x%x",
                *(_DWORD *)(*(_QWORD *)(v5 + 31120) + 4LL),
                (const char *)(a1 + 128),
                *(_DWORD *)(v2 + 224),
                v13);
          }
          cam_ife_csid_ver2_reset_discard_frame_cfg(a1, v5, v2);
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_discard_sof_pix_bottom_half",
          1226,
          "CSID[%u] powered down state",
          *(_DWORD *)(*(_QWORD *)(v5 + 31120) + 4LL));
      }
      raw_spin_unlock(v5 + 30968);
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_discard_sof_pix_bottom_half",
      1200,
      "Invalid handler_priv");
    return 4294967274LL;
  }
}
