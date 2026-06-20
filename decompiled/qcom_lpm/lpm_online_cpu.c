__int64 __fastcall lpm_online_cpu(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x13
  __int64 v3; // x19
  _BYTE *v4; // x1

  if ( (unsigned int)a1 >= 0x20 )
  {
    __break(0x5512u);
    *a1 = v2;
    JUMPOUT(0xAEA8);
  }
  v3 = _per_cpu_offset[(unsigned int)a1];
  if ( get_cpu_device(a1, a2) )
  {
    v4 = &lpm_cpu_data[v3];
    if ( &lpm_cpu_data[v3] )
    {
      *((_QWORD *)v4 + 2) = lpm_cpu_qos_notify;
      v4[324] = 0;
      dev_pm_qos_add_notifier();
    }
  }
  return 0;
}
