__int64 __fastcall cam_jpeg_mgr_bottom_half_irq(__int64 a1, __int64 a2)
{
  __int64 **v2; // x21
  __int64 *v3; // x22
  __int64 v4; // x28
  __int64 v6; // x20
  __int64 v8; // x0
  __int64 v9; // x19
  __int16 v10; // w9
  __int64 v11; // x8
  __int64 v12; // x6
  __int64 v13; // x8
  __int64 (__fastcall *v14)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v15; // x0
  unsigned int v16; // w23
  __int64 v17; // x0
  __int64 *v18; // x21
  __int64 v19; // x9
  __int64 v20; // x9
  __int64 v21; // x8
  _DWORD *v22; // x10
  int v23; // w11
  __int64 v24; // x8
  _DWORD *v25; // x8
  __int64 v26; // x0
  char *v27; // x21
  __int64 *v28; // x8
  __int64 v29; // x9
  __int64 (__fastcall *v30)(__int64, __int64, __int64 (__fastcall **)(int, int, __int64), __int64); // x8
  __int64 v31; // x0
  unsigned int v32; // w0
  const char *v33; // x5
  unsigned int v34; // w6
  __int64 v35; // x4
  unsigned int v36; // w19
  const char *v37; // x5
  __int64 v38; // x4
  __int64 result; // x0
  const char *v40; // x5
  __int64 v41; // x4
  __int64 v42; // x9
  _DWORD *v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  int *task; // x0
  __int64 v47; // x8
  unsigned int v48; // w0
  unsigned __int64 v49; // x6
  unsigned int v50; // w6
  int v51; // w8
  int v52; // w9
  __int64 v53; // x10
  unsigned int v54; // w21
  __int64 v55; // x22
  __int64 v56; // x0
  unsigned __int64 v57; // [xsp+20h] [xbp-150h] BYREF
  __int64 v58; // [xsp+28h] [xbp-148h] BYREF
  _QWORD *v59; // [xsp+30h] [xbp-140h] BYREF
  __int64 v60; // [xsp+38h] [xbp-138h]
  __int64 v61; // [xsp+40h] [xbp-130h] BYREF
  __int64 (__fastcall *v62)(int, int, __int64); // [xsp+48h] [xbp-128h] BYREF
  __int64 v63; // [xsp+50h] [xbp-120h]
  __int64 v64; // [xsp+58h] [xbp-118h]
  __int64 v65; // [xsp+60h] [xbp-110h]
  __int64 v66; // [xsp+68h] [xbp-108h] BYREF
  __int64 v67; // [xsp+70h] [xbp-100h]
  __int64 v68; // [xsp+78h] [xbp-F8h]
  __int64 v69; // [xsp+80h] [xbp-F0h]
  __int64 v70; // [xsp+88h] [xbp-E8h]
  __int64 v71; // [xsp+90h] [xbp-E0h]
  __int64 v72; // [xsp+98h] [xbp-D8h]
  __int64 v73; // [xsp+A0h] [xbp-D0h]
  _QWORD v74[21]; // [xsp+A8h] [xbp-C8h] BYREF
  __int64 v75; // [xsp+150h] [xbp-20h]
  __int64 v76; // [xsp+158h] [xbp-18h]
  __int64 v77; // [xsp+160h] [xbp-10h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  v76 = 0;
  v73 = 0;
  memset(v74, 0, sizeof(v74));
  v64 = 0;
  v65 = 0;
  v62 = nullptr;
  v63 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v66 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = nullptr;
  v57 = 0;
  if ( !a1 || !a2 )
  {
    v37 = "Invalid data";
    v38 = 388;
LABEL_47:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_bottom_half_irq",
      v38,
      v37);
    goto LABEL_48;
  }
  v2 = *(__int64 ***)(a2 + 16);
  v3 = *v2;
  if ( !*v2 )
  {
    v37 = "No ctx data found!";
    v38 = 399;
    goto LABEL_47;
  }
  if ( (v3[13] & 1) == 0 )
  {
    v37 = "ctx is not in use";
    v38 = 404;
    goto LABEL_47;
  }
  v4 = *v3;
  if ( !*v3 )
  {
    v37 = "cam_ctx is null";
    v38 = 410;
    goto LABEL_47;
  }
  v6 = *((unsigned int *)v3 + 14);
  v8 = mutex_lock(&g_jpeg_hw_mgr);
  if ( (unsigned int)v6 < 2 )
  {
    if ( ((8 * v6) | (unsigned __int64)&unk_1490) > 0x2AB0 || ((4 * v6) | (unsigned __int64)&unk_1488) > 0x2AB0 )
      goto LABEL_89;
    if ( dword_3AA120[v6] )
    {
      v9 = qword_3AA128[v6];
      if ( v9 )
      {
        v10 = debug_mdl;
        v11 = a2;
        v8 = a1;
        ++*(_DWORD *)(v9 + 104);
        if ( (v10 & 0x200) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            v10 & 0x200,
            4,
            "cam_jpeg_mgr_bottom_half_irq",
            429,
            "dev_type: %u, hw_entry_processed %d",
            v6);
          v8 = a1;
          v11 = a2;
        }
        if ( qword_3AA0D0 )
        {
          v12 = *(unsigned int *)(v9 + 88);
          LODWORD(v61) = *(_DWORD *)(v9 + 88);
          BYTE4(v61) = qword_3AA0D8 != 0;
          if ( (debug_mdl & 0x200) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x200,
              4,
              "cam_jpeg_mgr_bottom_half_irq",
              435,
              "req %lld bug is enabled for MISR :%d",
              v12,
              qword_3AA0D8 != 0);
          v13 = **((_QWORD **)&g_jpeg_hw_mgr + v6 + 649);
          v14 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v13 + 88);
          v15 = *(_QWORD *)(v13 + 112);
          if ( *((_DWORD *)v14 - 1) != -1055839300 )
            __break(0x8229u);
          v16 = v14(v15, 7, &v61, 8);
          v11 = a2;
          v8 = a1;
          if ( v16 )
          {
            if ( (unsigned int)__ratelimit(&cam_jpeg_mgr_bottom_half_irq__rs, "cam_jpeg_mgr_bottom_half_irq") )
              v17 = 3;
            else
              v17 = 2;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              v17,
              512,
              2,
              "cam_jpeg_mgr_bottom_half_irq",
              444,
              "jpeg and camnoc hw misr enable failed %d",
              v16);
            v8 = a1;
            v11 = a2;
          }
        }
        if ( (_DWORD)v6 == 1 )
        {
          if ( *(_DWORD *)(v11 + 4) )
          {
            if ( *(_DWORD *)(v9 + 104) <= 1u )
            {
              v8 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD *))cam_jpeg_process_next_hw_update)(v8, v3, v74);
              if ( !(_DWORD)v8 )
              {
                mutex_unlock(&g_jpeg_hw_mgr);
                result = 0;
                goto LABEL_49;
              }
            }
          }
        }
        v18 = v2[1];
        if ( *(_DWORD *)v18 )
          goto LABEL_30;
        if ( (unsigned int)cam_mem_get_cpu_buf(*((_DWORD *)v18 + 5), &v58, &v57) )
        {
          v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                 3,
                 512,
                 1,
                 "cam_jpeg_mgr_bottom_half_irq",
                 483,
                 "Buffer pointer for inout param is null");
        }
        else
        {
          v49 = *((unsigned int *)v18 + 6);
          if ( v57 < 8 || v57 - 8 <= v49 )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64))cam_print_log)(
              3,
              512,
              1,
              "cam_jpeg_mgr_bottom_half_irq",
              472,
              "Inval off = %u cmd buf len = %zu inout_param_size = %d",
              v49);
          else
            *(_DWORD *)(v58 + ((unsigned int)v49 & 0xFFFFFFFC) + 4) = *(_DWORD *)(a2 + 4);
          v8 = cam_mem_put_cpu_buf(*((_DWORD *)v18 + 5));
        }
        if ( (debug_mdl & 0x200) != 0 && !debug_priority )
        {
          v8 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 0x200,
                 4,
                 "cam_jpeg_mgr_bottom_half_irq",
                 487,
                 "Encoded Size %d Thresold Size: %u",
                 *(_DWORD *)(a2 + 4),
                 *((_DWORD *)v18 + 4));
          v50 = *((_DWORD *)v18 + 4);
          if ( !v50 )
            goto LABEL_30;
        }
        else
        {
          v50 = *((_DWORD *)v18 + 4);
          if ( !v50 )
            goto LABEL_30;
        }
        if ( *(_DWORD *)(a2 + 4) > v50 )
        {
          if ( (debug_mdl & 0x200) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x200,
              4,
              "cam_jpeg_mgr_bottom_half_irq",
              492,
              "Thumbnail max size: %u dev_type: %u",
              v50,
              *(_DWORD *)v18);
          v51 = *(_DWORD *)(v4 + 64);
          v52 = *(_DWORD *)(v4 + 56);
          v53 = v18[1];
          LODWORD(v67) = *(_DWORD *)(v4 + 60);
          HIDWORD(v67) = v51;
          LODWORD(v66) = v52;
          v68 = 0x100000001LL;
          v69 = v53;
          cam_req_mgr_notify_message(&v66, 4, 0x8000000);
          if ( *(_DWORD *)(v9 + 48) )
          {
            v54 = 0;
            do
              cam_sync_put_obj_ref(*(_DWORD *)(*(_QWORD *)(v9 + 40) + ((__int64)(int)v54++ << 6) + 16));
            while ( v54 < *(_DWORD *)(v9 + 48) );
          }
          raw_spin_lock(v4 + 120);
          v55 = *(_QWORD *)(v4 + 128);
          if ( v55 != v4 + 128 )
          {
            cam_smmu_buffer_tracker_putref((unsigned int *)(v55 + 112));
            list_del_init_1((_QWORD *)v55);
            list_add_tail_2((_QWORD *)v55, (_QWORD *)(v4 + 176));
            v56 = *(_QWORD *)(v55 + 136);
            if ( v56 )
            {
              cam_common_mem_free(v56);
              *(_QWORD *)(v55 + 136) = 0;
            }
          }
          raw_spin_unlock(v4 + 120);
          goto LABEL_37;
        }
