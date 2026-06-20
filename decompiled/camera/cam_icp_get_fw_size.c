__int64 __fastcall cam_icp_get_fw_size(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x20
  int v3; // w19
  int *v4; // x24
  int v5; // w6
  int v6; // w7
  int v7; // w8
  unsigned int v8; // w25
  unsigned int *v9; // x26
  const char *v10; // x5
  __int64 v11; // x4
  unsigned int *v12; // x21
  __int64 v13; // x24

  if ( !a1 || !a2 )
  {
    v10 = "invalid args";
    v11 = 56;
    goto LABEL_21;
  }
  *a2 = 0;
  v2 = *(unsigned int *)(a1 + 28);
  if ( !(a1 + v2) )
  {
    v10 = "failed to get elf program header attr";
    v11 = 68;
    goto LABEL_21;
  }
  v3 = *(unsigned __int16 *)(a1 + 44);
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    v12 = a2;
    v13 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_get_fw_size",
      72,
      "num_prg_hdrs = %d",
      v3);
    a1 = v13;
    a2 = v12;
    if ( v3 )
    {
LABEL_7:
      v4 = (int *)(v2 + a1 + 28);
      do
      {
        if ( *(v4 - 1) )
        {
          v5 = *(v4 - 2);
          v6 = *v4;
          v7 = *(v4 - 4);
          v8 = ((v5 + v6 - 1) & -v6) + v7;
          if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          {
            v9 = a2;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x100,
              4,
              "cam_icp_get_fw_size",
              82,
              "memsz:%x align:%x addr:%x seg_mem_size:%x",
              v5,
              v6,
              v7,
              v8);
            a2 = v9;
          }
          if ( *a2 < v8 )
            *a2 = v8;
        }
        --v3;
        v4 += 8;
      }
      while ( v3 );
    }
  }
  else if ( *(_WORD *)(a1 + 44) )
  {
    goto LABEL_7;
  }
  if ( *a2 )
    return 0;
  v10 = "invalid elf fw file";
  v11 = 89;
LABEL_21:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_get_fw_size",
    v11,
    v10);
  return 4294967274LL;
}
