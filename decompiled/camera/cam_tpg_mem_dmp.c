__int64 __fastcall cam_tpg_mem_dmp(__int64 a1, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x0
  unsigned int v4; // w19
  const char *v5; // x5
  __int64 v6; // x4
  __int64 v7; // x6
  char v9; // w19
  __int64 v10; // x20
  __int64 v11; // x21

  if ( !a1 )
  {
    v5 = "invalid input %d";
    v6 = 26;
    v7 = 4294967274LL;
    v4 = -22;
    goto LABEL_8;
  }
  v2 = a1;
  v3 = *(_QWORD *)(a1 + 288);
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    v9 = a2;
    v10 = v3;
    v11 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "cam_tpg_mem_dmp",
      30,
      "TPG[%d] register dump",
      *(_DWORD *)(v2 + 20));
    v2 = v11;
    v3 = v10;
    a2 = v9;
  }
  v4 = cam_io_dump(
         v3,
         0,
         (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(v2 + 224) + 8LL) - **(_QWORD **)(v2 + 224) + 1LL) >> 2,
         0x200000000LL,
         a2 & 1);
  if ( (v4 & 0x80000000) != 0 )
  {
    v5 = "generating dump failed %d";
    v6 = 34;
    v7 = v4;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_mem_dmp",
      v6,
      v5,
      v7);
  }
  return v4;
}
