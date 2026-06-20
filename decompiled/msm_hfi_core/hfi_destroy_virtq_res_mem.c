__int64 __fastcall hfi_destroy_virtq_res_mem(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x22
  int v7; // w23
  __int64 result; // x0
  __int64 v9; // x1

  if ( a1 >= 4 )
    goto LABEL_26;
  v6 = *(_QWORD *)(a2 + 176LL * a1 + 104);
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    v7 = *(_DWORD *)(v6 + 48);
    if ( !v7 )
      goto LABEL_18;
  }
  else
  {
    printk(&unk_1E83A, "hfi_destroy_virtq_res_mem", 520, a4, a5);
    v7 = *(_DWORD *)(v6 + 48);
    if ( !v7 )
      goto LABEL_18;
  }
  result = unmap_res(a2, v6 + 176);
  if ( (_DWORD)result )
    return result;
  if ( v7 == 1 )
  {
    v9 = v6 + 136;
    goto LABEL_7;
  }
  result = unmap_res(a2, v6 + 288);
  if ( (_DWORD)result )
    return result;
  if ( v7 != 2 )
  {
    result = unmap_res(a2, v6 + 400);
    if ( (_DWORD)result )
      return result;
    if ( v7 != 3 )
    {
      result = unmap_res(a2, v6 + 512);
      if ( (_DWORD)result )
        return result;
      if ( v7 != 4 )
      {
LABEL_26:
        __break(0x5512u);
LABEL_27:
        printk(&unk_1C28B, "hfi_destroy_virtq_res_mem", 545, a4, a5);
        return 0;
      }
    }
  }
  result = unmap_res(a2, v6 + 136);
  if ( !(_DWORD)result )
  {
    result = unmap_res(a2, v6 + 248);
    if ( !(_DWORD)result )
    {
      if ( v7 == 2 )
        goto LABEL_18;
      result = unmap_res(a2, v6 + 360);
      if ( (_DWORD)result )
        return result;
      if ( v7 == 3 )
      {
LABEL_18:
        result = unmap_res(a2, v6 + 64);
        if ( (_DWORD)result )
          return result;
        if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
          return 0;
        goto LABEL_27;
      }
      v9 = v6 + 472;
LABEL_7:
      result = unmap_res(a2, v9);
      if ( (_DWORD)result )
        return result;
      goto LABEL_18;
    }
  }
  return result;
}
