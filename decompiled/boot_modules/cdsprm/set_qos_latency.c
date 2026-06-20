__int64 __fastcall set_qos_latency(__int64 result)
{
  unsigned int v1; // w19
  __int64 v2; // x22
  unsigned __int64 v3; // x23
  __int64 cpu_device; // x0

  v1 = result;
  if ( byte_A48C == 1 )
  {
    if ( dword_A4F8 )
    {
      v2 = 0;
      v3 = 0;
      while ( 1 )
      {
        if ( (byte_A488 & 1) != 0 )
        {
          result = dev_pm_qos_update_request(qword_A500 + v2, v1);
        }
        else
        {
          cpu_device = get_cpu_device(*(unsigned int *)(qword_A4F0 + 4 * v3));
          result = dev_pm_qos_add_request(cpu_device, qword_A500 + v2, 1, v1);
        }
        if ( (result & 0x80000000) != 0 )
          break;
        ++v3;
        v2 += 80;
        if ( v3 >= (unsigned int)dword_A4F8 )
          goto LABEL_9;
      }
      _ReadStatusReg(SP_EL0);
      return printk(&unk_BCEF);
    }
    else
    {
LABEL_9:
      byte_A488 = 1;
    }
  }
  else if ( (byte_A488 & 1) != 0 )
  {
    return cpu_latency_qos_update_request(&unk_A368, (unsigned int)result);
  }
  else
  {
    result = cpu_latency_qos_add_request(&unk_A368, (unsigned int)result);
    byte_A488 = 1;
  }
  return result;
}
