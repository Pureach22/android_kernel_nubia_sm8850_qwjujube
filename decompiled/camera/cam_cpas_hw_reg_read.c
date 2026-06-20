__int64 __fastcall cam_cpas_hw_reg_read(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, char a5, _DWORD *a6)
{
  __int64 v6; // x9
  unsigned int v7; // w7
  __int64 v8; // x8
  _DWORD *v9; // x19
  int v10; // w0

  if ( (unsigned int)a3 >= 0xA )
  {
LABEL_18:
    __break(0x5512u);
    return cam_cpas_hw_update_ahb_vote(a1, a2, a3);
  }
  if ( a6 )
  {
    v6 = *(_QWORD *)(a1 + 3680);
    v7 = *(_DWORD *)(v6 + 4LL * (unsigned int)a3 + 2812);
    if ( (v7 & 0x80000000) != 0 || v7 >= *(_DWORD *)(a1 + 576) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_hw_reg_read",
        780,
        "Invalid reg_base=%d, reg_base_index=%d, num_map=%d",
        (unsigned int)a3);
    }
    else if ( (unsigned int)a2 <= 0x2A )
    {
      v8 = *(_QWORD *)(v6 + 8LL * (unsigned int)a2 + 320);
      if ( *(_BYTE *)(v8 + 168) != 1 || (*(_BYTE *)(v8 + 169) & 1) == 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_hw_reg_read",
          792,
          "client=[%d][%s][%d] has not started",
          a2,
          (const char *)v8,
          *(_DWORD *)(v8 + 128));
        return 0xFFFFFFFFLL;
      }
      if ( (a5 & 1) != 0 )
      {
        if ( v7 <= 7 )
        {
          v9 = a6;
          v10 = cam_io_r_mb(*(_QWORD *)(a1 + 24LL * v7 + 384) + a4);
LABEL_17:
          *v9 = v10;
          return 0;
        }
      }
      else if ( v7 <= 7 )
      {
        v9 = a6;
        v10 = cam_io_r(*(_QWORD *)(a1 + 24LL * v7 + 384) + a4);
        goto LABEL_17;
      }
      goto LABEL_18;
    }
  }
  return 4294967274LL;
}
