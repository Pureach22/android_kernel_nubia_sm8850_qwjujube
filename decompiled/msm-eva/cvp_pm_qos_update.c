__int64 __fastcall cvp_pm_qos_update(__int64 result, __int64 a2)
{
  unsigned int v2; // w21
  __int64 v3; // x8
  __int64 v4; // x20
  char v5; // w19
  __int64 v6; // x27
  unsigned __int64 v7; // x22
  unsigned __int64 StatusReg; // x25
  unsigned __int64 v9; // x9
  int v10; // w8
  void *v11; // x0

  if ( (a2 & 1) != 0 )
    v2 = *(_DWORD *)(result + 2696);
  else
    v2 = 0x7FFFFFFF;
  if ( *(_DWORD *)(result + 2696) )
  {
    v3 = *(_QWORD *)(result + 2208);
    v4 = result;
    if ( *(_QWORD *)(v3 + 400) )
    {
      if ( *(_DWORD *)(v3 + 384) )
      {
        v5 = a2;
        v6 = 0;
        v7 = 0;
        StatusReg = _ReadStatusReg(SP_EL0);
        do
        {
          if ( v6 == 160 )
          {
            __break(0x5512u);
            return _sys_set_debug(result, a2);
          }
          v9 = *(unsigned int *)(v3 + 4 * v7 + 392);
          if ( ((*(_QWORD *)((char *)&_cpu_possible_mask + ((v9 >> 3) & 0x1FFFFFF8)) >> v9) & 1) != 0 )
          {
            if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8C556, &unk_8DA84, "cvp_pm_qos_update", (unsigned int)v7);
              v3 = *(_QWORD *)(v4 + 2208);
            }
            result = dev_pm_qos_update_request(*(_QWORD *)(v3 + 400) + v6, v2);
            if ( (result & 0x80000000) != 0 )
            {
              v10 = (msm_cvp_debug_out == 0) & ((unsigned __int8)msm_cvp_debug >> 1);
              if ( (v5 & 1) != 0 )
              {
                if ( v10 )
                {
                  v11 = &unk_8C588;
LABEL_20:
                  result = printk(v11, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
                }
              }
              else if ( v10 )
              {
                v11 = &unk_84334;
                goto LABEL_20;
              }
            }
          }
          v3 = *(_QWORD *)(v4 + 2208);
          ++v7;
          v6 += 80;
        }
        while ( v7 < *(unsigned int *)(v3 + 384) );
      }
    }
  }
  return result;
}
