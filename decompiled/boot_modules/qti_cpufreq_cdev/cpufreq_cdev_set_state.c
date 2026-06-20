__int64 __fastcall cpufreq_cdev_set_state(__int64 a1, unsigned __int64 a2)
{
  _QWORD *v2; // x20
  __int64 result; // x0
  unsigned __int64 v4; // x8
  __int64 v5; // x8
  unsigned int v6; // w19
  unsigned __int64 v7; // x21
  unsigned int updated; // w0
  unsigned int v9; // w20

  v2 = *(_QWORD **)(a1 + 944);
  if ( v2[5] < a2 )
    return 4294967274LL;
  if ( v2[4] == a2 )
    return 0;
  v4 = v2[13];
  if ( v4
    && v4 <= 0xFFFFFFFFFFFFF000LL
    && ((v5 = v2[6]) == 0 ? (v7 = a2, v6 = -1) : (v6 = *(_DWORD *)(v5 + 4 * a2), v7 = a2),
        updated = freq_qos_update_request(v2 + 7, v6),
        a2 = v7,
        (updated & 0x80000000) != 0) )
  {
    v9 = updated;
    printk(&unk_67DA, "qti_cpufreq_cdev", "cpufreq_cdev_set_state", v6);
    return v9;
  }
  else
  {
    result = 0;
    v2[4] = a2;
  }
  return result;
}
