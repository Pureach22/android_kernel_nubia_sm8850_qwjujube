__int64 __fastcall qcom_free_io_pgtable_ops(__int64 result)
{
  unsigned int v1; // w1
  __int64 v2; // x19
  __int64 (__fastcall **v3)(); // x20
  void (__fastcall **v4)(_QWORD); // x8
  void (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x0
  __int64 (__fastcall *v7)(); // x8

  if ( !result )
    return result;
  v2 = result - 128;
  v1 = *(_DWORD *)(result - 128);
  if ( v1 <= 9 )
    return free_io_pgtable_ops();
  if ( v1 != -1 )
  {
    if ( v1 != -2 )
      return printk(&unk_11C2A);
    v3 = qcom_io_pgtable_arm_64_lpae_s1_init_fns;
    v4 = *(void (__fastcall ***)(_QWORD))(result - 72);
    if ( !v4 )
      goto LABEL_13;
    goto LABEL_9;
  }
  v3 = io_pgtable_av8l_fast_init_fns;
  v4 = *(void (__fastcall ***)(_QWORD))(result - 72);
  if ( v4 )
  {
LABEL_9:
    v5 = *v4;
    if ( v5 )
    {
      v6 = *(_QWORD *)(result - 120);
      if ( *((_DWORD *)v5 - 1) != 251140989 )
        __break(0x8228u);
      v5(v6);
    }
  }
LABEL_13:
  v7 = v3[1];
  if ( *((_DWORD *)v7 - 1) != -2124635574 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64))v7)(v2);
}
