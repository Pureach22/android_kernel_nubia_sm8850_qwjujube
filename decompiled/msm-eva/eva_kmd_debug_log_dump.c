void *eva_kmd_debug_log_dump()
{
  unsigned __int64 StatusReg; // x19
  void *result; // x0
  __int64 v2; // x8
  __int64 *v3; // x9
  __int64 v4; // x9
  unsigned __int64 v5; // x9
  __int64 v7; // x1
  __int64 v8; // x2
  void *v9; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  result = (void *)printk(&unk_888A2, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "info");
  v2 = *(_QWORD *)(cvp_driver + 48);
  if ( v2 )
  {
    v3 = *(__int64 **)(v2 + 256);
    if ( v3 && (v4 = *v3) != 0 )
    {
      v5 = *(_QWORD *)(v4 + 2528);
      result = (void *)(v5 + 262528);
      if ( v5 + 262528 >= v5 && (unsigned __int64)result <= v5 + 0x80000 )
        return memcpy(result, (const void *)(v2 + 5864), 0xB180u);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v7 = *(unsigned int *)(StatusReg + 1800);
        v8 = *(unsigned int *)(StatusReg + 1804);
        v9 = &unk_91D9D;
        return (void *)printk(v9, v7, v8, &unk_8E7CE);
      }
    }
    else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v7 = *(unsigned int *)(StatusReg + 1800);
      v8 = *(unsigned int *)(StatusReg + 1804);
      v9 = &unk_8C2C4;
      return (void *)printk(v9, v7, v8, &unk_8E7CE);
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v7 = *(unsigned int *)(StatusReg + 1800);
    v8 = *(unsigned int *)(StatusReg + 1804);
    v9 = &unk_88877;
    return (void *)printk(v9, v7, v8, &unk_8E7CE);
  }
  return result;
}
