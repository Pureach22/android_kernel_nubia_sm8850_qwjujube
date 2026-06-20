__int64 __fastcall cam_context_dump_dev_to_hw(__int64 a1, __int64 *a2)
{
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x9
  unsigned __int64 v7; // x22
  unsigned int v8; // w20
  unsigned int cpu_buf; // w0
  unsigned int v10; // w22
  __int64 result; // x0
  __int64 v12; // x7
  unsigned __int64 v13; // x6
  const char *v14; // x5
  __int64 v15; // x4
  __int64 v16; // x23
  __int64 v17; // x8
  int v18; // w9
  int v19; // w13
  int v20; // w11
  int v21; // w12
  int v22; // w14
  int v23; // w15
  unsigned __int64 v24; // x24
  __int64 *v25; // x27
  unsigned int v26; // w28
  _DWORD *v27; // x8
  __int64 v28; // x23
  __int64 v29; // x9
  unsigned int v30; // w8
  __int64 *v31; // x27
  unsigned int v32; // w28
  _DWORD *v33; // x8
  __int64 v34; // x23
  __int64 v35; // x9
  unsigned int v36; // w8
  __int64 v37; // x4
  char v38; // w23
  const char *v39; // x5
  __int64 v40; // x4
  __int64 *v41; // x27
  int v42; // w8
  unsigned int v43; // w28
  _DWORD *v44; // x8
  __int64 v45; // x23
  __int64 v46; // x9
  unsigned int v47; // w8
  __int64 *v48; // x8
  __int64 (__fastcall *v49)(__int64, __int64 *); // x9
  __int64 v50; // x0
  unsigned int v51; // w0
  unsigned int v52; // w20
  __int64 *v53; // [xsp+10h] [xbp-40h]
  __int64 *v54; // [xsp+10h] [xbp-40h]
  __int64 *v55; // [xsp+10h] [xbp-40h]
  __int64 v56; // [xsp+18h] [xbp-38h] BYREF
  unsigned __int64 v57; // [xsp+20h] [xbp-30h]
  unsigned int v58; // [xsp+28h] [xbp-28h]
  int v59; // [xsp+2Ch] [xbp-24h]
  __int64 v60; // [xsp+30h] [xbp-20h]
  __int64 v61; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v62[2]; // [xsp+40h] [xbp-10h] BYREF

  v62[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(a1 + 208);
    if ( v4 )
    {
      if ( *(_QWORD *)(v4 + 136) )
      {
        v5 = *(_QWORD *)(a1 + 264);
        v6 = *a2;
        v7 = a2[1];
        v61 = 0;
        v62[0] = 0;
        v60 = v5;
        v8 = *((_DWORD *)a2 + 4);
        LODWORD(v5) = *((_DWORD *)a2 + 5);
        v56 = v6;
        v58 = v8;
        v59 = v5;
        cpu_buf = cam_mem_get_cpu_buf(v8, &v61, v62);
        if ( cpu_buf )
        {
          v10 = cpu_buf;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            0x80000,
            1,
            "cam_context_user_dump",
            1605,
            "Invalid hdl %u rc %d",
            v8);
LABEL_18:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x80000,
            1,
            "cam_context_dump_dev_to_hw",
            1803,
            "[%s][%d] handle[%u] failed",
            (const char *)a1,
            *(_DWORD *)(a1 + 32),
            v8);
          result = v10;
          goto LABEL_19;
        }
        v12 = v62[0];
        v13 = v62[0] - v7;
        if ( v62[0] <= v7 )
        {
          v14 = "dump buffer overshoot offset %zu len %zu";
          v15 = 1611;
          v13 = v7;
          goto LABEL_16;
        }
        if ( v13 <= 0x8F )
        {
          v14 = "No sufficient space in dump buffer for headers, remain buf size: %d, header size: %d";
          v15 = 1621;
          v12 = 144;
LABEL_16:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, __int64))cam_print_log)(
            3,
            0x80000,
            2,
            "cam_context_user_dump",
            v15,
            v14,
            v13,
            v12);
