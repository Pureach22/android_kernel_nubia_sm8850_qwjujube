__int64 __fastcall cam_common_mem_kdup(_QWORD *a1, const void *a2, size_t a3)
{
  __int64 v6; // x2
  void *v7; // x0
  __int64 result; // x0

  if ( a1 && a2 && a3 )
  {
    if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFF0100) != 0 )
      v6 = 2336;
    else
      v6 = 3520;
    v7 = (void *)_kvmalloc_node_noprof(a3, 0, v6, 0xFFFFFFFFLL);
    *a1 = v7;
    if ( v7 )
    {
      memcpy(v7, a2, a3);
      result = 0;
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_common_mem_kdup",
          901,
          "Allocate and copy memory with size: %u",
          a3);
        return 0;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_common_mem_kdup",
        896,
        "Failed to allocate memory with size: %u",
        a3);
      return 4294967284LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_mem_kdup",
      887,
      "Invalid params src: %pK dst: %pK size: %u",
      a2,
      a1,
      a3);
    return 4294967274LL;
  }
  return result;
}
