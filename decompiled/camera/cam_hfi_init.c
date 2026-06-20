__int64 __fastcall cam_hfi_init(unsigned int a1, unsigned int *a2, __int64 *a3, const void *a4, unsigned __int8 a5)
{
  __int64 v6; // x19
  __int64 v11; // x8
  unsigned int v12; // w11
  unsigned int v13; // w11
  unsigned int v14; // w10
  unsigned int v15; // w21
  __int64 (__fastcall *v17)(_QWORD); // x8
  __int64 v18; // x9
  __int64 v19; // x10
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x22
  __int64 v22; // x0
  int v23; // w8
  __int64 v24; // x1
  __int64 v25; // x0
  int v26; // w0
  int v27; // w8
  void (__fastcall *v28)(_QWORD); // x8
  __int64 v29; // x0
  __int64 v30; // x0
  int v31; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+28h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  if ( a1 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      82,
      "Invalid HFI index: %u from hdl:%d",
      a1,
      a1);
    v15 = -22;
LABEL_12:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "cam_hfi_init",
      1074,
      "Failed to get hfi info rc: %d for hdl %d",
      v15,
      a1);
    goto LABEL_13;
  }
  v6 = *(_QWORD *)&g_hfi[2 * a1 + 2];
  if ( !v6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      89,
      "[%s] HFI interface not setup for client hdl: %d",
      byte_3EC,
      a1);
    v15 = -19;
    goto LABEL_12;
  }
  if ( !a2 || !a3 || !a4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "cam_hfi_init",
      1081,
      "[%s] Invalid arg: hfi_mem=%pK hfi_ops=%pK priv=%pK hfi hdl:%d",
      (const char *)(v6 + 1004),
      a2,
      a3,
      a4,
      a1);
    v15 = -22;
    goto LABEL_13;
  }
  mutex_lock(v6 + 832);
  mutex_lock(v6 + 880);
  mutex_lock(v6 + 928);
  *(_BYTE *)(v6 + 976) = 1;
  memcpy((void *)v6, a2, 0x120u);
  v11 = *((_QWORD *)a2 + 1);
  *(_QWORD *)v11 = 0xF08FFFFFFFFLL;
  *(_QWORD *)(v11 + 8) = 0x3BC00000018LL;
  *(_QWORD *)(v11 + 16) = 0x300000003LL;
  *(_DWORD *)(v11 + 84) = 1;
  v12 = a2[10];
  *(_DWORD *)(v11 + 276) = 2048;
  *(_DWORD *)(v11 + 340) = 0;
  *(_DWORD *)(v11 + 148) = v12;
  *(_DWORD *)(v11 + 404) = 0;
  *(_DWORD *)(v11 + 852) = 0;
  *(_DWORD *)(v11 + 916) = 0;
  *(_DWORD *)(v11 + 1040) = 1;
  v13 = a2[16];
  *(_DWORD *)(v11 + 1232) = 2048;
  *(_DWORD *)(v11 + 1296) = 0;
  *(_DWORD *)(v11 + 1104) = v13;
  *(_DWORD *)(v11 + 1360) = 0;
  *(_DWORD *)(v11 + 1808) = 0;
  *(_DWORD *)(v11 + 1872) = 0;
  *(_DWORD *)(v11 + 1996) = 1;
  v14 = a2[22];
  *(_DWORD *)(v11 + 2252) = 0;
  *(_DWORD *)(v11 + 2316) = 0;
  *(_DWORD *)(v11 + 2060) = v14;
  *(_DWORD *)(v11 + 2188) = 25600;
  *(_DWORD *)(v11 + 2764) = 0;
  *(_DWORD *)(v11 + 2828) = 0;
  **((_DWORD **)a2 + 13) = 4096;
  if ( a5 == 2 )
  {
    *(_DWORD *)(v11 + 212) = 33685504;
    *(_DWORD *)(v11 + 1168) = 33685505;
    *(_DWORD *)(v11 + 2124) = 33685506;
  }
  else
  {
    if ( a5 == 1 )
    {
      *(_DWORD *)(v11 + 468) = 1;
      *(_DWORD *)(v11 + 212) = 16842752;
      *(_DWORD *)(v11 + 532) = 1;
      *(_DWORD *)(v11 + 1168) = 16842753;
      *(_DWORD *)(v11 + 596) = 0;
      *(_DWORD *)(v11 + 660) = 1;
      *(_DWORD *)(v11 + 724) = 0;
      *(_DWORD *)(v11 + 788) = 0;
      *(_DWORD *)(v11 + 1424) = 1;
      *(_DWORD *)(v11 + 1488) = 1;
      *(_DWORD *)(v11 + 1552) = 1;
      *(_DWORD *)(v11 + 1616) = 0;
      *(_DWORD *)(v11 + 1680) = 0;
      *(_DWORD *)(v11 + 1744) = 0;
      *(_DWORD *)(v11 + 2124) = 16842754;
      *(_DWORD *)(v11 + 2380) = 1;
    }
    else
    {
      if ( a5 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000,
          1,
          "cam_hfi_init",
          1202,
          "[%s] Invalid event driven mode :%u for hdl:%d",
          (const char *)(v6 + 1004),
          a5,
          a1);
        goto LABEL_19;
      }
      *(_DWORD *)(v11 + 212) = 0;
      *(_DWORD *)(v11 + 468) = 1;
      *(_DWORD *)(v11 + 532) = 1;
      *(_DWORD *)(v11 + 596) = 1;
      *(_DWORD *)(v11 + 660) = 0;
      *(_DWORD *)(v11 + 724) = 0;
      *(_DWORD *)(v11 + 788) = 0;
      *(_DWORD *)(v11 + 1168) = 1;
      *(_DWORD *)(v11 + 1424) = 1;
      *(_DWORD *)(v11 + 1488) = 1;
      *(_DWORD *)(v11 + 1552) = 1;
      *(_DWORD *)(v11 + 1616) = 0;
      *(_DWORD *)(v11 + 1680) = 0;
      *(_DWORD *)(v11 + 1744) = 0;
      *(_DWORD *)(v11 + 2124) = 2;
      *(_DWORD *)(v11 + 2380) = 1;
    }
    *(_DWORD *)(v11 + 2508) = 0;
    *(_DWORD *)(v11 + 2444) = 1024;
    *(_DWORD *)(v11 + 2572) = 0;
    *(_DWORD *)(v11 + 2636) = 0;
    *(_DWORD *)(v11 + 2700) = 0;
  }
