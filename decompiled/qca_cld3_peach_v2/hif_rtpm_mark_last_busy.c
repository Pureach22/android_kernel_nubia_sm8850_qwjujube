__int64 __fastcall hif_rtpm_mark_last_busy(__int64 a1)
{
  __int64 v1; // x30
  __int64 v2; // x20
  unsigned int v3; // w19
  __int64 v4; // x22
  __int64 result; // x0
  unsigned __int64 StatusReg; // x9
  __int64 v7; // x8
  __int64 v8; // x10

  v2 = v1;
  v3 = a1;
  v4 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
  result = ktime_get_mono_fast_ns(a1);
  *(_QWORD *)(v4 + 520) = result;
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v7 = gp_hif_rtpm_ctx;
  *(_QWORD *)(gp_hif_rtpm_ctx + 248) = StatusReg;
  *(_DWORD *)(v7 + 256) = v3;
  *(_QWORD *)(v7 + 264) = v2;
  if ( v3 >= 0xC )
  {
    __break(0x5512u);
    JUMPOUT(0x176C2C);
  }
  v8 = *(_QWORD *)(v7 + 56 + 8LL * v3);
  if ( v8 )
  {
    ++*(_DWORD *)(v8 + 20);
    *(_QWORD *)(*(_QWORD *)(v7 + 56 + 8LL * v3) + 40LL) = *(_QWORD *)(v7 + 248);
  }
  return result;
}