LABEL_17:
          cam_mem_put_cpu_buf(v8);
          v10 = -28;
          goto LABEL_18;
        }
        v16 = v61 + v7;
        scnprintf(v61 + v7, 128, "%s_CTX_INFO:", (const char *)a1);
        *(_DWORD *)(v16 + 136) = 8;
        v17 = *(_QWORD *)(a1 + 24);
        v19 = *(_DWORD *)(a1 + 60);
        v18 = *(_DWORD *)(a1 + 64);
        v20 = *(_DWORD *)(a1 + 56);
        v21 = *(_DWORD *)(a1 + 404);
        if ( (unsigned int)(v7 + 176) >= LODWORD(v62[0]) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x80000,
            1,
            "cam_context_dump_data_validaion",
            1553,
            "actual len %pK base len %pK",
            (const void *)LODWORD(v62[0]),
            (const void *)(unsigned int)(v7 + 144));
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x80000,
            2,
            "cam_context_stream_dump_validation",
            1576,
            "failed to copy the stream info");
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x80000,
            2,
            "cam_context_user_dump",
            1636,
            "%s_CTX_INFO failed to copy the stream info ",
            (const char *)a1);
          goto LABEL_17;
        }
        v22 = *(_DWORD *)(a1 + 240);
        v23 = *(_DWORD *)(a1 + 464);
        v24 = v7 + 176;
        *(_DWORD *)(v16 + 144) = *(_DWORD *)(a1 + 272);
        *(_DWORD *)(v16 + 148) = v17;
        *(_DWORD *)(v16 + 152) = v19;
        *(_DWORD *)(v16 + 156) = v18;
        *(_DWORD *)(v16 + 160) = v20;
        *(_DWORD *)(v16 + 164) = v21;
        *(_DWORD *)(v16 + 168) = v23;
        *(_DWORD *)(v16 + 172) = v22;
        *(_QWORD *)(v16 + 128) = 32;
        v57 = v7 + 176;
        raw_spin_lock(a1 + 120);
        v25 = *(__int64 **)(a1 + 160);
        if ( v25 != (__int64 *)(a1 + 160) )
        {
          while ( 1 )
          {
            v53 = (__int64 *)*v25;
            if ( *((_DWORD *)v25 + 20) )
              break;
LABEL_24:
            v25 = v53;
            if ( v53 == (__int64 *)(a1 + 160) )
              goto LABEL_31;
          }
          v26 = 0;
          while ( v62[0] - v24 > 0x8F )
          {
            v27 = (_DWORD *)(v25[9] + ((__int64)(int)v26 << 6));
            v28 = v61 + v24;
            scnprintf(
              v61 + v24,
              128,
              "%s_OUT_FENCE_REQUEST_APPLIED.%d.%pad.%d:",
              (const char *)a1,
              *v27,
              v27 + 8,
              v27[4]);
            *(_DWORD *)(v28 + 136) = 8;
            if ( (unsigned int)(v24 + 152) >= LODWORD(v62[0]) )
            {
              v38 = 1;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x80000,
                1,
                "cam_context_dump_data_validaion",
                1553,
                "actual len %pK base len %pK",
                (const void *)LODWORD(v62[0]),
                (const void *)(unsigned int)(v24 + 144));
              v39 = "%s_CTX_INFO waiting_req: failed to copy the request info";
              v40 = 1676;
              goto LABEL_57;
            }
            v29 = *(unsigned int *)(v28 + 136);
            ++v26;
            *(_QWORD *)(v28 + 144) = v25[3];
            *(_QWORD *)(v28 + 128) = v29;
            v30 = *((_DWORD *)v25 + 20);
            v24 += v29 + 144;
            v57 = v24;
            if ( v26 >= v30 )
              goto LABEL_24;
          }
          v37 = 1654;
LABEL_55:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x80000,
            2,
            "cam_context_user_dump",
            v37,
            "No sufficient space in dump buffer for headers, remain buf size: %d, header size: %d");
          v38 = 0;
          v42 = -28;
          goto LABEL_58;
        }