LABEL_19:
  v18 = a3[1];
  v17 = (__int64 (__fastcall *)(_QWORD))a3[2];
  v19 = *a3;
  *(_QWORD *)(v6 + 984) = a4;
  *(_QWORD *)(v6 + 296) = v18;
  *(_QWORD *)(v6 + 304) = v17;
  *(_QWORD *)(v6 + 288) = v19;
  if ( !v17 )
    goto LABEL_40;
  if ( *((_DWORD *)v17 - 1) != -1437795666 )
    __break(0x8228u);
  v20 = v17(a4);
  if ( v20 > 0xFFFFFFFFFFFFF000LL || (v21 = v20) == 0 )
  {
LABEL_40:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "cam_hfi_init",
      1212,
      "[%s] Invalid HFI interface address for hdl: %d",
      (const char *)(v6 + 1004),
      a1);
    v15 = -22;
    goto LABEL_41;
  }
  cam_io_w_mb(a2[4], v20 + 24);
  cam_io_w_mb(a2[28], v21 + 40);
  cam_io_w_mb(a2[40], v21 + 16);
  cam_io_w_mb(a2[36], v21 + 20);
  cam_io_w_mb(a2[34], v21 + 28);
  cam_io_w_mb(a2[30], v21 + 32);
  cam_io_w_mb(a2[46], v21 + 44);
  cam_io_w_mb(a2[42], v21 + 48);
  cam_io_w_mb(a2[52], v21 + 52);
  cam_io_w_mb(a2[48], v21 + 56);
  cam_io_w_mb(a2[58], v21 + 60);
  cam_io_w_mb(a2[54], v21 + 64);
  cam_io_w_mb(a2[64], v21 + 68);
  cam_io_w_mb(a2[60], v21 + 72);
  cam_io_w_mb(a2[70], v21 + 76);
  v22 = cam_io_w_mb(a2[66], v21 + 80);
  v23 = debug_priority;
  v24 = debug_mdl & 0x40000;
  if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
  {
    v22 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v24,
            4,
            "cam_hfi_init",
            1251,
            "[%s] HFI handle: %d",
            (const char *)(v6 + 1004),
            a1);
    v23 = debug_priority;
    v24 = debug_mdl & 0x40000;
    if ( (debug_mdl & 0x40000) == 0 )
      goto LABEL_29;
  }
  else if ( !v24 )
  {
    goto LABEL_29;
  }
  if ( !v23 )
  {
    v22 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v24,
            4,
            "cam_hfi_init",
            1255,
            "IO1 : [0x%x 0x%x] IO2 [0x%x 0x%x]",
            a2[52],
            *((_QWORD *)a2 + 24),
            a2[58],
            *((_QWORD *)a2 + 27));
    v23 = debug_priority;
    v24 = debug_mdl & 0x40000;
  }
