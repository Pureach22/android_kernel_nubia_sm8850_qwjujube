__int64 __fastcall cam_ife_csid_ver2_disable_path(char a1, __int64 a2, unsigned int *a3, char a4)
{
  __int64 v5; // x21
  __int64 result; // x0
  __int64 v7; // x9
  const char *v8; // x5
  __int64 v9; // x1
  __int64 v10; // x6
  __int64 v11; // x2
  __int64 v12; // x4
  __int64 v13; // x7
  unsigned int v14; // w9
  __int64 v15; // x22
  int v17; // w1
  int v18; // w0
  int v19; // w0
  int v20; // w0
  int v21; // w0
  unsigned int v22; // w0
  __int64 v23; // x7
  const char *v24; // x3
  __int64 v25; // x6
  __int64 v26; // x4
  int v27; // w0
  int v28; // w0
  int v29; // w0
  int v30; // w0
  unsigned int v31; // w0
  unsigned int v32; // [xsp+0h] [xbp-10h]
  unsigned int v33; // [xsp+8h] [xbp-8h]

  if ( a3[2] != 4 )
  {
    v8 = "CSID:%u path res type:%d res_id:%d Invalid state:%d";
    v10 = *(unsigned int *)(*(_QWORD *)(a2 + 31120) + 4LL);
    v9 = 8;
    v12 = 4208;
    v13 = *a3;
    v14 = a3[1];
    v33 = a3[2];
    v11 = 1;
    v32 = v14;
    goto LABEL_7;
  }
  v5 = a3[1];
  if ( (unsigned int)v5 < 0xC )
  {
    v15 = *((_QWORD *)a3 + 3);
    v17 = *(_DWORD *)(v15 + 212);
    if ( (a1 & 1) != 0 )
    {
      if ( v17 )
      {
        v18 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a2 + 8 * v5 + 31016));
        if ( v18 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "cam_ife_csid_ver2_maskout_path_irqs",
            4081,
            "Failed to unsubscribe path err irq CSID:%u rc: %d",
            *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL),
            v18);
        *(_DWORD *)(v15 + 212) = 0;
      }
      if ( *(_DWORD *)(v15 + 208) )
      {
        v19 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a2 + 8 * v5 + 31016));
        if ( v19 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "cam_ife_csid_ver2_maskout_path_irqs",
            4093,
            "Failed to unsubscribe path info irq CSID:%u rc: %d",
            *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL),
            v19);
        *(_DWORD *)(v15 + 208) = 0;
      }
      if ( *(_DWORD *)(v15 + 216) )
      {
        v20 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a2 + 8 * v5 + 31016));
        if ( v20 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "cam_ife_csid_ver2_maskout_path_irqs",
            4105,
            "Failed to unsubscribe path discard irq CSID:%u rc: %d",
            *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL),
            v20);
        *(_DWORD *)(v15 + 216) = 0;
      }
      if ( !*(_DWORD *)(v15 + 204) )
        goto LABEL_44;
      v21 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a2 + 30984));
      if ( v21 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_ife_csid_ver2_maskout_path_irqs",
          4117,
          "Failed to unsubscribe path irq in top CSID:%u rc: %d",
          *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL),
          v21);
      *(_DWORD *)(v15 + 204) = 0;
      v22 = ((__int64 (__fastcall *)(_QWORD, _QWORD))cam_irq_controller_unregister_dependent)(
              *(_QWORD *)(a2 + 30984),
              *(_QWORD *)(a2 + 8 * v5 + 31016));
      if ( !v22 )
        goto LABEL_44;
      v23 = v22;
      v24 = "cam_ife_csid_ver2_maskout_path_irqs";
      v25 = *(unsigned int *)(*(_QWORD *)(a2 + 31120) + 4LL);
      v26 = 4127;
    }
    else
    {
      if ( v17 )
      {
        v27 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq_evt)(*(_QWORD *)(a2 + 8 * v5 + 31016));
        if ( v27 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "cam_ife_csid_ver2_disable_path_irqs_evts",
            4145,
            "Failed to unsubscribe path err irq evt CSID:%u rc: %d",
            *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL),
            v27);
        *(_DWORD *)(v15 + 212) = 0;
      }
      if ( *(_DWORD *)(v15 + 208) )
      {
        v28 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq_evt)(*(_QWORD *)(a2 + 8 * v5 + 31016));
        if ( v28 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "cam_ife_csid_ver2_disable_path_irqs_evts",
            4157,
            "Failed to unsubscribe path info irq evt CSID:%u rc: %d",
            *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL),
            v28);
        *(_DWORD *)(v15 + 208) = 0;
      }
      if ( *(_DWORD *)(v15 + 216) )
      {
        v29 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq_evt)(*(_QWORD *)(a2 + 8 * v5 + 31016));
        if ( v29 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "cam_ife_csid_ver2_disable_path_irqs_evts",
            4169,
            "Failed to unsubscribe path discard irq evt CSID:%u rc: %d",
            *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL),
            v29);
        *(_DWORD *)(v15 + 216) = 0;
      }
      if ( !*(_DWORD *)(v15 + 204) )
        goto LABEL_44;
      v30 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq_evt)(*(_QWORD *)(a2 + 30984));
      if ( v30 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_ife_csid_ver2_disable_path_irqs_evts",
          4181,
          "Failed to unsubscribe path irq in top evt CSID:%u rc: %d",
          *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL),
          v30);
      *(_DWORD *)(v15 + 204) = 0;
      v31 = ((__int64 (__fastcall *)(_QWORD, _QWORD))cam_irq_controller_unregister_dependent)(
              *(_QWORD *)(a2 + 30984),
              *(_QWORD *)(a2 + 8 * v5 + 31016));
      if ( !v31 )
        goto LABEL_44;
      v23 = v31;
      v24 = "cam_ife_csid_ver2_disable_path_irqs_evts";
      v25 = *(unsigned int *)(*(_QWORD *)(a2 + 31120) + 4LL);
      v26 = 4191;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      8,
      2,
      v24,
      v26,
      "Failed to unregister path dependent with top CSID:%u rc: %d",
      v25,
      v23);
LABEL_44:
    if ( (a4 & 1) == 0 )
      *(_BYTE *)(v15 + 256) = 0;
    *(_WORD *)(v15 + 248) = 0;
    *(_QWORD *)(v15 + 224) = 0;
    *(_DWORD *)(v15 + 236) = 0;
    return 0;
  }
  result = 4294967274LL;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v7 = *(_QWORD *)(a2 + 31120);
    v8 = "CSID:%u Invalid res id%d";
    v9 = debug_mdl & 8;
    v10 = *(unsigned int *)(v7 + 4);
    v11 = 4;
    v12 = 4214;
    v13 = (unsigned int)v5;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int, unsigned int))cam_print_log)(
      3,
      v9,
      v11,
      "cam_ife_csid_ver2_disable_path",
      v12,
      v8,
      v10,
      v13,
      v32,
      v33);
    return 4294967274LL;
  }
  return result;
}
