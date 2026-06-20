__int64 __fastcall ufs_qcom_shutdown(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x8
  __int64 v3; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x22
  __int64 (__fastcall *v6)(__int64, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // t1
  __int64 v9; // x8
  __int64 v10; // [xsp+8h] [xbp-8h]

  v2 = (unsigned __int8)is_bootdevice_ufs;
  if ( (is_bootdevice_ufs & 1) == 0 )
    return dev_info(result + 16, "UFS is not boot dev.\n");
  v3 = *(_QWORD *)(result + 168);
  if ( v3 )
  {
    v1 = *(_QWORD *)(v3 + 184);
    result = *(_QWORD *)(v1 + 656);
    if ( result && *(_BYTE *)(v1 + 664) == 1 )
    {
      _ReadStatusReg(SP_EL0);
      result = ipc_log_string();
    }
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v10 = v2;
      ++*(_DWORD *)(StatusReg + 16);
      v5 = qword_175B8;
      if ( qword_175B8 )
      {
        do
        {
          v6 = *(__int64 (__fastcall **)(__int64, __int64))v5;
          v7 = *(_QWORD *)(v5 + 8);
          if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != -110690895 )
            __break(0x8228u);
          result = v6(v7, v10);
          v8 = *(_QWORD *)(v5 + 24);
          v5 += 24;
        }
        while ( v8 );
      }
      v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v9;
      if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
        result = preempt_schedule_notrace();
    }
  }
  if ( (*(_BYTE *)(v1 + 3141) & 1) == 0 )
  {
    result = *(_QWORD *)(*(_QWORD *)(v3 + 184) + 296LL);
    if ( result )
      return gpiod_set_value_cansleep(result, 0);
  }
  return result;
}
