__int64 __fastcall cam_ife_csid_ver1_process_cmd(__int64 a1, int a2, _DWORD *a3)
{
  __int64 *v3; // x8
  __int64 result; // x0
  __int64 *v5; // x20
  unsigned int v6; // w9
  int v7; // w8
  int v8; // w10
  char v9; // w11
  bool v10; // cf
  __int64 v11; // x13
  __int64 v12; // x10
  unsigned int v13; // w9
  __int64 v14; // x7
  __int64 *v15; // x19
  _DWORD *v16; // x21
  char *v17; // x6
  unsigned __int64 v18; // x7
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x10
  __int64 v21; // x21
  unsigned int v22; // w9
  __int64 *v23; // x9
  __int64 v24; // x19
  __int64 *v25; // x20
  __int64 v26; // x10
  _DWORD *v27; // x8
  __int64 v28; // x21
  _DWORD *v29; // x22
  __int64 v30; // x9
  __int64 v31; // x21
  int v32; // w0
  __int64 v33; // x8
  int v34; // w19
  __int64 v35; // x19
  unsigned int v36; // w9
  __int64 v37; // x9
  __int64 *v38; // x21
  _DWORD *v39; // x22
  __int64 *v40; // x8
  __int64 v41; // x8
  __int64 v42; // x23
  unsigned int v43; // w0
  __int64 v44; // x8
  unsigned int v45; // w19
  unsigned __int64 v46; // x9
  __int64 v47; // x0
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x9
  const char *v50; // x5
  __int64 v51; // x6
  __int64 v52; // x4
  char *v53; // x19
  _DWORD *v54; // x20
  unsigned __int64 v55; // x9
  __int64 v56; // x8
  char *v57; // x23
  unsigned __int64 v58; // x24
  int v59; // w25
  __int64 v60; // x8
  __int64 v61; // x9
  char v62; // w8
  __int64 (*v63)(void); // x8
  unsigned __int64 v64; // x11
  char v65; // w9
  unsigned int v66; // w20
  _DWORD *v67; // x19
  int v68; // [xsp+8h] [xbp-48h]

  if ( a1 && a3 )
  {
    v3 = *(__int64 **)(a1 + 3680);
    result = 0;
    v5 = v3 + 3072;
    switch ( a2 )
    {
      case 21:
        if ( !v3 )
          return 4294967274LL;
        v3[3548] = *(_QWORD *)a3;
        return 0;
      case 27:
        return cam_ife_csid_ver1_set_csid_qcfa(v3, a3);
      case 33:
        v17 = *((char **)a3 + 1);
        v18 = *((_QWORD *)a3 + 2);
        if ( !v17 || !v18 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_csid_ver1_dump_hw",
            3640,
            "Invalid params %pK %zu",
            v17,
            v18);
          return 4294967274LL;
        }
        v19 = *((_QWORD *)a3 + 3);
        v20 = v18 - v19;
        if ( v18 <= v19 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64))cam_print_log)(
            3,
            8,
            2,
            "cam_ife_csid_ver1_dump_hw",
            3647,
            "Dump offset overshoot offset %zu buf_len %zu",
            v19);
          return 4294967268LL;
        }
        else
        {
          v21 = v3[1];
          if ( v20 >= (unsigned int)(*(_DWORD *)(v21 + 400) + 148) )
          {
            v53 = &v17[v19];
            v54 = a3;
            scnprintf(&v17[v19], 128, "CSID_REG:");
            v55 = *(_QWORD *)(v21 + 400);
            v56 = 4;
            *((_DWORD *)v53 + 34) = 4;
            v57 = v53 + 148;
            v58 = v55 >> 2;
            *((_DWORD *)v53 + 36) = *(_DWORD *)(v21 + 116);
            if ( (unsigned int)(v55 >> 2) )
            {
              v59 = 0;
              do
              {
                *(_DWORD *)v57 = v59 + **(_DWORD **)(v21 + 320);
                LODWORD(v58) = v58 - 1;
                *((_DWORD *)v57 + 1) = cam_io_r(*(_QWORD *)(v21 + 384) + v59);
                v57 += 8;
                v59 += 4;
              }
              while ( (_DWORD)v58 );
              v56 = *((unsigned int *)v53 + 34);
            }
            result = 0;
            v60 = ((v57 - (v53 + 144)) >> 2) * v56;
            *((_QWORD *)v53 + 16) = v60;
            v61 = *((_QWORD *)v54 + 3) + v60;
            v62 = debug_mdl;
            *((_QWORD *)v54 + 3) = v61 + 144;
            if ( (v62 & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v62 & 8,
                4,
                "cam_ife_csid_ver1_dump_hw",
                3678,
                "offset %zu",
                v61 + 144);
              return 0;
            }
          }
          else
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64))cam_print_log)(
              3,
              8,
              2,
              "cam_ife_csid_ver1_dump_hw",
              3656,
              "Dump buffer exhaust remain %zu, min %u",
              v20);
            return 4294967268LL;
          }
        }
        return result;
      case 40:
        if ( !v3 )
          return 4294967274LL;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "cam_ife_csid_ver1_dump_csid_clock",
          3740,
          "CSID:%d clock rate %llu",
          *(_DWORD *)(*v3 + 4),
          v3[3548]);
        return 0;
      case 42:
        return cam_ife_csid_halt(v3, (__int64)a3);
      case 45:
        v12 = *(_QWORD *)a3;
        v13 = **(_DWORD **)a3;
        if ( v13 != 3 || (v14 = *(unsigned int *)(v12 + 4), (unsigned int)v14 >= 0xC) )
        {
          v15 = v3;
          result = 4294967274LL;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v16 = a3;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_csid_ver1_get_time_stamp",
              3494,
              "CSID:%d Invalid res_type:%d res id%d",
              *(unsigned int *)(*v3 + 4),
              v13,
              *(_DWORD *)(v12 + 4));
