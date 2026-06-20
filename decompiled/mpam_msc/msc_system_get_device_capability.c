__int64 __fastcall msc_system_get_device_capability(unsigned int a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8
  _UNKNOWN **v4; // x8
  int v5; // w9
  unsigned int (__fastcall *v6)(_QWORD); // x9
  __int64 v7; // x0
  void *v8; // x8

  v3 = -22;
  if ( !a2 || !a3 )
    return v3;
  v4 = &qcom_mpam_list;
  do
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &qcom_mpam_list )
      goto LABEL_15;
  }
  while ( *((_DWORD *)v4 - 18) != a1 );
  if ( v4 == &_ksymtab_msc_system_mon_be_bw_info )
  {
LABEL_15:
    v8 = &unk_6E1C;
LABEL_17:
    printk(v8, a1);
    return (unsigned int)-22;
  }
  if ( ((_BYTE)v4[2] & 2) == 0 )
  {
    v8 = &unk_6DE8;
    goto LABEL_17;
  }
  v5 = *((unsigned __int16 *)v4 - 29);
  if ( v5 != *(unsigned __int16 *)(a2 + 2) )
  {
    printk(&unk_6DC0, a2);
    return (unsigned int)-22;
  }
  if ( v5 == 2 && (v6 = *((unsigned int (__fastcall **)(_QWORD))*(v4 - 6) + 2)) != nullptr )
  {
    v7 = (__int64)*(v4 - 2);
    if ( *((_DWORD *)v6 - 1) != -1049200603 )
      __break(0x8229u);
    return v6(v7);
  }
  else
  {
    return 0;
  }
}