LABEL_29:
  if ( v24 && !v23 )
  {
    v22 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v24,
            4,
            "cam_hfi_init",
            1259,
            "FwUncached : [0x%x 0x%x] Shared [0x%x 0x%x]",
            a2[64],
            *((_QWORD *)a2 + 30),
            a2[40],
            *((_QWORD *)a2 + 18));
    v23 = debug_priority;
    v24 = debug_mdl & 0x40000;
    if ( (debug_mdl & 0x40000) == 0 )
      goto LABEL_34;
  }
  else if ( !v24 )
  {
    goto LABEL_34;
  }
  if ( !v23 )
  {
    v22 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v24,
            4,
            "cam_hfi_init",
            1263,
            "SecHeap : [0x%x 0x%x] QDSS [0x%x 0x%x]",
            a2[34],
            *((_QWORD *)a2 + 15),
            a2[46],
            *((_QWORD *)a2 + 21));
    v23 = debug_priority;
    v24 = debug_mdl & 0x40000;
  }
LABEL_34:
  if ( v24 && !v23 )
  {
    v30 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v24,
            4,
            "cam_hfi_init",
            1268,
            "QTbl : [0x%x 0x%x] Sfr [0x%x 0x%x] Device [0x%x 0x%x]",
            a2[4],
            *(_QWORD *)a2,
            a2[28],
            *((_QWORD *)a2 + 12),
            a2[70],
            *((_QWORD *)a2 + 33));
    if ( (cam_presil_mode_enabled(v30) & 1) == 0 )
      goto LABEL_38;
    goto LABEL_37;
  }
  if ( (cam_presil_mode_enabled(v22) & 1) != 0 )
LABEL_37:
    cam_presil_send_buffer(0, 0, 0, *a2, a2[4], *((_QWORD *)a2 + 1), 1);
LABEL_38:
  v25 = cam_io_w_mb(1, v21 + 8);
  cam_presil_mode_enabled(v25);
  if ( (unsigned int)cam_common_read_poll_timeout((const void *)(v21 + 12), 0xAu, 1500000, 0xFFFFFFFF, 1, &v31) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "cam_hfi_init",
      1293,
      "[%s] hfi hdl:%u response poll timed out: status=0x%08x",
      (const char *)(v6 + 1004),
      a1,
      v31);
    v15 = -110;
LABEL_41:
    mutex_unlock(v6 + 928);
    mutex_unlock(v6 + 880);
    mutex_unlock(v6 + 832);
    goto LABEL_13;
  }
  v26 = cam_io_r(v21 + 4);
  v27 = debug_mdl;
  *(_DWORD *)(v6 + 1000) = v26;
  if ( (v27 & 0x40000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      *(_QWORD *)&v27 & 0x40000LL,
      4,
      "cam_hfi_init",
      1300,
      "[%s] ICP fw version: 0x%x",
      (const char *)(v6 + 1004),
      v26);
  v28 = *(void (__fastcall **)(_QWORD))(v6 + 296);
  *(_WORD *)(v6 + 1036) = 257;
  *(_BYTE *)(v6 + 1038) = 1;
  *(_BYTE *)(v6 + 976) = 2;
  if ( v28 )
  {
    v29 = *(_QWORD *)(v6 + 984);
    if ( *((_DWORD *)v28 - 1) != 251140989 )
      __break(0x8228u);
    v28(v29);
  }
  mutex_unlock(v6 + 928);
  mutex_unlock(v6 + 880);
  mutex_unlock(v6 + 832);
  v15 = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v15;
}
