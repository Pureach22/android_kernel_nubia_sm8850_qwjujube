__int64 __fastcall cam_compat_util_get_dmabuf_va(const void *a1, _QWORD *a2)
{
  __int64 result; // x0
  const void *v5; // x7
  const void *v6; // [xsp+18h] [xbp-18h] BYREF
  __int64 v7; // [xsp+20h] [xbp-10h]
  __int64 v8; // [xsp+28h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = nullptr;
  v7 = 0;
  result = dma_buf_vmap_unlocked(a1, &v6);
  if ( (_DWORD)result )
  {
    *a2 = 0;
  }
  else
  {
    v5 = v6;
    *a2 = v6;
    if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x400000,
        4,
        "cam_compat_util_get_dmabuf_va",
        692,
        "dmabuf=%p, *vaddr=%p, is_iomem=%d, vaddr_iomem=%p, vaddr=%p",
        a1,
        v5,
        (unsigned __int8)v7,
        v5,
        v5);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
