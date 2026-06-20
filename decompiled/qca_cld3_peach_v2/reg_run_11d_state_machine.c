__int64 __fastcall reg_run_11d_state_machine(__int64 a1)
{
  __int64 psoc_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned __int8 *v11; // x21
  char is_world_alpha2; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  __int64 v22; // x5
  const char *v23; // x2
  const char *v24; // x3
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 *v34; // x20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // [xsp+18h] [xbp-38h] BYREF
  __int64 *v44; // [xsp+20h] [xbp-30h]
  __int64 (__fastcall *v45)(); // [xsp+28h] [xbp-28h]
  __int64 (__fastcall *v46)(); // [xsp+30h] [xbp-20h]
  __int64 v47; // [xsp+38h] [xbp-18h]
  __int64 v48; // [xsp+40h] [xbp-10h]
  __int64 v49; // [xsp+48h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  psoc_obj = reg_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v23 = "%s: Null reg psoc private obj";
LABEL_8:
    v24 = "reg_run_11d_state_machine";
LABEL_9:
    result = qdf_trace_msg(0x51u, 2u, v23, v3, v4, v5, v6, v7, v8, v9, v10, v24);
    goto LABEL_22;
  }
  v11 = (unsigned __int8 *)(psoc_obj + 90112);
  if ( *(unsigned __int8 *)(psoc_obj + 91153) == 255 )
  {
    *(_BYTE *)(psoc_obj + 91151) = 0;
    v23 = "%s: Invalid vdev";
    goto LABEL_8;
  }
  is_world_alpha2 = reg_is_world_alpha2(psoc_obj + 91099);
  v21 = v11[1039];
  if ( v11[3122] == 1 && (is_world_alpha2 & 1) != 0 )
  {
    v22 = 1;
LABEL_14:
    v11[1039] = v22;
    goto LABEL_15;
  }
  if ( v11[1053] != 1 || v11[1052] != 1 )
  {
    v22 = v11[1038];
    goto LABEL_14;
  }
  v22 = 0;
  v11[1039] = 0;
LABEL_15:
  result = qdf_trace_msg(
             0x51u,
             8u,
             "%s: inside 11d state machine:tmp %d 11d_supp %d org %d set %d pri %d vdev %d",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "reg_run_11d_state_machine",
             v21,
             v22,
             v11[1038],
             v11[1052],
             v11[1041]);
  if ( v21 != v11[1039] && v11[1040] == 1 )
  {
    result = _qdf_mem_malloc(0x10u, "reg_run_11d_state_machine", 247);
    if ( result )
    {
      *(_QWORD *)result = a1;
      v34 = (__int64 *)result;
      *(_BYTE *)(result + 8) = v11[1039];
      v43 = 0;
      v44 = nullptr;
      v47 = 0;
      v48 = 0;
      v45 = nullptr;
      v46 = nullptr;
      if ( (unsigned int)wlan_objmgr_psoc_try_get_ref(a1, 0x15u, v26, v27, v28, v29, v30, v31, v32, v33) )
      {
        v23 = "%s: error taking psoc ref cnt";
        v24 = "reg_sched_11d_msg";
        goto LABEL_9;
      }
      v44 = v34;
      v45 = reg_send_11d_msg_cbk;
      v46 = reg_send_11d_flush_cbk;
      result = scheduler_post_message_debug(
                 0x51u,
                 0x51u,
                 73,
                 (unsigned __int16 *)&v43,
                 0xC6u,
                 (__int64)"reg_sched_11d_msg");
      if ( (_DWORD)result )
        result = wlan_objmgr_psoc_release_ref(*v34, 0x15u, v35, v36, v37, v38, v39, v40, v41, v42);
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
