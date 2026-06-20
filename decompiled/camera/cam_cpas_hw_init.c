__int64 __fastcall cam_cpas_hw_init(_QWORD *a1, const void *a2, int a3)
{
  __int64 (*v3)(void); // x8

  if ( a1 && a2 )
  {
    if ( a3 == 308 )
    {
      v3 = *(__int64 (**)(void))(a1[460] + 8008LL);
      if ( v3 )
      {
        if ( *((_DWORD *)v3 - 1) != -502984210 )
          __break(0x8228u);
        return v3();
      }
      else
      {
        return 0;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_hw_init",
        3263,
        "INIT HW size mismatch %zd %d",
        0x134u,
        a3);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_init",
      3257,
      "Invalid arguments %pK %pK",
      a1,
      a2);
    return 4294967274LL;
  }
}
