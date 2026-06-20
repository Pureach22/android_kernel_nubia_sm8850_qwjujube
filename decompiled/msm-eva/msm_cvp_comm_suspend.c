__int64 msm_cvp_comm_suspend()
{
  __int64 v0; // x8
  __int64 *v1; // x8
  __int64 (__fastcall *v2)(_QWORD); // x9
  __int64 v3; // x0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x1
  __int64 v7; // x2
  void *v8; // x0
  unsigned __int64 v9; // x8

  v0 = *(_QWORD *)(cvp_driver + 48);
  if ( !v0 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    v6 = *(unsigned int *)(StatusReg + 1800);
    v7 = *(unsigned int *)(StatusReg + 1804);
    v8 = &unk_8E172;
LABEL_13:
    printk(v8, v6, v7, &unk_8E7CE);
    return 4294967274LL;
  }
  v1 = *(__int64 **)(v0 + 256);
  if ( !v1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v9 = _ReadStatusReg(SP_EL0);
    v6 = *(unsigned int *)(v9 + 1800);
    v7 = *(unsigned int *)(v9 + 1804);
    v8 = &unk_83118;
    goto LABEL_13;
  }
  v2 = (__int64 (__fastcall *)(_QWORD))v1[18];
  if ( !v2 )
    return 0;
  v3 = *v1;
  if ( *((_DWORD *)v2 - 1) != -1066802076 )
    __break(0x8229u);
  return v2(v3);
}