LABEL_31:
        v31 = *(__int64 **)(a1 + 144);
        if ( v31 == (__int64 *)(a1 + 144) )
        {
LABEL_42:
          v41 = *(__int64 **)(a1 + 128);
          if ( v41 == (__int64 *)(a1 + 128) )
          {
            v42 = 0;
            v38 = 1;
LABEL_58:
            v10 = v42;
            raw_spin_unlock(a1 + 120);
            cam_mem_put_cpu_buf(v8);
            if ( (v38 & 1) == 0 )
              goto LABEL_18;
            v48 = *(__int64 **)(a1 + 208);
            v49 = (__int64 (__fastcall *)(__int64, __int64 *))v48[17];
            v50 = *v48;
            if ( *((_DWORD *)v49 - 1) != 1863972096 )
              __break(0x8229u);
            v51 = v49(v50, &v56);
            if ( v51 )
            {
              v52 = v51;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x80000,
                1,
                "cam_context_dump_dev_to_hw",
                1812,
                "[%s][%d] handle[%u] failed",
                (const char *)a1,
                *(_DWORD *)(a1 + 32),
                v58);
              result = v52;
              goto LABEL_19;
            }
            if ( v57 > a2[1] )
            {
              result = 0;
              a2[1] = v57;
              goto LABEL_19;
            }
LABEL_65:
            result = 0;
            goto LABEL_19;
          }
          while ( 1 )
          {
            v55 = (__int64 *)*v41;
            if ( *((_DWORD *)v41 + 20) )
              break;
LABEL_44:
            v41 = v55;
            v42 = 0;
            v38 = 1;
            if ( v55 == (__int64 *)(a1 + 128) )
              goto LABEL_58;
          }
          v43 = 0;
          while ( 1 )
          {
            if ( v62[0] - v24 <= 0x8F )
            {
              v37 = 1738;
              goto LABEL_55;
            }
            v44 = (_DWORD *)(v41[9] + ((__int64)(int)v43 << 6));
            v45 = v61 + v24;
            scnprintf(
              v61 + v24,
              128,
              "%s_OUT_FENCE_REQUEST_ACTIVE.%d.%pad.%d:",
              (const char *)a1,
              *v44,
              v44 + 8,
              v44[4]);
            *(_DWORD *)(v45 + 136) = 8;
            if ( (unsigned int)(v24 + 152) >= LODWORD(v62[0]) )
              break;
            v46 = *(unsigned int *)(v45 + 136);
            ++v43;
            *(_QWORD *)(v45 + 144) = v41[3];
            *(_QWORD *)(v45 + 128) = v46;
            v47 = *((_DWORD *)v41 + 20);
            v24 += v46 + 144;
            v57 = v24;
            if ( v43 >= v47 )
              goto LABEL_44;
          }
          v38 = 1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x80000,
            1,
            "cam_context_dump_data_validaion",
            1553,
            "actual len %pK base len %pK",
            (const void *)LODWORD(v62[0]),
            (const void *)(unsigned int)(v24 + 144));
          v39 = "%s_CTX_INFO active_req: failed to copy the request info";
          v40 = 1760;
        }
        else
        {
          while ( 1 )
          {
            v54 = (__int64 *)*v31;
            if ( *((_DWORD *)v31 + 20) )
              break;
LABEL_33:
            v31 = v54;
            if ( v54 == (__int64 *)(a1 + 144) )
              goto LABEL_42;
          }
          v32 = 0;
          while ( 1 )
          {
            if ( v62[0] - v24 <= 0x8F )
            {
              v37 = 1696;
              goto LABEL_55;
            }
            v33 = (_DWORD *)(v31[9] + ((__int64)(int)v32 << 6));
            v34 = v61 + v24;
            scnprintf(
              v61 + v24,
              128,
              "%s_OUT_FENCE_REQUEST_PENDING.%d.%pad.%d:",
              (const char *)a1,
              *v33,
              v33 + 8,
              v33[4]);
            *(_DWORD *)(v34 + 136) = 8;
            if ( (unsigned int)(v24 + 152) >= LODWORD(v62[0]) )
              break;
            v35 = *(unsigned int *)(v34 + 136);
            ++v32;
            *(_QWORD *)(v34 + 144) = v31[3];
            *(_QWORD *)(v34 + 128) = v35;
            v36 = *((_DWORD *)v31 + 20);
            v24 += v35 + 144;
            v57 = v24;
            if ( v32 >= v36 )
              goto LABEL_33;
          }
          v38 = 1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x80000,
            1,
            "cam_context_dump_data_validaion",
            1553,
            "actual len %pK base len %pK",
            (const void *)LODWORD(v62[0]),
            (const void *)(unsigned int)(v24 + 144));
          v39 = "%s_CTX_INFO pending_req: failed to copy the request info";
          v40 = 1718;
        }
LABEL_57:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          0x80000,
          2,
          "cam_context_user_dump",
          v40,
          v39,
          a1);
        v42 = 0;
        goto LABEL_58;
      }
      result = 0;
      if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x80000,
          4,
          "cam_context_dump_dev_to_hw",
          1821,
          "%s hw dump not registered",
          (const char *)a1);
        goto LABEL_65;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        1,
        "cam_context_dump_dev_to_hw",
        1789,
        "[%s][%d] HW interface is not ready",
        (const char *)a1,
        *(_DWORD *)(a1 + 32));
      result = 4294967282LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_dump_dev_to_hw",
      1784,
      "Invalid input params %pK %pK",
      (const void *)a1,
      a2);
    result = 4294967274LL;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
