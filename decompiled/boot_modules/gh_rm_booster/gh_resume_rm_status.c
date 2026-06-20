__int64 gh_resume_rm_status()
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( (freq_qos_remove_request(rm_status + 40) & 0x80000000) != 0 )
    dev_err(*(_QWORD *)(rm_status + 32), "Failed to resume RM freq\n");
  result = *(_QWORD *)(rm_status + 232);
  if ( result != -1 )
  {
    __asm { HVC             #0x603D }
    if ( (_DWORD)result == 1 )
    {
      result = *(_QWORD *)(rm_status + 232);
      __asm { HVC             #0x603D }
    }
    if ( (_DWORD)result )
    {
      dev_err(*(_QWORD *)(rm_status + 32), "gh set RM affinity fail\n");
      result = dev_err(*(_QWORD *)(rm_status + 32), "Failed to resume RM affinity\n");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
