__int64 __fastcall qcom_cpucp_fast_probe(__int64 a1)
{
  __int64 v2; // x19
  unsigned __int64 v3; // x0
  unsigned int v4; // w20
  unsigned int v5; // w0
  __int64 v7; // x0
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v2 = a1 + 16;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  qword_65F8 = a1 + 16;
  qword_6618 = (__int64)qcom_cpucp_fast_rx;
  v3 = mbox_request_channel(&qword_65F8, 0);
  qword_6630 = v3;
  if ( v3 < 0xFFFFFFFFFFFFF001LL || (v4 = v3, (_DWORD)v3 == -517) )
  {
    v5 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,policy-cpus", &v8, 1, 0);
    if ( (v5 & 0x80000000) != 0 )
    {
      v4 = v5;
      dev_err(v2, "Error getting policy%d CPU: %d\n", v8, v5);
    }
    else if ( v8 < nr_cpu_ids
           && ((*(_QWORD *)((char *)&_cpu_present_mask + (((unsigned __int64)v8 >> 3) & 0x1FFFFFF8)) >> v8) & 1) != 0 )
    {
      v7 = cpufreq_cpu_get(v8);
      if ( v7 )
      {
        qword_65F0 = *(_QWORD *)(v7 + 8);
        cpufreq_cpu_put();
        dev_info(v2, "Probe successful, FAST cpus=0x%lx\n", qword_65F0);
        v4 = 0;
        goto LABEL_10;
      }
      dev_err(v2, "No policy for CPU:%d. Defer.\n", v8);
      v4 = -517;
    }
    else
    {
      dev_err(v2, "Invalid CPU%d\n", v8);
      v4 = 0;
    }
    mbox_free_channel(qword_6630);
  }
  else
  {
    dev_err(v2, "Error getting mailbox %d\n", v3);
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v4;
}
