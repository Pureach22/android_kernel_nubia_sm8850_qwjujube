__int64 __fastcall msc_system_mon_alloc_info(unsigned int a1, __int64 a2, _DWORD *a3)
{
  __int64 (__fastcall *v3)(_QWORD); // x8
  _UNKNOWN **v4; // x9
  __int64 v5; // x0
  void *v6; // x8

  LODWORD(v3) = -22;
  if ( !a2 || !a3 )
    return (unsigned int)v3;
  v4 = &qcom_mpam_list;
  do
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &qcom_mpam_list )
      goto LABEL_14;
  }
  while ( *((_DWORD *)v4 - 18) != a1 );
  if ( v4 == &_ksymtab_msc_system_mon_be_bw_info )
  {
LABEL_14:
    v6 = &unk_6E1C;
LABEL_16:
    printk(v6, a1);
LABEL_18:
    LODWORD(v3) = -22;
    return (unsigned int)v3;
  }
  if ( ((_BYTE)v4[2] & 2) == 0 )
  {
    v6 = &unk_6DE8;
    goto LABEL_16;
  }
  if ( *((unsigned __int16 *)v4 - 29) != *(unsigned __int16 *)(a2 + 2) )
  {
    printk(&unk_6DC0, a2);
    goto LABEL_18;
  }
  *a3 = 0;
  LODWORD(v3) = 0;
  if ( *((_WORD *)v4 - 29) == 2 )
  {
    v3 = *((__int64 (__fastcall **)(_QWORD))*(v4 - 6) + 5);
    if ( v3 )
    {
      v5 = (__int64)*(v4 - 2);
      if ( *((_DWORD *)v3 - 1) != -1049200603 )
        __break(0x8228u);
      LODWORD(v3) = v3(v5);
    }
  }
  return (unsigned int)v3;
}
