__int64 __fastcall sub_AC8AC(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x13

  *a1 = v8;
  return ipa_teardown_sys_pipe((char *)a1 + 217, a2, a3, a4, a5, a6, a7, a8);
}
