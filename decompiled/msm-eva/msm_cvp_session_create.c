__int64 __fastcall msm_cvp_session_create(__int64 a1)
{
  unsigned __int64 StatusReg; // x19
  unsigned int v2; // w5
  __int64 result; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  unsigned int v7; // w19
  unsigned int v8; // w0
  unsigned int v9; // w21
  void (__fastcall *v10)(_QWORD); // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( !a1 || !*(_QWORD *)(a1 + 128) )
    return 4294967274LL;
  v2 = *(_DWORD *)(a1 + 328);
  if ( v2 > 6 )
    return 4294967192LL;
  if ( v2 != 3 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    printk(&unk_8D117, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  result = ((__int64 (*)(void))msm_cvp_comm_try_state)();
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v5 = *(unsigned int *)(StatusReg + 1800);
      v6 = *(unsigned int *)(StatusReg + 1804);
      v7 = result;
      printk(&unk_8B384, v5, v6, &unk_8E7CE);
      return v7;
    }
  }
  else
  {
    v8 = cvp_comm_set_arp_buffers(a1);
    if ( v8 )
    {
      v9 = v8;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_950DC, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      if ( (unsigned int)msm_cvp_comm_try_state(a1, 7) )
      {
        result = v9;
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          return result;
        printk(&unk_86D52, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
      return v9;
    }
    v10 = **(void (__fastcall ***)(_QWORD))(*(_QWORD *)(a1 + 128) + 272LL);
    if ( *((_DWORD *)v10 - 1) != -1787504020 )
      __break(0x8228u);
    v10(a1);
    raw_spin_lock(a1 + 176);
    *(_DWORD *)(a1 + 180) = 1;
    raw_spin_unlock(a1 + 176);
    trace_tracing_mark_write_0(69, StatusReg, "msm_cvp_session_create");
    return 0;
  }
  return result;
}
