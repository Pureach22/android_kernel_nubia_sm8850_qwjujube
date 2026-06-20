__int64 __fastcall cam_compat_util_put_dmabuf_va(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD v3[3]; // [xsp+8h] [xbp-18h] BYREF

  v3[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = a2;
  v3[1] = 0;
  result = dma_buf_vunmap_unlocked(a1, v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