LABEL_30:
        v19 = *(unsigned int *)(v9 + 48);
        LODWORD(v74[0]) = v19;
        if ( (_DWORD)v19 )
        {
          v20 = v19 << 6;
          v21 = 0;
          v22 = (_DWORD *)v74 + 1;
          while ( v21 != 2304 )
          {
            v23 = *(_DWORD *)(*(_QWORD *)(v9 + 40) + v21);
            v21 += 64;
            *v22++ = v23;
            if ( v20 == v21 )
              goto LABEL_34;
          }
          goto LABEL_88;
        }
LABEL_34:
        v24 = v18[1];
        LODWORD(v60) = 0;
        v59 = v74;
        v75 = v24;
        v25 = (_DWORD *)v3[12];
        v26 = *v3;
        if ( *(v25 - 1) != 414296116 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD **))v25)(v26, 0, &v59);
LABEL_37:
        v27 = (char *)&g_jpeg_hw_mgr + 8 * v6;
        v62 = cam_jpeg_hw_mgr_sched_bottom_half;
        v63 = 0;
        v28 = *((__int64 **)v27 + 649);
        v64 = 0;
        LODWORD(v65) = 0;
        v29 = *v28;
        v30 = *(__int64 (__fastcall **)(__int64, __int64, __int64 (__fastcall **)(int, int, __int64), __int64))(*v28 + 88);
        if ( v30 )
        {
          v31 = *(_QWORD *)(v29 + 112);
          if ( *((_DWORD *)v30 - 1) != -1055839300 )
            __break(0x8228u);
          v32 = v30(v31, 1, &v62, 32);
          if ( v32 )
          {
            v33 = "CMD_SET_IRQ_CB failed %d";
            v34 = v32;
            v35 = 556;
LABEL_42:
            v36 = v34;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              512,
              1,
              "cam_jpeg_mgr_bottom_half_irq",
              v35,
              v33);
LABEL_55:
            mutex_unlock(&g_jpeg_hw_mgr);
            result = v36;
            goto LABEL_49;
          }
          v42 = **((_QWORD **)v27 + 649);
          v43 = *(_DWORD **)(v42 + 24);
          if ( v43 )
          {
            v44 = *(_QWORD *)(v42 + 112);
            if ( *(v43 - 1) != 1989616049 )
              __break(0x8228u);
            if ( ((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD))v43)(v44, 0, 0) )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                512,
                1,
                "cam_jpeg_mgr_bottom_half_irq",
                564,
                "Failed to Deinit %lu HW",
                v6);
          }
          v45 = qword_3AA0A0;
          dword_3AA120[v6] = 0;
          qword_3AA128[v6] = 0;
          task = cam_req_mgr_workq_get_task(v45);
          if ( task )
          {
            v47 = *((_QWORD *)task + 1);
            *(_QWORD *)(v47 + 8) = 0;
            *(_QWORD *)(v47 + 16) = 0;
            *(_DWORD *)v47 = 1;
            *((_QWORD *)task + 2) = cam_jpeg_mgr_process_hw_update_entries;
            v48 = cam_req_mgr_workq_enqueue_task((unsigned int *)task, (__int64)&g_jpeg_hw_mgr, 0);
            if ( !v48 )
            {
              cam_jpeg_mgr_move_req_to_free_list(v9);
              v36 = 0;
              goto LABEL_55;
            }
            v33 = "could not enque task %d";
            v34 = v48;
            v35 = 591;
            goto LABEL_42;
          }
          v40 = "no empty task";
          v41 = 572;
        }
        else
        {
          v40 = "process_cmd null";
          v41 = 547;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_mgr_bottom_half_irq",
          v41,
          v40);
        v36 = -22;
        goto LABEL_55;
      }
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_bottom_half_irq",
      422,
      "irq for old request %d",
      0);
    mutex_unlock(&g_jpeg_hw_mgr);
LABEL_48:
    result = 4294967274LL;
LABEL_49:
    _ReadStatusReg(SP_EL0);
    return result;
  }
LABEL_88:
  __break(0x5512u);
LABEL_89:
  __break(1u);
  return cam_jpeg_mgr_flush(v8);
}
