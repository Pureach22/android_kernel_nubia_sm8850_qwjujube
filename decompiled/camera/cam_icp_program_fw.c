__int64 __fastcall cam_icp_program_fw(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w23
  unsigned int *v6; // x25

  v2 = *(unsigned int *)(a1 + 28);
  if ( a1 + v2 )
  {
    v3 = *(unsigned __int16 *)(a1 + 44);
    if ( *(_WORD *)(a1 + 44) )
    {
      v6 = (unsigned int *)(v2 + a1 + 12);
      do
      {
        if ( v6[3] )
        {
          if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x100,
              4,
              "cam_icp_program_fw",
              123,
              "Loading FW header size: %u paddr: %pK",
              v6[1],
              (const void *)*v6);
            if ( !v6[1] )
              goto LABEL_4;
LABEL_9:
            _memcpy_toio(a2 + *v6, a1 + *(v6 - 2));
            goto LABEL_4;
          }
          if ( v6[1] )
            goto LABEL_9;
        }
LABEL_4:
        --v3;
        v6 += 8;
      }
      while ( v3 );
    }
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_program_fw",
      114,
      "failed to get elf program header attr");
    return 4294967274LL;
  }
}
