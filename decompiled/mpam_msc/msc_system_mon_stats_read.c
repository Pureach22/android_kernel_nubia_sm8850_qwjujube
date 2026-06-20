__int64 __fastcall msc_system_mon_stats_read(unsigned int a1, __int64 a2, _DWORD *a3)
{
  unsigned int v3; // w8
  _UNKNOWN **v4; // x8
  unsigned int (__fastcall *v5)(_QWORD); // x9
  __int64 v6; // x0
  void *v7; // x8

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
    v7 = &unk_6E1C;
LABEL_17:
    printk(v7, a1);
    return (unsigned int)-22;
  }
  if ( ((_BYTE)v4[2] & 2) == 0 )
  {
    v7 = &unk_6DE8;
    goto LABEL_17;
  }
  if ( *((unsigned __int16 *)v4 - 29) != *(unsigned __int16 *)(a2 + 2) )
  {
    printk(&unk_6DC0, a2);
    return (unsigned int)-22;
  }
  *a3 = 4;
  if ( *((_WORD *)v4 - 29) == 2 && (v5 = *((unsigned int (__fastcall **)(_QWORD))*(v4 - 6) + 5)) != nullptr )
  {
    v6 = (__int64)*(v4 - 2);
    if ( *((_DWORD *)v5 - 1) != -1049200603 )
      __break(0x8229u);
    return v5(v6);
  }
  else
  {
    return 0;
  }
}
