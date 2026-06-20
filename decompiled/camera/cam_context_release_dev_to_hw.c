__int64 __fastcall cam_context_release_dev_to_hw(__int64 a1)
{
  __int64 *v1; // x8
  _DWORD *v2; // x9
  __int64 v4; // x0
  __int64 result; // x0
  _QWORD v6[3]; // [xsp+8h] [xbp-18h] BYREF

  v6[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[1] = 0;
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_release_dev_to_hw",
      425,
      "Invalid input param");
    goto LABEL_9;
  }
  v1 = *(__int64 **)(a1 + 208);
  if ( !v1 || (v2 = (_DWORD *)v1[4]) == nullptr )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_release_dev_to_hw",
      431,
      "[%s][%d] HW interface is not ready",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  v6[0] = *(_QWORD *)(a1 + 264);
  v4 = *v1;
  if ( *(v2 - 1) != 1863972096 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, _QWORD *))v2)(v4, v6);
  cam_context_free_mem_hw_entries(a1);
  result = 0;
  *(_QWORD *)(a1 + 264) = 0;
  *(_QWORD *)(a1 + 56) = -1;
  *(_DWORD *)(a1 + 64) = -1;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
