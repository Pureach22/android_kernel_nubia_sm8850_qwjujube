__int64 *__fastcall print_hfi_queue_info(__int64 *result)
{
  __int64 v1; // x19
  void (__fastcall *v2)(_QWORD); // x8
  __int64 *v3; // x20
  __int64 v4; // x0
  __int64 v5; // x25
  unsigned __int64 v6; // x26
  __int64 v7; // x27
  unsigned __int64 v8; // x8
  unsigned __int64 StatusReg; // x8

  if ( result )
  {
    v1 = *result;
    if ( *result )
    {
      v2 = (void (__fastcall *)(_QWORD))result[20];
      if ( v2 )
      {
        v3 = result;
        v4 = *result;
        if ( *((_DWORD *)v2 - 1) != -1066802076 )
          __break(0x8228u);
        v2(v4);
        v1 = *v3;
      }
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_9725E, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
      __dsb(0xFu);
      mutex_lock(v1 + 80);
      v5 = 0;
      v6 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v7 = *(_QWORD *)(v1 + v5 + 1024);
        if ( !v7 )
          break;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          printk(&unk_85A6B, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
        if ( *(_DWORD *)(v7 + 48) != *(_DWORD *)(v7 + 52) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          printk(&unk_85AA7, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
        v5 += 192;
        if ( v5 == 576 )
          return (__int64 *)mutex_unlock(v1 + 80);
      }
      result = (__int64 *)mutex_unlock(v1 + 80);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v8 = _ReadStatusReg(SP_EL0);
        return (__int64 *)printk(&unk_8E1F3, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
      }
    }
  }
  return result;
}
