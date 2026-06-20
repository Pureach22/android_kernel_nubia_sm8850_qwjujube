__int64 __fastcall msc_system_get_mpam_version(unsigned int a1, __int64 a2)
{
  _UNKNOWN **v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x9
  __int64 v4; // x0

  if ( !a2 )
    return 4294967274LL;
  v2 = &qcom_mpam_list;
  do
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &qcom_mpam_list )
      goto LABEL_14;
  }
  while ( *((_DWORD *)v2 - 18) != a1 );
  if ( v2 == &_ksymtab_msc_system_mon_be_bw_info )
  {
LABEL_14:
    printk(&unk_6E1C, a1);
    return 4294967274LL;
  }
  if ( *((_WORD *)v2 - 29) != 2 )
    return 0;
  v3 = *((__int64 (__fastcall **)(_QWORD))*(v2 - 6) + 7);
  if ( !v3 )
    return 0;
  v4 = (__int64)*(v2 - 2);
  if ( *((_DWORD *)v3 - 1) != 848979900 )
    __break(0x8229u);
  return v3(v4);
}
