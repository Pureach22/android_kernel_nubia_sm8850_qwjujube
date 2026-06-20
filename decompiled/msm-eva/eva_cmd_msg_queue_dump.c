__int64 eva_cmd_msg_queue_dump()
{
  unsigned __int64 StatusReg; // x20
  __int64 result; // x0
  __int64 v2; // x8
  __int64 *v3; // x8
  __int64 v4; // x21
  unsigned __int64 v5; // x19
  void *v6; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  result = printk(&unk_86853, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "info");
  v2 = *(_QWORD *)(cvp_driver + 48);
  if ( v2 )
  {
    v3 = *(__int64 **)(v2 + 256);
    if ( v3 && (v4 = *v3) != 0 )
    {
      v5 = *(_QWORD *)(v4 + 2528);
      if ( v5 )
      {
        result = eva_queue_dump(v4 + 1016, *(_QWORD *)(v4 + 2528), 0x100000u);
        if ( (_DWORD)result )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v6 = &unk_87E76;
            return printk(v6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          }
        }
        else
        {
          result = eva_queue_dump(v4 + 1208, v5, 0x200000u);
          if ( (_DWORD)result )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v6 = &unk_92A52;
              return printk(v6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            }
          }
          else
          {
            result = eva_queue_dump(v4 + 1592, v5, 0x300000u);
            if ( (_DWORD)result )
            {
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                v6 = &unk_82BD8;
                return printk(v6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
              }
            }
            else
            {
              result = eva_queue_dump(v4 + 1784, v5, 0x400000u);
              if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                v6 = &unk_8E70C;
                return printk(v6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
              }
            }
          }
        }
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v6 = &unk_85E08;
        return printk(v6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
    }
    else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v6 = &unk_8C2C4;
      return printk(v6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v6 = &unk_88877;
    return printk(v6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  return result;
}
