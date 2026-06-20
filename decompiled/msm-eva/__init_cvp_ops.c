__int64 __fastcall _init_cvp_ops(__int64 result)
{
  *(_QWORD *)(result + 2512) = &hal_ops;
  return result;
}