LABEL_64:
            a3 = v16;
            result = 4294967274LL;
            goto LABEL_82;
          }
          goto LABEL_82;
        }
        v35 = v3[1];
        v36 = *(_DWORD *)(v35 + 92);
        if ( v36 == 1 )
        {
          v37 = *(_QWORD *)v3[2];
          if ( (unsigned int)v14 < 5 )
          {
            v38 = v3;
            v39 = a3;
            v40 = (__int64 *)(v37 + 8 * v14 + 24);
LABEL_59:
            v41 = *v40;
            v42 = *(unsigned int *)(v41 + 120);
            v43 = cam_io_r_mb(*(_QWORD *)(v35 + 384) + *(unsigned int *)(v41 + 124));
            v44 = *(_QWORD *)(v35 + 384);
            v45 = v43;
            v46 = 10000LL * (unsigned int)cam_io_r_mb(v44 + v42);
            a3 = v39;
            v47 = g_ref_time;
            v48 = (((unsigned __int64)(HIDWORD(v46) + 10000LL * v45) / 0xC0) << 32)
                | (unsigned int)((unsigned __int64)((((unsigned int)v46 & 0xFFFFFFC0
                                                    | (((unsigned __int64)(HIDWORD(v46) + 10000LL * v45) % 0xC0) << 32))
                                                   * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
            *((_QWORD *)v39 + 1) = v48;
            if ( v47 )
            {
              v49 = qword_394728;
            }
            else
            {
              v63 = (__int64 (*)(void))arch_timer_read_counter;
              if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
                __break(0x8228u);
              qword_394728 = v63();
              v47 = ktime_get_with_offset(1);
              a3 = v39;
              v49 = (((((10000 * (unsigned __int64)(unsigned int)qword_394728) >> 32) + 10000LL * HIDWORD(qword_394728))
                    / 0xC0) << 32)
                  | (unsigned int)((unsigned __int64)((((10000LL * (unsigned int)qword_394728) & 0xFFFFFFC0LL
                                                      | (((((10000 * (unsigned __int64)(unsigned int)qword_394728) >> 32)
                                                         + 10000LL * HIDWORD(qword_394728))
                                                        % 0xC0) << 32))
                                                     * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
              g_ref_time = v47;
              qword_394728 = v49;
              v48 = *((_QWORD *)v39 + 1);
            }
            v64 = v48 - v49;
            v65 = debug_mdl;
            *((_QWORD *)a3 + 2) = v64 + v47;
            if ( (v65 & 8) != 0 && !debug_priority )
            {
              v67 = a3;
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v65 & 8,
                4,
                "cam_ife_csid_ver1_get_time_stamp",
                3553,
                "timestamp:%lld",
                v64 + v47);
              v48 = *((_QWORD *)v67 + 1);
              a3 = v67;
            }
            v38[3547] = v48;
            result = 0;
            v15 = v38;
            v38[3546] = *((_QWORD *)a3 + 2);
LABEL_82:
            if ( (*((_BYTE *)v5 + 3756) & 0x80) != 0 )
            {
              v66 = result;
              cam_ife_csid_ver1_print_hbi_vbi(v15, *(_QWORD *)a3);
              return v66;
            }
            return result;
          }
          if ( (_DWORD)v14 == 6 )
          {
            v38 = v3;
            v39 = a3;
            v40 = (__int64 *)(v37 + 16);
            goto LABEL_59;
          }
          if ( (_DWORD)v14 == 5 )
          {
            v38 = v3;
            v39 = a3;
            v40 = (__int64 *)(v37 + 8);
            goto LABEL_59;
          }
          v15 = v3;
          v50 = "CSID:%d invalid res %d";
          v51 = *(unsigned int *)(*v3 + 4);
          v16 = a3;
          v52 = 3528;
        }
        else
        {
          v15 = v3;
          v50 = "CSID:%d Invalid dev state :%d";
          v51 = *(unsigned int *)(*v3 + 4);
          v16 = a3;
          v52 = 3501;
          v14 = v36;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_get_time_stamp",
          v52,
          v50,
          v51,
          v14);
        goto LABEL_64;
      case 46:
        v6 = *a3;
        v3[3545] = 0;
        v3[3544] = 0;
        v3[3543] = 0;
        v3[3542] = 0;
        *((_DWORD *)v3 + 7083) = v6;
        if ( !v6 )
          return 0;
        v7 = 0;
        v8 = 0;
        v9 = 0;
        break;
      case 47:
        cam_ife_csid_ver1_sof_irq_debug(v3, a3);
        return 0;
      case 49:
        v22 = a3[2];
        if ( v22 > 1 )
        {
          v24 = v3[1];
          v23 = (__int64 *)v3[2];
          v25 = v3;
          v26 = *v3;
          v27 = *((_DWORD **)a3 + 3);
          v28 = *v23;
          v29 = a3;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            3,
            "cam_ife_csid_log_acquire_data",
            3713,
            "CSID:%d res id:%d type:%d state:%d in f:%d out f:%d st pix:%d end pix:%d st line:%d end line:%d h bin:%d qcfa bin:%d",
            *(_DWORD *)(v26 + 4),
            a3[1],
            *a3,
            *a3,
            v27[1],
            v27[2],
            v27[3],
            v27[4],
            v27[6],
            v27[7],
            v27[10],
            v27[12]);
          v30 = (unsigned int)v29[1];
          if ( (unsigned int)v30 <= 3 )
          {
            v31 = *(_QWORD *)(v28 + 8 * v30 + 24);
            v32 = cam_io_r_mb(*(_QWORD *)(v24 + 384) + *(unsigned int *)(v31 + 168));
            v33 = *(_QWORD *)(v24 + 384);
            v34 = v32;
            v68 = cam_io_r_mb(v33 + *(unsigned int *)(v31 + 172));
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, int))cam_print_log)(
              3,
              8,
              3,
              "cam_ife_csid_log_acquire_data",
              3726,
              "CSID:%d res id:%d byte cnt val ping:%d pong:%d",
              *(unsigned int *)(*v25 + 4),
              (unsigned int)v29[1],
              v34,
              v68);
          }
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, unsigned int))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_csid_log_acquire_data",
            3701,
            "CSID:%d invalid res id:%d res type: %d state:%d",
            *(unsigned int *)(*v3 + 4),
            (unsigned int)a3[1],
            *a3,
            v22);
        }
        return 0;
      case 50:
      case 52:
      case 53:
      case 55:
      case 73:
      case 74:
        return result;
      default:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_process_cmd",
          3820,
          "CSID:%d unsupported cmd:%d",
          *(unsigned int *)(*v3 + 4));
        return 4294967274LL;
    }
    while ( 1 )
    {
      if ( (v6 & 1) != 0 )
      {
        v11 = 1LL << v9;
        if ( (int)(1LL << v9) > 15 )
        {
          if ( (int)v11 > 63 )
          {
            if ( (_DWORD)v11 == 64 )
            {
              v8 |= 0x400u;
            }
            else
            {
              if ( (_DWORD)v11 != 512 )
                goto LABEL_13;
              v8 |= 0x400000u;
            }
          }
          else if ( (_DWORD)v11 == 16 )
          {
            v8 |= 0x200u;
          }
          else
          {
            if ( (_DWORD)v11 != 32 )
              goto LABEL_13;
            v8 |= 0x100u;
          }
        }
        else
        {
          if ( (int)v11 <= 3 )
          {
            if ( (_DWORD)v11 == 1 )
            {
              v7 |= 0x1000u;
              *((_DWORD *)v5 + 945) = v7;
            }
            else if ( (_DWORD)v11 == 2 )
            {
              v7 |= 0x200u;
              *((_DWORD *)v5 + 945) = v7;
            }
            goto LABEL_13;
          }
          if ( (_DWORD)v11 == 4 )
          {
            v8 |= 0x70u;
          }
          else
          {
            if ( (_DWORD)v11 != 8 )
              goto LABEL_13;
            v8 |= 7u;
          }
        }
        *((_DWORD *)v5 + 944) = v8;
      }
LABEL_13:
      result = 0;
      v10 = v6 >= 2;
      ++v9;
      v6 >>= 1;
      if ( !v10 )
        return result;
    }
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver1_process_cmd",
    3754,
    "CSID: Invalid arguments");
  return 4294967274LL;
}
