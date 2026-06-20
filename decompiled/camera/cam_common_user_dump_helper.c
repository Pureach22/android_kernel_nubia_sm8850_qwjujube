__int64 __fastcall cam_common_user_dump_helper(
        _QWORD *a1,
        __int64 (__fastcall *a2)(__int64, __int64),
        __int64 a3,
        __int64 a4,
        const char *a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  __int64 v9; // x6
  unsigned __int64 v10; // x7
  unsigned __int64 v11; // x8
  unsigned int v12; // w19
  const char *v13; // x5
  __int64 v14; // x4
  __int64 v16; // x20
  int v18; // w23
  __int64 v21; // x0
  __int64 v22; // x21
  unsigned __int64 v23; // x0
  __int64 v24; // x6
  _QWORD v25[4]; // [xsp+28h] [xbp-48h] BYREF
  char *v26; // [xsp+48h] [xbp-28h]
  _QWORD *v27; // [xsp+50h] [xbp-20h]
  __int64 v28; // [xsp+58h] [xbp-18h]
  __int64 v29; // [xsp+60h] [xbp-10h]
  __int64 v30; // [xsp+68h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v26 = nullptr;
  v27 = nullptr;
  if ( !a1 )
  {
    v13 = "dump_args is NULL!";
    v14 = 336;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_user_dump_helper",
      v14,
      v13);
    v12 = -22;
    goto LABEL_12;
  }
  v9 = a1[1];
  v10 = a1[2];
  if ( !v9 || !v10 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_user_dump_helper",
      343,
      "Invalid params: cpu_addr=%pk, buf_len=%zu",
      v9,
      v10);
    goto LABEL_8;
  }
  v11 = a1[3];
  if ( v10 <= v11 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_common_user_dump_helper",
      349,
      "Dump offset overshoot offset %zu buf_len %zu",
      v11);
    v12 = -28;
    goto LABEL_12;
  }
  if ( a4 + 144 + v11 > v10 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, _QWORD))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_user_dump_helper",
      358,
      "Insufficient buffer space: offset %zu, required %zu, buf_len %zu",
      a1[3],
      a4 + 144,
      a1[2]);
LABEL_8:
    v12 = -22;
    goto LABEL_12;
  }
  v16 = v9 + v11;
  v18 = a4;
  v29 = 4294967272LL;
  v26 = &a9;
  v27 = v25;
  v25[0] = &a9;
  v25[1] = v25;
  v25[2] = v28;
  v25[3] = 4294967272LL;
  vscnprintf(v9 + v11, 128, a5, v25);
  *(_DWORD *)(v16 + 136) = v18;
  if ( !a2 || (v21 = a3) == 0 )
  {
    v13 = "function ptr / dump struct is NULL";
    v14 = 375;
    goto LABEL_10;
  }
  v22 = v16 + 144;
  if ( *((_DWORD *)a2 - 1) != 1471526939 )
    __break(0x8233u);
  v23 = a2(v21, v16 + 144);
  v12 = v23;
  if ( v23 && v23 < 0xFFFFFFFFFFFFF001LL )
  {
    v24 = v23 - v22;
    *(_QWORD *)(v16 + 128) = v23 - v22;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_common_user_dump_helper",
        389,
        "hdr size: %d, word size: %d, addr: %x, start: %x",
        v24,
        *(_DWORD *)(v16 + 136),
        v23,
        v16 + 144);
      v24 = *(_QWORD *)(v16 + 128);
    }
    v12 = 0;
    a1[3] += v24 + 144;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_user_dump_helper",
      382,
      "function call failed!");
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v12;
}
